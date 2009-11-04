#include "autoconf.h"
#include "pinning.c"
#ifndef KTY_INLINE_SUPPORT
#error Don't inline this file without KTY_INLINE_SUPPORT
#endif
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE html PUBLIC
    "-//W3C//DTD XHTML 1.1 plus MathML 2.0 plus SVG 1.1//EN"
    "http://www.w3.org/2002/04/xhtml-math-svg/xhtml-math-svg.dtd">
<html xmlns="http://www.w3.org/1999/xhtml"
      xmlns:svg="http://www.w3.org/2000/svg">
  <head>
    <title>Ethersex KTY Temperature Sheet</title>
    <link rel="stylesheet" href="Sty.c" type="text/css"/>
    <script src="scr.js" type="text/javascript"></script>
    <script src="gph.js" type="text/javascript"></script>
    <script type="text/javascript"><![CDATA[
var num = 8;
var min = -10, max = 80;
var g = new Array();

function kty_trigger() {
	setTimeout("kty_trigger_get();", 5000);
}

function kty_trigger_get() {
	ArrAjax.ecmd('kty get', kty_get_handler, 'GET', 0);
	kty_trigger();
}

function kty_get_handler(request, data) {
	var daten = returnObjById("daten");
	daten.innerHTML = request.responseText;

	for (var i = 0; i < num; i++) {
		var sensor = request.responseText.substr(i*6, 6);
		var temperatur = parseFloat (sensor);
		var sensor = returnObjById("sensor"+i);
		sensor.innerHTML = temperatur;
		graphAppend (g[i], temperatur);

	}
}

window.onload = function() {
	graphCreateAxis("axis", "text", min, max);
	for (var i = 0; i < num; i++)
		g[i] = new Graph("grph" + i, 40, min, max);
	kty_trigger();
}
]]></script>
  </head>
  <body>
    <h1>SVG-powered KTY Status</h1>

    <p><!-- Jippie, we like Microsoft Internet Explorer -->
      <object id="AdobeSVG" classid="clsid:78156a80-c6a1-4bbf-8e6a-3cd390eeb4e2"> </object>
    </p>

    <?import namespace="svg" urn="http://www.w3.org/2000/svg" implementation="#AdobeSVG"?>
    <svg:svg width="900px" height="600px" viewBox="0 0 900 600"
	     zoomAndPan="disable">
      <svg:g stroke="red"   style="stroke-width:2px;" id="grph0"></svg:g>
      <svg:g stroke="purple"  style="stroke-width:2px;" id="grph1"></svg:g>
      <svg:g stroke="lime" style="stroke-width:2px;" id="grph2"></svg:g>
      <svg:g stroke="green" style="stroke-width:2px;" id="grph3"></svg:g>
      <svg:g stroke="olive" style="stroke-width:2px;" id="grph4"></svg:g>
      <svg:g stroke="navy" style="stroke-width:2px;" id="grph5"></svg:g>
      <svg:g stroke="maroon" style="stroke-width:2px;" id="grph6"></svg:g>
      <svg:g stroke="fuchsia" style="stroke-width:2px;" id="grph7"></svg:g>
      <svg:g stroke="#999"  style="stroke-dasharray: 2, 5; " id="axis"></svg:g>
      <svg:g stroke="#999" font-size="12" id="text"></svg:g>
    </svg:svg>

    <table id='ow_table' border="1" cellspacing="0" class="bigtable">
    <tr><td style="color: red;">Kessel</td><td style="color: purple;">Vorlauf</td><td style="color: lime;">Wasser</td>
    <td style="color: green;">W.Rueckl</td><td style="color: olive;">W.Zulauf</td><td style="color: navy;">AussenNord</td>
    <td style="color: maroon;">Ruecklauf</td><td style="color: fuchsia;">Ofen</td></tr>
    <tr><td id='sensor0'> </td><td id='sensor1'> </td><td id='sensor2'> </td><td id='sensor3'> </td><td id='sensor4'> </td><td id='sensor5'> </td><td id='sensor6'> </td><td id='sensor7'> </td></tr>
    <tr><td id='daten' colspan="8">No data</td></tr>
    </table>
    <div id="logconsole"></div>
  </body>
</html>
