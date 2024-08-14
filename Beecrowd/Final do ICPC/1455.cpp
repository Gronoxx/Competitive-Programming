#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Point {
    double x, y;
};

double dist(const Point &a, const Point &b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

struct Circle {
    Point center;
    double radius;
    Circle() : center{0, 0}, radius{0} {}
    Circle(const Point &c, double r) : center{c}, radius{r} {}
    Circle(const Point &a, const Point &b) {
        center = { (a.x + b.x) / 2, (a.y + b.y) / 2 };
        radius = dist(a, b) / 2;
    }
    Circle(const Point &a, const Point &b, const Point &c) {
        double A = b.x - a.x;
        double B = b.y - a.y;
        double C = c.x - a.x;
        double D = c.y - a.y;
        double E = A * (a.x + b.x) + B * (a.y + b.y);
        double F = C * (a.x + c.x) + D * (a.y + c.y);
        double G = 2 * (A * (c.y - b.y) - B * (c.x - b.x));
        if (fabs(G) < 1e-9) {
            center = { 0, 0 };
            radius = numeric_limits<double>::infinity();
        } else {
            center = { (D * E - B * F) / G, (A * F - C * E) / G };
            radius = dist(center, a);
        }
    }
    bool contains(const Point &p) const {
        return dist(center, p) <= radius + 1e-9;
    }
};

Circle welzl_helper(vector<Point> &P, vector<Point> R, int n) {
    if (n == 0 || R.size() == 3) {
        if (R.size() == 0) return Circle();
        if (R.size() == 1) return Circle(R[0], 0);
        if (R.size() == 2) return Circle(R[0], R[1]);
        return Circle(R[0], R[1], R[2]);
    }

    Point p = P[n - 1];
    Circle D = welzl_helper(P, R, n - 1);

    if (D.contains(p)) {
        return D;
    }

    R.push_back(p);
    return welzl_helper(P, R, n - 1);
}

Circle welzl(vector<Point> &P) {
    random_shuffle(P.begin(), P.end());
    return welzl_helper(P, {}, P.size());
}

int main() {
    int n, instance = 1;
    while (cin >> n && n != 0) {
        vector<Point> cities(n);
        for (int i = 0; i < n; ++i) {
            cin >> cities[i].x >> cities[i].y;
        }

        Circle result = welzl(cities);
        cout << fixed << setprecision(2);
        cout << "Instancia " << instance++ << endl;
        cout << result.center.x << " " << result.center.y << " " << result.radius << endl;
        cout << endl;
    }
    return 0;
}
