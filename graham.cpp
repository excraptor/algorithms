#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <stdlib.h>

using namespace std;

struct point
{
    int x, y; 
    const char* name;
};

point p0;
//next to top element of stack
point next_to_top(stack<point> &s) {
    point p =  s.top();
    s.pop();
    point res = s.top();
    s.push(p);
    return res;
}

int swap(point &p1, point &p2) {
    point temp = p1;
    p1 = p2;
    p2 = temp;
    return 0;
}

int distance_square(point p1, point p2) {
    return (p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y);
}

int crossProduct(point a, point b, point c) {
    int y1 = a.y - b.y;
    int y2 = a.y - c.y;
    int x1 = a.x - b.x;
    int x2 = a.x - c.x;
    if(y2*x1 - y1*x2 == 0) {
        return 0;
    }
    cout << y2*x1 - y1*x2 << endl;
    return (y2*x1 - y1*x2 > 0)? 2: 1;
}
int compare(const void *vp1, const void *vp2) {
    point *p1 = (point *)vp1;
    point *p2 = (point *)vp2;

    int o = crossProduct(p0, *p1, *p2);
    if(o == 0) {
        return (distance_square(p0, *p2) >= distance_square(p0, *p1))? -1: 1;
    }
    return (o == 2)? -1: 1; 
}

void printStack(stack<point> &s) {
    if (s.empty())
    {
        cout << endl;
        return;
    }
    point x = s.top();
    s.pop();
    printStack(s);
    s.push(x);
    cout << x.name << endl;
}

void graham(point points[], int n) {
    point start = points[0];
    for(int i = 1; i<n; i++) {
        if (points[i].x < start.x){
            start = points[i];
        }
    }
    //sort them according to polar angle
    swap(points[0], start);

    p0 = points[0];
    qsort(&points[1], n-1, sizeof(point), compare);
    
    cout << "pontok a sort után: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << points[i].name << " ";
    }
    cout << endl;

    if(n < 3) {
        return;
    }
    stack<point> s;
    s.push(points[0]);
    s.push(points[1]);
    s.push(points[2]);
    int j = 1;
    for (int i = 3; i < n; i++)
    {
        while (crossProduct(next_to_top(s), s.top(), points[i]) != 2)
        {
            cout << j << ". forgásirány: jobbra/semerre" << endl;
            j++;
            s.pop();
            cout << "a stack tartalma:" << endl;
            printStack(s);
        }
        cout << j << ". forgásirány: balra" << endl;
        j++;
        s.push(points[i]);
        cout << "a stack tartalma:" << endl;
        printStack(s);
    }
    /*cout << "################################" << endl;
    while (!s.empty())
    {
        point p = s.top();
        cout << "(" << p.x << ", " << p.y <<")" << endl;
        s.pop();
    }*/
}



int main() {
    point points[] = {{-5,-5, "A"}, {2,8, "B"}, {-4,7, "C"}, {7,7, "D"}, {-3,-6, "E"}, {8,8, "F"}, {-2,4, "G"}, {-5,1, "H"}};
    int n = 8;
    graham(points, n);
    return 0;
}