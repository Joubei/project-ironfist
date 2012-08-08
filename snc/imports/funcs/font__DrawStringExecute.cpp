{
  int result; // eax@2
  font *this; // [sp+Ch] [bp-10h]@1
  int x; // [sp+10h] [bp-Ch]@1
  int i; // [sp+14h] [bp-8h]@1
  char v13; // [sp+18h] [bp-4h]@3
  char v14; // [sp+18h] [bp-4h]@9

  this = ecx0;
  x = a3;
  for ( i = 0; ; ++i )
  {
    result = a2[i];
    if ( !a2[i] )
      break;
    v13 = a2[i];
    switch ( v13 )
    {
      case 31:
        x += font::GetCharacterWidth(this, a2[i]);
        break;
      case 123:
        this->field_18 = 1;
        break;
      case 125:
        this->field_18 = 0;
        break;
      default:
        v14 = v13 - 32;
        if ( v14 < 0 || v14 > 95 )
          v14 = 95;
        if ( v14 )
        {
          if ( a5 != 1 || this->field_18 )
          {
            if ( a5 == 2 || a5 == 1 && this->field_18 )
            {
              IconToBitmapColorTable(
                this->icon,
                gpWindowManager->screenBuffer,
                x,
                a4,
                v14,
                1,
                a7,
                a8,
                regionWidth,
                regionHeight,
                0,
                gColorTableYellow,
                1);
            }
            else if ( a5 == 4 )
            {
              IconToBitmapColorTable(
                this->icon,
                gpWindowManager->screenBuffer,
                x,
                a4,
                v14,
                1,
                a7,
                a8,
                regionWidth,
                regionHeight,
                0,
                gColorTableScenWin,
                0);
            }
            else
            {
              IconToBitmapColorTable(
                this->icon,
                gpWindowManager->screenBuffer,
                x,
                a4,
                v14,
                1,
                a7,
                a8,
                regionWidth,
                regionHeight,
                0,
                gColorTableDarkGray,
                1);
            }
          }
          else
          {
            IconToBitmap(this->icon, gpWindowManager->screenBuffer, x, a4, v14, 1, a7, a8, regionWidth, regionHeight, 0);
          }
        }
        x += font::GetCharacterWidth(this, a2[i]);
        break;
    }
  }
  return result;
}