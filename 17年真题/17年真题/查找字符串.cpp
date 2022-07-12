#include<iostream>
#include<string.h>
using namespace std;
void find() {
	char target1[] = "SCU";
	char input[100] = { 0 };
	int pos = 0; int count = 0;  
	cin >> input;
	for (int i = 0; i < strlen(input)-2; i++) { // Ñ°ÕÒ×Ó×Ö·û´®
		pos = i; 
		while((input[pos] == target1[count])&&(target1[count])) {
			pos++; count++;
		}
		if ((count == 3) && (i - 1 >= 0) &&(pos < strlen(input)) && (input[i - 1] =='A')) {
			if (input[pos] == 'A')
			{
				cout << "YES" << endl; return;
			}
			else
			{
				cout << "NO" << endl;
				return;
			}
		}
		else if (count == 3) {
			cout << "YES" << endl;
			return;
		}
		count = 0;
	}
	cout << "NO" << endl;
}
int main() {
	int n; int i = 0;
	cin >> n;
	for (i = 0; i < n; i++) {
		find();
	}
}