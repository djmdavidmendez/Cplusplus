// Author:                   <David Mendez>
// File Name:              TT10_L2_Mendez.cpp    (Example: TT10_L1_Mendez.cpp)
// Course/Section:     COSC 1337 Fall 2013 TT10
// Due Date:              <September 28, 2013 1421>
// Instructor:               Thayer
//
// star making program.

#include <iostream>
using namespace std;
int main(){
	int lines = 0;
	do{
	    int rows = 0, stars = 0;
	    cout << "Enter the number of lines: ";
	    cin >> lines;
	    for (rows = 1; rows <= (lines / 2) ; rows++){
	        for (int spaces = (lines / 2); spaces >= rows; spaces--){
	        	cout << " ";
	       	}
	        for (stars = 1; stars < rows; stars++){
	            cout << "*";
	        }
	       for (stars = 0; stars < rows; stars++){
	            cout << "*";
	        } 
	         cout << "\n";
		}	
	     // This is where the descending rows start.
	//    cout << "--------------------------------------------" << endl;
	    // FOR even numbers rows should equal 0.
	    for (rows = (!(lines % 2)); rows <= lines ; rows++){
	       	for (int spaces = 0; spaces < rows; spaces++){
	            cout << " ";
	            
	        } 
			for (stars = (lines / 2) ; stars >= rows ; stars--){
	            cout << "*";
	        }
	        for (stars = (lines / 2)-1; stars >= rows; stars--){
	            cout << "*";
	        }
	        cout << "\n";
	    }
	}while (lines != 0);
	cout << "Good Bye!";
	return 0;  
}
/*
Enter the number of lines: 7
   *
  ***
 *****
*******
 *****
  ***
   *




Enter the number of lines: 5
  *
 ***
*****
 ***
  *



Enter the number of lines: 4
  *
 ***
 ***
  *


Enter the number of lines: 0
Good Bye!
--------------------------------
Process exited with return value 0
Press any key to continue . . .
*/
