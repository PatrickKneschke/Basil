
#include "stopwatch.h"


Stopwatch::Stopwatch(QWidget *parent) :	
	QWidget(parent),
	lineColor(0, 0, 0),
	pointerColor(0, 120, 180),
	clockColor(150, 150, 150),
	wedgeColor(180, 40, 40)
{
	updateTimer = new QTimer(this);
	QObject::connect(updateTimer, &QTimer::timeout,
					 this		, qOverload<>(&QWidget::update));
	updateTimer->start(1000);
	
	clockTimer = new QTimer(this);
	clockTimer->setSingleShot(true);
	clockTimer->stop();
	QObject::connect(clockTimer, &QTimer::timeout,
					 this	   , &Stopwatch::timeout);
}


void Stopwatch::setTime(const int &min, const int &sec) {
	clockTimer->setInterval(60000*min + 1000*sec);
}


void Stopwatch::toggleOnOff() {
	if(clockTimer->isActive()) {
		clockTimer->setInterval(clockTimer->remainingTime());
		clockTimer->stop();
	}
	else {
		clockTimer->start();
	}
}


void Stopwatch::paintEvent(QPaintEvent *event) {
	static const QPoint pointer[4] = {
			QPoint( 3,   3),
			QPoint( 0,   5),
			QPoint(-3,   3),
			QPoint(	0, -90)
	};
	
	int radius = qMin(width(), height()) / 2;
	float angle = (clockTimer->isActive() ? clockTimer->remainingTime() : clockTimer->interval()) / 10000.0;
	
	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing);
	painter.translate(width()/2, height()/2);
	
	// draw clock background
	painter.setPen(lineColor);
	painter.setBrush(clockColor);
	painter.drawEllipse(QPointF(0.0, 0.0), radius, radius);
	
	// draw clock wedge from top to pointer
	painter.setBrush(wedgeColor);
	painter.drawPie(-radius, -radius, 2*radius, 2*radius, 90*16, -angle*16);
	
	// draw pointer
	painter.setBrush(pointerColor);
	painter.save();
	painter.scale(radius/100.0, radius/100.0);
	painter.rotate(angle);
	painter.drawConvexPolygon(pointer, 4);
	painter.restore();
	
	// draw minute marks
	for(int i=0; i<60; i++) {
		painter.drawLine( (i%5==0 ? 0.8 : 0.9)*radius, 0, 0.95*radius, 0);
		painter.rotate(6.0);
	}	
}
