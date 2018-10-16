#include <iostream>
#include <vector>

using namespace std;

int change(int d);

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };
int map[101][101];
int N, x, y, d, g;
vector<int> dragon;

//d= 0 -> 1 ¡ä2 3 
int main() {
	cin >> N;
	int result = 0;
	for (size_t i = 0; i < N; i++) //dragon °¹¼ö¸¸Å­ ¹Ýº¹
	{
		//
		dragon.clear();
		cin >> x;
		cin >> y;
		cin >> d;
		cin >> g;
		//dragon input
		dragon.push_back(d);
		for (size_t j = 0; j < g; j++)
		{
			int num = dragon.size();
			for  (int k = num-1; k >=0 ; k--)
			{
				dragon.push_back(change(dragon[k]));
			}
		}
		// ¼±±ß±â

		map[y][x] = 1;
		int nx = x;
		int ny = y;
		for (int j = 0; j < dragon.size(); j++)
		{
			nx += dx[dragon[j]];
			ny += dy[dragon[j]];
			map[ny][nx] = 1;
		}
	}

	for (size_t i = 0; i < 100; i++)  //count square
	{
		for (size_t j = 0; j < 100; j++) {
			if (map[i][j] == 1 && map[i + 1][j] == 1 && map[i][j + 1] && map[i + 1][j + 1])
				result++;
		}
	}
	cout << result << endl;
	//system("pause");
	return 0;
}

int change(int d) {
	int result=0;
	if (d == 3)
		result = 0;
	else
		result = d + 1;

	return result;
}