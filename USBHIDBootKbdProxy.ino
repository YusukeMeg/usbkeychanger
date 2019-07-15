#include <hidboot.h>
#include <usbhub.h>

// Satisfy the IDE, which needs to see the include statment in the ino too.
#ifdef dobogusinclude
#include <spi4teensy3.h>
#endif
#include <SPI.h>

#include "Keyboard.h"

class KbdRptParser : public KeyboardReportParser
{
    void PrintKey(uint8_t mod, uint8_t key);

  protected:
    void OnControlKeysChanged(uint8_t before, uint8_t after);

    void OnKeyDown	(uint8_t mod, uint8_t key);
    void OnKeyUp	(uint8_t mod, uint8_t key);
    void OnKeyPressed(uint8_t key);
};

char bmNumLock = 0;

char oemToModAscii(char m, char key) {
  
  
  MODIFIERKEYS mod;
  *((uint8_t*)&mod) = m;

  
  if (bmNumLock  == 1) {
        switch(key){
       case 0x2D:
          return('[');
          break;
      case 0x2E:
          return('^');
          break;
      case 0x89:
          return('¥');
          break;

      case 0x1A:
          return(',');
          break;
      case 0x08:
          return('.');
          break;
      case 0x15:
          return('p');
          break;
      case 0x17:
          return('y');
          break;
      case 0x1C:
          return('f');
          break;
      case 0x18:
          return('g');
          break;
      case 0x0C:
          return('c');
          break;
      case 0x12:
          return('r');
          break;
      case 0x13:
          return('l');
          break;
      case 0x2F:
          return('@');
          break;
      case 0x30:
          return('/');
          break;
      case 0x04:
          return('a');
          break;
      case 0x16:
          return('o');
          break;
      case 0x07:
          return('e');
          break;
      case 0x09:
          return('u');
          break;
      case 0x0A:
          return('i');
          break;
      case 0x0B:
          return('d');
          break;
      case 0x0D:
          return('h');
          break;
      case 0x0E:
          return('t');
          break;
      case 0x0F:
          return('n');
          break;
      case 0x33:
          return('s');
          break;
      case 0x34:
          return('S');
          break;
      case 0x32:
          return('=');
          break;
      case 0x1D:
          return(';');
          break;
      case 0x1B:
          return('q');
          break;
      case 0x06:
          return('j');
          break;
      case 0x19:
          return('k');
          break;
      case 0x05:
          return('x');
          break;
      case 0x11:
          return('b');
          break;
      case 0x10:
          return('m');
          break;
      case 0x36:
          return('w');
          break;
      case 0x37:
          return('v');
          break;
      case 0x38:
          return('z');
          break;
      case 0x87:
          return('{');
          break;
          
        }
  } else {
    
//    switch (key) {
//
//      case 0x1E:
//        return ('1');
//        break;
//      case 0x1F:
//        return ('2');
//        break;
//      case 0x20:
//        return ('3');
//        break;
//      case 0x21:
//        return ('4');
//        break;
//      case 0x22:
//        return ('5');
//        break;
//      case 0x23:
//        return ('6');
//        break;
//      case 0x24:
//        return ('7');
//        break;
//      case 0x25:
//        return ('8');
//        break;
//      case 0x26:
//        return ('9');
//        break;
//      case 0x27:
//        return ('0');
//        break;
//      case 0x2D:
//        return ('-');
//        break;
//      case 0x2E:
//        return ('^');
//        break;
//      case 0x89:
//        return ('¥');
//        break;
//      case 0x28:
//        return (0xB0);
//        break;
//      case 0x2A:
//        return (0xB2);
//        break;
//      case 0x2B:
//        return (0xB3);
//        break;
//      case 0x14:
//        return ('q');
//        break;
//      case 0x1A:
//        return ('w');
//        break;
//      case 0x08:
//        return ('e');
//        break;
//      case 0x15:
//        return ('r');
//        break;
//      case 0x17:
//        return ('t');
//        break;
//      case 0x1C:
//        return ('y');
//        break;
//      case 0x18:
//        return ('u');
//        break;
//      case 0x0C:
//        return ('i');
//        break;
//      case 0x12:
//        return ('o');
//        break;
//      case 0x13:
//        return ('p');
//        break;
//      case 0x2F:
//        return ('@');
//        break;
//      case 0x30:
//        return ('[');
//        break;
//      case 0x31:
////            return('\');
//        break;
//
//      case 0x04:
//        return ('a');
//        break;
//      case 0x16:
//        return ('s');
//        break;
//      case 0x07:
//        return ('d');
//        break;
//      case 0x09:
//        return ('f');
//        break;
//      case 0x0A:
//        return ('g');
//        break;
//      case 0x0B:
//        return ('h');
//        break;
//      case 0x0D:
//        return ('j');
//        break;
//      case 0x0E:
//        return ('k');
//        break;
//      case 0x0F:
//        return ('l');
//        break;
//      case 0x33:
//        return (';');
//        break;
//      case 0x34:
//        return (':');
//        break;
//      case 0x32:
//        return (']');
//        break;
//
//      case 0xE1:
//        return (0x81);
//        break;
//      case 0x1D:
//        return ('z');
//        break;
//      case 0x1B:
//        return ('x');
//        break;
//      case 0x06:
//        return ('c');
//        break;
//      case 0x19:
//        return ('v');
//        break;
//      case 0x05:
//        return ('b');
//        break;
//      case 0x11:
//        return ('n');
//        break;
//      case 0x10:
//        return ('m');
//        break;
//      case 0x36:
//        return (',');
//        break;
//      case 0x37:
//        return ('.');
//        break;
//      case 0x38:
//        return ('/');
//        break;
//      case 0x87:
//        return ('_');
//        break;
//
//      case 0xE0:
//        return (0x80);
//        break;
//      case 0xE2:
//        return (0x82);
//        break;
//
//      case 0xE6:
//        return (0x86);
//        break;
//      case 0xE4:
//        return (0x84);
//        break;
//      case 0x49:
//        return (0xD1);
//        break;
//      case 0x4C:
//        return (0xD4);
//        break;
//      case 0x50:
//        return (0xD8);
//        break;
//      case 0x4A:
//        return (0xD2);
//        break;
//      case 0x4D:
//        return (0xD5);
//        break;
//      case 0x52:
//        return (0xDA);
//        break;
//      case 0x51:
//        return (0xD9);
//        break;
//      case 0x4B:
//        return (0xD3);
//        break;
//      case 0x4E:
//        return (0xD6);
//        break;
//      case 0x4F:
//        return (0xD7);
//        break;
//      case 0x2C:
//        return (0x20);
//        break;
//
//      case 0x5F:
//        return ('7');
//        break;
//      case 0x5C:
//        return ('4');
//        break;
//      case 0x59:
//        return ('1');
//        break;
//      case 0x54:
//        return ('/');
//        break;
//      case 0x60:
//        return ('8');
//        break;
//      case 0x5D:
//        return ('5');
//        break;
//      case 0x5A:
//        return ('2');
//        break;
//      case 0x62:
//        return ('0');
//        break;
//      case 0x55:
//        return ('*');
//        break;
//      case 0x61:
//        return ('9');
//        break;
//      case 0x5E:
//        return ('6');
//        break;
//      case 0x5B:
//        return ('3');
//        break;
//      case 0x63:
//        return ('.');
//        break;
//      case 0x56:
//        return ('-');
//        break;
//      case 0x57:
//        return ('+');
//        break;
//      case 0x58:
//        return (0xB0);
//        break;
//      case 0x29:
//        return (0xB1);
//        break;
//      case 0x3A:
//        return (0xC2);
//        break;
//      case 0x3B:
//        return (0xC3);
//        break;
//      case 0x3C:
//        return (0xC4);
//        break;
//      case 0x3D:
//        return (0xC5);
//        break;
//      case 0x3E:
//        return (0xC6);
//        break;
//      case 0x3F:
//        return (0xC7);
//        break;
//      case 0x40:
//        return (0xC8);
//        break;
//      case 0x41:
//        return (0xC9);
//        break;
//      case 0x42:
//        return (0xCA);
//        break;
//      case 0x43:
//        return (0xCB);
//        break;
//      case 0x44:
//        return (0xCC);
//        break;
//      case 0x45:
//        return (0xCD);
//        break;
//
//      case 0xE3:
//        return (0x83);
//        break;
//      case 0xE7:
//        return (0x87);
//        break;
//      case 0x39:
//        return(0xC1);
//        break;
//      case 0x53:
//        bmNumLock=0;
//        break;
//      default:
//        return (0);
//        break;
    }

  return(key+136);



}


