#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream> //string stream
#include <cctype> // for ispunct 

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


void vowel(string [], int, char[]);
void consonant(string [], int, char[]);
void shortstr(string [], int);
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
    cout << endl;

    char reference[tsize]; // reference array that holds the first characters of the strings so the functions can work on the real arrays without stepping on each other
    for(int i = 0; i < tsize; i++){
      reference[i] = arr[i][0]; // this is how to stuff 1st character from 2d string array to regular 1d char array 
    }
	// TODO: call a function to encrypt strings that starts with a vowel
    vowel(arr, tsize, reference);    

	// TODO: call a function to encrypt strings that starts with a consonant
    consonant(arr, tsize, reference);

	// TODO: call a function to encrypt short strings
       
    shortstr(arr, tsize); // we do not need to add reference[] because this functions conditions do not depend on the first char  thus no stepping on toes and vowel and consonant funcs exclude toklen length above 3
	// TODO: display the encrypted strings (the results)
    for(int i = 0; i < tsize; i++){
     cout << arr[i] << "";
    }
  cout << endl;
    return 0; 
}


void vowel(string a[], int s, char r[]){ // array of strings (array within an array) and num of tokens
int tmp = 0; //tmp variable
int toklen = 0; // for token length
for(int i = 0; i < s; i++){ // checking the entire token string array
 int count = 0; //counter for first 3 letters                           
 toklen = a[i].length();
  // a[i][j] means character now cuz we in a string(array) in a array
  if((r[i] == 'a' || r[i] == 'A' || r[i] == 'e' || r[i] == 'E' || r[i] == 'i' || r[i] == 'I' || r[i] == 'o' || r[i] == 'O' || r[i] == 'u' || r[i] == 'U') && toklen > 3)
  {  while(count < 3){
    // if first character is a vowel swap to move to beginning of token for last 3 letters
     for(int j = toklen - 1; j > 0; j--){  
      tmp = a[i][j];
      a[i][j] = a[i][j - 1];       //pseudo bubble swap, starting from the end 
      a[i][j - 1] = tmp;
     }
     count++;
   }
   a[i].insert(0, 1, '#'); // add 1 '#' to the beginning 
  }

 
}
}

void consonant(string a[], int s, char r[]){ // array of strings (array within an array) and num of tokens
int tmp = 0; //tmp variable
int toklen = 0; // for token length
for(int i = 0; i < s; i++){ // checking the entire token string array
 int count = 0; //counter for first 3 letters                           
 toklen = a[i].length();
  // a[i][j] means character now cuz we in a string(array) in a array
  if(r[i] != 'a' && r[i] != 'A' && r[i] != 'e' && r[i] != 'E' && r[i] != 'i' && r[i] != 'I' && r[i] != 'o' && r[i] != 'O' && r[i] != 'u' && r[i] != 'U' && toklen > 3) //today i learned you can access the 2d array immediately without the for loop
  {  while(count < 3){
    // if first character is not a vowel swap to move to end of token for first 3 letters
     for(int j = 0; j < toklen - 1; j++){  
      tmp = a[i][j];
      a[i][j] = a[i][j + 1];       //pseudo bubble swap 
      a[i][j + 1] = tmp;
     }
     count++;
   }
   a[i].push_back('$'); // add $ to the end of the token after 3 letter swap 
  }

 
}
}

void shortstr(string a[], int s){
int toklen = 0; // for token length
int tmp = 0;
for(int i = 0; i < s; i++){
 toklen = a[i].length();
 if(toklen <= 3){
      tmp = a[i][toklen - 1];
      a[i][toklen - 1] = a[i][0];       //reverse 
      a[i][0] = tmp;
      a[i].insert(0, 1, '%');
      a[i].push_back('%');
 }
}
}
