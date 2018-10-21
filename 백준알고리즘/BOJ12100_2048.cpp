#include <iostream>
#include <queue>
using namespace std;

int N;
int M[21][21];
int result = 0;
void copy(int dest[21][21], int temp[21][21]) {
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			temp[i][j] = dest[i][j];
		}
	}
}
void cal(int dir) {
	queue<int> q;
	if (dir == 1)  //left
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (M[i][j] != 0)
				{
					q.push(M[i][j]);
					M[i][j] = 0;
				}
			}
			int temp = 0;
			int index = 0;
			while (!q.empty()) {
				temp = q.front();
				q.pop();
				if (M[i][index] == 0)
					M[i][index] = temp;
				else if (M[i][index] == temp)
					M[i][index++] *= 2;
				else {
					M[i][++index] = temp;
				}
			}
		}
	}
	else if (dir == 2) { //up
		for (int j = 0; j < N; j++)
		{
			for (int i = 0; i < N; i++)
			{
				if (M[i][j] != 0)
				{
					q.push(M[i][j]);
					M[i][j] = 0;
				}
			}
			int temp = 0;
			int index = 0;
			while (!q.empty()) {
				temp = q.front();
				q.pop();
				if (M[index][j] == 0)
					M[index][j] = temp;
				else if (M[index][j] == temp)
					M[index++][j] *= 2;
				else {
					M[++index][j] = temp;
				}
			}
		}
	}
	else if (dir == 3) {//right
		for (int i = 0; i < N; i++)
		{
			for (int j = N - 1; j >= 0; j--)
			{
				if (M[i][j] != 0)
				{
					q.push(M[i][j]);
					M[i][j] = 0;
				}
			}
			int temp = 0;
			int index = N - 1;
			while (!q.empty()) {
				temp = q.front();
				q.pop();
				if (M[i][index] == 0)
					M[i][index] = temp;
				else if (M[i][index] == temp)
					M[i][index--] *= 2;
				else {
					M[i][--index] = temp;
				}
			}
		}
	}
	else {//down
		for (int j = 0; j < N; j++)
		{
			for (int i = N - 1; i >= 0; i--)
			{
				if (M[i][j] != 0)
				{
					q.push(M[i][j]);
					M[i][j] = 0;
				}
			}
			int temp = 0;
			int index = N - 1;
			while (!q.empty()) {
				temp = q.front();
				q.pop();
				if (M[index][j] == 0)
					M[index][j] = temp;
				else if (M[index][j] == temp)
					M[index--][j] *= 2;
				else {
					M[--index][j] = temp;
				}
			}
		}
	}
}
void dfs(int depth) {
	int temp = 0;
	if (depth == 5)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (M[i][j]>temp)
					temp = M[i][j];
			}
		}
		if (temp > result)
			result = temp;
		return;
	}
	int temp_m[21][21] = { 0, };
	copy(M, temp_m);
	for (int i = 0; i < 4; i++)
	{
		cal(i + 1);
		dfs(depth + 1);
		copy(temp_m, M);
	}
}
int main() {

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> M[i][j];
		}
	}
	dfs(0);
	cout << result << endl;
	return 0;

}