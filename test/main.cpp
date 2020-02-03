#include "Son.h"//Son里面必须带Father,故只写Son即可

int main() {
	Son s("肉肉", 21, "红烧肉", "galgame");
	Father f;
	Mother m;
	
	s.ball();
	s.dance();
	cout << s.getGame() << endl;

	return 0;
}
