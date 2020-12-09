#ifndef DEC_6_H
#define DEC_6_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>


using namespace std;
struct node {
public:
	string name;
	node* orbiting = nullptr;
	vector<node*> orbitees;
	int orbits = 0;
};

class Orbiter {
public:
	Orbiter();
	~Orbiter() {};
	void scan(node*);
	void process(void);
	int getOrbits() { return orbits; };
	int getSteps() { return steps; };

private:
	vector<string> orbitVec;
	int orbits = 0, steps = 0;
	bool found = false;
	set<node*> node_cache;

public:
	map<string, node> nodes;
};


#endif //DEC_6_H
