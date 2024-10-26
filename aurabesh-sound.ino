
/*********************************************************************
|original code The Last Outpost Workshop code to display Aurebesh (video here The Last Outpost Workshop )
|
|Edited for Scopenator 2000 by Mordred 06-08-2024
|Random slection code by Darwinwaswrong in Wokwi discord.

  i2c SH1106 modified by Rupert Hirst  12/09/21
*********************************************************************/

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>


const uint8_t Aurebesh8pt7bBitmaps[] PROGMEM = {
  0x00, 0x5B, 0xDA, 0xC3, 0xE3, 0x33, 0x1B, 0x0F, 0x00, 0x00, 0x0D, 0x80,
  0x0D, 0x80, 0x7F, 0xFF, 0xFF, 0xFC, 0x0D, 0x9C, 0x0D, 0xB8, 0x00, 0x70,
  0x00, 0xE0, 0x01, 0xC0, 0x03, 0x80, 0x03, 0x00, 0x0E, 0x00, 0x00, 0x00,
  0xED, 0xB6, 0x80, 0x33, 0x33, 0xFF, 0x33, 0x33, 0xCC, 0xCC, 0xFF, 0xCC,
  0xCC, 0x00, 0x00, 0xFF, 0xC0, 0xFF, 0xF0, 0xDE, 0xF7, 0xBD, 0x80, 0x33,
  0x33, 0x3C, 0xCC, 0xCC, 0xFF, 0xFF, 0xFF, 0xF0, 0x07, 0x80, 0x3C, 0x01,
  0xE0, 0x0F, 0x00, 0x78, 0x03, 0xFF, 0xFF, 0xFF, 0xC0, 0x37, 0xB3, 0x33,
  0x33, 0x33, 0xFF, 0xFF, 0xFF, 0xC0, 0x06, 0x00, 0x3F, 0xFF, 0xFF, 0xFF,
  0x00, 0x18, 0x00, 0xFF, 0xFF, 0xFF, 0xC0, 0xFF, 0xFF, 0xFF, 0xC0, 0x06,
  0x00, 0x37, 0xFF, 0xFF, 0xFC, 0x00, 0x60, 0x03, 0xFF, 0xFF, 0xFF, 0xC0,
  0x00, 0x60, 0xE3, 0x0E, 0x00, 0x60, 0x07, 0xFF, 0xFF, 0xFC, 0x01, 0x80,
  0x0C, 0x00, 0x60, 0x03, 0x00, 0xFF, 0xFF, 0xFF, 0xF0, 0x01, 0x80, 0x0F,
  0xFF, 0xFF, 0xFC, 0x00, 0x60, 0x03, 0xFF, 0xFF, 0xFF, 0xC0, 0xFF, 0xFF,
  0xFF, 0xF0, 0x01, 0x80, 0x0F, 0xFF, 0xFF, 0xFF, 0x00, 0x78, 0x03, 0xFF,
  0xFF, 0xFF, 0xC0, 0xFF, 0xFF, 0xFE, 0x00, 0xC0, 0x18, 0x03, 0x00, 0x70,
  0x0E, 0x01, 0xC0, 0x38, 0x07, 0x00, 0xFF, 0xFF, 0xFF, 0xF0, 0x07, 0x80,
  0x3F, 0xFF, 0xFF, 0xFF, 0x00, 0x78, 0x03, 0xFF, 0xFF, 0xFF, 0xC0, 0xFF,
  0xFF, 0xFF, 0xF0, 0x07, 0x80, 0x3F, 0xFF, 0xFF, 0xFC, 0x00, 0x60, 0x03,
  0xFF, 0xFF, 0xFF, 0xC0, 0x84, 0x30, 0xC3, 0x7F, 0xE0, 0xFF, 0xFF, 0xF0,
  0x00, 0x00, 0x00, 0xE7, 0xB7, 0xBD, 0x8C, 0x63, 0x33, 0x00, 0x00, 0xC0,
  0x0F, 0xE0, 0x1E, 0x3F, 0xFC, 0x1F, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x03,
  0xFF, 0x01, 0xFF, 0xE0, 0xC0, 0x3C, 0x60, 0x07, 0xC0, 0x3F, 0xF8, 0x3F,
  0xFC, 0x60, 0x06, 0x80, 0x01, 0x07, 0xE0, 0x07, 0xE0, 0x00, 0x00, 0xE0,
  0x07, 0x3F, 0xFC, 0x3F, 0xFC, 0xC0, 0x30, 0x0C, 0x03, 0x33, 0xCC, 0xF3,
  0x3C, 0xCC, 0x03, 0x00, 0xC0, 0x30, 0x7F, 0xFF, 0xFE, 0x00, 0xC0, 0x18,
  0x3F, 0x07, 0xF0, 0x0E, 0x01, 0xC0, 0x38, 0x07, 0x00, 0xC0, 0x7E, 0xC0,
  0xFD, 0x83, 0xB1, 0x86, 0x63, 0x1C, 0xC3, 0x31, 0x86, 0x63, 0x07, 0x86,
  0x0F, 0x0C, 0x0C, 0x18, 0x03, 0x02, 0x06, 0x3C, 0x0F, 0xE7, 0xFF, 0x0F,
  0xF0, 0x18, 0x60, 0x30, 0xC0, 0x61, 0x80, 0xFF, 0xFF, 0xFF, 0xFC, 0xCF,
  0xFF, 0x9F, 0xFB, 0x00, 0x66, 0x00, 0xCC, 0x03, 0x18, 0x0E, 0x30, 0x18,
  0x60, 0x60, 0xFF, 0xC1, 0xFF, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00,
  0x00, 0x00, 0x1F, 0xF8, 0x1F, 0xF8, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF,
  0xFF, 0xFF, 0x3B, 0xF7, 0xB1, 0x8C, 0x63, 0x18, 0xC0, 0x00, 0x0E, 0x00,
  0x38, 0x01, 0xE0, 0x1F, 0xCF, 0xFB, 0x1F, 0x86, 0x00, 0x18, 0x00, 0x30,
  0xFF, 0xC1, 0xFF, 0x80, 0xFF, 0xFF, 0xFF, 0xFC, 0x00, 0x18, 0x00, 0x30,
  0x00, 0x60, 0x00, 0xC0, 0x01, 0x80, 0x03, 0xFF, 0xFF, 0xFF, 0xFC, 0x01,
  0x80, 0xC0, 0x60, 0x3C, 0x1F, 0x0D, 0xE6, 0x3B, 0x0F, 0x81, 0xC0, 0x07,
  0x86, 0xC3, 0x03, 0x01, 0x81, 0x80, 0xC0, 0xC0, 0x7F, 0xFF, 0x80, 0x31,
  0xC0, 0xC3, 0x83, 0x8F, 0x86, 0x1B, 0x0C, 0x73, 0x18, 0xC6, 0x33, 0x86,
  0x76, 0x0C, 0x7C, 0x0C, 0x70, 0x1C, 0x0F, 0xE0, 0x3F, 0xE0, 0x60, 0xC1,
  0xC1, 0xC3, 0x01, 0x8E, 0x03, 0x98, 0x03, 0x70, 0x07, 0xFF, 0xFE, 0xFF,
  0xF8, 0x38, 0xDE, 0x3C, 0x0F, 0x03, 0xC0, 0xF0, 0x3C, 0x0F, 0x83, 0x7F,
  0xCF, 0xF0, 0xFF, 0xFF, 0xFF, 0xF0, 0x07, 0x80, 0x3C, 0x00, 0x60, 0x03,
  0x00, 0x18, 0x00, 0xFF, 0x87, 0xF8, 0x00, 0x7F, 0xFF, 0xFE, 0x00, 0xC0,
  0x18, 0x03, 0x00, 0x70, 0x0E, 0x01, 0xC0, 0x38, 0x07, 0x00, 0x1C, 0x0C,
  0x38, 0x30, 0x70, 0xC0, 0xC3, 0x01, 0x8E, 0x03, 0x3F, 0x0E, 0xDF, 0x1F,
  0x0F, 0x3C, 0x0C, 0x70, 0x03, 0x00, 0x0C, 0x00, 0x30, 0x00, 0xC0, 0x03,
  0x03, 0x8C, 0x77, 0x33, 0x8E, 0xDC, 0x1F, 0xE0, 0x3F, 0x00, 0xC1, 0xFF,
  0x07, 0xFC, 0x30, 0xF1, 0x83, 0xC8, 0x0F, 0x00, 0x3C, 0x00, 0xF0, 0x03,
  0xFF, 0xFF, 0xFF, 0xF0, 0xE1, 0xDC, 0xE3, 0x30, 0x78, 0x0C, 0x03, 0x00,
  0xC0, 0x30, 0x0C, 0x03, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x1E, 0x00,
  0x3C, 0x00, 0x78, 0x00, 0xF0, 0x01, 0xE0, 0x03, 0xFF, 0xFF, 0xFF, 0xFC,
  0x07, 0x00, 0x78, 0x03, 0x60, 0x33, 0x81, 0x8C, 0x18, 0x71, 0xC1, 0x8C,
  0x06, 0xFF, 0xF3, 0xFF, 0xC0, 0xFC, 0x1F, 0xE1, 0xDB, 0x8C, 0xCC, 0xE3,
  0x06, 0x18, 0x30, 0x63, 0x03, 0x18, 0x0D, 0x80, 0x7C, 0x00, 0x00, 0x18,
  0x00, 0xC3, 0xFE, 0x3F, 0xF3, 0x81, 0xB8, 0x0C, 0x00, 0x60, 0x03, 0xFF,
  0xFF, 0xFF, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x0F, 0xE0,
  0x1E, 0x3F, 0xFC, 0x1F, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x03, 0xFF, 0x01,
  0xFF, 0xE0, 0xC0, 0x3C, 0x60, 0x07, 0xC0, 0x3F, 0xF8, 0x3F, 0xFC, 0x60,
  0x06, 0x80, 0x01, 0x07, 0xE0, 0x07, 0xE0, 0x00, 0x00, 0xE0, 0x07, 0x3F,
  0xFC, 0x3F, 0xFC, 0xC0, 0x30, 0x0C, 0x03, 0x33, 0xCC, 0xF3, 0x3C, 0xCC,
  0x03, 0x00, 0xC0, 0x30, 0x7F, 0xFF, 0xFE, 0x00, 0xC0, 0x18, 0x3F, 0x07,
  0xF0, 0x0E, 0x01, 0xC0, 0x38, 0x07, 0x00, 0xC0, 0x7E, 0xC0, 0xFD, 0x83,
  0xB1, 0x86, 0x63, 0x1C, 0xC3, 0x31, 0x86, 0x63, 0x07, 0x86, 0x0F, 0x0C,
  0x0C, 0x18, 0x03, 0x02, 0x06, 0x3C, 0x0F, 0xE7, 0xFF, 0x0F, 0xF0, 0x18,
  0x60, 0x30, 0xC0, 0x61, 0x80, 0xFF, 0xFF, 0xFF, 0xFC, 0xCF, 0xFF, 0x9F,
  0xFB, 0x00, 0x66, 0x00, 0xCC, 0x03, 0x18, 0x0E, 0x30, 0x18, 0x60, 0x60,
  0xFF, 0xC1, 0xFF, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00,
  0x1F, 0xF8, 0x1F, 0xF8, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF,
  0x3B, 0xF7, 0xB1, 0x8C, 0x63, 0x18, 0xC0, 0x00, 0x0E, 0x00, 0x38, 0x01,
  0xE0, 0x1F, 0xCF, 0xFB, 0x1F, 0x86, 0x00, 0x18, 0x00, 0x30, 0xFF, 0xC1,
  0xFF, 0x80, 0xFF, 0xFF, 0xFF, 0xFC, 0x00, 0x18, 0x00, 0x30, 0x00, 0x60,
  0x00, 0xC0, 0x01, 0x80, 0x03, 0xFF, 0xFF, 0xFF, 0xFC, 0x01, 0x80, 0xC0,
  0x60, 0x3C, 0x1F, 0x0D, 0xE6, 0x3B, 0x0F, 0x81, 0xC0, 0x07, 0x86, 0xC3,
  0x03, 0x01, 0x81, 0x80, 0xC0, 0xC0, 0x7F, 0xFF, 0x80, 0x31, 0xC0, 0xC3,
  0x83, 0x8F, 0x86, 0x1B, 0x0C, 0x73, 0x18, 0xC6, 0x33, 0x86, 0x76, 0x0C,
  0x7C, 0x0C, 0x70, 0x1C, 0x0F, 0xE0, 0x3F, 0xE0, 0x60, 0xC1, 0xC1, 0xC3,
  0x01, 0x8E, 0x03, 0x98, 0x03, 0x70, 0x07, 0xFF, 0xFE, 0xFF, 0xF8, 0x38,
  0xDE, 0x3C, 0x0F, 0x03, 0xC0, 0xF0, 0x3C, 0x0F, 0x83, 0x7F, 0xCF, 0xF0,
  0xFF, 0xFF, 0xFF, 0xF0, 0x07, 0x80, 0x3C, 0x00, 0x60, 0x03, 0x00, 0x18,
  0x00, 0xFF, 0x87, 0xF8, 0x00, 0x7F, 0xFF, 0xFE, 0x00, 0xC0, 0x18, 0x03,
  0x00, 0x70, 0x0E, 0x01, 0xC0, 0x38, 0x07, 0x00, 0x1C, 0x0C, 0x38, 0x30,
  0x70, 0xC0, 0xC3, 0x01, 0x8E, 0x03, 0x3F, 0x0E, 0xDF, 0x1F, 0x0F, 0x3C,
  0x0C, 0x70, 0x03, 0x00, 0x0C, 0x00, 0x30, 0x00, 0xC0, 0x03, 0x03, 0x8C,
  0x77, 0x33, 0x8E, 0xDC, 0x1F, 0xE0, 0x3F, 0x00, 0xC1, 0xFF, 0x07, 0xFC,
  0x30, 0xF1, 0x83, 0xC8, 0x0F, 0x00, 0x3C, 0x00, 0xF0, 0x03, 0xFF, 0xFF,
  0xFF, 0xF0, 0xE1, 0xDC, 0xE3, 0x30, 0x78, 0x0C, 0x03, 0x00, 0xC0, 0x30,
  0x0C, 0x03, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x1E, 0x00, 0x3C, 0x00,
  0x78, 0x00, 0xF0, 0x01, 0xE0, 0x03, 0xFF, 0xFF, 0xFF, 0xFC, 0x07, 0x00,
  0x78, 0x03, 0x60, 0x33, 0x81, 0x8C, 0x18, 0x71, 0xC1, 0x8C, 0x06, 0xFF,
  0xF3, 0xFF, 0xC0, 0xFC, 0x1F, 0xE1, 0xDB, 0x8C, 0xCC, 0xE3, 0x06, 0x18,
  0x30, 0x63, 0x03, 0x18, 0x0D, 0x80, 0x7C, 0x00, 0x00, 0x18, 0x00, 0xC3,
  0xFE, 0x3F, 0xF3, 0x81, 0xB8, 0x0C, 0x00, 0x60, 0x03, 0xFF, 0xFF, 0xFF,
  0xC0, 0x00, 0x00, 0x00, 0x00 };

