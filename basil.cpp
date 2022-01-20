
#include "ui_basil.h"
#include "basil.h"


Basil::Basil(QWidget *parent) : QWidget(parent), ui(new UI::Basil) {
	ui->setupUI(this);
	setMinimumSize(1080, 480);
}

Basil::~Basil() {
	delete ui;
}
