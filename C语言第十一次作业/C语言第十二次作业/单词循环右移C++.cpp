#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main() {
	string s[200];
	int i = 0; int n = 0,count=0;
	cin >> n;
	while (cin >> s[count]) {
		count++;
	}
	if (n > count) cout << "error" << endl;
	else {
		for (i=count-1; i>=0; i--) {  // 依次后移
			s[i + n] = s[i];
		}
		for (i = 0; i < n; i++) {  // 找到最前面的单词
			s[i] = s[count+i];
		}
		for (i = 0; i < count; i++) {
			cout << s[i]<<" ";
		}
	}
}