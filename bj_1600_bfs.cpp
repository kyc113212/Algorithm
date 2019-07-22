#include <iostream>
#include <queue>
#include <vector>
#include <cstdio>

using namespace std;

const int MAX = 201;

int row, col;
int K;
int map[MAX][MAX];
int visited[MAX][MAX][31];

struct pos {
	int x;
	int y;
	int cnt;
	int k;
	pos(int a, int b, int c, int d) : x(a), y(b), cnt(c), k(d){}
};

int mdx[] = { -1,1,0,0 };
int mdy[] = { 0,0,-1,1 };
int hdx[] = { 2,2,-2,-2,1,1,-1,-1 };
int hdy[] = { 1,-1,1,-1,2,-2,2,-2 };

int bfs() {

	queue<pos> q;
	q.push(pos(0, 0, 0, K));

	while (!q.empty()) {
		pos cur = q.front();
		q.pop();

		if (cur.x < 0 || cur.y < 0 || cur.x >= col || cur.y >= row)
			continue;

		if (map[cur.y][cur.x] == 1)
			continue;


		if (cur.x == col - 1 && cur.y == row - 1) {
			return cur.cnt;
		}
		
		if (visited[cur.y][cur.x][cur.k] == 1)
			continue;
		visited[cur.y][cur.x][cur.k] = true;
		
		for (int i = 0; i < 4; i++) {
			int nx = mdx[i] + cur.x;
			int ny = mdy[i] + cur.y;
			q.push(pos(nx, ny, cur.cnt + 1, cur.k));
		}
		if (cur.k == 0)
			continue;
		for (int i = 0; i < 8; i++) {
			int nx = hdx[i] + cur.x;
			int ny = hdy[i] + cur.y;
			q.push(pos(nx, ny, cur.cnt + 1, cur.k-1));
		}
	}

	return -1;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//cin >> K;
	//cin >> row >> col;

	scanf("%d", &K);
	scanf("%d %d", &col, &row);

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			//cin >> map[i][j];
			scanf("%d", &map[i][j]);
		}
	}

	printf("%d\n", bfs());
	//cout << bfs() << endl;

	return 0;
}
