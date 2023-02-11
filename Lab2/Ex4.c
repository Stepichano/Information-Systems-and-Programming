#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
double binomial(int row, int pos)
{
    double koef = 1;
    double i;
    if (pos > row / 2)
    {
        pos = row - pos;
    }
    if (pos == 1)
    {
        return row;
    }
    if (pos == 0)
    {
        return 1;
    }
    double r = 1;
    for (int i = 1; i <= pos; i++)
    {
        if ((int)r % 2 == 0)
        {
            r /= i;
            r *= row - i + 1;
        }
        else
        {
            r *= row - i + 1;
            r /= i;
        }
    }
    return r;
}
int main(void)
{
    int n;
    double c;
    scanf("%d", &n);
    c = n;
    for (int i = 1; i <= n; i++) {
        int row, pos;
        scanf("%d %d", &row, &pos);
        printf("%0.10g", binomial(row, pos));
        printf("\n");
    }

    return 0;
}