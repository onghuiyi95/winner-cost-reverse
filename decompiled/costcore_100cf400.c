//==== FUN_100cf400 @ 0x100cf400 lines=1043 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

double * FUN_100cf400(double *param_1,int *param_2,uint *param_3,uint *param_4,undefined4 *param_5)

{
  double dVar1;
  double dVar2;
  char cVar3;
  undefined4 *puVar4;
  bool bVar5;
  float fVar6;
  float fVar7;
  uint *puVar8;
  undefined1 uVar9;
  undefined4 *puVar10;
  int iVar11;
  double *pdVar12;
  int *piVar13;
  undefined4 uVar14;
  int iVar15;
  uint *puVar16;
  int *piVar17;
  double *pdVar18;
  double *pdVar19;
  uint uVar20;
  double *pdVar21;
  double *pdVar22;
  int iVar23;
  double *pdVar24;
  undefined1 *puVar25;
  double *pdVar26;
  undefined1 *puVar27;
  undefined1 *puVar28;
  undefined4 *puVar29;
  double *pdVar30;
  int iVar31;
  float10 fVar32;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 extraout_ST0_01;
  float10 extraout_ST0_02;
  undefined8 uStack_1e0;
  uint uStack_1c4;
  double *pdStack_1c0;
  double *pdStack_1bc;
  double *local_1b8;
  double *pdStack_1b4;
  double *pdStack_1b0;
  undefined1 *puStack_1ac;
  uint *local_1a8;
  double *pdStack_1a4;
  int iStack_1a0;
  double *pdStack_19c;
  double *local_198;
  undefined4 local_194;
  undefined8 uStack_190;
  int iStack_188;
  undefined4 uStack_184;
  undefined1 auStack_180 [8];
  undefined4 uStack_178;
  uint uStack_174;
  undefined8 uStack_170;
  float fStack_168;
  float fStack_164;
  undefined4 *puStack_15c;
  int iStack_140;
  undefined4 *puStack_114;
  uint uStack_fc;
  uint uStack_f8;
  float fStack_f4;
  float fStack_f0;
  float fStack_ec;
  int iStack_d4;
  int iStack_a8;
  undefined1 auStack_98 [36];
  undefined1 auStack_74 [104];
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_101491ce;
  local_c = ExceptionList;
  local_194 = 0;
  if ((param_3 == (uint *)0x0) || (ExceptionList = &local_c, iVar11 = FUN_1008fe50(), iVar11 < 3)) {
    dVar2 = _DAT_10159428;
    *param_5 = 0;
    *param_1 = dVar2;
    *(undefined4 *)(param_1 + 1) = 0;
    ExceptionList = local_c;
    return param_1;
  }
  uStack_1e0._4_4_ = (double **)0x100cf44c;
  pdVar12 = (double *)FUN_1008fe20();
  uStack_1e0._4_4_ = (double **)0x100cf45b;
  local_1b8 = pdVar12;
  piVar13 = (int *)FUN_1008fe20();
  uStack_1e0._4_4_ = (double **)0x100cf46a;
  local_1a8 = (uint *)piVar13;
  local_198 = (double *)FUN_1008fe20();
  if (((pdVar12 == (double *)0x0) || (piVar13 == (int *)0x0)) || (local_198 == (double *)0x0)) {
    *param_1 = _DAT_10159428;
    *(undefined4 *)(param_1 + 1) = 0;
    ExceptionList = local_c;
    return param_1;
  }
  uStack_1e0._4_4_ = (double **)param_4;
  uStack_1e0._0_4_ = (char *)param_3;
  iVar11 = FUN_1009e2d0(param_2);
  if (iVar11 == 0) {
    dVar2 = (double)DAT_1019167c;
    *(undefined4 *)(param_1 + 1) = 0;
    *param_1 = dVar2;
    ExceptionList = local_c;
    return param_1;
  }
  uStack_1e0._4_4_ = (double **)0x100cf4d3;
  FUN_1008fea0();
  local_4 = 1;
  uStack_1e0._4_4_ = (double **)0x100cf4eb;
  FUN_1008fea0();
  local_4._0_1_ = 2;
  uStack_1e0._4_4_ = (double **)0x100cf500;
  FUN_1008fea0();
  local_4._0_1_ = 3;
  uStack_1e0._4_4_ = (double **)0x100cf515;
  FUN_1008fea0();
  local_4._0_1_ = 4;
  uStack_1e0._4_4_ = (double **)0x100cf52a;
  FUN_1008fea0();
  local_4._0_1_ = 5;
  uStack_1e0._4_4_ = (double **)0x100cf53f;
  FUN_1008fea0();
  local_4._0_1_ = 6;
  uStack_1e0._4_4_ = (double **)0x100cf554;
  FUN_1008fea0();
  uStack_1e0._4_4_ = (double **)local_1b8;
  local_4._0_1_ = 7;
  uStack_1e0._0_4_ = (char *)0x100cf570;
  fVar32 = (float10)(**(code **)(*param_2 + 0xc))();
  unique0x0000aa00 = (double)fVar32;
  uStack_1e0._0_4_ = auStack_98;
  fVar32 = (float10)(**(code **)(*param_2 + 0xc))(pdStack_1b0);
  uStack_170 = (double)fVar32;
  fVar32 = (float10)(**(code **)(*param_2 + 0xc))(local_1a8,auStack_74);
  auStack_180 = (undefined1  [8])(double)fVar32;
  uStack_1e0._4_4_ = (double **)param_5;
  uStack_1e0._0_4_ = (char *)param_4;
  FUN_1009e2d0();
  uStack_1e0._4_4_ = (double **)0x100cf5b9;
  pdStack_1c0 = (double *)FUN_100b23c0();
  uStack_1e0._4_4_ = (double **)param_5;
  uStack_1e0._0_4_ = (char *)param_4;
  FUN_1009e2d0();
  uStack_1e0._4_4_ = (double **)0x100cf5d2;
  iStack_1a0 = FUN_100b23c0();
  uStack_1e0._4_4_ = (double **)param_4;
  uStack_1e0._0_4_ = (char *)param_3;
  iVar11 = FUN_1009e2d0(param_2);
  iVar11 = *(int *)(iVar11 + 0x68);
  pdStack_19c = (double *)iVar11;
  if (((pdStack_1c0 == (double *)0x0) || (iStack_1a0 == 0)) || (iVar11 < 1)) {
LAB_100d08eb:
    fVar32 = (float10)DAT_1019167c;
    *(undefined4 *)(param_1 + 1) = 0;
  }
  else {
    local_1b8 = (double *)&uStack_1e0;
    uStack_1e0._0_4_ = SUB84(_DAT_10159428,0);
    uStack_1e0._4_4_ = (double **)((ulonglong)_DAT_10159428 >> 0x20);
    FUN_1008ff70(iVar11);
    local_1b8 = (double *)&uStack_1e0;
    uStack_1e0._0_4_ = SUB84(_DAT_10159428,0);
    uStack_1e0._4_4_ = (double **)((ulonglong)_DAT_10159428 >> 0x20);
    FUN_1008ff70(iVar11);
    pdVar12 = pdStack_19c;
    uStack_190 = _DAT_10159428;
    pdStack_1bc = (double *)0x0;
    uStack_1c4 = 0;
    if (0 < iVar11) {
      dVar2 = (double)DAT_1019167c;
      puStack_1ac = (undefined1 *)((int)pdStack_1c0 - iStack_1a0);
      pdStack_1b4 = (double *)(iStack_1a0 - (int)pdStack_1c0);
      local_1a8 = (uint *)0x0;
      pdStack_1b0 = pdStack_1c0;
      pdVar30 = (double *)0x0;
      pdVar21 = pdStack_1c0;
      do {
        *(double *)(iStack_d4 + (int)local_1a8) = _DAT_10159428;
        *(double *)(iStack_a8 + (int)local_1a8) = _DAT_10159428;
        pdVar22 = pdVar30;
        if (((*(double *)(puStack_1ac + iStack_1a0 + (int)local_1a8) != dVar2) &&
            (*(double *)(iStack_1a0 + (int)local_1a8) != dVar2)) &&
           (3 < (int)(uStack_1c4 - (int)pdVar30))) {
          dVar1 = *(double *)((int)pdStack_1b4 + (int)pdVar21);
          pdVar22 = (double *)((int)pdVar30 + 1);
          uStack_190 = *pdVar21;
          pdVar21 = pdVar22;
          pdStack_1a4 = pdVar30;
          if (3 < (int)((uStack_1c4 - (int)pdVar22) + 1)) {
            pdVar26 = (double *)((int)pdVar30 + 3);
            pdVar18 = (double *)((int)(pdStack_1b4 + 3) + (int)pdStack_1b0);
            pdVar19 = pdStack_1b0;
            do {
              pdVar24 = pdVar19 + 6;
              if (uStack_190 < *(double *)((int)pdVar19 + 0xc)) {
                uStack_190 = *(double *)((int)pdVar19 + 0xc);
                pdVar30 = pdVar21;
              }
              if (*(double *)((int)pdVar18 + -0xc) < dVar1) {
                dVar1 = *(double *)((int)pdVar18 + -0xc);
                pdStack_1a4 = pdVar21;
              }
              if (uStack_190 < *(double *)(puStack_1ac + (int)pdVar18)) {
                uStack_190 = *(double *)(puStack_1ac + (int)pdVar18);
                pdVar30 = (double *)((int)pdVar26 + -1);
              }
              if (*pdVar18 < dVar1) {
                pdStack_1a4 = (double *)((int)pdVar26 + -1);
                dVar1 = *pdVar18;
              }
              if (uStack_190 < *(double *)((int)pdVar19 + 0x24)) {
                uStack_190 = *(double *)((int)pdVar19 + 0x24);
                pdVar30 = pdVar26;
              }
              if (*(double *)((int)pdVar18 + 0xc) < dVar1) {
                dVar1 = *(double *)((int)pdVar18 + 0xc);
                pdStack_1a4 = pdVar26;
              }
              if (uStack_190 < *pdVar24) {
                uStack_190 = *pdVar24;
                pdVar30 = (double *)((int)pdVar26 + 1);
              }
              if (pdVar18[3] < dVar1) {
                pdStack_1a4 = (double *)((int)pdVar26 + 1);
                dVar1 = pdVar18[3];
              }
              pdVar21 = (double *)((int)pdVar21 + 4);
              pdVar18 = pdVar18 + 6;
              pdVar26 = (double *)((int)pdVar26 + 4);
              pdVar19 = pdVar24;
            } while ((int)pdVar21 <= (int)(uStack_1c4 - 3));
          }
          pdVar18 = pdStack_1a4;
          if ((int)pdVar21 <= (int)uStack_1c4) {
            pdVar19 = (double *)(iStack_1a0 + (int)pdVar21 * 0xc);
            do {
              if (uStack_190 < *(double *)(puStack_1ac + (int)pdVar19)) {
                uStack_190 = *(double *)(puStack_1ac + (int)pdVar19);
                pdVar30 = pdVar21;
              }
              if (*pdVar19 < dVar1) {
                dVar1 = *pdVar19;
                pdVar18 = pdVar21;
              }
              pdVar21 = (double *)((int)pdVar21 + 1);
              pdVar19 = (double *)((int)pdVar19 + 0xc);
            } while ((int)pdVar21 <= (int)uStack_1c4);
          }
          if ((int)pdVar30 - (int)pdStack_1bc == 2) {
LAB_100cf86e:
            *(double *)(iStack_d4 + (int)pdVar30 * 0xc) = _DAT_1015af08;
LAB_100cf881:
            if ((int)pdVar18 - (int)pdStack_1bc == 2) {
              *(double *)(iStack_a8 + (int)pdVar18 * 0xc) = _DAT_1015af08;
            }
          }
          else if ((int)pdVar18 - (int)pdStack_1bc == 2) {
            if ((int)pdVar30 - (int)pdStack_1bc == 2) goto LAB_100cf86e;
            goto LAB_100cf881;
          }
          pdVar21 = (double *)((int)pdStack_1b0 + 0xc);
          pdStack_1bc = pdVar22;
          pdStack_1b0 = pdVar21;
          local_198 = pdVar22;
        }
        uStack_1c4 = uStack_1c4 + 1;
        local_1a8 = (uint *)((int)local_1a8 + 0xc);
        pdVar30 = pdVar22;
      } while ((int)uStack_1c4 < (int)pdStack_19c);
    }
    local_1a8 = (uint *)((int)pdStack_19c * 0xc);
    *(double *)((int)local_1a8 + iStack_d4 + -0xc) = _DAT_1015af08;
    local_1b8 = (double *)&uStack_1e0;
    uStack_1e0._0_4_ = SUB84(_DAT_10159428,0);
    uStack_1e0._4_4_ = (double **)((ulonglong)_DAT_10159428 >> 0x20);
    pdStack_1b0 = (double *)0x0;
    FUN_1008ff70(pdStack_19c);
    local_1b8 = (double *)&uStack_1e0;
    uStack_1e0._0_4_ = SUB84(_DAT_10159428,0);
    uStack_1e0._4_4_ = (double **)((ulonglong)_DAT_10159428 >> 0x20);
    FUN_1008ff70(pdVar12);
    puVar25 = (undefined1 *)0x0;
    if (0 < (int)pdVar12) {
      uStack_1c4 = 0;
      puVar27 = (undefined1 *)0x0;
      do {
        *(double *)(uStack_1c4 + iStack_140) = _DAT_10159428;
        iVar11 = FUN_100dd8dc();
        puVar28 = puVar27;
        pdVar30 = pdStack_1b0;
        dVar2 = uStack_190;
        if (iVar11 == 1) {
          dVar1 = _DAT_10159428;
          if (*(double *)(uStack_1c4 + (int)pdStack_1c0) != (double)DAT_1019167c) {
            dVar1 = *(double *)(uStack_1c4 + (int)pdStack_1c0);
          }
          puVar28 = puVar25;
          pdVar30 = (double *)puVar25;
          dVar2 = dVar1;
          if (puVar27 != (undefined1 *)0x0) {
            local_1b8 = (double *)(puVar25 + -(int)puVar27);
            if ((float10)(int)local_1b8 <= extraout_ST0) {
              puVar28 = puVar27;
              pdVar30 = pdStack_1b0;
              dVar2 = uStack_190;
              if (uStack_190 < dVar1) {
                puVar28 = puVar25;
                pdVar30 = (double *)puVar25;
                dVar2 = dVar1;
              }
            }
            else {
              pdStack_1b4 = (double *)(puVar27 + -1);
              pdVar12 = pdStack_19c;
              if (-1 < (int)pdStack_1b4) {
                pdVar21 = (double *)((int)pdStack_1c0 + (int)pdStack_1b4 * 0xc);
                do {
                  if ((float10)(int)pdStack_1b4 <= (float10)(int)pdStack_1b0 - extraout_ST0) break;
                  if (*(double *)((int)pdStack_1c0 + (int)puVar27 * 0xc) < *pdVar21)
                  goto LAB_100cfa64;
                  pdStack_1b4 = (double *)((int)pdStack_1b4 + -1);
                  pdVar21 = (double *)((int)pdVar21 + -0xc);
                } while (-1 < (int)pdStack_1b4);
              }
              *(double *)(iStack_140 + (int)puVar27 * 0xc) = _DAT_1015af08;
            }
          }
        }
LAB_100cfa64:
        uStack_190 = dVar2;
        pdStack_1b0 = pdVar30;
        puVar25 = puVar25 + 1;
        uStack_1c4 = uStack_1c4 + 0xc;
        puVar27 = puVar28;
      } while ((int)puVar25 < (int)pdVar12);
      if (puVar28 != (undefined1 *)0x0) {
        *(double *)(iStack_140 + (int)puVar28 * 0xc) = _DAT_1015af08;
      }
    }
    *(double *)((int)local_1a8 + iStack_140 + -0xc) = _DAT_1015af08;
    uStack_190 = (double)DAT_1019167c;
    puVar29 = puStack_114;
    for (uVar20 = (uint)local_1a8 >> 2; uVar20 != 0; uVar20 = uVar20 - 1) {
      *puVar29 = 0;
      puVar29 = puVar29 + 1;
    }
    for (uVar20 = (uint)local_1a8 & 3; uVar20 != 0; uVar20 = uVar20 - 1) {
      *(undefined1 *)puVar29 = 0;
      puVar29 = (undefined4 *)((int)puVar29 + 1);
    }
    pdVar30 = (double *)0x0;
    pdStack_1a4 = (double *)0x0;
    pdStack_1b4 = (double *)0x0;
    if (0 < (int)pdVar12) {
      puStack_1ac = (undefined1 *)0x0;
      pdStack_1b0 = (double *)0x0;
      do {
        iVar11 = FUN_100dd8dc();
        if (0 < iVar11) {
          fVar32 = extraout_ST0_00;
          if ((int)pdStack_1b4 <= (int)pdVar30) {
            local_1b8 = (double *)(iStack_a8 - iStack_1a0);
            pdVar12 = (double *)((int)pdStack_1b0 + iStack_1a0);
            pdVar21 = pdStack_1b4;
            do {
              iVar11 = FUN_100dd8dc();
              if ((((0 < iVar11) && (dVar2 = *pdVar12, dVar2 < uStack_190)) &&
                  (dVar2 < *(double *)((int)pdStack_1b0 + (int)pdStack_1c0))) &&
                 (dVar2 < *(double *)(puStack_1ac + (int)pdStack_1c0))) {
                pdStack_1a4 = pdVar21;
                uStack_190 = dVar2;
              }
              pdVar21 = (double *)((int)pdVar21 + 1);
              pdVar12 = (double *)((int)pdVar12 + 0xc);
              fVar32 = extraout_ST0_01;
            } while ((int)pdVar21 <= (int)pdVar30);
          }
          if (((int)pdStack_1b4 < (int)pdStack_1a4) && ((int)pdStack_1a4 < (int)pdVar30)) {
            *(double *)(puStack_114 + (int)pdStack_1a4 * 3) = _DAT_1015af08;
          }
          else if (*(double *)(puStack_1ac + (int)pdStack_1c0) <=
                   *(double *)((int)pdStack_1b0 + (int)pdStack_1c0)) {
            *(double *)(puStack_1ac + iStack_140) = _DAT_10159428;
          }
          else {
            *(double *)((int)pdStack_1b0 + iStack_140) = _DAT_10159428;
          }
          uStack_190 = (double)fVar32;
          pdStack_1b0 = (double *)puStack_1ac;
          pdVar12 = pdStack_19c;
          pdStack_1b4 = pdVar30;
          pdStack_1a4 = pdVar30;
        }
        pdVar30 = (double *)((int)pdVar30 + 1);
        puStack_1ac = puStack_1ac + 0xc;
      } while ((int)pdVar30 < (int)pdVar12);
    }
    iVar11 = FUN_100dd8dc();
    pdVar30 = pdStack_19c;
    puVar8 = (uint *)uStack_1e0._4_4_;
    puVar16 = (uint *)(char *)uStack_1e0;
    uStack_1e0._0_4_ = SUB84(_DAT_10159428,0);
    uStack_1e0._4_4_ = (double **)((ulonglong)_DAT_10159428 >> 0x20);
    if (iVar11 == 0) {
      local_1b8 = (double *)&uStack_1e0;
      FUN_1008ff70(pdVar12);
      param_4[4] = param_4[4] | 0x100;
      iVar11 = FUN_100dd8dc();
      if (iVar11 == 0) {
        uVar20 = FUN_100c29e0();
        uStack_170 = (double)(ulonglong)uVar20;
        local_4._0_1_ = 8;
        piVar13 = (int *)FUN_101129b5();
        iVar11 = (**(code **)(*piVar13 + 0xc))();
        uStack_1c4 = iVar11 + 0x10;
        uStack_1e0._4_4_ = (double **)0x0;
        uStack_1e0._0_4_ = (char *)param_4;
        local_4 = CONCAT31(local_4._1_3_,9);
        iVar11 = FUN_1009e180();
        if (iVar11 < (int)pdVar12) {
          pdStack_1b4 = (double *)(iStack_1a0 - (int)pdStack_1c0);
          iVar31 = iVar11 * 0xc;
          local_1a8 = (uint *)((int)pdVar12 - iVar11);
          pdVar12 = pdStack_1b0;
          do {
            bVar5 = false;
            iVar11 = FUN_100dd8dc();
            if (0 < iVar11) {
              *(undefined8 *)(iVar31 + param_4[5]) = *(undefined8 *)(iVar31 + (int)pdStack_1c0);
              uStack_1e0._4_4_ = (double **)0x0;
              bVar5 = true;
              uStack_1e0._0_4_ = (char *)0x100cfcf3;
              pdVar12 = (double *)FUN_1009f070();
              *(undefined1 *)pdVar12 = 0x1b;
              *(undefined1 *)((int)pdVar12 + 1) = 1;
              uStack_1e0._4_4_ = SUB84(SQRT(*(double *)(iVar31 + (int)pdStack_1c0)),0);
              uStack_1e0._0_4_ = "%.3lf";
              FUN_10001d30(&uStack_1c4);
              if (DAT_101961ac != (code *)0x0) {
                uStack_1e0._4_4_ = (double **)&uStack_1c4;
                uStack_1e0._0_4_ = (char *)0x100cfd2f;
                uVar14 = (*DAT_101961ac)();
                *(undefined4 *)((int)pdVar12 + 0xc) = uVar14;
              }
              *(double **)(param_4[5] + 8 + iVar31) = pdVar12;
            }
            iVar11 = FUN_100dd8dc();
            if (iVar11 < 1) {
              *(undefined8 *)(iVar31 + param_4[5]) = *(undefined8 *)(iVar31 + (int)pdStack_1c0);
            }
            else {
              local_1b8 = (double *)((undefined1 *)(iVar31 + (int)pdStack_1b4) + (int)pdStack_1c0);
              *(undefined8 *)(iVar31 + param_4[5]) =
                   *(undefined8 *)((undefined1 *)(iVar31 + (int)pdStack_1b4) + (int)pdStack_1c0);
              if (bVar5) {
                *(undefined1 *)((int)pdVar12 + 1) = 3;
              }
              else {
                uStack_1e0._4_4_ = (double **)0x0;
                uStack_1e0._0_4_ = (char *)0x100cfd80;
                pdVar12 = (double *)FUN_1009f070();
                *(undefined1 *)pdVar12 = 0x1b;
                *(undefined1 *)((int)pdVar12 + 1) = 2;
              }
              uStack_1e0._4_4_ = SUB84(SQRT(*local_1b8),0);
              uStack_1e0._0_4_ = "%.3lf";
              FUN_10001d30(&uStack_1c4);
              if (DAT_101961ac != (code *)0x0) {
                uStack_1e0._4_4_ = (double **)&uStack_1c4;
                uStack_1e0._0_4_ = (char *)0x100cfdc2;
                uVar14 = (*DAT_101961ac)();
                *(undefined4 *)((int)pdVar12 + 0xc) = uVar14;
              }
              *(double **)(param_4[5] + 8 + iVar31) = pdVar12;
            }
            iVar31 = iVar31 + 0xc;
            local_1a8 = (uint *)((int)local_1a8 + -1);
          } while (local_1a8 != (uint *)0x0);
        }
        local_4 = CONCAT31(local_4._1_3_,8);
        piVar13 = (int *)(uStack_1c4 - 4);
        LOCK();
        iVar11 = *piVar13;
        *piVar13 = *piVar13 + -1;
        UNLOCK();
        if (iVar11 == 1 || iVar11 + -1 < 0) {
          uStack_1e0._4_4_ = (double **)0x100cfe16;
          (**(code **)(**(int **)(uStack_1c4 - 0x10) + 4))();
        }
        puVar29 = (undefined4 *)*(uint *)uStack_170;
        *(uint *)uStack_170 = (uint)(uint *)uStack_170;
        ((uint *)uStack_170)[1] = (uint)(uint *)uStack_170;
        if (puVar29 == (uint *)uStack_170) {
                    /* WARNING: Subroutine does not return */
          uStack_1e0._4_4_ = (double **)&UNK_100cfe3c;
          _free((uint *)uStack_170);
        }
                    /* WARNING: Subroutine does not return */
        uStack_1e0._4_4_ = (double **)&UNK_100cfe2d;
        _free(puVar29);
      }
      if (iVar11 == 1) {
        uStack_190 = (double)((ulonglong)uStack_190 & 0xffffffff);
        iStack_188 = 0;
        uStack_184 = 0;
        FUN_10001710();
        local_4._0_1_ = 0xb;
        uStack_1c4 = 0;
        puStack_1ac = (undefined1 *)0x0;
        if ((int)pdVar12 < 200) {
          *(undefined4 *)(param_1 + 1) = 0;
        }
        else {
          uStack_1e0._4_4_ = (double **)0x0;
          uStack_1e0._0_4_ = (char *)param_4;
          uVar20 = FUN_1009e180();
          if ((int)uVar20 < (int)pdVar12) {
            iVar31 = uVar20 * 0xc;
            pdStack_1b4 = (double *)(iStack_1a0 - (int)pdStack_1c0);
            iVar11 = 0;
            do {
              iVar15 = FUN_100dd8dc();
              if (iVar15 < 1) {
LAB_100cff53:
                iVar15 = FUN_100dd8dc();
                if (iVar15 < 1) {
                  *(undefined8 *)(iVar31 + param_4[5]) = *(undefined8 *)(iVar31 + (int)pdStack_1c0);
                }
                else {
                  if ((puStack_1ac != (undefined1 *)0x2) && (puStack_1ac != (undefined1 *)0x0)) {
                    uStack_fc = uStack_1c4;
                    fStack_f4 = (float)*(double *)(iVar11 + (int)pdStack_1c0);
                    fStack_f0 = (float)*(double *)
                                        ((undefined1 *)(iVar31 + (int)pdStack_1b4) +
                                        (int)pdStack_1c0);
                    fStack_ec = fStack_f4 / fStack_f0;
                    uStack_1e0._4_4_ = (double **)0x100cffcf;
                    uStack_f8 = uVar20;
                    FUN_100ca610();
                  }
                  puStack_1ac = (undefined1 *)0x2;
                  iVar11 = iVar31;
                  uStack_1c4 = uVar20;
                }
              }
              else {
                if ((puStack_1ac != (undefined1 *)0x1) && (puStack_1ac != (undefined1 *)0x0)) {
                  fStack_168 = (float)*(double *)(iVar11 + iStack_1a0);
                  uStack_170 = (double)CONCAT44((float)*(double *)(iVar31 + (int)pdStack_1c0),
                                                uStack_1c4);
                  fStack_164 = (float)*(double *)(iVar31 + (int)pdStack_1c0) / fStack_168;
                  uStack_1e0._4_4_ = (double **)0x100cff45;
                  uStack_174 = uVar20;
                  FUN_100ca610();
                  puStack_1ac = (undefined1 *)0x1;
                  iVar11 = iVar31;
                  uStack_1c4 = uVar20;
                  goto LAB_100cff53;
                }
                puStack_1ac = (undefined1 *)0x1;
                iVar11 = iVar31;
                uStack_1c4 = uVar20;
              }
              uVar20 = uVar20 + 1;
              iVar31 = iVar31 + 0xc;
            } while ((int)uVar20 < (int)pdStack_19c);
            if ((uStack_190._4_4_ != 0) &&
               (pdVar12 = (double *)((iStack_188 - uStack_190._4_4_) / 0x14), local_1b8 = pdVar12,
               pdVar12 != (double *)0x0)) {
              puVar16 = (uint *)FUN_100c29e0();
              uStack_170 = (double)ZEXT48(puVar16);
              local_4._0_1_ = 0xc;
              FUN_100ca6a0();
              local_4._0_1_ = 0xd;
              FUN_100ca6a0();
              uStack_1c4 = 0;
              pdStack_1bc = (double *)0x0;
              local_4 = CONCAT31(local_4._1_3_,0xe);
              piVar13 = (int *)(uStack_190._4_4_ + 4);
              while (pdStack_1bc < pdVar12) {
                local_1a8 = puVar16 + 1;
                uStack_1e0._4_4_ = (double **)*local_1a8;
                uStack_1e0._0_4_ = (char *)puVar16;
                uVar20 = FUN_100c2a40();
                uStack_1e0._4_4_ = (double **)0x100d00cf;
                FUN_100c5e40();
                *local_1a8 = uVar20;
                **(uint **)(uVar20 + 4) = uVar20;
                local_1a8 = (uint *)FUN_100dd8dc();
                uStack_1e0._4_4_ = (double **)0x100d00f9;
                piVar17 = (int *)FUN_100ca6d0();
                *piVar17 = *piVar17 + 1;
                uVar20 = piVar13[-1] - *piVar13 >> 0x1f;
                iVar11 = (piVar13[-1] - *piVar13 ^ uVar20) - uVar20;
                uStack_1c4 = uStack_1c4 + 1 + iVar11;
                local_1a8 = (uint *)(iVar11 + 1);
                uStack_1e0._4_4_ = (double **)0x100d0129;
                piVar17 = (int *)FUN_100ca6d0();
                pdStack_1bc = (double *)((int)pdStack_1bc + 1);
                *piVar17 = *piVar17 + 1;
                piVar13 = piVar13 + 5;
                pdVar12 = local_1b8;
                puVar16 = (uint *)uStack_170;
              }
              FUN_100cf1e0();
              uStack_1c4 = uStack_1c4 / (uint)pdVar12;
              uVar20 = 0;
              pdStack_1bc = (double *)0x0;
              fVar7 = _DAT_1014f174;
              for (puVar29 = (undefined4 *)*(uint *)uStack_170; puVar29 != (uint *)uStack_170;
                  puVar29 = (undefined4 *)*puVar29) {
                uVar20 = uVar20 + 1;
                if (uVar20 == uStack_170._4_4_ >> 1) {
                  pdStack_1bc = (double *)puVar29[2];
                }
                fVar7 = fVar7 + (float)puVar29[2];
              }
              fVar6 = (float)(int)uStack_170._4_4_;
              if ((longlong)uStack_170 < 0) {
                fVar6 = fVar6 + _DAT_1015dec8;
              }
              pdStack_1b4 = (double *)(fVar7 / fVar6);
              piVar13 = (int *)(uStack_190._4_4_ + 4);
              for (pdStack_19c = (double *)0x0; pdStack_19c < pdVar12;
                  pdStack_19c = (double *)((int)pdStack_19c + 1)) {
                iVar11 = piVar13[-1];
                iVar31 = *piVar13;
                if (pdStack_19c == (double *)((int)pdVar12 + -1)) {
                  iVar15 = 0;
                  uStack_1e0._4_4_ = (double **)0x0;
                  if (iVar31 < iVar11) {
                    *(undefined8 *)(iVar11 * 0xc + param_4[5]) =
                         *(undefined8 *)(iVar11 * 0xc + (int)pdStack_1c0);
                    uStack_1e0._0_4_ = (char *)0x100d01f8;
                    pdStack_1b0 = (double *)FUN_1009f070();
                    uVar14 = auStack_180._4_4_;
                    *(undefined1 *)pdStack_1b0 = 0x1b;
                    *(undefined1 *)((int)pdStack_1b0 + 1) = 1;
                    local_1a8 = *(uint **)auStack_180._4_4_;
                    puStack_1ac = (undefined1 *)0x0;
                    local_198 = (double *)0x0;
                    if (local_1a8 != (uint *)auStack_180._4_4_) {
                      iVar11 = 0;
                      do {
                        if (iVar11 < (int)local_1a8[4]) {
                          puStack_1ac = (undefined1 *)local_1a8[3];
                          iVar11 = local_1a8[4];
                        }
                        FUN_100c01b0();
                      } while (local_1a8 != (uint *)uVar14);
                    }
                    puVar29 = (undefined4 *)*puStack_15c;
                    iVar11 = 0;
                    while (puVar29 != puStack_15c) {
                      if (iVar11 < (int)puVar29[4]) {
                        iVar11 = puVar29[4];
                      }
                      if (*(char *)((int)puVar29 + 0x15) == '\0') {
                        puVar4 = (undefined4 *)puVar29[2];
                        if (*(char *)((int)puVar4 + 0x15) == '\0') {
                          cVar3 = *(char *)((int)*puVar4 + 0x15);
                          puVar29 = puVar4;
                          puVar4 = (undefined4 *)*puVar4;
                          while (cVar3 == '\0') {
                            cVar3 = *(char *)((int)*puVar4 + 0x15);
                            puVar29 = puVar4;
                            puVar4 = (undefined4 *)*puVar4;
                          }
                        }
                        else {
                          cVar3 = *(char *)((int)puVar29[1] + 0x15);
                          puVar10 = (undefined4 *)puVar29[1];
                          puVar4 = puVar29;
                          while ((puVar29 = puVar10, cVar3 == '\0' &&
                                 (puVar4 == (undefined4 *)puVar29[2]))) {
                            cVar3 = *(char *)((int)puVar29[1] + 0x15);
                            puVar10 = (undefined4 *)puVar29[1];
                            puVar4 = puVar29;
                          }
                        }
                      }
                    }
                  }
                  else {
                    *(undefined8 *)(iVar31 * 0xc + param_4[5]) =
                         *(undefined8 *)(iVar31 * 0xc + iStack_1a0);
                    uStack_1e0._0_4_ = (char *)0x100d02d3;
                    pdStack_1b0 = (double *)FUN_1009f070();
                    uVar14 = auStack_180._4_4_;
                    *(undefined1 *)pdStack_1b0 = 0x1b;
                    *(undefined1 *)((int)pdStack_1b0 + 1) = 2;
                    local_1a8 = *(uint **)auStack_180._4_4_;
                    puStack_1ac = (undefined1 *)0x0;
                    local_198 = (double *)0x0;
                    while (local_1a8 != (uint *)uVar14) {
                      if (iVar15 < (int)local_1a8[4]) {
                        puStack_1ac = (undefined1 *)local_1a8[3];
                        iVar15 = local_1a8[4];
                      }
                      FUN_100c01b0();
                    }
                    puVar29 = (undefined4 *)*puStack_15c;
                    iVar11 = 0;
                    while (puVar29 != puStack_15c) {
                      if (iVar11 < (int)puVar29[4]) {
                        iVar11 = puVar29[4];
                      }
                      if (*(char *)((int)puVar29 + 0x15) == '\0') {
                        puVar4 = (undefined4 *)puVar29[2];
                        if (*(char *)((int)puVar4 + 0x15) == '\0') {
                          cVar3 = *(char *)((int)*puVar4 + 0x15);
                          puVar29 = puVar4;
                          puVar4 = (undefined4 *)*puVar4;
                          while (cVar3 == '\0') {
                            cVar3 = *(char *)((int)*puVar4 + 0x15);
                            puVar29 = puVar4;
                            puVar4 = (undefined4 *)*puVar4;
                          }
                        }
                        else {
                          cVar3 = *(char *)((int)puVar29[1] + 0x15);
                          puVar10 = (undefined4 *)puVar29[1];
                          puVar4 = puVar29;
                          while ((puVar29 = puVar10, cVar3 == '\0' &&
                                 (puVar4 == (undefined4 *)puVar29[2]))) {
                            cVar3 = *(char *)((int)puVar29[1] + 0x15);
                            puVar10 = (undefined4 *)puVar29[1];
                            puVar4 = puVar29;
                          }
                        }
                      }
                    }
                  }
                  uStack_1e0._4_4_ = (double **)uStack_1c4;
                  uStack_1e0._0_4_ =
                       (char *)((ulonglong)((double)(int)puStack_1ac * _DAT_1015ab98) >> 0x20);
                  FUN_10001d30(&pdStack_1a4,"%.3f,%.3f,%.3f,%.3f,%d,%d",(double)(float)piVar13[3],
                               (double)(float)pdStack_1b4,(double)(float)pdStack_1bc,
                               SUB84((double)(int)puStack_1ac * _DAT_1015ab98,0));
                  if (DAT_101961ac != (code *)0x0) {
                    uStack_1e0._4_4_ = &pdStack_1a4;
                    uStack_1e0._0_4_ = (char *)0x100d03d0;
                    uVar14 = (*DAT_101961ac)();
                    *(undefined4 *)((int)pdStack_1b0 + 0xc) = uVar14;
                  }
                }
                else {
                  uStack_1e0._4_4_ = (double **)0x0;
                  if (iVar31 < iVar11) {
                    *(undefined8 *)(iVar11 * 0xc + param_4[5]) =
                         *(undefined8 *)(iVar11 * 0xc + (int)pdStack_1c0);
                    uStack_1e0._0_4_ = (char *)0x100d0402;
                    puVar25 = (undefined1 *)FUN_1009f070();
                    *puVar25 = 0x1b;
                    puVar25[1] = 1;
                  }
                  else {
                    *(undefined8 *)(iVar31 * 0xc + param_4[5]) =
                         *(undefined8 *)(iVar31 * 0xc + iStack_1a0);
                    uStack_1e0._0_4_ = (char *)0x100d0436;
                    puVar25 = (undefined1 *)FUN_1009f070();
                    *puVar25 = 0x1b;
                    puVar25[1] = 2;
                  }
                  uStack_1e0 = (double)(float)piVar13[3];
                  FUN_10001d30();
                  if (DAT_101961ac != (code *)0x0) {
                    uStack_1e0._4_4_ = &pdStack_1a4;
                    uStack_1e0._0_4_ = (char *)0x100d0476;
                    uVar14 = (*DAT_101961ac)();
                    *(undefined4 *)(puVar25 + 0xc) = uVar14;
                  }
                }
                piVar13 = piVar13 + 5;
                pdVar12 = local_1b8;
              }
              uStack_1e0._4_4_ = (double **)*puStack_15c;
              uStack_1e0._0_4_ = (char *)&local_1b8;
              local_4 = CONCAT31(local_4._1_3_,0xd);
              FUN_100c5ee0();
                    /* WARNING: Subroutine does not return */
              uStack_1e0._4_4_ = (double **)&UNK_100d04bc;
              _free(puStack_15c);
            }
          }
          *(undefined4 *)(param_1 + 1) = 0;
        }
        local_194 = 1;
        *param_1 = (double)DAT_1019167c;
        FUN_100014b0();
        FUN_100c5040();
        goto LAB_100d0ad7;
      }
      goto LAB_100d08eb;
    }
    if ((_DAT_1015af08 <= (double)auStack_180) && ((double)auStack_180 < _DAT_10159700)) {
      local_1b8 = (double *)&uStack_1e0;
      FUN_1008ff70(pdVar12);
      param_4[4] = param_4[4] | 0x100;
      iVar11 = FUN_100dd8dc();
      if (iVar11 == 1) {
        piVar13 = (int *)0x0;
        uStack_1c4 = 0;
        pdStack_1b4 = (double *)0x0;
        if (0 < (int)pdVar12) {
          iVar31 = 0;
          pdVar12 = local_1b8;
          iVar11 = (int)local_1b8 * 0xc;
LAB_100d05e1:
          *(undefined8 *)(iVar31 + param_4[5]) = *(undefined8 *)(iVar31 + (int)pdStack_1c0);
          pdVar30 = pdVar12;
          iVar15 = iVar11;
          if (((_DAT_1015af08 <= *(double *)(iVar31 + iStack_140)) &&
              (local_1a8 = (uint *)((int)piVar13 + 1), pdVar30 = pdStack_1b4,
              piVar13 = (int *)local_1a8, iVar15 = iVar31, local_1a8 != (uint *)0x1)) &&
             (pdVar30 = pdVar12, iVar15 = iVar11, local_1a8 == (uint *)0x2)) {
            if ((int)pdVar12 < (int)pdStack_1b4) {
              pdStack_1bc = (double *)((int)puStack_114 + iVar11);
              do {
                if (_DAT_1015af08 <= *pdStack_1bc) {
                  if ((int)pdVar30 < 1) goto LAB_100d07b9;
                  pdStack_1b0 = (double *)((int)pdVar30 * 0xc);
                  dVar2 = *(double *)((int)pdStack_1c0 + iVar11) -
                          *(double *)(iVar31 + (int)pdStack_1c0);
                  if (dVar2 <= (double)_DAT_1014f174) {
                    dVar2 = -dVar2;
                  }
                  dVar2 = dVar2 / (*(double *)((int)pdStack_1c0 + iVar11) -
                                  *(double *)((int)pdStack_1b0 + iStack_1a0));
                  if ((((double)_DAT_1015f708 <= dVar2) || (dVar2 <= (double)_DAT_1014f174)) ||
                     ((int)pdVar12 < 1)) goto LAB_100d07b9;
                  pdStack_1bc = (double *)((int)puStack_114 + iVar11);
                  pdVar30 = pdVar12;
                  goto LAB_100d06f0;
                }
                pdVar30 = (double *)((int)pdVar30 + 1);
                pdStack_1bc = (double *)((int)pdStack_1bc + 0xc);
              } while ((int)pdVar30 < (int)pdStack_1b4);
              pdVar30 = pdStack_1b4;
              piVar13 = (int *)0x1;
              iVar15 = iVar31;
            }
            else {
LAB_100d07b9:
              pdVar30 = pdStack_1b4;
              piVar13 = (int *)0x1;
              iVar15 = iVar31;
            }
          }
          goto LAB_100d08d7;
        }
      }
      goto LAB_100d08eb;
    }
    if ((((double)auStack_180 < _DAT_10159700) || (_DAT_1015f700 <= (double)auStack_180)) &&
       ((double)auStack_180 == _DAT_1015f6f8)) {
      local_1b8 = (double *)&uStack_1e0;
      iVar31 = 0;
      FUN_1008ff70(pdStack_19c);
      param_4[4] = param_4[4] | 0x100;
      FUN_10001710();
      uStack_1e0._4_4_ = (double **)0x0;
      uStack_1e0._0_4_ = (char *)param_4;
      local_4 = CONCAT31(local_4._1_3_,0xf);
      iVar11 = FUN_1009e180();
      if (iVar11 < (int)pdVar30) {
        pdStack_1b4 = (double *)(iStack_1a0 - (int)pdStack_1c0);
        iVar15 = iVar11 * 0xc;
        local_1b8 = (double *)((int)pdStack_19c - iVar11);
        do {
          uStack_1e0._4_4_ = (double **)0x0;
          uStack_1e0._0_4_ = (char *)0x100d09c0;
          puVar25 = (undefined1 *)FUN_1009f070();
          iVar11 = FUN_100dd8dc();
          if (iVar11 < 1) {
            iVar11 = FUN_100dd8dc();
            if (0 < iVar11) {
              *(undefined8 *)(iVar15 + param_4[5]) =
                   *(undefined8 *)((undefined1 *)(iVar15 + (int)pdStack_1b4) + (int)pdStack_1c0);
              puVar25[1] = 2;
              goto LAB_100d09e7;
            }
            *(undefined8 *)(iVar15 + param_4[5]) = *(undefined8 *)(iVar15 + (int)pdStack_1c0);
            *(undefined1 **)(iVar15 + 8 + param_4[5]) = puVar25;
            puVar25[1] = 3;
          }
          else {
            *(undefined8 *)(iVar15 + param_4[5]) = *(undefined8 *)(iVar15 + (int)pdStack_1c0);
            puVar25[1] = 1;
LAB_100d09e7:
            *puVar25 = 0x1d;
            uStack_1e0._4_4_ = (double **)(iVar31 % 0x1a + 0x41);
            uStack_1e0._0_4_ = &DAT_1015f6ec;
            FUN_10001d30(&uStack_1c4);
            if (DAT_101961ac != (code *)0x0) {
              uStack_1e0._4_4_ = (double **)&uStack_1c4;
              uStack_1e0._0_4_ = (char *)0x100d0a1f;
              uVar14 = (*DAT_101961ac)();
              *(undefined4 *)(puVar25 + 0xc) = uVar14;
            }
            iVar31 = iVar31 + 1;
          }
          iVar15 = iVar15 + 0xc;
          local_1b8 = (double *)((int)local_1b8 + -1);
        } while (local_1b8 != (double *)0x0);
      }
      *param_1 = (double)DAT_1019167c;
      *(undefined4 *)(param_1 + 1) = 0;
      local_194 = 1;
      local_4._0_1_ = 7;
      piVar13 = (int *)(uStack_1c4 - 4);
      LOCK();
      iVar11 = *piVar13;
      *piVar13 = *piVar13 + -1;
      UNLOCK();
      if (iVar11 == 1 || iVar11 + -1 < 0) {
        uStack_1e0._4_4_ = (double **)0x100d0ac1;
        (**(code **)(**(int **)(uStack_1c4 - 0x10) + 4))();
      }
      goto LAB_100d0ad7;
    }
    *(undefined4 *)(param_1 + 1) = 0;
    fVar32 = extraout_ST0_02;
    uStack_1e0._0_4_ = (char *)puVar16;
    uStack_1e0._4_4_ = (double **)puVar8;
  }
  *param_1 = (double)fVar32;
  local_194 = 1;
LAB_100d0ad7:
  local_4._0_1_ = 6;
  FUN_1008fef0();
  local_4._0_1_ = 5;
  FUN_1008fef0();
  local_4._0_1_ = 4;
  FUN_1008fef0();
  local_4._0_1_ = 3;
  FUN_1008fef0();
  local_4._0_1_ = 2;
  FUN_1008fef0();
  local_4._0_1_ = 1;
  FUN_1008fef0();
  local_4 = (uint)local_4._1_3_ << 8;
  FUN_1008fef0();
  ExceptionList = local_c;
  return param_1;
  while( true ) {
    pdVar30 = (double *)((int)pdVar30 + -1);
    pdStack_1bc = (double *)((int)pdStack_1bc + -0xc);
    if ((int)pdVar30 < 1) break;
LAB_100d06f0:
    if (_DAT_1015af08 <= *pdStack_1bc) {
      if ((((int)pdVar30 < 1) ||
          (local_1b8 = (double *)((int)pdVar30 * 0xc),
          *(double *)((int)pdStack_1b0 + iStack_1a0) <= *(double *)((int)local_1b8 + iStack_1a0)))
         || ((int)pdStack_19c <= (int)pdStack_1b4)) goto LAB_100d07b9;
      pdStack_1bc = (double *)((int)puStack_114 + iVar31);
      pdVar30 = pdStack_1b4;
      goto LAB_100d0760;
    }
  }
  pdVar30 = pdStack_1b4;
  piVar13 = (int *)0x1;
  iVar15 = iVar31;
  goto LAB_100d08d7;
  while( true ) {
    pdStack_1bc = (double *)((int)pdStack_1bc + 0xc);
    pdVar30 = (double *)((int)pdVar30 + 1);
    if ((int)pdStack_19c <= (int)pdVar30) break;
LAB_100d0760:
    if (_DAT_1015af08 <= *pdStack_1bc) {
      if ((int)pdVar30 < 1) goto LAB_100d07b9;
      iVar23 = (int)pdVar30 * 0xc;
      pdVar30 = pdVar12;
      if (*(double *)(iVar23 + iStack_1a0) < *(double *)((int)pdStack_1b0 + iStack_1a0)) {
        uStack_1c4 = uStack_1c4 + 1;
        uStack_1e0._4_4_ = (double **)0x0;
        uStack_1e0._0_4_ = (char *)0x100d07e2;
        pdStack_1bc = (double *)FUN_1009f070();
        *(undefined1 *)((int)pdStack_1bc + 1) = (undefined1)uStack_1c4;
        *(undefined1 *)pdStack_1bc = 0x1c;
        *(undefined8 *)((int)local_1b8 + param_4[5]) = *(undefined8 *)((int)local_1b8 + iStack_1a0);
        *(double **)(param_4[5] + 8 + (int)local_1b8) = pdStack_1bc;
        uStack_1e0._4_4_ = (double **)0x0;
        uStack_1e0._0_4_ = (char *)0x100d081e;
        pdStack_1bc = (double *)FUN_1009f070();
        *(undefined1 *)((int)pdStack_1bc + 1) = (undefined1)uStack_1c4;
        *(undefined1 *)pdStack_1bc = 0x1c;
        *(undefined8 *)((int)pdStack_1b0 + param_4[5]) =
             *(undefined8 *)((int)pdStack_1b0 + iStack_1a0);
        *(double **)((int)pdStack_1b0 + param_4[5] + 8) = pdStack_1bc;
        uStack_1e0._4_4_ = (double **)0x0;
        uStack_1e0._0_4_ = (char *)0x100d0856;
        puVar25 = (undefined1 *)FUN_1009f070();
        puVar25[1] = (undefined1)uStack_1c4;
        *puVar25 = 0x1c;
        *(undefined8 *)(iVar23 + param_4[5]) = *(undefined8 *)(iVar23 + iStack_1a0);
        *(undefined1 **)(param_4[5] + 8 + iVar23) = puVar25;
        uStack_1e0._4_4_ = (double **)0x0;
        uStack_1e0._0_4_ = (char *)0x100d0882;
        puVar25 = (undefined1 *)FUN_1009f070();
        uVar9 = (undefined1)uStack_1c4;
        *puVar25 = 0x1c;
        puVar25[1] = (undefined1)uStack_1c4;
        *(undefined8 *)(param_4[5] + iVar11) = *(undefined8 *)((int)pdStack_1c0 + iVar11);
        *(undefined1 **)(param_4[5] + 8 + iVar11) = puVar25;
        uStack_1e0._4_4_ = (double **)0x0;
        uStack_1e0._0_4_ = (char *)0x100d08ae;
        puVar25 = (undefined1 *)FUN_1009f070();
        *puVar25 = 0x1c;
        puVar25[1] = uVar9;
        *(undefined8 *)(iVar31 + param_4[5]) = *(undefined8 *)(iVar31 + (int)pdStack_1c0);
        *(undefined1 **)(iVar31 + 8 + param_4[5]) = puVar25;
        pdVar30 = pdStack_1b4;
        piVar13 = (int *)0x1;
        iVar15 = iVar31;
      }
      goto LAB_100d08d7;
    }
  }
  pdVar30 = pdStack_1b4;
  piVar13 = (int *)0x1;
  iVar15 = iVar31;
LAB_100d08d7:
  pdStack_1b4 = (double *)((int)pdStack_1b4 + 1);
  iVar31 = iVar31 + 0xc;
  pdVar12 = pdVar30;
  iVar11 = iVar15;
  if ((int)pdStack_19c <= (int)pdStack_1b4) goto LAB_100d08eb;
  goto LAB_100d05e1;
}


