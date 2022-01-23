#ifndef UI_BASIL_H
#define UI_BASIL_H


#include "stopwatch.h"
#include <QFrame>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPalette>
#include <QPushButton>
#include <QSpinBox>
#include <QVBoxLayout>


namespace UI {

class Basil {
public:
	void setupUI(QWidget *parent) {
		mainLayout 			= new QHBoxLayout();
		
		stopwatch 			= new Stopwatch(parent);		
		inputFrame 			= new QFrame(parent);
		inputFrame->setLineWidth(3);
		inputFrame->setFrameStyle(QFrame::Panel | QFrame::Raised);
		inputLayout 		= new QVBoxLayout(inputFrame);
		
		timeSetFrame 		= new QFrame(inputFrame);
		timeSetFrame->setFrameStyle(QFrame::Box | QFrame::Plain);
		timeSetLayout 		= new QGridLayout(timeSetFrame);
		timeSetLabel1 		= new QLabel("Pomodoro : ", timeSetFrame);
		timeSetLabel2 		= new QLabel("min", timeSetFrame);
		timeSetLabel3 		= new QLabel("ShortBreak : ", timeSetFrame);
		timeSetLabel4 		= new QLabel("min", timeSetFrame);
		timeSetLabel5 		= new QLabel("Long Break : ", timeSetFrame);
		timeSetLabel6 		= new QLabel("min", timeSetFrame);
		pomodoroMinutes 	= new QSpinBox(timeSetFrame);
		pomodoroMinutes->setRange(0, 60);
		shortBreakMinutes 	= new QSpinBox(timeSetFrame);
		shortBreakMinutes->setRange(0, 60);
		longBreakMinutes 	= new QSpinBox(timeSetFrame);
		longBreakMinutes->setRange(0, 60);
		
		goalFrame			= new QFrame(inputFrame);
		goalFrame->setFrameStyle(QFrame::Box | QFrame::Plain);
		goalLayout 			= new QHBoxLayout(goalFrame);
		goalLabel1 			= new QLabel("I will do", goalFrame);
		goalLabel2 			= new QLabel("pomodoros.", goalFrame);
		pomodoroGoal 		= new QSpinBox(goalFrame);
		
		progressFrame		= new QFrame(inputFrame);
		progressFrame->setFrameStyle(QFrame::Box | QFrame::Plain);
		progressLayout 		= new QHBoxLayout(progressFrame);
		startButton 		= new QPushButton("Start", progressFrame);
		startButton->setFont(QFont("Arial", 15, QFont::Bold));
		progressLabel 		= new QLabel("0/n completed", progressFrame);
		progressLabel->setAlignment(Qt::AlignCenter);
		progressLabel->setFont(QFont("Arial", 12, QFont::Bold));
		progressLabel->setVisible(false);

		parent->setLayout(mainLayout);
		mainLayout->addWidget(stopwatch,  2);
		mainLayout->addWidget(inputFrame, 3);
		
		timeSetLayout->addWidget(timeSetLabel1,     0, 0);
		timeSetLayout->addWidget(pomodoroMinutes,   0, 1);
		timeSetLayout->addWidget(timeSetLabel2,     0, 2);
		timeSetLayout->addWidget(timeSetLabel3,     1, 0);
		timeSetLayout->addWidget(shortBreakMinutes, 1, 1);
		timeSetLayout->addWidget(timeSetLabel4,     1, 2);
		timeSetLayout->addWidget(timeSetLabel5,     2, 0);
		timeSetLayout->addWidget(longBreakMinutes,  2, 1);
		timeSetLayout->addWidget(timeSetLabel6,     2, 2);

		goalLayout->addWidget(goalLabel1);
		goalLayout->addWidget(pomodoroGoal);
		goalLayout->addWidget(goalLabel2);
		
		progressLayout->addWidget(startButton,   2);
		progressLayout->addWidget(progressLabel, 3);

		inputLayout->addWidget(timeSetFrame,  3);
		inputLayout->addWidget(goalFrame, 	  1);
		inputLayout->addWidget(progressFrame, 1);
	}
	
	
	void setupPalettes() {
		pomodoroPalette.setColor(QPalette::Window, 	 QColor(190, 90, 90));
		pomodoroPalette.setColor(QPalette::Light,    QColor(200, 100, 100));
		pomodoroPalette.setColor(QPalette::Dark,     QColor(160, 60, 60));
		
		shortBreakPalette.setColor(QPalette::Window, QColor(90, 90, 190));
		shortBreakPalette.setColor(QPalette::Light,  QColor(100, 100, 200));
		shortBreakPalette.setColor(QPalette::Dark,   QColor(60, 60, 160));
		
		longBreakPalette.setColor(QPalette::Window, QColor(90, 190, 90));
		longBreakPalette.setColor(QPalette::Light,  QColor(100, 200, 100));
		longBreakPalette.setColor(QPalette::Dark,   QColor(60, 160, 60));
	}
	
	
	QHBoxLayout *mainLayout;
	
	Stopwatch   *stopwatch;
	QFrame		*inputFrame;
	QVBoxLayout *inputLayout;
	
	QFrame		*timeSetFrame;
	QGridLayout *timeSetLayout;
	QLabel		*timeSetLabel1, *timeSetLabel2, *timeSetLabel3,
	 			*timeSetLabel4, *timeSetLabel5, *timeSetLabel6;
	QSpinBox 	*pomodoroMinutes;
	QSpinBox 	*shortBreakMinutes;
	QSpinBox 	*longBreakMinutes;
	
	QFrame      *goalFrame;
	QHBoxLayout *goalLayout;
	QLabel		*goalLabel1, *goalLabel2;
	QSpinBox	*pomodoroGoal;
	
	QFrame		*progressFrame;
	QHBoxLayout *progressLayout;
	QLabel		*progressLabel;
	QPushButton *startButton;
	
	QPalette pomodoroPalette;
	QPalette shortBreakPalette;
	QPalette longBreakPalette;
};

} //UI


#endif