const GFXglyph Aurebesh8pt7bGlyphs[] PROGMEM = {
  {     0,   1,   1,   8,    0,    0 },   // 0x20 ' '
  {     1,   2,   8,   5,    0,   -8 },   // 0x21 '!'
  {     3,   9,   5,   9,    0,  -10 },   // 0x22 '"'
  {     9,   1,   1,   8,    0,    0 },   // 0x23 '#'
  {    10,  16,  12,  16,    0,  -11 },   // 0x24 '$'
  {    34,   1,   1,   8,    0,    0 },   // 0x25 '%'
  {    35,   1,   1,   8,    0,    0 },   // 0x26 '&'
  {    36,   3,   6,   5,    0,  -10 },   // 0x27 '''
  {    39,   4,  10,   6,    0,   -9 },   // 0x28 '('
  {    44,   4,  10,   6,    0,   -9 },   // 0x29 ')'
  {    49,   1,   1,   8,    0,    0 },   // 0x2A '*'
  {    50,   1,   1,   8,    0,    0 },   // 0x2B '+'
  {    51,   2,   5,   4,    0,   -4 },   // 0x2C ','
  {    53,   6,   2,   8,    0,   -9 },   // 0x2D '-'
  {    55,   5,   5,   7,    0,   -4 },   // 0x2E '.'
  {    59,   4,  10,   6,    0,   -9 },   // 0x2F '/'
  {    64,  13,  10,  15,    0,   -9 },   // 0x30 '0'
  {    81,   4,  10,   5,    0,   -9 },   // 0x31 '1'
  {    86,  13,  10,  15,    0,   -9 },   // 0x32 '2'
  {   103,  13,  10,  15,    0,   -9 },   // 0x33 '3'
  {   120,  13,  10,  15,    0,   -9 },   // 0x34 '4'
  {   137,  13,  10,  15,    0,   -9 },   // 0x35 '5'
  {   154,  13,  10,  15,    0,   -9 },   // 0x36 '6'
  {   171,  12,  10,  14,    0,   -9 },   // 0x37 '7'
  {   186,  13,  10,  15,    0,   -9 },   // 0x38 '8'
  {   203,  13,  10,  15,    0,   -9 },   // 0x39 '9'
  {   220,   5,   7,   7,    0,   -6 },   // 0x3A ':'
  {   225,   2,  10,   4,    0,   -9 },   // 0x3B ';'
  {   228,   1,   1,   8,    0,    0 },   // 0x3C '<'
  {   229,   1,   1,   8,    0,    0 },   // 0x3D '='
  {   230,   1,   1,   8,    0,    0 },   // 0x3E '>'
  {   231,   5,  10,   7,    0,   -9 },   // 0x3F '?'
  {   238,   1,   1,   8,    0,    0 },   // 0x40 '@'
  {   239,  17,  10,  17,    0,   -9 },   // 0x41 'A'
  {   261,  16,  10,  17,    0,   -9 },   // 0x42 'B'
  {   281,  10,  10,  12,    0,   -9 },   // 0x43 'C'
  {   294,  12,  10,  12,    0,   -9 },   // 0x44 'D'
  {   309,  15,  10,  16,    0,   -9 },   // 0x45 'E'
  {   328,  15,  10,  16,    0,   -9 },   // 0x46 'F'
  {   347,  15,  10,  15,    0,   -9 },   // 0x47 'G'
  {   366,  16,  10,  17,    0,   -9 },   // 0x48 'H'
  {   386,   5,  10,   7,    0,   -9 },   // 0x49 'I'
  {   393,  15,  10,  15,    0,   -9 },   // 0x4A 'J'
  {   412,  15,  10,  17,    0,   -9 },   // 0x4B 'K'
  {   431,   9,  10,  11,    0,   -9 },   // 0x4C 'L'
  {   443,   9,  10,  10,    0,   -9 },   // 0x4D 'M'
  {   455,  15,  10,  15,    0,   -9 },   // 0x4E 'N'
  {   474,  15,  10,  16,    0,   -9 },   // 0x4F 'O'
  {   493,  10,  10,  12,    0,   -9 },   // 0x50 'P'
  {   506,  13,  10,  14,    0,   -9 },   // 0x51 'Q'
  {   523,  12,  10,  12,    0,   -9 },   // 0x52 'R'
  {   538,  14,  10,  16,    0,   -9 },   // 0x53 'S'
  {   556,  14,  10,  15,    0,   -9 },   // 0x54 'T'
  {   574,  14,  10,  16,    0,   -9 },   // 0x55 'U'
  {   592,  10,  10,  12,    0,   -9 },   // 0x56 'V'
  {   605,  15,  10,  17,    0,   -9 },   // 0x57 'W'
  {   624,  13,  10,  13,    0,   -9 },   // 0x58 'X'
  {   641,  13,  10,  14,    0,   -9 },   // 0x59 'Y'
  {   658,  13,  10,  15,    0,   -9 },   // 0x5A 'Z'
  {   675,   1,   1,   8,    0,    0 },   // 0x5B '['
  {   676,   1,   1,   8,    0,    0 },   // 0x5C '\'
  {   677,   1,   1,   8,    0,    0 },   // 0x5D ']'
  {   678,   1,   1,   8,    0,    0 },   // 0x5E '^'
  {   679,   1,   1,   8,    0,    0 },   // 0x5F '_'
  {   680,   1,   1,   8,    0,    0 },   // 0x60 '`'
  {   681,  17,  10,  17,    0,   -9 },   // 0x61 'a'
  {   703,  16,  10,  17,    0,   -9 },   // 0x62 'b'
  {   723,  10,  10,  12,    0,   -9 },   // 0x63 'c'
  {   736,  12,  10,  12,    0,   -9 },   // 0x64 'd'
  {   751,  15,  10,  16,    0,   -9 },   // 0x65 'e'
  {   770,  15,  10,  16,    0,   -9 },   // 0x66 'f'
  {   789,  15,  10,  15,    0,   -9 },   // 0x67 'g'
  {   808,  16,  10,  17,    0,   -9 },   // 0x68 'h'
  {   828,   5,  10,   7,    0,   -9 },   // 0x69 'i'
  {   835,  15,  10,  15,    0,   -9 },   // 0x6A 'j'
  {   854,  15,  10,  17,    0,   -9 },   // 0x6B 'k'
  {   873,   9,  10,  11,    0,   -9 },   // 0x6C 'l'
  {   885,   9,  10,  11,    0,   -9 },   // 0x6D 'm'
  {   897,  15,  10,  15,    0,   -9 },   // 0x6E 'n'
  {   916,  15,  10,  16,    0,   -9 },   // 0x6F 'o'
  {   935,  10,  10,  12,    0,   -9 },   // 0x70 'p'
  {   948,  13,  10,  14,    0,   -9 },   // 0x71 'q'
  {   965,  12,  10,  12,    0,   -9 },   // 0x72 'r'
  {   980,  14,  10,  16,    0,   -9 },   // 0x73 's'
  {   998,  14,  10,  15,    0,   -9 },   // 0x74 't'
  {  1016,  14,  10,  16,    0,   -9 },   // 0x75 'u'
  {  1034,  10,  10,  11,    0,   -9 },   // 0x76 'v'
  {  1047,  15,  10,  17,    0,   -9 },   // 0x77 'w'
  {  1066,  13,  10,  13,    0,   -9 },   // 0x78 'x'
  {  1083,  13,  10,  14,    0,   -9 },   // 0x79 'y'
  {  1100,  13,  10,  15,    0,   -9 },   // 0x7A 'z'
  {  1117,   1,   1,   8,    0,    0 },   // 0x7B '{'
  {  1118,   1,   1,   8,    0,    0 },   // 0x7C '|'
  {  1119,   1,   1,   8,    0,    0 },   // 0x7D '}'
  {  1120,   1,   1,   8,    0,    0 } }; // 0x7E '~'

