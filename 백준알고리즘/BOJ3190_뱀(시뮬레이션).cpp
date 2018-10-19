#include <iostream>
#include <vector>

using namespace std;

struct Snake {
	int x;
	int y;
};

int main() {
	int N;
	int map[101][101] = {0};
	int apple_count;
	int dir_count;
	int row;
	int col;
	char direction[100];
	int start[100];
	vector<Snake> snake;
	cin >> N;
	cin >> apple_count;
	for(size_t i = 0; i < apple_count; i++)
	{
		cin >> row;
		cin >> col;
		map[row][col]=1;
	}


	cin >> dir_count;

	for (size_t i = 0; i < dir_count; i++)
	{
		cin >> start[i];
		cin >> direction[i];
	}

	bool finish = false;
	int day = 0;
	int current_dir = 1;
	int index = 0;
	Snake temp;
	temp.x = 1;
	temp.y = 1;
	snake.push_back(temp);
	
	
	while (!finish) {
		if (index<dir_count)
		{
			if (start[index] == day)  //방향이 바뀔때 설정
			{
				if (direction[index] == 'D')
					current_dir++;
				else
					current_dir--;

				if (current_dir == 5)
					current_dir = 1;
				if (current_dir == 0)
					current_dir = 4;

				index++;
				//cout << "방향 바뀜" << day <<" : "<<start[index]<< endl;
			}
		}
		

	///moving zone
		if (current_dir==1)//right
		{
			
			temp.x = snake.front().x;
			temp.y = snake.front().y;
			if (temp.x == N)//game finish
				break;
			else if (map[temp.y][temp.x + 1] == 2)
				break;
				
			
			if (map[temp.y][temp.x+1]==1)//if eat apple
			{
				//cout << "사과먹고 오른쪽으로 움직임" << endl;
				map[temp.y][temp.x + 1] = 0;
				temp.x += 1;
				Snake temp2;
				for (size_t i = 0; i < snake.size(); i++)
				{
					temp2 = snake[i];
					snake[i] = temp;
					temp = temp2;
				}
				snake.push_back(temp2);
			}
			else//no apple
			{
				//cout << "오른쪽으로 움직임" << endl;
				temp.x += 1;
				Snake temp2;
				for (size_t i = 0; i < snake.size(); i++)
				{
					temp2 = snake[i];
					snake[i] = temp;
					temp = temp2;
				}
			}	
		}
		else if (current_dir==2)//down
		{
			temp.x = snake.front().x;
			temp.y = snake.front().y;
			if (temp.y == N)//game finish
				break;
			else if (map[temp.y+1][temp.x] == 2)
				break;
			if (map[temp.y+1][temp.x] == 1)//if eat apple
			{
			//	cout << "사과 먹고 밑으로 움직임" << endl;
				map[temp.y+1][temp.x] = 0;
				temp.y += 1;
				Snake temp2;
				for (size_t i = 0; i < snake.size(); i++)
				{
					temp2 = snake[i];
					snake[i] = temp;
					temp = temp2;
				}
				snake.push_back(temp2);
			}
			else//no apple
			{
			//	cout << "밑으로 움직임" << endl;
				temp.y += 1;
				Snake temp2;
				for (size_t i = 0; i < snake.size(); i++)
				{
					temp2 = snake[i];
					snake[i] = temp;
					temp = temp2;
				}
			}
		}
		else if (current_dir==3)//left
		{
			temp.x = snake.front().x;
			temp.y = snake.front().y;
			if (temp.x == 1)//game finish
				break;
			else if (map[temp.y][temp.x -1] == 2)
				break;
			if (map[temp.y][temp.x-1] == 1)//if eat apple
			{
			//	cout << "사과먹고 왼쪽으로 움직임" << endl;
				map[temp.y][temp.x - 1] = 0;
				temp.x -= 1;
				Snake temp2;
				for (size_t i = 0; i < snake.size(); i++)
				{
					temp2 = snake[i];
					snake[i] = temp;
					temp = temp2;
				}
				snake.push_back(temp2);
			}
			else//no apple
			{
			//	cout << "왼쪽으로 움직임" << endl;
				temp.x -= 1;
				Snake temp2;
				for (size_t i = 0; i < snake.size(); i++)
				{
					temp2 = snake[i];
					snake[i] = temp;
					temp = temp2;
				}
			}
		}
		else//up
		{
			temp.x = snake.front().x;
			temp.y = snake.front().y;
			if (temp.y == 1)//game finish
				break;
			else if (map[temp.y-1][temp.x] == 2)
				break;
			if (map[temp.y-1][temp.x] == 1)//if eat apple
			{
			//	cout << "사과먹고 위쪽으로 움직임" << endl;
				map[temp.y-1][temp.x] = 0;
				temp.y -= 1;
				Snake temp2;
				for (size_t i = 0; i < snake.size(); i++)
				{
					temp2 = snake[i];
					snake[i] = temp;
					temp = temp2;
				}
				snake.push_back(temp);
			}
			else//no apple
			{
			//	cout << "위쪽으로 움직임" << endl;
				temp.y -= 1;
				Snake temp2;
				for (size_t i = 0; i < snake.size(); i++)
				{
					temp2 = snake[i];
					snake[i] = temp;
					temp = temp2;
				}
			}
		}


		for (size_t i = 1; i <= N; i++)
		{
			for (size_t j = 1; j <= N; j++)
			{
				if (map[i][j] == 2)
					map[i][j] = 0;
			}
		}

		for (size_t i = 0; i < snake.size(); i++)
		{
			map[snake[i].y][snake[i].x] = 2;
		}

		day++;
	}

	cout << (day + 1) << endl;
	
	
	//system("pause");
	return 0;

}