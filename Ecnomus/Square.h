#pragma once
class Square
{
public:
	Square(int , int , char , bool, bool);
	int getRow();
	void setRow(int);
	int getColumn();
	void setColumn(int);
	char getSquareSimbol();
	void setSquareSimbol(char squareSimbol);
	bool isFill();
	void setFill(bool);
	bool isShow();
	void setShow(bool);

	~Square();
private:
	int row;
	int column;
	bool fill;
	bool show;
	char simbol;

};

