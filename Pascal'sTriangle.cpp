// 
// Pascal'sTriangle.cpp : Implementation of function pascal_val.
// Finds values of Pascal's Triangle given by row and position.
// Richard Pittman - 10/27/16
//

#include <assert.h>
#include <iostream>
#include <map>
#include <stdlib.h>
#include <string>
#include <utility>

typedef std::pair<int, int> coord;
typedef std::map<coord, unsigned __int64> trimap;

//Finds value in pascal's triangle of row, pos
//uses trimap triangle to record previously computed values
unsigned __int64 pascal_val(int row, int pos, trimap* triangle)
{
	//check input
	if (row < 0 || pos < 0 || pos > row) 
		throw 1;
	//check if edge of row
	if (pos == 0 || pos == row)
	{
		return 1;
	}
	//recursive call
	//find answer in triangle
	coord coords(pos, row);
	trimap::iterator value = triangle->find(coords);
	if (value == triangle->end()) //value not recorded
	{
		unsigned __int64 answer = pascal_val(row - 1, pos - 1, triangle) + pascal_val(row - 1, pos, triangle);
		triangle->insert(std::pair<coord, unsigned __int64>(coords, answer));
		return answer;
	}
	else
	{
		return value->second;
	}
}

int main()
{
	trimap *triangle = new trimap();
	try 
	{
		std::cout << "(0, 0) = " << pascal_val(0, 0, triangle) << '\n';
		assert (pascal_val(0, 0, triangle) == 1);
		std::cout << "(700, 0) = " << pascal_val(700, 0, triangle) << '\n';
		assert (pascal_val(700, 0, triangle) == 1);
		std::cout << "(700, 700) = " << pascal_val(700, 700, triangle) << '\n';
		assert (pascal_val(700, 700, triangle) == 1);
		std::cout << "(7, 4) = " << pascal_val(7, 4, triangle) << '\n';
		assert (pascal_val(7, 4, triangle) == 35);
		std::cout << "(50, 20) = " << pascal_val(50, 20, triangle) << '\n';
		std::cout << "(500, 249) = " << pascal_val(500, 249, triangle) << '\n';
	}
	catch (int e)
	{
		switch (e) 
		{
		case 1: //illegal input exception
			std::cerr << "Illegal Input in pascal_val(row, pos)" << '\n'
				<< "Usage: ensure row and pos are legal pascal position values" 
				<< '\n';
			break;
		default:
			break;
		}
	}
	return 0;
}

