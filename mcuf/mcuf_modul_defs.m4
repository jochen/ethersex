modul_ifdef(MCUF_IMAGE_SUPPORT)
  modul(mcuf_image, "image")
modul_endif()
modul_ifdef(MCUF_CHESS_SUPPORT)
  modul(mcuf_chess, "chess")
modul_endif()
modul_ifdef(MCUF_SPIRAL_SUPPORT)
  modul(spiral, "spiral")
modul_endif()
modul_ifdef(MCUF_CLEAN_SUPPORT)
  modul(clean, "clean")
modul_endif()
modul_ifdef(MCUF_MODUL_BORG16_MATRIX_SUPPORT)
  modul(matrix, "matrix")
modul_endif()
modul_ifdef(MCUF_MODUL_BORG16_XONI_STUDY_SUPPORT)
  modul(xoni_study1, "xoni")
modul_endif()
modul_ifdef(MCUF_MODUL_BORG16_FIRE_SUPPORT)
  modul(feuer, "fire")
modul_endif()
modul_ifdef(MCUF_MODUL_BORG16_SPIRAL_SUPPORT)
  modul(fspirale, "spiral")
modul_endif()
modul_ifdef(MCUF_MODUL_BORG16_JOERN1_SUPPORT)
  modul(joern1, "joern1")
modul_endif()
modul_ifdef(MCUF_MODUL_BORG16_SCHACHBRETT_SUPPORT)
  modul(fschachbrett, "chessboard")
modul_endif()
modul_ifdef(MCUF_MODUL_BORG16_SNAKE_SUPPORT)
  modul(snake, "snake")
modul_endif()
modul_ifdef(MCUF_MODUL_BORG16_RANDOM_BRIGHT_SUPPORT)
  modul(frandom_bright, "random")
modul_endif()
modul_ifdef(MCUF_MODUL_BORG16_TEST1_SUPPORT)
  modul(test1, "test1")
modul_endif()
modul_ifdef(MCUF_MODUL_BORG16_TESTL1_SUPPORT)
  modul(test_level1, "level1")
modul_endif()
modul_ifdef(MCUF_MODUL_BORG16_TESTL2_SUPPORT)
  modul(test_level2, "level2")
modul_endif()
modul_ifdef(MCUF_MODUL_BORG16_TESTL3_SUPPORT)
  modul(test_level3, "level3")
modul_endif()
modul_ifdef(MCUF_MODUL_BORG16_TESTLX_SUPPORT)
  modul(test_levels, "levels")
modul_endif()
modul_ifdef(MCUF_MODUL_BORG16_PALETTE_SUPPORT)
  modul(test_palette, "palette")
modul_endif()
modul_ifdef(MCUF_MODUL_BORG16_FADEIN_SUPPORT)
  modul(fadein, "fadin")
modul_endif()
modul_ifdef(MCUF_MODUL_BORG16_TETRIS_SUPPORT)
  modul(tetris, "tetris")
modul_endif()
modul_ifdef(MCUF_MODUL_BORG16_GAMEOFLIFE_SUPPORT)
  modul(gameoflife, "game of life")
modul_endif()
modul_ifdef(MCUF_MODUL_BORG16_INVADERS_SUPPORT)
  modul(borg_invaders, "invaders")
modul_endif()