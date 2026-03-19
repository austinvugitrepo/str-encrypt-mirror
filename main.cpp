#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream> //string stream

using namespace std;

const int NUM_OF_TOKENS = 10;

int tokenize(string myString, string strArray[NUM_OF_TOKENS]){
	
    istringstream iss(myString);
    string token;
	int i = 0;
    while (getline(iss, token, ' ')) //iss functions as cin in this scenario, instead of user input into token, its iss into token
    {
		strArray[i] = token;
		i++;
   }
   
   return i;
}


int main ()
{
      string str = " ";
        string arr[NUM_OF_TOKENS];

	// TODO: prompt the user to input a string
	 cout << "Input a string: ";
           getline(cin, str);
	// TODO: call the tokenize function
	 int tsize = tokenize(str, arr);
	// TODO: display the tokens
	 for(int i = 0; i < tsize; i++){
           cout << arr[i] << endl;
           }
	// TODO: call a function to encrypt strings that starts with a vowel

	// TODO: call a function to encrypt strings that starts with a consonant

	// TODO: call a function to encrypt short strings
    
	// TODO: display the encrypted strings (the results)

    return 0; 
}

