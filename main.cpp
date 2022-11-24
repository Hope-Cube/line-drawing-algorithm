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

class Point {
    private:
        int _x;
        int _y;
    public:
        Point(int x, int y){
            _x = x;
            _y = y;
        }
        int X(){
            return _x;
        }
        int Y(){
            return _y;
        }
        string PointOut(){
            string s = to_string(X()) + ", " + to_string(Y());
            return s;
        }
};

class LineGroup{
    private:
        vector<vector<Point>> lines;
    public:
        LineGroup(){
        vector<vector<Point>> lines;
        }
        void Add(vector<Point> line){
        lines.push_back(line);
        }
        string LinesOut(){
        string o;
        for(int i = 0; i < lines.size(); i++){
                o = o + to_string(i+1) + "|\n";
            for(int j = 0; j < lines[i].size(); j++){
                o = o + lines[i][j].PointOut() + "\n";
            }
            o = o + "\n";
        }
        return o;
        }
};

int Abs(int a)
{
    if(a < 0){
        a = a * -1;
    }
    return a;
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

vector<Point> CreateLine(Point p1, Point p2){
    bool interchange = 0;

    int x = p1.X();
    int y = p1.Y();

    int dx = Abs(p2.X()-p1.X());
    int dy = Abs(p2.Y()-p1.Y());
    int s1 = Sign(p2.X()-p1.X());
    int s2 = Sign(p2.Y()-p1.Y());

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

    vector<Point> line;

    Point p = Point(p1.X(),p1.Y());

    line.push_back(p);

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
        p = Point(x,y);
        line.push_back(p);
    }

    p = Point(p2.X(),p2.Y());
    line.push_back(p);
    return line;
}

int main()
{
    srand(time(0));
    setlocale(LC_ALL,"");

    vector<vector<char>> screen(32, vector<char> (32,'0'));

    Point p1 = Point(0,0);
    Point p2 = Point(8,4);

    LineGroup lines = LineGroup();
    lines.Add(CreateLine(p1,p2));

    //p1 = Point(5,9);
    //p2 = Point(8,20);

    //lines.Add(CreateLine(p1,p2));
    cout << lines.LinesOut();

    cout << "\n";
    system("pause");
    return 0;
}
