#pragma once
class qipan {
public:
	qipan();
	void rand();
	void move(int);
	void up();
	void down();
	void left();
	void right();
	int color(int);
	void Print();
	bool isOver();

	int qp[4][4];
	bool canMoveUp;
	bool canMoveDown;
	bool canMoveLeft;
	bool canMoveRight;
};