const GFXfont Aurebesh8pt7b PROGMEM = {
  (uint8_t  *)Aurebesh8pt7bBitmaps,
  (GFXglyph *)Aurebesh8pt7bGlyphs,
  0x20, 0x7E, 12 };

// Approx. 1793 bytes


#define speakerPin 11
int k1 =1;
int k2 =1; 
int k3 =1;
int k4 =1;
int k5 =1;
int mult=1;
int potpin = A5;  // analog pin used to connect the potentiometer
int val=10;





/* Uncomment the initialize the I2C address , uncomment only one, If you get a totally blank screen try the other*/
#define i2c_Address 0x3c // initialize with the I2C addr 0x3C Typically eBay OLED's
//#define i2c_Address 0x3d //initialize with the I2C addr 0x3D Typically Adafruit OLED's

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define SCREEN_CENTER_X 64
#define SCREEN_CENTER_y 32

#define OLED_RESET -1 //   QT-PY / XIAO
Adafruit_SH1106G display = Adafruit_SH1106G(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Screen parameters with Aurebesh
const int AUREBESH_WIDTH = 18;
const int AUREBESH_HEIGHT = 15;
const int aurebeshScreenLines = 4;   // SCREEN_HEIGHT / AUREBESH_HEIGHT;
const int aurebeshScreenColumns = 7; // SCREEN_WIDTH / AUREBESH_WIDTH;
typedef struct
{
  int line;
  int column;
} AurebeshScreenCoordinate;
typedef struct
{
  int16_t x;
  int16_t y;
} PixelCoordinate;

typedef struct
{
  unsigned long time_start;
  unsigned long durationMs;
} Timer;

typedef struct
{
  uint16_t lx;
  uint16_t ly;
  uint16_t rx;
  uint16_t ry;
} resultPos;

static AurebeshScreenCoordinate currentCoordinate;
static const int cursorSpeed = 50;
static char currentlyShowing[aurebeshScreenLines][aurebeshScreenColumns + 1];


//noise,
// Screen Modes
enum Modes
{
  listing,
  listingAlert,
  aurebeshComplex,
   s1,
   s2,
   s3,
   s4,
   s5,
   s6,
   s7,
   s8,
   s9,
   s10,
   s11,
   s12,
   s13,
   s14,
   s15,
   s16,
   s17,
   s18,
   s19,
   s20
};
const int nbrModes = 8;

void setup()
{

  Serial.begin(57600);
  Serial.println("go");
    pinMode(speakerPin, OUTPUT);
    randomSeed(analogRead(0));
//for (int dogs_feet=0 ; dogs_feet <nbrModes;dogs_feet++ )
//  {
//    pinMode(dogs_feet, INPUT_PULLUP);
//  }

delay(250); // wait for the OLED to power up
  if (!display.begin(i2c_Address, true))
  {
    Serial.println(F("Oled Failed"));
    while (true)
    {
      /* code */
    }
  }

  initAurebeshScreen();
  display.display();
}

void loop()
{

    val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023)
  val = map(val, 0, 1023, 1, 20);     // scale it to use it with the servo (value between 0 and 180)
  int K5 = 2000;
  displayRandomScreenMode();
  displayCursor(currentCoordinate, random(500, 200), 200);






        
    
    /*
    for (int i1 = 0; i1 <= random(3, 9); i1++){
    Serial.println("start kbase");    
        digitalWrite(led3Pin, HIGH);  
        tone(speakerPin, K5 + random(-1700, 2000));          
        delay(random(70, 170));  
        digitalWrite(led3Pin, LOW);           
        noTone(speakerPin);         
        delay(random(0, 30));             
    } 
  */
    noTone(speakerPin);         
    Serial.println("start delay");
    delay(random(2000, 4000)); 
    Serial.println("end delay");                
}




