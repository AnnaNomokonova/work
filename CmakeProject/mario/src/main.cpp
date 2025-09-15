#include <stdio.h>
#include <stdlib.h>
 
#include <math.h>
#include <curses.h>

#define mapWidth 80
#define mapHeight 25

typedef struct SObject {
    float x,y;
    float width, height;
    float vertSpeed;
    bool IsFly;
}  TObject;


char map[mapHeight][mapWidth+1];
TObject mario;

void clearMap ()
{ 
    for (int i = 0; i < mapWidth; i++)
        map[0][i] =  '.';
    map[0][mapWidth] = '\0';
    for (int j = 1; j < mapHeight; j++)
        sprintf ( map[j], map[0]);

}

void ShowMap ()
{
    map[mapHeight - 1][mapWidth - 1 ] = '\0';
    for ( int j = 0 ; j < mapHeight; j++)   
        printw( map[j]);   
}
void SetObjectPos(TObject *obj, float xPos, float yPos)
{
    (*obj).x = xPos;
    (*obj).y = yPos;
}
void HorizonMoveMap( float dx)
{
    mario.x -= dx;
    void HorizonMoveMap( float dx);
}
void InitObject(TObject *obj, float xPos, float yPos, float oWidth, float oHeight )
{
    SetObjectPos(obj, xPos, yPos);
    (*obj).width = oWidth;
    (*obj).height = oHeight;
    (*obj).vertSpeed = 0;
}
void VertMoveObjectOnMap(TObject *obj)
{
    (*obj).vertSpeed += 0.05;
    SetObjectPos(obj, (*obj).x, (*obj).y + (*obj).vertSpeed );
}
bool IsPosInMap ( int x, int y)
{
    return( (x >= 0) && (x < mapWidth) && (y >= 0) && (y < mapHeight));
}
void PutObjectOnMap( TObject obj)
{
    int ix = (int)round(obj.x);
    int iy = (int)round(obj.y);
    int iWidth = (int)round(obj.width);
    int iHeight = (int)round(obj.height);
    for (int i = ix; i < (ix + iWidth); i++)
        for (int j = iy; j < (iy + iHeight); j++)
            if (IsPosInMap(i,j))
            {
                map[j][i] = '@';
                
            }
}

int main()
{
    initscr();
    curs_set(0);
    noecho();
    nodelay(stdscr, TRUE);

    InitObject(&mario, 39, 10, 3, 3);
    int key = -1;

    do
    {
          clearMap();
          VertMoveObjectOnMap(&mario);
          PutObjectOnMap(mario);

          ShowMap(); 

          key = getch();

        //   if (mario.IsFly == FALSE && key ==(int) ' ') mario.vertSpeed = -1;
          if (key ==(int) ' ') mario.vertSpeed = -1;
          if (key == (int) 'a') HorizonMoveMap(1);
          if (key == (int) 'd') HorizonMoveMap(-1);
          

          move(0,0);
          napms(300);

    } while (key != 27);

    endwin();


   



return 0;
}