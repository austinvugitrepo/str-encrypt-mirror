#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

const int NUM_OF_TOKENS = 10;

int tokenize(string myString, string strArray[NUM_OF_TOKENS]){
	
    istringstream iss(myString);
    string token;
	int i = 0;
    while (getline(iss, token, ' '))
    {
		strArray[i] = token;
		i++;
   }
   
   return i;
}


int main ()
{

	// TODO: prompt the user to input a string
	
	// TODO: call the tokenize function
	
	// TODO: display the tokens
	
	// TODO: call a function to encrypt strings that starts with a vowel

	// TODO: call a function to encrypt strings that starts with a consonant

	// TODO: call a function to encrypt short strings
    
	// TODO: display the encrypted strings (the results)

    return 0; 
}

