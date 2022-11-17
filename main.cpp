#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <math.h>
#include <locale>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

int Abs(int a)
{
    return a * ((a>0)-(a<0));
}

int Sign(int a)
{
    if (a < 0){
        return -1;
    }
    else if(a > 0){
        return 1;
    }
    else{
        return 0;
    }
}

int main()
{
    srand(time(0));
    setlocale(LC_ALL,"");

    char screen [32][32] = {};

    bool interchange = 0;

    int x1 = 0;
    int y1 = 0;
    int x2 = -8;
    int y2 = -4;

    int x = x1;
    int y = y1;

    int dx = Abs(x2-x1);
    int dy = Abs(y2-y1);
    int s1 = Sign(y2-y1);
    int s2 = Sign(y2-y1);

    if(dy > dx){
        int t = dx;
        dx = dy;
        dy = t;
        interchange = 1;
    }
    else
    {
        interchange = 0;
    }

    int error = 2 * dy - dx;
    int A = 2 * dy;
    int B = 2 * dy - 2 * dx;

    for(int i = 1; i < dx; i++){
        if(error < 0){
            if(interchange == 1){
                y = y + s2;
            }
            else{
                x = x + s1;
                error = error + A;
            }
        }
        else{
            y = y + s2;
            x = x + s1;
            error = error + B;
        }
        cout << x << " " << y << endl;
    }

    cout << "\n";
    system("pause");
    return 0;
}
