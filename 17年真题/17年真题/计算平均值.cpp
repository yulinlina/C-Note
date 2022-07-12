#include<iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int a[100] = { 0 };
	float sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	printf("%.2f", sum / n);
}
