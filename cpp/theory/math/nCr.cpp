#include <iostream>
using namespace std; 

int fact(int);

int main()
{

int n,r;

cout << "Enter the value of n and r: ";
cin >> n >> r;

int nCr = fact(n) / (fact(r) * fact(n - r));

cout << "The value of nCr for the values above is: " << nCr << endl;
    return 0;
}

int fact(int a) {
  int num = 1;
  for (int i = 2; i <= a; i++) {
  // for (int i = 0; i < n; i++) {
  // num *= (n-1);
    
    num *= i;
  }
  return num;
}