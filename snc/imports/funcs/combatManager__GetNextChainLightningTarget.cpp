{
  int v3; // eax@10
  int v4; // ST40_4@10
  int v5; // eax@10
  int v6; // eax@10
  signed int i; // [sp+1Ch] [bp-28h]@1
  signed int v10; // [sp+20h] [bp-24h]@1
  army *this; // [sp+24h] [bp-20h]@5
  signed int v12; // [sp+28h] [bp-1Ch]@10
  int j; // [sp+30h] [bp-14h]@3
  int v14; // [sp+34h] [bp-10h]@1
  int v15; // [sp+38h] [bp-Ch]@1
  int v16; // [sp+3Ch] [bp-8h]@1

  v10 = 999999;
  v14 = -1;
  v16 = army::MidX(creat);
  v15 = army::MidY(creat);
  for ( i = 0; i < 2; ++i )
  {
    for ( j = 0; ecx0->numCreatures[i] > j; ++j )
    {
      this = &ecx0->creatures[i][j];
      if ( !gArmyEffected[i][j]
        && (forChainLightning && army::SpellCastWorks(this, SPELL_CHAIN_LIGHTNING)
         || !forChainLightning && army::SpellCastWorkChance(this, SPELL_CHAIN_LIGHTNING) != 0.0) )
      {
        v3 = army::MidX(this);
        v4 = abs(v3 - v16);
        v5 = army::MidY(this);
        v6 = abs(v5 - v15);
        v12 = (signed __int64)sqrt((double)(v6 * v6 + v4 * v4));
        if ( v12 < v10 )
        {
          v10 = v12;
          v14 = ecx0->creatures[i][j].occupiedHex;
        }
      }
    }
  }
  return v14;
}