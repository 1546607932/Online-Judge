#include<iostream>
#include<string>
#include<cctype>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

map<string, int> cnt;
vector<string> words;
//标准化函数
string repr(const string& s)
{
	string ans = s;
	for (int i = 0; i < ans.length(); i++)
		ans[i] = tolower(ans[i]);
	sort(ans.begin(), ans.end());
	return ans;
}
int main()
{
	int n = 0;
	string s;
	while (cin >> s)
	{
		if (s[0] == '#')	break;
		words.push_back(s);						//words添加新元素
		string r = repr(s);
		if (!cnt.count(r))	
			cnt[r] = 0;							//表示第一次出现，添加到cnt中
		cnt[r]++;								//若出现多次则结果大于1
	}
	vector<string> ans;
	for (int i = 0; i < words.size(); i++)		//得到答案
		if (cnt[repr(words[i])] == 1)
			ans.push_back(words[i]);
	sort(ans.begin(), ans.end());				//排序
	for (int i = 0; i < ans.size(); i++)		//输出结果
		cout << ans[i] << endl;
	return 0;
}