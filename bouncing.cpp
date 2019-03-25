#include <iostream>
#include <vector>

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
            for (int y = 0; y <= dimy; y++)
            {
                cout << y << " ";
                for (int x = 0; x <= dimx; x++)
                {
                    cout << grid.at(y).at(x) << " ";
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
    grid.display();

    return 0;
}
