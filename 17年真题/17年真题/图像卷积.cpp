#include<iostream>
#include<string.h>
using namespace std;
int main() {
	int x, h;
	cin >> x >> h;
	int img[200][200] = { 0 };
	int kernel[100][100] = { 0 };
	int result[102][102] = { 0 };
	int i = 0; int j = 0;
	for (i = (h-1)/2; i < x+ (h - 1 )/ 2; i++) {
		for (j =( h - 1 )/ 2; j < x+ (h - 1)/ 2; j++) {
			cin >> img[i][j];
		}
	}
	for(i=0;i<h;i++){
		for (j = 0; j < h; j++) {
			cin >> kernel[h-i-1][h-j-1];
		}

	}
	int sum = 0; int row; int col;
	for (row = 0; row < x; row++) {
		for (col = 0; col < x; col++) {
			for (i = 0; i < h; i++) {
				for (j = 0; j < h; j++) {
					sum += img[i+row][j+col] * kernel[i][j];
				}
			}
			result[row][col] = sum;
			sum = 0;
		}
	}
	for (row = 0; row < x; row++) {
		for (col = 0; col < x; col++) {
			cout << result[row][col]<<" ";
		}
		cout << endl;
	}
	return 0;
}