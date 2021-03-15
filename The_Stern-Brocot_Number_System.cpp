#include<stdio.h>
#include<stdlib.h>
void SternBrocot(int ,int );
int main(void)
{
	int numer,denomi,i=0,j,P[50000][2];

	while(scanf("%d %d", &numer, &denomi)){
		if(numer == 1 && denomi == 1)
			break;
		else{
			P[i][0]=numer;
			P[i][1]=denomi;
		}
		i++;	
	}
	
	for(j=0;j<i;j++)
		SternBrocot(P[j][0],P[j][1]);
	return 0;
}
void SternBrocot(int F_numer,int F_denomi)
{
	int L_numer=0,L_denomi=1;
	int M_numer=1,M_denomi=1;
	int R_numer=1,R_denomi=0;
	long double Fd = F_numer/(long double)F_denomi;
	long double Md = M_numer/(long double)M_denomi;
	while(!(M_denomi == F_denomi && M_numer == F_numer) ){
		if(Fd>Md){
			L_numer = M_numer;
			L_denomi = M_denomi;
			M_numer = M_numer+R_numer;
			M_denomi = M_denomi+R_denomi;
			printf("R");
		}
		else{
			R_numer = M_numer;
			R_denomi = M_denomi;
			M_numer = M_numer + L_numer;
			M_denomi = M_denomi + L_denomi;
			printf("L");
		}
		Md = M_numer/(long double)M_denomi;
	}
	printf("\n");
}
