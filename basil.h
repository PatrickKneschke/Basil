#ifndef BASIL_H
#define BASIL_H


#include <QWidget>
#include <memory>

namespace UI {
	class Basil;
}

class Basil : public QWidget {
	Q_OBJECT
public:
	Basil(QWidget *parent = nullptr);
	
private:
	std::unique_ptr<UI::Basil> ui;
};


#endif
