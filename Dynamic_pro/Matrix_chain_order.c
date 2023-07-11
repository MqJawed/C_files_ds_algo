#include<stdio.h>

int matrixchain(int a[], int n)
{
    int dp[n][n], order[n][n];
    int len,row,col,k,temp;
    for (len = 2; len<n; len++)
    {
        for(row = 0, col = len; row<n-len; row++,col++)
        {
            dp[row][col] = 999999;
            for (k = row + 1; k<col; k++)
            {
                temp = dp[row][k] + dp[k][col] + a[row] * a[k] * a[col];
                if (temp < dp[row][col])
                {
                    dp[row][col] = temp;
                    order[row][col] = k;
                }
            }
        }
    }
printf("The miniimum operation will be %d",dp[0][n-1]);
printf("\nThe break index will be %d",order[0][n-1]);
}

void main()
{
    int a[] = {2,3,4,1,3};
    matrixchain(a,5);
}