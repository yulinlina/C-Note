#include<iostream>
#include<algorithm>
#include<stdlib.h> 
#include<string.h>
using namespace std;
struct stu {
	char name[20];
	char id[20];
	int grade;
	int rank;
}arr[100];
int main() {
	int n; int j = 0; char patter[20]; char temp[5];
	cin >> n; cin >> patter;
	for (int i = 0; i < n; i++) {  // 结构的输入
		cin >> arr[i].name; cin >> arr[i].id; cin >> temp; arr[i].grade =atoi(temp);
	}
	for (int i = 0; i < n; i++) {  // 结构的稳定降序排序
		for (j = 1; j < n - i; j++) {
			if (arr[j - 1].grade < arr[j].grade) swap(arr[j - 1], arr[j]);
		}
	}
	int rank = 1; arr[1].rank = 1; int count = 1;// 真实排名
	for (j = 1; j < n; j++) { // 排名编号
		if (arr[j].grade != arr[j - 1].grade) { rank++; count++; arr[j].rank = count; }
		else {
			arr[j].rank = rank; count++;
		}
	}
	int num = atoi(patter);
	if(isalpha(patter[0])) { // 人名查找
		for (j = 0; j < n; j++) {
			if (strstr(arr[j].name, patter) != NULL) {// 注意每一项之间是否打印了空格
				if (arr[j].grade == 0)
					cout << arr[j].name << " " << arr[j].id << " n/a n/a" << endl;
				else
					cout << arr[j].name << " " << arr[j].id << " " << arr[j].grade << " " << arr[j].rank << endl;
			}
		}
	}
	else if ( num<= 100) { // 成绩查找
		for (j = 0; j < n; j++) {
			if (arr[j].grade == num) 
			{
				if (arr[j].grade == 0)
					cout << arr[j].name << " " << arr[j].id << " n/a n/a" << endl;
				else
					cout << arr[j].name << " " << arr[j].id << " " << arr[j].grade << " " << arr[j].rank << endl;
			}
		}
	}
	else {// id查找
		for (j = 0; j < n; j++) {
			if (strstr(arr[j].id, patter) != NULL)
			{
				if (arr[j].grade == 0)
					cout << arr[j].name <<" " << arr[j].id << " n/a n/a" << endl;
				else
					cout << arr[j].name <<" " << arr[j].id <<" " << arr[j].grade << " " << arr[j].rank << endl;
			}
		}
	}
	return 0;
}