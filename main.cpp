#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream> //string stream
#include <cctype>

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
      string str = " "; // string is character array
        string arr[NUM_OF_TOKENS];

	// TODO: prompt the user to input a string
	 cout << "Input a string: ";
           getline(cin, str);
           for(int i = 0; i < str.length(); i++){ //.length() from <string>
            if(ispunct(str[i])){ // if character is punctuation then erase 1 character at current index 
               str.erase(i, 1); // .erase(position, number of characters to remove)
               i--; // reset position, so i dont skip potential punctuation neighbors
           }
           }
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

