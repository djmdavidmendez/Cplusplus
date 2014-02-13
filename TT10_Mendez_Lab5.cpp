// Author:                   <David Mendez>
// File Name:              TT10_L5_Mendez.cpp    (Example: TT10_L1_Mendez.cpp)
// Course/Section:     COSC 1337 Fall 2013 TT10
// Due Date:              <October 1, 2013 1301>
// Instructor:               Thayer
//
// Reads the population of people from a file people.txt.
# include <iostream>
# include <iostream>
# include <iomanip>
# include <cstdlib>
# include <fstream>
using namespace std;

void display_file(){
	ifstream infile;
	int population = 0, year = 1900, star = 0;
	
	// open the file.
	infile.open("people.txt");
	if (infile){
		cout << "Open of the file people.txt was successful.\n";
		cout << "Retrieving data...\n\n";
		
		cout << "TOWN POPULATION GROWTH" << endl;
		cout << "(each * represents 1000 people)\n\n";
		while(!infile.eof()){
			infile >> population;
			if (infile.eof()) break;
			for (int row = 0; row < 1; row ++){
				cout << year << ": ";
				for (int star = 0; star < population / 1000; star ++){
					cout << "*";
				}
				cout << endl;
			}
			year += 20;
		}	
	}else{
		cout << "sorry, file not found\n";
	}
}
int main(){
	display_file();
	return 0;
}
/*Open of the file people.txt was successful.
Retrieving data...

TOWN POPULATION GROWTH
(each * represents 1000 people)

1900: **
1920: ****
1940: *****
1960: *********
1980: **************
2000: ******************
2020: *************************
2040: ******************************

--------------------------------
Process exited with return value 0
Press any key to continue . . .
*/

