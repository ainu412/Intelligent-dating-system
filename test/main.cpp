#include "Son.h"//Son��������Father,��ֻдSon����

int main() {
	Son s("����", 21, "������", "galgame");
	Father f;
	Mother m;
	
	s.ball();
	s.dance();
	cout << s.getGame() << endl;

	return 0;
}
