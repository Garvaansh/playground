#include <iostream>
using namespace std; 

// Functions were used to find the factorial of a number.

void fact(int);

int main()
{
int a;
cout << "Enter your number: " ;
cin >> a;

fact(a);

    return 0;
}

void fact(int n) {
  int num = 1;
  for (int i = 2; i <= n; i++) {
  // for (int i = 0; i < n; i++) {
  // num *= (n-1);
    
    num *= i;
  }
  cout << "Factorial of " << n << " is: " << num << endl;
}