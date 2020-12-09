#include "dec_3.1.h"

CrossedWires::CrossedWires() {
	string tmp;
	ifstream InputFile;
	InputFile.open("dec_3_input.txt");
	Point origin = { 0,0 };
	if (InputFile.is_open()) {
		getline(InputFile, tmp);
		stringstream ss(tmp);
		while (ss.good()) {
			getline(ss, tmp, ',');
			Point lorigin = origin;
			firstWire.push_back(CreateRay(origin, tmp));
		}
		origin = { 0,0 };
		getline(InputFile, tmp);
		stringstream st(tmp);
		while (st.good()) {
			getline(st, tmp, ',');
			Point lorigin = origin;
			secondWire.push_back(CreateRay(origin, tmp));
		}
		InputFile.close();
	}
}

Point CrossedWires::CreatePoint(Point& origin, int point, bool XY) {
	Point r;
	if (XY) {
		r = { origin.x + point,origin.y };
		return r;
	}
	else {
		r = { origin.x,origin.y + point };
		return r;
	}
}

Ray CrossedWires::CreateRay(Point& origin, string& tmp) {
	string direction = tmp.substr(0, 1);
	int point = stoi(tmp.substr(1, tmp.length()));
	Point org = origin;
	Point end;
	int m;
	if (direction.compare("R") == 0 || direction.compare("U") == 0) {
		m = 1;
		if (direction.compare("R") == 0) {
			end = CreatePoint(org, (m*point), true);
		}
		else {
			end = CreatePoint(org, (m*point), false);
		}
	}
	else {
		m =-1;
		if (direction.compare("L") == 0) {
			end = CreatePoint(org, (m*point), true);
		}
		else {
			end = CreatePoint(org, (m*point), false);
		}
	}
	Ray r(origin, end);
	origin = end;
	return r;
}

void CrossedWires::Check(int& returnDist, int& returnDelay) {
	Point test = { 0,0 };
	Point result;
	returnDist=INT_MAX;
	int oneDist = 0;
	for (auto& m : firstWire) {
		int twoDist = 0;
		for (auto& n : secondWire) {
			result = m.Intersect(n);
			if (result != test) {
				returnDist = min(returnDist, result.sum());
				returnDelay = min(returnDelay, oneDist + twoDist + result.dist(m.getP()) + result.dist(n.getP()));
			}
			twoDist += n.Dist();
		}
		oneDist += m.Dist();
	}
}

Point Ray::Intersect(Ray t) {
	Point result = { 0,0 };
	if ((this->xMin >= t.xMin && this->xMin <= t.xMax) &&
		(t.yMin >= this->yMin && t.yMin <= this->yMax)) {
		result.x = this->xMin;
		result.y = t.yMin;
		return result;
	}
	else if ((t.xMin >= this->xMin && t.xMin <= this->xMax) &&
		(this->yMin >= t.yMin && this->yMin <= t.yMax)) {
		result.x = t.xMin;
		result.y = this->yMin;
		return result;
	}
	return result;
}