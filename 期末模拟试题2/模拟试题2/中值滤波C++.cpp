#include<iostream>
#include<algorithm>
#define X 5
#define y X+1
#define f(x) x*x
using namespace std;
void filter_middle(int w, int n) {
    int a[100] = { 0 }; int b[100] = { 0 }; int c[20];
    for (int i = 0; i < n; i++) {
        cin >> a[i]; b[i] = a[i];
    }
    int begin = 0;   int mid = (begin + begin + w) / 2;
    while (begin <= n - w) {//最大滤波边界 小于 滤波窗口长度
        for (int i = 0; i < w; i++) c[i] = a[begin + i];// 取出子序列，原序列保持不变
        stable_sort(c, c+w);
        b[mid+begin] = c[mid];
        begin++;
    }
    for (int i = 0; i < n; i++) {
        cout << b[i]<<" ";
    }
    cout << endl;
}
int main() {
  /*  int w;
    int n;
    while (cin>>w>>n) {
        if (w % 2 == 0)printf("ERROR\n");
        else
            filter_middle(w, n);
    }*/
    //cout <<b<<c;
    /*cout << f(4 + 4)/f(2+2);*/
    int x = 0; int y = 0;
    for (x = 30, y = 0; x >= 10, y < 10; x--, y++)
        x /= 2, y += 2;
    cout << x << y;
    return 0;
}