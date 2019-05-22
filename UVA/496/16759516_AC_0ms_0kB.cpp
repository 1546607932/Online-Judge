#include<iostream>
#include<sstream>
#include<string>
#include<set>
using namespace std;
set<int> a, b;
bool init() {
	string aa, bb;
	a.clear(); b.clear();
	if (!getline(cin, aa))
		return false;
	getline(cin, bb);
	stringstream line(aa);
	int temp;
	while (line >> temp)
		a.insert(temp);
	line.clear(); line.str(bb);
	while (line >> temp)
		b.insert(temp);
	return true;
}
int main() {
	while (init()) {
		int temp;
		int flag = 0;
		for(auto p=b.begin();p!=b.end();) {
			temp = *p;
			if (a.count(temp)) {
				flag = 1;
				a.erase(temp);
				p++;
				b.erase(temp);
			}
			else
				p++;
		}
		if (a.empty() && b.empty())
			cout << "A equals B" << endl;
		else if (a.empty() && !b.empty())
			cout << "A is a proper subset of B" << endl;
		else if (!a.empty() && !b.empty()&&flag==0)
			cout << "A and B are disjoint" << endl;
		else if (!a.empty() && b.empty())
			cout << "B is a proper subset of A" << endl;
		else
			cout << "I'm confused!" << endl;
	}
	return 0;
}