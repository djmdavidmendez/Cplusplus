// Author:                   <David Mendez>
// File Name:              TT10_L8_Mendez.cpp    (Example: TT10_L1_Mendez.cpp)
// Course/Section:     COSC 1337 Fall 2013 TT10
// Due Date:              <November 22, 2013 2254>
// Instructor:               Thayer
//
// Tic Tac Toe Computer player
# include <iostream>
# include <iomanip>
# include <vector>
# include <string>
# include <windows.h>
# include <ctime>
using namespace std;
const int LENGTH = 3;
class Board {
private:
  char tttBoard[LENGTH][LENGTH];
public:
  // Default constructor fills the board with numbers.
  Board();
  ~Board(){
  }
  // This member function displays the board
  void show_board();
  // This member function finds the number that was entered(num) and replaces it 
  // with an 'X'(letter) for player1 or 'O'(letter) for player 2.
  bool validate_move(char num, char letter);
  // Member function used to determine winner.
  bool show_tie();
  bool show_winner();
  void reset_board();
  //**********************************************************
  // The member function block_player return an integer.
  // This fucntion is designed to count the number of human x's 
  // on the board. If the x count for a horizontal, vertical or diagonal
  // nears completion(2 characters in a row). The computer must know
  // return the integer to negate player x from winning.
  //   
  // 									   
  //**********************************************************
  char block_player();
  
};

void Board::reset_board(){
  char counter = '9';	// counter is set as a character '9';
  for (int row = 0; row < LENGTH; ++row) {
    for (int col = 2; col > -1; --col) {
      tttBoard[row][col] = counter;
      counter--;
    }
  }
}
bool Board::show_tie(){
  int totalCount = 0;
  for (int row = 0; row < LENGTH; row++){
    for (int col = 0; col < LENGTH; col++){
      totalCount += (tttBoard[col][row] == 'X');
      totalCount += (tttBoard[col][row] == 'O');
      //cout << "This is the total count!" << totalCount << endl;
      if ((LENGTH * LENGTH) == totalCount){
      	return true;
      }
    }
  }
  //cout << "This is the total count!" << totalCount << endl;  
  return false;
}
// Default constructor fills the board with numbers
// starting with the highest value at the top of the 
// board.
Board::Board(){
  char counter = '9';	// counter is set as a character '9';
  for (int row = 0; row < LENGTH; ++row) {
    for (int col = 2; col > -1; --col) {
      tttBoard[row][col] = counter;
      counter--;
    }
  }
}
// This member function displays the board
void Board::show_board(){
	int color = 15;
    HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
    for (int row = 0; row < LENGTH; row++){
        for(int col = 0; col < LENGTH; col++){
          COORD pos = {((col*2)+1) , ((row *2)+1)};
          if (tttBoard[row][col] == 'X'){
          	color = 14;
          	SetConsoleTextAttribute(screen, color);     
          }
          if (tttBoard[row][col] == 'O'){
          	color = 12;
          	SetConsoleTextAttribute(screen, color);     
          }
		  SetConsoleTextAttribute(screen, color);     
          SetConsoleCursorPosition(screen, pos);
          cout << tttBoard[row][col];
          if (tttBoard[row][col] == 'X'){
          	color = 15;
          	SetConsoleTextAttribute(screen, color);     
          }
          if (tttBoard[row][col] == 'O'){
          	color = 15;
          	SetConsoleTextAttribute(screen, color);     
          } 
        }
    }
    cout << " " <<endl;
    cout << " " <<endl;
}
// This member function finds the number that was entered(num) and replaces it 
// with an 'X'(letter) for player1 or 'O'(letter) for player 2.
bool Board::validate_move(char num, char letter){
  for (int row = 0; row < LENGTH; ++row) {
    for (int col = 0; col < LENGTH; ++col) {
      if (tttBoard[row][col] == num){   // If the number was found
        tttBoard[row][col] = letter;    // replace it with the appropriate letter and
        return true;                    // return to main as a good move. 
      }
    }
  }
  return false; // Returns false when the number was not found.
}
// This member function blocks the player from winning.
char Board::block_player(){
  int xCount = 0;	// xCount is a conter for every 'X' in a row.
  for (int row = 0; row < LENGTH; row++){
  	xCount = 0;	// After every row scan the counter must be reset to zero.
	for(int col = 0; col < LENGTH; col++){
  	  xCount += (tttBoard[row][col] == 'X');	// For every instance that the loop encounters an x; add it 1 to the xCount.
  	  if (xCount >= 2){		// If the number of X's reaches 2....
  	    for (col = 0; col < LENGTH; col++){		// Scan the entire row again and find the open space to block player X.
  	      //cout << "tttBoard[row][col]=" << tttBoard[row][col] << endl;
  	  	  if (tttBoard[row][col] != 'X' && tttBoard[row][col] != 'O'){	// FOR SOME REASON I GET SOME BAD DATA.
  	  	  //cout << "tttBoard[row][col] =" << tttBoard[row][col] << endl;  // The count statement allows me to see what is actually being returned.
  	  	  return tttBoard[row][col];	// Returns the last number character to the computer player.
  	  	  }
  	    }
  	  }
  	}
  }
  return '0'; 	// This returns a character '0' after scanning all of the rows in the two-dimensional array.
  for (int row = 0; row < LENGTH; row++){
  	xCount = 0;
  	for (int col = 0; col < LENGTH; col++){
  	  xCount += (tttBoard[col][row] == 'X');
  	  
  	}
  }
}

