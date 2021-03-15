#include<stdio.h>

int main(void){
	int w,x,y,z,i=0,n=0,j;
	int m[8000]={0};
	int g[8000]={0};
	int v[8000]={0};
	int c[8000][201]={{0}};
	int items[8000][201]={{0}};
	
	scanf("%d", &w);
	while(1){
		scanf("%d %d %d",&x,&y,&z);
		if(x==-1 && y==-1 && z==-1)
			break;
		m[i]=x;
		g[i]=y;
		v[i]=z;
		i+=1;
		n+=1;
	}

	
	for(i=0;i<n;i++){
		for(j=0;j<=w;j++){
			if(j-g[i]<0)
				c[i+1][j]=c[i][j];
			else{
				if((c[i][j-g[i]]+v[i]) > c[i][j]){
					c[i+1][j]=c[i][j-g[i]]+v[i];
					items[i][j]=1;
				}
				else
					c[i+1][j]=c[i][j];
			}
		}
	}
	
	for(i=n,j=w;i>=0;i--){
		if(items[i][j]==1){
			printf("%d ",i);
			j-=g[i];
		}
	}
	printf("\n");
	printf("%d\n",c[n][w]);
	return 0;
}

