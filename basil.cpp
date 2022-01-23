
#include "ui_basil.h"
#include "basil.h"


Basil::Basil(QWidget *parent) : 
	QWidget(parent), 
	ui(new UI::Basil),
	pomodoroCount(0),
	takeBreak(true)
{
	setMinimumSize(1080, 480);
	ui->setupUI(this);
	ui->setupPalettes();
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


void Basil::updateProgressLabel() {
	ui->progressLabel->setText( QString::number(pomodoroCount) + " / " + QString::number(ui->pomodoroGoal->value()) + " completed!" );
}


void Basil::startSession() {
	QSound::play("bell.wav");
	
	if(ui->pomodoroGoal->value() == 0) {
		reset();
		return;
	}
	
	ui->pomodoroMinutes->setReadOnly(true);
	ui->shortBreakMinutes->setReadOnly(true);
	ui->longBreakMinutes->setReadOnly(true);
	ui->pomodoroGoal->setReadOnly(true);
		
	ui->stopwatch->setTime(ui->pomodoroMinutes->value(), 0);
	ui->progressLabel->setVisible(true);
	updateProgressLabel();
		
	setPalette(ui->pomodoroPalette);
		
	disconnect(ui->startButton, &QPushButton::clicked, 
			   this,            &Basil::startSession);
}


void Basil::reset() {
	pomodoroCount = 0;
	takeBreak = true;

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
	
	setPalette(QPalette());
		
	connect(ui->startButton, &QPushButton::clicked, 
	        this,	         &Basil::startSession);
}


void Basil::nextTask() {		
	if(takeBreak) {
		++pomodoroCount;
		updateProgressLabel();
		if(pomodoroCount >= ui->pomodoroGoal->value()) {
			reset();
			return;
		}
		if(pomodoroCount % 3 == 0) {
			setPalette(ui->longBreakPalette);
			ui->stopwatch->setTime(ui->longBreakMinutes->value(), 0);
		}
		else {
			setPalette(ui->shortBreakPalette);
			ui->stopwatch->setTime(ui->shortBreakMinutes->value(), 0);
		}
		takeBreak = false;
	}
	else {
		setPalette(ui->pomodoroPalette);
		ui->stopwatch->setTime(ui->pomodoroMinutes->value(), 0);
		takeBreak = true;
	}
	ui->stopwatch->toggleOnOff();
}
