#include<stdio.h>
#include<stdlib.h>

int cmpfunc(const void * a, const void * b){
	return (*(int*)a - *(int*)b);
}

int main(void){
	int n,d, r, i, j, p=0;
	int sum[10000]={0};
	int M[100]={0};
	int E[100]={0};
	
	while(1){
		scanf("%d %d %d",&n , &d, &r);
		if((n==0 && d==0 && r==0) || (n<1 || n>100 || d<1 || d>10000 || r<1 || r>5))
			break;
		for(i=0;i<n;i++)
			scanf("%d", &M[i]);
		for(j=0;j<n;j++)
			scanf("%d", &E[j]);
		qsort(M,n,sizeof(int),cmpfunc);
		qsort(E,n,sizeof(int),cmpfunc);	
		
		for(i=0;i<n;i++){
			if(M[i]+E[n-i-1]>d)
				sum[p]+=(M[i]+E[n-i-1]-d)*r;
		}
		p++;
	}
	
	for(i=0;i<p;i++){
		printf("%d", sum[i]);
		printf("\n");
	}
	return 0;
} 
