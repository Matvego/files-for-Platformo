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

int main()
{
txCreateWindow (1350, 700);
Platforma platforma1 = {-125,600,300,100,txLoadImage("Platforma.bmp")};
platforma1.draw();


txTextCursor (false);
txDeleteDC(platforma1.image);
return 0;
}

