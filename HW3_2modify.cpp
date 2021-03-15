#include<stdio.h>
#include<stdlib.h>
#define SIZE_BALL 524288
#define SIZE_DEP 20
int position(int ,int );
int main(void)
{
	int P[50000]={0}, nball=0, dep=0, j=0, i=0;
	int n, flag = 0;
	
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d %d", &dep, &nball);
		P[i] = position(dep,nball);
	}
	scanf("%d", &flag);
	for(int j=0; j<n; j++){
		printf("%d\n", P[j]);
	}
	
	return 0;	
 }
 int position(int dep, int nball)
 {
 	int pos=1,j=1;
	pos=1;
	j=1;
	while(j<dep)
	{
		if(nball%2==0)
			pos=pos*2+1;
		else
			pos=pos*2;
		if(nball>1)
		{
			if(nball%2==0)
				nball=nball/2;
			else
				nball=nball/2+1;
		}
		j++;
	}
	return pos;
 }
