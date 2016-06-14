// Author:                   <David Mendez>
// File Name:              TT10_L3_Mendez.cpp    (Example: TT10_L1_Mendez.cpp)
// Course/Section:     COSC 1337 Fall 2013 TT10
// Due Date:              <September 26, 2013 1147>
// Instructor:               Thayer
//
// This program is desined to tutor a elementary shool student.
# include <iostream>
# include <iomanip>
# include <cstdlib>
// this imports the time functions
# include <ctime>
using namespace std;


int get_questions(int val1);
int validate_choice(int choice);
int grading_answers(int outcome);
void final_grade(int correct, int questions);
	
int main(){
	cout << "Math tutoring program!" << endl;
	char choice = ' ';
	do{
		int correct = 0;
		int questions = 0;
		srand (time(0));
		choice = validate_choice(choice);
		if ((choice == 'q') || (choice == 'Q')){
			break;
		}
		int validated_questions = 0;
		validated_questions = get_questions(questions);
		questions = validated_questions; 
		// THIS IS WHERE THE SWITCH STARTS
		switch (choice){
		// CASE a ADITION TUTOR
		case 'a':{
			int gloop_counter = 1;
			while ((gloop_counter <= questions)){
				// Generate random numbers
				int numerator = 0, denominator = 0, answer = 0;
				numerator = 1 + rand() % 50;
				denominator = 1 + rand() % 50;
				answer = numerator + denominator;
				cout << "Question #" << gloop_counter << endl;
				cout << " " << numerator << endl;
				cout << "+"<< denominator << endl;
				cout << "-------" << endl;
				char grader = ' ';
				grader = grading_answers(answer);
                if (grader == '1'){
				correct += 1;
                }
                else if (grader == 'y'){
				cout << "exiting case 1 addition problems" << endl;
				break;
                }
                gloop_counter +=1;
                }     				
			}
			final_grade(correct, questions);
			break;
		// CASE 2 SUBTRACTION TUTOR
		case 's':{
			int gloop_counter = 1;
			while ((gloop_counter <= questions)){
				// GENERATE RANDOM NUMBERS FOR SUBTRACTION.
				int numerator = 0, denominator = 0, answer = 0;
				numerator = 1 + rand() % 99;
				denominator = 1 + rand() % 99;
				if (numerator <= denominator){
					answer = denominator - numerator;
					cout << "Question #" << gloop_counter << endl;
					cout << " " << denominator << endl;
					cout << "-"<< numerator << endl;
					cout << "-------" << endl;
				}
				else if (numerator >= denominator){
					answer = numerator - denominator;
					cout << "Question #" << gloop_counter << endl;
					cout << " " << numerator << endl;
					cout << "-"<< denominator << endl;
					cout << "-------" << endl;
				}
				char grader = ' ';
				grader = grading_answers(answer);
                if (grader == '1'){
				correct += 1;
                }
                else if (grader == 'y'){
				cout << "exiting case 1 addition problems" << endl;
				break;
                }
                gloop_counter +=1;
                }     
			}
			final_grade(correct, questions);
			break;
		// CASE 3 MULTIPLICATION TUTOR
		case 'm':{			
			int gloop_counter = 1;
			while ((gloop_counter <= questions)){
				
				// Generate random numbers
				int numerator = 0, denominator = 0, answer = 0;
				numerator = 1 + rand() % 99;
				denominator = 1 + rand() % 99;
				while ((numerator * denominator) > 100){
				numerator = 1 + rand() % 99;
				denominator = 1 + rand() % 99;
				answer = numerator * denominator;
				}
				cout << "Question #" << gloop_counter << endl;
				cout << "  " << numerator << endl;
				cout << "X "<< denominator << endl;
				cout << "-------" << endl;
				char grader = ' ';
				grader = grading_answers(answer);
            	if (grader == '1'){
				correct += 1;
            	}
            	else if (grader == 'y'){
				cout << "exiting case 1 addition problems" << endl;
				break;
            	}
            	gloop_counter +=1;
            	}     
			}
			final_grade(correct, questions);
			break;
		// CASE 4 DIVISION TUTOR
		case 'd':{
			int gloop_counter = 1;
			while ((gloop_counter <= questions)){
				// Generate random numbers
				int numerator = 1, denominator = 1, answer = 1;
				// THIS WILL GENERATE RANDOM DIVISIONS
				// UNTIL WE HAVE AN ACCEPTABLE PROBLEM
				while ((denominator / numerator) < 2){
                      denominator = rand() % 100;
                while (answer > 0){
				// Generate random numbers
				numerator = 1 + rand() % 99;
                while (numerator < 2){
                      numerator = 1 + rand() % 99;
                }
				answer = denominator % numerator;
				}
				answer = denominator / numerator;
                }
				cout << "Question #" << gloop_counter << endl;
				cout << "  " << denominator << endl;
				cout << "/ "<< numerator << endl;
				cout << "-------" << endl;
                answer = denominator / numerator;
				char grader = ' ';
				grader = grading_answers(answer);
                if (grader == '1'){
				correct += 1;
                }
                else if (grader == 'y'){
				cout << "exiting case 1 addition problems" << endl;
				break;
                }
                gloop_counter +=1;
                }
				final_grade(correct, questions);    
			    break;
		}
    	} // switch
		cout << "Thank you for using the Math Tutor." << endl;
		cout << "Do you want to exit Math Tutor? Y/N: ";
		char early_quit = ' ';
		cin >> early_quit;
		if ((early_quit == 'n') || (early_quit == 'N')){		
		 }
		 else if ((early_quit == 'y') || (early_quit == 'Y')){
			  choice = 'q';
		 }
	 
	} while ((choice != 'q') );
	cout << "Exiting math tutor..." << endl;
	return 0;
}
int get_questions(int val1){
	cout << "How many questions would you like: ";
	cin >> val1;
	if ((val1 >= 1) && (val1 <= 99999))
		return val1;
	else{
		while (val1 <= 0){
		cout << "Invalid number of questions." << endl;
		cout << "How many questions would you like: ";
		cin >> val1;
		if ((val1 >= 1) && (val1 <= 99999)){
			return val1;
		}
		}
		
	}


}
int validate_choice(int choice){
	cout << "a)ddition, s)ubtraction, m)ultiplication, d)ivision, q)uit: " << endl;
	cout << "Please enter your choice: ";
	char choice1 = ' ';
	cin >> choice1;
	choice = tolower(choice1);
	cout << "This is your choice " << choice1 << endl;
	if ((choice1 == 'a') || (choice1 == 's') || (choice1 == 'm') || (choice1 == 'd') || (choice1 == 'q')){
		return choice1;
	}
	else{
		while (!(choice1 == 'a') || (choice == 's') || (choice == 'm') || (choice == 'd') || (choice == 'q')){
					cout << "INVALID CHOICE" << endl;
					cout << "a)ddition, s)ubtraction, m)ultiplication, d)ivision, q)uit: " << endl;
					cin >> choice1;
					if ((choice1 == 'a') || (choice1 == 's') || (choice1 == 'm') || (choice1 == 'd') || (choice1 == 'q')){
					return choice1;
					}
					
		}

			
	}
		
		
}	
void final_grade(int correct, int questions){
	double percentage = 0.0, correct1 = 0.0, questions1 = 0.0;
	int wrong = 0;
	wrong = questions - correct;
	correct1 = correct;
	questions1 = questions;
	percentage = (correct1 / questions1) * 100;
	cout << "You got " << correct << " correct!" << endl;
	cout << "You got " << wrong << " wrong." << endl;
	cout << "Number of questions: " << questions << endl;
	cout << "Your grade is: " << percentage << "%"<< endl;
}
int grading_answers(int outcome){
	cout << "please enter your answer: ";
	int guess1 = 0;
	cin >> guess1;
	char correct = '1';
	if (guess1 < 0){
		cout << "Do you wish to quit? (y/n): ";
		char early_quit = ' ';
		cin >> early_quit;
		early_quit = tolower(early_quit);
		if (early_quit == 'y'){
			cout << "exiting the program" << endl;
			return early_quit;
		}
		else{
			cout << "please enter your answer: ";
			cin >> guess1;
			if (guess1 == outcome){
				cout << "Good Job!" << endl;
				char correct = '1';
				return correct;
				
			}
			else{
				cout << "Sorrry wrong answer!" << endl;
				cout << "The answer is " << outcome << "\n"<< endl;
			}
		}
	}
	else if(guess1 == outcome){
		cout << "Good job" << endl;
		char correct = '1';
		return correct;
	}
	else{
		cout << "Sorry wrong answer." << endl;
	}		
}
