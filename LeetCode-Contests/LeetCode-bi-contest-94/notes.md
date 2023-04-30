To be honest, I didn't resolve this problem because of the number overflow. After reading others' nice posts, I spent hours learning and understanding the background knowledge which are mostly in the cope of **Discrete Mathematics**.

So here is basically what you may need
1. Multinomial Coefficients
2. Modulo Multiplicative Inverse
3. Fermate's little theorem
4. Your brilliant skill achieve them in codes.

#### Multinomial Coefficients
I believe most of people can get to this step to compute something like
`n! / (a!*b!*...(n-a-b)!)`
We would be easy to get stuck in computing any of `n!` due to results too large.

#### Modulo Multiplicative Inverse
While it's equivalent to have `(a mod m) * (b mod m) = (a * b) mod m`. This is not applicable to division. So we need *Modulo Multiplicative Inverse* to help us.

a *Multiplicative Inverse*, `b'` of `b` mod `m` makes an relationship
```
b*b' mod m === 1 mod m
```
we have the following deduction (assume `a` is divisible by `b`)
```
a mod m === (a * 1) mod m === (a * b * b') mod m;
(a / b) mod m === (b * b' * a / b) mod m;
(a / b) mod m === (a * b') mod m;
```
### Fermate's little theorm
Since we have converted `(a / b) mod m` to `(a * b') mod m`, which is further `(a mod m) * (b' mod m)`. 
Following *Fermate's little theorem*, if `p` is a prime number, for any integer `a`, we will have
```
(a^p - a) mod p = 0
```
The provable special case is: if `a` and `p` are coprime, there is
```
(a^(p-1) - 1) mod p = 0 => a^(p-1) === 1 mod p
```
Because if `a` and `p` are coprime, `(a^p + a) = X*(a * p) => a ^ (p-1) = X*p => (a^(p-1) - 1) mod p = 0`.

Recall that `(b*b') === 1 mod m`

In our case, `m` is prime, `b` is always less than `m`, so `b` and `m` are coprime. Then `b'` can possibly be `b^(m-2)` such that `b*b' = b^(m-1) === 1 mod m`.

Since b^(m-2) is not an effcient operation, apply **Binary Exponentiation** for optimization.

As for now, the original problem has been deduced to 
```
[n! / (a!*b!*...)] mod m === (n! mod m) * [(a!)' mod m] * [(b!)' mod m] * ...

=> n! * (a!)^(m-2) * (b!)^(m-2) * ... mod m
```

#### Solution
1. Precompute `n!` and `(n!) ^ (m-2)`, take `O(NlogN)`.
2. For each work apply *Multinomial Coefficients* accordingly. 

```c++
class Solution {
public:
    int countAnagrams(string s) {
        // A33/A22 * A33 = 3 * 6 = 18
    	// modulo multiplicative inverse
    	int n = s.size();
    	int mod = 1e9 + 7;
    	// factorials and inverse factorials
    	vector<long> fact(n + 1, 1), invfact(n + 1, 1);
    	for(int i = 1; i <= n; ++i) {
    		fact[i] = i * fact[i-1] % mod;
    		if(i >= 2)
	    		invfact[i] = binpow(fact[i], mod-2, mod);
    	}
    	long ans = 1;
    	string word;
    	stringstream ss(s);
    	while(ss >> word) {
    		vector<int> freq(26, 0);
    		for(char c : word)
    			freq[c - 'a']++;
    		// n!
    		long res = fact[word.size()];
    		// n! / a! / b!/ ...
    		for(int cnt : freq)
    			if(cnt > 1)
    				res = res * invfact[cnt] % mod;
    		ans = ans * res % mod;
    	}
        return ans;
    }  
private:
	long binpow(long a, long n, long m) {
		long res = 1;
		while(n > 0) {
			if(n % 2)
				res = res * a % m;
			a = a * a % m;
			n /= 2;
		}
		return res;
	}
};
```




