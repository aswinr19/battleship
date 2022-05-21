#include <iostream>
#include "Utils.h"
using namespace std;

enum shipType{

	ST_NONE = 0,
	ST_AIRCRAFT_CARRIER,
	ST_BATTLESHIP,
	ST_CRUISER,
	ST_DESTROYER,
	ST_SUBMARINE
};

enum shipOrientationType{

	SO_HORIZONTAL = 0,
	SO_VERTICAL
};

struct shipPostionType{

	int row;
	int col;
};
int main()
{
	return 0;

}	
