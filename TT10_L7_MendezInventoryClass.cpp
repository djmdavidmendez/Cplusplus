// Author:                   <David Mendez>
// File Name:              TT10_L7_Mendez.cpp    (Example: TT10_L1_Mendez.cpp)
// Course/Section:     COSC 1337 Fall 2013 TT10
// Due Date:              <October 29, 2013 2254>
// Instructor:               Thayer
//
// An Inventory class that can hold information for an item in 
// a retail store's inventory.
# include <iostream>
# include <string>
# include <iomanip>
using namespace std;
// Class Inventory
class Inventory{
  private:
    int itemNumber;
   	int qty;
   	double cost;
   	string description;
  public:
    // Default constructor sets all of my member variables to zero!
    // Constructor 1 Prototype.
   	Inventory();
    // Constructor 2 Accepts an item's number, quantity, cost and description
    // as arguments.
    // Constructor 2 Prototype.
   	Inventory(int i, int q, double c, string d);
   	// Setter Methods!
   	void setItemNumber(int val1){
	  itemNumber = val1; 
	  }
   	void setQuantity(int val1){ 
      qty = val1; 
    }
   	void setCost(double val1){
      cost = val1; 
    }
   	void setDescription(string val1){
      description = val1; 
    }
   	// Getter Methods!
  	string getDescription() const{
      return description;
    }
   	int getItemNumber() const{
      return itemNumber;
    }
   	int getQuantity() const{
      return qty;
    }
   	double getCost() const{
      return cost;
    }
   	double getTotalCost() const{
      return (cost * qty);
    } 	
};
// Constructor 1!
Inventory::Inventory(){
  //cout << "INSIDE CONSTRUCTOR #1 INVENTORY()" << endl;
  itemNumber = qty= 0;
  cost = 0.0;
  description = " ";
}
// Constructor 2!
Inventory::Inventory(int i, int q, double c, string d){
  //cout << "INSIDE CONSTRUCTOR #2 Inventory::Inventory(int i, int q, double c, string d)" << endl;
  setItemNumber(i);
  setQuantity(q);
  setCost(c);
  setDescription(d);
}
// Input validation function.
void getInput(int &returnval, string prompt, int min = 0, int max = 2147483647){
   do{
      cout << prompt;
      cin >> returnval;
   }while (returnval < min || returnval > max);
}
// Input validation function for a double.
void getInput(double &returnval, string prompt, double min = 0, double max = 2147483647){
   do{
     cout << prompt;
     cin >> returnval;
   }while (returnval < min || returnval > max);
}
// This functions references an Inventory object
// and fills the member variables with acceptable data.
void setValues(Inventory &tempItem, const int item_num){
  int partNum;                 // Temporary Variables.
  string description;
  int qty;
  double price;
  cout << "\nEnter the data for the new part number" << item_num << endl;
  cout << "Part number: ";
  cin >> partNum;
  cout << "Description: ";
  // cin.get();
  cin.ignore(100, '\n');
  getline(cin, description);
  //stringstream <string>  is (description);
  // is >> description;
  // Validate that the numbers are greater than zero!
  getInput(qty, "Quantity on hand: ");
  getInput(price, "Unit price: ");
  // Calling the setter methods.
  tempItem.setQuantity(qty);
  tempItem.setCost(price);
  tempItem.setItemNumber(partNum);
  tempItem.setDescription(description);
}
// This function returns the member variables!
void showValues(Inventory  &item){
  // Calling the getter methods.
  cout << fixed << showpoint << setprecision(2) << endl;
  cout << "Part Number         : " <<item.getItemNumber() << endl;
  cout << "Description         : " <<item.getDescription() << endl;
  cout << "Quantity            : " <<item.getQuantity() << endl;
  cout << "Cost                : " <<item.getCost() << endl;
  cout << "Total Cost          : " <<item.getTotalCost() << endl;
}
int main(){
  cout << "Choose between 1 and 5 inventory items\n" << endl;
  int invCount = 0;
  double sum = 0;
  double sum2 = 0;
  // This the maximum capacity of the array!
  const int CAPACITY = 5;
  Inventory store[CAPACITY];
  getInput(invCount, "Enter number between 1 and 5\n",1, 5);

  for (int counter = 0; counter < invCount; counter++){
    setValues(store[counter], counter +1);
  }
  for (int counter = 0; counter < invCount; counter++){
    showValues(store[counter]);
    sum += store[counter].getTotalCost();
  }
  cout << "This is the total cost of the entire inventory: $" << sum <<endl;
  //cout << "\nTesting constructor #2 Inventory(int i, int q, double c, string d)"<< endl; 
  Inventory ob1(1,1,1.0,"board"),ob2(0,0,0.0," "),ob3(0,0,0.0," "),ob4(0,0,0.0," ");
  setValues(ob1, 1); showValues(ob1);
  setValues(ob2, 2); showValues(ob2);
  setValues(ob3, 3); showValues(ob3);
  setValues(ob4, 4); showValues(ob4);
  sum += ob1.getTotalCost() + ob2.getTotalCost() + ob3.getTotalCost() + ob4.getTotalCost(); cout << "This is the sum of all of the Inventory Items: $" << sum;
  system("pause");
  return 0;	
}
/*Choose between 1 and 5 inventory items

Enter number between 1 and 5
3

Enter the data for the new part number1
Part number: 11111
Description: Cars
Quantity on hand: 2
Unit price: 1.99

Enter the data for the new part number2
Part number: 22222
Description: Dolls
Quantity on hand: 2
Unit price: 1.99

Enter the data for the new part number3
Part number: 3333
Description: Cookies
Quantity on hand: 2
Unit price: 1.99

Part Number         : 11111
Description         : Cars
Quantity            : 2
Cost                : 1.99
Total Cost          : 3.98

Part Number         : 22222
Description         : Dolls
Quantity            : 2
Cost                : 1.99
Total Cost          : 3.98

Part Number         : 3333
Description         : Cookies
Quantity            : 2
Cost                : 1.99
Total Cost          : 3.98
This is the total cost of the entire inventory: $11.94

Enter the data for the new part number1
Part number: 11111
Description: Board
Quantity on hand: 1
Unit price: 20

Part Number         : 11111
Description         : Board
Quantity            : 1
Cost                : 20.00
Total Cost          : 20.00

Enter the data for the new part number2
Part number: 2222
Description: Wheels
Quantity on hand: 2
Unit price: 5.99

Part Number         : 2222
Description         : Wheels
Quantity            : 2
Cost                : 5.99
Total Cost          : 11.98

Enter the data for the new part number3
Part number: 33333
Description: Screws
Quantity on hand: 25
Unit price: .49

Part Number         : 33333
Description         : Screws
Quantity            : 25
Cost                : 0.49
Total Cost          : 12.25

Enter the data for the new part number4
Part number: 44444
Description: Sprockets
Quantity on hand: 2
Unit price: 12.99

Part Number         : 44444
Description         : Sprockets
Quantity            : 2
Cost                : 12.99
Total Cost          : 25.98
This is the sum of all of the Inventory Items: $82.15Press any key to continue .
. .*/
