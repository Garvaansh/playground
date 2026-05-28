#include <iostream>
using namespace std; 

// int bin(int);

// int reversion(int);

void decToBinary(int);
int main()
{
    int num;
cout << "Enter your number: " ;
cin >> num;

// cout << "Binary representation is: " << reversion(num) << endl;
decToBinary(num);
    return 0;
}

// int bin(int num) {
//         long long int a = 0;
//     while (num != 0 ) {
//         int lastdig = (num % 2);
//         a = (a * 10) + lastdig;
//         num /= 2;
//     }
//     return a;
// }

// int reversion(int a) {
//         a = bin(a);
//         long long int rev = 0;
//     while (a != 0) {
//         int lastdig = (a % 10);
//         rev = (rev * 10) + lastdig;
//         a /= 10;
//     }
//     return rev;
// }

void decToBinary(int n)
{
    // array to store binary number
    int binaryNum[32];

    // counter for binary array
    int i = 0;
    while (n > 0) {

        // storing remainder in binary array
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }

    // printing binary array in reverse order
    for (int j = i - 1; j >= 0; j--)
        cout << binaryNum[j];
}