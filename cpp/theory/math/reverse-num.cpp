#include <iostream>
using namespace std; 

int reverse(int a) {
  if (a == 0)
    return a;
  else {
    int rev = 0;
    while (a > 0) {
    int last_digit = a % 10;
    rev = (rev * 10) + last_digit;
    a = a / 10;}
    return rev;
  }
}

int main()
{
int num;
cout << "Enter your number: " ;
cin >> num;

int reversed_num = reverse(num);
cout << "Your reversed number: " << reversed_num << endl;

    return 0;
}