void displayRandomScreenMode()
{
  int mode = getRandomMode();
  resetAurebeshScreen();
  switch (mode)
  {
  case listing:
    displayAurebeshString((char *)getRandomSentences());
    //transitionVertical();
    displayNoisePixelated(random(10, 300), false, random(10, 500));
    break;
  case listingAlert:
    resetAurebeshScreen();
    displayAurebeshString((char *)getRandomSentences());
    invertLine(getRandomLineNotEmptyCurrentlyShowing(), 50, 5000);
    //transitionVertical();
    displayNoisePixelated(random(10, 300), false, random(10, 500));
    break;
        case s1:shuffle(); break;
        case s2:shuffle(); break;
        case s3:shuffle(); break;
        case s4:shuffle(); break;
        case s5:shuffle();shuffle(); break;
        case s6:shuffle();shuffle(); break;
        case s7:shuffle();shuffle(); break;
        case s8:shuffle();shuffle(); break;
        case s9:shuffle();shuffle(); break;
        case s10:shuffle();shuffle();shuffle(); break;
        case s11:shuffle();shuffle();shuffle(); break;
        case s12:shuffle();shuffle();shuffle(); break;
        case s13:shuffle();shuffle();shuffle(); break;
        case s14:shuffle();shuffle();shuffle(); break;
        case s15:shuffle();shuffle();shuffle(); break;
        case s16:shuffle();shuffle();shuffle(); break;
        case s17:shuffle();shuffle();shuffle(); break;
        case s18:shuffle();shuffle();shuffle();shuffle(); break;
        case s19:shuffle();shuffle();shuffle();shuffle(); break;
        case s20:shuffle();shuffle();shuffle();shuffle();shuffle(); break;

  default:
    break;
  }
  display.clearDisplay();
}

