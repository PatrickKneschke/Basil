#ifndef BASIL_H
#define BASIL_H


#include <QWidget>


namespace UI {
	class Basil;
}

class Basil : public QWidget {
	Q_OBJECT
public:
	Basil(QWidget *parent = nullptr);
	~Basil();
	
private:
	UI::Basil *ui;
};


#endif
