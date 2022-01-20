
#include <QApplication>
#include "basil.h"

int main(int argc, char * argv[]) {
	QApplication app(argc, argv);
	
	Basil basil;
	basil.show();
	
	return app.exec();
}
