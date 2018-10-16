#include <iostream>
#include <stack>
#include <string>

using namespace std;

//croak
/*
karoc
croakcorakcroak
ccroak
*/

void solve(int t,string str) {
	int cnt = 0;
	int cnt_2 = 0;
	bool check = true;
	
	stack<char> C;
	stack<char> R;
	stack<char> O;
	stack<char> A;
	stack<char> K;
	for (size_t i = 0; i < str.length(); i++)
	{
		char temp = str.at(i);
		
		switch (temp)
		{
		case 'c':
			if (cnt > 0) {
				cnt--;
				cnt_2++;
			}
			C.push(temp);
			break;
		case 'r':
			if (C.size() > R.size())
				R.push(temp);
			else
				check = false;
			break;
		case 'o':
			if (R.size() > O.size())
				O.push(temp);
			else
				check = false;
			break;
		case 'a':
			if (O.size() > A.size())
				A.push(temp);
			else
				check = false;
			break;
		case 'k':
			if (A.size() > K.size()) {
				K.push(temp);
				cnt++;
			}
			else
				check = false;
			break;
		default:
			break;
		}
	}
	int count = C.size();
	if (!check || count != R.size() || count != O.size() || count != A.size() || count != K.size()) {
		printf("#%d -1\n", t);
	}
	else
	{
		printf("#%d %d\n", t,count-cnt_2);
	}
	
	
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		string str;
		cin >> str;

		solve(test_case,str);
	}
	system("pause");
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}