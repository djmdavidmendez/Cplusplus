// Author:                      David Mendez
// Assignment Number:           Lab 11
// File Name:                   TT10_L11_Mendez.cpp
// Course/Section:              COSC 1337 Section TT10
// Due Date:                    See syllabus or blackboard
// Instructor:                  Thayer
// This Program converts an integer and displays it in month-day format and vice versa.
# include <iostream>
# include <string>
using namespace std;

class Day{
  private: 
  	int dayNum;  
  	static const int NUMOFMONTHS = 12;    
    static const int daysInMonth[NUMOFMONTHS];
    static const string monthOfYear[NUMOFMONTHS];
  public:
  	// Constructor 1
  	Day(int num){
  	  if (num > 365 || num <= 0){
  	  	//cout << "Number of days out of range!\n";
  	  }
  	  else{
  	  	dayNum = num;
  	  }	  
  	}
  	// Constructor 2
  	Day(string m, int d); 
    string getMonth();
  	int getDay(); 
	void conversion(string m, int d);
	int getDayNum(){
	  return dayNum;  
	}
	// Overloading operator ++.
	Day operator++(){
	  dayNum++;
	  if (dayNum >= 365){
	  	dayNum = 1;
	  }
	  return *this;	
	} 	
	// Overloading operator --.
	Day operator--(){
	  dayNum--;
	  return *this;
	}
	// Overloading operator <<.
	friend ostream &operator<<(ostream& out , Day a);
};
ostream &operator<<(ostream& out, Day a){
  out << a.getMonth() << " " <<a.getDay() << endl;
  return out;
}
//Constructor 2
void Day::conversion(string m, int d){
  int counter = 0;
  for(int i = 0; i < NUMOFMONTHS; i++){
  	counter += daysInMonth[i - 1];
  	if (m == monthOfYear[i]){
  	  dayNum = counter + d;	
  	}
  }	
}

Day::Day(string m, int d){
  conversion(m, d);
}
// This member function gets the day number.
int Day::getDay(){
  int counter = 0;
  int dayCounter = 0;
  int num = 0;
  for (int i = 0; i < NUMOFMONTHS; i++){
  	counter += daysInMonth[i];
	dayCounter += daysInMonth[i-1];
  	if (dayNum <= counter){
  	  num = dayNum - dayCounter;
	  return num;
  	}
  }
  return 0;	
}
// This member function Gets the month.
string Day::getMonth(){
  int counter = 0;
  for (int i = 0; i < (NUMOFMONTHS); i++){
    counter += daysInMonth[i];
	if (dayNum <= counter){
	  return monthOfYear[i];  
    }
  }
  return " "; 
}
const int Day::daysInMonth[NUMOFMONTHS] =       {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const string Day::monthOfYear[NUMOFMONTHS] = {"january","february","march","april","may","june","july",
											  "august","september","october","november","december"};
int main(){
  bool running = true;
  while(running){
  	cout << "Testing constructor1" << endl;
  	string prompt = "Enter a number of days: (-1 to quit)";
    cout << prompt;
	int num = 0;
    cin >> num;
    if (num == -1)break;
  	Day obj1(num);
  	if (!(num > 365 || num <= 0)){
  	  cout << obj1 << endl;
    }
  }
  bool running1 = true;
  while(running1){
  	cout << "Testing constructor number2." << endl;
  	cout << "Enter the month in lowercase:(-1 to exit) ";
  	string month = " ";
  	cin >> month;
  	if (month == "-1")break;
  	cout << "Enter the day:(-1 to exit) ";
  	int day = 0;
  	if (month == "-1" || day == -1)break;
  	cin >> day;
  	Day testDay(month, day);
  	cout << testDay;
  }
  Day cincoDeMayo("may", 5);
  cout << cincoDeMayo;
  cout << "Day number = 300" << endl;
  int dayNumber = 300;
  for (int dayCounter = (dayNumber -5); dayCounter <= (dayNumber + 5); dayCounter++){
  	Day testDay(dayCounter);
  	cout << testDay;
  }
  cout << "testing number 2" << endl;
  while (dayNumber < 400){
  	Day testDay(dayNumber);
	cout << ++ testDay;
	dayNumber++;
  }
  return 0;
}
/*
Testing constructor1
Enter a number of days: (-1 to quit)-1
Enter the month in lowercase:(-1 to exit) january
Enter the day:(-1 to exit) 31
january 31
Enter the month in lowercase:(-1 to exit) -1
may 5
Day number = 300
october 22
october 23
october 24
october 25
october 26
october 27
october 28
october 29
october 30
october 31
november 1
testing number 2
october 28
october 29
october 30
october 31
november 1
november 2
november 3
november 4
november 5
november 6
november 7
november 8
november 9
november 10
november 11
november 12
november 13
november 14
november 15
november 16
november 17
november 18
november 19
november 20
november 21
november 22
november 23
november 24
november 25
november 26
november 27
november 28
november 29
november 30
december 1
december 2
december 3
december 4
december 5
december 6
december 7
december 8
december 9
december 10
december 11
december 12
december 13
december 14
december 15
december 16
december 17
december 18
december 19
december 20
december 21
december 22
december 23
december 24
december 25
december 26
december 27
december 28
december 29
december 30
january 1
january 1
january 2
january 3
january 4
january 5
january 6
january 7
january 8
january 9
january 10
january 11
january 12
january 13
january 14
january 15
january 16
january 17
january 18
january 19
january 20
january 21
january 22
january 23
january 24
january 25
january 26
january 27
january 28
january 29
january 30
january 31
february 1
february 2
february 3
february 4

--------------------------------
Process exited with return value 0
Press any key to continue . . .
*/
