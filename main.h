//---------------------------------------------------------------------------

#ifndef mainH
#define mainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
#include <XPMan.hpp>
#include "cspin.h"
#include <Dialogs.hpp>
#include <ExtDlgs.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TStringGrid *StringGrid1;
	TStringGrid *StringGrid2;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TXPManifest *XPManifest1;
	TButton *Button1;
	TLabel *Label5;
	TEdit *Edit1;
	TUpDown *UpDown1;
	TStringGrid *StringGrid3;
	TLabel *Label6;
	TLabel *Label7;
	TCheckBox *CheckBox1;
	TButton *Button2;
	TCheckBox *CheckBox2;
	void __fastcall Edit1KeyPress(TObject *Sender, char &Key);
	void __fastcall Edit1Change(TObject *Sender);
	void __fastcall ContextPopupDisable(TObject *Sender, TPoint &MousePos,
		  bool &Handled);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall CheckBox1Click(TObject *Sender);
	void __fastcall StringGridDrawCell(TObject *Sender, int ACol, int ARow,
          TRect &Rect, TGridDrawState State);
	void __fastcall StringGridKeyPress(TObject *Sender, char &Key);
	void __fastcall StringGridSetEditText(TObject *Sender, int ACol, int ARow,
          const AnsiString Value);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
