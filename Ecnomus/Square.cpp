#include "Square.h"

Square::Square(int row, int column, char squareSimbol, bool fill, bool show)
{
	this->row = row;
	this->column = column;
	this->simbol = squareSimbol;
	this->fill = fill;
	this->show = show;
}

Square::~Square()
{
}

int Square::getRow() {
	return row;
}

void Square::setRow(int row) {
	this->row = row;
}

int Square::getColumn() {
	return column;
}

void Square::setColumn(int column) {
	this->column = column;
}

char Square::getSquareSimbol() {
	return simbol;
}

void Square::setSquareSimbol(char squareSimbol) {
	this->simbol = squareSimbol;
}

bool Square::isFill() {
	return fill;
}

void Square::setFill(bool fill) {
	this->fill = fill;
}


bool Square::isShow() {
	return show;
}

void Square::setShow(bool show) {
	this->show = show;
}
