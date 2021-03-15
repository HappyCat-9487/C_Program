#include<stdio.h>
#include<string.h>

int Prt(int *b, char* X, int i, int j, int count){
	if(i<0 || j<0)
		return count;
	if(b[i][j]==1){
		Prt((int *)b,&X[0],i-1,j-1,count+1);
	}
	else if(b[i][j]==2)
		Prt((int *)b,&X[0],i-1,j,count);
	else 
		Prt((int *)b,&X[0],i,j-1,count);
} 

void LCS(char *X, char *Y){
	size_t lengthX = strlen(X);
	size_t lengthY = strlen(Y);
	int m,n,i,j;
	m=lengthX;
	n=lengthY;
	int c[m][n]={0};
	int b[m][n]={0};
	
	for(i=0;i<m;i++)
		for(j=0;j<n;j++){
			if(X[i]==Y[j]){
				c[i][j]=c[i-1][j-1]+1;
				b[i][j]=1;
			}
			else if(c[i-1][j] >= c[i][j-1]){
				c[i][j]=c[i-1][j];
				b[i][j]=2;
			}
			else{
				c[i][j]=c[i][j-1];
				b[i][j]=3;
			}
		}
	i-=1;
	j-=1;
	int count=0;
	Prt((int *)b, &X[0],i,j,count);
	printf("%d", count);
}

int main(void){
	char X[1000];
	char Y[1000];
	scanf("%s", X);
	scanf("%s", Y);
	LCS(&X[0],&Y[0]);
	printf("\n");
	return 0;
}

