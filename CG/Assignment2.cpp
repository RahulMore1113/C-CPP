#include <graphics.h>
#include <iostream>
#include <math.h>
#define PI 3.141592
using namespace std;

class pt
{
protected:
    int xco, yco, color;

public:
    pt()
    {
        xco = 0;
        yco = 0;
        color = 15;
    }
    void setco(int x, int y)
    {
        xco = x;
        yco = y;
    }
    void setcolor(int c)
    {
        color = c;
    }
    void draw()
    {
    }
};
class dline : public pt
{
private:
    int x2, y2;

public:
    dline() : pt()
    {
        x2 = 0, y2 = 0;
    }
    void setline(int x, int y, int xx, int yy)
    {
        pt::setco(x, y);
        x2 = xx;
        y2 = yy;
    }
    void drawl(int color, int xo, int yo)
    {
        float x, y, dx, dy, e, temp;
        int i, s1, s2, ex;
        dx = abs(x2 - xco);
        dy = abs(y2 - yco);
        x = xco;
        y = yco;
        putpixel(x + xo, yo - y, 15);
        if (x2 > xco)
        {
            s1 = 1;
        }
        if (x2 < xco)
        {
            s1 = -1;
        }
        if (x2 == xco)
        {
            s1 = 0;
        }
        if (y2 > yco)
        {
            s2 = 1;
        }
        if (y2 < yco)
        {
            s2 = -1;
        }
        if (y2 == yco)
        {
            s2 = 0;
        }
        if (dy > dx)
        {
            temp = dx;
            dx = dy;
            dy = temp;
            ex = 1;
        }
        else
        {
            ex = 0;
        }
        e = 2 * dy - dx;
        i = 1;
        do
        {
            while (e >= 0)
            {
                if (ex == 1)
                {
                    x = x + s1;
                }
                else
                {
                    y = y + s2;
                }
                e = e - 2 * dx;
            }
            if (ex == 1)
            {
                y = y + s2;
            }
            else
            {
                x = x + s1;
            }
            e = e + 2 * dy;
            putpixel(x + xo, yo - y, 15);
            i = i + 1;
        } while (i <= dx);
    }
};
void FloodFill(int pointx, int pointy, int OldColor, int NewColor)
{
    int Intensity = getpixel(pointx, pointy);
    if (Intensity == OldColor)
    {
        putpixel(pointx, pointy, NewColor);
        FloodFill(pointx + 1, pointy, OldColor, NewColor);
        FloodFill(pointx - 1, pointy, OldColor, NewColor);
        FloodFill(pointx, pointy + 1, OldColor, NewColor);
        FloodFill(pointx, pointy - 1, OldColor, NewColor);
    }
}
void drawchessboard(int xmid, int ymid)
{
    dline l;
    for (int i = 0; i <= 4; i++)
    {
        l.setline(10 + (50 * i), 10, 10 + (50 * i), 210);
        l.drawl(15, xmid, ymid);
        l.setline(10, 10 + (50 * i), 210, 10 + (50 * i));
        l.drawl(15, xmid, ymid);
    }
}
void rotate(int xmid, int ymid)
{
    dline l;
    for (int i = 0; i <= 4; i++)
    {
        float a = cos(45 * PI / 180.0);
        l.setline(10 + (50 * i), 10 * a, 10 + (50 * i), 210 * a);
        l.drawl(15, xmid, ymid);
        l.setline(10, (10 + (50 * i)) * a, 210, (10 + (50 * i)) * a);
        l.drawl(15, xmid, ymid);
    }
}
int main()
{
    int gd, gm;
    gd = DETECT;
    int xmax, ymax, xmid, ymid;
    initgraph(&gd, &gm, NULL);
    xmax = getmaxx();
    ymax = getmaxy();
    xmid = xmax / 2;
    ymid = ymax / 2;
    line(xmid, 0, xmid, ymax);
    line(0, ymid, xmax, ymid);
    drawchessboard(xmid, ymid);
    FloodFill(15 + xmid, ymid - 15, 0, 15);
    FloodFill(15 + xmid + 100, ymid - 15, 0, 15);
    FloodFill(15 + xmid, ymid - (15 + 100), 0, 15);
    FloodFill(15 + xmid + 100, ymid - (15 + 100), 0, 15);
    FloodFill(15 + xmid + 50, ymid - (15 + 50), 0, 15);
    FloodFill(15 + xmid + 150, ymid - (15 + 50), 0, 15);
    FloodFill(15 + xmid + 50, ymid - (15 + 150), 0, 15);
    FloodFill(15 + xmid + 150, ymid - (15 + 150), 0, 15);
    getch();
    cleardevice();
    line(xmid, 0, xmid, ymax);
    line(0, ymid, xmax, ymid);
    rotate(xmid, ymid);
    float a = cos(45 * PI / 180.0);
    FloodFill(15 + xmid, ymid - (15 * a), 0, 15);
    FloodFill(15 + xmid + 100, ymid - (15 * a), 0, 15);
    FloodFill(15 + xmid, ymid - ((15 + 100) * a), 0, 15);
    FloodFill(15 + xmid + 100, ymid - ((15 + 100) * a), 0, 15);
    FloodFill(15 + xmid + 50, ymid - ((15 + 50) * a), 0, 15);
    FloodFill(15 + xmid + 150, ymid - ((15 + 50) * a), 0, 15);
    FloodFill(15 + xmid + 50, ymid - ((15 + 150) * a), 0, 15);
    FloodFill(15 + xmid + 150, ymid - ((15 + 150) * a), 0, 15);
    getch();
    closegraph();
    return 0;
}