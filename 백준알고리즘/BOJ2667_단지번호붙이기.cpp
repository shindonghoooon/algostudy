#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;
int M[25][25];
bool visited[25][25];
char M_input[25][25];
int N;
queue<pair<int, int>> q;
vector<int> answer;
int result = 0;
int bfs() {
	result++;
	int ret = 0;
	int dx[4] = { 1,-1,0,0 };
	int dy[4] = { 0,0,1,-1 };
	pair<int, int> temp;
	while (!q.empty())
	{
	
		temp = q.front();
		q.pop();
		for (size_t i = 0; i < 4; i++)
		{
			int nx = temp.second + dx[i];
			int ny = temp.first + dy[i];
			if (nx == N || nx == -1 || ny == N || ny == -1)
				continue;
			if (visited[ny][nx]|| M[ny][nx] != 1)
				continue;
			q.push(make_pair(ny, nx));
			visited[ny][nx] = true;
			ret++;
		}
	}
	if (ret==0)
	{
		return 1;
	}
	return ret;
}

int main() {
	cin >> N;
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < N; j++)
		{
			cin >> M_input[i][j];
			M[i][j] = M_input[i][j] - '0';
			visited[i][j] = false;
		}
	}
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < N; j++)
		{
			if (!visited[i][j]&&M[i][j]==1)
			{
				q.push(make_pair(i, j));
				answer.push_back(bfs());
			}
		}
	}
	cout << result<<endl;
	sort(answer.begin(), answer.end());
	for (size_t i = 0; i < answer.size(); i++)
		cout << answer[i] << endl;
	system("pause");
	return 0;
}