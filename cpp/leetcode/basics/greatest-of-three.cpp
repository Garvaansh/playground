// Problem: Find the greatest and smallest among three numbers
// Approach: Use conditional statements
// Time Complexity: O(1)
// Space Complexity: O(1)
// Tags: Basics, Conditionals

#include <iostream>
using namespace std; 

int x,y,z;

int greatest() {
  if(x>y && x>z) {
    return x; }
  else if(y>x && y>z) {
    return y;}
  else {
    return z;}
}

int smallest() {
  if(x<y && x<z) {
    return x; }
  else if(y<x && y<z) {
    return y;}
  else {
    return z;}
};


int main()
{
cout << "Enter the numbers: " ;
  cin >> x >> y >> z;
  
cout << "The greatest number is: " << greatest() << endl;
cout << "The smallest number is: " << smallest() << endl;

    return 0;
}

// ---------------------------------------------------------------------------------------------------------------//



// #include <iostream>
// #include <cmath>
// using namespace std; 

// int main()
// {
// int x,y,z;
// cout << "Enter the numbers: ";
// cin >> x >> y >> z;

// int greatest = max(max(x, y), z);
// int smallest = min(min(x, y), z);

// cout << "The greatest number is: " << greatest << endl;
// cout << "The smallest number is: " << smallest << endl;

//     return 0;
// }