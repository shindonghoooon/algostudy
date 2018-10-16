#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

long long F[1000001];
long long sum[1000001];
int main(int argc, char** argv)
{
	
	for (size_t i = 1; i <=1000000 ; i++)
	{
		F[i] = 0;
		sum[i] = 0;
	}

	for (int i = 1; i <= 1000000; i++)
	{
		if (i % 2 == 1) {
			for (int j = i; j <= 1000000; j+=i)
			{
				F[j] += i;
			}
		}
	}
	sum[1] = 1;
	for (int i = 2; i <= 1000000; i++)
	{
		sum[i] = F[i] + sum[i - 1];
		
	}
	
	int test_case;
	int T;
	cin >> T;
	/*
	여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	


	for (test_case = 1; test_case <= T; ++test_case)
	{
		int L_num, R_num;
		long long result = 0;
		scanf("%d%d", &L_num, &R_num);
		result = (sum[R_num] - sum[L_num-1]);
		printf("#%d %lld\n", test_case,result );
	}
	system("pause");
	return 0;
}