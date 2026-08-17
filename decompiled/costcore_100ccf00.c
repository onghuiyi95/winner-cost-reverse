//==== FUN_100ccf00 @ 0x100ccf00 lines=836 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

double * FUN_100ccf00(double *param_1,int param_2,undefined4 param_3,int param_4)

{
  uint *puVar1;
  double dVar2;
  int iVar3;
  double *pdVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  int *piVar8;
  undefined4 *puVar9;
  uint uVar10;
  int iVar11;
  double *pdVar12;
  undefined1 *puVar13;
  byte bVar14;
  int iVar15;
  void *_Memory;
  undefined1 *puVar16;
  bool bVar17;
  __uint64 _Var18;
  undefined1 *local_240;
  double *local_23c;
  int local_234;
  int local_230;
  int local_22c;
  undefined8 local_228;
  uint *local_21c;
  int local_218;
  uchar *local_214;
  undefined1 *local_210;
  void *local_208;
  undefined4 local_204;
  undefined4 local_200;
  CFile aCStack_1fc [16];
  int iStack_1ec;
  void *pvStack_1e4;
  int iStack_1e0;
  int aiStack_1dc [113];
  void *pvStack_18;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_101490ad;
  local_14 = ExceptionList;
  local_210 = (undefined1 *)0x0;
  ExceptionList = &local_14;
  iVar3 = FUN_1009e2d0(param_2);
  if ((((iVar3 == 0) || (iVar3 = FUN_1009e2d0(param_2), *(int *)(iVar3 + 0x68) < 1)) ||
      (param_2 == 0)) || (iVar3 = FUN_1009e2d0(param_2), iVar3 == 0)) {
    dVar2 = (double)DAT_1019167c;
    *(undefined4 *)(param_1 + 1) = 0;
    *param_1 = dVar2;
    ExceptionList = local_14;
    return param_1;
  }
  iVar3 = FUN_1009e2d0(param_2);
  local_230 = *(int *)(iVar3 + 0x68);
  local_210 = &stack0xfffffda4;
  FUN_1008ff70(local_230);
  FUN_1007c8f0();
  FUN_10007600();
  local_c = 0;
  iVar3 = __mbsicmp(local_214,(uchar *)"1A0001");
  if (iVar3 != 0) {
    dVar2 = (double)DAT_1019167c;
    *(undefined4 *)(param_1 + 1) = 0;
    *param_1 = dVar2;
    FUN_100014b0();
    ExceptionList = local_14;
    return param_1;
  }
  pdVar4 = (double *)FUN_100b23c0();
  local_22c = FUN_100b23c0();
  iVar3 = FUN_100b23c0();
  aiStack_1dc[0x12] = 0x2b6;
  aiStack_1dc[0x1b] = 0x2b6;
  aiStack_1dc[0x22] = 0xb55;
  aiStack_1dc[0x2b] = 0xb55;
  aiStack_1dc[1] = 0;
  aiStack_1dc[2] = 0x1f;
  aiStack_1dc[3] = 0x3b;
  aiStack_1dc[4] = 0x5a;
  aiStack_1dc[5] = 0x78;
  aiStack_1dc[6] = 0x97;
  aiStack_1dc[7] = 0xb5;
  aiStack_1dc[8] = 0xd4;
  aiStack_1dc[9] = 0xf3;
  aiStack_1dc[10] = 0x111;
  aiStack_1dc[0xb] = 0x130;
  aiStack_1dc[0xc] = 0x14e;
  aiStack_1dc[0xd] = 0xa4b;
  aiStack_1dc[0xe] = 0x5164b;
  aiStack_1dc[0xf] = 0x6a5;
  aiStack_1dc[0x10] = 0x6d4;
  aiStack_1dc[0x11] = 0x415b5;
  aiStack_1dc[0x13] = 0x957;
  aiStack_1dc[0x14] = 0x2092f;
  aiStack_1dc[0x15] = 0x497;
  aiStack_1dc[0x16] = 0x60c96;
  aiStack_1dc[0x17] = 0xd4a;
  aiStack_1dc[0x18] = 0xea5;
  aiStack_1dc[0x19] = 0x50da9;
  aiStack_1dc[0x1a] = 0x5ad;
  aiStack_1dc[0x1c] = 0x3126e;
  aiStack_1dc[0x1d] = 0x92e;
  aiStack_1dc[0x1e] = 0x7192d;
  aiStack_1dc[0x1f] = 0xc95;
  aiStack_1dc[0x20] = 0xd4a;
  aiStack_1dc[0x21] = 0x61b4a;
  aiStack_1dc[0x23] = 0x56a;
  aiStack_1dc[0x24] = 0x4155b;
  aiStack_1dc[0x25] = 0x25d;
  aiStack_1dc[0x26] = 0x92d;
  aiStack_1dc[0x27] = 0x2192b;
  aiStack_1dc[0x28] = 0xa95;
  aiStack_1dc[0x29] = 0x71695;
  aiStack_1dc[0x2a] = 0x6ca;
  aiStack_1dc[0x2c] = 0x50ab5;
  aiStack_1dc[0x2d] = 0x4da;
  aiStack_1dc[0x2e] = 0xa5b;
  aiStack_1dc[0x2f] = 0x30a57;
  aiStack_1dc[0x30] = 0x52b;
  aiStack_1dc[0x31] = 0x8152a;
  aiStack_1dc[0x32] = 0xe95;
  aiStack_1dc[0x33] = 0x6aa;
  aiStack_1dc[0x34] = 0x615aa;
  aiStack_1dc[0x35] = 0xab5;
  aiStack_1dc[0x36] = 0x4b6;
  aiStack_1dc[0x37] = 0x414ae;
  aiStack_1dc[0x38] = 0xa57;
  aiStack_1dc[0x39] = 0x526;
  aiStack_1dc[0x3a] = 0x31d26;
  aiStack_1dc[0x3b] = 0xd95;
  aiStack_1dc[0x3c] = 0x70b55;
  aiStack_1dc[0x3d] = 0x56a;
  aiStack_1dc[0x3e] = 0x96d;
  aiStack_1dc[0x4e] = 0x6d4;
  aiStack_1dc[0x3f] = 0x5095d;
  aiStack_1dc[0x40] = 0x4ad;
  aiStack_1dc[0x41] = 0xa4d;
  aiStack_1dc[0x42] = 0x41a4d;
  aiStack_1dc[0x43] = 0xd25;
  aiStack_1dc[0x44] = 0x81aa5;
  aiStack_1dc[0x45] = 0xb54;
  aiStack_1dc[0x46] = 0xb6a;
  aiStack_1dc[0x47] = 0x612da;
  aiStack_1dc[0x48] = 0x95b;
  aiStack_1dc[0x49] = 0x49b;
  aiStack_1dc[0x4a] = 0x41497;
  aiStack_1dc[0x4b] = 0xa4b;
  aiStack_1dc[0x4c] = 0xa164b;
  aiStack_1dc[0x4d] = 0x6a5;
  aiStack_1dc[0x4f] = 0x615b4;
  aiStack_1dc[0x50] = 0xab6;
  aiStack_1dc[0x51] = 0x957;
  aiStack_1dc[0x52] = 0x5092f;
  aiStack_1dc[0x53] = 0x497;
  aiStack_1dc[0x54] = 0x64b;
  aiStack_1dc[0x55] = 0x30d4a;
  aiStack_1dc[0x56] = 0xea5;
  aiStack_1dc[0x57] = 0x80d65;
  aiStack_1dc[0x58] = 0x5ac;
  aiStack_1dc[0x59] = 0xab6;
  aiStack_1dc[0x5a] = 0x5126d;
  aiStack_1dc[0x5b] = 0x92e;
  aiStack_1dc[0x5c] = 0xc96;
  aiStack_1dc[0x5d] = 0x41a95;
  aiStack_1dc[0x5e] = 0xd4a;
  aiStack_1dc[0x5f] = 0xda5;
  aiStack_1dc[0x60] = 0x20b55;
  aiStack_1dc[0x61] = 0x56a;
  aiStack_1dc[0x62] = 0x7155b;
  aiStack_1dc[99] = 0x25d;
  aiStack_1dc[100] = 0x92d;
  aiStack_1dc[0x65] = 0x5192b;
  aiStack_1dc[0x66] = 0xa95;
  aiStack_1dc[0x67] = 0xb4a;
  aiStack_1dc[0x68] = 0x416aa;
  aiStack_1dc[0x69] = 0xad5;
  aiStack_1dc[0x6a] = 0x90ab5;
  aiStack_1dc[0x6b] = 0x4ba;
  aiStack_1dc[0x6c] = 0xa5b;
  aiStack_1dc[0x6d] = 0x60a57;
  aiStack_1dc[0x6e] = 0x52b;
  aiStack_1dc[0x6f] = 0xa93;
  aiStack_1dc[0x70] = 0x40e95;
  local_218 = 0;
  local_208 = (void *)0x0;
  local_204 = 0;
  local_200 = 0;
  local_c = CONCAT31(local_c._1_3_,1);
  FUN_100ca460();
  FUN_1009e2d0(param_2,param_3);
  iVar5 = FUN_100b21e0();
  if (iVar5 == 0) goto LAB_100ce4be;
  local_234 = 0;
  if (0 < local_230) {
    local_228 = (double)CONCAT44(local_228._4_4_,(int)pdVar4 + -0xc);
LAB_100cd562:
    iVar5 = FUN_100dd8dc();
    uVar6 = iVar5 / 10000;
    iVar11 = (iVar5 % 10000) / 100;
    uVar10 = uVar6 & 0x80000003;
    bVar17 = uVar10 == 0;
    iVar5 = aiStack_1dc[iVar11] +
            ((int)((uVar6 - 0x781) + ((int)(uVar6 - 0x781) >> 0x1f & 3U)) >> 2) + uVar6 * 0x16d +
            -0xab313 + iVar5 % 100;
    if ((int)uVar10 < 0) {
      bVar17 = (uVar10 - 1 | 0xfffffffc) == 0xffffffff;
    }
    if ((bVar17) && (2 < iVar11)) {
      iVar5 = iVar5 + 1;
    }
    local_21c = (uint *)(aiStack_1dc + 0xd);
    do {
      uVar6 = *local_21c;
      iVar11 = (0xffe < (int)uVar6) + 0xc;
      do {
        uVar10 = uVar6;
        if (1 < iVar11) {
          iVar15 = iVar11 + -1;
          do {
            uVar10 = (int)uVar10 / 2;
            iVar15 = iVar15 + -1;
          } while (iVar15 != 0);
        }
        uVar10 = uVar10 & 0x80000001;
        if ((int)uVar10 < 0) {
          uVar10 = (uVar10 - 1 | 0xfffffffe) + 1;
        }
        if (iVar5 <= (int)(uVar10 + 0x1d)) {
          if ((local_218 == 0x1e) || (local_218 == 0x1d)) {
            if ((iVar5 < local_218) && ((local_218 == 0x1d || (local_218 == 0x1e)))) {
              uVar7 = FUN_100dd8dc();
              *(undefined4 *)((int)local_208 + local_234 * 4 + -4) = uVar7;
            }
LAB_100cd68f:
            *(undefined4 *)((int)local_208 + local_234 * 4) = 0;
          }
          else {
            if (local_218 <= iVar5) goto LAB_100cd68f;
            uVar7 = FUN_100dd8dc();
            *(undefined4 *)((int)local_208 + local_234 * 4 + -4) = uVar7;
          }
          local_234 = local_234 + 1;
          local_228 = (double)CONCAT44(local_228._4_4_,(uint)local_228 + 0xc);
          local_218 = iVar5;
          if (local_230 <= local_234) goto LAB_100cd6ba;
          goto LAB_100cd562;
        }
        iVar5 = iVar5 + (-0x1d - uVar10);
        iVar15 = iVar11 + -2;
        iVar11 = iVar11 + -1;
      } while (-1 < iVar15);
      local_21c = local_21c + 1;
    } while( true );
  }
LAB_100cd6ba:
  local_234 = 0x133f073;
  *(uint *)(param_4 + 0x10) = *(uint *)(param_4 + 0x10) | 0x100;
  piVar8 = (int *)FUN_101129b5();
  puVar9 = (undefined4 *)(**(code **)(*piVar8 + 0xc))();
  local_c._0_1_ = 2;
  local_218 = 0;
  local_210 = (undefined1 *)0xffffffff;
  uVar7 = FUN_100761a0();
  local_c._0_1_ = 3;
  FUN_100021c0(&local_21c,uVar7,"\\skbjTemp.dat");
  local_c._0_1_ = 5;
  piVar8 = (int *)(iStack_1ec + -4);
  LOCK();
  iVar5 = *piVar8;
  *piVar8 = *piVar8 + -1;
  UNLOCK();
  if (iVar5 == 1 || iVar5 + -1 < 0) {
    (**(code **)(**(int **)(iStack_1ec + -0x10) + 4))();
  }
  CFile::CFile(aCStack_1fc);
  local_c._0_1_ = 6;
  iVar5 = CFile::Open(aCStack_1fc,(char *)local_21c,0x8000,(CFileException *)0x0);
  if (iVar5 != 0) {
    _Memory = (void *)0x0;
    pvStack_1e4 = (void *)0x0;
    iStack_1e0 = 0;
    aiStack_1dc[0] = 0;
    local_c = CONCAT31(local_c._1_3_,7);
    _Var18 = CFile::GetLength(aCStack_1fc);
    local_228 = (double)CONCAT44(local_228._4_4_,(int)_Var18);
    iVar5 = 0;
    if (((_Var18 & 3) == 0) && (0 < (int)_Var18)) {
      FUN_100ca460();
      _Memory = pvStack_1e4;
      CFile::Read(aCStack_1fc,pvStack_1e4,(uint)local_228);
      iVar5 = iStack_1e0;
    }
    CFile::Close(aCStack_1fc);
    for (uVar6 = 0; (_Memory != (void *)0x0 && (uVar6 < (uint)(iVar5 - (int)_Memory >> 2)));
        uVar6 = uVar6 + 1) {
      iVar11 = *(int *)((int)_Memory + uVar6 * 4);
      if (0x133f073 < iVar11) {
        local_234 = iVar11;
      }
    }
    local_c._0_1_ = 6;
    if (_Memory != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
      _free(_Memory);
    }
  }
  iVar11 = local_230;
  iVar5 = 0;
  local_228 = (double)((ulonglong)local_228 & 0xffffffff00000000);
  if (3 < local_230) {
    local_23c = pdVar4 + 3;
    piVar8 = (int *)((int)local_208 + 8);
    iVar15 = (local_230 - 4U >> 2) + 1;
    iVar5 = iVar15 * 4;
    do {
      if (((double)local_234 < local_23c[-3]) && (0 < piVar8[-2])) {
        uVar6 = (uint)local_228 + 1;
        local_228 = (double)CONCAT44(local_228._4_4_,uVar6);
        uVar6 = uVar6 & 0x80000003;
        bVar17 = uVar6 == 0;
        if ((int)uVar6 < 0) {
          bVar17 = (uVar6 - 1 | 0xfffffffc) == 0xffffffff;
        }
        if (bVar17) {
          local_234 = piVar8[-2];
        }
      }
      if (((double)local_234 < *(double *)((int)local_23c + -0xc)) && (0 < piVar8[-1])) {
        uVar6 = (uint)local_228 + 1;
        local_228 = (double)CONCAT44(local_228._4_4_,uVar6);
        uVar6 = uVar6 & 0x80000003;
        bVar17 = uVar6 == 0;
        if ((int)uVar6 < 0) {
          bVar17 = (uVar6 - 1 | 0xfffffffc) == 0xffffffff;
        }
        if (bVar17) {
          local_234 = piVar8[-1];
        }
      }
      if (((double)local_234 < *local_23c) && (0 < *piVar8)) {
        uVar6 = (uint)local_228 + 1;
        local_228 = (double)CONCAT44(local_228._4_4_,uVar6);
        uVar6 = uVar6 & 0x80000003;
        bVar17 = uVar6 == 0;
        if ((int)uVar6 < 0) {
          bVar17 = (uVar6 - 1 | 0xfffffffc) == 0xffffffff;
        }
        if (bVar17) {
          local_234 = *piVar8;
        }
      }
      if (((double)local_234 < *(double *)((int)local_23c + 0xc)) && (0 < piVar8[1])) {
        uVar6 = (uint)local_228 + 1;
        local_228 = (double)CONCAT44(local_228._4_4_,uVar6);
        uVar6 = uVar6 & 0x80000003;
        bVar17 = uVar6 == 0;
        if ((int)uVar6 < 0) {
          bVar17 = (uVar6 - 1 | 0xfffffffc) == 0xffffffff;
        }
        if (bVar17) {
          local_234 = piVar8[1];
        }
      }
      local_23c = local_23c + 6;
      piVar8 = piVar8 + 4;
      iVar15 = iVar15 + -1;
    } while (iVar15 != 0);
  }
  if (iVar5 < local_230) {
    pdVar12 = (double *)((int)pdVar4 + iVar5 * 0xc);
    do {
      if (((double)local_234 < *pdVar12) &&
         (iVar15 = *(int *)((int)local_208 + iVar5 * 4), 0 < iVar15)) {
        uVar6 = (uint)local_228 + 1;
        local_228 = (double)CONCAT44(local_228._4_4_,uVar6);
        uVar6 = uVar6 & 0x80000003;
        bVar17 = uVar6 == 0;
        if ((int)uVar6 < 0) {
          bVar17 = (uVar6 - 1 | 0xfffffffc) == 0xffffffff;
        }
        if (bVar17) {
          local_234 = iVar15;
        }
      }
      iVar5 = iVar5 + 1;
      pdVar12 = (double *)((int)pdVar12 + 0xc);
    } while (iVar5 < local_230);
  }
  iVar5 = CFile::Open(aCStack_1fc,(char *)local_21c,0x9001,(CFileException *)0x0);
  if (iVar5 != 0) {
    CFile::Write(aCStack_1fc,&local_234,4);
    CFile::Close(aCStack_1fc);
  }
  iVar5 = 0;
  if (0 < iVar11) {
    local_228 = (double)local_234;
    do {
      if (*pdVar4 == local_228) {
        if (-1 < iVar5) {
          uVar6 = 0;
          puVar13 = (undefined1 *)(iVar5 + -1);
          puVar16 = local_210;
          if (-1 < (int)puVar13) goto LAB_100cd9f5;
          goto LAB_100cda0a;
        }
        break;
      }
      iVar5 = iVar5 + 1;
      pdVar4 = (double *)((int)pdVar4 + 0xc);
    } while (iVar5 < iVar11);
  }
  goto LAB_100ce461;
LAB_100cd9f5:
  do {
    if (0 < *(int *)((int)local_208 + (int)puVar13 * 4)) {
      uVar6 = uVar6 + 1;
      puVar16 = puVar13;
    }
    puVar13 = puVar13 + -1;
  } while (-1 < (int)puVar13);
  if (puVar16 == (undefined1 *)0xffffffff) {
LAB_100cda0a:
    dVar2 = (double)DAT_1019167c;
    *(undefined4 *)(param_1 + 1) = 0;
    *param_1 = dVar2;
    local_c._0_1_ = 5;
    CFile::~CFile(aCStack_1fc);
    local_c = CONCAT31(local_c._1_3_,2);
    puVar1 = local_21c + -1;
    LOCK();
    uVar6 = *puVar1;
    *puVar1 = *puVar1 - 1;
    UNLOCK();
    if ((int)(uVar6 - 1) < 1) {
      (**(code **)(*(int *)local_21c[-4] + 4))();
    }
    local_c = CONCAT31(local_c._1_3_,1);
    piVar8 = puVar9 + 3;
    LOCK();
    iVar3 = *piVar8;
    *piVar8 = *piVar8 + -1;
    UNLOCK();
    if (iVar3 + -1 < 1) {
      (**(code **)(*(int *)*puVar9 + 4))();
    }
    if (local_208 == (void *)0x0) {
      local_c = 0xffffffff;
      piVar8 = (int *)(local_214 + -4);
      LOCK();
      iVar3 = *piVar8;
      *piVar8 = *piVar8 + -1;
      UNLOCK();
      if (iVar3 != 1 && -1 < iVar3 + -1) {
        ExceptionList = local_14;
        return param_1;
      }
      (**(code **)(**(int **)(local_214 + -0x10) + 4))();
      ExceptionList = pvStack_18;
      return param_1;
    }
                    /* WARNING: Subroutine does not return */
    _free(local_208);
  }
  uVar6 = uVar6 & 0x80000003;
  if ((int)uVar6 < 0) {
    uVar6 = (uVar6 - 1 | 0xfffffffc) + 1;
  }
  uVar6 = 4 - uVar6;
  puVar16 = puVar16 + 1;
  local_228._4_4_ = (undefined4)((ulonglong)local_228 >> 0x20);
  local_228 = (double)CONCAT44(local_228._4_4_,uVar6);
  if ((int)puVar16 < iVar11) {
    do {
      local_218 = local_218 + 1;
      if (0 < *(int *)((int)local_208 + (int)puVar16 * 4)) {
        uVar6 = uVar6 + 1;
        local_228 = (double)CONCAT44(local_228._4_4_,uVar6);
        local_218 = 0;
      }
      uVar6 = uVar6 & 0x80000003;
      if ((int)uVar6 < 0) {
        uVar6 = (uVar6 - 1 | 0xfffffffc) + 1;
      }
      if (uVar6 == 0) {
        if (local_218 == 6) {
          FUN_10001d30();
          iVar5 = (int)puVar16 * 0xc;
          local_240 = (undefined1 *)FUN_1009f070();
          *local_240 = 0x1f;
          local_240[1] = 0;
          if (((int)(puVar16 + -2) < 0) || (local_230 <= (int)(puVar16 + 2))) goto LAB_100ce41a;
          bVar14 = *(double *)(iVar3 + -0xc + (int)puVar16 * 0xc) < *(double *)(iVar5 + iVar3);
          iVar11 = (int)puVar16 * 3 + 3;
          if (*(double *)(iVar3 + iVar11 * 4) < *(double *)(iVar5 + iVar3)) {
            bVar14 = bVar14 + 1;
          }
          if (*(double *)(iVar3 + (int)puVar16 * 0xc + -0x18) < *(double *)(iVar5 + iVar3)) {
            bVar14 = bVar14 + 1;
          }
          if (*(double *)(iVar3 + iVar11 * 4 + 0xc) < *(double *)(iVar5 + iVar3)) {
            bVar14 = bVar14 + 1;
          }
LAB_100ce3f6:
          if (bVar14 < 3) goto LAB_100ce41a;
          local_240[1] = 1;
          *(undefined8 *)((int)puVar16 * 0xc + *(int *)(param_4 + 0x14)) =
               *(undefined8 *)((int)puVar16 * 0xc + iVar3);
        }
        else {
          if (local_218 != 0xe) goto LAB_100ce454;
          FUN_10001d30();
          iVar5 = (int)puVar16 * 0xc;
          local_240 = (undefined1 *)FUN_1009f070();
          *local_240 = 0x1f;
          local_240[1] = 0;
          if ((-1 < (int)(puVar16 + -2)) && ((int)(puVar16 + 2) < local_230)) {
            bVar14 = *(double *)(iVar3 + -0xc + (int)puVar16 * 0xc) < *(double *)(iVar5 + iVar3);
            iVar11 = (int)puVar16 * 3 + 3;
            if (*(double *)(iVar3 + iVar11 * 4) < *(double *)(iVar5 + iVar3)) {
              bVar14 = bVar14 + 1;
            }
            if (*(double *)(iVar3 + (int)puVar16 * 0xc + -0x18) < *(double *)(iVar5 + iVar3)) {
              bVar14 = bVar14 + 1;
            }
            if (*(double *)(iVar3 + iVar11 * 4 + 0xc) < *(double *)(iVar5 + iVar3)) {
              bVar14 = bVar14 + 1;
            }
            if (2 < bVar14) {
              local_240[1] = 1;
              *(undefined8 *)(iVar5 + *(int *)(param_4 + 0x14)) = *(undefined8 *)(iVar5 + iVar3);
              goto LAB_100ce42a;
            }
          }
LAB_100ce41a:
          *(undefined8 *)((int)puVar16 * 0xc + *(int *)(param_4 + 0x14)) =
               *(undefined8 *)((int)puVar16 * 0xc + local_22c);
        }
LAB_100ce42a:
        if (DAT_101961ac != (code *)0x0) {
          uVar7 = (*DAT_101961ac)();
          *(undefined4 *)(local_240 + 0xc) = uVar7;
        }
        *(undefined1 **)((int)puVar16 * 0xc + 8 + *(int *)(param_4 + 0x14)) = local_240;
      }
      else {
        if (uVar6 == 1) {
          if (local_218 == 0) {
            FUN_10001d30();
            iVar5 = (int)puVar16 * 0xc;
            local_240 = (undefined1 *)FUN_1009f070();
            *local_240 = 0x1f;
            local_240[1] = 0;
            if ((-1 < (int)(puVar16 + -2)) && ((int)(puVar16 + 2) < local_230)) {
              bVar14 = *(double *)(iVar3 + -0xc + (int)puVar16 * 0xc) < *(double *)(iVar5 + iVar3);
              iVar11 = (int)puVar16 * 3 + 3;
              if (*(double *)(iVar3 + iVar11 * 4) < *(double *)(iVar5 + iVar3)) {
                bVar14 = bVar14 + 1;
              }
              if (*(double *)(iVar3 + (int)puVar16 * 0xc + -0x18) < *(double *)(iVar5 + iVar3)) {
                bVar14 = bVar14 + 1;
              }
              if (*(double *)(iVar3 + iVar11 * 4 + 0xc) < *(double *)(iVar5 + iVar3)) {
                bVar14 = bVar14 + 1;
              }
              if (2 < bVar14) {
                local_240[1] = 1;
                *(undefined8 *)(iVar5 + *(int *)(param_4 + 0x14)) = *(undefined8 *)(iVar5 + iVar3);
                goto LAB_100ce42a;
              }
            }
          }
          else if (local_218 == 8) {
            FUN_10001d30();
            iVar5 = (int)puVar16 * 0xc;
            local_240 = (undefined1 *)FUN_1009f070();
            *local_240 = 0x1f;
            local_240[1] = 0;
            if ((-1 < (int)(puVar16 + -2)) && ((int)(puVar16 + 2) < local_230)) {
              bVar14 = *(double *)(iVar3 + -0xc + (int)puVar16 * 0xc) < *(double *)(iVar5 + iVar3);
              iVar11 = (int)puVar16 * 3 + 3;
              if (*(double *)(iVar3 + iVar11 * 4) < *(double *)(iVar5 + iVar3)) {
                bVar14 = bVar14 + 1;
              }
              if (*(double *)(iVar3 + (int)puVar16 * 0xc + -0x18) < *(double *)(iVar5 + iVar3)) {
                bVar14 = bVar14 + 1;
              }
              if (*(double *)(iVar3 + iVar11 * 4 + 0xc) < *(double *)(iVar5 + iVar3)) {
                bVar14 = bVar14 + 1;
              }
              if (2 < bVar14) {
                local_240[1] = 1;
                *(undefined8 *)(iVar5 + *(int *)(param_4 + 0x14)) = *(undefined8 *)(iVar5 + iVar3);
                goto LAB_100ce42a;
              }
            }
          }
          else if (local_218 == 0xb) {
            FUN_10001d30();
            iVar5 = (int)puVar16 * 0xc;
            local_240 = (undefined1 *)FUN_1009f070();
            *local_240 = 0x1f;
            local_240[1] = 0;
            if ((-1 < (int)(puVar16 + -2)) && ((int)(puVar16 + 2) < local_230)) {
              bVar14 = *(double *)(iVar3 + -0xc + (int)puVar16 * 0xc) < *(double *)(iVar5 + iVar3);
              iVar11 = (int)puVar16 * 3 + 3;
              if (*(double *)(iVar3 + iVar11 * 4) < *(double *)(iVar5 + iVar3)) {
                bVar14 = bVar14 + 1;
              }
              if (*(double *)(iVar3 + (int)puVar16 * 0xc + -0x18) < *(double *)(iVar5 + iVar3)) {
                bVar14 = bVar14 + 1;
              }
              if (*(double *)(iVar3 + iVar11 * 4 + 0xc) < *(double *)(iVar5 + iVar3)) {
                bVar14 = bVar14 + 1;
              }
              if (2 < bVar14) {
                local_240[1] = 1;
                *(undefined8 *)(iVar5 + *(int *)(param_4 + 0x14)) = *(undefined8 *)(iVar5 + iVar3);
                goto LAB_100ce42a;
              }
            }
          }
          else {
            if (local_218 != 0xf) goto LAB_100ce454;
            FUN_10001d30();
            iVar5 = (int)puVar16 * 0xc;
            local_240 = (undefined1 *)FUN_1009f070();
            *local_240 = 0x1f;
            local_240[1] = 0;
            if ((-1 < (int)(puVar16 + -2)) && ((int)(puVar16 + 2) < local_230)) {
              bVar14 = *(double *)(iVar3 + -0xc + (int)puVar16 * 0xc) < *(double *)(iVar5 + iVar3);
              iVar11 = (int)puVar16 * 3 + 3;
              if (*(double *)(iVar3 + iVar11 * 4) < *(double *)(iVar5 + iVar3)) {
                bVar14 = bVar14 + 1;
              }
              if (*(double *)(iVar3 + (int)puVar16 * 0xc + -0x18) < *(double *)(iVar5 + iVar3)) {
                bVar14 = bVar14 + 1;
              }
              if (*(double *)(iVar3 + iVar11 * 4 + 0xc) < *(double *)(iVar5 + iVar3)) {
                bVar14 = bVar14 + 1;
              }
              if (2 < bVar14) {
                local_240[1] = 1;
                *(undefined8 *)(iVar5 + *(int *)(param_4 + 0x14)) = *(undefined8 *)(iVar5 + iVar3);
                goto LAB_100ce42a;
              }
            }
          }
          goto LAB_100ce41a;
        }
        if (uVar6 == 2) {
          if (local_218 == 4) {
            FUN_10001d30();
            iVar5 = (int)puVar16 * 0xc;
            local_240 = (undefined1 *)FUN_1009f070();
            *local_240 = 0x1f;
            local_240[1] = 0;
            if ((-1 < (int)(puVar16 + -2)) && ((int)(puVar16 + 2) < local_230)) {
              bVar14 = *(double *)(iVar3 + -0xc + (int)puVar16 * 0xc) < *(double *)(iVar5 + iVar3);
              iVar11 = (int)puVar16 * 3 + 3;
              if (*(double *)(iVar3 + iVar11 * 4) < *(double *)(iVar5 + iVar3)) {
                bVar14 = bVar14 + 1;
              }
              if (*(double *)(iVar3 + (int)puVar16 * 0xc + -0x18) < *(double *)(iVar5 + iVar3)) {
                bVar14 = bVar14 + 1;
              }
              if (*(double *)(iVar3 + iVar11 * 4 + 0xc) < *(double *)(iVar5 + iVar3)) {
                bVar14 = bVar14 + 1;
              }
              if (2 < bVar14) {
                local_240[1] = 1;
                *(undefined8 *)(iVar5 + *(int *)(param_4 + 0x14)) = *(undefined8 *)(iVar5 + iVar3);
                goto LAB_100ce42a;
              }
            }
          }
          else if (local_218 == 8) {
            FUN_10001d30();
            iVar5 = (int)puVar16 * 0xc;
            local_240 = (undefined1 *)FUN_1009f070();
            *local_240 = 0x1f;
            local_240[1] = 0;
            if ((-1 < (int)(puVar16 + -2)) && ((int)(puVar16 + 2) < local_230)) {
              bVar14 = *(double *)(iVar3 + -0xc + (int)puVar16 * 0xc) < *(double *)(iVar5 + iVar3);
              iVar11 = (int)puVar16 * 3 + 3;
              if (*(double *)(iVar3 + iVar11 * 4) < *(double *)(iVar5 + iVar3)) {
                bVar14 = bVar14 + 1;
              }
              if (*(double *)(iVar3 + (int)puVar16 * 0xc + -0x18) < *(double *)(iVar5 + iVar3)) {
                bVar14 = bVar14 + 1;
              }
              if (*(double *)(iVar3 + iVar11 * 4 + 0xc) < *(double *)(iVar5 + iVar3)) {
                bVar14 = bVar14 + 1;
              }
              if (2 < bVar14) {
                local_240[1] = 1;
                *(undefined8 *)(iVar5 + *(int *)(param_4 + 0x14)) = *(undefined8 *)(iVar5 + iVar3);
                goto LAB_100ce42a;
              }
            }
          }
          else {
            if (local_218 != 0xf) goto LAB_100ce454;
            FUN_10001d30();
            iVar5 = (int)puVar16 * 0xc;
            local_240 = (undefined1 *)FUN_1009f070();
            *local_240 = 0x1f;
            local_240[1] = 0;
            if ((-1 < (int)(puVar16 + -2)) && ((int)(puVar16 + 2) < local_230)) {
              bVar14 = *(double *)(iVar3 + -0xc + (int)puVar16 * 0xc) < *(double *)(iVar5 + iVar3);
              iVar11 = (int)puVar16 * 3 + 3;
              if (*(double *)(iVar3 + iVar11 * 4) < *(double *)(iVar5 + iVar3)) {
                bVar14 = bVar14 + 1;
              }
              if (*(double *)(iVar3 + (int)puVar16 * 0xc + -0x18) < *(double *)(iVar5 + iVar3)) {
                bVar14 = bVar14 + 1;
              }
              if (*(double *)(iVar3 + iVar11 * 4 + 0xc) < *(double *)(iVar5 + iVar3)) {
                bVar14 = bVar14 + 1;
              }
              if (2 < bVar14) {
                local_240[1] = 1;
                *(undefined8 *)(iVar5 + *(int *)(param_4 + 0x14)) = *(undefined8 *)(iVar5 + iVar3);
                goto LAB_100ce42a;
              }
            }
          }
          goto LAB_100ce41a;
        }
        if (uVar6 == 3) {
          if (local_218 == 6) {
            FUN_10001d30();
            iVar5 = (int)puVar16 * 0xc;
            local_240 = (undefined1 *)FUN_1009f070();
            *local_240 = 0x1f;
            local_240[1] = 0;
            if ((-1 < (int)(puVar16 + -2)) && ((int)(puVar16 + 2) < local_230)) {
              bVar14 = *(double *)(iVar3 + -0xc + (int)puVar16 * 0xc) < *(double *)(iVar5 + iVar3);
              iVar11 = (int)puVar16 * 3 + 3;
              if (*(double *)(iVar3 + iVar11 * 4) < *(double *)(iVar5 + iVar3)) {
                bVar14 = bVar14 + 1;
              }
              if (*(double *)(iVar3 + (int)puVar16 * 0xc + -0x18) < *(double *)(iVar5 + iVar3)) {
                bVar14 = bVar14 + 1;
              }
              if (*(double *)(iVar3 + iVar11 * 4 + 0xc) < *(double *)(iVar5 + iVar3)) {
                bVar14 = bVar14 + 1;
              }
              if (2 < bVar14) {
                local_240[1] = 1;
                *(undefined8 *)(iVar5 + *(int *)(param_4 + 0x14)) = *(undefined8 *)(iVar5 + iVar3);
                goto LAB_100ce42a;
              }
            }
          }
          else {
            if ((local_218 != 10) && (local_218 != 0x10)) goto LAB_100ce454;
            FUN_10001d30();
            iVar5 = (int)puVar16 * 0xc;
            local_240 = (undefined1 *)FUN_1009f070();
            *local_240 = 0x1f;
            local_240[1] = 0;
            if ((-1 < (int)(puVar16 + -2)) && ((int)(puVar16 + 2) < local_230)) {
              bVar14 = *(double *)(iVar3 + -0xc + (int)puVar16 * 0xc) < *(double *)(iVar5 + iVar3);
              iVar11 = (int)puVar16 * 3 + 3;
              if (*(double *)(iVar3 + iVar11 * 4) < *(double *)(iVar5 + iVar3)) {
                bVar14 = bVar14 + 1;
              }
              if (*(double *)(iVar3 + (int)puVar16 * 0xc + -0x18) < *(double *)(iVar5 + iVar3)) {
                bVar14 = bVar14 + 1;
              }
              if (*(double *)(iVar3 + iVar11 * 4 + 0xc) < *(double *)(iVar5 + iVar3)) {
                bVar14 = bVar14 + 1;
              }
              goto LAB_100ce3f6;
            }
          }
          goto LAB_100ce41a;
        }
      }
LAB_100ce454:
      puVar16 = puVar16 + 1;
      if (local_230 <= (int)puVar16) break;
      uVar6 = (uint)local_228;
    } while( true );
  }
LAB_100ce461:
  local_c._0_1_ = 5;
  CFile::~CFile(aCStack_1fc);
  local_c = CONCAT31(local_c._1_3_,2);
  puVar1 = local_21c + -1;
  LOCK();
  uVar6 = *puVar1;
  *puVar1 = *puVar1 - 1;
  UNLOCK();
  if ((int)(uVar6 - 1) < 1) {
    (**(code **)(*(int *)local_21c[-4] + 4))();
  }
  local_c = CONCAT31(local_c._1_3_,1);
  piVar8 = puVar9 + 3;
  LOCK();
  iVar3 = *piVar8;
  *piVar8 = *piVar8 + -1;
  UNLOCK();
  if (iVar3 + -1 < 1) {
    (**(code **)(*(int *)*puVar9 + 4))();
  }
LAB_100ce4be:
  *param_1 = (double)DAT_1019167c;
  *(undefined4 *)(param_1 + 1) = 0;
  if (local_208 == (void *)0x0) {
    local_c = 0xffffffff;
    piVar8 = (int *)(local_214 + -4);
    LOCK();
    iVar3 = *piVar8;
    *piVar8 = *piVar8 + -1;
    UNLOCK();
    if (iVar3 == 1 || iVar3 + -1 < 0) {
      (**(code **)(**(int **)(local_214 + -0x10) + 4))();
    }
    ExceptionList = local_14;
    return param_1;
  }
                    /* WARNING: Subroutine does not return */
  _free(local_208);
}


