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


void consonant(string [], int);
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
    consonant(arr, tsize);

	// TODO: call a function to encrypt short strings
    
	// TODO: display the encrypted strings (the results)
    for(int i = 0; i < tsize; i++){
     cout << arr[i] << endl;
    }

    return 0; 
}


void consonant(string a[], int s){ // array of strings (array within an array) and num of tokens
int tmp = 0; //tmp variable
int toklen = 0; // for token length
for(int i = 0; i < s; i++){ // checking the entire token string array
 int count = 0; //counter for first 3 letters                           //
 toklen = a[i].length();
  // a[i][j] means character now cuz we in a string(array) in a array
  if(a[i][0] != 'a' && a[i][0] != 'A' && a[i][0] != 'e' && a[i][0] != 'E' && a[i][0] != 'o' && a[i][0] != 'O' && a[i][0] != 'u' && a[i][0] != 'U') //today i learned you can access the 2d array immediately without the for loop
  {  while(count < 3){
    // if not vowel swap to move to end of token for first 3 letters
     for(int j = 0; j < toklen - 1; j++){  
      tmp = a[i][j];
      a[i][j] = a[i][j + 1];       //pseudo bubble swap 
      a[i][j + 1] = tmp;
     }
     count++;
   }
  }

 
}
}

