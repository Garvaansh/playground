#include<iostream>
#include <cmath>
#include <complex>

using namespace std; 

int main()
{
int a,b,c;
cout << "Enter the constants of the roots in form of \n ax^2 + bx + c : " ;
cin >> a >> b >> c ;

int val = (pow(b,2) - 4*a*c);

if (val < 0) {
  complex<int> r1 = (-b + sqrt(complex(val))/2*a); 
  complex<int> r2 = (-b - sqrt(complex(val))/2*a); 

  cout << "The roots are complex: " << r1.real() << " + " << r1.imag() << "i" << 
          " & " << r2.real() << " + " << r2.imag() << "i" << ".\n";

}

else if (val == 0) {
  cout << "The root is real and equal to " << (-b +- sqrt(val)/(2*a)) << ".\n";
}

else {
  cout << "The roots are real and distinct.\n";
  cout << "The first root is " << (-b + sqrt(val))/(2*a) << ".\n";
  cout << "The second root is " << (-b - sqrt(val))/(2*a) << ".\n";
}

    return 0;
}