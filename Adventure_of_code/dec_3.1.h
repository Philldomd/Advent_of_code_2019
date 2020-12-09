#ifndef DEC_3_1_H
#define DEC_3_1_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;

struct Vec {
	int x;
	int y;
	int z;
	int Sum() { return x + y + z; };
};

struct Point {
	int x;
	int y;
	bool operator==(Point _p) {
		if (x == _p.x && y == _p.y) {
			return true;
		}
		return false;
	};
	bool operator!=(Point _p) {
		return !(*this == _p);
	}
	int sum() { return abs(x) + abs(y); };
	int dist(const Point &b) { return abs(this->x - b.x) + abs(this->y - b.y); };
};

class Ray {
public:
	Ray(Point p, Point q) {
		this->p = p;
		this->q = q;
		xMin = min(p.x, q.x);
		xMax = max(p.x, q.x);
		yMin = min(p.y, q.y);
		yMax = max(p.y, q.y);
	};
	~Ray() {};
	Point Intersect(Ray);
	int Dist() { return p.dist(q); };
	Point getP() { return p; };

private:
	Point p;
	Point q;
	int xMin;
	int xMax;
	int yMin;
	int yMax;
};

class CrossedWires {
public:
	CrossedWires();
	~CrossedWires() {};
	/*True for X and false for Y*/
	Point CreatePoint(Point&, int, bool);
	Ray CreateRay(Point&,string&);
	void Check(int&,int&);
private:
	vector<Ray> firstWire;
	vector<Ray> secondWire;
};
#endif //DEC_3_1_H