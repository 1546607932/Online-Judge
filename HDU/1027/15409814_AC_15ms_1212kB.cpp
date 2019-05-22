#include<stdio.h>
#include<algorithm>
using namespace std;
int a[10005];
int main(){
	int n,k,m,i;
	while(~scanf("%d%d",&n,&k)){
		m=1;
		for(i=0;i<=n+1;i++)
			a[i]=i+1;
		while(next_permutation(a,a+n)){
			m++;
			if(m==k){
				break;
			}
			
		}
		for(i=0;i<n;i++){
			if(i!=n-1)
				printf("%d ",a[i]);
			else printf("%d\n",a[n-1]);
		}
	}
	return 0;
} 
