#include <iostream> 
#include <fstream> 
#include <cmath> 
using namespace std; 
 
int main() { 
 int a, b, half_sum; 
 
 ifstream read_file("input.bin", ios::binary); 
 
 read_file.read((char*)(&a), sizeof(a)); 
 read_file.read((char*)(&b), sizeof(b)); 
 read_file.close(); 
 
 half_sum = floor(double(a) / 2 + double(b) / 2); 
 
 ofstream write_file("output.bin", ios::binary); 
 write_file.write((char*)(&half_sum), sizeof(int)); 
 write_file.close(); 
}
