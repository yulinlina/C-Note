#include<iostream>
#include<math.h>
using namespace std;
bool is_prime(int x) {
	int i;
	for (i = 2; i <= sqrt(x); i++) {
		if (x % i == 0) return false;
	}
	return true;
}
int main() {
	int n; int i;
	cin >> n;
	if ((n <= 6) ||(n%2==1))cout << "ERROR" << endl;
	else {
		for (i = 2; i <= n / 2; i++) {
			if (is_prime(i) && (is_prime(n - i)))
				cout << i << " " << n - i << endl;
		}
	}
	return 0;
}