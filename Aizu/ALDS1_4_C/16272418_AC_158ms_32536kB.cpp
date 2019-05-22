#include<iostream>
#include<string>
#include<set>
using namespace std;

int main() {
	set<string> s;
	int n; cin >> n;
	string cmd,temp;
	for (int i = 0; i < n; i++) {
		cin >> cmd >> temp;
		if (cmd[0] == 'i')
			s.insert(temp);
		else
			if (s.count(temp))
				printf("yes\n");
			else
				printf("no\n");
	}
	return 0;
}