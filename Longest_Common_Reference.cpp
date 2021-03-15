#include <stdio.h>
#include <string.h>

int i, j, m, n, LCS_table[20000][20000], t=0, k;
char ch, S1[20000], S2[20000], b[20000][20000];

int main(){
    k=0;
    while(scanf("%c", &ch)){
        if(ch=='\n')  break;
        S1[k] = ch; k++;}
    k=0;
    while(scanf("%c", &ch)!=EOF){
        if(ch=='\n')  break;
        S2[k] = ch; k++;}
    m = strlen(S1);
    n = strlen(S2);
    for (i = 0; i <= m; i++)
        LCS_table[i][0] = 0;
    for (i = 0; i <= n; i++)
        LCS_table[0][i] = 0;

    for (i = 1; i <= m; i++)
        for (j = 1; j <= n; j++){
            if (S1[i - 1] == S2[j - 1]){
                LCS_table[i][j] = LCS_table[i - 1][j - 1] + 1;}
            else if (LCS_table[i - 1][j] >= LCS_table[i][j - 1]){
                LCS_table[i][j] = LCS_table[i - 1][j];}
            else{
                LCS_table[i][j] = LCS_table[i][j - 1];}}

    int index = LCS_table[m][n];
    char lcs[index + 1];
    lcs[index] = '\0';

    int i = m, j = n;
    while (i > 0 && j > 0){
        if (S1[i - 1] == S2[j - 1]){
            lcs[index - 1] = S1[i - 1];
            i--;
            j--;
            index--;
            t++;}

    else if (LCS_table[i - 1][j] > LCS_table[i][j - 1]) i--;
    else j--;}

    printf("%d", t);
    printf("\n");
}
