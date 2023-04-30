class Solution {
public:
    int monkeyMove(int n) {
        // any two monkeys have one vertex in the middle
        // 2 ^ n - 2
        // care for the "subtraction" when doing modulo
  		int ans = binpow(2, n) - 2;  
  		return ans < 0 ? ans + mod : ans;
    }
private:
	int mod = 1e9 + 7;
	long binpow(long a, long n) {
		long ans = 1;
		while(n > 0) {
			if(n % 2 == 1)
				ans = ans * a % mod;
			a = a * a % mod;
			n /= 2; // n >>= 1
		}
		return ans;
	}
    
};