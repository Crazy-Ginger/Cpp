#include <iostream>
#include <vector>
#include <time.h>
//for sleeping across platforms
#include <chrono>
#include <thread>
using namespace std;

class particle
{
    private:
        int currentx = 1, currenty = 1;
        int prevx, prevy;
        int gridw, gridh;
        int velx = 1, vely = 0;
        
        void boundCheck()
        {
            if (prevx == 0 || prevx == gridw)
            {
                velx = -(velx);
            }
            if (prevy == 0 || prevy == gridh)
            {
                vely = -(vely);
            }
        }

    public:
        void setGrid(int x, int y)
        {
            gridw = x;
            gridh = y;
            currentx = (x/2);
            currenty = (y/2);

        }

        void setVel(int x, int y)
        {
            velx = x;
            vely = y;
        }
        
        int retCurrentX()
        {
            return currentx;
        }
        int retCurrentY()
        {
            return currenty;
        }
        
};

class table
{
    private:
        vector<vector<char>> grid;
        int dimx;
        int dimy;

        void set_grid()
        {
            vector <char> row;
            for (int y = 0; y <= dimy; y++)
            {
                for (int x = 0; x <= dimx; x++)
                {
                    if (y == 0 || y == dimy)
                    {
                        row.push_back('-');
                    }
                    else if (x == 0 || x == dimx)
                    {
                        row.push_back('|');
                    }
                    else
                    {
                        row.push_back(static_cast<char>(' '));
                    }

                    //cout << static_cast<char>(x) << ", ";
                }
                grid.push_back(row);
                row.clear();
            }
        }

    public:
        void display()
        {
            ballx = retCurrentX;
            bally = retCurrentY;
            for (int y = 0; y <= dimy; y++)
            {
                cout << y << "\t";
                for (int x = 0; x <= dimx; x++)
                {
                    if (x == ballx && y == bally)
                    {
                        cout << "# ";
                    }
                    else
                    {
                        cout << grid.at(y).at(x) << " ";
                    }
                }
                cout << endl;
            }
            cout << endl;
        }

        void set_dim(int x = 10, int y = 10)
        {
            dimx = x;
            dimy = y;
            set_grid();
        }
};


int main()
{
    table grid;
    particle bouncer;
    int x , y;

    cout << "Width: ";
    cin >> x;
    cout << "Height: ";
    cin >> y;

    grid.set_dim(x, y);
    bouncer.setGrid(x, y);
    //clock_t clockEnd, clockStart = clock();
    grid.display();
    //clockEnd = clock();

    //float tickDiff ((float)clockEnd - (float)clockStart), clockDiff = tickDiff / CLOCKS_PER_SEC;
    //cout << "ticks: " << tickDiff << "\tseconds: " << clockDiff << endl;

    return 0;
}
