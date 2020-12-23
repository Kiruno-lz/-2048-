#include"global.h"
using namespace std;
qipan::qipan()
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			qp[i][j] = 0;
	rand();
	rand();
	canMoveUp=1;
	canMoveDown=1;
	canMoveLeft=1;
	canMoveRight=1;
}

void qipan::rand()
{
	default_random_engine e;
	uniform_real_distribution<double> u(0, 16);
	int a1 =u(e)/4,a2 =u(e)/4,i=0;
	while (qp[a1][a2] != 0 && i < 100)
		a1 = u(e), a2 = u(e), i++;
	qp[a1][a2] = 2;

}

void qipan::move(int key)
{
	switch (key) {
	case 72:
		up();
		rand();
		break;
	case 75:
		left();
		rand();
		break;
	case 77:
		right();
		rand();
		break;
	case 80:
		down();
		rand();
		break;
	default:
		break;
	}
}

void qipan::up() {
	canMoveUp = 0;
	for (int j = 0; j < 4; j++) {
		for (int i = 3, a = 2; i >= 0; i--) {
			if (qp[i][j] != 0) {
				if (qp[i][j] == qp[a][j] && a != i) {
					qp[i][j] += qp[a][j];
					qp[a][j] = 0;
				}
				else
					a = i;
			}
		}
		for (int i = 0; i < 4; i++) {
			for (int k = 3; k > 0; k--) {
				if (qp[k - 1][j] == 0)
					swap(qp[k - 1][j], qp[k][j]), canMoveUp++;
			}
		}
	}
}

void qipan::down() {
	canMoveDown = 0;
	for (int j = 0; j < 4; j++) {
		for (int i = 3, a = 2; i >= 0; i--) {
			if (qp[i][j] != 0) {
				if (qp[i][j] == qp[a][j] && a != i) {
					qp[i][j] += qp[a][j];
					qp[a][j] = 0;
				}
				else
					a = i;
			}
		}
		for (int i = 0; i < 4; i++) {
			for (int k = 1; k < 4; k++) {
				if (qp[k][j] == 0)
					swap(qp[k - 1][j], qp[k][j]), canMoveDown++;
			}
		}
	}
}

void qipan::left() {
	canMoveLeft = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 1, a = 0; j < 4; j++) {
			if (qp[i][j] != 0) {
				if (qp[i][j] == qp[i][a] && a != j) {
					qp[i][j] += qp[i][a];
					qp[i][a] = 0;
				}
				else
					a = j;
			}
		}
		for (int j = 0; j < 4; j++) {
			for (int k = 3; k > 0; k--) {
				if (qp[i][k - 1] == 0)
					swap(qp[i][k - 1], qp[i][k]), canMoveLeft++;
			}
		}
	}
}

void qipan::right() {
	canMoveRight=0;
	for (int i = 0; i < 4; i++) {
		for (int j = 3, a = 2; j >= 0; j--) {
			if (qp[i][j] != 0) {
				if (qp[i][j] == qp[i][a] && a != j) {
					qp[i][j] += qp[i][a];
					qp[i][a] = 0;
				}
				else
					a = j;
			}
		}
		for (int j = 0; j < 4; j++) {
			for (int k = 1; k < 4; k++) {
				if (qp[i][k] == 0)
					swap(qp[i][k - 1], qp[i][k]),canMoveRight++;
			}
		}
	}
}

void qipan::Print()
{
	system("cls");
	printf("按除方向键任意键可结束体验...\n");
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++)
			printf("%4d|", qp[i][j]);
		cout << '\n';
	}
	Sleep(150);
}

bool qipan::isOver()
{
	return canMoveUp+canMoveDown+canMoveLeft+canMoveRight;
}

int qipan::color(int num)   //未导入颜色,能力限制
{
	switch (num) {
	case 2:
		break;
	case 4:
		break;
	case 8:
		break;
	case 16:
		break;
	case 32:
		break;
	case 64:
		break;
	case 128:
		break;
	case 256:
		break;
	case 512:
		break;
	default:
		break;
	}
	return 0;
}

