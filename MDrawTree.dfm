object Form4: TForm4
  Left = 0
  Top = 0
  Caption = #1044#1077#1088#1077#1074#1086' '#1087#1077#1088#1077#1093#1086#1076#1086#1074' '#1089#1077#1090#1080' '#1055#1077#1090#1088#1080
  ClientHeight = 304
  ClientWidth = 643
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  DesignSize = (
    643
    304)
  PixelsPerInch = 96
  TextHeight = 13
  object ScrollBox1: TScrollBox
    Left = 0
    Top = 0
    Width = 643
    Height = 304
    Align = alClient
    TabOrder = 0
    ExplicitLeft = 264
    ExplicitTop = 128
    ExplicitWidth = 185
    ExplicitHeight = 41
    object Image1: TImage
      Left = 0
      Top = 0
      Width = 105
      Height = 105
    end
  end
  object Button1: TButton
    Left = 8
    Top = 255
    Width = 75
    Height = 25
    Anchors = [akLeft, akBottom]
    Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
    TabOrder = 1
    OnClick = Button1Click
  end
  object XPManifest1: TXPManifest
    Left = 608
    Top = 8
  end
  object SavePictureDialog1: TSavePictureDialog
    Filter = 
      'JPEG Image File (*.jpg)|*.jpg|JPEG Image File (*.jpeg)|*.jpeg|Bi' +
      'tmaps (*.bmp)|*.bmp'
    FilterIndex = 3
    Options = [ofOverwritePrompt, ofHideReadOnly, ofNoNetworkButton, ofEnableSizing]
    Left = 576
    Top = 8
  end
end
