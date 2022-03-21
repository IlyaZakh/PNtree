object Form3: TForm3
  Left = 0
  Top = 0
  BorderStyle = bsToolWindow
  Caption = #1044#1077#1088#1077#1074#1086' '#1080' '#1089#1083#1086#1074#1072#1088#1100' '#1089#1074#1086#1073#1086#1076#1085#1086#1075#1086' '#1103#1079#1099#1082#1072' PN'
  ClientHeight = 465
  ClientWidth = 891
  Color = clBtnFace
  Constraints.MaxWidth = 897
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
  object Splitter1: TSplitter
    Left = 681
    Top = 0
    Height = 465
    MinSize = 150
    ExplicitLeft = 672
    ExplicitTop = 296
    ExplicitHeight = 100
  end
  object GroupBox1: TGroupBox
    Left = 0
    Top = 0
    Width = 681
    Height = 465
    Align = alLeft
    Caption = #1044#1077#1088#1077#1074#1086
    Constraints.MinWidth = 150
    TabOrder = 0
    object TreeView1: TTreeView
      Left = 2
      Top = 15
      Width = 677
      Height = 448
      Align = alClient
      Indent = 19
      TabOrder = 0
    end
  end
  object GroupBox2: TGroupBox
    Left = 684
    Top = 0
    Width = 207
    Height = 465
    Align = alClient
    Caption = #1057#1083#1086#1074#1072#1088#1100' '#1089#1074#1086#1073#1086#1076#1085#1086#1075#1086' '#1103#1079#1099#1082#1072' PN'
    TabOrder = 1
    object ListBox1: TListBox
      Left = 2
      Top = 15
      Width = 203
      Height = 448
      Align = alClient
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ItemHeight = 13
      ParentFont = False
      TabOrder = 0
    end
  end
  object XPManifest1: TXPManifest
    Left = 8
    Top = 8
  end
end
