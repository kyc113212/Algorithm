#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int N;

int map[50][9];
int visited[9];

int temp[9] = { 0,1,2,3,4,5,6,7,8 };
int max_score = -99999;
vector<int> v;

int solve(vector<int> &tv) {
	int out_count = 0;
	int inings = 0;
	int temp_map[50][9] = { 0, };
	int score = 0;
	int ru[3] = { 0 };

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 9; j++) {
			temp_map[i][j] = map[i][tv[j]];
		}
	}



	while (1) {
		for (int i = 0; i < 9; i++) {
			if (temp_map[inings][i] == 0) {
				out_count++;
				if (out_count == 3) {
					inings++;
					if (inings >= N) {
						return score;
					}
					else {
						out_count = 0;
						memset(ru, 0, sizeof(ru));
					}
				}
			}
			else if (temp_map[inings][i] == 1) {
				if (ru[2] == 1) {
					score++;
					ru[2] = 0;
				}
				if (ru[1] == 1) {
					ru[1] = 0;
					ru[2] = 1;
				}
				if (ru[0] == 1) {
					ru[0] = 0;
					ru[1] = 1;
				}
				ru[0] = 1;
			}
			else if (temp_map[inings][i] == 2) {
				if (ru[2] == 1) {
					score++;
					ru[2] = 0;
				}
				if (ru[1] == 1) {
					ru[1] = 0;
					score++;
				}
				if (ru[0] == 1) {
					ru[0] = 0;
					ru[2] = 1;
				}
				ru[1] = 1;
			}
			else if (temp_map[inings][i] == 3) {
				if (ru[2] == 1) {
					score++;
					ru[2] = 0;
				}
				if (ru[1] == 1) {
					ru[1] = 0;
					score++;
				}
				if (ru[0] == 1) {
					ru[0] = 0;
					score++;
				}
				ru[2] = 1;
			}
			else if (temp_map[inings][i] == 4) {
				if (ru[2] == 1) {
					score++;
					ru[2] = 0;
				}
				if (ru[1] == 1) {
					ru[1] = 0;
					score++;
				}
				if (ru[0] == 1) {
					ru[0] = 0;
					score++;
				}
				score++;
			}
		}
	}	

}

void dfs(int cnt) {

	if (cnt == 8) {
		max_score = max(max_score, solve(v));
		
		return;
	}

	for (int i = 0; i < 9; i++) {
		if (v.size() == 3) {
			v.push_back(temp[0]);
			//visited[3] = true;
		}
		else {
			if (!visited[i]) {
				visited[i] = true;
				v.push_back(temp[i]);
				dfs(cnt + 1);
				v.pop_back();
				visited[i] = false;
			}
		}
	}


	if (v.size() == 4) {
		v.pop_back();
		//visited[3] = false;
	}

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> map[i][j];
		}
	}
	
	visited[0] = true;
	dfs(0);
	
	cout << max_score << endl;

	return 0;
}
