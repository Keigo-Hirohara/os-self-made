// 開発環境に同封されているedk2/MdePkg/Uefi.hをインクルード
#include <Uefi.h>

// 開発環境に同封されいているedk2/MdePkg/Library/UefiLib.hをインクルード
#include <Library/UefiLib.h>

// EFIAPIはUEFI固有の呼び出し規約を指定するマクロ
EFI_STATUS EFIAPI
UefiMain(EFI_HANDLE image_handle, EFI_SYSTEM_TABLE *system_table)
{
  Print(L"Hello Mikan World!\n");

  while (1)
    ;

  return EFI_SUCCESS;
}