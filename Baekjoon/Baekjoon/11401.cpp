#include <iostream>
using namespace std;
typedef long long ll;
#define P 1000000007LL

ll n, k, fac[4000001];

ll power(ll n, ll k) {
	if (k == 0)
		return 1;
	if (k % 2 == 0) {
		ll temp = power(n, k / 2);
		return (temp * temp) % P;
	}
	return (n * power(n, k - 1)) % P;
}

int main() {
	cin >> n >> k;
	
	fac[1] = 1;
	for (ll i = 2; i <= 4000000; i++)
		fac[i] = (fac[i - 1] * i) % P;
	if (n == k || k == 0) {
		cout << 1 << '\n';
	}
	else {
		ll ans = fac[n];
		ans = (ans * power((fac[k] * fac[n - k]) % P, P - 2)) % P;
		cout << ans << '\n';
	}

	return 0;
}