void transitionVertical(void)
{
  int x1 = SCREEN_CENTER_X;
  int x2 = SCREEN_CENTER_X;

  while (x1 > 0)
  {
    display.drawFastVLine(x1, 0, SCREEN_HEIGHT, SH110X_WHITE);
    display.drawFastVLine(x2, 0, SCREEN_HEIGHT, SH110X_WHITE);
    display.display();
    delay(5);
    display.drawFastVLine(x1, 0, SCREEN_HEIGHT, SH110X_BLACK);
    display.drawFastVLine(x2, 0, SCREEN_HEIGHT, SH110X_BLACK);
    display.display();
    delay(5);
    x1--;
    x2++;
  }
}

void complexAurebesh(int durationsMS, int speedMS)
{
  AurebeshScreenCoordinate coord;
  char aurebeshChar;
  char displayed[aurebeshScreenLines][aurebeshScreenColumns];

  memset(displayed, -1, sizeof(displayed[0][0]) * aurebeshScreenLines * aurebeshScreenColumns);
  Timer time = initTimer(durationsMS);

  while (duration(time))
  {
    coord.line = random(aurebeshScreenLines);
    coord.column = random(aurebeshScreenColumns);
    aurebeshChar = random(32, 128);
    if (displayed[coord.line][coord.column] != -1)
    {
      display.setTextColor(SH110X_BLACK);
      displayAurebeshCharAtCoordinate(displayed[coord.line][coord.column], coord);
    }
    display.setTextColor(SH110X_WHITE);
    displayAurebeshCharAtCoordinate(aurebeshChar, coord);
    // Serial.println(displayed[coord.line][coord.column],DEC);
    displayed[coord.line][coord.column] = aurebeshChar;
    display.display();
    delay(speedMS);
  }
}





