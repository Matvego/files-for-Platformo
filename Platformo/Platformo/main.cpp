//========================================================================
#include "TXLib.h"

struct Platforma
{
int x;
int y;
int w;
int h;
HDC image;
bool dvig;
bool spike;
bool revers;
int level;
int level1;
int w_screen;
int h_screen;

void draw()
     {
     Win32::TransparentBlt(txDC(),x,y,w_screen,h_screen,image,0,0,w,h,TX_WHITE);

     }

};

struct Player
{
int x;
int y;
int w;
int h;
HDC image;
HDC image_R;
HDC image_L;
HDC image_Jump_R;
HDC image_Jump_L;
int n_cadr;

void draw()
     {
     txTransparentBlt(txDC(),x,y,w,h,image,200*n_cadr,0,RGB(12,184,220));

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

struct Vrag1
{
int x;
int y;
int w;
int h;
int vx;
HDC image;
HDC image_R;
HDC image_L;
int n_cadr;

void draw()
     {
     txTransparentBlt(txDC(),x,y,w,h,image,50*n_cadr,0,TX_WHITE);

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




int change_gamelevel(Platforma platforma[], int gamelevel)
{
    int count_platform;
    if (gamelevel == 1)
    {
        count_platform = 3;
        platforma[0] = {-160,550,400,200,txLoadImage("Platforma.bmp"), 0,0,0, platforma[0].y,platforma[0].y,400,200};
        platforma[1] = {1160,130,400,200,txLoadImage("Platforma.bmp"), 0,0,0, platforma[1].y,platforma[1].y,400,200};
        platforma[2] = {400,550,400,200,txLoadImage("PlatformaDvig.bmp"), 1,0,0, platforma[2].y,platforma[2].y,200,100};
    }

    else if (gamelevel == 2)
    {
        count_platform = 6 ;
        platforma[0] = {-180,130,400,200,txLoadImage("Platforma.bmp"), 0,0,0, platforma[0].y,platforma[0].y,400,200};
        platforma[1] = {300,130,400,200,txLoadImage("Platforma.bmp"), 0, false,0, platforma[1].y,platforma[1].y,200,100};
        platforma[2] = {600,30,200,400,txLoadImage("PlatformaDvigVerticSpike.bmp"), 1,1,0, platforma[2].y,platforma[2].y, 100, 200};
        platforma[3] = {500,350,400,200,txLoadImage("PlatformaSpike.bmp"), 0,1,0, platforma[3].y,platforma[3].y,300,150};
        platforma[4] = {700,550,400,200,txLoadImage("Platforma.bmp"), 0, false,0, platforma[4].y,platforma[4].y,200,100};
        platforma[5] = {1160,550,400,200,txLoadImage("Platforma.bmp"), 0,0,0, platforma[5].y,platforma[5].y,400,200};
    }

    else if (gamelevel == 3)
    {
        count_platform = 5 ;
        platforma[0] = {-180,550,400,200,txLoadImage("Platforma.bmp"), 0,0,0, platforma[0].y,platforma[0].y,400,200};
        platforma[1] = {230,110,400,200,txLoadImage("PlatformaDvig.bmp"), 1, 0,0, platforma[1].y,platforma[1].y,200,100};
        platforma[2] = {500,100,400,200,txLoadImage("PlatformaSpikeRevers.bmp"), 0,0,1, platforma[2].y,platforma[2].y, 300, 150};
        platforma[3] = {500,500,400,200,txLoadImage("PlatformaSpike.bmp"), 0,1,0, platforma[3].y,platforma[3].y,300,150};
        platforma[4] = {1160,150,400,200,txLoadImage("PlatformaFinish.bmp"), 0, 0,0, platforma[4].y,platforma[4].y,400,200};

    }

    else if (gamelevel == 4)
    {
        count_platform = 4 ;
        platforma[0] = {-180,550,400,200,txLoadImage("Platforma.bmp"), 0,0,0, platforma[0].y,platforma[0].y,400,200};
        platforma[1] = {500,350,400,200,txLoadImage("PlatformaDvig.bmp"), 1, 0,0, platforma[1].y,platforma[1].y,200,100};
        platforma[2] = {850,250,200,400,txLoadImage("PlatformaVerticSpike.bmp"), 0,1,0, platforma[2].y,platforma[2].y, 100, 200};
        platforma[3] = {1160,550,400,200,txLoadImage("Platforma.bmp"), 0,0,0, platforma[3].y,platforma[3].y,400,200};
    }

    else if (gamelevel == 5)
    {
        count_platform = 6 ;
        platforma[0] = {-180,550,400,200,txLoadImage("Platforma.bmp"), 0,0,0, platforma[0].y,platforma[0].y,400,200};
        platforma[1] = {400,350,400,200,txLoadImage("PlatformaDvig.bmp"), 1, 0,0, platforma[1].y,platforma[1].y,200,100};
        platforma[2] = {650,200,200,400,txLoadImage("PlatformaVerticSpike.bmp"), 0,1,0, platforma[2].y,platforma[2].y, 100, 200};
        platforma[3] = {250,150,200,400,txLoadImage("PlatformaVerticSpike1.bmp"), 0,1,0, platforma[3].y,platforma[3].y,100,200};
        platforma[4] = {850,150,400,200,txLoadImage("Platforma.bmp"), 0,0,0, platforma[4].y,platforma[4].y,200,100};
        platforma[5] = {1160,150,400,200,txLoadImage("Platforma.bmp"), 0,0,0, platforma[5].y,platforma[5].y,400,200};

    }

    else if (gamelevel == 6)
    {
        count_platform = 6 ;
        platforma[0] = {-180,150,400,200,txLoadImage("Platforma.bmp"), 0,0,0, platforma[0].y,platforma[0].y,400,200};
        platforma[1] = {250,550,400,200,txLoadImage("PlatformaDvig.bmp"), 1, 0,0, platforma[1].y,platforma[1].y,200,100};
        platforma[2] = {650,300,200,400,txLoadImage("PlatformaVerticSpike.bmp"), 0,1,0, platforma[2].y,platforma[2].y, 200, 400};
        platforma[3] = {1100,300,400,200,txLoadImage("PlatformaSpike.bmp"), 0,1,0, platforma[3].y,platforma[3].y,400,200};
        platforma[4] = {950,550,400,200,txLoadImage("Platforma.bmp"), 0,0,0, platforma[4].y,platforma[4].y,200,100};
        platforma[5] = {1200,600,400,200,txLoadImage("Platforma.bmp"), 0,0,0, platforma[5].y,platforma[5].y,400,200};

    }

    else if (gamelevel == 7)
    {
        count_platform = 5 ;
        platforma[0] = {-50,550,400,200,txLoadImage("Platforma.bmp"), 0,0,0, platforma[0].y,platforma[0].y,200,100};
        platforma[1] = {300,550,400,200,txLoadImage("Platforma.bmp"), 0, 0,0, platforma[1].y,platforma[1].y,200,100};
        platforma[2] = {570,550,400,200,txLoadImage("PlatformaDvig.bmp"), 1,0,0, platforma[2].y,platforma[2].y, 200, 100};
        platforma[3] = {850,550,400,200,txLoadImage("Platforma.bmp"), 0,0,0, platforma[3].y,platforma[3].y,200,100};
        platforma[4] = {1250,550,400,200,txLoadImage("Platforma.bmp"), 0,0,0, platforma[4].y,platforma[4].y,200,100};


    }


    return count_platform;
}

int main()
{
txCreateWindow (1350, 700);
txTextCursor (false);
HDC fon = txLoadImage("fon.bmp");
int gamelevel = 1;


Platforma platforma[100];
int count_platform = change_gamelevel(platforma, gamelevel);

Player player1 = {50,340,200,140,   txLoadImage("AnimathionGlavPersaR.bmp"),
                            txLoadImage("AnimathionGlavPersaR.bmp"),
                            txLoadImage("AnimathionGlavPersaL.bmp"),
                            txLoadImage("GlavPersJumpAnimathionR.bmp"),
                            txLoadImage("GlavPersJumpAnimathionL.bmp"),0};
Vrag1 vrag1 = {600,250,50,50,5, txLoadImage("AnimathionVrag1R.bmp"),
                            txLoadImage("AnimathionVrag1R.bmp"),
                            txLoadImage("AnimathionVrag1L.bmp"),0};

char str[50];

   while(!GetAsyncKeyState(VK_ESCAPE))
   {
      txClear();
      txBegin();
      txBitBlt(txDC(),0,0,1350,700,fon);
      player1.draw();

      if (gamelevel == 7)
      {
        vrag1.draw();
        vrag1.vx += 5;
        vrag1.image = vrag1.image_R;
        vrag1.animathion();

      }
      /*
      sprintf(str, "%d", count_platform);
      txTextOut(0, 0, str);   */

      for(int i=0; i<count_platform; i++)
      {
          platforma[i].draw();
      }

      if(GetAsyncKeyState(VK_RIGHT))
      {
        player1.x += 50;
        player1.image = player1.image_R;
        player1.animathion();
      }





      for(int i=0; i<count_platform; i++)
      {
          if(GetAsyncKeyState('D') && platforma[i].dvig)
          {
              platforma[i].x += 20;
          }
          else if(GetAsyncKeyState('A') && platforma[i].dvig)
          {
              platforma[i].x -= 20;
          }
          else if(GetAsyncKeyState('W') && platforma[i].dvig)
          {
              platforma[i].y -= 20;
          }
          else if(GetAsyncKeyState('S') && platforma[i].dvig)
          {
              platforma[i].y += 20;
          }
      }


      if(GetAsyncKeyState(VK_LEFT))
      {
        player1.x -= 50;
        player1.image = player1.image_L;
        player1.animathion();
      }



      for(int i=0; i<count_platform; i++)
      {
          if (GetAsyncKeyState(VK_SPACE) && player1.y+player1.h >= platforma[i].y)
          {
             player1.y -= 130;
             while (GetAsyncKeyState(VK_SPACE))
                {
                    txSleep(15);
                }
             if (player1.image == player1.image_R)
             player1.image = player1.image_Jump_R;
             if (player1.image == player1.image_L)
             player1.image = player1.image_Jump_L;
             player1.animathion();

           }
      }

       player1.y += 25;

       for(int i=0; i<count_platform; i++)
       {
           if (player1.y > platforma[i].level)
           {
                player1.y = platforma[i].level;
                player1.image = player1.image;
           }
       }

       for(int i=0; i<count_platform; i++)
       {
           if (!platforma[i].spike && player1.x+100>platforma[i].x && player1.x+player1.w-100<platforma[i].x+platforma[i].w_screen && player1.y<platforma[i].y && player1.y+player1.h>platforma[i].y)
           {
             platforma[i].level = platforma[i].y-120;
           }
           else platforma[i].level = 1000;

       }

       for(int i=0; i<count_platform; i++)
       {
           if (platforma[i].spike && player1.x+100 > platforma[i].x && player1.x+player1.w-100 < platforma[i].x+platforma[i].w_screen && player1.y<platforma[i].y && player1.y+player1.h>platforma[i].y)
           {
             player1.x = 0;
             player1.y = 0;
           }
       }

       for(int i=0; i<count_platform; i++)
       {
           if (platforma[i].revers && player1.x+100 > platforma[i].x && player1.x+player1.w-100 < platforma[i].x+platforma[i].w_screen && player1.y-player1.h+40<platforma[i].y
           && player1.y>platforma[i].y)
           {
             player1.x = 0;
             player1.y = 0;
           }
       }

       if(player1.x+100>1350)
       {
           player1.x = 10;
           gamelevel ++;
           count_platform = change_gamelevel(platforma, gamelevel);
       }


       vrag1.y += 25;
       for(int i=0; i<count_platform; i++)
       {
           if (vrag1.y > platforma[2].level1)
           {
                vrag1.y = platforma[2].level1;
                vrag1.image = vrag1.image;
           }
       }

       //for(int i=0; i<count_platform; i++)
       {
           if (!platforma[2].spike && vrag1.x+100>platforma[2].x && vrag1.x+vrag1.w-50<platforma[2].x+platforma[2].w_screen && vrag1.y<platforma[2].y && vrag1.y+vrag1.h>platforma[2].y)
           {
             platforma[2].level1 = platforma[2].y-40;
           }
           else platforma[2].level1 = 1000;
       }

       if(vrag1.x<platforma[2].x)
       {
        vrag1.vx = -vrag1.vx;
        vrag1.image = vrag1.image_L;
        vrag1.animathion();
       }
       if(vrag1.x+vrag1.w-50>platforma[2].x+platforma[2].w_screen)
       {
        vrag1.vx = -vrag1.vx;
        vrag1.image = vrag1.image_R;
        vrag1.animathion();
       }




     txEnd();
     txSleep(50);
   }


for(int i=0; i<count_platform; i++)
{
    //txDeleteDC(platforma[i].image);
}
//txDeleteDC(player1.image);
txDeleteDC(player1.image_R);
txDeleteDC(player1.image_L);
txDeleteDC(player1.image_Jump_R);
txDeleteDC(player1.image_Jump_L);
txDeleteDC(fon);
return 0;
}

