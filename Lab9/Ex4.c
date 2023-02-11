
#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h> 
#include <string.h> 
 
/* Таблица частот */ 
unsigned Freq[256]; 
 
 
void main(void) 
{ 
    FILE* F; 
    int i; 
 
    F = fopen("input.txt", "rt"); 
    memset(Freq, 0, 256 * sizeof(unsigned)); 
 
    while (!feof(F)) 
        Freq[fgetc(F)] ++; 
 
    for (i = 13; i < 256; i++) 
        if (Freq[i])  
        { 
            printf("%c ",i); 
            for (int j = 0; j < Freq[i]; j++) 
                printf("#"); 
            printf("\n"); 
        } 
}
