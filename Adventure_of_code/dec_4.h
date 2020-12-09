#ifndef DEC_4_H
#define DEC_4_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class SecureContainer {
public:
	SecureContainer();
	~SecureContainer() {};
	bool CheckDouble(string&);
	bool CheckDoubleTwo(string&);
	bool CheckNumbers(string&);
	void PasswordCount(int);
	int GetCount() { return passwords.size(); };
	void ClearCount(){ 
		passwords.clear();
		passwords.shrink_to_fit();
	};

private:
	string rangeLow;
	string rangeHigh;
	vector<int> passwords;
};


#endif //DEC_4_H

