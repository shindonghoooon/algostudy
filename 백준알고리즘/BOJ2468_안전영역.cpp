#include <iostream>
#include <queue>

using namespace std;

struct point
{
	int x;
	int y;
};
point make(int y,int x) {
	point temp;
	temp.y = y;
	temp.x = x;
	return temp;
}
queue<point> q;
int N;
int m[101][101];
bool visited[101][101];
int ans = 0;
int C = 0;
void bfs() {
	int dx[4] = { 1,-1,0,0 };
	int dy[4] = { 0,0,-1,1 };
	while (!q.empty()) {
		point a = q.front();
		q.pop();
		int x = a.x;
		int y = a.y;
		visited[y][x] = true;
		for (size_t i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx == N || nx == -1 || ny == N || ny == -1)
				continue;
			if (m[ny][nx]>C && !visited[ny][nx])  //물이 아니고 방문한적없으면
				q.push(make(ny, nx));
				
		}
	}
	
}

int main() {
	cin >> N;
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < N; j++)
		{
			cin >> m[i][j];
		}
	}
	int result = 0;
	C = 0;
	while (1) {
		
		result = 0;
		
		for (size_t i = 0; i < N; i++)
		{
			for (size_t j = 0; j < N; j++)
			{
				if (m[i][j]>C && !visited[i][j]) {
					q.push(make(i, j));
					bfs();
					result++;
				}
			}
		}
		if (result==0)
			break;
		//cout << result << " : result " << endl;	
		if (ans < result)
			ans = result;
		C++;
	}
	cout << ans << endl;
	system("pause");
	return 0;
}