//========================================================================
//! @file       Main.cpp
//{=======================================================================
//!
//! @brief      <���������>\n
//! @brief      <������������>
//!
//! @version    [Version 0.01 alpha, build 1]
//! @author     Copyright (C) <�����>, <���> (<���> <�����>)
//! @date       <����>
//!
//! @par        ��������������
//!           - (TODO: ������ ��������)
//!
//! @todo     - (TODO: ������ ��������� ������ �� ����� �����)
//!
//! @bug      - (TODO: ������ ��������� ������ � ���� �����)
//!
//! @par        ������� ��������� �����
//!           - ������ 0.01 Alpha
//!             - ������ ��� ��������� ����
//!
//}=======================================================================

#include "TXLib.h"
struct Platforma
{
int x;
int y;
int w;
int h;
HDC image;

void draw()
     {
     txTransparentBlt(txDC(),x,y,w,h,image,0,0,TX_WHITE);

     }

};
struct Player
{
int x;
int y;
int w;
int h;
HDC image;

void draw()
     {
     txTransparentBlt(txDC(),x,y,w,h,image,0,0,RGB(12,184,220));

     }

};


int main()
{
txCreateWindow (1350, 700);
HDC fon = txLoadImage("fon.bmp");
txBitBlt(txDC(),0,0,1350,700,fon);
Platforma platforma1 = {-160,550,400,200,txLoadImage("Platforma.bmp")};
platforma1.draw();
Player player1 = {50,450,200,140,txLoadImage("TestChelik3.bmp")};
player1.draw();

txTextCursor (false);
txDeleteDC(platforma1.image);
txDeleteDC(player1.image);
txDeleteDC(fon);
return 0;
}

