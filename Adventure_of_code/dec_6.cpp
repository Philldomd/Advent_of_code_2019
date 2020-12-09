#include "dec_6.h"

Orbiter::Orbiter() {
	string temp;
	ifstream InputFile;
	InputFile.open("dec_6_input.txt");
	if (InputFile.is_open()) {
		while (getline(InputFile, temp)) {
			orbitVec.push_back(temp);
		}
	}
}

void Orbiter::scan(node* new_node) {
	if (new_node != nullptr) {
		std::vector<node*> adjacent_nodes;
		adjacent_nodes.reserve(new_node->orbitees.size());
		adjacent_nodes.push_back(new_node->orbiting);
		adjacent_nodes.insert(adjacent_nodes.begin(), new_node->orbitees.begin(), new_node->orbitees.end());

		for (node* adjacent_node : adjacent_nodes) {
			if (adjacent_node != nullptr && !found) {
				if (adjacent_node->name == "SAN") {
					found = true;
				}
				else if (node_cache.insert(adjacent_node).second) {
					scan(adjacent_node);
				}
			}
		}
		steps += found ? 1 : 0;
	}
}

void Orbiter::process() {
	for (string raw : orbitVec) {
		string orbiting = raw.substr(0, raw.find(')'));
		string orbitee = raw.substr(raw.find(')')+1, raw.length());

		nodes[orbitee].name = orbitee;
		nodes[orbiting].name = orbiting;

		nodes[orbitee].orbiting = &nodes[orbiting];
		nodes[orbiting].orbitees.push_back(&nodes[orbitee]);
	}

	for (pair<string, node> body : nodes) {
		node* orbited = body.second.orbiting;

		while (orbited != nullptr) {
			++orbits;
			orbited = orbited->orbiting;
		}
	}
}