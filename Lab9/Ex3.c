#include <stdio.h> 
#include <string.h> 
int main() 
{ 
 FILE *file; 
 file = fopen("input.txt", "r"); 
 char c; 
 int counter = 0; 
 while (!feof(file)) { 
        c = fgetc(file); 
        if(c == '\n') 
        { 
 
            counter++; 
        } 
    } 
//mas[32]=mas[32]+mas[10]-1; 
printf("%d",counter ); 
 
 
 return 0 ; 
 
}
