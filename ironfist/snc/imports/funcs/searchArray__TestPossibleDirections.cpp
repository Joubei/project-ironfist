{
  searchArray *v6; // ebp@1
  mapCell *v7; // eax@1
  int v8; // ecx@2
  signed int result; // eax@2
  char v10; // al@19
  char v11; // al@24
  char v12; // al@43

  *(_DWORD *)a4 = 0;
  v6 = this;
  *(_DWORD *)(a4 + 4) = 0;
  v7 = advManager::GetCell(gpAdvManager, a2, SHIDWORD(a2));
  dword_526B8C = 0;
  dword_526B9C = (int)v7;
  do
  {
    v8 = a2 + normalDirTable[4 * dword_526B8C];
    result = HIDWORD(a2) + byte_4F1DC1[4 * dword_526B8C];
    dword_526B88 = v8;
    ::a3 = result;
    if ( v8 < 0
      || (result = v8, MAP_WIDTH <= v8)
      || (result = ::a3, ::a3 < 0)
      || (result = MAP_HEIGHT, ::a3 >= MAP_HEIGHT)
      || (result = (signed int)advManager::GetCell(gpAdvManager, dword_526B88, ::a3),
          dword_526B80 = result,
          *(_BYTE *)(result + 8) & 8)
      || gbHumanPlayer[giCurPlayer]
      && (result = dword_526B88 + ::a3 * MAP_WIDTH, !(mapExtra[result] & (unsigned __int8)giCurPlayerBit)) )
    {
LABEL_49:
      dword_526C18 = -1;
      goto LABEL_50;
    }
    if ( *(_BYTE *)(dword_526B80 + 9) & 0x80 )
    {
      if ( a5 )
      {
        *(_BYTE *)(dword_526B8C + a4) = 1;
      }
      else
      {
        result = dword_526B88;
        if ( *(_DWORD *)&v6->_1[0] != dword_526B88 )
          goto LABEL_49;
        result = ::a3;
        if ( *(_DWORD *)&v6->_1[4] != ::a3 )
          goto LABEL_49;
      }
    }
    dword_526C18 = (unsigned __int8)giGroundToTerrain[*(_WORD *)dword_526B80];
    if ( dword_526C18 )
    {
      if ( a6 )
      {
        result = dword_526B80;
        if ( *(_BYTE *)(dword_526B80 + 9) != 28 )
          goto LABEL_49;
      }
    }
    else
    {
      result = dword_526B80;
      if ( a6 )
      {
        if ( *(_BYTE *)(dword_526B80 + 9) == -85 )
          goto LABEL_49;
        if ( !giGroundToTerrain[*(_WORD *)dword_526B9C] )
        {
          v10 = normalDirTable[4 * dword_526B8C];
          if ( v10 )
          {
            if ( byte_4F1DC1[4 * dword_526B8C] )
            {
              result = (signed int)advManager::GetCell(gpAdvManager, a2 + v10, SHIDWORD(a2));
              if ( giGroundToTerrain[*(_WORD *)result] )
                goto LABEL_49;
              result = (signed int)advManager::GetCell(gpAdvManager, a2, HIDWORD(a2) + byte_4F1DC1[4 * dword_526B8C]);
              if ( giGroundToTerrain[*(_WORD *)result] )
                goto LABEL_49;
            }
          }
        }
      }
      else
      {
        v11 = *(_BYTE *)(dword_526B80 + 9);
        if ( v11 != -86 && v11 != -85 && v11 != -96 )
          goto LABEL_49;
      }
    }
    result = 1 << dword_526B8C;
    if ( (1 << dword_526B8C) & 0x83 )
    {
      if ( *(_BYTE *)(dword_526B9C + 3) != -1 )
      {
        if ( (*(_BYTE *)(dword_526B9C + 2) & 0xFC) != -68 )
        {
          result = dword_526B9C;
          if ( !(*(_BYTE *)(dword_526B9C + 8) & 0x80) )
            goto LABEL_49;
        }
      }
      result = dword_526B80;
      if ( *(_BYTE *)(dword_526B80 + 7) != -1 )
      {
        result = (signed int)advManager::GetCell(gpAdvManager, dword_526B88, ::a3 + 1);
        if ( *(_BYTE *)(result + 3) != -1 )
        {
          if ( (*(_BYTE *)(result + 2) & 0xFC) != -68 && !(*(_BYTE *)(result + 8) & 0x80) )
            goto LABEL_49;
        }
      }
    }
    else if ( result & 0x38 )
    {
      if ( *(_BYTE *)(dword_526B80 + 3) != -1 )
      {
        if ( (*(_BYTE *)(dword_526B80 + 2) & 0xFC) != -68 )
        {
          result = dword_526B80;
          if ( !(*(_BYTE *)(dword_526B80 + 8) & 0x80) )
          {
            v12 = *(_BYTE *)(dword_526B80 + 9);
            if ( !(v12 & 0x80) )
              goto LABEL_49;
            dword_526B84 = v12 & 0x7F;
            if ( !StopOnTrigger(dword_526B80) )
              goto LABEL_49;
          }
        }
      }
      result = dword_526B9C;
      if ( *(_BYTE *)(dword_526B9C + 7) != -1 )
      {
        result = (signed int)advManager::GetCell(gpAdvManager, a2, HIDWORD(a2) + 1);
        if ( *(_BYTE *)(result + 3) != -1 )
        {
          if ( (*(_BYTE *)(result + 2) & 0xFC) != -68 && !(*(_BYTE *)(result + 8) & 0x80) )
            goto LABEL_49;
        }
      }
    }
LABEL_50:
    LOBYTE(result) = dword_526C18;
    *(_BYTE *)(dword_526B8C++ + a3) = dword_526C18;
  }
  while ( dword_526B8C < 8 );
  return result;
}