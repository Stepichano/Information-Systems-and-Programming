#define _CRT_SECURE_NO_WARNINGS 
#define N 70
#include <stdio.h>
long long int c[70][70];
int main()
{
    for (int n = 0; n < N; n++)
    {
        for (int k = 0; k < N; k++)
        {
            if (k == 0 || n == k)
            {
                c[n][k] = 1;
            }
            else
            {
                c[n][k] = c[n - 1][k - 1] + c[n - 1][k];
            }
        }
    }
    int n = 0;
    scanf("%d", &n);
    if (n >= 1 && n <= 31)
    {
        for (int k = 0; n >= k; k++)
        {
            for (int m = 0; k >= m; m++)
            {
                printf("%d ", c[k][m]);

            }
            printf("\n");
        }
        return 0;

    }
}