#include "Utils.h"
#include <iostream>
#include <cctype>

using namespace std;


char getCharacter(const char* prompt , const char* error){

const int IGNORE_CHARS = 256;

	char input;
	bool failure;

	do{
		failure = false;

		cout<<prompt;
		cin>>input;

		if(cin.fail()){
			cin.clear();
			cin.ignore(IGNORE_CHARS,'\n');
			cout<<error<<endl;
			failure = true;
		}else{
			cin.ignore(IGNORE_CHARS,'\n');

			if(isalpha(input)){
				
				input = tolower(input);
			}else{
				cout<<error<<endl;
				failure = true;
			}
		}
	}while(failure);

	return input;
}




char getCharacter(const char* prompt , const char* error , const char validInputs[] , int validInputLength)
{

const int IGNORE_CHARS = 256;

	char input;
	bool failure;

	do{
		failure = false;

		cout<<prompt;
		cin>>input;

		if(cin.fail()){
			cin.clear();
			cin.ignore(IGNORE_CHARS,'\n');
			cout<<error<<endl;
			failure = true;
		}
		else
		{
			cin.ignore(IGNORE_CHARS,'\n');

			if(isalpha(input)){

				input = tolower(input);

				for(int i = 0; i < validInputLength; i++){

					if(input == validInputs[i]){
						return input;
					}
				}
			}
			cout<<error<<endl;
			failure = true;
		}
	}while(failure);

	return input;
}

