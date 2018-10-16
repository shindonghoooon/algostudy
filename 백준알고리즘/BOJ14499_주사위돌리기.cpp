#include <iostream>

using namespace std;

int M;
int N;
int map[22][22];

class cube{
private:
	
	int front;
	int back;
	int east;
	int west;
	int north;
	int south;
public:
	int x;
	int y;
	void init();
	void goeast();
	void gowest();
	void gonorth();
	void gosouth();
	void copy();

};

int main(){
	cube C;
	C.init();
	int commands = 0;
	cin >> N;
	cin >> M;
	cin >> C.y;
	cin >> C.x;
	cin >> commands;
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}

	for (size_t i = 0; i < commands; i++)
	{
		int command=0;
		cin >> command;
		int nx = C.x;
		int ny = C.y;
		
		switch (command)
		{
		case 1:
			if ((nx+1)!=M)
			{
				C.copy();
				C.goeast();
			}
			break;
		case 2:
			if ((nx-1)!=-1)
			{
				C.copy();
				C.gowest();
				
			}
			break;
		case 3:
			
			if ((ny-1)!=-1)
			{
				C.copy();
				C.gonorth();
			}
			break;
		case 4:
			if ((ny+1)!=N)
			{
				C.copy();
				C.gosouth();
			}
			break;
		default:
			break;
		}
		
	}
	//system("pause");
	return 0;
}

void cube::init()
{
	front = 0;
	back = 0;
	east = 0;
	west = 0;
	north = 0;
	south = 0;
}

void cube::goeast()
{
	int pre_front = front;
	int pre_back = back;
	int pre_west = west;
	int pre_east = east;

	front = pre_west;
	back = pre_east;
	west = pre_back;
	east = pre_front;
	x += 1;
	cout  << front << endl;

}

void cube::gowest()
{
	int pre_front = front;
	int pre_back = back;
	int pre_west = west;
	int pre_east = east;

	front = pre_east;
	back = pre_west;
	west = pre_front;
	east = pre_back;
	x -=1;
	cout  << front << endl;

}

void cube::gonorth()
{
	int pre_front = front;
	int pre_back = back;
	int pre_north = north;
	int pre_south = south;
	
	front = pre_south;
	back = pre_north;
	north = pre_front;
	south = pre_back;
	y -= 1;
	cout  << front << endl;
	
}

void cube::gosouth()
{
	int pre_front = front;
	int pre_back = back;
	int pre_north = north;
	int pre_south = south;


	front = pre_north;
	back = pre_south;
	north = pre_back;
	south = pre_front;
	y += 1;
	cout << front << endl;

}

void cube::copy()
{
	if (map[y][x]==0)
	{
		map[y][x] = back;
	}
	else {
		back = map[y][x];
		map[y][x] = 0;
	}
	
}

