//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MTreeForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm3::FormClose(TObject *Sender, TCloseAction &Action)
{
	Action = caHide;	
}
//---------------------------------------------------------------------------
void __fastcall TForm3::FormCreate(TObject *Sender)
{
	AddFontResource("MyFont.otf");
	SendMessage(HWND_BROADCAST, WM_FONTCHANGE, 0, 0);
	ListBox1->Font->Name = "MyFont";
}
//---------------------------------------------------------------------------
