#include <bits/stdc++.h>
using namespace std; 

int calcGCD(int n, int m){  
    // * Approach 1: Brute Force
    // * Logic: Loop from the smaller of n and m down to 1, find the largest number that divides both.
    // * Check each candidate divisor starting from min(n,m).
    // * Time Complexity: O(min(n,m)) - worst case checks many numbers.
    // * Space Complexity: O(1).
    // * Pros: Simple to understand, correct for small n,m.
    // ! Cons: Inefficient for large n or m, as it may check up to min(n,m) times.
    // ? Note: Returns 1 if no common divisor >1, which is always true.
    /*
    int min_val = min(n, m);
    for(int i = min_val; i >= 1; i--) {
        if(n % i == 0 && m % i == 0) {
            return i;
        }
    }
    return 1;  // Though this line is unreachable for n,m >=1
    */
  
    // * Approach 2: Euclidean Algorithm
    // * Logic: Repeatedly replace the larger number with the remainder of division until one becomes 0.
    // * The GCD is the non-zero number at the end.
    // * Time Complexity: O(log min(n,m)) - efficient for large numbers.
    // * Space Complexity: O(1) - uses constant space.
    // * Pros: Fast and standard algorithm, works for all positive integers.
    // ! Cons: Assumes positive integers; may need handling for negatives or zero.
    // ? Note: GCD of 0 and n is n; GCD of two 0s is undefined, but here assumes n,m > 0.
    while(m > 0 && n > 0) {
        ((m > n) ? 
        m %= n : n %= m);
    }
    if(m == 0) return n;
    return m;
}

int main() {
    int n, m;
    cin >> n >> m;
    int gcd = calcGCD(n, m);
    cout << "GCD of " << n << " and " << m << " is " << gcd << endl;

    return 0;
}