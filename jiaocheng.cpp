#include"global.h"
using namespace std;
fstream _jc;

jiaocheng::jiaocheng(HANDLE h)
{
	hOut = h;
	_jc.open("jiaocheng.txt", ios::in);
}

void jiaocheng::readNext(int kb,int i)
{
	COORD CrPos = { 0, i + 2 };
	if (kb != 80) return nmd(i);
	char a[15000]="";
	_jc.getline(a, 15000);
	if (a[0] == '0') {							//0为加长
		COORD CrPos = { 0, i+2 };
		SetConsoleCursorPosition(hOut, CrPos);
		cout << "                                            \n                                           \n";
		i += 4;
	}
	if (a[0] == '1') {							 //1为换页
		system("cls");
		i = 0;
	}
	if (_jc.peek() == '2' || a[0] == '2') return;
	while (_jc.peek() != '0' && _jc.peek() != '1' && _jc.peek() != '2') {
		_jc.getline(a, 15000);
		cout << a << endl;
		i++;
	}
	return animeFordown(i);
}

void jiaocheng::Print()
{
}

void jiaocheng::animeFordown(int row)
{
	COORD CrPos = { 0, row+2 };
	int ch;
	SetConsoleCursorPosition(hOut, CrPos);
	cout << "按 下方向键 让我们继续";
	CrPos = { (SHORT)22,(SHORT)(row + 2) };
	while (1) {
		SetConsoleCursorPosition(hOut, CrPos);
		for (int i = 0; i < 250; i++) {
			Sleep(10);
			if (_kbhit()) {
				ch = _getch();
				if (ch < 150)	return readNext(ch,row);
			}
			if (i % 50 == 0) cout << '.';
		}
		Sleep(50);
		SetConsoleCursorPosition(hOut, CrPos);
		cout << "                  ";
	}
}

void jiaocheng::animeForRight(int row)   //无用
{
	COORD CrPos = { 0, row + 2 };
	while (1) {
		SetConsoleCursorPosition(hOut, CrPos);
		cout << "按让我们翻到下一页" << endl;
		for (int i = 0; i < 100; i++) {
			Sleep(10);
			if (_kbhit())
				return readNext(_getch(),row);
		}
		SetConsoleCursorPosition(hOut, CrPos);
		cout << "                    " << endl;
		for (int i = 0; i < 100; i++) {
			Sleep(10);
			if (_kbhit())
				return readNext(_getch(),row);
		}
	}
}

void jiaocheng::nmd(int num)
{
	cout << "\n念在你是祖国的花朵，就再给你一次机会\n";
	return animeFordown(num);
}
