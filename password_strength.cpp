// Author:                      David Mendez
// Assignment Number:           Lab 12
// File Name:                   TT10_L12_Mendez.cpp
// Course/Section:              COSC 1337 Section TT10
// Due Date:                    See syllabus or blackboard
// Instructor:                  Thayer
// This Program shows the difference between the C-Strings and the C++String class.
# include <iostream>
# include <string>
using namespace std;
class Password{
  private:
  	static const int SIZE = 80;
  	unsigned short password[SIZE];	// used to encrypt password.
  	//string password1;
  public:
  	// constructor one takes an array of characters as an argument.
    Password(char *charArray){
      for (int i = 0; charArray[i] != '\0' ; i++){
      	password[i] = charArray[i] <<1; // bit shift
	  }
    }
    // constructor2 takes a string as an argument.
    Password(string charArray){
      for (int i = 0; charArray[i] != '\0' ; i++){
      	password[i] = charArray[i] <<1;	// bit shift
	  }      
    }
    // prints password.
    void printPassword(){
      for (int i = 0; password[i] != '\0'; i++){
	    cout << password[i];
	  }
    }
};
// Used to measure the string lenght.
int stringLength(char *cArray){
  int length = 0;
  for (int i = 0; cArray[i] != '\0'; i++){
  	length++;
  }
  return length;
}
// Overloaded function takes a array of characters.
bool validatePass(char *cArray){
  bool upper = false;
  bool lower = false;
  bool digit = false;
  bool special = false;
  for(int i =0; cArray[i] != '\0'; i++){	// Loop through each character of the string and compare requirements.
	if (ispunct(cArray[i])){	// If you find a special character.
      special = true;
	}
  	if(isupper(cArray[i])){		// if you find an upper case leeter.
  	  upper = true;
	}
  	if(islower(cArray[i])){		// If you find a lower case letter.
  	  lower = true;
  	}
  	if(isdigit(cArray[i])){		// if you find a number.
      digit = true;  	
	}  	
  }
  if(!upper){	// if no upper case letter; tell the user.
  	cout << "Password requires a uppercase letter!" << endl;
  }
  if(!lower){	// if no lower case letter; tell the user.
  	cout << "Password requires a lowercase letter!" << endl;
  }
  if(!digit){	// if no number; tell the user.
  	cout << "Password requires a number!" << endl;  	
  }
  if(!special){ // if no special character; tell the user.
  	cout << "Password requires a special character!" << endl;
  }
  if(stringLength(cArray) < 8){ // if not long enough; tell the user.
    cout << "Password must be at least 8 characters long!" << endl;
  }
  if (upper && lower && digit && special && (stringLength(cArray) > 8)){	// if password fulfills the requirement; tell the user and return true.
  	cout << "password meets all requirements" << endl;
  	return true;
  }     	
  else{	// return false if the password is invalid.
  	return false;
  }
}
// Overloaded functions takes a string.
bool validatePass(string cArray){
  bool upper = false;
  bool lower = false;
  bool digit = false;
  bool special = false;
  for(int i =0; cArray[i] != '\0'; i++){	// Loop through each character of the string and compare requirements.
	if (ispunct(cArray[i])){
      special = true;
	}
  	if(isupper(cArray[i])){
  	  upper = true;
	}
  	if(islower(cArray[i])){
  	  lower = true;
  	}
  	if(isdigit(cArray[i])){
      digit = true;  	
	}  	
  }
  if(!upper){	// if no upper case letter; tell the user.
  	cout << "Password requires a uppercase letter!" << endl;
  }
  if(!lower){	// if no lower case letter; tell the user.
  	cout << "Password requires a lowercase letter!" << endl;
  }
  if(!digit){	// if no number; tell the user.
  	cout << "Password requires a number!" << endl;  	
  }
  if(!special){	// if no special character; tell the user.
  	cout << "Password requires a special character!" << endl;
  }
  if(cArray.size() < 8){	// if not long enough; tell the user.
    cout << "Password must be at least 8 characters long!" << endl;
  }
  if (upper && lower && digit && special && (cArray.size() > 8)){	// if password fulfills the requirement; tell the user and return true.
  	cout << "password meets all requirements" << endl;
  	return true;
  }     	
  else{	// return false if the password is invalid.
  	return false;
  }
}


int main(){
  const int LENGTH = 80;
  char line[LENGTH];	// array of characters.
  char choice = ' ';
  do{
	cout << "Testing password checker. What data type should the password be? c) c-string, s) string class, q) quit:";
	cin >> choice;
	switch (choice){
	  case 'c': {
	  	bool valPass = false;	// valpass equals false until the password is valid.
	    while (!valPass){		// Loop until the password is valid.
	    cout << "Enter your password:(0 to Menu)";
	    cin >> line;
	    if (line[0] == '0'){
	  	  break;
	    }
	    valPass = validatePass(line);	// function to determine if password is valid.
        }
        if (valPass){
         Password ob(line);	
        }
		//cout << "Password valid." << endl;	  	
	  	break;
	  }
	  case 's': {
        bool valPass2 = false; // valpass2 equals false until the password is valid.
        string password = " ";
        while (!valPass2){	// Loop until password is valid(true).
          cout << "Enter your string password:(0 to Menu)";
          cin >> password;
          if (password[0] == '0'){
          	break;
          }
          valPass2 = validatePass(password);	// function to determine if password is valid.
        }
        if(valPass2){
          Password ob2(password);
        }	  	
	  	break;
	  }
	  case 'q': {
	  	cout << "Thank You goodBye." << endl;
	  	break;
	  }
	  default:{
	  	cout << "Invalid Choice!" << endl;
	  }
	}
  }while (choice != 'q');
  return 0;
}
/*
Testing password checker. What data type should the password be? c) c-string, s)
 string class, q) quit:c
Enter your password:(0 to Menu)d
Password requires a uppercase letter!
Password requires a number!
Password requires a special character!
Password must be at least 8 characters long!
Enter your password:(0 to Menu)Dj1234&^%
password meets all requirements
Testing password checker. What data type should the password be? c) c-string, s)
 string class, q) quit:s
Enter your string password:(0 to Menu)d
Password requires a uppercase letter!
Password requires a number!
Password requires a special character!
Password must be at least 8 characters long!
Enter your string password:(0 to Menu)Dj1234&^%
password meets all requirements
Testing password checker. What data type should the password be? c) c-string, s)
 string class, q) quit:q
Thank You goodBye.

--------------------------------
Process exited with return value 0
Press any key to continue . . .
*/

