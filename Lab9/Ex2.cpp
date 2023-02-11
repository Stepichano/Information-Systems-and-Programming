#include <iostream> 
#include <string> 
#include <fstream> 
 
using namespace std; 
 
int main(){ 
 const std::string path = "input.txt"; 
 ifstream file(path); 
 string line; 
 int mass[100] = {0}; 
 while ((file >> line)) 
 { 
  /*cout << line.length() << " ";*/ 
  mass[(line.length())]++; 
 } 
 for (int i = 1; i < 100; i++) 
 { 
  if (mass[i] > 0) 
   cout << i << " - " << mass[i] << endl; 
 } 
 return 0; 
}
