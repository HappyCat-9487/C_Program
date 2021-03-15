#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX_N 50000

int max3(int, int, int);
int maxSubArray(int [], int, int);

int main(){
    int nums[MAX_N];
    int i=0,n;
	while((scanf("%d",&n) != EOF) && (i<MAX_N)){
		nums[i]=n;
		i++;
	}
	
    printf("%d\n", maxSubArray(nums,0,i-1));

    return 0;
}


int maxSubArray(int nums[], int left, int right){
    int maxLeftSum, maxRightSum;
    int maxLeftBorderSum, maxRightBorderSum;
    int leftBorderSum, rightBorderSum;

    if(left == right)
        if(nums[left] > 0)
            return nums[left];
        else
            return 0;

    int mid = (left + right) / 2, i;
    maxLeftSum = maxSubArray(nums, left, mid);
    maxRightSum = maxSubArray(nums, mid + 1, right);

    maxLeftBorderSum = INT_MIN, leftBorderSum = 0;
    for(i = mid; i >= left; i--){
        leftBorderSum += nums[i];
        if(leftBorderSum > maxLeftBorderSum)
            maxLeftBorderSum = leftBorderSum;
    }

    maxRightBorderSum = INT_MIN, rightBorderSum = 0;
    for(i = mid + 1; i <= right; i++){
        rightBorderSum += nums[i];
        if(rightBorderSum > maxRightBorderSum)
            maxRightBorderSum = rightBorderSum;
    }

    return max3(maxLeftSum, maxRightSum, maxLeftBorderSum + maxRightBorderSum);
}


int max3(int a, int b, int c){
    if(a > b)
        return a > c ? a : c;
    else
        return b > c ? b : c;
}




