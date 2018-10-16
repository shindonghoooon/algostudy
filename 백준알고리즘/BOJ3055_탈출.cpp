#include <iostream>
#include <queue>
using namespace std;


struct Point {
	int x;
	int y;
	int depth = 0;
};
Point make(int x,int y,int depth=0) {
	Point temp;
	temp.x = x;
	temp.y = y;
	temp.depth =  depth;
	return temp;
}

char map[55][55];
int visit[55][55] = { 0 };



int main() {
	queue<Point> W;
	queue<Point> D;
	int height;
	int width;
	Point Douchi;
	Point CAVE;
	bool Gamefinish = false;
	cin >> height;
	cin >> width;
	int dx[4] = { 0,0,1,-1 };
	int dy[4] = { 1,-1,0,0 };
	for (size_t i = 0; i < height; i++)
	{
		for (size_t j = 0; j < width; j++)
		{
			cin >> map[i][j];
			if (map[i][j]=='S')
			{
				Douchi.x = j;
				Douchi.y = i;
				Douchi.depth = 0;
				D.push(Douchi);
				
				
			}
			else if (map[i][j]=='D')
			{
				CAVE.x = j;
				CAVE.y = i;
			}
		}
	}
	Point temp;

	for (size_t i = 0; i < height; i++)
	{
		for (size_t j = 0; j < width; j++)
		{
			if (map[i][j]=='*')
			{
				temp.x = j;
				temp.y = i;
				W.push(temp);
			}
		}
	}

	//input

	int result = -1;

	while (!D.empty()) {

		int count = W.size();
		//물퍼트리기
		while (count > 0) {
	
			Point w = W.front();
			W.pop();
			count--;
			int x = w.x;
			int y = w.y;
			for (size_t i = 0; i < 4; i++)
			{
				int nx =x+ dx[i];
				int ny =y+ dy[i];
				if (nx == -1 || nx == width || ny == -1 || ny == height)
					continue;
				if (map[ny][nx] == 'X' || map[ny][nx] == 'D'||map[ny][nx]=='*')
					continue;
				map[ny][nx] = '*';
				W.push(make(nx, ny));
			}
		}
		//고슴도치 움직임
		count = D.size();
		for (size_t i = 0; i < count; i++)
		{
			Douchi = D.front();
			D.pop();
			int x = Douchi.x;
			int y = Douchi.y;
			int sec = Douchi.depth;
			if (x == CAVE.x&&y == CAVE.y) { //gamefinish
				result = sec;
				Gamefinish = true;
			}
			if (visit[y][x] == 1)
				continue;
			visit[y][x] = 1;
			//search 4 way
			for (size_t i = 0; i < 4; i++)
			{
				int nx =x+dx[i];
				int ny =y+dy[i];
				if (nx == -1 || nx == width || ny == -1 || ny == height)
					continue;
				if (map[ny][nx] == 'X' ||visit[ny][nx]==1||map[ny][nx]=='*')
					continue;

				D.push(make(nx, ny,sec+1));
			}
		}
		if (Gamefinish) 
			break;
	}	


	if (result==-1)
		cout << "KAKTUS";
	else
		cout << result;
	//system("pause");
	return 0;
}