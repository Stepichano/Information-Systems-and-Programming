#define _CRT_SECURE_NO_WARNINGS  
#include <stdio.h>  
#include <string.h>  
  
 
unsigned Freq[256];  
  
  
void main(void)  
{  
    char Name[12];  
    FILE* F;  
    int i;  
  
    F = fopen("input.txt", "rt");  
    memset(Freq, 0, 256 * sizeof(unsigned));  
  
    while (!feof(F))  
        Freq[fgetc(F)] ++;  
  
    for (i = 13; i < 256; i++)  
        if (Freq[i])  
            printf("%d : %c - %u\n", int(i), i, Freq[i]);  
}