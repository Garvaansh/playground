#include <iostream>
using namespace std; 

int reverse_helper(int,int);
int reverse(int);

int main()
{
int num;
cout << "Enter your number: " ;
cin >> num;

int reversed = reverse(num);
cout << "reversed number is: " << reversed << endl;

    return 0;
}

int reverse_helper(int rev, int n) {
    // Base case: when there are no more digits to process
    if (n == 0)
        return rev;
    
    // Recursive step: extract last digit and build the reversed number
    // rev * 10 shifts the digits of rev to the left and (n % 10) adds the last digit of n
    return reverse_helper(rev * 10 + (n % 10), n / 10);
}

int reverse(int n) {
    // Initial call to the helper function with rev as 0
    return reverse_helper(0, n);
}