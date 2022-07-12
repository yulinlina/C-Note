#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int main() {
	char str[100][20] = { 0 };
	int i = 0;int j=0;
	int count = 0;
	char c='0';
	while (c!='\n') { 
		cin >> str[i];
		for (j = 0; j < strlen(str[i]); j++) {
			if (isalpha(str[i][j])) count++;
		}
		reverse(str[i], str[i] + count);
		count = 0;
		c = getchar();
		i++;
}
	for (j = 0; j < i; j++) cout << str[j] << " ";
	return 0;
}