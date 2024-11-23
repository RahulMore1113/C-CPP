#include <iostream>
#include <conio.h>
#include <cstdlib>
using namespace std;

class Ball
{
public:
    virtual void move(char direction) = 0;
    virtual void display() = 0;
};

class BouncingBall : public Ball
{
private:
    int x, y;

public:
    BouncingBall() : x(5), y(5) {}
    void move(char direction) override
    {
        switch (direction)
        {
        case 'w':
            y--;
            break;
        case 's':
            y++;
            break;
        case 'a':
            x--;
            break;
        case 'd':
            x++;
            break;
        }
    }
    void display() override
    {
        cout << "Bouncing Ball at (" << x << ", " << y << ")\n";
    }
};

class RollingBall : public Ball
{
private:
    int x, y;

public:
    RollingBall() : x(5), y(5) {}
    void move(char direction) override
    {
        switch (direction)
        {
        case 'w':
            y--;
            break;
        case 's':
            y++;
            break;
        case 'a':
            x--;
            break;
        case 'd':
            x++;
            break;
        }
    }
    void display() override
    {
        cout << "Rolling Ball at (" << x << ", " << y << ")\n";
    }
};

int main()
{
    Ball *ball;
    char choice;
    cout << "Choose ball type (b: Bouncing, r: Rolling): ";
    cin >> choice;
    if (choice == 'b')
    {
        ball = new BouncingBall();
    }
    else
    {
        ball = new RollingBall();
    }
    char key;
    while (true)
    {
        system("cls");
        ball->display();
        if (_kbhit())
        {
            key = _getch();
            if (key == 27)
                break;
            ball->move(key);
        }
    }
    delete ball;
    return 0;
}