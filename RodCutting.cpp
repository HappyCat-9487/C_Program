#include<stdio.h>
#include<limits.h>
int BottomUpCut(int [], int);

int main(void){
	int n,i,j=1,ans;
	int p[50000]={0};
	scanf("%d", &n);
	while(1){
		scanf("%d %d", &i, &p[j]);
		if(i==0 && p[j]==0)
			break;
		j++;
	}
	
	ans=BottomUpCut(p, n);
	
	printf("%d\n", ans);
	
	return 0;
}
int BottomUpCut(int p[], int n){
	int r[n+1]={0};
	int i, j, q;
	
	for(j=1;j<=n;j++){
		q=INT_MIN;
		for(i=1;i<=j;i++)
			if(q < p[i]+r[j-i])
				q=p[i]+r[j-i];
		r[j]=q;
	}
	return r[n];
} 
