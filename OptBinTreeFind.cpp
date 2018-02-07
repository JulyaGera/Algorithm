// Оптимальне бінарне дерево пошуку (динамічне програмування)
#include <iostream>
using namespace std;
#define MAX 100
#define INF 0x3F3F3F3F
int m[MAX], sum[MAX];
int t[MAX][MAX];

int weight(int i, int j)
{
	if (i > j) return 0;
	return sum[j] - sum[i - 1];
}

int way(int i, int j)
{
	int l, temp;
	if (i > j) return 0;
	if (t[i][j] == INF)
	{
		for (l = i; l <= j; l++)
		{
			temp = way(i, l - 1) + way(l + 1, j) + weight(i, l - 1) + weight(l + 1, j);
			if (temp < t[i][j]) t[i][j] = temp;
		}
	}
	return t[i][j];
}
int main() {
	int n = 1; int i;
	while (n == 1) {
		cin >> n;
		memset(t, 0x3F, sizeof(t));
		for (i = 1; i <= n; i++)
			cin >> m[i], t[i][i] = 0;
		
		for (sum[0] = 0, i = 1; i <= n; i++)
			sum[i] = sum[i - 1] + m[i];
		
		way(1, n);
		cout << t[1][n] << endl;
	}
	system("pause");
}
