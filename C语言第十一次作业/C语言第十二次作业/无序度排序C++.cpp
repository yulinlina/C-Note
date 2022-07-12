#include<string.h>
#include<iostream>
using namespace std;
struct DNA {
	char s[100];
	int dis_order;
}dna[100];
int Disorder_count(char str[], int length) {
	int i = 0;
	int tmp = 0;
	int count = 0;
	int result = 0;
	for (tmp = 0; tmp < length - 1; tmp++) {
		for (i = tmp + 1; i < length; i++) {
			result = str[tmp] - str[i];
			if (result > 0) count++;
		}
	}
	return count;
}
int main() {
	int n, m;int i = 0;int j = 0;
	while (cin>>n>>m){  // 输入DNA序列，得到无序度
		for (i = 0; i < m; i++) {
			cin >> dna[i].s;
			dna[i].dis_order = Disorder_count(dna[i].s, strlen(dna[i].s));
		}
		for (i = 0; i < m; i++) {  // 比较DNA的无序度
			for (j = 1; j < m - i; j++) {
				if (dna[j - 1].dis_order > dna[j].dis_order)swap(dna[j - 1], dna[j]); // 交换结构的简洁实现
			}
		}
		for (i = 0; i < m; i++) {  // 输出排序的DNA序列
			cout << dna[i].s << endl;
		}
		printf("********************\n");
	}
	return 0;
}