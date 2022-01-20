#ifndef STOPWATCH_H
#define STOPWATCH_H


#include <QPainter>
#include <QWidget>
#include <QTimer>


class Stopwatch : public QWidget {
public:
	Stopwatch(QWidget *parent=nullptr);

public slots:
	void setTime(const int &min, const int &sec);
	void toggleOnOff();
	
signals:
	void timeout();
	
protected:
	void paintEvent(QPaintEvent *event);
	
	
	QTimer *updateTimer,
		   *clockTimer;
	QColor lineColor,
		   pointerColor,
		   clockColor,
		   wedgeColor;
};


#endif
