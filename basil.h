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
	
public slots:
	void startSession();
	void nextTask();
	void reset();
	
private:
	void setupConnections();
	void updateProgressLabel();

	UI::Basil *ui;	
	int pomodoroCount;
	bool takeBreak;
};


#endif
