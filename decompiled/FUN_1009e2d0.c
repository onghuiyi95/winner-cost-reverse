
int FUN_1009e2d0(int *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_3 + 0x24);
  if (*(int *)(param_3 + 0x24) == 0) {
    if ((param_1 != (int *)0x0) && (iVar1 = (**(code **)(*param_1 + 0x10))(), iVar1 != 0)) {
                    /* WARNING: Could not recover jumptable at 0x1009e2f4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar1 = (**(code **)(*param_1 + 0x10))();
      return iVar1;
    }
    iVar1 = FUN_100b2400(1);
    if (iVar1 != 0) {
      iVar1 = FUN_100b2400(1);
      return iVar1;
    }
    iVar2 = FUN_100b2400(2);
    iVar1 = DAT_101961a4;
    if (iVar2 != 0) {
      iVar1 = FUN_100b2400(2);
      return iVar1;
    }
  }
  return iVar1;
}