resultPos displayRectCentered(int16_t w, int16_t h)
{
  resultPos pos;
  pos.lx = SCREEN_CENTER_X - (w / 2);
  pos.ly = SCREEN_CENTER_y - (h / 2);
  pos.rx = pos.lx + w;
  pos.ry = pos.ly + h;
  display.drawRect(SCREEN_CENTER_X - (w / 2), SCREEN_CENTER_y - (h / 2), w, h, SH110X_WHITE);
  return pos;
}

void displayLineHorizontalCentered(int16_t length, uint16_t color)
{
  display.drawLine(SCREEN_CENTER_X - (length / 2), SCREEN_CENTER_y, SCREEN_CENTER_X + (length / 2), SCREEN_CENTER_y, color);
}
void displayLineVerticalCentered(int16_t length, uint16_t color)
{
  display.drawLine(SCREEN_CENTER_X, SCREEN_CENTER_y - (length / 2), SCREEN_CENTER_X, SCREEN_CENTER_y + (length / 2), color);
}

void displayCircleCentered(int16_t r, uint16_t color)
{
  display.drawCircle(SCREEN_CENTER_X, SCREEN_CENTER_y, r, color);
}

void displayRoundRectCentered(int16_t w, int16_t h)
{
  display.drawRoundRect(SCREEN_CENTER_X - (w / 2), SCREEN_CENTER_y - (h / 2), w, h, 10, SH110X_WHITE);
}

// Read the Switch array and select a random from the enabled;
//Thanks @darwinwaswrong in Wokwi forum
int getRandomMode()
{
//original
  return random(nbrModes);
}


