#include "Boy.h"
#include "Girl.h"
#include "Database.h"

int main() {
	Database data;
	data.load();
	data.print();
	data.automatch();

	return 0;
}