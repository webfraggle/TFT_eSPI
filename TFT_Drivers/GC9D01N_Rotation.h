
// This is the command sequence that rotates the GC9A01 driver coordinate frame

  rotation = m % 4;
Serial.println("ksjdhfsdjhflsdjhf");
  writecommand(TFT_MADCTL);
  switch (rotation) {
    case 0: // Portrait
      writedata(0x00);
      _width  = _init_width;
      _height = _init_height;
      break;
    case 1: // Landscape (Portrait + 90)
      writedata(0x00 | TFT_MAD_MX | TFT_MAD_MV);
      _width  = _init_height;
      _height = _init_width;
      break;
    case 2: // Inverter portrait
      writedata(0x00 | TFT_MAD_MX | TFT_MAD_MY);
      _width  = _init_width;
      _height = _init_height;
      break;
    case 3: // Inverted landscape
      writedata(0x00 | TFT_MAD_MV | TFT_MAD_MY);
      _width  = _init_height;
      _height = _init_width;
      break;
  }


  /*
  
  #define TFT_MAD_MY  0x80
#define TFT_MAD_MX  0x40
#define TFT_MAD_MV  0x20
#define TFT_MAD_ML  0x10

    writecommand(0x36);

//#if LANDSCAPE
//writedata(0x00 |  TFT_MAD_MX | TFT_MAD_MY);

#if (LANDSCAPE==2)||(PORTRAIT==2)
    writedata(0x00);
#else
    writedata(0x00 |  TFT_MAD_MX | TFT_MAD_MY);
#endif
    writecommand(0x11);
    delay(200);

  */