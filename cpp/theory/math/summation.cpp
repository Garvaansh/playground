// To calculate the summation of n numbers, even or odd n numbers.

#include <iostream>
using namespace std; 

int main()
{
string s;
cout << "Enter your action to perform: " ;
cin >> s;
int n;
cout << "Mention the number of terms: " ;
cin >> n;
int sum = 0;

if(s == "Even" || s == "even") {
  for( int i = 0; i <=n ; i++) {
    if(i % 2 == 0) {
      sum += i;
    }    
  }
  cout << sum ;
}

else if(s == "Odd" || s == "odd") {
  for( int i = 0; i <=n ; i++) {
    if(i % 2 != 0) {
      sum += i;
    }    
  }
  cout << sum ;
}

else if(s == "all" || s == "All") {
  for( int i = 0; i <= n ; i++) {
sum += i;
}
  cout << sum ;
}

else {
  cout << "Error";
}

    return 0;
}