#ifndef __UTILS_H__
#define __UTILS_H__

enum CharacterCaseType{
	CC_UPPER_CASE = 0,
	CC_LOWER_CASE,
	CC_EITHER
};


char getCharacter(const char * prompt , const char * error);

char getCharacter(const char * prompt , const char * error , const char validInputs[] , int  validInputLength);

int GetInteger(const char * prompt , const char error , const int validInput[] , int validInputLength);

void ClearScreen();

void WaitForKeyPress();

#endif
