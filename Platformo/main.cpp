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
HDC image;
HDC image_R;
HDC image_L;
HDC image_Jump_R;
HDC image_Jump_L;
int n_cadr;

void draw()
     {
     txTransparentBlt(txDC(),x,y,200,140,image,200*n_cadr,0,RGB(12,184,220));

     }
void animathion()
    {
        n_cadr += 1;
        if (n_cadr >= 5)
         {
           n_cadr = 0;
         }
    }

};


int main()
{
txCreateWindow (1350, 700);
txTextCursor (false);
HDC fon = txLoadImage("fon.bmp");
Platforma platforma1 = {-160,550,400,200,txLoadImage("Platforma.bmp")};
Player player1 = {50,450,   txLoadImage("AnimathionGlavPersaR.bmp"),
                            txLoadImage("AnimathionGlavPersaR.bmp"),
                            txLoadImage("AnimathionGlavPersaL.bmp"),
                            txLoadImage("GlavPersJumpAnimathionR.bmp"),
                            txLoadImage("GlavPersJumpAnimathionL.bmp"),0};

   while(!GetAsyncKeyState(VK_ESCAPE))
   {
      txClear();
      txBegin();
      txBitBlt(txDC(),0,0,1350,700,fon);
      player1.draw();
      platforma1.draw();
      if(GetAsyncKeyState(VK_RIGHT))
      {
        player1.x += 50;
        player1.image = player1.image_R;
        player1.image_Jump_R = player1.image_R;
        player1.animathion();
      }

      if(GetAsyncKeyState(VK_LEFT))
      {
        player1.x -= 50;
        player1.image = player1.image_L;
        player1.image_Jump_L = player1.image_L;
        player1.animathion();
      }


      if (GetAsyncKeyState(VK_SPACE))
      {
         player1.y -= 30;
         player1.image = player1.image_Jump_R;
         player1.image_L = player1.image_Jump_L;
         player1.image_R = player1.image_Jump_R;
         //player1.animathion();



       }
     txEnd();
     txSleep(50);
   }


txDeleteDC(platforma1.image);
txDeleteDC(player1.image);
txDeleteDC(player1.image_R);
txDeleteDC(player1.image_L);
txDeleteDC(player1.image_Jump_R);
txDeleteDC(player1.image_Jump_L);
txDeleteDC(fon);
return 0;
}

