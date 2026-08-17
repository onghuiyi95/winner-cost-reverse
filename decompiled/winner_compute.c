//==== FUN_10092e60 @ 0x10092e60 (WINNER 计算函数, 反编译含WINNER字符串) ====

void __fastcall FUN_10092e60(undefined4 *param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  
  piVar3 = *(int **)((int)param_1 + 0x12);
  *param_1 = &PTR_WINNER_IMPL_1015e7f8;
  if (piVar3 != (int *)0x0) {
    puVar4 = (undefined4 *)(*piVar3 + -0x10);
    piVar1 = (int *)(*piVar3 + -4);
    LOCK();
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 1 || iVar2 + -1 < 0) {
      (**(code **)(*(int *)*puVar4 + 4))(puVar4);
    }
                    /* WARNING: Subroutine does not return */
    _free(piVar3);
  }
  piVar3 = (int *)param_1[6];
  if (piVar3 != (int *)0x0) {
    puVar4 = (undefined4 *)(*piVar3 + -0x10);
    piVar1 = (int *)(*piVar3 + -4);
    LOCK();
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 1 || iVar2 + -1 < 0) {
      (**(code **)(*(int *)*puVar4 + 4))(puVar4);
    }
                    /* WARNING: Subroutine does not return */
    _free(piVar3);
  }
  piVar3 = (int *)param_1[7];
  if (piVar3 != (int *)0x0) {
    puVar4 = (undefined4 *)(*piVar3 + -0x10);
    piVar1 = (int *)(*piVar3 + -4);
    LOCK();
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 1 || iVar2 + -1 < 0) {
      (**(code **)(*(int *)*puVar4 + 4))(puVar4);
    }
                    /* WARNING: Subroutine does not return */
    _free(piVar3);
  }
  FUN_100b5400();
  return;
}