const char *getRandomSentences()
{
  // Sentences
  static const char *Sentences[] = {"Boss? Darth Surgo on the comms for you", "Don't shoot, I know that guy",
                                    "Scanning Scanning lalala Scanning", "Message from TAC Tempest Squardon check in ASAP",
                                    "Now that is HOT"};
  int nbrOfSentences = sizeof(Sentences) / sizeof(Sentences[0]);
  int rnd = random(nbrOfSentences);
  return Sentences[rnd];
}

void scrollCurrentlyShowing(void)
{
  for (int i = 0; i < aurebeshScreenLines - 1; i++)
  {
    strcpy(currentlyShowing[i], currentlyShowing[i + 1]);
  }
  strcpy(currentlyShowing[aurebeshScreenLines - 1], "");
}

bool isOutOfScreen(AurebeshScreenCoordinate coord)
{
  if (coord.line > (aurebeshScreenLines - 1) || coord.column > (aurebeshScreenColumns - 1))
  {
    // line or columns out of range
    Serial.println(F("Coord OFR: "));
    Serial.print(F("l="));
    Serial.print(coord.line);
    Serial.print(F("C="));
    Serial.println(coord.column);
    return true;
  }
  return false;
}

PixelCoordinate aurebeshCoordinateToPixel(AurebeshScreenCoordinate coord)
{
  int16_t x = coord.column * AUREBESH_WIDTH;
  int16_t y = (coord.line + 1) * AUREBESH_HEIGHT;

  return {x, y};
}

void displayAurebeshString(char *s)
{
  for (int i = 0; i < strlen(s); i++)
  {
    displayAurebeshChar(s[i]);
    delay(cursorSpeed);
  }
}

void displayAurebeshChar(char c)
{
  displayAurebeshCharAtCoordinate(c, currentCoordinate);
  display.display();
  currentlyShowing[currentCoordinate.line][currentCoordinate.column] = c;
  currentlyShowing[currentCoordinate.line][currentCoordinate.column + 1] = 0;
  currentCoordinate.column++;
  if (currentCoordinate.column == aurebeshScreenColumns)
  {
    scrollCurrentlyShowing();
    redrawCurrentlyShowing();
    resetCoordinates();
  }
}

void displayAurebeshCharAtCoordinate(char c, AurebeshScreenCoordinate coord)
{
  if (!isOutOfScreen(coord))
  {
    PixelCoordinate pixCoord = aurebeshCoordinateToPixel(coord);
    display.setCursor(pixCoord.x, pixCoord.y); // as per Adafruit convention custom fonts draw up from line so move cursor
    display.print(c);
  }
}

void initAurebeshScreen(void)
{
  display.clearDisplay();
  display.display();
  display.setFont(&Aurebesh8pt7b);
  display.setTextSize(1);
  display.setTextColor(SH110X_WHITE);
  display.setTextWrap(false);

  resetAurebeshScreen();
}

void resetAurebeshScreen()
{
  resetCurrentlyShowing();
  resetCoordinates();
  display.clearDisplay();
  display.display();
}

void resetCoordinates(void)
{
  currentCoordinate = {aurebeshScreenLines - 1, 0};
}

void resetCurrentlyShowing(void)
{
  for (int i = 0; i < aurebeshScreenLines; i++)
  {
    currentlyShowing[i][0] = 0;
  }
}

int getRandomLineNotEmptyCurrentlyShowing(void)
{
  int lines[aurebeshScreenLines];
  int nbrOfNotEmptyLines;

  nbrOfNotEmptyLines = 0;
  for (int i = 0; i < aurebeshScreenLines; i++)
  {
    if (currentlyShowing[i][0] != 0)
    {
      lines[nbrOfNotEmptyLines] = i;
      nbrOfNotEmptyLines++;
    }
  }
  return lines[random(aurebeshScreenLines)];
}

void redrawCurrentlyShowing(void)
{
  display.clearDisplay();
  for (int i = 0; i < aurebeshScreenLines - 1; i++)
  {
    for (int j = 0; j < aurebeshScreenColumns; j++)
    {
      if (currentlyShowing[i][j] == 0)
      {
        break;
      }
      displayAurebeshCharAtCoordinate(currentlyShowing[i][j], {i, j});
    }
    display.display();
  }
}

void displayNoisePixelated(int density, bool accumulate, int durationMS)
{
  int rnd_x;
  int rnd_y;

  Timer time = initTimer(durationMS);

  while (duration(time))
  {
    for (int i = 0; i < density; i++)
    {
      rnd_x = random(display.width());
      rnd_y = random(display.height());
      display.drawPixel(rnd_x, rnd_y, SH110X_WHITE);
    }

    display.display();
    delay(1);
    if (!accumulate)
    {
      display.clearDisplay();
    }
  }
  display.display();
}

Timer initTimer(unsigned long durationMS)
{
  return {millis(), durationMS};
}

boolean duration(Timer time)
{
  return millis() - time.time_start < time.durationMs;
}

