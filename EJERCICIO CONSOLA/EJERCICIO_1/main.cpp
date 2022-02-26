#include<conio.h>

#include"CControladora.h"

void main() {

	const int widthS = 120, heightS = 30;
	Console::SetWindowSize(widthS, heightS);
	Console::CursorVisible = false;

	CControladora* control = new CControladora();

	while (true) {

		control->erase();
		control->move(widthS, heightS);

		_sleep(80);
	}

	_getch();
}