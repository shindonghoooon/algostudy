#include <iostream>

using namespace std;

int m, N;
int H;
int map[32][32];
int result = -1;

int main() {
	cin >> m;
	cin >> N;
	cin >> H;
	int x, y;
	bool finish = false;
	int M = m;
	for (size_t i = 0; i < N; i++)
	{
		cin >> y;
		cin >> x;
		map[y][x] = 1;
	}

	for (size_t i = 0; i <4; i++) // 사다리 놓는 갯수
	{
		bool check = false;
		if (i == 0) {
			for (size_t j = 1; j <= m; j++) // 제대로 되는지 확인하기
			{
				int x = j;
				for (size_t k = 1; k <= H; k++)
				{
					if (x == 1) {
						if (map[k][x] == 1) {
							x++;
						}
					}
					else if (x == m) {
						if (map[k][x - 1] == 1)
							x--;
					}
					else
					{
						if (map[k][x - 1] == 1)
							x--;
						else if (map[k][x] == 1)
							x++;
					}
				}
				if (x != j) {
					check = false;
					break;
				}
				check = true;
			}
			if (check)
				result = 0;
		}
		else if (i == 1)
		{
			for (int a = 1; a <= m*H; a++)
			{
				if (map[(a / M) + 1][a%M] == 1)
					continue;
				map[(a / M) + 1][a%M] = 1;
				for (size_t j = 1; j <= m; j++) // 제대로 되는지 확인하기
				{
					int x = j;
					for (size_t k = 1; k <= H; k++)
					{
						if (x == 1) {
							if (map[k][x] == 1) {
								x++;
							}
						}
						else if (x == m) {
							if (map[k][x - 1] == 1)
								x--;
						}
						else
						{
							if (map[k][x - 1] == 1)
								x--;
							else if (map[k][x] == 1)
								x++;
						}
					}
					if (x != j) {
						check = false;
						break;
					}
					check = true;
				}
				if (check) {
					result = 1;
					break;
				}
				map[(a / M) + 1][a%M] = 0;
			}

		}
		else if (i == 2)
		{
			for (int a = 1; a <= m*H; a++)
			{
				if (map[(a / M) + 1][a%M] == 1 || map[(a / M) + 1][(a%M) - 1] == 1 || map[(a / M) + 1][(a%M) + 1] == 1)
					continue;
				map[(a / M) + 1][a%M] = 1;
				for (int b = 1; b <= m*H; b++)
				{
					if (a == b)continue;
					if (map[(b / M) + 1][b%M] == 1 || map[(b / M) + 1][(b%M) + 1] == 1 || map[(b / M) + 1][(b%M) - 1] == 1)
						continue;
					map[(b / M) + 1][b%M] = 1;

					for (size_t j = 1; j <= m; j++) // 제대로 되는지 확인하기
					{
						int x = j;
						for (size_t k = 1; k <= H; k++)
						{
							if (x == 1) {
								if (map[k][x] == 1) {
									x++;
								}
							}
							else if (x == m) {
								if (map[k][x - 1] == 1)
									x--;
							}
							else
							{
								if (map[k][x - 1] == 1)
									x--;
								else if (map[k][x] == 1)
									x++;
							}
						}
						if (x != j) {
							check = false;
							break;
						}
						check = true;
					}
					if (check) {
						result = 2;
						break;
					}
					map[(b / M) + 1][b%M] = 0;
				}
				if (check)
					break;
				map[(a / M) + 1][a%M] = 0;
			}
		}
		else if (i == 3)
		{
			for (int a = 1; a <= m*H; a++)
			{
				if (map[(a / M) + 1][a%M] == 1 || map[(a / M) + 1][(a%M) - 1] == 1 || map[(a / M) + 1][(a%M) + 1] == 1)
					continue;
				map[(a / M) + 1][a%M] = 1;
				for (int b = 1; b <= m*H; b++)
				{
					if (a == b)continue;
					if (map[(b / M) + 1][b%M] == 1 || map[(b / M) + 1][(b%M) + 1] == 1 || map[(b / M) + 1][(b%M) - 1] == 1)
						continue;
					map[(b / M) + 1][b%M] = 1;
					for (int c = 1; c <= m*H; c++) {
						if (a == c || b == c)continue;
						if (map[(c / M) + 1][c%M] == 1 || map[(c / M) + 1][(c%M) + 1] == 1 || map[(c / M) + 1][(c%M) - 1] == 1)
							continue;
						map[(c / M) + 1][c%M] = 1;
						for (size_t j = 1; j <= m; j++) // 제대로 되는지 확인하기
						{
							int x = j;
							for (size_t k = 1; k <= H; k++)
							{
								if (x == 1) {
									if (map[k][x] == 1) {
										x++;
									}
								}
								else if (x == m) {
									if (map[k][x - 1] == 1)
										x--;
								}
								else
								{
									if (map[k][x - 1] == 1)
										x--;
									else if (map[k][x] == 1)
										x++;
								}
							}
							if (x != j) {
								check = false;
								break;
							}
							check = true;
						}
						if (check) {
							result = 3;
							break;
						}
						map[(c / M) + 1][c%M] = 0;
					}
					if (check)
						break;
					map[(b / M) + 1][b%M] = 0;
				}
				if (check)
					break;
				map[(a / M) + 1][a%M] = 0;
			}
		}
		if (check)
			break;
	}

	cout << result;
	//system("pause");
	return 0;

}