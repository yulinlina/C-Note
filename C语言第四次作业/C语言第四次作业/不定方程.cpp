#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>
void process() {
	int m, n; // m : people n:money
	scanf("%d%d", &m, &n);
	int x, y;
	for (x = 0; x <= m; x++) {
		for (y = 0; y <= m - x; y++) {
				if (3 * x + 2 * y + m-x-y == n) {
					printf("%d %d %d\n", x, y, m-x-y);
					break;
			}

		}
	}

}
int main()
{
	int num;
	int i;
	scanf("%d", &num);
	for (i = 0; i < num; i++)
	{
		process();
	}
	return 0;
}