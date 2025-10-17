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
    char cType;
}  TObject;


char map[mapHeight][mapWidth+1];
TObject mario;
TObject *brick = NULL;
int brickLength;


void clearMap ()
{ 
    for (int i = 0; i < mapWidth; i++)
        map[0][i] =  ' ';
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

void InitObject(TObject *obj, float xPos, float yPos, float oWidth, float oHeight, char inType )
{
    SetObjectPos(obj, xPos, yPos);
    (*obj).width = oWidth;
    (*obj).height = oHeight;
    (*obj).vertSpeed = 0;
    (*obj).cType = inType;
}

bool IsCollision(TObject o1, TObject o2);
void CreateLevel();
void VertMoveObjectOnMap(TObject *obj)
{
    (*obj).IsFly = true ; 
    (*obj).vertSpeed += 0.05;
    SetObjectPos(obj, (*obj).x, (*obj).y + (*obj).vertSpeed );
    for (int i = 0; i < brickLength; i++)
        if (IsCollision( *obj, brick[i]))
        {
            (*obj).y -= (*obj).vertSpeed;
            (*obj).vertSpeed = 0;
            (*obj).IsFly = false;
            if (brick[i].cType == '+')
            {
                CreateLevel();
                napms(500);
            }
            break;
        }
}
bool IsPosInMap ( int x, int y)
{
    return( (x >= 0) && (x < mapWidth) && (y >= 0) && (y < mapHeight));
}
void HorizonMoveMap( float dx)
{
    mario.x -= dx;
    for (int i = 0; i < brickLength; i++)
        if (IsCollision(mario, brick[i]))
        {
            mario.x += dx;
            return;
        }
    mario.x += dx;

    for (int i = 0; i < brickLength; i++)
        brick[i].x += dx;
}

bool IsCollision(TObject o1, TObject o2)
{
    return ((o1.x + o1.width) > o2.x) && ( o1.x < ( o2.x +o2.width)) &&
                    ((o1.y + o1.height) > o2.y) && (o1.y < (o2.y + o2.height));
}
void CreateLevel()
{
    InitObject(&mario, 39, 10, 3, 3,'@');

    brickLength = 6;
    //brick =(TObject*) realloc(brick, brickLength);
    brick = new TObject[brickLength];
    InitObject(brick+0, 20, 20, 40, 5, '#');
    InitObject(brick+1, 60, 15, 10, 10, '#');
    InitObject(brick+2, 80, 20, 30, 5, '#');      //30=20
    InitObject(brick+3, 120, 15, 20, 10, '#');    //20=10
    InitObject(brick+4, 150, 20, 40, 5, '#');
    InitObject(brick+5, 200, 15, 10, 1, '+');     //50=10 200=210
    
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
                map[j][i] = obj.cType;
                
            }
}

int main()
{
    initscr();
    curs_set(0);
    noecho();
    nodelay(stdscr, TRUE);

    CreateLevel();
    
    int key = -1;

    do
    {
          clearMap();
          
          key = getch();
          if (mario.IsFly == false && key ==(int) ' ') mario.vertSpeed = -1;
          if (key == (int) 'a') HorizonMoveMap(1);
          if (key == (int) 'd') HorizonMoveMap(-1);

          if (mario.y > mapHeight) CreateLevel();

          VertMoveObjectOnMap(&mario);
          for (int i = 0; i < brickLength; i++)
             PutObjectOnMap(brick[i]);
          PutObjectOnMap(mario);

          ShowMap(); 

          

          move(0,0);
          napms(50);

    } while (key != 27);

    endwin();


   



return 0;
}