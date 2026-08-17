//==== FUN_100934f0 @ 0x100934f0 ====

undefined4 * __thiscall
FUN_100934f0(undefined4 *param_1,ushort param_2,int param_3,undefined2 param_4,undefined4 param_5)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_10146560;
  pvStack_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  FUN_100b53e0();
  *param_1 = &PTR_LAB_1015e7f8;
  param_1[2] = param_1[2] | 0x2000000;
  *(ushort *)(param_1 + 3) = param_2;
  *(undefined2 *)((int)param_1 + 0x16) = param_4;
  local_4 = CONCAT31(local_4._1_3_,1);
  if (*(int *)(param_3 + -0xc) == 0) {
    *(undefined4 *)((int)param_1 + 0x12) = 0;
  }
  else {
    piVar1 = operator_new(4);
    if (piVar1 == (int *)0x0) {
      *(undefined4 *)((int)param_1 + 0x12) = 0;
      FUN_100048b0(&param_3);
    }
    else {
      piVar2 = (int *)FUN_101129b5();
      iVar3 = (**(code **)(*piVar2 + 0xc))();
      *piVar1 = iVar3 + 0x10;
      *(int **)((int)param_1 + 0x12) = piVar1;
      FUN_100048b0(&param_3);
    }
  }
  if ((param_2 < 0xcb) || (0xdd < param_2)) {
    if ((param_2 < 0xe0) || (0xe8 < param_2)) {
      if ((param_2 < 0xeb) || (0xfd < param_2)) {
        if ((param_2 < 0x100) || (0x108 < param_2)) {
          if ((param_2 < 0x10b) || (0x113 < param_2)) {
            if ((param_2 < 0x116) || (0x123 < param_2)) {
              if ((param_2 < 0x126) || (0x12e < param_2)) {
                if ((param_2 < 0x131) || (0x139 < param_2)) {
                  if ((param_2 < 0x13c) || (0x144 < param_2)) {
                    if ((param_2 < 0x147) || (0x163 < param_2)) {
                      if ((param_2 < 0x66) || (200 < param_2)) {
                        if ((param_2 < 0x166) || (0x187 < param_2)) {
                          if ((param_2 < 0x18a) || (0x1a6 < param_2)) {
                            uVar4 = 0;
                          }
                          else {
                            uVar4 = 0xb;
                          }
                        }
                        else {
                          uVar4 = 0xd;
                        }
                      }
                      else {
                        uVar4 = 0xc;
                      }
                    }
                    else {
                      uVar4 = 10;
                    }
                  }
                  else {
                    uVar4 = 9;
                  }
                }
                else {
                  uVar4 = 8;
                }
              }
              else {
                uVar4 = 7;
              }
            }
            else {
              uVar4 = 6;
            }
          }
          else {
            uVar4 = 5;
          }
        }
        else {
          uVar4 = 4;
        }
      }
      else {
        uVar4 = 3;
      }
    }
    else {
      uVar4 = 2;
    }
  }
  else {
    uVar4 = 1;
  }
  *(undefined4 *)((int)param_1 + 0xe) = uVar4;
  param_1[8] = param_5;
  param_1[6] = 0;
  param_1[7] = 0;
  local_4 = 0xffffffff;
  piVar1 = (int *)(param_3 + -4);
  LOCK();
  iVar3 = *piVar1;
  *piVar1 = *piVar1 + -1;
  UNLOCK();
  if (iVar3 == 1 || iVar3 + -1 < 0) {
    (**(code **)(**(int **)(param_3 + -0x10) + 4))((undefined4 *)(param_3 + -0x10));
  }
  ExceptionList = pvStack_c;
  return param_1;
}


