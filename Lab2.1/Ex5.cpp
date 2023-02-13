#include <iostream> 
#include <string> 
#include <fstream> 
using namespace std;


int main1() 
{ 
    string strline; 
    ifstream Fin( "input.txt" ); 
    ofstream Fout( "output.txt" ); 
    int line = 1; 

    while ( getline(Fin, strline ))  
    { 
        int upper = 0, lower = 0, digits = 0, i = 0; 
        cout << strline.length() << "\n"; 
        for (; i < strline.length(); i++) 
        { 
            if (strline[i] > 64 && strline[i] < 91) 
                upper++; 
            if (strline[i] > 47 && strline[i] < 58)     
                digits++; 
            if (strline[i] > 96 && strline[i] < 123)    
                lower++; 
        } 
        Fout << "Line " << line++ << " has " << i << " chars: " << lower + upper << 
            " are letters (" << lower << " lower, " << upper << " upper), " << digits << " are digits." << endl; 
    } 
}