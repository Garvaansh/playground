// Problem: Generate Fibonacci series up to n terms
// Approach: Iterative method using loop
// Time Complexity: O(n)
// Space Complexity: O(1)
// Tags: Math, Series, Iterative

#include <iostream>
using namespace std; 

void fibonacci(int);

int main()
{
int a;

cout << "Enter the number of terms: ";
cin >> a;

cout << "Fibonacci series: " ;
fibonacci(a) ;
    return 0;
}

void fibonacci(int a) {
  int num1 = 0, num2 = 1, num;
  for(int i = 0; i <a; i++) {
    if(i == 0) {
      num = 0;
      cout << num << ",";
    } 
    else if(i == 1) {
      num = 1;
      cout << num << ",";
    }
    else {
      num = num1 + num2;
      num1 = num2;
      num2 = num;
      cout << num << ",";
    }
    // cout << num << ",";
  }
}