
#include "ui_basil.h"
#include "basil.h"


Basil::Basil(QWidget *parent) : 
	QWidget(parent), 
	ui(new UI::Basil),
	pomodoroCount(0),
	takeBreak(false)
{
	setMinimumSize(1080, 480);
	ui->setupUI(this);
	setupConnections();
}


Basil::~Basil() {
	delete ui;
}


void Basil::setupConnections() {
		connect(ui->stopwatch, &Stopwatch::timeout, 
		        this,          &Basil::nextTask);
		connect(ui->startButton, &QPushButton::clicked, 
		        this,            &Basil::startSession);
		connect(ui->startButton, &QPushButton::clicked, 
				ui->stopwatch,   &Stopwatch::toggleOnOff);
		connect(ui->startButton, &QPushButton::clicked, this, [&](){
			ui->startButton->setText(ui->startButton->text()=="Pause" ? "Resume" : "Pause");
		});
}


void Basil::startSession() {
		if(ui->pomodoroGoal->value() == 0)
			return;
		takeBreak = true;		
		pomodoroCount = 0;
	
		ui->pomodoroMinutes->setReadOnly(true);
		ui->shortBreakMinutes->setReadOnly(true);
		ui->longBreakMinutes->setReadOnly(true);
		ui->pomodoroGoal->setReadOnly(true);
		
		ui->stopwatch->setTime(ui->pomodoroMinutes->value(), 0);
		
		disconnect(ui->startButton, &QPushButton::clicked, 
				   this,            &Basil::startSession);
}


void Basil::reset() {
	ui->pomodoroMinutes->setValue(0);
	ui->pomodoroMinutes->setReadOnly(false);
	ui->shortBreakMinutes->setValue(0);
	ui->shortBreakMinutes->setReadOnly(false);
	ui->longBreakMinutes->setValue(0);
	ui->longBreakMinutes->setReadOnly(false);
	ui->pomodoroGoal->setValue(0);
	ui->pomodoroGoal->setReadOnly(false);
		
	ui->stopwatch->setTime(0, 0);
		
	ui->startButton->setText("Start");
	connect(ui->startButton, &QPushButton::clicked, 
	        this,	         &Basil::startSession);
}


void Basil::nextTask() {
	if(takeBreak) {
		++pomodoroCount;
		if(pomodoroCount >= ui->pomodoroGoal->value()) {
			reset();
			return;
		}
		if(pomodoroCount % 3 == 0) {
			ui->stopwatch->setTime(ui->longBreakMinutes->value(), 0);
		}
		else {
			ui->stopwatch->setTime(ui->shortBreakMinutes->value(), 0);
		}
		takeBreak = false;
	}
	else {
		ui->stopwatch->setTime(ui->pomodoroMinutes->value(), 0);
		takeBreak = true;
	}
	ui->stopwatch->toggleOnOff();
}
