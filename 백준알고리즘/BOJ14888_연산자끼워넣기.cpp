#include <iostream>
#include <queue>
using namespace std;

struct node {
	char type;
};


int num[11];
int N;
int depth_limit;
int MAXX = -1000000000;
int MINN = 1000000000;


void cal(char type,int depth,int oper[4], queue<node> bag) {
	node temp;
	int temp2=0;
	char op=0;
	int result = 0;

	if (type!='0')
	{
		temp.type = type;
		bag.push(temp);
		if (type == '+')
		{
			oper[0]-=1;
		}
		else if (type == '-')
		{
			oper[1] -= 1;
		}
		else if (type == '*')
		{
			oper[2] -= 1;
		}
		else
		{
			oper[3] -= 1;
		}
	}

	if (depth==depth_limit)
	{
		//cout << depth << " : adsf" << endl;
		op = bag.front().type;
		bag.pop();
		if (op=='+')
		{
			temp2 = num[0] + num[1];
		}
		else if (op=='-')
		{
			temp2 = num[0] - num[1];
		}
		else if (op=='*')
		{
			temp2 = num[0] * num[1];
		}
		else
		{
			temp2 = num[0] / num[1];
		}


		for (size_t i = 1; i < N-1; i++)
		{
			op = bag.front().type;
			bag.pop();
			if (op == '+')
			{
				temp2 += num[i+1];
			}
			else if (op == '-')
			{
				temp2 -= num[i+1];
			}
			else if (op == '*')
			{
				temp2 *= num[i + 1];;
			}
			else
			{
				temp2 /= num[i+1];
			}
		}

		if (type == '+')
		{
			oper[0] += 1;
		}
		else if (type == '-')
		{
			oper[1] += 1;
		}
		else if (type == '*')
		{
			oper[2] += 1;
		}
		else
		{
			oper[3] += 1;
		}

		result = temp2;

		if (MINN > result)
			MINN = result;
		if (MAXX < result)
			MAXX = result;
		return;
	}
	else
	{
		if (oper[0] != 0) {
		
			cal('+', depth + 1,oper,bag);
		}
		if (oper[1] != 0) {
		
			cal('-', depth + 1,oper,bag);
		}
		if (oper[2] != 0) {
		
			cal('*', depth + 1,oper,bag);
		}
		if (oper[3] != 0) {
		
			cal('/', depth + 1,oper,bag);
		}
	}
	
	if (type == '+')
	{
		oper[0] += 1;
	}
	else if (type == '-')
	{
		oper[1] += 1;
	}
	else if (type == '*')
	{
		oper[2] += 1;
	}
	else
	{
		oper[3] += 1;
	}

	return;

}

int main() {
	
	
	cin >> N;
	depth_limit = N - 1;
	int oper[4];
	queue<node> bag;
	for (size_t i = 0; i < N; i++)
	{
		cin >> num[i];
	}
	
	for (size_t i = 0; i < 4; i++)
	{
		cin >> oper[i];
	}
	cal('0', 0,oper,bag);

	cout << MAXX << endl;
	cout << MINN << endl;
	//system("pause");
	return 0;
}