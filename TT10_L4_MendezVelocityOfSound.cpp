// Author:                   <David Mendez>
// File Name:              TT10_L4_Mendez.cpp    (Example: TT10_L1_Mendez.cpp)
// Course/Section:     COSC 1337 Fall 2013 TT10
// Due Date:              <September 20, 2013 1900>
// Instructor:               Thayer
//
// Velocity of sound in a the given material.
# include <iostream>
# include <iomanip>
# include <cstdlib>
# include <fstream>
using namespace std;
// This function displays the contents of the file to the console 
// window.
void display_file(){                                                            
	ifstream infile;
	int counter =1;
	string medium, speeds;
																					
	infile.open("velocity.txt");
	if(infile){
		cout << "Open of velocity.txt was succesful.\n";
		cout << "Retrieving data...\n\n";
		while (!infile.eof()){	// Loop until end of file.
			infile >> medium >> speeds;
			if (infile.eof()) break;
			cout << counter << ")"<< medium << ": " << speeds
				  << "" <<endl;
			counter ++;	// (This helps the user make a selection by putting 
						// a number infront of the string. 
		}				
		infile.close();
	}else{
		cout << "sorry, file not found\n";
	}
}



int read_file(int input){
//	cout << "INSID READ FILE " << endl;                                                          
	ifstream infile;
	int speed =0, speed1 = 0, counter =1;
	string medium, med1, speeds;
	
	infile.open("velocity.txt");
	if(infile){		
		while (!infile.eof()){
			infile >> medium >> speed;
			if (infile.eof()) break;
			counter ++;
			if (counter == input +1){
				speed1 = speed;
				med1 = medium;
			}
		}	
		infile.close();
	}else{
		cout << "sorry, file not found\n";
	}
	return speed1;
}

string get_medium(int input){
//	cout << "INSIDE GET MEDIUM" << endl;                                                          
	ifstream infile;
	int speed =0, speed1 = 0, counter =1;
	string medium, med1, speeds;
	infile.open("velocity.txt");
	if(infile){		
		while (!infile.eof()){
			infile >> medium >> speed;
			if (infile.eof()) break;
			counter ++;
			if (counter == input +1){
				speed1 = speed;
				med1 = medium;
			}
		}	
		infile.close();
	}else{
		cout << "sorry, file not found\n";
	}
	return med1;
}


int main(){
	cout << "THE SPEED OF SOUND in a Medium MENU" << endl << endl;
	float choice_velocity = 0;
	int input = 0;
	do{
		display_file();
		cout << "Please enter the number for your choice(0 to quit): ";
		cin >> input;
		choice_velocity = read_file(input);
		string medium;
		medium = get_medium(input); 
		cout << "\n";
		while (choice_velocity > 0){
			cout << "In "<< medium <<" sound travels " 
					 << choice_velocity << " feet per second" << endl;
			float time = 0;
			cout << "Please enter a distance in " 
				 << "feet from where the object produces sound(0 to MENU): ";
			float distance = 0.0;
			cin >> distance;
			if (distance == 0){
				break;
			}
			time = distance / choice_velocity;
			cout << "In " << distance << " feet, sound will arrive in " 
				 << time << " seconds.\n"<< endl;
		}

		
									
	}while (input != 0);
	cout << "Exiting";
	return 0;

}
