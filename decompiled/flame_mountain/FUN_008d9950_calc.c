
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_008d9950(float param_1,undefined1 *param_2,undefined4 param_3,undefined4 param_4,float param_5)

{
  double dVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  double *pdVar5;
  int iVar6;
  int iVar7;
  double *pdVar8;
  uint uVar9;
  int iVar10;
  int *piVar11;
  uint uVar12;
  int iVar13;
  int iVar14;
  float10 extraout_ST0;
  float10 fVar15;
  undefined1 *puVar16;
  undefined4 uVar17;
  undefined1 local_5c [12];
  undefined8 local_50;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  uint *local_20;
  int local_1c;
  uint local_18;
  int local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  *param_2 = 0;
  iVar4 = FUN_008d8df0();
  if ((((param_1 == 0.0) || (local_2c = *(int *)((int)param_1 + 0x4a), local_2c == 0)) ||
      (*(int *)((int)param_1 + 0x46) < 1)) || (iVar4 == 0)) {
    return 0;
  }
  uVar17 = 0x2b8f;
  puVar16 = local_5c;
  local_8 = 0xffffffff;
  FUN_0089fd10(puVar16,0x2b8f);
  pdVar5 = (double *)FUN_009a8960(puVar16,uVar17);
  local_50 = *pdVar5 * _DAT_00efe278;
  FUN_0097bd30();
  iVar4 = 0;
  if (local_50 < 0.0) {
    local_30 = *(int *)(param_2 + 5);
    if (local_30 < 1) {
      return 0;
    }
  }
  else {
    local_30 = (int)param_5;
    if (3 < (int)param_5) {
      iVar10 = (int)param_5 + -2;
      piVar11 = (int *)(local_2c + -0x10 + (int)param_5 * 0x28);
      do {
        if (((local_30 < 0) || (iVar13 = *(int *)((int)param_1 + 0x46), iVar13 <= local_30)) ||
           (local_10 = iVar4 + piVar11[10], local_50 <= (double)local_10)) goto LAB_008d9af9;
        if (((iVar10 + 1 < 0) || (iVar13 <= iVar10 + 1)) ||
           (local_10 = local_10 + *piVar11, local_50 <= (double)local_10)) {
          local_30 = (int)param_5 - (local_30 + -1);
          goto LAB_008d9b13;
        }
        if (((iVar10 < 0) || (iVar13 <= iVar10)) ||
           (local_10 = local_10 + piVar11[-10], local_50 <= (double)local_10)) {
          local_30 = (int)param_5 - (local_30 + -2);
          goto LAB_008d9b13;
        }
        if (((iVar10 + -1 < 0) || (iVar13 <= iVar10 + -1)) ||
           (iVar4 = local_10 + piVar11[-0x14], local_10 = iVar4, local_50 <= (double)iVar4)) {
          local_30 = local_30 + -3;
          goto LAB_008d9af9;
        }
        local_30 = local_30 + -4;
        iVar10 = iVar10 + -4;
        piVar11 = piVar11 + -0x28;
      } while (3 < local_30);
    }
    if (local_30 < 1) {
LAB_008d9af9:
      local_30 = (int)param_5 - local_30;
    }
    else {
      piVar11 = (int *)(local_2c + 0x18 + local_30 * 0x28);
      do {
        if (((local_30 < 0) || (*(int *)((int)param_1 + 0x46) <= local_30)) ||
           (iVar4 = iVar4 + *piVar11, local_10 = iVar4, local_50 <= (double)iVar4))
        goto LAB_008d9af9;
        local_30 = local_30 + -1;
        piVar11 = piVar11 + -10;
      } while (0 < local_30);
      local_30 = (int)param_5 - local_30;
    }
  }
LAB_008d9b13:
  *(undefined8 *)(param_2 + 0x15) = 0x3ff0000000000000;
  local_28 = (int)param_5 - local_30;
  if (local_28 < 0) {
    local_28 = 0;
  }
  iVar4 = local_28;
  FUN_008d6fb0();
  local_48 = (int)param_5;
  if (iVar4 <= (int)param_5) {
    local_20 = (uint *)(local_2c + 0x18 + (int)param_5 * 0x28);
    local_44 = 0;
    iVar4 = (int)param_5;
    do {
      local_48 = iVar4;
      if ((iVar4 < 0) || (*(int *)((int)param_1 + 0x46) <= iVar4)) break;
      local_1c = *(int *)(local_24 + 0x1e6);
      iVar10 = FUN_00bea080();
      local_10 = iVar10;
      local_c = FUN_00bea080();
      if (DAT_0113e240 == 1) {
        local_18 = *local_20;
      }
      else if (DAT_0113e240 == 2) {
        local_18 = (local_c - iVar10) + 1;
        if ((int)local_18 < 2) {
          local_18 = 1;
        }
        local_18 = *local_20 / local_18;
      }
      if ((iVar10 <= local_1c) && (-1 < local_c)) {
        if (iVar10 < 0) {
          local_10 = 0;
        }
        if (local_1c < local_c) {
          local_c = local_1c;
        }
        if ((DAT_01127201 & 0x1000000) != 0) {
          iVar10 = 0;
          if (DAT_0113e2cc == 0) {
            return 0;
          }
          if (0 < (int)DAT_0113e2cc) {
            do {
              if (((iVar10 < (int)(DAT_0113e2cc - 1)) &&
                  ((int)param_5 - (&DAT_0113e280)[iVar10] <= iVar4)) &&
                 (iVar4 <= (int)param_5 - (&DAT_0113e27c)[iVar10])) {
                local_8 = iVar10 + 1;
                break;
              }
              if ((iVar4 <= (int)param_5) && ((int)param_5 - DAT_0113e27c < iVar4)) {
                local_8 = 0;
                break;
              }
              if ((local_28 <= iVar4) &&
                 (iVar4 < (int)param_5 - *(int *)(&DAT_0113e278 + DAT_0113e2cc * 4))) {
                local_8 = DAT_0113e2cc;
                break;
              }
              iVar10 = iVar10 + 1;
            } while (iVar10 < (int)DAT_0113e2cc);
          }
        }
        if ((DAT_01127201 & 0x800000) != 0) {
          local_8 = 4 - local_44 / (local_30 / 5 + 1);
        }
        uVar12 = local_8;
        if ((DAT_01127201 & 0x2000000) != 0) {
          iVar10 = 0;
          if (DAT_0113e2d0 == 0) {
            return 0;
          }
          if (0 < (int)DAT_0113e2d0) {
            while ((((int)(DAT_0113e2d0 - 1) <= iVar10 ||
                    (iVar4 < (int)param_5 - (&DAT_0113e2a8)[iVar10])) ||
                   ((int)param_5 - (&DAT_0113e2a4)[iVar10] < iVar4))) {
              if ((iVar4 <= (int)param_5) && ((int)param_5 - DAT_0113e2a4 < iVar4)) {
                local_8 = 0;
                goto LAB_008d9d6f;
              }
              if (((local_28 <= iVar4) &&
                  (uVar12 = DAT_0113e2d0,
                  iVar4 < (int)param_5 - *(int *)(&DAT_0113e2a0 + DAT_0113e2d0 * 4))) ||
                 (iVar10 = iVar10 + 1, uVar12 = local_8, (int)DAT_0113e2d0 <= iVar10))
              goto LAB_008d9d63;
            }
            uVar12 = iVar10 + 1;
          }
        }
LAB_008d9d63:
        local_8 = uVar12;
        if (10 < local_8) break;
LAB_008d9d6f:
        if (DAT_0113e240 == 1) {
          iVar4 = (local_c + local_10) / 2;
          local_14 = local_10;
          if (local_10 < iVar4) {
            if (3 < iVar4 - local_10) {
              local_40 = local_18 * 0xc;
              local_3c = local_18 * 8;
              iVar13 = local_c - local_10;
              local_38 = local_18 * 4;
              iVar10 = local_18 * 0x10;
              iVar14 = ((iVar4 - local_10) - 4U >> 2) + 1;
              local_14 = local_10 + iVar14 * 4;
              local_34 = 0;
              pdVar5 = (double *)(&DAT_011289b8 + local_8 * 1000 + local_10);
              do {
                iVar6 = local_34 / iVar13;
                local_34 = local_34 + iVar10;
                iVar7 = local_38 / iVar13;
                pdVar5[-1] = (double)(iVar6 / iVar13) + pdVar5[-1];
                local_38 = local_38 + iVar10;
                iVar6 = local_3c / iVar13;
                *pdVar5 = (double)(iVar7 / iVar13) + *pdVar5;
                local_3c = local_3c + iVar10;
                iVar7 = local_40 / iVar13;
                pdVar5[1] = (double)(iVar6 / iVar13) + pdVar5[1];
                local_40 = local_40 + iVar10;
                iVar7 = iVar7 / iVar13;
                iVar14 = iVar14 + -1;
                local_50 = (double)CONCAT44(iVar7,(undefined4)local_50);
                pdVar5[2] = (double)iVar7 + pdVar5[2];
                pdVar5 = pdVar5 + 4;
              } while (iVar14 != 0);
            }
            if (local_14 < iVar4) {
              local_40 = local_18 * 4;
              iVar10 = (local_14 - local_10) * local_18 * 4;
              iVar13 = iVar4 - local_14;
              pdVar5 = (double *)(&DAT_011289b0 + local_8 * 1000 + local_14);
              do {
                iVar14 = iVar10 / (local_c - local_10);
                iVar10 = iVar10 + local_40;
                iVar14 = iVar14 / (local_c - local_10);
                iVar13 = iVar13 + -1;
                local_50 = (double)CONCAT44(iVar14,(undefined4)local_50);
                *pdVar5 = (double)iVar14 + *pdVar5;
                pdVar5 = pdVar5 + 1;
              } while (iVar13 != 0);
            }
          }
          local_14 = iVar4;
          if (iVar4 < local_c) {
            iVar10 = local_c - iVar4;
            if (3 < iVar10) {
              local_40 = iVar10 * local_18 * 4;
              iVar13 = local_c - local_10;
              local_34 = (iVar10 + -3) * local_18 * 4;
              local_3c = (iVar10 * 4 + -4) * local_18;
              local_38 = (iVar10 + -2) * local_18 * 4;
              iVar14 = local_18 * -0x10;
              iVar10 = ((local_c - iVar4) - 4U >> 2) + 1;
              local_14 = iVar4 + iVar10 * 4;
              pdVar5 = (double *)(&DAT_011289b8 + local_8 * 1000 + iVar4);
              do {
                iVar4 = local_40 / iVar13;
                local_40 = local_40 + iVar14;
                iVar6 = local_3c / iVar13;
                pdVar5[-1] = (double)(iVar4 / iVar13) + pdVar5[-1];
                local_3c = local_3c + iVar14;
                iVar4 = local_38 / iVar13;
                *pdVar5 = (double)(iVar6 / iVar13) + *pdVar5;
                local_38 = local_38 + iVar14;
                iVar6 = local_34 / iVar13;
                pdVar5[1] = (double)(iVar4 / iVar13) + pdVar5[1];
                local_34 = local_34 + iVar14;
                iVar6 = iVar6 / iVar13;
                iVar10 = iVar10 + -1;
                local_50 = (double)CONCAT44(iVar6,(undefined4)local_50);
                pdVar5[2] = (double)iVar6 + pdVar5[2];
                pdVar5 = pdVar5 + 4;
              } while (iVar10 != 0);
            }
            if (local_14 < local_c) {
              local_40 = local_c - local_14;
              iVar4 = local_40 * local_18 * 4;
              pdVar5 = (double *)(&DAT_011289b0 + local_8 * 1000 + local_14);
              do {
                iVar10 = iVar4 / (local_c - local_10);
                iVar4 = iVar4 + local_18 * -4;
                iVar10 = iVar10 / (local_c - local_10);
                local_40 = local_40 + -1;
                local_50 = (double)CONCAT44(iVar10,(undefined4)local_50);
                *pdVar5 = (double)iVar10 + *pdVar5;
                pdVar5 = pdVar5 + 1;
              } while (local_40 != 0);
              local_40 = 0;
            }
          }
        }
        else if ((DAT_0113e240 == 2) && (local_10 < local_c)) {
          iVar4 = local_10;
          if (3 < local_c - local_10) {
            dVar1 = (double)(int)local_18;
            iVar10 = ((local_c - local_10) - 4U >> 2) + 1;
            iVar4 = local_10 + iVar10 * 4;
            pdVar5 = (double *)(&DAT_011289b8 + local_8 * 1000 + local_10);
            do {
              iVar10 = iVar10 + -1;
              pdVar5[-1] = dVar1 + pdVar5[-1];
              *pdVar5 = dVar1 + *pdVar5;
              pdVar5[1] = dVar1 + pdVar5[1];
              pdVar5[2] = dVar1 + pdVar5[2];
              pdVar5 = pdVar5 + 4;
            } while (iVar10 != 0);
          }
          if (iVar4 < local_c) {
            iVar10 = local_c - iVar4;
            pdVar5 = (double *)(&DAT_011289b0 + local_8 * 1000 + iVar4);
            do {
              iVar10 = iVar10 + -1;
              *pdVar5 = (double)(int)local_18 + *pdVar5;
              pdVar5 = pdVar5 + 1;
            } while (iVar10 != 0);
          }
        }
      }
      local_20 = local_20 + -10;
      local_44 = local_44 + 1;
      iVar4 = local_48 + -1;
      local_48 = iVar4;
    } while (local_28 <= iVar4);
  }
  if (((DAT_01127201 & 0x1000000) != 0) &&
     (iVar4 = 0, uVar12 = DAT_0113e2cc, 0 < *(int *)(local_24 + 0x1e6))) {
    do {
      uVar9 = uVar12;
      if (3 < (int)uVar12) {
        iVar10 = (uVar12 - 4 >> 2) + 1;
        uVar9 = uVar12 + iVar10 * -4;
        pdVar5 = (double *)(&DAT_011289b0 + (uVar12 - 2) * 1000 + iVar4);
        do {
          iVar10 = iVar10 + -1;
          dVar1 = pdVar5[1000];
          pdVar5[1000] = pdVar5[2000] + dVar1;
          dVar1 = pdVar5[2000] + dVar1 + *pdVar5;
          *pdVar5 = dVar1;
          dVar1 = dVar1 + pdVar5[-1000];
          pdVar5[-1000] = dVar1;
          pdVar5[-2000] = dVar1 + pdVar5[-2000];
          pdVar5 = pdVar5 + -4000;
        } while (iVar10 != 0);
      }
      if (0 < (int)uVar9) {
        pdVar5 = (double *)(&DAT_01126a70 + (uVar9 * 1000 + iVar4) * 8);
        do {
          uVar9 = uVar9 - 1;
          *pdVar5 = pdVar5[1000] + *pdVar5;
          pdVar5 = pdVar5 + -1000;
        } while (0 < (int)uVar9);
      }
      if (*(double *)(param_2 + 0x15) < (double)(&DAT_011289b0)[iVar4]) {
        *(undefined8 *)(param_2 + 0x15) = (&DAT_011289b0)[iVar4];
        uVar12 = DAT_0113e2cc;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(local_24 + 0x1e6));
  }
  if (((DAT_01127201 & 0x800000) != 0) && (iVar4 = 0, 0 < *(int *)(local_24 + 0x1e6))) {
    do {
      dVar1 = (double)(&DAT_0112e770)[iVar4];
      (&DAT_0112e770)[iVar4] = (double)(&DAT_011306b0)[iVar4] + dVar1;
      dVar1 = (double)(&DAT_011306b0)[iVar4] + dVar1 + (double)(&DAT_0112c830)[iVar4];
      (&DAT_0112c830)[iVar4] = dVar1;
      dVar1 = dVar1 + (double)(&DAT_0112a8f0)[iVar4];
      (&DAT_0112a8f0)[iVar4] = dVar1;
      dVar1 = dVar1 + (double)(&DAT_011289b0)[iVar4];
      (&DAT_011289b0)[iVar4] = dVar1;
      if (*(double *)(param_2 + 0x15) < dVar1) {
        *(double *)(param_2 + 0x15) = dVar1;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(local_24 + 0x1e6));
  }
  uVar12 = DAT_0113e2d0;
  if (((DAT_01127201 & 0x2000000) != 0) && (iVar4 = 0, 0 < *(int *)(local_24 + 0x1e6))) {
    pdVar5 = (double *)&DAT_0112a8f0;
    do {
      pdVar8 = pdVar5;
      uVar9 = uVar12;
      if (0 < (int)uVar12) {
        do {
          uVar9 = uVar9 - 1;
          *pdVar8 = pdVar8[-1000] + *pdVar8;
          pdVar8 = pdVar8 + 1000;
        } while (uVar9 != 0);
      }
      if (*(double *)(param_2 + 0x15) < (double)(&DAT_011289b0)[uVar12 * 1000 + iVar4]) {
        *(undefined8 *)(param_2 + 0x15) = (&DAT_011289b0)[uVar12 * 1000 + iVar4];
        uVar12 = DAT_0113e2d0;
      }
      iVar4 = iVar4 + 1;
      pdVar5 = pdVar5 + 1;
    } while (iVar4 < *(int *)(local_24 + 0x1e6));
  }
  _DAT_0113e1b0 = 0.0;
  _DAT_0113e1b4 = 0;
  _DAT_0113e1b8 = 0;
  _DAT_0113e1bc = 0;
  _DAT_0113e1c0 = 0;
  _DAT_0113e1c4 = 0;
  _DAT_0113e1c8 = 0;
  _DAT_0113e1cc = 0;
  DAT_0113e1d0 = 0;
  DAT_0113e1f8 = 0;
  _DAT_0113e1d4 = 0;
  _DAT_0113e1fc = 0;
  _DAT_0113e1d8 = 0;
  _DAT_0113e200 = 0;
  _DAT_0113e1dc = 0;
  _DAT_0113e204 = 0;
  _DAT_0113e1e0 = 0;
  _DAT_0113e208 = 0;
  _DAT_0113e1e4 = 0;
  _DAT_0113e20c = 0;
  _DAT_0113e1e8 = 0;
  _DAT_0113e210 = 0;
  _DAT_0113e1ec = 0;
  _DAT_0113e214 = 0;
  _DAT_0113e1f0 = 0;
  _DAT_0113e218 = 0;
  _DAT_0113e1f4 = 0;
  _DAT_0113e21c = 0;
  DAT_0113e1a8 = *(undefined4 *)(local_2c + (int)param_5 * 0x28);
  _DAT_0113e1ac = 0.0;
  iVar4 = *(int *)(local_24 + 0x1e6);
  local_1c = iVar4;
  local_10 = FUN_00bea080();
  uVar9 = DAT_0113e2cc;
  if (local_10 < 0) {
    local_10 = 0;
  }
  fVar2 = 0.0;
  fVar3 = fVar2;
  if ((DAT_01127201 & 0x1000000) == 0) {
    if ((DAT_01127201 & 0x2000000) != 0) {
      iVar10 = 0;
      if (3 < local_10) {
        iVar13 = (local_10 - 4U >> 2) + 1;
        iVar10 = iVar13 * 4;
        pdVar5 = (double *)(&DAT_011289b8 + uVar12 * 1000);
        do {
          iVar13 = iVar13 + -1;
          fVar3 = (float)pdVar5[-1] + fVar3 + (float)*pdVar5 + (float)pdVar5[1] + (float)pdVar5[2];
          pdVar5 = pdVar5 + 4;
        } while (iVar13 != 0);
      }
      if (iVar10 < local_10) {
        iVar13 = local_10 - iVar10;
        pdVar5 = (double *)(&DAT_011289b0 + uVar12 * 1000 + iVar10);
        do {
          iVar13 = iVar13 + -1;
          fVar3 = fVar3 + (float)*pdVar5;
          pdVar5 = pdVar5 + 1;
        } while (iVar13 != 0);
      }
      if (local_10 < iVar4) {
        iVar10 = local_10;
        if (3 < iVar4 - local_10) {
          iVar13 = ((iVar4 - local_10) - 4U >> 2) + 1;
          iVar10 = local_10 + iVar13 * 4;
          pdVar5 = (double *)(&DAT_011289b8 + uVar12 * 1000 + local_10);
          do {
            iVar13 = iVar13 + -1;
            fVar2 = fVar2 + (float)pdVar5[-1] + (float)*pdVar5 + (float)pdVar5[1] + (float)pdVar5[2]
            ;
            pdVar5 = pdVar5 + 4;
          } while (iVar13 != 0);
        }
        if (iVar10 < iVar4) {
          pdVar5 = (double *)(&DAT_011289b0 + uVar12 * 1000 + iVar10);
          iVar4 = iVar4 - iVar10;
          do {
            fVar2 = fVar2 + (float)*pdVar5;
            pdVar5 = pdVar5 + 1;
            iVar4 = iVar4 + -1;
          } while (iVar4 != 0);
        }
      }
    }
  }
  else {
    iVar10 = 0;
    if (3 < local_10) {
      do {
        pdVar5 = (double *)(&DAT_011289b0 + iVar10);
        iVar10 = iVar10 + 4;
        fVar3 = (float)*pdVar5 + fVar3 + (float)*(double *)(iVar10 * 8 + 0x1128998) +
                (float)*(double *)(iVar10 * 8 + 0x11289a0) +
                (float)*(double *)(&DAT_011289a8 + iVar10 * 8);
      } while (iVar10 < local_10 + -3);
    }
    for (; iVar10 < local_10; iVar10 = iVar10 + 1) {
      pdVar5 = (double *)(&DAT_011289b0 + iVar10);
      fVar3 = (float)*pdVar5 + fVar3;
    }
    if (local_10 < iVar4) {
      iVar10 = local_10;
      if (3 < iVar4 - local_10) {
        do {
          pdVar5 = (double *)(&DAT_011289b0 + iVar10);
          iVar10 = iVar10 + 4;
          fVar2 = fVar2 + (float)*pdVar5 + (float)*(double *)(iVar10 * 8 + 0x1128998) +
                  (float)*(double *)(iVar10 * 8 + 0x11289a0) +
                  (float)*(double *)(&DAT_011289a8 + iVar10 * 8);
        } while (iVar10 < iVar4 + -3);
      }
      for (; iVar10 < iVar4; iVar10 = iVar10 + 1) {
        fVar2 = fVar2 + (float)(double)(&DAT_011289b0)[iVar10];
      }
    }
  }
  if (fVar2 + fVar3 != 0.0) {
    _DAT_0113e1ac = fVar2 / (fVar2 + fVar3);
  }
  _DAT_0113e1b0 = (float)local_10;
  param_1 = (float)extraout_ST0;
  fVar15 = (float10)_DAT_00ef9ed0;
  if ((DAT_01127201 & 0x1000000) != 0) {
    pdVar5 = (double *)&DAT_011289b8;
    do {
      pdVar8 = pdVar5 + 10;
      param_1 = param_1 + (float)pdVar5[-1] + (float)*pdVar5 + (float)pdVar5[1] + (float)pdVar5[2] +
                (float)pdVar5[3] + (float)pdVar5[4] + (float)pdVar5[5] + (float)pdVar5[6] +
                (float)pdVar5[7] + (float)pdVar5[8];
      pdVar5 = pdVar8;
    } while ((int)pdVar8 < 0x112a8f8);
    iVar4 = 1;
    if (0 < (int)DAT_0113e2cc) {
      pdVar5 = (double *)&DAT_0112a8f8;
      do {
        param_5 = (float)extraout_ST0;
        iVar10 = 100;
        pdVar8 = pdVar5;
        do {
          pdVar5 = pdVar8 + 10;
          iVar10 = iVar10 + -1;
          param_5 = param_5 + (float)pdVar8[-1] + (float)*pdVar8 + (float)pdVar8[1] +
                    (float)pdVar8[2] + (float)pdVar8[3] + (float)pdVar8[4] + (float)pdVar8[5] +
                    (float)pdVar8[6] + (float)pdVar8[7] + (float)pdVar8[8];
          pdVar8 = pdVar5;
        } while (iVar10 != 0);
        if (extraout_ST0 == (float10)param_5) {
          *param_2 = 1;
          return 1;
        }
        iVar4 = iVar4 + 1;
        *(float *)(&DAT_0113e1c8 + iVar4 * 4) =
             (float)(((float10)param_5 / (float10)param_1) * fVar15);
      } while (iVar4 <= (int)uVar9);
    }
  }
  uVar12 = DAT_0113e2d0;
  if ((DAT_01127201 & 0x2000000) != 0) {
    iVar4 = 100;
    pdVar5 = (double *)(&DAT_011289b8 + DAT_0113e2d0 * 1000);
    do {
      iVar4 = iVar4 + -1;
      param_1 = param_1 + (float)pdVar5[-1] + (float)*pdVar5 + (float)pdVar5[1] + (float)pdVar5[2] +
                (float)pdVar5[3] + (float)pdVar5[4] + (float)pdVar5[5] + (float)pdVar5[6] +
                (float)pdVar5[7] + (float)pdVar5[8];
      pdVar5 = pdVar5 + 10;
    } while (iVar4 != 0);
    iVar4 = 0;
    if (0 < (int)DAT_0113e2d0) {
      pdVar5 = (double *)&DAT_011289b8;
      do {
        param_5 = (float)extraout_ST0;
        iVar10 = 100;
        pdVar8 = pdVar5;
        do {
          pdVar5 = pdVar8 + 10;
          iVar10 = iVar10 + -1;
          param_5 = param_5 + (float)pdVar8[-1] + (float)*pdVar8 + (float)pdVar8[1] +
                    (float)pdVar8[2] + (float)pdVar8[3] + (float)pdVar8[4] + (float)pdVar8[5] +
                    (float)pdVar8[6] + (float)pdVar8[7] + (float)pdVar8[8];
          pdVar8 = pdVar5;
        } while (iVar10 != 0);
        if ((float10)param_1 == (float10)param_5) {
          *param_2 = 1;
          return 1;
        }
        iVar4 = iVar4 + 1;
        *(float *)(&DAT_0113e1f4 + iVar4 * 4) =
             (float)(((float10)param_5 / (float10)param_1) * fVar15);
      } while (iVar4 < (int)uVar12);
    }
  }
  *param_2 = 1;
  return 1;
}

