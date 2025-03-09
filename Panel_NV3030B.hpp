/*----------------------------------------------------------------------------/
  Lovyan GFX - Graphics library for embedded devices.

Original Source:
 https://github.com/lovyan03/LovyanGFX/

Licence:
 [FreeBSD](https://github.com/lovyan03/LovyanGFX/blob/master/license.txt)

Author:
 [lovyan03](https://twitter.com/lovyan03)

Contributors:
 [ciniml](https://github.com/ciniml)
 [mongonta0716](https://github.com/mongonta0716)
 [tobozo](https://github.com/tobozo)
 [od_1969](https://github.com/od1969)
/----------------------------------------------------------------------------*/
#pragma once

#include "Panel_LCD.hpp"

namespace lgfx
{
 inline namespace v1
 {
//----------------------------------------------------------------------------

  struct Panel_NV3030B  : public Panel_LCD
  {
    Panel_NV3030B(void)
    {
      _cfg.panel_height = _cfg.memory_height = 320;

      _cfg.dummy_read_pixel = 16;
    }

  protected:
	
    static constexpr uint8_t CMD_OSCSET   = 0x60;      // osc setting
    static constexpr uint8_t CMD_DVDDSET  = 0x61;      // dvdd setting
    static constexpr uint8_t CMD_BIASSET  = 0x62;      // bias setting
    static constexpr uint8_t CMD_VGLSET   = 0x63;      // vgl setting
    static constexpr uint8_t CMD_VGHSET   = 0x64;      // vgh setting
    static constexpr uint8_t CMD_VSPSET   = 0x65;      // VSP setting
    static constexpr uint8_t CMD_VSNSET   = 0x66;      // VSN setting
    static constexpr uint8_t CMD_PCLKSET  = 0x67;      // pump clock sel
    static constexpr uint8_t CMD_GAMREF1  = 0x68;      // gamma ref 1
    
    static constexpr uint8_t CMD_FRARATE  = 0xB1;      // frame rate
    static constexpr uint8_t CMD_DPCTRL   = 0xB4;      // display pol control
    static constexpr uint8_t CMD_BLAPRO   = 0xB5;      // blanking porch
    static constexpr uint8_t CMD_DISFUNC  = 0xB6;      // display function
    static constexpr uint8_t CMD_EMSET    = 0xB7;      // entry mode set
	
    static constexpr uint8_t CMD_GAMPOS1  = 0xE0;      // gamma positive 1
    static constexpr uint8_t CMD_GAMPOS2  = 0xE1;      // gamma positive 2
    static constexpr uint8_t CMD_GAMPOS3  = 0xE2;      // gamma positive 3
    static constexpr uint8_t CMD_GAMNEG1  = 0xE3;      // gamma negative 1
    static constexpr uint8_t CMD_GAMNEG2  = 0xE4;      // gamma negative 2
    static constexpr uint8_t CMD_GAMNEG3  = 0xE5;      // gamma negative 3
    
    static constexpr uint8_t CMD_SRCTRL1  = 0xE6;      // SRC_CTRL1
    static constexpr uint8_t CMD_SRCTRL2  = 0xE7;      // SRC_CTRL2
    static constexpr uint8_t CMD_SRCTRL3  = 0xE8;      // SRC_CTRL3
    static constexpr uint8_t CMD_CHASHA   = 0xE9;      // Charge Share
    static constexpr uint8_t CMD_SRCTRL4  = 0xEA;      // SRC_CTRL4
    static constexpr uint8_t CMD_GADRTI   = 0xEC;      // Gate driver timing
    
    static constexpr uint8_t CMD_TEAEFF   = 0xF1;      // tearing effect
    static constexpr uint8_t CMD_INTCTRL  = 0xF6;      // interface control
	static constexpr uint8_t CMD_PRIACC   = 0xFD;      // Private access

    const uint8_t* getInitCommands(uint8_t listno) const override {
      static constexpr uint8_t list0[] = {
      	  
	      CMD_PRIACC , 2, 0x06, 0x08,
      	  CMD_OSCSET , 2, 0x07, 0x04,
      	  
          CMD_BIASSET, 3, 0x00, 0x44, 0x45,
      	  
          CMD_VGLSET , 4, 0x41, 0x07, 0x12, 0x12,
      	  CMD_VGHSET , 1, 0x37,
      	  CMD_VSPSET , 3, 0x09, 0x10, 0x21,
      	  CMD_VSNSET , 3, 0x09, 0x10, 0x21,
      	  	  
          CMD_PCLKSET, 2, 0x21, 0x40,
      	  
          CMD_GAMREF1, 4, 0x90, 0x4C, 0x50, 0x70,
      	  
      	  CMD_FRARATE, 3, 0x0F, 0x02, 0x01,
      	  CMD_DPCTRL , 1, 0x01,
      	  CMD_BLAPRO , 4, 0x02, 0x02, 0x0A, 0x14,
      	  CMD_DISFUNC, 5, 0x04, 0x01, 0x9F, 0x00, 0x02,
      	  CMD_PRIACC , 1, 0x11,
      	  
          //--------------------------------NV3030B gamma setting---------------------------------------//
      	  
          CMD_GAMPOS1, 8, 0x05, 0x06, 0x0A, 0x0C, 0x0B, 0x0B, 0x13, 0x19,
      	  CMD_GAMPOS2, 2, 0x05, 0x67,
      	  CMD_GAMPOS3, 6, 0x03, 0x00, 0x00, 0x30, 0x33, 0x3F,
      	  CMD_GAMNEG1, 8, 0x18, 0x13, 0x0D, 0x09, 0x0B, 0x0B, 0x05, 0x06,
      	  CMD_GAMNEG2, 2, 0x67, 0x06,
      	  CMD_GAMNEG3, 6, 0x3F, 0x33, 0x30, 0x00, 0x00, 0x03,
      	  
      	  CMD_SRCTRL1, 2, 0x00, 0xFF,
      	  CMD_SRCTRL2, 6, 0x01, 0x04, 0x03, 0x03, 0x00, 0x12,
      	  CMD_SRCTRL3, 3, 0x00, 0x70, 0x00,
      	  
      	  CMD_GADRTI , 1, 0x52,
      	  CMD_TEAEFF , 3, 0x01, 0x01, 0x02,
      	  
      	  CMD_INTCTRL, 4, 0x01, 0x30, 0x00, 0x00,
      	  CMD_PRIACC , 2, 0xFA, 0xFC,
      	  
      	  CMD_COLMOD , 1, 0x55,
      	  0x35       , 1, 0x00,
      	  CMD_INVON  , 0,
      	  
          CMD_SLPOUT , CMD_INIT_DELAY, 200,  // Delay_ms(200);
          CMD_DISPON , CMD_INIT_DELAY, 10,   //  Delay_ms(10);
          0xFF,0xFF, // end
      };
      switch (listno) {
      case 0: return list0;
      default: return nullptr;
      }
    }
  };

//----------------------------------------------------------------------------
 }
}
