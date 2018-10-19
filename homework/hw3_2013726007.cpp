
//2013726007 신동훈 hw3
// visual studio 2015
//c++

#include <iostream>
#include <vector>


using namespace std;

class point {
public:
	int x;
	int y;
	inline point() { x = 0, y = 0; };
	inline point(int X, int Y) { x = X, y = Y; };
};

vector<char> v_char;//contain result
vector<point>  mino_xy;//checking cycle
vector<point>  tesu_xy;
vector<int> cycle;
vector<int> D; //find fast way

			   //int h[18][19];
			   /* ex)1
			   int h[7][8] = {
			   { 1,1,1,1,1,1,1,1},
			   { 1,0,0,0,0,0,1,1},
			   { 1,0,1,1,1,0,1,1},
			   { 1,0,0,0,1,0,0,0},
			   { 1,0,1,1,1,0,1,1},
			   { 1,0,0,0,0,0,1,1},
			   { 1,1,1,1,1,1,1,1}

			   };
			   point A = point(5, 3);

			   */

			   /*
			   int h[9][8] = {
			   { 1,1,1,1,1,1,1,1},
			   { 1,0,0,0,0,0,1,1},
			   { 1,0,0,1,1,0,1,1},
			   { 1,0,0,0,0,0,0,0},
			   { 1,0,1,0,0,0,1,1},
			   { 1,0,1,0,0,0,1,1},
			   { 1,1,1,0,0,0,1,1},
			   { 1,0,0,0,0,0,1,1},
			   { 1,1,1,1,1,1,1,1}
			   };

			   point A = point(7, 3);
			   */
			   /*     //ex3
			   int h[10][16] = {
			   { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
			   { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
			   { 1,0,1,0,1,0,0,0,0,0,0,0,0,0,1},
			   { 1,0,1,0,1,0,0,0,0,0,0,0,0,0,1},
			   { 1,0,1,1,1,0,0,0,0,0,1,0,1,0,1},
			   { 1,0,0,0,0,0,0,0,0,0,1,0,1,0,1},
			   { 1,0,0,0,0,0,0,0,0,0,1,1,1,0,1},
			   { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
			   { 1,0,1,1,1,1,1,1,1,1,1,1,1,1,1},
			   { 1,0,1,1,1,1,1,1,1,1,1,1,1,1,1}
			   };
			   */
			   
			   int h1[18][19] = {
			   { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },         // Puzzle1
			   { 1,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,1 },
			   { 1,1,1,1,1,0,1,0,1,0,1,0,1,0,1,1,1,0,1 },
			   { 1,0,0,0,1,0,1,0,1,0,1,0,1,0,0,0,1,0,1 },
			   { 1,0,1,0,1,1,1,0,1,0,1,0,1,0,1,1,1,0,1 },
			   { 1,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1 },
			   { 1,0,1,1,1,0,1,0,1,1,1,1,1,1,1,0,0,0,1 },
			   { 1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,0,0,1 },
			   { 1,1,1,0,1,0,1,1,1,0,1,0,1,1,1,1,1,1,1 },
			   { 1,0,1,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,1 },
			   { 1,0,1,0,1,1,1,0,1,1,1,1,1,1,1,1,1,0,1 },
			   { 1,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,1 },
			   { 1,0,1,1,1,0,1,1,1,0,1,0,1,1,1,1,1,1,1 },
			   { 1,0,1,0,1,0,0,0,1,0,1,0,0,0,0,0,0,0,1 },
			   { 1,0,1,0,1,0,1,1,1,0,1,1,1,1,1,1,1,0,1 },
			   { 1,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1 },
			   { 1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
			   { 1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },};
			   
			   
			   int h2[18][19] = {
			   { 1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1 },         // Puzzle2
			   { 1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1 },
			   { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
			   { 1,1,1,1,1,0,0,0,0,0,1,1,0,0,0,0,0,0,1 },
			   { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
			   { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
			   { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
			   { 1,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,1,0,1 },
			   { 1,0,1,0,0,0,1,0,1,0,0,0,0,0,0,0,1,0,1 },
			   { 1,0,1,1,1,0,1,0,1,0,0,0,0,0,0,0,1,0,1 },
			   { 1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1 },
			   { 1,0,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,1 },
			   { 1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1 },
			   { 1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1 },
			   { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1 },
			   { 1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,0,1 },
			   { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
			   { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 }
			   }; //puzzle 2
			  
			  
			   int h3[17][18] = {
			   { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },         // Puzzle3
			   { 0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
			   { 1,1,0,1,0,0,0,0,0,0,0,1,1,0,0,1,1,1 },
			   { 1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1 },
			   { 1,1,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,1 },
			   { 1,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1 },
			   { 1,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1 },
			   { 1,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1 },
			   { 1,1,0,0,1,1,0,1,0,0,0,1,1,0,0,0,0,1 },
			   { 1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1 },
			   { 1,1,0,1,0,1,0,0,0,0,0,0,0,1,0,0,0,1 },
			   { 1,1,0,1,0,1,0,0,0,0,0,0,0,1,0,0,0,1 },
			   { 1,1,1,1,0,1,0,0,0,1,0,0,0,1,1,1,0,1 },
			   { 1,1,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,1 },
			   { 1,1,1,1,0,0,0,0,0,1,1,1,0,0,0,0,0,1 },
			   { 1,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1 },
			   { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 }
			   };
			   
			   
			   int h4[19][31] = {
			   { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
			   { 1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,1,1 },
			   { 1,1,1,1,1,0,1,0,1,0,1,0,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1 },
			   { 1,0,1,0,1,0,1,0,1,0,1,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1 },
			   { 1,0,1,0,1,0,1,1,1,0,1,0,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1 },
			   { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1 },
			   { 1,0,1,0,1,1,1,0,1,0,1,0,1,1,1,0,1,0,1,0,1,1,1,1,1,0,1,0,1,1,1 },
			   { 1,0,1,0,1,0,0,0,1,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,1,0,1,1,1 },
			   { 1,0,1,0,1,1,1,0,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,0,1,0,1,1,1 },
			   { 1,0,1,0,1,0,0,0,1,0,1,0,1,0,1,0,1,0,0,0,0,0,0,0,1,0,1,0,1,1,1 },
			   { 1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,0,1,0,1,0,1,1,1 },
			   { 1,0,1,0,1,0,1,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,1,1,1 },
			   { 1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,0,1,0,1,0,1,1,1 },
			   { 1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,0,0,0,0,0,0,1,0,1,0,1,1,1 },
			   { 1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,0,1,0,1,0,1,1,1 },
			   { 1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,0,0,0,0,0,0,1,0,1,0,1,1,1 },
			   { 1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,0,1,0,1,0,1,1,1 },
			   { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1 },
			   { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 } };
		   
int h5[19][30]
{
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 ,1 },
	{ 1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1 ,1 },
	{ 1,0,1,0,1,0,1,1,1,0,1,1,1,1,1,0,1,0,1,1,1,0,1,1,1,1,1,0,1 ,1 },
	{ 1,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,0,0,1,0,1,0,1,0,1,0,1,1 },
	{ 1,0,1,1,1,1,1,0,1,0,1,0,1,1,1,0,1,0,1,1,1,0,1,0,1,0,1,0,1,1 },
	{ 1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,1,1 },
	{ 1,0,1,0,1,0,1,1,1,1,1,0,1,1,1,0,1,1,1,0,1,0,1,0,1,0,1,0,1,1 },
	{ 1,0,1,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,0,0,1,0,1,0,1,0,1,1 },
	{ 1,0,1,0,1,0,1,0,1,0,1,0,1,1,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1 },
	{ 1,0,1,0,1,0,1,0,1,0,1,0,0,0,1,0,1,0,1,0,1,0,1,0,0,0,0,0,1,1 },
	{ 1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,1 },
	{ 1,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,1,0,1,0,1,0,1,0,1,0,1,0,0,0 },
	{ 1,0,1,1,1,1,1,1,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1 },
	{ 1,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,1,1 },
	{ 1,1,1,1,1,0,1,0,1,1,1,1,1,0,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1 },
	{ 1,0,1,0,1,0,1,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1 },
	{ 1,0,1,0,1,0,1,0,1,1,1,1,1,0,1,0,1,0,1,1,1,1,1,1,1,0,1,0,1,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
};

int h[19][31];

bool dye_checking = true;
bool move_checking = true;
bool mino_move_checking = true;
bool goal_checking = true;
point A;
bool find_cycle(int i, point T, point M);
void find_optimal(point T);
void show(point T, point M) {
	h[M.y][M.x] = 8;
	h[T.y][T.x] = 3;
	//system("cls");
	for (int i = 0; i < 17; i++)
	{
		for (int j = 0; j < 18; j++)
		{
			if (h[i][j] == 8)
			{
				cout << "● ";
			}
			else if (h[i][j] == 3) {
				cout << "○ ";
			}
			else {
				cout << h[i][j] << "  ";
			}
		}
		cout << endl;
	}
	cout << endl;
	h[M.y][M.x] = 0;
	h[T.y][T.x] = 0;
}
void show_result() {

	
	for (size_t i = 0; i < v_char.size(); i++)
	{
		cout << " " << v_char[i] << " ";
		
	}
	cout << endl;
	v_char.clear();
	tesu_xy.clear();
	mino_xy.clear();
	cycle.clear();
}
point movetesu(point M, point T, int i) {
	dye_checking = true;
	move_checking = true;
	mino_move_checking = true;
	if (i == 1)
	{
		v_char.push_back('L');
		if (h[T.y][(T.x - 1)] == 0) {
			T.x = T.x - 2;
			//cout << "테수 왼쪽우르 움직임" << endl;

		}
		else {
			move_checking = false;
		}


	}
	else if (i == 2)
	{
		v_char.push_back('R');
		if (h[T.y][(T.x + 1)] == 0)
		{
			T.x = T.x + 2;

			//cout << "테수 오른쪽으로 움직임" << endl;
		}
		else {
			move_checking = false;
		}
	}
	else if (i == 3)
	{
		v_char.push_back('U');
		if (h[T.y - 1][(T.x)] == 0)
		{
			T.y = T.y - 2;

			//cout << "테수 위쪽으로 움직임" << endl;
		}
		else {
			move_checking = false;
		}
	}
	else if (i == 4)
	{
		v_char.push_back('D');
		if (h[T.y + 1][(T.x)] == 0)
		{
			T.y = T.y + 2;

			//cout << "테수 아래쪽으로 움직임" << endl;
		}
		else {
			move_checking = false;
		}
	}
	else if (i == 5)
	{
		v_char.push_back('S');
		//cout << "테수 stay했음" << endl;
	}
	if (T.x == A.x&&T.y == A.y) {
		goal_checking = false;

	}
	if (T.x == M.x&&T.y == M.y)
	{
		//cout << "point die!!!!!!"<<endl;
		dye_checking = false;
	}

	return T;
}

point movemino(point M, point T) {
	if (goal_checking == false || move_checking == false || dye_checking == false)
	{

		return M;

	}
	mino_move_checking = true;
	dye_checking = true;
	for (size_t i = 0; i < 2; i++)
	{
		if (h[(M.y)][M.x - 1] == 0 && (abs(M.x - T.x)>abs((M.x - 2) - T.x)))//left
		{

			M.x = M.x - 2;
		}
		else if (h[(M.y)][M.x + 1] == 0 && (abs(M.x - T.x)>abs((M.x + 2) - T.x)))//right
		{

			M.x = M.x + 2;
		}
		else if (h[(M.y - 1)][M.x] == 0 && (abs(M.y - T.y)>abs((M.y - 2) - T.y)))//up
		{
		
			M.y = M.y - 2;
		}
		else if (h[(M.y + 1)][(M.x)] == 0 && (abs(M.y - T.y)>abs((M.y + 2) - T.y)))//down
		{

			M.y = M.y + 2;
		}
		else { //can't move
			
			mino_move_checking = false;
		}
		if (T.x == M.x&&T.y == M.y)         //die
		{

			dye_checking = false;
			return M;

		}

		//show(T,M);
	}
	return M;
}

bool promising(int i, point T, point M) {        ///promising function

	if (goal_checking == false || move_checking == false || dye_checking == false || (find_cycle(i, T, M) == false))
	{

		if (goal_checking) {
			if (!v_char.empty())
			{
				v_char.pop_back();
			}
		}
		return false;
	}
	else {
		//cycle 검사해주는 vector
		tesu_xy.push_back(T);  //tesu 좌표
		mino_xy.push_back(M);  //미노 좌표
		cycle.push_back(i);   //그때의 방향

		return true;

	}

}

void backtracking(int i, point T, point M,bool first_check) { //backtraking 함수
	point temp_m;
	point temp_t;
	int d_index;
	//int d[5] = {0};
	int index = i;
	temp_t = movetesu(M, T, i);//move tesu
	temp_m = movemino(M, temp_t);//move mino

	if (mino_move_checking) {
		if (promising(index, temp_t, temp_m)) {  //checking promising
			int index = 1;
			if (index == 1)
			{
				backtracking(index, temp_t, temp_m, false);
				if (goal_checking == true)
				{
					index++;
				}
			}
			if (index == 2)
			{
				backtracking(index, temp_t, temp_m,false);
				if (goal_checking == true)
				{
					index++;
				}
			}
			if (index == 3)
			{
				backtracking(index, temp_t, temp_m, false);
				if (goal_checking == true)
				{
					index++;
				}
			}
			if (index == 4)
			{
				backtracking(index, temp_t, temp_m, false);
				if (goal_checking == true)
				{
					index++;
				}
			}
			if (index == 5) {
				//cout << "stay 트레킹백";
				backtracking(index, temp_t, temp_m,false);
			}

			if (goal_checking) {
				if (!v_char.empty())
				{
					v_char.pop_back();
				}
			}

		}
	}
	else { //move mino checking false == mino can't move
		if (promising(index, temp_t, temp_m)) {  //checking promising
			d_index = 0;
			find_optimal(temp_t);
			if (d_index == 0)
			{
				//cout << "//왼쪽 트레킹백" << D[d_index] << " " << cycle_check << endl;
				backtracking(D[d_index], temp_t, temp_m, false);
				if (goal_checking == true)
				{

					d_index++;
				}
			}
			if (d_index == 1)
			{
				backtracking(D.at(d_index), temp_t, temp_m, false);
				if (goal_checking == true)
				{
					d_index++;
				}
			}
			if (d_index == 2)
			{
				backtracking(D.at(d_index), temp_t, temp_m, false);

				if (goal_checking == true)
				{
					d_index++;
				}
			}
			if (d_index == 3)
			{
				backtracking(D.at(d_index), temp_t, temp_m, false);
				if (goal_checking == true)
				{
					d_index++;
				}
			}
			if (d_index == 4) {
				//cout << "stay 트레킹백";
				backtracking(D.at(d_index), temp_t, temp_m, false);
			}
			if (goal_checking) {
				if (!v_char.empty())
				{
					v_char.pop_back();
				}
			}
		}
	}
	if (first_check)
	{
		int num = i;
		num++;
		if (goal_checking&&(num<6))
		{
			backtracking(num, T, M,true);
		}
		
	}
}



int main() {
	point T;
	point M;
	bool first_check = true;
	int direction = 1;
	 
	for (size_t i = 0; i < 18; i++)           //puzzle 1init
	{ 
		for (size_t j= 0; j < 19; j++)
		{
			h[i][j] = h1[i][j];
		}
	}
	
	
	cout << "Puzzle 1" << endl;
	M.x = 5;                        //puzzle 1 init
	M.y = 5;
	T.x = 1;
	T.y = 1;
	A.x = 3;
	A.y = 17;
	goal_checking = true;
	backtracking(1, T, M,first_check);
	show_result();
	
	
	for (size_t i = 0; i < 19; i++)               //puzzle2 init
	{ 
		for (size_t j = 0; j < 31; j++)
		{
			h[i][j] = 0;
		}
	}
	for (size_t i = 0; i < 18; i++)
	{
		for (size_t j = 0; j < 19; j++)
		{
			h[i][j] = h2[i][j];
		}	
	}
	
	
	cout << "Puzzle 2" << endl;
	
	M.x = 1;                            //puzzle 2 init
	M.y = 2;
	T.x = 17;
	T.y = 2;
	A.x = 7;
	A.y = 0;
	 goal_checking = true;
	 backtracking(1, T, M,first_check);
	 show_result();
	
	for (size_t i = 0; i < 19; i++)               //puzzle 3 puzzle init
	{
		for (size_t j = 0; j < 31; j++)
		{
			h[i][j] = 0;
		}
	}
	
	for (size_t i = 0; i < 17; i++)
	{
		for (size_t j = 0; j < 18; j++)
		{
			h[i][j] = h3[i][j];
			
		}
	
	}
	
	
	cout << "Puzzle 3" << endl;
	
	M.x = 2;                              //puzzle 3 init
	M.y = 1;
	T.x = 4;
	T.y = 3;
	A.x = 0;
	A.y = 1;
	goal_checking = true;
	backtracking(1, T, M,first_check);
	
	show_result();
	
	for (size_t i = 0; i < 19; i++)       //puzzle 4 puzzle init
	{
		for (size_t j = 0; j < 31; j++)
		{
			h[i][j] = 0;
		}
	}
	for (size_t i = 0; i < 19; i++)
	{
		for (size_t j = 0; j < 31; j++)
		{
			h[i][j] = h4[i][j];
		
		}
	
	}
	
	cout << "Puzzle 4" << endl;
	M.x = 27;                     //puzzle 4 init
	M.y = 9;
	T.x = 1;
	T.y = 9;
	A.x = 29;
	A.y = 3;
	first_check = true;
	goal_checking = true;
	backtracking(1, T, M,first_check);
	show_result();
	for (size_t i = 0; i < 19; i++)
	{
		for (size_t j = 0; j < 31; j++)
		{
			h[i][j] = 0;
		}
	}
	for (size_t i = 0; i < 19; i++)
	{
		for (size_t j = 0; j < 30; j++)
		{
			h[i][j] = h5[i][j];
		}
	}

	cout << "Puzzle 5" << endl;
	M.x = 13;
	M.y = 7;
	T.x = 25;
	T.y = 11;
	A.x = 29;
	A.y = 11;
	goal_checking = true;
	backtracking(1, T, M,first_check);

	show_result();
	

	system("pause");
}



void find_optimal(point T) {
	D.clear();
	if (abs(A.x - (T.x - 2))<abs(A.x - T.x))
	{
		D.push_back(1);
	}
	if (abs(A.x - (T.x + 2))<abs(A.x - T.x))
	{
		D.push_back(2);

	}
	if (abs(A.y - (T.y - 2))<abs(A.y - T.y))
	{
		D.push_back(3);

	}
	if (abs(A.y - (T.y + 2))<abs(A.y - T.y))
	{
		D.push_back(4);
	}

	int count = 0;
	for (size_t i = 1; i < 6; i++)
	{
		count = 0;
		for (int j = 0; j < D.size(); j++)
		{
			if (i == D[j])
			{
				count++;
				break;
			}


		}
		if (count == 0)
		{
			D.push_back(i);
		}
	}

}

bool find_cycle(int i, point T, point M) {


	for (size_t j = 0; j < tesu_xy.size(); j++)
	{
		if (tesu_xy[j].x == T.x&&tesu_xy[j].y == T.y&&mino_xy[j].x == M.x&&mino_xy[j].y == M.y)
		{

			if (cycle[j] == i)
			{
				//cout << "중복된거 발견!" << j<<endl;
				return false;
			}
		}

	}
	return true;
}