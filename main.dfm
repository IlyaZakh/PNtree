object Form1: TForm1
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = 'PNtree'
  ClientHeight = 433
  ClientWidth = 713
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 8
    Width = 23
    Height = 23
    Caption = 'F :'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 20
    Top = 6
    Width = 6
    Height = 13
    Caption = 'P'
  end
  object Label3: TLabel
    Left = 361
    Top = 8
    Width = 23
    Height = 23
    Caption = 'F :'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label4: TLabel
    Left = 373
    Top = 6
    Width = 4
    Height = 13
    Caption = 't'
  end
  object Label5: TLabel
    Left = 8
    Top = 388
    Width = 82
    Height = 13
    Caption = #1043#1083#1091#1073#1080#1085#1072' '#1076#1077#1088#1077#1074#1072
  end
  object Label7: TLabel
    Left = 713
    Top = 8
    Width = 23
    Height = 23
    Caption = 'F :'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    Visible = False
  end
  object Label6: TLabel
    Left = 727
    Top = 6
    Width = 2
    Height = 13
    Caption = 'i'
    Visible = False
  end
  object StringGrid1: TStringGrid
    Left = 8
    Top = 37
    Width = 345
    Height = 345
    ColCount = 3
    DefaultColWidth = 22
    DefaultRowHeight = 22
    RowCount = 3
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing]
    TabOrder = 0
    OnContextPopup = ContextPopupDisable
    OnDrawCell = StringGridDrawCell
    OnKeyPress = StringGridKeyPress
    OnSetEditText = StringGridSetEditText
  end
  object StringGrid2: TStringGrid
    Left = 361
    Top = 37
    Width = 345
    Height = 345
    ColCount = 3
    DefaultColWidth = 22
    DefaultRowHeight = 22
    RowCount = 3
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing]
    TabOrder = 1
    OnContextPopup = ContextPopupDisable
    OnDrawCell = StringGridDrawCell
    OnKeyPress = StringGridKeyPress
    OnSetEditText = StringGridSetEditText
  end
  object Button1: TButton
    Left = 360
    Top = 390
    Width = 178
    Height = 35
    Caption = #1047#1072#1076#1072#1090#1100' '#1085#1072#1095#1072#1083#1100#1085#1091#1102' '#1088#1072#1079#1084#1077#1090#1082#1091
    TabOrder = 2
    OnClick = Button1Click
  end
  object Edit1: TEdit
    Left = 8
    Top = 407
    Width = 81
    Height = 21
    TabOrder = 3
    Text = '2'
    OnChange = Edit1Change
    OnContextPopup = ContextPopupDisable
    OnKeyPress = Edit1KeyPress
  end
  object UpDown1: TUpDown
    Left = 89
    Top = 407
    Width = 16
    Height = 21
    Associate = Edit1
    Min = 2
    Max = 16
    Position = 2
    TabOrder = 4
  end
  object StringGrid3: TStringGrid
    Left = 713
    Top = 37
    Width = 345
    Height = 345
    ColCount = 3
    DefaultColWidth = 22
    DefaultRowHeight = 22
    RowCount = 3
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing]
    TabOrder = 5
    Visible = False
    OnContextPopup = ContextPopupDisable
    OnDrawCell = StringGridDrawCell
    OnKeyPress = StringGridKeyPress
    OnSetEditText = StringGridSetEditText
  end
  object CheckBox1: TCheckBox
    Left = 120
    Top = 388
    Width = 121
    Height = 17
    Caption = #1048#1085#1075#1080#1073#1080#1090#1086#1088#1085#1072#1103' '#1089#1077#1090#1100
    TabOrder = 6
    OnClick = CheckBox1Click
  end
  object Button2: TButton
    Left = 544
    Top = 390
    Width = 158
    Height = 35
    Caption = #1057#1075#1077#1085#1077#1088#1080#1088#1086#1074#1072#1090#1100' '#1076#1077#1088#1077#1074#1086
    TabOrder = 7
    OnClick = Button2Click
  end
  object CheckBox2: TCheckBox
    Left = 120
    Top = 411
    Width = 225
    Height = 17
    Caption = #1043#1077#1085#1077#1088#1080#1088#1086#1074#1072#1090#1100' '#1089#1083#1086#1074#1072#1088#1100' PN ('#1084#1077#1076#1083#1077#1085#1085#1077#1077')'
    TabOrder = 8
  end
  object XPManifest1: TXPManifest
    Left = 680
    Top = 8
  end
end
