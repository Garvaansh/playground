#include <iostream>
using namespace std; 

// Funtion prototyping
// type function-name (arguments);

int sum(int a, int b);

int main()
{
int num1, num2;

cout << "Enter two integers: ";
cin >> num1 >> num2;

cout << "The sum is: " << sum(num1, num2) << endl;

    return 0;
}

int sum(int a, int b) {
  int c = a + b;
  return c;
}