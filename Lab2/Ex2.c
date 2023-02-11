#define _CRT_SECURE_NO_WARNINGS 
#define R 70 
#include <stdio.h> 

int a[70][70];
int main()
{
    for (int N = 0; N < R; N++)
    {
        for (int k = 0; k < R; k++)
        {
            if (k == 0 || N == k)
            {
                a[N][k] = 1;
            }
            else
            {
                a[N][k] = a[N - 1][k - 1] + a[N - 1][k];
            }
        }
    }
    int N = 0;
    scanf("%d", &N);
    if (N >= 1 && N <= 20)
    {
    for (int k = 0; N >= k; k++)
    {
        for (int m = 0; k >= m; m++)
        {
            printf("%d ", a[k][m]);

        }
        printf("\n");
    }
    return 0;
    }
}