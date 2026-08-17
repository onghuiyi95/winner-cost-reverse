
/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
FUN_008f1100(int param_1,char *param_2,int param_3,int *param_4,undefined4 param_5,
            undefined4 param_6,int param_7)

{
  ushort uVar1;
  undefined3 uVar2;
  LONG LVar3;
  uint uVar4;
  HPEN pHVar5;
  COLORREF color;
  HGDIOBJ pvVar6;
  int *piVar7;
  undefined4 *puVar8;
  POINT *pPVar9;
  ulong uVar10;
  double *pdVar11;
  undefined4 uVar12;
  int iVar13;
  char cVar14;
  char cVar15;
  int iVar16;
  int iVar17;
  bool bVar18;
  bool bVar19;
  undefined1 local_2038 [8];
  undefined8 local_2030;
  int local_2028;
  int local_2024;
  int local_2020;
  LPCSTR local_201c;
  tagSIZE local_2018;
  int local_2010;
  CGdiObject *local_200c;
  undefined **local_2008;
  undefined4 local_2004;
  undefined **local_2000;
  undefined4 local_1ffc;
  undefined **local_1ff8;
  undefined4 local_1ff4;
  undefined **local_1ff0;
  undefined4 local_1fec;
  undefined **local_1fe8;
  undefined4 local_1fe4;
  undefined **local_1fe0;
  undefined4 local_1fdc;
  undefined **local_1fd8;
  undefined4 local_1fd4;
  undefined **local_1fd0;
  undefined4 local_1fcc;
  undefined **local_1fc8;
  undefined4 local_1fc4;
  undefined **local_1fc0;
  undefined4 local_1fbc;
  undefined **local_1fb8;
  undefined4 local_1fb4;
  undefined **local_1fb0;
  undefined4 local_1fac;
  int local_1fa8;
  int local_1fa4;
  char local_1f9d;
  char *local_1f9c;
  uint local_1f98;
  uint local_1f94;
  int *local_1f8c;
  int local_1f88;
  LPCSTR local_1f84;
  int local_1f80;
  int local_1f7c;
  char local_1f75;
  tagRECT local_1f74;
  tagRECT local_1f64;
  POINT local_1f54 [1000];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00e5d6df;
  local_10 = ExceptionList;
  uVar4 = DAT_011132f8 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_2018.cy = (LONG)param_4;
  iVar17 = 0;
  local_1f9c = param_2;
  local_2010 = param_3;
  local_2030 = (double)CONCAT44(param_7,(undefined4)local_2030);
  local_14 = uVar4;
  if ((*param_2 == '\0') || (param_7 == 0)) goto LAB_008f242a;
  local_1f88 = *(int *)(param_1 + 0x1da);
  if ((DAT_01127201 & 0x200000) == 0) {
    uVar1 = *(ushort *)(param_1 + 0x1d2);
    local_1f94 = (uint)(ushort)-*(short *)(param_1 + 0x1e2);
    local_1f88 = local_1f88 + 9;
  }
  else {
    local_1f94 = (int)*(short *)(param_1 + 0x1e2) / 3;
    uVar1 = *(ushort *)(param_1 + 0x1d6);
  }
  local_1f98 = (uint)uVar1;
  local_1f94 = local_1f94 & 0xffff;
  local_1f8c = *(int **)(param_3 + 0x1a);
  local_1fcc = 0;
  local_1fd0 = CPen::vftable;
  local_2004 = 0;
  local_2008 = CPen::vftable;
  local_1ff4 = 0;
  local_1ff8 = CPen::vftable;
  local_1fb4 = 0;
  local_1fb8 = CPen::vftable;
  local_1fd4 = 0;
  local_1fd8 = CPen::vftable;
  local_1fbc = 0;
  local_1fc0 = CPen::vftable;
  local_1ffc = 0;
  local_2000 = CPen::vftable;
  local_1fdc = 0;
  local_1fe0 = CPen::vftable;
  local_1fec = 0;
  local_1ff0 = CPen::vftable;
  local_1fc4 = 0;
  local_1fc8 = CPen::vftable;
  local_1fe4 = 0;
  local_1fe8 = CPen::vftable;
  local_1fac = 0;
  local_1fb0 = CPen::vftable;
  local_8._1_3_ = 0;
  uVar2 = local_8._1_3_;
  local_8._0_1_ = 0xb;
  local_8._1_3_ = 0;
  if (*(int *)(param_3 + 0x1a) < 1) {
LAB_008f2354:
    local_8._1_3_ = uVar2;
                    /* WARNING: Subroutine does not return */
    FUN_00a3a78c(uVar4);
  }
  pHVar5 = CreatePen(*(int *)(param_3 + 6),*(int *)(param_3 + 10),
                     *(COLORREF *)(**(int **)(param_3 + 0x16) + 1));
  CMenu::Attach((CMenu *)&local_1fd0,(HMENU__ *)pHVar5);
  uVar2 = local_8._1_3_;
  if (*(int *)(param_3 + 0x1a) < 2) goto LAB_008f2354;
  pHVar5 = CreatePen(*(int *)(param_3 + 6),*(int *)(param_3 + 10),
                     *(COLORREF *)(*(int *)(*(int *)(param_3 + 0x16) + 4) + 1));
  CMenu::Attach((CMenu *)&local_2008,(HMENU__ *)pHVar5);
  uVar2 = local_8._1_3_;
  if (*(int *)(param_3 + 0x1a) < 3) goto LAB_008f2354;
  pHVar5 = CreatePen(*(int *)(param_3 + 6),*(int *)(param_3 + 10),
                     *(COLORREF *)(*(int *)(*(int *)(param_3 + 0x16) + 8) + 1));
  CMenu::Attach((CMenu *)&local_1ff8,(HMENU__ *)pHVar5);
  uVar2 = local_8._1_3_;
  if (*(int *)(param_3 + 0x1a) < 4) goto LAB_008f2354;
  pHVar5 = CreatePen(*(int *)(param_3 + 6),*(int *)(param_3 + 10),
                     *(COLORREF *)(*(int *)(*(int *)(param_3 + 0x16) + 0xc) + 1));
  CMenu::Attach((CMenu *)&local_1fb8,(HMENU__ *)pHVar5);
  uVar2 = local_8._1_3_;
  if (*(int *)(param_3 + 0x1a) < 5) goto LAB_008f2354;
  pHVar5 = CreatePen(*(int *)(param_3 + 6),*(int *)(param_3 + 10),
                     *(COLORREF *)(*(int *)(*(int *)(param_3 + 0x16) + 0x10) + 1));
  CMenu::Attach((CMenu *)&local_1fd8,(HMENU__ *)pHVar5);
  uVar2 = local_8._1_3_;
  if (*(int *)(param_3 + 0x1a) < 6) goto LAB_008f2354;
  pHVar5 = CreatePen(*(int *)(param_3 + 6),*(int *)(param_3 + 10),
                     *(COLORREF *)(*(int *)(*(int *)(param_3 + 0x16) + 0x14) + 1));
  CMenu::Attach((CMenu *)&local_1fc0,(HMENU__ *)pHVar5);
  uVar2 = local_8._1_3_;
  if (*(int *)(param_3 + 0x1a) < 7) goto LAB_008f2354;
  pHVar5 = CreatePen(*(int *)(param_3 + 6),*(int *)(param_3 + 10),
                     *(COLORREF *)(*(int *)(*(int *)(param_3 + 0x16) + 0x18) + 1));
  CMenu::Attach((CMenu *)&local_2000,(HMENU__ *)pHVar5);
  uVar2 = local_8._1_3_;
  if (*(int *)(param_3 + 0x1a) < 8) goto LAB_008f2354;
  pHVar5 = CreatePen(*(int *)(param_3 + 6),*(int *)(param_3 + 10),
                     *(COLORREF *)(*(int *)(*(int *)(param_3 + 0x16) + 0x1c) + 1));
  CMenu::Attach((CMenu *)&local_1fe0,(HMENU__ *)pHVar5);
  uVar2 = local_8._1_3_;
  if (*(int *)(param_3 + 0x1a) < 9) goto LAB_008f2354;
  pHVar5 = CreatePen(*(int *)(param_3 + 6),*(int *)(param_3 + 10),
                     *(COLORREF *)(*(int *)(*(int *)(param_3 + 0x16) + 0x20) + 1));
  CMenu::Attach((CMenu *)&local_1ff0,(HMENU__ *)pHVar5);
  uVar2 = local_8._1_3_;
  if (*(int *)(param_3 + 0x1a) < 10) goto LAB_008f2354;
  pHVar5 = CreatePen(*(int *)(param_3 + 6),*(int *)(param_3 + 10),
                     *(COLORREF *)(*(int *)(*(int *)(param_3 + 0x16) + 0x24) + 1));
  CMenu::Attach((CMenu *)&local_1fc8,(HMENU__ *)pHVar5);
  uVar2 = local_8._1_3_;
  if (*(int *)(param_3 + 0x1a) < 0xb) goto LAB_008f2354;
  pHVar5 = CreatePen(*(int *)(param_3 + 6),1,
                     *(COLORREF *)(*(int *)(*(int *)(param_3 + 0x16) + 0x28) + 1));
  CMenu::Attach((CMenu *)&local_1fe8,(HMENU__ *)pHVar5);
  color = FUN_009a40f0();
  pHVar5 = CreatePen(0,1,color);
  CMenu::Attach((CMenu *)&local_1fb0,(HMENU__ *)pHVar5);
  pvVar6 = GetCurrentObject(*(HDC *)(*(int *)(param_1 + 0x1b2) + 8),1);
  local_200c = CGdiObject::FromHandle(pvVar6);
  if (((DAT_01127201 & 0x1800000) != 0) && (local_1f80 = 0, 0 < *(int *)(param_1 + 0x1e6))) {
    do {
      iVar16 = local_1f80;
      local_1f75 = '\0';
      if (0 < (int)local_1f8c) {
        local_1f84 = (LPCSTR)0x0;
        do {
          if (local_1f75 == '\0') {
            if (_DAT_0113e1b0 <= (float)local_1f80) {
              FUN_008aa590();
              if (iVar16 == (iVar16 / 3) * 3) {
                local_1f7c = (int)(short)local_1f98;
                local_1f84 = (LPCSTR)(int)(short)local_1f94;
                iVar17 = FUN_00bea080();
                CDC::MoveTo(*(CDC **)(param_1 + 0x1b2),(int)local_2038,iVar17);
                goto LAB_008f1729;
              }
            }
            else {
              FUN_008aa590();
              if (iVar16 == (iVar16 / 3) * 3) {
                local_1f7c = (int)(short)local_1f98;
                local_1f84 = (LPCSTR)(int)(short)local_1f94;
                iVar17 = FUN_00bea080();
                piVar7 = &local_1fa8;
                goto LAB_008f1700;
              }
            }
          }
          else {
            if ((((((local_1f75 == '\x01') || (local_1f75 == '\x02')) || (local_1f75 == '\x03')) ||
                 ((local_1f75 == '\x04' || (local_1f75 == '\x05')))) ||
                (((local_1f75 == '\x06' || ((local_1f75 == '\a' || (local_1f75 == '\b')))) ||
                 (local_1f75 == '\t')))) || (local_1f75 == '\n')) {
              FUN_008aa590();
            }
            local_1f7c = (int)(short)local_1f98;
            local_1f84 = (LPCSTR)(int)(short)local_1f94;
            iVar17 = FUN_00bea080();
            piVar7 = &local_2020;
LAB_008f1700:
            CDC::MoveTo(*(CDC **)(param_1 + 0x1b2),(int)piVar7,iVar17);
LAB_008f1729:
            CDC::LineTo(*(CDC **)(param_1 + 0x1b2),local_1f7c,local_1f88 + iVar16);
          }
          local_1f75 = local_1f75 + '\x01';
          local_1f84 = (LPCSTR)(int)local_1f75;
        } while ((int)local_1f84 < (int)local_1f8c);
      }
      local_1f80 = iVar16 + 1;
    } while (local_1f80 < *(int *)(param_1 + 0x1e6));
  }
  if (((DAT_01127201 & 0x2000000) != 0) && (local_1f80 = 0, 0 < *(int *)(param_1 + 0x1e6))) {
    cVar14 = (char)local_1f8c + -1;
    local_1f84 = &DAT_0113c230;
    cVar15 = cVar14;
    local_1f9d = cVar14;
    do {
      for (; local_1f75 = cVar15, -1 < cVar15; cVar15 = cVar15 + -1) {
        if (((((cVar15 == '\0') || (cVar15 == '\x01')) || (cVar15 == '\x02')) ||
            (((cVar15 == '\x03' || (cVar15 == '\x04')) ||
             ((cVar15 == '\x05' || ((cVar15 == '\x06' || (cVar15 == '\a')))))))) ||
           ((cVar15 == '\b' || (cVar15 == '\t')))) {
          FUN_008aa590();
LAB_008f17da:
          iVar16 = local_1f80;
          local_1f7c = (int)(short)local_1f98;
          local_1fa4 = (int)(short)local_1f94;
          iVar17 = FUN_00bea080();
          iVar16 = iVar16 + local_1f88;
          CDC::MoveTo(*(CDC **)(param_1 + 0x1b2),(int)local_2038,iVar17);
LAB_008f1850:
          CDC::LineTo(*(CDC **)(param_1 + 0x1b2),local_1f7c,iVar16);
          cVar15 = local_1f75;
        }
        else {
          if (cVar15 != '\n') goto LAB_008f17da;
          FUN_008aa590();
          if (local_1f80 == (local_1f80 / 3) * 3) {
            local_1f7c = (int)(short)local_1f98;
            local_1fa4 = (int)(short)local_1f94;
            iVar17 = FUN_00bea080();
            iVar16 = local_1f80 + local_1f88;
            CDC::MoveTo(*(CDC **)(param_1 + 0x1b2),(int)&local_2020,iVar17);
            goto LAB_008f1850;
          }
        }
        cVar14 = local_1f9d;
      }
      local_1f84 = local_1f84 + 8;
      local_1f80 = local_1f80 + 1;
      cVar15 = cVar14;
    } while (local_1f80 < *(int *)(param_1 + 0x1e6));
  }
  piVar7 = (int *)FUN_00a3bbde();
  if (piVar7 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    thunk_FUN_00426e80();
  }
  local_1f7c = (**(code **)(*piVar7 + 0xc))();
  local_1f7c = local_1f7c + 0x10;
  local_8._0_1_ = 0xc;
  if ((DAT_01127201 & 0x800000) == 0) {
    pPVar9 = local_1f54;
    iVar16 = 999;
    do {
      pPVar9->x = 0;
      pPVar9->y = 0;
      pPVar9 = pPVar9 + 1;
      iVar16 = iVar16 + -1;
    } while (-1 < iVar16);
    FUN_008aa590();
    local_1f75 = (char)local_1f8c + -2;
    if (-1 < local_1f75) {
      local_1f8c = (int *)(local_1f75 * 1000);
      do {
        iVar16 = 0;
        local_1f80 = 0;
        if (0 < *(int *)(param_1 + 0x1e6)) {
          do {
            if ((DAT_01127201 & 0x2000000) != 0) {
              local_1fa4 = (int)(short)local_1f94;
              iVar17 = FUN_00bea080();
            }
            if ((DAT_01127201 & 0x1000000) != 0) {
              local_1fa4 = (int)(short)local_1f94;
              iVar17 = FUN_00bea080();
            }
            if (iVar17 == 0) {
              Polyline(*(HDC *)(*(int *)(param_1 + 0x1b2) + 4),local_1f54,iVar16);
              iVar16 = 0;
            }
            else {
              local_1f54[iVar16].x = iVar17;
              local_1f54[iVar16].y = local_1f80 + local_1f88;
              iVar16 = iVar16 + 1;
            }
            local_1f80 = local_1f80 + 1;
          } while (local_1f80 < *(int *)(param_1 + 0x1e6));
          if (iVar16 != 0) {
            Polyline(*(HDC *)(*(int *)(param_1 + 0x1b2) + 4),local_1f54,iVar16);
          }
        }
        local_1f8c = (int *)((int)local_1f8c + -1000);
        local_1f75 = local_1f75 + -1;
      } while (-1 < local_1f75);
    }
    if ((DAT_01127201 & 0x800000) == 0) {
      if (DAT_0113e1a8 == 0) goto LAB_008f1a18;
      local_2028 = *(int *)local_2018.cy;
      local_2024 = *(int *)(local_2018.cy + 4);
      local_2020 = *(int *)(local_2018.cy + 8);
      local_201c = *(LPCSTR *)(local_2018.cy + 0xc);
      local_1f64.left = *(LONG *)local_2018.cy;
      local_1f64.top = *(int *)(local_2018.cy + 4);
      local_1f64.right = *(int *)(local_2018.cy + 8);
      local_1f64.bottom = *(int *)(local_2018.cy + 0xc);
      local_1f74.left = 0;
      local_1f74.top = 0;
      local_1f74.right = 0;
      local_1f74.bottom = 0;
      local_1fa4 = (**(code **)(**(int **)(param_1 + 0x1b2) + 0x28))();
      (**(code **)(**(int **)(param_1 + 0x1b2) + 0x30))(0);
      uVar10 = FUN_009a40f0();
      thunk_FUN_00427ed0();
      GetTextExtentPoint32A
                (*(HDC *)(*(int *)(param_1 + 0x1b2) + 8),local_1f84,*(int *)(local_1f84 + -0xc),
                 &local_2018);
      local_1f8c = (int *)local_2018.cy;
      piVar7 = (int *)(local_1f84 + -4);
      LOCK();
      iVar17 = *piVar7;
      *piVar7 = *piVar7 + -1;
      UNLOCK();
      if (iVar17 == 1 || iVar17 + -1 < 0) {
        (**(code **)(**(int **)(local_1f84 + -0x10) + 4))();
      }
      local_1f64.right = local_1f64.right + -5;
      local_1f64.left = local_1f64.right + local_2018.cx * -0x10;
      local_1f8c = (int *)(local_2018.cy + 2);
      if (local_1f64.left < 1) {
        local_1f64.left = 0;
      }
      iVar17 = local_1f74.left;
      iVar16 = local_1f74.right;
      LVar3 = local_1f64.right;
      local_1f74.left = local_1f64.left;
      iVar13 = DAT_0113e2cc;
      if ((DAT_01127201 & 0x1000000) != 0) {
        while (local_1f74.right = LVar3, local_1f80 = iVar13 + -1, local_1f64.left = local_1f74.left
              , local_1f64.right = local_1f74.right, -1 < local_1f80) {
          iVar13 = DAT_0113e2cc - local_1f80;
          if (*(float *)(&DAT_0113e1cc + iVar13 * 4) == 0.0) goto LAB_008f2141;
          local_1f74.bottom = (LONG)(local_201c + (-3 - (iVar13 + 3) * (int)local_1f8c));
          local_1f74.top = local_1f74.bottom + -(int)local_1f8c;
          local_1f64.top = local_1f74.top;
          local_1f64.bottom = local_1f74.bottom;
          uVar2 = local_8._1_3_;
          if ((iVar13 < 0) || (*(int *)(local_2010 + 0x1a) <= iVar13)) goto LAB_008f2354;
          FUN_008aa7f0(&local_1f74,
                       *(undefined4 *)(*(int *)(*(int *)(local_2010 + 0x16) + iVar13 * 4) + 1));
          CDC::Draw3dRect(*(CDC **)(param_1 + 0x1b2),&local_1f74,uVar10,uVar10);
          iVar13 = local_1f80;
          thunk_FUN_00428ed0(&local_1f7c,&DAT_00f80e90,
                             *(undefined4 *)(&DAT_0113e278 + (DAT_0113e2cc - local_1f80) * 4),
                             (double)*(float *)(&DAT_0113e1cc + (DAT_0113e2cc - local_1f80) * 4));
          local_1f74.left = local_1f74.left + 2;
          (**(code **)(**(int **)(param_1 + 0x1b2) + 0x68))(local_1f7c,0xffffffff);
          LVar3 = local_1f64.right;
          iVar17 = local_1f74.left + -2;
          iVar16 = local_1f74.right;
          local_1f74.left = local_1f64.left;
        }
      }
      local_1f74.right = iVar16;
      local_1f74.left = iVar17;
      iVar17 = local_1f74.left;
      iVar16 = local_1f74.right;
      if (((DAT_01127201 & 0x2000000) != 0) && (local_1f80 = 0, 0 < DAT_0113e2d0)) {
        local_2018.cy = -(int)local_1f8c;
        local_1f84 = local_201c + (int)local_1f8c * -4 + -3;
        do {
          iVar13 = local_1f80;
          iVar17 = local_1f74.left;
          iVar16 = local_1f74.right;
          if ((float)(&DAT_0113e1f8)[local_1f80] == 0.0) break;
          local_1f74.top = (LONG)(local_1f84 + -(int)local_1f8c);
          local_1f64.bottom = (LONG)local_1f84;
          local_1f74.right = local_1f64.right;
          local_1f74.left = local_1f64.left;
          local_1f74.bottom = (LONG)local_1f84;
          local_1f64.top = local_1f74.top;
          uVar2 = local_8._1_3_;
          if ((local_1f80 < 0) || (*(int *)(local_2010 + 0x1a) <= local_1f80)) goto LAB_008f2354;
          FUN_008aa7f0(&local_1f74,
                       *(undefined4 *)(*(int *)(*(int *)(local_2010 + 0x16) + local_1f80 * 4) + 1));
          CDC::Draw3dRect(*(CDC **)(param_1 + 0x1b2),&local_1f74,uVar10,uVar10);
          thunk_FUN_00428ed0(&local_1f7c,&DAT_00f80e80,(&DAT_0113e2a4)[iVar13],
                             (double)(float)(&DAT_0113e1f8)[iVar13]);
          local_1f74.left = local_1f74.left + 2;
          (**(code **)(**(int **)(param_1 + 0x1b2) + 0x68))(local_1f7c,0xffffffff);
          local_1f74.left = local_1f74.left + -2;
          local_1f84 = local_1f84 + local_2018.cy;
          local_1f80 = local_1f80 + 1;
          iVar17 = local_1f74.left;
          iVar16 = local_1f74.right;
        } while (local_1f80 < DAT_0113e2d0);
      }
LAB_008f2141:
      local_1f74.right = iVar16;
      local_1f74.left = iVar17;
      if (((DAT_01127201 & 0x1000000) != 0) || ((DAT_01127201 & 0x2000000) != 0)) {
        local_1f64.bottom = (LONG)local_201c;
        local_1f64.top = (LONG)(local_201c + (int)local_1f8c * -4);
      }
      local_1f64.left = local_2028;
      thunk_FUN_00428ed0(&local_1f7c,&DAT_00f80e6c,DAT_0113e1a8);
      iVar17 = **(int **)(param_1 + 0x1b2);
      FUN_009a40f0();
      (**(code **)(iVar17 + 0x30))();
      (**(code **)(**(int **)(param_1 + 0x1b2) + 0x68))(local_1f7c,0xffffffff,&local_1f64,0);
      OffsetRect(&local_1f64,0,(int)local_1f8c);
      thunk_FUN_00428ed0(&local_1f7c,&DAT_00f80e5c,(double)(_DAT_0113e1ac * (float)_DAT_00ef9ed0));
      iVar17 = **(int **)(param_1 + 0x1b2);
      FUN_009a40f0();
      (**(code **)(iVar17 + 0x30))();
      (**(code **)(**(int **)(param_1 + 0x1b2) + 0x68))(local_1f7c,0xffffffff,&local_1f64,0);
      OffsetRect(&local_1f64,0,(int)local_1f8c);
      thunk_FUN_00428ed0(&local_1f7c,&DAT_00f80e4c,
                         (double)((1.0 - _DAT_0113e1ac) * (float)_DAT_00ef9ed0));
      iVar17 = **(int **)(param_1 + 0x1b2);
      FUN_009a40f0();
      (**(code **)(iVar17 + 0x30))();
      (**(code **)(**(int **)(param_1 + 0x1b2) + 0x68))(local_1f7c,0xffffffff,&local_1f64,0);
      OffsetRect(&local_1f64,0,(int)local_1f8c);
      FUN_0089fd10();
      pdVar11 = (double *)FUN_009aab80();
      local_2030 = *pdVar11;
      FUN_0097bd30();
      if (local_2030 == (double)DAT_01109d64) {
        thunk_FUN_004279f0(&DAT_00f80e20,9);
      }
      else if (local_2030 <= _DAT_00efe278) {
        thunk_FUN_00428ed0(&local_1f7c,&DAT_00f80e2c,local_2030 / _DAT_00ef9ed0);
      }
      else {
        thunk_FUN_00428ed0(&local_1f7c,&DAT_00f80e3c,local_2030 / _DAT_00f0d930);
      }
      iVar17 = **(int **)(param_1 + 0x1b2);
      FUN_009a40f0();
      (**(code **)(iVar17 + 0x30))();
      iVar16 = local_1f7c;
      (**(code **)(**(int **)(param_1 + 0x1b2) + 0x68))(local_1f7c,0xffffffff,&local_1f64,0);
      iVar17 = **(int **)(param_1 + 0x1b2);
      uVar12 = FUN_009a40e0();
      (**(code **)(iVar17 + 0x30))(uVar12);
      FUN_008aa590(local_200c);
      (**(code **)(**(int **)(param_1 + 0x1b2) + 0x28))(local_1fa4);
      puVar8 = (undefined4 *)(iVar16 + -0x10);
      local_8 = CONCAT31(local_8._1_3_,0xb);
      piVar7 = (int *)(iVar16 + -4);
      LOCK();
      iVar17 = *piVar7;
      *piVar7 = *piVar7 + -1;
      UNLOCK();
      bVar19 = iVar17 + -1 < 0;
      bVar18 = iVar17 == 1;
    }
    else {
      FUN_008aa590();
      puVar8 = (undefined4 *)(local_1f7c + -0x10);
      local_8 = CONCAT31(local_8._1_3_,0xb);
      piVar7 = (int *)(local_1f7c + -4);
      LOCK();
      iVar17 = *piVar7;
      *piVar7 = *piVar7 + -1;
      UNLOCK();
      bVar19 = iVar17 + -1 < 0;
      bVar18 = iVar17 == 1;
    }
  }
  else {
LAB_008f1a18:
    FUN_008aa590();
    puVar8 = (undefined4 *)(local_1f7c + -0x10);
    piVar7 = (int *)(local_1f7c + -4);
    local_8 = CONCAT31(local_8._1_3_,0xb);
    LOCK();
    iVar17 = *piVar7;
    *piVar7 = *piVar7 + -1;
    UNLOCK();
    bVar19 = iVar17 + -1 < 0;
    bVar18 = iVar17 == 1;
  }
  if (bVar18 || bVar19) {
    (**(code **)(*(int *)*puVar8 + 4))();
  }
  local_8._0_1_ = 10;
  local_1fb0 = CPen::vftable;
  thunk_FUN_00439b90();
  local_8._0_1_ = 9;
  local_1fe8 = CPen::vftable;
  thunk_FUN_00439b90();
  local_8._0_1_ = 8;
  local_1fc8 = CPen::vftable;
  thunk_FUN_00439b90();
  local_8._0_1_ = 7;
  local_1ff0 = CPen::vftable;
  thunk_FUN_00439b90();
  local_8._0_1_ = 6;
  local_1fe0 = CPen::vftable;
  thunk_FUN_00439b90();
  local_8._0_1_ = 5;
  local_2000 = CPen::vftable;
  thunk_FUN_00439b90();
  local_8._0_1_ = 4;
  local_1fc0 = CPen::vftable;
  thunk_FUN_00439b90();
  local_8._0_1_ = 3;
  local_1fd8 = CPen::vftable;
  thunk_FUN_00439b90();
  local_8._0_1_ = 2;
  local_1fb8 = CPen::vftable;
  thunk_FUN_00439b90();
  local_8._0_1_ = 1;
  local_1ff8 = CPen::vftable;
  thunk_FUN_00439b90();
  local_8 = (uint)local_8._1_3_ << 8;
  local_2008 = CPen::vftable;
  thunk_FUN_00439b90();
  local_8 = 0xffffffff;
  local_1fd0 = CPen::vftable;
  thunk_FUN_00439b90();
LAB_008f242a:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