void invertLine(int lineNumber, int speedMS, int durationMS)
{
  Timer time = initTimer(durationMS);
  while (duration(time))
  {
    invertLineNumber(lineNumber);
    display.display();
    delay(speedMS);
    invertLineNumber(lineNumber);
    display.display();
    delay(speedMS);
  }
}
void invertLineNumber(int lineNumber)
{
  AurebeshScreenCoordinate coord = {lineNumber, 0};
  if (!isOutOfScreen(coord))
  {
    PixelCoordinate pixCoord;
    pixCoord = aurebeshCoordinateToPixel(coord);
    invertPixels(pixCoord.x, pixCoord.y - AUREBESH_HEIGHT + 3, SCREEN_WIDTH + AUREBESH_WIDTH, AUREBESH_HEIGHT);
  }
}
void invertPixels(int16_t x, int16_t y, int16_t w, int16_t h)
{

  for (int j = 0; j < h; j++)
  {
    for (int i = 0; i < w; i++)
    {
      if (display.getPixel(x + i, y + j))
      {

        display.drawPixel(x + i, y + j, SH110X_BLACK);
      }
      else
      {
        display.drawPixel(x + i, y + j, SH110X_WHITE);
      }
    }
  }
}

void displayCursor(AurebeshScreenCoordinate coord, int durationMS, int speedMS)
{
  if (!isOutOfScreen(coord))
  {
    Timer time = initTimer(durationMS);
    PixelCoordinate pixCoord = aurebeshCoordinateToPixel(coord);
    while (duration(time))
    {
      display.fillRect(pixCoord.x, pixCoord.y - AUREBESH_HEIGHT + 5, AUREBESH_WIDTH - 4, AUREBESH_HEIGHT - 4, SH110X_WHITE);
      display.display();
      delay(speedMS);
      display.fillRect(pixCoord.x, pixCoord.y - AUREBESH_HEIGHT + 5, AUREBESH_WIDTH - 4, AUREBESH_HEIGHT - 4, SH110X_BLACK);
      display.display();
      delay(speedMS);
    }
  }
}


void shuffle(){
  Serial.println("shuffle phrase");    
    switch (random(1,5)) {
        
        case 1:phrase1(); break;
        case 2:phrase2(); break;
        case 3:phrase3(); break;
        case 4:phrase4(); break;
        case 5:phrase4(); break;
        
    }
}

void phrase1() {
        Serial.println("start k1");   
    k1 = random(500,2000);

    for (int i1a = 0; i1a <=  random(100,200); i1a++){

        tone(speakerPin, k1+(-i1a*2));          
        delay(random(1,2));             
    } 

 
    for (int i1b = 0; i1b <= random(100,200); i1b++){
        
        tone(speakerPin, k1 + (i1b * 10));          
        delay(random(1,2));             
    } 

    Serial.println("exit k1");   
}

void phrase2() {
        Serial.println("start k2");   
    k2 = random(200,2000);
    int k2ta = random(100,800);
    int k2tb = random(100,800);

    for (int i2a = 0; i2a <= k2ta; i2a++){
//      Serial.println("i1");    
//      Serial.println(i);    
        i2a=i2a+mult;
        tone(speakerPin, k2+(i2a*2));          
        delay(random(1,2));             
    } 

   
           
    for (int i2b = 0; i2b <= k2tb; i2b++){
  //    Serial.println("12");    
  //    Serial.println(i);    
  i2b=i2b+mult;
        tone(speakerPin, k2 + (i2b * 10));          
        delay(random(1,2));             
    } 
        Serial.println("exit k2");   
}

void phrase3() {
    //down
        Serial.println("start k3");   
    k3 = random(100,2000);
    for (int i3a = random(100,400); i3a >= 100; i3a--){
    i3a=i3a-10;

       tone(speakerPin, k3+(i3a*2));          
        delay(random(1,2));             
    } 
 
    for (int i3b = 0; i3b <= random(100,400); i3b++){
    
i3b=i3b+10;
        tone(speakerPin, k3 + (i3b * 10));          
        
        delay(random(1,2));             
    } 
    Serial.println("exit k3");   
}
void phrase4() {
    //mono
    Serial.println("start k4");
    k4 = random(10,2000);
    for (int i41a = random(100,400); i41a >= 0; i41a--){
        i41a=i41a-mult;
        tone(speakerPin, k4);          
        delay(random(1,2));             
    } 
    Serial.println("exit k41");  

    for (int i41b = 0; i41b <= random(100,400); i41b++){
        i41b=i41b+mult;
        tone(speakerPin, k4+1000 );          
        delay(random(1,2));             
    } 
    k4 = random(10,2000);
        
    for (int i42a = random(100,400); i42a >= 0; i42a--){
       i42a=i42a-mult; 
        tone(speakerPin, k4);          
        delay(random(1,2));             
    } 
    
    for (int i42b = 0; i42b <= random(100,400); i42b++){
       i42b=i42b+mult; 
        tone(speakerPin, k4+1000 );          
        delay(random(1,2));             
    } 
Serial.println("exit k42");  
    
    for (int i43a = random(100,400); i43a >= 0; i43a--){
      i43a=i43a-mult;  
        tone(speakerPin, k4);          
        delay(random(1,2));             
    } 

    for (int i43b = 0; i43b <= random(100,400); i43b++){
     i43b=i43b+mult;   
        tone(speakerPin, k4+1000 );          
        delay(random(1,2));             
    } 

    Serial.println("exit k43");    
}

void phrase5(){
    Serial.println("start k5");    
    k5 = 4000;
    for (int i1 = 0; i1 <= random(3, 12); i1++){
        tone(speakerPin, k5 + random(-1700, 2000));          
        delay(random(70, 170));  
        noTone(speakerPin);         
        delay(random(0, 30));             
    } 
        Serial.println("exit k5");    
}  
