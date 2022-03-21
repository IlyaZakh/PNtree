//---------------------------------------------------------------------------

#include <vcl.h>
#include "jpeg.hpp"
#pragma hdrstop

#include "MDrawTree.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm4 *Form4;
//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm4::FormClose(TObject *Sender, TCloseAction &Action)
{
	Action = caHide;	
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Button1Click(TObject *Sender)
{
	if (SavePictureDialog1->Execute()) {
		AnsiString Path = SavePictureDialog1->FileName;
		switch (SavePictureDialog1->FilterIndex) {
			case 1: //.jpg
				if (!(Path.Length() > 4 &&
					Path[Path.Length() - 3] == '.' &&
					(Path[Path.Length() - 2] == 'j' ||
					Path[Path.Length() - 2] == 'J') &&
					(Path[Path.Length() - 1] == 'p' ||
					Path[Path.Length() - 1] == 'P') &&
					(Path[Path.Length()] == 'g' ||
					Path[Path.Length()] == 'G'))) {
						Path += ".jpg";
				}
				break;
			case 2: //.jpeg
				if (!(Path.Length() > 5 &&
					Path[Path.Length() - 4] == '.' &&
					(Path[Path.Length() - 3] == 'j' ||
					Path[Path.Length() - 3] == 'J') &&
					(Path[Path.Length() - 2] == 'p' ||
					Path[Path.Length() - 2] == 'P') &&
					(Path[Path.Length() - 1] == 'e' ||
					Path[Path.Length() - 1] == 'E') &&
					(Path[Path.Length()] == 'g' ||
					Path[Path.Length()] == 'G'))) {
						Path += ".jpeg";
				}
				break;
			case 3: //.bmp
				if (!(Path.Length() > 4 &&
					Path[Path.Length() - 3] == '.' &&
					(Path[Path.Length() - 2] == 'b' ||
					Path[Path.Length() - 2] == 'B') &&
					(Path[Path.Length() - 1] == 'm' ||
					Path[Path.Length() - 1] == 'M') &&
					(Path[Path.Length()] == 'p' ||
					Path[Path.Length()] == 'P'))) {
						Path += ".bmp";
				}
				break;
		}
		if (SavePictureDialog1->FilterIndex == 3) {
			Image1->Picture->SaveToFile(Path);
		}
		else {
			TJPEGImage *jpeg = new TJPEGImage();
			jpeg->Assign(Image1->Picture->Graphic);
			jpeg->CompressionQuality = 90;
			jpeg->Compress();
			jpeg->SaveToFile(Path);
			delete jpeg;
        }
	}
}
//---------------------------------------------------------------------------

