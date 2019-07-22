#include <iostream>

using namespace std;

int history[401][401];
int relation, n;

void solve()
{
	int i, j, k;
	for (k = 1; k <= n; k++) {
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= n; j++) {
				if (history[i][j] == 0) {
					if (history[i][k] + history[k][j] == 0);
					else if (history[i][k] == -1 && history[k][j] == -1)
						history[i][j] = -1;
					else if (history[i][k] == 1 && history[k][j] == 1)
						history[i][j] = 1;
				}
			}
		}
	}
}

int main()
{
	int i;

	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	
	cin >> n >> relation;
	for (i = 0; i < relation; i++) {
		int from, to;
		cin >> from >> to;
		history[from][to] = -1;
		history[to][from] = 1;
	}

	solve();

	int S;
	cin >> S;
	for (i = 0; i < S; i++) {
		int from, to;
		cin >> from >> to;
		cout << history[from][to] << "\n";
	}

	return 0;
}
