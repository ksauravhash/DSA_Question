/*
* Leetcode 204
* https://leetcode.com/problems/count-primes/
*/

// Sieve of Eratosthenes

class Solution {
public:
    int countPrimes(int n) {
        int count = 0;
        // Stores all the prime
        vector<bool> prime(n+1, true);
        prime[0] = prime[1] = false;

        for(int i = 2;i<n;i++) {
            if(prime[i]) {
                count++;
                // Mark multiples of prime as composite
                for(int j= i*2;j<n;j+=i) {
                    prime[j] = false;
                }
            }
        }
        return count;
    }
};