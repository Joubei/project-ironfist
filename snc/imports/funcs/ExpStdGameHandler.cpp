{
  int v2; // [sp+Ch] [bp-Ch]@4
  void *v3; // [sp+10h] [bp-8h]@1
  signed int v4; // [sp+14h] [bp-4h]@4

  v3 = this;
  if ( *((_BYTE *)this + 13) & 2 && (*((_DWORD *)this + 1) == 12 || *((_DWORD *)this + 1) == 14) )
  {
    v4 = -1;
    v2 = *((_DWORD *)this + 2);
    switch ( v2 )
    {
      case 1:
        v4 = 0;
        break;
      case 2:
        v4 = 1;
        break;
      case 30721:
        v4 = 2;
        break;
    }
    if ( v4 >= 0 )
      NormalDialog((&off_51A730)[4 * v4], 4, -1, -1, -1, 0, -1, 0, -1, 0);
  }
  return BaseSetupHandler(v3);
}