#include <iostream>

using namespace std;

int N;
int M;
int map[51][51];

int main() {
	int r_x=0;
	int r_y=0;
	int r_d=0;
	cin >> N;
	cin >> M;
	cin >> r_y;
	cin >> r_x;
	cin >> r_d;
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}
	int result = 0;
	int dx[4] = { 0,1,0,-1 };
	int dy[4] = { -1,0,1,0 };
	int nx, ny;
	bool gamefinish = true;
	while (gamefinish)
	{
		//1. 현재위치 청소한다
		map[r_y][r_x] = 2;
		result++;
		
		//2.왼쪽으로 회전
		int count = 0;
		while (count < 4) {
			r_d--;//회전
			
			if (r_d < 0)
				r_d = 3;
			
			if (map[r_y + dy[r_d]][r_x + dx[r_d]] == 0) {
				r_y = r_y + dy[r_d];
				r_x = r_x + dx[r_d];
				break;
			}
			count++;
			if (count == 4) //4방향 다돔
			{
				if (map[r_y - dy[r_d]][r_x - dx[r_d]] != 1) { //뒤가 벽이아닐경우 후진
					//cout << "빠꾸함" << endl;
					r_y = r_y - dy[r_d];
					r_x = r_x - dx[r_d];
					count = 0;
				}
				else { //벽일경우 게임오버
					gamefinish = false;
					break;		
				}
			}
		}
	}
	
	cout << result << endl;
	system("pause");
}