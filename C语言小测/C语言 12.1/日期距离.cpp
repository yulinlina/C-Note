#include<iostream>
#include<math.h>
using namespace std;
struct Date
{
	int y;//year
	int m;//month
	int d;//day in month
}date1,date2;
bool isLeap(int y)//判断是否是闰年
{
	return y % 4 == 0 && y % 100 != 0 || y % 400 == 0;//真返回为1，假为0
}
int daysOfMonth(int y, int m)
{
	int day[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (m != 2)
		return day[m - 1];
	else
		return 28 + isLeap(y);
}

int daysOfDate(Date d)//计算一共的天数
{
	long days = d.d;  //初始化天数
	for (int y = 1; y < d.y; y++)//计算年
		days += 365 + isLeap(y);
	for (int m = 1; m < d.m; m++)//计算月
		days += daysOfMonth(d.y, m);
	return days;
}
int main() {
	char date[20]; char month[3] = { 0 }; char year[3] = { 0 }; char day[3] = {0};
	char Month[13][20] = { "January", "February", "March", "Apri", "May"," June"," July", "August", "September", "October", "November","December" };
	int i = 0; 
	cin >> date;
	for (i = 0; i < 2; i++)year[i] = date[i];
	for (i = 0; i < 2; i++)month[i] = date[3 + i];
	for (i = 0; i < 2; i++)day[i] = date[6 + i];
	date1.y = atoi(year);
	date1.m = atoi(month);
	date1.d = atoi(day);
	if (date1.y > 12) {
		cout <<Month[date1.m - 1] << " " << date1.d << ", "<<date1.y<<endl;
	}
	else {
		for (i = 0; i < 2; i++)month[i] = date[0 + i];
		for (i = 0; i < 2; i++)day[i] = date[3 + i];
		for (i = 0; i < 2; i++)year[i] = date[6 + i];
		date2.y = atoi(year);
		date2.m = atoi(month);
		date2.d = atoi(day);
		cout << abs(daysOfDate(date1) - daysOfDate(date2)) << endl;
	}
	return 0;
}