#include <iostream>




using namespace std;
int limit = 0;
int *team;

int M[21][21];

int answer;
int N;


void cal(int *team, int length);

void combination(int *team, int index, int n, int r, int target) {
	if (r == 0)
		cal(team, index);
	else if (target == n) return;
	else {
		team[index] = target;
		combination(team, index + 1, n, r - 1, target + 1);
		combination(team, index, n, r, target + 1);
	}
}

void cal(int *team, int length) {


	int *link = new int[limit];
	int count = 0;

	for (int i = 0; i < N; i++)
	{
		bool check = true;
		for (int j = 0; j < length; j++)
		{
			if (team[j] == i) {
				check = false;
			}
		}
		if (check) {
			link[count] = i;
			count++;
		}
	}
	int result_start = 0;
	int result_link = 0;
	for (int i = 0; i < limit; i++)
	{
		for (int j = 0; j < limit; j++)
		{
			if (i != j) {
				result_start += M[team[i]][team[j]];
				result_link += M[link[i]][link[j]];
			}
		}
	}
	if (answer > abs(result_start - result_link)) {
		answer = abs(result_start - result_link);
	}
}

int main() {



	//init
	answer = 100000;
	cin >> N;
	limit = N / 2;
	team = new int[N];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> M[i][j];
	////start
	combination(team, 0, N, limit, 0);
	cout << answer << endl;
	//system("pause");
	return 0;
}


