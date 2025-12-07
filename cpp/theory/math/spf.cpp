#include <bits/stdc++.h>
using namespace std; 

class prime_factors{
  vector<int> spf_sieve(int n) {
    // * Approach: Smallest Prime Factor (SPF) Sieve
    // * Logic: Initialize spf[i] = i for all i. For each prime i (where spf[i] == i), mark multiples j starting from i*i by setting spf[j] = i if not already set.
    // * This ensures each composite number's spf is its smallest prime factor.
    // * Time Complexity: O(n log log n) - efficient sieve-like preprocessing.
    // * Space Complexity: O(n) - array of size n+1.
    // * Pros: Allows fast factorization; once computed, factoring any m <= n is O(log m).
    // ! Cons: Memory usage scales with n; recomputing per n is wasteful for multiple queries.
    // ? Note: spf[1] = 1 (not prime), spf[prime] = prime; used internally for factoring.
    vector<int> spf(n + 1);
    for (int i = 1; i <= n; i++) {
      spf[i] = i;
    }

    for (int i = 2; i * i <= n; i++) {
      if (spf[i] == i) { // i is prime
        for (int j = i * i; j <= n; j += i) {
          if (spf[j] == j) {
            spf[j] = i;
          }
        }
      }
    }
    return spf;
  }

  public:
    vector<int> factors(int n) {
      // * Approach 1: Trial Division
      // * Logic: Loop from 2 to sqrt(n), for each i, divide n by i as many times as possible and collect factors.
      // * If n > 1 after the loop, add it as a prime factor.
      // * This finds all prime factors with multiplicity.
      // * Time Complexity: O(sqrt(n)) - efficient for moderate n.
      // * Space Complexity: O(k) where k is number of prime factors.
      // * Pros: Simple and straightforward for factoring individual numbers.
      // ! Cons: Inefficient for very large n; better for small inputs.
      // ? Note: Assumes n > 1; returns factors in ascending order with duplicates for multiplicity.
      //   vector<int> factors;
      //   for (int i = 2; i * i <= n; i++) {
      //     while (n % i == 0) {
      //       factors.push_back(i);
      //       n /= i;
      //     }
      //   }
      
      //   if (n > 1) {
      //     factors.push_back(n);
      //   }
      
      //   return factors;
    /* ------------------------------------------------------------------------------------------------------------------------ */
    
      // * Approach 2: Using Smallest Prime Factor (SPF) Sieve
      // * Logic: Precompute SPF array where spf[i] is the smallest prime factor of i.
      // * Then, to factor n, repeatedly divide n by spf[n] and collect factors until n=1.
      // * This gives prime factors with multiplicity in ascending order.
      // * Time Complexity: O(n log log n) for sieve + O(log n) for factoring - efficient for moderate n.
      // * Space Complexity: O(n) for SPF array.
      // * Pros: Faster than trial division for factoring; reusable SPF array.
      // ! Cons: Higher space usage; sieve recomputed per n (can optimize by precomputing up to max n).
      // ? Note: Assumes n > 1; factors are in ascending order with duplicates for multiplicity.

      vector<int> spf = spf_sieve(n);
      vector<int> factors;

      while(n > 1) {
        factors.push_back(spf[n]);
        n /= spf[n];
      }

      return factors;
    }
  
};

int main() {
  int t;
  cin >> t;
  
  prime_factors pf;

  while(t--) {
    int n;
    cin >> n;

    vector<int> factors = pf.factors(n);
    for (int factor : factors) {
      cout << factor << " ";
    } 
    cout << "\n"; 
  }

  return 0;
}