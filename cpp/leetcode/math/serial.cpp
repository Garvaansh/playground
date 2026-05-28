#include <iostream>
using namespace std; 

int main()
{
int n;
int sum = 0;
cout << "enter num: ";
cin >> n;


for( int i = 1; i <= n; i++ ) {
  if ( i % 2 == 0) {
    cout << i << " ";
    sum += i;
  }
  else {
    cout << i * i << " ";
    sum += i * i;
  }
}
  cout << "\nThe sum is: " << sum;
    return 0;
}