//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MZeroForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button1Click(TObject *Sender)
{
	Form2->Hide();	
}
//---------------------------------------------------------------------------

void __fastcall TForm2::FormClose(TObject *Sender, TCloseAction &Action)
{
	Action = caHide;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::StringGrid1DrawCell(TObject *Sender, int ACol, int ARow,
      TRect &Rect, TGridDrawState State)
{
	if (ARow == 0) {
    	StringGrid1->Canvas->Font->Size = 10;
		StringGrid1->Canvas->TextOut(Rect.Left+4, Rect.Top, "P");
		StringGrid1->Canvas->Font->Size = 6;
		StringGrid1->Canvas->TextOut(Rect.Left+10, Rect.Top+9, IntToStr(ACol + 1));
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm2::StringGrid1ContextPopup(TObject *Sender,
      TPoint &MousePos, bool &Handled)
{
	Handled = true;	
}
//---------------------------------------------------------------------------

void __fastcall TForm2::StringGrid1KeyPress(TObject *Sender, char &Key)
{
	if ((Key < 48 && Key != 8) || (Key > 57 && Key != 127)) {
		Key = 0;
	}
}
//---------------------------------------------------------------------------

