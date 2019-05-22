#include<iostream>
using namespace std;
int n[1000005], m[10005];
int ns, ms;
int nex[10005];
void GetNext(int* p, int next[])
{
	int pLen = ms;
	next[0] = -1;
	int k = -1;
	int j = 0;
	while (j < pLen - 1)
	{
		//p[k]表示前缀，p[j]表示后缀  
		if (k == -1 || p[j] == p[k])
		{
			++k;
			++j;
			next[j] = k;
		}
		else
		{
			k = next[k];
		}
	}
}
int KmpSearch(int* s, int* p)
{
	int i = 0;
	int j = 0;
	int sLen = ns;
	int pLen = ms;
	while (i < sLen && j < pLen)
	{
		//①如果j = -1，或者当前字符匹配成功（即S[i] == P[j]），都令i++，j++      
		if (j == -1 || s[i] == p[j])
		{
			i++;
			j++;
		}
		else
		{
			//②如果j != -1，且当前字符匹配失败（即S[i] != P[j]），则令 i 不变，j = next[j]      
			//next[j]即为j所对应的next值        
			j = nex[j];
		}
	}
	if (j == pLen)
		return i - j;
	else
		return -1;
}

int main()
{
	int kase;
	cin >> kase;
	while (kase--)
	{
		cin >> ns >> ms;
		for (int i = 0; i < ns; i++)
			scanf("%d", &n[i]);
		for (int i = 0; i < ms; i++)
			scanf("%d", &m[i]);

		GetNext(m,nex);
		int temp = KmpSearch(n, m);
		if (temp == -1)
			cout << -1 << endl;
		else
			cout << temp + 1 << endl;
	}
	return 0;
} 