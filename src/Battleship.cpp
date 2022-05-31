#include <iostream>
#include <cstring>
#include "Utils.h"

using namespace std;

const char * INPUT_ERROR_STRING = "Input error! Please try again.";

enum {
	AIRCRAFT_CARRIER_SIZE = 5,
	BATTLESHIP_SIZE = 4,
	CRUISER_SIZE = 3,
		DESTROYER_SIZE = 3,
		SUBMARINE_SIZE = 2,

		BOARD_SIZE = 10,
		NUM_SHIPS = 5,
		PLAYER_NAME_SIZE = 8,
		MAX_SHIP_SIZE = AIRCRAFT_CARRIER_SIZE
	};

	enum ShipType{

		ST_NONE = 0,
		ST_AIRCRAFT_CARRIER,
		ST_BATTLESHIP,
		ST_CRUISER,
		ST_DESTROYER,
		ST_SUBMARINE
	};

	enum ShipOrientationType{

		SO_HORIZONTAL = 0,
		SO_VERTICAL
	};

	struct ShipPostionType{

		int row;
		int col;
	};

	struct Ship{

		ShipType shipType;
		int shipSize;
		ShipOrientationType orientation;
		ShipPostionType position;
	};

enum GuessType{

	GT_NONE = 0,
	GT_MISSED,
	GT_HIT
};

struct ShipPartType{

	ShipType shipType;
	bool isHit;
};

struct Player{
	char playerName[PLAYER_NAME_SIZE];
	Ship ships[NUM_SHIPS];
	GuessType guessBoard[BOARD_SIZE][BOARD_SIZE];
	ShipPartType shipBoard[BOARD_SIZE][BOARD_SIZE];
};


void InitializePlayer(Player& player,const char *playerName);
void Initializeship(Ship& ship,int shipSize ,ShipType shipType);
void PlayGame(Player& player1,Player& player2);
bool WantToPlayAgain();
void SetupBoards(Player& player);
void ClearBoards(Player& player);
void DrawBoards(const Player& player);

int main()
{

Player player1;
Player player2;

InitializePlayer(player1,"Player1");
InitializePlayer(player2,"Player2");

do{ 
	PlayGame(player1,player2);

}while(WantToPlayAgain());

return 0;

}


void InitializePlayer(Player& player,const char *playerName){

	if( playerName != nullptr && strlen(playerName) > 0 )
	{
		strcpy(player.playerName, playerName);
	}

	Initializeship( player.ships[0], AIRCRAFT_CARRIER_SIZE , ST_AIRCRAFT_CARRIER );
	Initializeship( player.ships[1], BATTLESHIP_SIZE , ST_BATTLESHIP);
	Initializeship( player.ships[2] , CRUISER_SIZE , ST_CRUISER );
	Initializeship(player.ships[3] , DESTROYER_SIZE , ST_DESTROYER );

	Initializeship(player.ships[4] , SUBMARINE_SIZE , ST_SUBMARINE );

}

void InitializeShip(Ship& ship ,int shipSize,ShipType shipType){

	ship.shipType = shipType;
	ship.shipSize = shipSize;
	ship.position.row = 0;
	ship.position.col = 0;
	ship.orientation = SO_HORIZONTAL;

}

void PlayGame(Player& player1,Player& player2){

	SetupBoards(player1);
	SetupBoards(player2);
}

bool WantToPlayAgain(){

	char input;
	const char validInput[2] = { 'y' , 'n' };
	input = GetCharacter("Would you like to play again? (y/n): ",INPUT_ERROR_STRING,validInput,2,CC_LOWER_CASE);

	return input == 'y';
}

void SetupBoards(Player& player ){

	ClearBoards(player);
	DrawBoards(player);
}

void ClearBoards(Player& player){
	
	for(int r = 0; r < BOARD_SIZE; r++){ 

		for(int c = 0; c < BOARD_SIZE; c++){

			player.guessBoard[r][c] = GT_NONE;
			player.shipBoard[r][c].shipType = ST_NONE;
			player.shipBoard[r][c].isHit = false;
		}
	}
}

void DrawSeparatorLine(){

	cout<<" ";
	for(int c = 0; c < BOARD_SIZE; c++){

		cout<<"+---";
	}
	cout<<"+";

}

void DrawColumnsRow(){
	
	cout<<"  ";
	for(int c = 0; c < BOARD_SIZE; c++){

		int columnName = c+1;
		cout<<" "<<columnName<<"  ";

	}

}

char GetShipRepresentation(const Player& player, int row, int col){

	if(player.shipBoard[row][col].isHit){

		return '*';
	}

	if(player.shipBoard[row][col].shipType == ST_AIRCRAFT_CARRIER){

		return 'A';
	}
	if(player.shipBoard[row][col].shipType == ST_BATTLESHIP){

		return 'B';
	}
	if(player.shipBoard[row][col].shipType == ST_CRUISER){

		return 'C';
	}
	if(player.shipBoard[row][col].shipType == ST_DESTROYER){

		return 'D';
	}
	if(player.shipBoard[row][col].shipType == ST_SUBMARINE){

		return 'S';
	}
	else{
		return ' ';
	}

}

char GetGuessRepresentationAt(const Player& player, int row, int col){

	if(player.guessBoard[row][col] == GT_HIT){

		return '*';
	}
	else if(player.guessBoard[row][col] == GT_MISSED)
	{
		return 'o';
	}
	else{

		return ' ';
	}
}
void DrawShipBoardRow(const Player& player , int row){

	char rowName = row + 'A';
	cout<<rowName << "|";

	for(int c = 0; c < BOARD_SIZE; c++){

		cout<<" "<< GetShipRepresentation(player, row, c) <<" |";
	}
}

void DrawGuessBoardRow(const Player& player , int row){

	char rowName = row + 'A';
	cout<<rowName<<"|";

	for(int c = 0; c < BOARD_SIZE; c++){

		cout<<" "<< GetGuessRepresentationAt(player, row, c) <<" |";
	}
}
void DrawBoards(const Player& player){

	DrawColumnsRow();
	DrawColumnsRow();

	cout<<endl;

	for(int r = 0; r < BOARD_SIZE; r++){

		DrawSeparatorLine();
		cout<<" ";
		DrawSeparatorLine();
		cout<<endl;
		DrawShipBoardRow(player , r);
		cout<<" ";
		DrawGuessBoardRow(player , r);
	}

	DrawSeparatorLine();
	cout<<" ";
	DrawSeparatorLine();
	cout<<endl;
}
