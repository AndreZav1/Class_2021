
#include"CControladora.h"

void main() {

	int widthS = 120, heightS = 30;
	Console::SetWindowSize(widthS, heightS);
	Console::CursorVisible = false;

	CControladora* control = new CControladora(widthS, heightS);

	char key = ' ';
	while (true) {

		if (control->you_defeat()) {
			break;
		}
		control->Borrar();
		if (_kbhit()) {
			control->Input(key);
		}
		control->Mover(widthS, heightS);
		control->Pintar();

		_sleep(80);
	}

	system("cls");
	Console::SetCursorPosition((widthS / 2) - 21, heightS / 2);
	cout << "Monigotes salvados: " << control->get_monigotes_salvados();
	Console::SetCursorPosition((widthS / 2) - 21, (heightS / 2) + 1);
	cout << "Monigotes perdidos: " << control->get_monigotes_perdidos();

	_sleep(2000);

	_getch();
}