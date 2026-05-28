#include <iostream>
#include <string>
using namespace std; 

int main()
{
string s;
cout << "Enter a string: " ;
cin >> s;
const int num = 96;
int x = s.length();

int y ;
cout << "letters to number alphabetically: ";
for (int i = 0; i < x; i++) {
cout << (s[i] - num) << " ";
}

    return 0;
}