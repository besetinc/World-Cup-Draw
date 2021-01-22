#include <iostream>
#include <algorithm>
#include <list>
using namespace std;
struct point { int x, y; };
class gen {
	int r;
	int v() { return rand() % (2 * r + 1) - r; }
public:
	gen(int r) : r(r) {}
	point operator() () { point p; p.x = v(); p.y = v(); return p; }
};
class in_circle {
	int r;
public:
	in_circle(int r) : r(r) {}
	bool operator() (const point& p) { return sqrt(p.x*p.x + p.y*p.y) <= r; }
};
int main() {
	int n, r; cin >> n >> r;
	list<point> c(n); generate(c.begin(), c.end(), gen(r));
	cout << count_if(c.begin(), c.end(), in_circle(r)) * 4. / n;
	getchar();
	getchar();
}
