#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

struct Point {
    int x, y;

    bool operator==(const Point &other) const {
        return x == other.x && y == other.y;
    }
};


int ccw(Point p, Point q, Point r)
{
	int val = (q.y - p.y) * (r.x - q.x) -
			(q.x - p.x) * (r.y - q.y);

	if (val == 0) return 0; 
	return (val > 0)? 1: 2; 
}

void jarvismarch(vector<Point> points, stack<Point>& S){
    int n = points.size();
    
    vector<Point> hull;
  
    int l = 0;
    for (int i = 1; i < n; i++){
        if (points[i].x < points[l].x)
            l = i;
    }

    int p = l, q;
    do
    {
        hull.push_back(points[p]);

        q = (p+1)%n;
        for (int i = 0; i < n; i++)
        {   
           if (ccw(points[p], points[i], points[q]) == 2)
               q = i;
        }
  
        p = q;
  
    } while (p != l); 

    for (int i = 0; i < hull.size(); i++) 
        S.push(hull[i]);
}

int main() {
    int N;
    while(cin >> N) {
        if(N==0)
        break;

        vector<Point> pontos;
        stack<Point> hull;

        for (int i = 0; i < N; i++) {
            int a, b;
            cin >> a >> b;
            Point p = {a, b};
            pontos.push_back(p);
        }

        int camadas = 0;

        while (true) {
            if(pontos.size()<3)
            break;
            jarvismarch(pontos,hull);
            while(!hull.empty()){

                auto it = find(pontos.begin(), pontos.end(), hull.top());
                if (it != pontos.end()) 
                    pontos.erase(it);

                hull.pop();
            } 
            camadas++;
        }

        if(camadas % 2 == 0)
            cout << "Do not take this onion to the lab!" << endl;
        else
            cout << "Take this onion to the lab!" << endl;
    }

    return 0;
}
