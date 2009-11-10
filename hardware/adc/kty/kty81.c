/* Copyright(C) 2007 Jochen Roessner <jochen@lugrot.de>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA
 */


#include <avr/io.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <avr/pgmspace.h>
#include "config.h"
#include "core/eeprom.h"

#include "kty81.h"

#ifdef KTY_SUPPORT

/* schaltet auf den Sensorchannel und AREF auf 0 
 * liest den adc Wert ein und gibt ihn zurueck
 */
uint16_t
get_kty(uint8_t sensorchannel)
{
  ADMUX = (ADMUX & 0xF0) | sensorchannel;
  /* Start der adc konvertierung */
  ADCSRA |= _BV(ADSC);
  /* Warten bis sie fertig ist */
  while (ADCSRA & _BV(ADSC))
    ;
  return ADC;
}

int8_t
kty_calibrate(uint16_t sensorwert)
{
  int32_t volt = sensorwert;
  int8_t calibration;
  volt *= 2500;
  volt /= 1023;
  int32_t R = 1000L;
  R *= 5000L - volt;
  R /= volt;
  if (R < 2320 && R > 2080){
    calibration = 2200L - R;
    eeprom_save_char (kty_calibration, calibration);
    eeprom_update_chksum();
    return 1;
  }
  return 0;
}

/* Berechnet die Temperatur in Zehntelgrad
 * vom adc wert
 */
int16_t
temperatur(uint16_t sensorwert)
{
  int32_t volt = sensorwert;
  int8_t calibration;
  eeprom_restore_char (kty_calibration, &calibration);
  volt *= 2500;
  volt /= 1023;
  int32_t R = 2200L;
  R += calibration;
  R *= volt;
  R /=  5000L - volt;
  int32_t temper;
#if KTY_DEVICE == KTY_DEVICE_110
  if (R > 1110){
    temper = -94379;
    temper += 131 * R;
  }
  else{
    temper = -140995;
    temper += 173 * R;
  }
  temper /= 128;
#endif
  return temper;

}

/* gibt die Temperatur (in Zehntelgrad) formatiert als Klartext
 * im Textbuffer zurueck.
 * Mindestlaenge des buf ist 6 byte
 * Aequivalent zu:
 *   sprintf(textbuf, "% 3i.%1i", temperatur/10, abs(temperatur%10));
 */
void
temp2text(char *textbuf, int16_t temperatur)
{
  if (temperatur > -300 && temperatur < 1500){
    char *ptr = textbuf;

    /* fülle mit Padding-bytes auf */
    if (temperatur >= 0 && temperatur < 10)
      *ptr++ = ' ';
    if (temperatur > -10 && temperatur < 100)
      *ptr++ = ' ';
    if (temperatur > -100 && temperatur < 1000)
      *ptr++ = ' ';

    itoa (temperatur, ptr, 10);

    /* konvertiere Zehntelgrad nach Grad: baue Dezimalstelle */
    textbuf[4] = textbuf[3];
    textbuf[3] = '.';

    textbuf[5] = '\0';
  }
  else{
    /* "Out of range" Indikator */
    strcpy_P(textbuf, PSTR("!NaN!"));
  }
  // return 5; <-- maybe better make it explicit
}
#endif