void KbdRptParser::PrintKey(uint8_t m, uint8_t key)
{
  MODIFIERKEYS mod;
  *((uint8_t*)&mod) = m;
  Serial.print((mod.bmLeftCtrl   == 1) ? "C" : " ");
  Serial.print((mod.bmLeftShift  == 1) ? "S" : " ");
  Serial.print((mod.bmLeftAlt    == 1) ? "A" : " ");
  Serial.print((mod.bmLeftGUI    == 1) ? "G" : " ");

  Serial.print(" >");
  PrintHex<uint8_t>(key, 0x80);
  Serial.print("< ");

  Serial.print((mod.bmRightCtrl   == 1) ? "C" : " ");
  Serial.print((mod.bmRightShift  == 1) ? "S" : " ");
  Serial.print((mod.bmRightAlt    == 1) ? "A" : " ");
  Serial.println((mod.bmRightGUI    == 1) ? "G" : " ");
};

void KbdRptParser::OnKeyDown(uint8_t mod, uint8_t key)
{
  Serial.print("DN ");
  PrintKey(mod, key);

  uint8_t c = OemToAscii(mod, key);

  if (c) {
    OnKeyPressed(c);

  }
  if(key == 0x53){
    bmNumLock = bmNumLock ^ 0x1;
  }
    
  
  Keyboard.press(oemToModAscii(mod, key));

}

