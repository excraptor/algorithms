#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

struct point
{
    int x;
    int y;
    
    bool operator==(point p2) {
        return x == p2.x && y == p2.y;
    }
    bool operator<(const point &p2) const {
        return true;
    }
    point operator++() {

    }
    string tostring() {
        return "(" + to_string(x) + "," + to_string(y) + ")";
    }
};

int crossProduct(point a, point b, point c) {
    int y1 = a.y - b.y;
    int y2 = a.y - c.y;
    int x1 = a.x - b.x;
    int x2 = a.x - c.x;
    return y2*x1 - y1*x2;
}

int distance_square(point a, point b) {
    int param1 = a.x-b.x;
    int param2 = a.y-b.y;
    return param1*param1 + param2*param2;
}

set<point> jarvis(point points[], int n) {
    point start = points[0];
    for(int i = 1; i<n; i++) {
        if (points[i].x < start.x){
            start = points[i];
        }
    }

    point current = start;
    vector<point> * colinear = new vector<point>;
    set<point> result;
    result.insert(start);
    int j = 1;
    point next = points[0];
    int indexOfLast = 2;
    while(true) {
        cout << j << ". iteráció: " << endl;
        indexOfLast = (indexOfLast+1) % n;
        for (int i = 0; i < n; i++)
        {
                int cross_product = crossProduct(current, points[i], points[indexOfLast]);
                cout << "jelenlegi pont: " << current.tostring() << ", következő pont: " << points[i].tostring() << ", harmadik pont: " << points[indexOfLast].tostring();
                cout << " forgásirány: " << to_string(cross_product) << endl;
                if (cross_product < 0)
                {
                    indexOfLast = i;
                }  /*else if (cross_product == 0) {
                    if (distance_square(next, current) < distance_square(points[i], current))
                    {
                        colinear->push_back(next);
                        next = points[i];
                    } else {
                        colinear->push_back(points[i]);
                    }
                }*/
            
        }
        /*vector<point>::iterator it;
        for (it = colinear->begin(); it != colinear->end(); it++)
        {
            result.insert(*it);
        }*/

        if (points[indexOfLast] == start)
        {
            break;
        }

        result.insert(points[indexOfLast]);
        current = points[indexOfLast];
        j++;
    }
    return result;
}


int main() {
    point points[] = {{-2,-5}, {7,-5}, {5,8}, {2,4}, {3,-4}, {8,-8}, {8,-6}, {8,-5}};
    int n = 8;

    set<point> result = jarvis(points, n);
    cout << "a ponthalmaz konvex burka: " << endl;

    set<point>::iterator it;
    for (it = result.begin(); it != result.end(); it++)
    {
        cout << "(" << it->x << "," << it->y << ") ";
    }
    cout << endl;

    return 0;
    
}