// This member function counts the number of letters 
// to determine a winner.
bool Board::show_winner(){
  int xCount = 0, oCount = 0;
  // For loop to scan the rows for 3 matching letters.
  for (int row = 0; row < LENGTH; row++){
    xCount = oCount = 0;// Must reset after each column scan.
    for (int col = 0; col < LENGTH; col++){
      xCount += (tttBoard[row][col] == 'X');  // Count the number of times
      oCount += (tttBoard[row][col] == 'O');  // the letter is found.
    }
    // LENGTH is compared to the counter.
    // This way if you accidentally assign(LENGTH = xCount)
    // you will get a compiler error because LENGTH is const.
    if (LENGTH == xCount)return true; // Returns true when a player has won.
    if (LENGTH == oCount)return true;
  }
  // For loop to scan the columns for 3 matching letters.
  for (int row = 0; row < LENGTH; row++){
    xCount = oCount = 0;
    for (int col = 0; col < LENGTH; col++){
      xCount += (tttBoard[col][row] == 'X');
      oCount += (tttBoard[col][row] == 'O');
    }
    if (LENGTH == xCount)return true;
    if (LENGTH == oCount)return true;
  }
  xCount = oCount = 0;
  for (int cell = 0; cell < LENGTH; cell++){
    xCount += (tttBoard[cell][cell] == 'X');
    oCount += (tttBoard[cell][cell] == 'O');
  }
  if (LENGTH == xCount)return true;
  if (LENGTH == oCount)return true;
  xCount = oCount = 0;
  for (int row = LENGTH - 1, col = 0; row >= 0; row--, col++){
    xCount += (tttBoard[row][col] == 'X');
    oCount += (tttBoard[row][col] == 'O');
  }
  if (LENGTH == xCount)return true;
  if (LENGTH == oCount)return true;
  return false;
}
void clear_prompt();
bool player1(Board &game, string str, string plyr){
  bool playerTurn = true;
  while(playerTurn){
    cout << plyr << str;
    cout << endl;
    char choice = ' ';
    cin >> choice;
    bool valid = false;
    if (plyr == "Player X"){
      valid = game.validate_move(choice, 'X');
      if (valid){
      	playerTurn = false;
      	return true;
      }
    }
  clear_prompt();  
  }
  return false;
}
// Player 2 is the dumb computer.
bool player2(Board &game, string str, string plyr){
  srand (time(0));
  bool playerTurn = true;
  while(playerTurn){
    cout << plyr << str;
    cout << endl;
    int choice1 = 1 + rand() % 9;
    char choice2 = choice1 + 48;
    cout << "This is choice2 =" << choice2 << endl;
    bool valid = false;
    char xCount = '0';
    xCount = game.block_player();
    cout << "Why is xCount = " << xCount << endl;
    if (xCount != '0'){
      valid = game.validate_move(xCount, 'O');
      return true;
    }
    if (plyr == "Player O"){
        valid = game.validate_move(choice2, 'O');
	  if (valid){
      	playerTurn = false;
      	return true;
      }
    }
  //clear_prompt();
  }
  return false;
}
int main(){
  cout << "\n  | |\n -----\n  | |\n ----- \n  | |";
  Board game1;
  int num = 0;
  const string prompt = " pick a number between 1 and 9: ";
  const string p1 = "Player X";
  const string p2 = "Player O";
  char choice = 'y';
  do{
    bool win = false;
    bool tie = false;
    Board game1;
    game1.show_board();
    while (!win && !tie){
      player1(game1, prompt, p1);
      game1.show_board();
      win = game1.show_winner();
      tie = game1.show_tie();
      //clear_prompt();
      if (win){ cout << "player X wins! ";break; }
      if(tie){ cout << "Congratulations! Both players are losers.";break;}
      player2(game1, prompt, p2);
      game1.show_board();
      win = game1.show_winner();
      tie = game1.show_tie();
      //clear_prompt();
      if (win){ cout << "player O wins! ";break; }
      if(tie){ cout << "Congratulations! Both players are losers." << endl; cout << endl;break;}
    }
    cout << "Play again? (y/n)" ;
    cin >> choice;
    tolower(choice);
    if (choice == 'y')game1.reset_board();
    clear_prompt();
  } while (choice == 'y');
  cout << "Good Bye!" << endl;
  system("pause");
  return 0;
}
void clear_prompt(){
	HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = {0, 7};
	SetConsoleCursorPosition(screen, pos);
	for(int i =0; i < 320; i++){
		cout << ' ';
	}
	SetConsoleCursorPosition(screen, pos);
}
