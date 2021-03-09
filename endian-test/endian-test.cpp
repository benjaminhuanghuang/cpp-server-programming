#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

/*
  0x00000001 
  little endian:   01 00 00 00
  big endian:      00 00 00 01

*/

union EndianTest
{
  int8_t u[4];
  int32_t i;
};

static bool isLittleEndianSystem()
{
  EndianTest et;
  et.i = 1;
  return et.u[0] == 1;
}

static bool isLittleEndianOS()
{  
  return __BYTE_ORDER__ == __LITTLE_ENDIAN__;
}

int main()
{
  if (isLittleEndianSystem())
  {
    printf("This is little endian system");
  }
  else
  {
    printf("This is big endian system");
  }
  return 0;
}