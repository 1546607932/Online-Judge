#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=1e6+5;
char tmp[maxn];
int n,nxt[maxn],len,lll;
int read()
{
scanf("%s",&tmp);len=strlen(tmp);
int bck=0;
for(int i=0;i<len;i++)bck=bck*10+tmp[i]-'0';
return bck;
}
int main()
{
for(n=read();n!=0;n=read()){
lll++;scanf("%s",&tmp);len=strlen(tmp);
printf("Test case #%d\n",lll);
nxt[0]=-1;nxt[1]=0;
for(int i=2;i<=len;i++){
int cnt=i-1;
while(tmp[nxt[cnt]]!=tmp[i-1]&&cnt)cnt=nxt[cnt];
nxt[i]=nxt[cnt]+1;
if(!(i%(i-nxt[i]))&&nxt[i])
printf("%d %d\n",i,i/(i-nxt[i]));
}
printf("\n");
}
return 0;
}