#include <iostream>
#include <vector>
#include "Square.h"

int main() {

	int num;

	cin >> num;
	vector<Square> squares;

	for (int i = 0; i < num; i++)
	{
		string pname;
		int px, py;
		unsigned int pside;

		cin >> pname >> px >> py >> pside;
		squares.push_back(Square(pname, px, py, pside));
	}

	cout << endl << endl;
	cout << "Squares in increasing order of area\n";

	for (int i = 0; i < num - 1; i++)
	{
		for (int j = 0; j < num - i - 1; j++)
		{
			if (squares[j].getArea() > squares[j + 1].getArea())
			{
				swap(squares[j], squares[j + 1]);
			}
		}
	}
	for (const Square& s : squares)
	{
		cout << s.getName() << "(" << s.getX() << ", " << s.getY() << ") side=" << s.getSide()
			<< ", area=" << s.getArea() << endl;
	}

	cout << endl << endl;
	cout << "Squares in increasing order of max x-coordinate\n";

	for (int i = 0; i < num - 1; i++)
	{
		for (int j = 0; j < num - i - 1; j++)
		{
			if (squares[j].getX() + (int)squares[j].getSide() > squares[j + 1].getX() + (int)squares[j + 1].getSide())
			{
				swap(squares[j], squares[j + 1]);
			}
		}
	}
	for (const Square& s : squares)
	{
		cout << s.getName() << "(" << s.getX() + (int)s.getSide() << ", " << s.getY() << ") side=" << s.getSide()
			<< ", area=" << s.getArea() << endl;
	}

	cout << endl << endl;
	cout << "Squares in increasing order of max y-coordinate\n";

	for (int i = 0; i < num - 1; i++)
	{
		for (int j = 0; j < num - i - 1; j++)
		{
			if (squares[j].getY() + (int)squares[j].getSide() > squares[j + 1].getY() + (int)squares[j + 1].getSide())
			{
				swap(squares[j], squares[j + 1]);
			}
		}
	}
	for (const Square& s : squares)
	{
		cout << s.getName() << "(" << s.getX() << ", " << s.getY() + (int)s.getSide() << ") side=" << s.getSide()
			<< ", area=" << s.getArea() << endl;
	}

	return 0;
}


Point::Point(int px, int py)
{
	x = px;
	y = py;
}
int Point::getX() const
{
	return x;
}
int Point::getY() const
{
	return y;
}
void Point::setX(int px)
{
	x = px;
}
void Point::setY(int py)
{
	y = py;
}


Square::Square(const string pname, int px, int py, unsigned int pside)
	:Point(px, py)
{
	name = pname;
	side = pside;
	area = pside * pside;
}
unsigned int Square::getSide() const
{
	return side;
}
unsigned int Square::getArea() const
{
	return area;
}
string Square::getName() const
{
	return name;
}
void Square::setSide(unsigned int pside)
{
	side = pside;
}
void Square::setArea(unsigned int parea)
{
	area = parea;
}
void Square::setName(string pname)
{
	name = pname;
}