void KbdRptParser::OnControlKeysChanged(uint8_t before, uint8_t after) {

  MODIFIERKEYS beforeMod;
  *((uint8_t*)&beforeMod) = before;

  MODIFIERKEYS afterMod;
  *((uint8_t*)&afterMod) = after;

  if (beforeMod.bmLeftCtrl != afterMod.bmLeftCtrl) {
    if (afterMod.bmLeftCtrl) {
      Keyboard.press(KEY_LEFT_CTRL);
    } else {
      Keyboard.release(KEY_LEFT_CTRL);
    }
    Serial.println("LeftCtrl changed");
  }
  if (beforeMod.bmLeftShift != afterMod.bmLeftShift) {
    if (afterMod.bmLeftShift) {
      Keyboard.press(KEY_LEFT_SHIFT);
    } else {
      Keyboard.release(KEY_LEFT_SHIFT);
    }
    Serial.println("LeftShift changed");
  }
  if (beforeMod.bmLeftAlt != afterMod.bmLeftAlt) {
    if (afterMod.bmLeftAlt) {
      Keyboard.press(KEY_LEFT_ALT);
    } else {
      Keyboard.release(KEY_LEFT_ALT);
    }
    Serial.println("LeftAlt changed");
  }
  if (beforeMod.bmLeftGUI != afterMod.bmLeftGUI) {
    if (afterMod.bmLeftGUI) {
      Keyboard.press(KEY_LEFT_GUI);
    } else {
      Keyboard.release(KEY_LEFT_GUI);
    }
    Serial.println("LeftGUI changed");
  }

  if (beforeMod.bmRightCtrl != afterMod.bmRightCtrl) {
    if (afterMod.bmRightCtrl) {
      Keyboard.press(KEY_RIGHT_CTRL);
    } else {
      Keyboard.release(KEY_RIGHT_CTRL);
    }
    Serial.println("RightCtrl changed");
  }
  if (beforeMod.bmRightShift != afterMod.bmRightShift) {
    if (afterMod.bmRightShift) {
      Keyboard.press(KEY_RIGHT_SHIFT);
    } else {
      Keyboard.release(KEY_RIGHT_SHIFT);
    }
    Serial.println("RightShift changed");
  }
  if (beforeMod.bmRightAlt != afterMod.bmRightAlt) {
    if (afterMod.bmRightAlt) {
      Keyboard.press(KEY_RIGHT_ALT);
    } else {
      Keyboard.release(KEY_RIGHT_ALT);
    }
    Serial.println("RightAlt changed");
  }
  if (beforeMod.bmRightGUI != afterMod.bmRightGUI) {
    if (afterMod.bmRightGUI) {
      Keyboard.press(KEY_RIGHT_GUI);
    } else {
      Keyboard.release(KEY_RIGHT_GUI);
    }
    Serial.println("RightGUI changed");
  }

}

void KbdRptParser::OnKeyUp(uint8_t mod, uint8_t key)
{
  Serial.print("UP ");
  Serial.print(key);

  PrintKey(mod, key);

  Keyboard.release(oemToModAscii(mod, key));


}

void KbdRptParser::OnKeyPressed(uint8_t key)
{
  Serial.print("ASCII: ");
  Serial.println((char)key);
};

USB     Usb;
//USBHub     Hub(&Usb);
HIDBoot<USB_HID_PROTOCOL_KEYBOARD>    HidKeyboard(&Usb);

KbdRptParser Prs;

void setup()
{
//  Serial.begin( 9600 );

#if !defined(__MIPSEL__)
//  while (!Serial); // Wait for serial port to connect - used on Leonardo, Teensy and other boards with built-in USB CDC serial connection
#endif
//  Serial.println("Start");

  if (Usb.Init() == -1)
//    Serial.println("OSC did not start.");

  Keyboard.begin();

  delay( 200 );

  HidKeyboard.SetReportParser(0, &Prs);
}

void loop()
{
  Usb.Task();
}
