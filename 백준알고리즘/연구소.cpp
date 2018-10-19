#include <iostream>
#include <list>
#include <vector>

using namespace std;

int count_virus(int ** map,int y,int x) {
	
	int result = 0;
	int count = 0;
	list<int> bag;
	

	for (size_t i = 0; i < (x*y); i++)
	{
		if (map[i / x][i%x] == 2) {
		//cout <<"i : "<< i << endl;
		bag.push_back(i);	

		}
	
	}
	//cout << "1" << endl;
	while (!bag.empty())
	{

		int coord = 0;
		coord= bag.front();
		//cout << "while¹® µé¾î¿È" << endl;
		if (!bag.empty())
		{
			bag.pop_front();
		}
		
		if ((coord/x)!=0)
		{
			//cout << "1µé¾î¿È" <<(coord/x)<< endl;
			if (map[(coord / x) - 1][coord%x] == 0) {
				map[(coord / x) - 1][coord%x] = 2;
				bag.push_back(coord - x);
			}
		}


		if ((coord / x) != (y-1))
		{
			//cout << "2µé¾î¿È" << (coord / x) << endl;
			if (map[(coord / x) + 1][coord%x] == 0) {
				map[(coord / x) + 1][coord%x] = 2;
				bag.push_back((coord + x));
			}

		}

		
		if (coord % x != 0)
		{
			//cout << "3µé¾î¿È" << (coord / x) << endl;
			if (map[(coord / x)][coord%x - 1] == 0) {
				map[(coord / x)][coord%x - 1] = 2;
				bag.push_back(coord - 1);
			}
		}

		if (coord % x != (x-1))
		{
			if (map[(coord / x) ][coord%x + 1] == 0) {
				map[(coord / x) ][coord%x + 1] = 2;
				bag.push_back(coord + 1);
			}
		}
	}
	
	for (size_t i = 0; i < y; i++)
	{
		for (size_t j = 0; j < x; j++)
		{
			if (map[i][j]==0)
				count++;
			if (map[i][j] == 2)
				map[i][j] = 0;
		}
	}
	
	return count;
}

int main() {

	int x, y = 0;
	int **map;
	int result = 0;
	cin >> y;
	cin >> x;
	int count = 0;
	map = new int*[y];
	
	vector<int> init;
	for (size_t i = 0; i < y; i++)
	{
		map[i] = new int[x];
	}

	for (size_t i = 0; i < y; i++)
	{
		for (size_t j = 0; j < x; j++)
		{
			cin >> map[i][j];
			if (map[i][j]==2)
			{
				
				init.push_back(i*x+j);
				//cout << init.front() << endl;
			}
		}
	}
		
	
	for (size_t i = 0; i < (x*y); i++)
	{
		if (map[i / x][i%x] != 0) {
			continue;
		}
		for (size_t j = 0; j < (x*y); j++)
		{
			if (i == j || (map[j / x][j%x] != 0)) {
				continue;
			}
			for (size_t k = 0; k < (x*y); k++)
			{

				if (i == k || j == k || map[k / x][k%x] != 0) {
					continue;
				}
					map[i / x][i%x] = 1;
					map[j / x][j%x] = 1;
					map[k / x][k%x] = 1;
					int temp = 0;
					
					temp = count_virus(map, y, x);
					
					if (result < temp)
						result = temp;
					
					map[i / x][i%x] = 0;
					map[j / x][j%x] = 0;
					map[k / x][k%x] = 0;
					for (size_t a = 0; a < init.size(); a++)
					{
						map[init[a] / x][init[a] % x] = 2;
					}
					
			}
		}
	}
	
	/*
	for (size_t a = 0; a < y; a++)
	{
	for (size_t b = 0; b < x; b++)
	{
	cout << map[a][b];
	}
	cout << endl;
	}
	*/
		
	cout << result;
	
		//cout<< count_virus(map, y, x);
		system("pause");
	
}