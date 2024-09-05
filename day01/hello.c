
// 符号なし2ビットの整数を扱う型の名前にCHAR16を付与
typedef unsigned short CHAR16;

// 符号なし8バイト以上の整数を扱う型に名前、EFI_STATUSを付与
typedef unsigned long long EFI_STATUS;

// voidポインタ型に新しい名前、EFI_HANDLEを付与
// EFI_HANDLEは任意のポインタ型になる
typedef void *EFI_HANDLE;

// 不完全型: EFI_HANDLEを定義
// 不完全型なので、後で詳細を記述できる
struct _EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL;

// 文字列出力関数のポインタ型を定義
// 戻り値: EFI_STATUS
// 引数: _EFI_SIMPLE_TEXT_OUTPUT_PROTOCOLのポインタ型のThis, CHAR16のポインタ型のString
// 関数名: EFI_TEXT_STRINGの関数ポインタ型を定義
typedef EFI_STATUS (*EFI_TEXT_STRING)(
    struct EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *This,
    CHAR16 *String);

// 不完全型: _EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL から完全型: EFI_SIMPLE_TEXT_OUTPUT_PROTOCOLを定義
// メンバ: 汎用ポインタ型のdummy, EFI_TEXT_STRINGという関数ポインタ型のOutputString
typedef struct _EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL
{
  void *dummy;
  EFI_TEXT_STRING OutputString;
} EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL;

// 構造体: EFI_SYSTEM_TABLEを定義
// メンバ
// char: 52バイトの文字列型のdummy(ConOut, COnsoleOutHandleメンバの位置がEFI_SYSTEM_TABLE構造体内での位置と一致するから。dummyデータには本来別のUEFI仕様に基づくメンバが入る)
// EFI_HANDLE型: ConsoleOutHandle
// EFI_SIMPLE_TEXT_OUTPUT_PROTOCOLのポインタ型: ConOut
typedef struct
{
  char dummy[52];
  EFI_HANDLE ConsoleOutHandle;
  EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *ConOut;
} EFI_SYSTEM_TABLE;

// EfiMain関数を定義
// 引数: EFI_HANDLE型のImageHandle, EFI_SYSTEM_TABLEのポインタ型のSystemTable
// 戻り値: EFI_STATUS型
EFI_STATUS EfiMain(
    EFI_HANDLE ImageHandle,
    EFI_SYSTEM_TABLE *SystemTable)
{
  // ImageHandleとSystemTableはUEFI BIOSがセットしてくれる。
  SystemTable->ConOut->OutputString(SystemTable->ConOut, L"Hello World!\n");

  // 無限ループによってUEFIアプリケーションが終了するのを防げる
  while (1)
    ;
  return 0;
}