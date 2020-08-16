#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int cnt[40000], table[110][13], bn;

struct data {
	int id, dn;
	data* id_prev, * id_next, * dn_prev, * dn_next;
	data* alloc(int _id, int _dn, data* id_n, data* dn_n) {
		id = _id, dn = _dn, id_prev = 0, id_next = id_n, dn_prev = 0, dn_next = dn_n;
		return this;
	}
}*mem[10001], * dat[40000], buf[1000000];

void push(int id, int dn) {
	cnt[dn]++;
	mem[id] = dat[dn] = buf[bn++].alloc(id, dn, mem[id], dat[dn]);
	if (mem[id]->id_next) mem[id]->id_next->id_prev = mem[id];
	if (dat[dn]->dn_next) dat[dn]->dn_next->dn_prev = dat[dn];
}
void del(data* p) {
	int id = p->id, dn = p->dn;
	cnt[dn]--;
	if (p->id_prev)p->id_prev->id_next = p->id_next;
	if (p->id_next)p->id_next->id_prev = p->id_prev;
	if (p->dn_prev)p->dn_prev->dn_next = p->dn_next;
	if (p->dn_next)p->dn_next->dn_prev = p->dn_prev;
	if (mem[id] == p) mem[id] = p->id_next;
	if (dat[dn] == p) dat[dn] = p->dn_next;
}
void del_id(int id) {
	while (mem[id]) del(mem[id]);
}
int days(int y, int m) {
	int d[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (y % 400 == 0 || (y % 4 == 0 && y % 100)) d[2] = 29;
	return d[m];
}
void table_fill() {
	int i, j, y;
	for (i = 2018; i < 2118; i++) {
		y = i - 2018;
		for (j = 1; j <= 12; j++) {
			table[y][j] = table[y][j - 1] + days(i, j);
		}
		table[y + 1][0] = table[y][12];
	}
}
void init() {
	int i, j;
	bn = 0;
	for (i = 0; i <= 10000; i++)mem[i] = 0;
	for (i = 0; i < 40000; i++) dat[i] = 0, cnt[i] = 0;
}
int encode(int y, int m, int d)
{
	return table[y - 2018][m - 1] + d;
}
void output() {
	int y, m, d, date, sum = 0;
	scanf("%4d%2d%d", &y, &m, &d);
	date = encode(y, m, d);
	for (int i = 0; i < 30; i++) {
		sum += cnt[date + i];
	}
	printf("%d\n", sum);
}

void reserve() {
	int id, method, repeat, y, m, d, dn, i;
	scanf("%d %d %d", &id, &method, &repeat);
	scanf("%4d%2d%2d", &y, &m, &d);
	dn = encode(y, m, d);
	if (method == 0) repeat = 1;
	for (i = 0; i < repeat; i++) {
		push(id, dn);
		if (method == 8) {
			if (++m > 12)y++, m = 1;
			dn = encode(y, m, d);
		}
		else if (method == 9) {
			dn = encode(++y, m, d);
		}
		else dn += method;
		if (y > 2117 || dn > table[99][12]) break;
	}
}
void cancel() {
	int method, id, y, m, d, dn;
	scanf("%d", &method);
	if (method == 2) {
		scanf("%d", &id);
		del_id(id);
	}
	else {
		scanf("%4d%2d%2d", &y, &m, &d);
		dn = encode(y, m, d);
		while (dat[dn]) {
			if (method == 0) del(dat[dn]);
			else del_id(dat[dn]->id);
		}
	}
}
int main() {
	int TC, N, cmd;
	table_fill();
	scanf("%d", &TC);
	while (TC--) {
		scanf("%d", &N);
		init();
		while (N--) {
			scanf("%d", &cmd);
			switch (cmd) {
			case 1:
				reserve(); break;
			case 2:
				cancel(); break;
			case 3:
				output(); break;
			}
		}
	}
	return 0;
}
