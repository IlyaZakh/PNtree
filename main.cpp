//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "main.h"
#include "MZeroForm.h"
#include "MTreeForm.h"
#include "MDrawTree.h"
#include "list"
#include "queue"
#include "math.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cspin"
#pragma resource "*.dfm"
TForm1 *Form1;
unsigned int Value;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Edit1KeyPress(TObject *Sender, char &Key)
{
	if ((Key < 48 && Key != 8) || (Key > 57 && Key != 127)) {
		Key = 0;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit1Change(TObject *Sender)
{
	if (!TryStrToInt(Edit1->Text, (int)Value)) {
		 Value = 2;
	}
	if (Value > 16) {
		Value = 16;
	}
	if (Value < 2) {
		Value = 2;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ContextPopupDisable(TObject *Sender, TPoint &MousePos,
	  bool &Handled)
{
	Handled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
	Button2->Left = Form1->ClientWidth - 8 - Button2->Width;
	Button1->Left = Button2->Left - 8 - Button1->Width;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CheckBox1Click(TObject *Sender)
{
	StringGrid3->Visible = !StringGrid3->Visible;
	Label6->Visible = !Label6->Visible;
	Label7->Visible = !Label7->Visible;
	if (CheckBox1->Checked) {
		Form1->ClientWidth = 1065;
	}
	else {
		Form1->ClientWidth = 713;
		for (int i = 0; i < StringGrid3->ColCount; i++) {
			for (int j = 0; j < StringGrid3->RowCount; j++) {
				StringGrid3->Cells[i][j] = "";
			}
		}
		StringGridSetEditText(StringGrid1, 1, 1, StringGrid1->Cells[1][1]);
	}
	Button2->Left = Form1->ClientWidth - 8 - Button2->Width;
	Button1->Left = Button2->Left - 8 - Button1->Width;
}
//---------------------------------------------------------------------------

const int left = 10;
const int top = 9;

void __fastcall TForm1::StringGridDrawCell(TObject *Sender, int ACol, int ARow,
	  TRect &Rect, TGridDrawState State)
{
	if ((ACol == ((TStringGrid*)Sender)->ColCount - 1 || ARow == ((TStringGrid*)Sender)->RowCount - 1 && ARow != 0) && ACol != 0 && ARow != 0) {
		((TStringGrid*)Sender)->Canvas->Brush->Color = clLime;
		((TStringGrid*)Sender)->Canvas->FillRect(Rect);
	}
	if (((TStringGrid*)Sender)->Name  == "StringGrid2") {
		if (ACol == 0 && ARow != 0) {
			((TStringGrid*)Sender)->Canvas->Font->Size = 10;
			((TStringGrid*)Sender)->Canvas->TextOut(Rect.Left+4, Rect.Top, "t");
			((TStringGrid*)Sender)->Canvas->Font->Size = 6;
			((TStringGrid*)Sender)->Canvas->TextOut(Rect.Left+left, Rect.Top+top, IntToStr(ARow));
		}
		if (ARow == 0 && ACol != 0) {
			((TStringGrid*)Sender)->Canvas->Font->Size = 10;
			((TStringGrid*)Sender)->Canvas->TextOut(Rect.Left+4, Rect.Top, "P");
			((TStringGrid*)Sender)->Canvas->Font->Size = 6;
			((TStringGrid*)Sender)->Canvas->TextOut(Rect.Left+left, Rect.Top+top, IntToStr(ACol));
		}
	}
	else {
		if (ACol == 0 && ARow != 0) {
			((TStringGrid*)Sender)->Canvas->Font->Size = 10;
			((TStringGrid*)Sender)->Canvas->TextOut(Rect.Left+4, Rect.Top, "P");
			((TStringGrid*)Sender)->Canvas->Font->Size = 6;
			((TStringGrid*)Sender)->Canvas->TextOut(Rect.Left+left, Rect.Top+top, IntToStr(ARow));
		}
		if (ARow == 0 && ACol != 0) {
			((TStringGrid*)Sender)->Canvas->Font->Size = 10;
			((TStringGrid*)Sender)->Canvas->TextOut(Rect.Left+4, Rect.Top, "t");
			((TStringGrid*)Sender)->Canvas->Font->Size = 6;
			((TStringGrid*)Sender)->Canvas->TextOut(Rect.Left+left, Rect.Top+top, IntToStr(ACol));
		}
	}
}
//---------------------------------------------------------------------------


void __fastcall TForm1::StringGridKeyPress(TObject *Sender, char &Key)
{
	if ((Key < 48 && Key != 8) || (Key > 57 && Key != 127)) {
		Key = 0;
	}
}
//---------------------------------------------------------------------------

void WidthCorrection() {
	int max = Form1->StringGrid1->RowCount;
	if (Form1->StringGrid1->ColCount > max) {
		max = Form1->StringGrid1->ColCount;
	}
	if (max > 100) {
		Form1->StringGrid1->DefaultColWidth = 22 + (IntToStr(max - 1).Length() - 2) * 5;
	}
	else {
		Form1->StringGrid1->DefaultColWidth = 22;
	}
}

bool crutch = true;
void __fastcall TForm1::StringGridSetEditText(TObject *Sender, int ACol,
	  int ARow, const AnsiString Value)
{
	if (crutch) {
		int flag = false;
		if (ACol == ((TStringGrid*)Sender)->ColCount - 1 && Value != "" && ACol != 0 && ARow != 0) {
			if (((TStringGrid*)Sender)->Name == "StringGrid2") {
				StringGrid1->RowCount += 1;
				StringGrid2->ColCount += 1;
				StringGrid3->RowCount += 1;
			}
			else {
				StringGrid1->ColCount += 1;
				StringGrid2->RowCount += 1;
				StringGrid3->ColCount += 1;
			}
			flag = true;
		}
		if (ARow == ((TStringGrid*)Sender)->RowCount - 1 && Value != "" && ACol != 0 && ARow != 0) {
			if (((TStringGrid*)Sender)->Name == "StringGrid2") {
				StringGrid1->ColCount += 1;
				StringGrid2->RowCount += 1;
				StringGrid3->ColCount += 1;
			}
			else {
				StringGrid1->RowCount += 1;
				StringGrid2->ColCount += 1;
				StringGrid3->RowCount += 1;
			}
			flag = true;
		}
		if (flag) {
			WidthCorrection();
		}
		int R = StringGrid1->RowCount;
		int	C = StringGrid1->ColCount;
		bool fl2 = false;
		flag = true;
		for (int i = 1; i < StringGrid1->ColCount - 1; i++) {
			if (StringGrid1->Cells[i][StringGrid1->RowCount - 2] != "" ||
				StringGrid2->Cells[StringGrid2->ColCount - 2][i] != "" ||
				StringGrid3->Cells[i][StringGrid3->RowCount - 2] != "") {
					flag = false;
			}
		}
		if (flag && R > 3) {
			R -= 1;
			fl2 = true;
		}
		flag = true;
		for (int i = 1; i < StringGrid1->RowCount - 1; i++) {
			if (StringGrid1->Cells[StringGrid1->ColCount - 2][i] != "" ||
				StringGrid2->Cells[i][StringGrid2->RowCount - 2] != "" ||
				StringGrid3->Cells[StringGrid3->ColCount - 2][i] != "") {
					flag = false;
			}
		}
		if (flag && C > 3) {
			C -= 1;
			fl2 = true;
		}
		crutch = false;
		StringGrid1->RowCount = R;
		StringGrid1->ColCount = C;
		StringGrid2->RowCount = C;
		StringGrid2->ColCount = R;
		StringGrid3->RowCount = R;
		StringGrid3->ColCount = C;
		crutch = true;
		if (fl2) {
			StringGridSetEditText(StringGrid1, 1, 1, StringGrid1->Cells[1][1]);
			WidthCorrection();
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
	Form2->StringGrid1->ColCount = StringGrid1->RowCount - 2;
	Form2->Position = poMainFormCenter;
	Form2->Show();
}
//---------------------------------------------------------------------------

class Marking {
	public:
		AnsiString Name;
		int *m;
		Marking(AnsiString _Name, int *_m) {
			Name = _Name;
			m = _m;
		}
		~Marking() {
			delete[] m;
		}
};

class Tree {
	public:
		Marking *Mi;
		Tree **Child;
		bool Repeated;
		AnsiString Lang;
		unsigned int level;
		Tree(Marking* _Mi, bool _Repeated, AnsiString _Lang, unsigned int _level) {
			Mi = _Mi;
			Child = NULL;
			Repeated = _Repeated;
			Lang = _Lang;
			level = _level;
		}
		Tree() {
			Mi = NULL;
			Child = NULL;
			Repeated = false;
			Lang = "";
			level = 0u;
		}
		~Tree() {
			delete Mi;
			if (Child != NULL) {
				for (unsigned int i = 0; i < sizeof(Child) / sizeof(Child[0]); i++) {
					if (Child[i] != NULL) {
						delete Child[i];
					}
				}
				delete[] Child;
			}
        }
};

std::list <Marking*> Mn;

void TreeFind(Tree *branch, unsigned int maxLvl, int **Fp, int **Ft, int **Fi, int p, int t) {
	std::queue <Tree*> O;
	O.push(branch);
	while (!O.empty()) {
		Tree* currentBranch = O.front();
		O.pop();
		if (currentBranch->level < maxLvl) {
			currentBranch->Child = new Tree*[t];
			for (int i = 0; i < t; i++) {
				currentBranch->Child[i] = NULL;
			}
			for (int i = 0; i < t; i++) {
				bool flag = true;
				for (int j = 0; j < p; j++) {
					if (Fi[j][i] != 0 && currentBranch->Mi->m[j] >= Fi[j][i]) {
						flag = false;
					}
				}
				for (int j = 0; j < p; j++) {
					if (currentBranch->Mi->m[j] < Fp[j][i]) {
						flag = false;
					}
				}
				if (flag) {
					int *Mi = new int[p];
					for (int j = 0; j < p; j++) {
						Mi[j] = currentBranch->Mi->m[j] - Fp[j][i] + Ft[i][j];
					}
					bool f2 = true;
					Marking *fff;
					for (std::list<Marking*>::iterator lMi = Mn.begin(); lMi != Mn.end(); lMi++) {
						flag = false;
						for (int j = 0; j < p; j++) {
							if (Mi[j] != (*lMi)->m[j]) {
								flag = true;
							}
						}
						if (!flag) {
							f2 = false;
							fff = (*lMi);
						}
					}
					if (!f2) {
						currentBranch->Child[i] = new Tree(fff, true, currentBranch->Lang + "t" + IntToStr(i + 1) + " ", currentBranch->level + 1);
					}
					else {
						AnsiString Mname = "M" + IntToStr(StrToInt(Mn.front()->Name.SubString(2, Mn.front()->Name.Length() - 1)) + 1);
						Mn.push_front(new Marking(Mname, Mi));
						currentBranch->Child[i] = new Tree(Mn.front(), false, currentBranch->Lang + "t" + IntToStr(i + 1) + " ", currentBranch->level + 1);
					}
				}
			}
			for (int i = 0; i < t; i++) {
				if (currentBranch->Child[i] != NULL && !currentBranch->Child[i]->Repeated) {
					O.push(currentBranch->Child[i]);
				}
				else {
					if (Form1->CheckBox2->Checked && currentBranch->Child[i] != NULL) {
						currentBranch->Child[i]->Child = new Tree*[1];
						currentBranch->Child[i]->Child[0] = new Tree(currentBranch->Child[i]->Mi, false, currentBranch->Child[i]->Lang, currentBranch->Child[i]->level);
						O.push(currentBranch->Child[i]->Child[0]);
					}
				}
			}

		}
	}
}

void AddTree(Tree *branch, int p, int t, TTreeNode *a) {
	if (branch->Child != NULL && !branch->Repeated) {
		for (int i = 0; i < t; i++) {
			if (branch->Child[i] != NULL) {
				AnsiString sads = "";
				for (int k = 0; k < p; k++) {
					if (k != p - 1) {
						sads += IntToStr(branch->Child[i]->Mi->m[k]) + ",";
					}
					else {
						sads += IntToStr(branch->Child[i]->Mi->m[k]);
					}
				}

				if (branch->Child[i]->Repeated) {
					AddTree(branch->Child[i], p, t, Form3->TreeView1->Items->AddChild(a, "t" + IntToStr(i+1) + " " + branch->Child[i]->Mi->Name + "(" + sads + ") Повтор"));
				}
				else {
					AddTree(branch->Child[i], p, t, Form3->TreeView1->Items->AddChild(a, "t" + IntToStr(i+1) + " " + branch->Child[i]->Mi->Name + "(" + sads + ")"));
				}
			}
		}
	}
}

void AddLang(Tree *branch, int t) {
	std::queue <Tree*> O;
	O.push(branch);
	while (!O.empty()) {
		Tree* currentBranch = O.front();
		O.pop();
		if (currentBranch->Child != NULL) {
			if (!currentBranch->Repeated) {
				for (int i = 0; i < t; i++) {
					if (currentBranch->Child[i] != NULL) {
						Form3->ListBox1->Items->Add(currentBranch->Child[i]->Lang);
						O.push(currentBranch->Child[i]);
					}
				}
			}
			else {
				if (currentBranch->Child[0]->Child != NULL) {
					for (int i = 0; i < t; i++) {
						if (currentBranch->Child[0]->Child[i] != NULL) {
							Form3->ListBox1->Items->Add(currentBranch->Child[0]->Child[i]->Lang);
							O.push(currentBranch->Child[0]->Child[i]);
						}
					}
				}
			}
		}
	}
}

class SizeTree {
	public:
		int Height;
		int MaxChildWidth;
		SizeTree **Child;
		SizeTree() {
			Height = 0;
			MaxChildWidth = 0;
			Child = NULL;
		}
		~SizeTree() {
			if (Child != NULL) {
				for (unsigned int i = 0; i < sizeof(Child) / sizeof(Child[0]); i++) {
					if (Child[i] != NULL) {
						delete Child[i];
					}
				}
				delete[] Child;
			}
		}
};

const int SpaceWidth = 20;
const int SpaceHeight = 5;

void GenerateSizeTree(SizeTree *stree, Tree *branch, int p, int t, TCanvas *c) {
	if (branch->Child != NULL && !branch->Repeated) {
		stree->Child = new SizeTree*[t];
		int MaxChildWidth = 0;
		int Count = 0;
		for (int i = 0; i < t; i++) {
			if (branch->Child[i] != NULL) {
				stree->Child[i] = new SizeTree;
				AnsiString str = "";
				for (int k = 0; k < p; k++) {
					if (k != p - 1) {
						str += IntToStr(branch->Child[i]->Mi->m[k]) + ",";
					}
					else {
						str += IntToStr(branch->Child[i]->Mi->m[k]);
					}
				}

				if (branch->Child[i]->Repeated) {
					str="t" + IntToStr(i+1) + " " + branch->Child[i]->Mi->Name + "(" + str + ") Повтор";
				}
				else {
					str="t" + IntToStr(i+1) + " " + branch->Child[i]->Mi->Name + "(" + str + ")";
				}
				stree->Child[i]->Height = c->TextHeight(str);
				if (c->TextWidth(str) + 2 * SpaceWidth > MaxChildWidth) {
					MaxChildWidth = c->TextWidth(str) + 2 * SpaceWidth;
				}
				Count++;
				GenerateSizeTree(stree->Child[i], branch->Child[i], p, t, c);
				stree->Height += stree->Child[i]->Height + SpaceHeight;
			}
		}
		if (Count == 1) {
			stree->Height -= 13 + SpaceHeight;
		}
		stree->MaxChildWidth = MaxChildWidth;
	}
}

int Round(double d) {
	int r = (int)(d + 0.5);
	if (r % 2 && r==d + 0.5) {
		r--;
	}
	return r;
}

void DrawArrow(TPoint P1, TPoint P2, TCanvas *c) {
	c->MoveTo(P1.x, P1.y);
	c->LineTo(P2.x, P2.y);
	double Angle = 180.0 * atan2(P2.y - P1.y, P2.x - P1.x) / M_PI;
	TPoint P3 = TPoint(P2.x + Round(15.0 * cos(M_PI * (Angle + 150.0) / 180.0)), P2.y + Round(15.0 * sin(M_PI * (Angle + 150.0) / 180.0)));
	TPoint P4 = TPoint(P2.x + Round(15.0 * cos(M_PI * (Angle - 150.0) / 180.0)), P2.y + Round(15.0 * sin(M_PI * (Angle - 150.0) / 180.0)));
	c->MoveTo(P2.x, P2.y);
	c->LineTo(P3.x, P3.y);
	c->MoveTo(P2.x, P2.y);
	c->LineTo(P4.x, P4.y);
}

void DrawTree(SizeTree *stree, Tree* branch, int p, int t, int left, int top, TPoint arrowFrom) {
	if (branch->Child != NULL && !branch->Repeated) {
		for (int i = 0; i < t; i++) {
			if (branch->Child[i] != NULL) {
				AnsiString str = "";
				for (int k = 0; k < p; k++) {
					if (k != p - 1) {
						str += IntToStr(branch->Child[i]->Mi->m[k]) + ",";
					}
					else {
						str += IntToStr(branch->Child[i]->Mi->m[k]);
					}
				}
				if (branch->Child[i]->Repeated) {
					str="t" + IntToStr(i+1) + " " + branch->Child[i]->Mi->Name + "(" + str + ") Повтор";
				}
				else {
					str="t" + IntToStr(i+1) + " " + branch->Child[i]->Mi->Name + "(" + str + ")";
				}
				if (left + stree->MaxChildWidth > Form4->Image1->Width) {
					Form4->Image1->Width = left + stree->MaxChildWidth + SpaceWidth;
					Form4->Image1->Picture->Bitmap->Width = Form4->Image1->Width;
				}
				if (top + 17 > Form4->Image1->Height) {
					Form4->Image1->Height = top + 17 + SpaceHeight;
					Form4->Image1->Picture->Bitmap->Height = Form4->Image1->Height;
				}
				Form4->Image1->Canvas->Pen->Color = clBlack;
				DrawArrow(arrowFrom, TPoint(left - 2, top + (stree->Child[i]->Height / 2) + 2), Form4->Image1->Canvas);
				bool dEnd = false;
				if (branch->Child[i]->Child != NULL) {
					dEnd = true;
					for (int k = 0; k < t; k++) {
						if (branch->Child[i]->Child[k] != NULL) {
							dEnd = false;
						}
					}
				}
				if (dEnd) {
					Form4->Image1->Canvas->Pen->Color = StringToColor("0x0000ff");
				}
				if (branch->Child[i]->Repeated) {
					Form4->Image1->Canvas->Pen->Color = StringToColor("0xff00ff");
				}
				Form4->Image1->Canvas->Rectangle(left - 2, top + (stree->Child[i]->Height / 2) - (Form4->Image1->Canvas->TextHeight(str) / 2)-1, left + Form4->Image1->Canvas->TextWidth(str) + 2, top + (stree->Child[i]->Height / 2) + (Form4->Image1->Canvas->TextHeight(str) / 2) + 3);
				Form4->Image1->Canvas->TextOutA(left, top + (stree->Child[i]->Height / 2) - (Form4->Image1->Canvas->TextHeight(str) / 2), str);
				DrawTree(stree->Child[i], branch->Child[i], p, t, left + stree->MaxChildWidth + SpaceWidth, top, TPoint(left + Form4->Image1->Canvas->TextWidth(str) + 2, top + (stree->Child[i]->Height / 2) + 2));
				top += stree->Child[i]->Height + 4 + SpaceHeight;
			}
		}
	}
}

void GeneratePicture(Tree *branch, int p, int t) {
	SizeTree *root = new SizeTree();
	AnsiString str = "";
	for (int k = 0; k < p; k++) {
		if (k != p - 1) {
			str += IntToStr(branch->Mi->m[k]) + ",";
		}
		else {
			str += IntToStr(branch->Mi->m[k]);
		}
	}
	str = "M0(" + str + ")";
	root->Height = Form4->Image1->Canvas->TextHeight(str) + 2*SpaceHeight;
	GenerateSizeTree(root, branch, p, t, Form4->Image1->Canvas);
	Form4->Position = poMainFormCenter;
	Form4->Show();
	Form4->Image1->Canvas->Brush->Color = clWhite;
	Form4->Image1->Canvas->Pen->Color = clBlack;
	if (root->Height < 55) {
		root->Height = 55;
	}
	Form4->Image1->Height = root->Height;
	Form4->Image1->Width = Form4->Image1->Canvas->TextWidth(str) + 2*SpaceWidth;
	Form4->Image1->Picture->Bitmap->Height = Form4->Image1->Height;
	Form4->Image1->Picture->Bitmap->Width = Form4->Image1->Width;
	Form4->Image1->Canvas->Rectangle(-1, -1, Form4->Image1->Width + 1, Form4->Image1->Height + 1);
	Form4->Image1->Canvas->Rectangle(SpaceWidth-2, (root->Height / 2) - (Form4->Image1->Canvas->TextHeight(str) / 2) - 1, SpaceWidth + Form4->Image1->Canvas->TextWidth(str) + 2, (root->Height / 2) + (Form4->Image1->Canvas->TextHeight(str) / 2) + 3);
	Form4->Image1->Canvas->TextOutA(SpaceWidth, (root->Height / 2) - (Form4->Image1->Canvas->TextHeight(str) / 2), str);
	DrawTree(root, branch, p, t, 4 * SpaceWidth + Form4->Image1->Canvas->TextWidth(str) + 3, SpaceHeight, TPoint(SpaceWidth + Form4->Image1->Canvas->TextWidth(str) + 2, (root->Height / 2) + 2));
	TPoint Pos;
	Pos.x = Form4->Image1->Width + 5;
	Pos.y = (Form4->Image1->Height - 45) / 2;
	Form4->Image1->Width += 35 + Form4->Image1->Canvas->TextWidth("Повтор");
	Form4->Image1->Picture->Bitmap->Width = Form4->Image1->Width;
	Form4->Image1->Canvas->Brush->Color = StringToColor("0x0000ff");
	Form4->Image1->Canvas->Pen->Color = StringToColor("0x0000ff");
	Form4->Image1->Canvas->Rectangle(Pos.x, Pos.y, Pos.x + 20, Pos.y + 20);
	Form4->Image1->Canvas->Brush->Color = clWhite;
	Form4->Image1->Canvas->TextOutA(Pos.x + 25, Pos.y + 10 - Form4->Image1->Canvas->TextHeight("Тупик")/2, "Тупик");
	Form4->Image1->Canvas->Brush->Color = StringToColor("0xff00ff");
	Form4->Image1->Canvas->Pen->Color = StringToColor("0xff00ff");
	Form4->Image1->Canvas->Rectangle(Pos.x, Pos.y + 25, Pos.x + 20, Pos.y + 45);
	Form4->Image1->Canvas->Brush->Color = clWhite;
	Form4->Image1->Canvas->TextOutA(Pos.x + 25, Pos.y + 35 - Form4->Image1->Canvas->TextHeight("Повтор")/2, "Повтор");
	delete root;	
}

void __fastcall TForm1::Button2Click(TObject *Sender)
{
	int p = StringGrid1->RowCount - 2;
	int t = StringGrid1->ColCount - 2;
	int **Fp = new int*[p];
	for (int i = 0; i < p; i++) {
		Fp[i] = new int[t];
	}
	int **Ft = new int*[t];
	for (int i = 0; i < t; i++) {
		Ft[i] = new int[p];
	}
	int **Fi = new int*[p];
	for (int i = 0; i < p; i++) {
		Fi[i] = new int[t];
	}
	int *M0 = new int[p];
	for (int i = 0; i < p; i++) {
		for (int j = 0; j < t; j++) {
			if (!TryStrToInt(StringGrid1->Cells[j + 1][i + 1], Fp[i][j])) {
				Fp[i][j] = 0;
			}
			if (!TryStrToInt(StringGrid2->Cells[i + 1][j + 1], Ft[j][i])) {
				Ft[j][i] = 0;
			}
			if (!TryStrToInt(StringGrid3->Cells[j + 1][i + 1], Fi[i][j])) {
				Fi[i][j] = 0;
			}
		}
		if (!TryStrToInt(Form2->StringGrid1->Cells[i][1], M0[i])) {
			M0[i] = 0;
		}
	}

	Mn.clear();
	Mn.push_back(new Marking("M0", M0));
	Tree *root = new Tree();
	root->Mi = Mn.front();
	TreeFind(root, Value, Fp, Ft, Fi, p, t);
	AnsiString sads = "";
	for (int i = 0; i < p; i++) {
		if (i != p - 1) {
			sads += IntToStr(root->Mi->m[i]) + ",";
		}
		else {
			sads += IntToStr(root->Mi->m[i]);
		}
	}
	Form3->ListBox1->Items->Clear();
	if (CheckBox2->Checked) {
		Form3->ListBox1->Enabled = true;
		Form3->GroupBox2->Enabled = true;
		Form3->ListBox1->Items->Add(char(108));
		AddLang(root, t);
	}
	else {
		Form3->ListBox1->Enabled = false;
		Form3->GroupBox2->Enabled = false;
	}
	Form3->TreeView1->Items->Clear();
	Form3->TreeView1->Items->Add(NULL, root->Mi->Name + "(" + sads + ")");
	AddTree(root, p, t, Form3->TreeView1->Items->Item[0]);
	Form3->Position = poMainFormCenter;
	Form3->Show();
	GeneratePicture(root, p, t);
	for (int i = 0; i < p; i++) {
		delete[] Fp[i];
	}
	delete[] Fp;
	for (int i = 0; i < t; i++) {
		delete[] Ft[i];
	}
	delete[] Ft;
	for (int i = 0; i < p; i++) {
		delete[] Fi[i];
	}
	delete[] Fi;
	delete M0;
	while (!Mn.empty()) {
		delete Mn.front();
		Mn.pop_front();
	}
	delete root;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
	RemoveFontResource("MyFont.otf");
}
//---------------------------------------------------------------------------

