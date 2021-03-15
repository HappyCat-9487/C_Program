#include<stdio.h>
#include<stdlib.h>
#define SIZE_BALL 524288
#define SIZE_DEP 20
int position(int ,int );
int main(void)
{
	int P[1000], nball, dep, j, i=0;
	
	while((scanf("%d %d", &dep, &nball) != EOF) ){
		if((1<=nball<=SIZE_BALL && 2<=dep<=SIZE_DEP)){
			P[i]=position(dep,nball);
			i++;
		}				
	}
	
	
	for(j=0;j<i;j++){
		printf("%d\n", P[j]);
	}
	return 0;	
 }
 int position(int dep,int nball)
 {
 	int pos=1,j=1;
	pos=1,j=1;
	while(j<dep){
		if(nball%2==0)
			pos=pos*2+1;
		else
			pos=pos*2;
		if(nball>1){
			if(nball%2==0)
				nball=nball/2;
			else
				nball=nball/2+1;
		}
	j++;
	}
	return pos;
 }
 
  
