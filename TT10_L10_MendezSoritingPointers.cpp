// Author:                      David Mendez
// Assignment Number:           Lab 10
// File Name:                   TT10_L0_Mendez.cpp
// Course/Section:              COSC 1337 Section TT10
// Due Date:                    See syllabus or blackboard
// Instructor:                  Thayer
// This program calculates the time it takes an algorithm to sort an array of pointers.
// Algorithms used on array of integers: Quick Sort, Bubble Sort, Selection Sort, Linear Search, Binary Search.
// Algorithms used on array of pointers: Select Sort, BubbleSort, InsertionSort.
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

class ArrayAllocation {
private:
	int length;
	int *pArrayNum;
    int **pArrayUp;
    int **pArrayDown;
public:
	//Constructor1 copies an existing array to *pArrayNum.
	ArrayAllocation(int array[], int size);
	// Constructor2 fills *pArrayNum with random values.
	ArrayAllocation(int size);
     ~ArrayAllocation();
    void selectSortA();
	void selectSortD();
	void bubbleSortA();
	void bubbleSortD();
	void quickSortA();
	void quickSortD();
	void insertionSortD(); 
	void insertionSortA();
	void show();
	void showSortedA();
	void showSortedD();
	int** getpArrayUp() const{
	  return pArrayUp;
	}
};

//***********************************************************
// Constructor.                                             * 
// The argument passed to size indicates the number of      *
// elements in array passed to array. The variable array    *
// holds the list of data values. The constructor           *
// allocates the pArrayNum, pArrayUp and pArrayDown arrays. *
// The "array" array is coped to the pArrayNum array.       *
// The elements of the pArrayUp and pArrayDown arrays       *
// are made to point to the elements of the pArrayNum array.*
// and then sorted in ascending order by  					*
// the selectSort function.                                 *
//***********************************************************
ArrayAllocation::ArrayAllocation(int array[], int size)
{
   length = size;	// length is a member variable.
   if (size > 0)
   {
       // Allocate an array of integers.
       pArrayNum = new int[size];
       // Allocate an array of pointers to integers.
       pArrayUp = new int*[size];
       // Allocate an array of pointers to integers.
       pArrayDown = new int*[size];
       // Initialize the arrays.
       for (int count = 0; count < length; count++)
	   {
           pArrayNum[count] = array[count];		// Fills the donations array with data.
           pArrayUp[count] = &pArrayNum[count];	    // Fills the array of pointers with the memory 
		   pArrayDown[count] = &pArrayNum[count];	        // adresses of the values of pArrayNum array.
       }
   }
}
//**********************************************************
// Constructor Number 2									   *
//**********************************************************
ArrayAllocation::ArrayAllocation(int size)
{
   length = size;	
   if (size > 0)
   {
       // Allocate an array of integers.
       pArrayNum = new int[size];
       if (!pArrayNum){
         throw "Error: out of memory.";
       }
       // Allocate an array of pointers to integers.
       pArrayUp = new int*[size];
       if (!pArrayUp){
         throw "Error: out of memory.";
       }
       // Allocate an array of pointers to integers.
       pArrayDown = new int*[size];
       if (!pArrayDown){
         throw "Error: out of memory.";
       }   
       // Initialize the arrays.
       for (int count = 0; count < length; count++)
	   {
           pArrayNum[count] = 1 + (rand()*rand()) % length;		// Fills the pArrayNum array with random data.
           pArrayUp[count] = &pArrayNum[count];	    // FFills the array of pointers with the memory 
		   pArrayDown[count] = &pArrayNum[count];	        // adresses of the values of pArrayNum array.
       }
       // Now, sort the array of pointers.

   }
}
//**********************************************************
// Destructor frees the memory allocated by the constructor*
//**********************************************************
ArrayAllocation::~ArrayAllocation()
{
   if (length > 0)
   {
     delete [ ] pArrayNum;
	  pArrayNum = 0;
     delete [ ] pArrayUp;
	  pArrayUp = 0;
	 delete [ ] pArrayDown;
	  pArrayDown = 0;
   }  
}

//*******************************************************
// The show function uses cout to display the pArrayNum *
// array in sequential order.                           *
//*******************************************************
void ArrayAllocation::show()
{
	int size = length > 20?20:length;
	for (int count = 0; count < size; count++)
		cout << pArrayNum[count] << " ";
	cout << endl;
}

// ASCENDING SELECT SORT
//************************************************************
// The selecSort function performs a ascending selection sort*
// on the pArrayUp array of pointers.    					 *
//************************************************************
void ArrayAllocation::selectSortA()
{
    int scan, minIndex;
    int *minElem;

    for (scan = 0; scan < (length - 1); scan++)
    {
         minIndex = scan;
         minElem = pArrayUp[scan];
         for(int index = scan + 1; index < length; index++)
         {
            if (*(pArrayUp[index]) < *minElem)
             {
                minElem = pArrayUp[index];
                minIndex = index;
             }
         }
      pArrayUp[minIndex] = pArrayUp[scan];
      pArrayUp[scan] = minElem;
    }
}

// DESCENDING SELECT SORT
//************************************************************
// The selecSort function performs a descending selection    *
// sort on the pArrayDown array of pointers.    			 *
//************************************************************
void ArrayAllocation::selectSortD()
{
    int scan, minIndex;
    int *minElem;

    for (scan = 0; scan < (length - 1); scan++)
    {
         minIndex = scan;
         minElem = pArrayDown[scan];
         for(int index = scan + 1; index < length; index++)
         {
            if (*(pArrayDown[index]) > *minElem)
             {
                minElem = pArrayDown[index];
                minIndex = index;
             }
         }
      pArrayDown[minIndex] = pArrayDown[scan];
      pArrayDown[scan] = minElem;
    }
}
// ASCENDING BUBBLE SORT
//************************************************************
// The bubbleSortA function performs a ascending selection  *
// sort on the pArrayDown array of pointers.    			 *
//************************************************************
void ArrayAllocation::bubbleSortA(){
  int *temp;
  bool swap;
  do{
  	swap = false;
  	for (int i = 0; i < (length -1); i++){
  	  if ( **(pArrayUp + i) > **(pArrayUp +(i + 1))){
        //cout << list[i] << endl;
        temp = pArrayUp[i];
        pArrayUp[i] = pArrayUp[i + 1];
        pArrayUp[i + 1] = temp;
        swap = true;
	  }	
  	}
  // When the sort is complete swap is false.
  }while(swap);
}
// DESCENDING BUBBLE SORT
//************************************************************
// The bubbleSortA function performs a descending selection  *
// sort on the pArrayDown array of pointers.    			 *
//************************************************************
void ArrayAllocation::bubbleSortD(){
  int *temp;
  bool swap;
  do{
  	swap = false;
  	for (int i = 0; i < (length -1); i++){
  	  if ( **(pArrayDown + i) < **(pArrayDown +(i + 1))){
        //cout << list[i] << endl;
        temp = pArrayDown[i];
        pArrayDown[i] = pArrayDown[i + 1];
        pArrayDown[i + 1] = temp;
        swap = true;
	  }	
  	}
  // When the sort is complete swap is false.
  }while(swap);
}
// ASCENDING INSERTION SORT
//************************************************************
// The insertionSortA function performs a ascending selection  *
// sort on the pArrayDown array of pointers.    			 *
//************************************************************
void ArrayAllocation::insertionSortA(){
  int j;
  int *tmp;
  for (int i = 1; i < length; i++){  
    j = i;  
    while (j > 0 && *pArrayUp[j - 1] > *pArrayUp[j]){
      tmp = pArrayUp[j];
      pArrayUp[j] = pArrayUp[j - 1];
      pArrayUp[j - 1] = tmp;
      j--;
    }//end of while loop

  }//end of for loop
}//end of insertion_sort.
// DESCENDING INSERTION SORT
//************************************************************
// The insertionSortD function performs a descending selection*
// sort on the pArrayDown array of pointers.    			 *
//************************************************************
void ArrayAllocation::insertionSortD(){
  int j;
  int *tmp;
  for (int i = 1; i < length; i++){  
    j = i;  
    while (j > 0 && *pArrayDown[j - 1] < *pArrayDown[j]){
      tmp = pArrayUp[j];
      pArrayDown[j] = pArrayDown[j - 1];
      pArrayDown[j - 1] = tmp;
      j--;
    }//end of while loop

  }//end of for loop
}//end of insertion_sort.


//*********************************************************
// The showSorted function uses cout to display the values*
// pointed to by the elements of the pArrayUp array. Since*
// pArrayUp is sorted, this function displays the elements*
// of the pArrayNum array in ascending order.             *
//*********************************************************
void ArrayAllocation::showSortedA()
{
	int size = length > 20?20:length;
	for (int count = 0; count < size; count++)
		cout << *(pArrayUp[count]) << " ";
	cout << endl;
}

//*********************************************************
// The showSorted function uses cout to display the values*
// pointed to by the elements of the pArrayUp array. Since*
// pArrayUp is sorted, this function displays the elements*
// of the pArrayNum array in descending order.            *
//*********************************************************
void ArrayAllocation::showSortedD()
{   
    int size = length > 20?20:length;
	for (int count = 0; count < size; count++)
		cout << *(pArrayDown[count]) << " ";
	cout << endl;
}
// END OF CLASS DEFINITION //
/////////////////////////////////
// This function adjusts the precision.
int getPrecision(const int millisec){ // USED FOR setprecision(#)
  return 5.100580114*pow(0.9981917788, millisec);
}

const int TARGET = 123456789;
// This target value will never be found, because it
// is larger than any random number generated by rand().
// Do not find the target to test for worst-case performance.

void showArray(int[], int);

// Each selection sort below does the same algorithm. The
// difference is in how well it documents its operation.
void selectionSort(int[], int);
void selectionSortDescribed(int[], int);
void selectionSortDescribedShowProgress(int[], int);
void selectionSortConcise(int[], int);
void bubbleSort(int[], int);
void quickSort(int[], int);

bool binarySearch(int[], int, int, int&);
bool linearSearchArray(int[], int, int, int&);

const int testSizes[] = { 1000, 5000, 10000, 20000, 30000, 40000, 50000, 0 };

// This code helps to automate multiple test runs.
//*****************************************************************
// SORTING ARRAY OF POINTERS ALGORITHM TESTING!					  *
// Copy and/or reuse this code as desired to test your algorithms.*                                       
//*****************************************************************
float testSelectSortA(int array[], int arraySize){
	for (int index = 0; index < arraySize; index++){
		array[index] = rand();
	}
	ArrayAllocation object1(array, arraySize);
	int startTime = clock();
	object1.selectSortA();
	int stopTime = clock();
	float duration = stopTime - startTime;
	return duration;
}

float testSelectSortD(int array[], int arraySize){
	for (int index = 0; index < arraySize; index++){
		array[index] = rand();
	}
	ArrayAllocation object2(array, arraySize);
	int startTime = clock();
	object2.selectSortD();
	int stopTime = clock();
	float duration = stopTime - startTime;
	return duration;
}

float testBubbleSortA(int array[], int arraySize){
	for (int index = 0; index < arraySize; index++){
		array[index] = rand();
	}
	ArrayAllocation obj3(array, arraySize);
	int startTime = clock();
	obj3.bubbleSortA();
	int stopTime = clock();
	float duration = stopTime - startTime;
	return duration;
}

float testBubbleSortD(int array[], int arraySize){
	for (int index = 0; index < arraySize; index++){
		array[index] = rand();
	}
	ArrayAllocation obj4(array, arraySize);
	int startTime = clock();
	obj4.bubbleSortD();
	int stopTime = clock();
	float duration = stopTime - startTime;
	return duration;
}
float testInsertionSortA(int array[], int arraySize){
	for (int index = 0; index < arraySize; index++){
		array[index] = rand();
	}
	ArrayAllocation obj5(array, arraySize);
	int startTime = clock();
	obj5.insertionSortA();
	int stopTime = clock();
	float duration = stopTime - startTime;
	return duration;
}

float testInsertionSortD(int array[], int arraySize){
	for (int index = 0; index < arraySize; index++){
		array[index] = rand();
	}
	ArrayAllocation obj6(array, arraySize);
	int startTime = clock();
	obj6.insertionSortD();
	int stopTime = clock();
	float duration = stopTime - startTime;
	return duration;
}
//*****************************************************************
// ALGORITHM TESTING!											  *
// Copy and/or reuse this code as desired to test your algorithms.*                                       
//*****************************************************************
float testQuickSort(int array[], int arraySize) {
  // fill the array with random, unsorted numbers before sorting it
  for (int index = 0; index < arraySize; index++)
    array[index] = rand();  // initialize array with random values
  int startTime = clock(); // start the test clock
  quickSort(array, arraySize);  // ALGORITHM UNDER TEST
  int stopTime = clock();  // stop the test clock
  float duration = stopTime - startTime;
  return duration;
}

float testBubbleSort(int array[], int arraySize) {
  // fill the array with random, unsorted numbers before sorting it
  for (int index = 0; index < arraySize; index++)
    array[index] = rand();  // initialize array with random values
  int startTime = clock(); // start the test clock
  bubbleSort(array, arraySize);  // ALGORITHM UNDER TEST
  int stopTime = clock();  // stop the test clock
  float duration = stopTime - startTime;
  return duration;
}

float testSelectionSort(int array[], int arraySize) {
  // fill the array with random, unsorted numbers before sorting it
  for (int index = 0; index < arraySize; index++)
    array[index] = rand();  // initialize array with random values
  int startTime = clock(); // start the test clock
  selectionSortDescribed(array, arraySize);  // ALGORITHM UNDER TEST
  int stopTime = clock();  // stop the test clock
  float duration = stopTime - startTime;
  return duration;
}

float testLinearSearch(int array[], int arraySize) {
  bool found = false; // true if TARGET is found in array
  int foundAt = 0;    // index in array where TARGET was found
  int startTime = clock();
  for (int repeat = 0; repeat < 50000; repeat++)
    found = linearSearchArray(array, arraySize, TARGET, foundAt); // ALGORITHM UNDER TEST
  int stopTime = clock();
  float duration = stopTime - startTime;
  duration /= 50000.0;
  return duration;
}

float testBinarySearch(int array[], int arraySize) {
  bool found = false; // true if TARGET is found in array
  int foundAt = 0;    // index in array where TARGET was found
  int startTime = clock();
  for (int repeat = 0; repeat < 2000000; repeat++)
    found = binarySearch(array, arraySize, TARGET, foundAt); // ALGORITHM UNDER TEST
  int stopTime = clock();
  float duration = stopTime - startTime;
  duration /= 2000000.0; 
  return duration;
}

void testAlgorithms(int array[], int arraySize) {
  // This draws a table of results for each algorithm tested.
  cout << setw(10) << left << "Algorithm";
  int testCount = 0;
  while (testSizes[testCount])
    cout << setw(9) << right << testSizes[testCount++];
  cout << endl;
  cout << setw(10) << left << "==========";
  testCount = 0;
  while (testSizes[testCount++])
    cout << setw(9) << right << " =======";
  cout << endl;

  testCount = 0;
  cout << setw(10) << left << "selectSort";
  while (testSizes[testCount] && testSizes[testCount] <= arraySize){
    float result = testSelectionSort(array, testSizes[testCount++]);
    cout << fixed << setprecision(getPrecision(result));
    cout << setw(9) << right << result;
  }
  cout << endl;

  testCount = 0;
  cout << setw(10) << left << "linearSrch";
  while (testSizes[testCount] && testSizes[testCount] <= arraySize){
    float result = testLinearSearch(array, testSizes[testCount++]);
    cout << fixed << setprecision(getPrecision(result));
    cout << setw(9) << right << result;
  }
  cout << endl;
  // Add a loop to call and test your first sort algorithm here
  testCount = 0;
  cout << setw(10) << left << "bubbleSort";
  while (testSizes[testCount] && testSizes[testCount] < arraySize){
    float result = testBubbleSort(array, testSizes[testCount++]);
    cout << fixed << setprecision(getPrecision(result));
    cout << setw(9) << right << result;
  }
  cout << endl;
  // Add a loop to call and test your second sort algorithm here
  testCount = 0;
  cout << setw(10) << left << "quickSort";
  while (testSizes[testCount] && testSizes[testCount] <= arraySize){
    float result = testQuickSort(array, testSizes[testCount++]);
    cout << fixed << setprecision(getPrecision(result));
    cout << setw(9) << right << result;
  }
  cout << endl;
  // Add a loop to call and test your search algorithm here
  testCount = 0;
  cout << setw(10) << left << "binarySrch";
  while (testSizes[testCount] && testSizes[testCount] <= arraySize){
    float result = testBinarySearch(array, testSizes[testCount++]);
    cout << fixed << setprecision(getPrecision(result));
    cout << setw(9) << right << result;
  }
  cout << endl;
//*****************************************************************
// SORTING ARRAY OF POINTERS ALGORITHM TESTING!					  *
// Copy and/or reuse this code as desired to test your algorithms.*                                       
//*****************************************************************
  // Add a loop to call and test your first sort algorithm here
  testCount = 0;
  cout << setw(10) << left << "*slctSrtA ";
  while (testSizes[testCount] && testSizes[testCount] <= arraySize){
    float result = testSelectSortA(array, testSizes[testCount++]);
    cout << fixed << setprecision(getPrecision(result));
    cout << setw(9) << right << result;
  }
  cout << endl;
  // Add a loop to call and test your first sort algorithm here
  testCount = 0;
  cout << setw(10) << left << "*slctSrtD ";
  while (testSizes[testCount] && testSizes[testCount] <= arraySize){
    float result = testSelectSortD(array, testSizes[testCount++]);
    cout << fixed << setprecision(getPrecision(result));
    cout << setw(9) << right << result;
  }
  cout << endl;
  // Add a loop to call and test your first sort algorithm here
  testCount = 0;
  cout << setw(10) << left << "*bblSrtA  ";
  while (testSizes[testCount] && testSizes[testCount] < arraySize){
    float result = testBubbleSortA(array, testSizes[testCount++]);
    cout << fixed << setprecision(getPrecision(result));
    cout << setw(9) << right << result;
  }
  cout << endl;
  // Add a loop to call and test your first sort algorithm here
  testCount = 0;
  cout << setw(10) << left << "*bblSrtD  ";
  while (testSizes[testCount] && testSizes[testCount] < arraySize){
    float result = testBubbleSortD(array, testSizes[testCount++]);
    cout << fixed << setprecision(getPrecision(result));
    cout << setw(9) << right << result;
  }
  cout << endl;
  // Add a loop to call and test your first sort algorithm here
  testCount = 0;
  cout << setw(10) << left << "*insSrtA  ";
  while (testSizes[testCount] && testSizes[testCount] <= arraySize){
    float result = testInsertionSortA(array, testSizes[testCount++]);
    cout << fixed << setprecision(getPrecision(result));
    cout << setw(9) << right << result;
  }
  cout << endl;
  // Add a loop to call and test your first sort algorithm here
  testCount = 0;
  cout << setw(10) << left << "*insSrtD  ";
  while (testSizes[testCount] && testSizes[testCount] <= arraySize){
    float result = testInsertionSortD(array, testSizes[testCount++]);
    cout << fixed << setprecision(getPrecision(result));
    cout << setw(9) << right << result;
  }
  cout << endl;
}


int main() {
  int foundit = 0;
  bool founder = true;
  // the random number generator has to be "seeded" only once.
  unsigned int seed = time(0);
  srand(seed);

  // When first implementing your algorithm, you may want to test it
  // on a very small array. If so, uncomment the lines below.
  const int SMALLSIZE = 6;
  int smallArray[SMALLSIZE] = { 5, 7, 2, 8, 9, 1 }; // for testing purposes

  cout << "UNSORTED smallArray is: "; showArray(smallArray, SMALLSIZE);
  selectionSortDescribedShowProgress(smallArray, SMALLSIZE);
  cout << "SORTED   smallArray is: "; showArray(smallArray, SMALLSIZE);

  // When first implementing your algorithm, you may want to test it
  // on a very small array. If so, try it on smallArray below.
  int smallArray1[SMALLSIZE] = { 5, 7, 2, 8, 9, 1 };
  founder = binarySearch(smallArray1, SMALLSIZE, TARGET, foundit);
  const int BIGSIZE = 50000;
  int bigArray[BIGSIZE];
  float duration = 0.0; // time in milliseconds
  while(true){
   	cout << "\nSpecify the array size: 0 to quit ";
	int arraySize = 0;
	cin >> arraySize;
	if(!arraySize) break;
	try{
	  cout << "\nTesting Selection Sort Ascending!\n" << endl;
	  ArrayAllocation object1(arraySize);
	  object1.selectSortA();
	  object1.showSortedA();
	  cout << "Testing Selection Sort Descending!\n" << endl;
	  ArrayAllocation object2(arraySize);
	  object2.selectSortD();
	  object2.showSortedD();
	  cout << "Testing Bubble Sort Ascending!\n" << endl;
	  ArrayAllocation object3(arraySize);
	  object3.bubbleSortA();
	  object3.showSortedA();	  
	  cout << "Testing Bubble Sort Descending!\n" << endl;
	  ArrayAllocation object4(arraySize);
	  object4.bubbleSortD();
	  object4.showSortedD();
	  cout << "Testing Insertion Sort Ascending!\n" << endl;
	  ArrayAllocation object5(arraySize);
	  object5.insertionSortA();
	  object5.showSortedA();	   
	  cout << "Testing Insertion Sort Descending!\n" << endl;
	  ArrayAllocation object6(arraySize);
	  object6.insertionSortD();
	  object6.showSortedD();
	}
	catch (char *exceptionString){
	cout << exceptionString;
	}	
}   
  // Do a single test run using the full size of bigArray
  // Quick Sort
  duration = testQuickSort(bigArray, BIGSIZE);
  cout << fixed << setprecision(getPrecision(duration));
  cout << "\nQuick sort on bigArray took    : "
    << setw(3) << duration << " milliseconds." << endl;
  // Binary Search
  duration = testBinarySearch(bigArray, BIGSIZE);
  cout << fixed << setprecision(getPrecision(duration));
  cout << "Binary search on bigArray took : "
    << setw(3) << duration << " milliseconds." << endl;
  // Bubble Sort.
  duration = testBubbleSort(bigArray, BIGSIZE);
  cout << fixed << setprecision(getPrecision(duration));
  cout << "Bubble sort on bigArray took   : "
    << setw(3) << duration << " milliseconds." << endl;

  duration = testSelectionSort(bigArray, BIGSIZE);
  cout << fixed << setprecision(getPrecision(duration));
  cout << "Selection sort on bigArray took: "
    << setw(3) << duration << " milliseconds." << endl;

  duration = testLinearSearch(bigArray, BIGSIZE);
  cout << fixed << setprecision(getPrecision(duration));
  cout << "Linear search  of bigArray took: "
    << setw(3) << duration << " milliseconds." << endl;
//*****************************************************************
// SORTING ARRAY OF POINTERS ALGORITHM TESTING!					  *
// Copy and/or reuse this code as desired to test your algorithms.*                                       
//*****************************************************************    
  duration = testSelectSortA(bigArray, BIGSIZE);
  cout << fixed << setprecision(getPrecision(duration));
  cout << "*SelectSortA of bigArray took  : "
    << setw(3) << duration << " milliseconds." << endl;
    
  duration = testSelectSortD(bigArray, BIGSIZE);
  cout << fixed << setprecision(getPrecision(duration));
  cout << "*SelectSortD of bigArray took  : "
    << setw(3) << duration << " milliseconds." << endl;
    
  duration = testBubbleSortA(bigArray, BIGSIZE);
  cout << fixed << setprecision(getPrecision(duration));
  cout << "*BubbleSortA of bigArray took  : "
    << setw(3) << duration << " milliseconds." << endl;

  duration = testBubbleSortD(bigArray, BIGSIZE);
  cout << fixed << setprecision(getPrecision(duration));
  cout << "*BubbleSortD of bigArray took  : "
    << setw(3) << duration << " milliseconds." << endl;
 
  duration = testInsertionSortA(bigArray, BIGSIZE);
  cout << fixed << setprecision(getPrecision(duration));
  cout << "*InsertSortA of bigArray took  : "
    << setw(3) << duration << " milliseconds." << endl;
    
  duration = testInsertionSortD(bigArray, BIGSIZE);
  cout << fixed << setprecision(getPrecision(duration));
  cout << "*InsertSortD of bigArray took  : "
    << setw(3) << duration << " milliseconds.\n" << endl;
  // Test the algorithms on ever longer list of numbers. Only one
  // array is needed.  Lengths of 1000, 5000, 10000, 20000, 30000,
  // 40000, 50000 are tested.
  testAlgorithms(bigArray, BIGSIZE);
  cout << endl;

  system("pause");
  return 0;
} // end of main

//////////////////////////////////////////////
// Add your first sort algorithm in here
void bubbleSort(int list[], int size){
  int temp;
  bool swap;
  do{
    swap = false;
    for (int i = 0; i < (size - 1); i++){       // The letter 'i' is used for the index/subscript of the array.
      // If the first element of the list is greater than the one that follows it; swap their position.
      if (list[i] > list[i + 1]){
        // The temp variable holds the first element of the list.
        temp = list[i];
        // Since the element list[i + 1] is smaller; move its value and assign it to list[1].
        list[i] = list[i + 1];
        // Since the element list[i] is greater; move its value and assign it to list[i +1];
        list[i + 1] = temp;
        // This enables the algorithm to keep looping until the array is sorted.
        swap = true;
      }
    }
    // When the array becomes sorted; swap will be false.
  } while (swap);
}
// Add your second sort algorithm in here
void quickSort(int **array, int size) {
  if (size < 2)			    // If the size of the array is less than two elements; it cannot be sorted.
    return;
  int pivot = *(array[size / 2]);
  int **firstElement = array;				// "*firstElement" is a pointer to the first element of the array.
  int **lastElement = array + size - 1;	// "*LastElement" is a pointer to the last element of the array.
  //cout << "This is *firstElement: " << *firstElement << endl;
  //cout << "This is *lastElement: " << *lastElement << endl;
  //cout << "This is pivot: " << pivot << endl; 	
  while (firstElement <= lastElement) { // This compares the addresses of the first and last elements
    if (**firstElement < pivot) {
      firstElement++;
      //showArray(array, size);
      continue;
    }
    if (**lastElement > pivot) {
      lastElement--;
      //showArray(array, size);
      continue; // we need to check the condition (l <= r) every time we change the value of l or r
    }
    // This is a swap.
    int *temp = *firstElement;
    *firstElement++ = *lastElement;
    *lastElement-- = temp;
  }
  quickSort(array, lastElement - array + 1);
  quickSort(firstElement, array + size - firstElement);
}
// Add your second sort algorithm in here
void quickSort(int array[], int size) {
  if (size < 2)			    // If the size of the array is less than two elements; it cannot be sorted.
    return;
  int pivot = array[size / 2];
  int *firstElement = array;				// "*firstElement" is a pointer to the first element of the array.
  int *lastElement = array + size - 1;	// "*LastElement" is a pointer to the last element of the array.
  //cout << "This is *firstElement: " << *firstElement << endl;
  //cout << "This is *lastElement: " << *lastElement << endl;
  //cout << "This is pivot: " << pivot << endl; 	
  while (firstElement <= lastElement) { // This compares the addresses of the first and last elements
    if (*firstElement < pivot) {
      firstElement++;
      //showArray(array, size);
      continue;
    }
    if (*lastElement > pivot) {
      lastElement--;
      //showArray(array, size);
      continue; // we need to check the condition (l <= r) every time we change the value of l or r
    }
    // This is a swap.
    int temp = *firstElement;
    *firstElement++ = *lastElement;
    *lastElement-- = temp;
  }
  quickSort(array, lastElement - array + 1);
  quickSort(firstElement, array + size - firstElement);
}
// Add your search algorithm in here
bool binarySearch(int array[], int size, int targ, int &found){
  int first = 0;            // First array element 
  int last = size - 1;      // Last array element
  int middle;
  bool foundit = false;
  while (!foundit && first <= last){
    middle = (first + last) / 2;         // Calculates the midpoint of the array.
    if (array[middle] == targ){          // If the target is found at the midpoint of the array
      foundit = true;
      found = middle;
      return true;
    }
    else if (array[middle] > targ)      // If the middle is greater than the value; 
      last = middle - 1;                // target must be in the lower half of the array.
    else
      first = middle + 1;               // The target must be in
  }
  return false;
}
//////////////////////////////////////////////

void showArray(int array[], int size) {
  for (int count = 0; count < size; count++)
    cout << setw(2) << array[count] << ' ';
  cout << endl;
}

bool linearSearchArray(int a[], int s, int t, int &p) {
  // This is different from the textbook. If you use this, write in
  // your own words; use good variable names and add useful comments.
  for (int i = 0; i < s; i++) if (a[i] == t) { p = i; return true; }
  p = -1;
  return false;
}


// This is the selection sort from our textbook
void selectionSort(int array[], int size) {
  int startScan, minIndex, minValue;
  for (startScan = 0; startScan < (size - 1); startScan++) {
    minIndex = startScan;
    minValue = array[startScan];
    for (int index = startScan + 1; index < size; index++) {
      if (array[index] < minValue) {
        minValue = array[index];
        minIndex = index;
      }
    }
    array[minIndex] = array[startScan];
    array[startScan] = minValue;
  }
}

// This is selection sort described in more detail
void selectionSortDescribed(int array[], int size) {
  int minIndexSoFar = 0, minValueSoFar;
  for (int unsortedIndex = 0; unsortedIndex < (size - 1); unsortedIndex++) {
    // The outer loop looks at unsorted data, which is initially the whole array.
    // Gradually, a smaller and smaller portion of the array remains unsorted.
    minIndexSoFar = unsortedIndex;
    minValueSoFar = array[unsortedIndex];
    for (int seekMinIndex = unsortedIndex + 1; seekMinIndex < size; seekMinIndex++) {
      // the inner loop seeks the smallest value possible in the
      // remaining unsorted portion of the array.
      if (array[seekMinIndex] < minValueSoFar) {
        // found a smaller value than I had before, save it for now
        minValueSoFar = array[seekMinIndex];
        minIndexSoFar = seekMinIndex;
      }
    }
    // The smallest value in the unsorted portion of the array has been found.
    // Replace the older minimum value, which wasn't really the actual minimum
    // value, with the new, real minimum value which was just found.
    array[minIndexSoFar] = array[unsortedIndex];
    array[unsortedIndex] = minValueSoFar;
    // ... continue seeking the minimum value in the smaller remaining portion.
  }
}

// This is selection sort described in great detail
// It also shows the result of each pass of the outer loop.
void selectionSortDescribedShowProgress(int array[], int size) {
  int minIndexSoFar = 0, minValueSoFar;
  for (int unsortedIndex = 0; unsortedIndex < (size - 1); unsortedIndex++) {
    // The outer loop looks at unsorted data, which is initially the whole array.
    // Gradually, a smaller and smaller portion of the array remains unsorted.
    minIndexSoFar = unsortedIndex;
    minValueSoFar = array[unsortedIndex];
    for (int seekMinIndex = unsortedIndex + 1; seekMinIndex < size; seekMinIndex++) {
      // the inner loop seeks the smallest value possible in the
      // remaining unsorted portion of the array.
      if (array[seekMinIndex] < minValueSoFar) {
        // found a smaller value than I had before, save it for now
        cout << "  previous min value: " << minValueSoFar << " at offset: " << minIndexSoFar;
        minValueSoFar = array[seekMinIndex];
        minIndexSoFar = seekMinIndex;
        cout << "; found smaller value: " << minValueSoFar << " at offset: " << minIndexSoFar << endl;
      }
    }
    // The smallest value in the unsorted portion of the array has been found.
    // Replace the older minimum value, which wasn't really the actual minimum
    // value, with the new, real minimum value which was just found.
    array[minIndexSoFar] = array[unsortedIndex];
    array[unsortedIndex] = minValueSoFar;
    cout << "  swapped the previous minimum value: " << array[minIndexSoFar]
      << " with with new minimum value: " << array[unsortedIndex] << endl;
    cout << "After pass " << unsortedIndex << " the array looks like this: ";
    showArray(array, size);
    cout << endl;
    // ... continue seeking the minimum value in the smaller remaining portion.
  }
}

// This is a selection sort from a concise algorithm encyclopedia.
// As is, it is VERY CRYPTIC!
void selectionSortConcise(int array[], int size) {
  int i, idx, val;
  for (i = 0; i < (size - 1); i++) {
    idx = i;
    val = array[i];
    for (int j = i + 1; j < size; j++) {
      if (array[j] < val) {
        val = array[j];
        idx = j;
      }
    }
    array[idx] = array[i];
    array[i] = val;
  }
}

/*
UNSORTED smallArray is:  5  7  2  8  9  1
  previous min value: 5 at offset: 0; found smaller value: 2 at offset: 2
  previous min value: 2 at offset: 2; found smaller value: 1 at offset: 5
  swapped the previous minimum value: 5 with with new minimum value: 1
After pass 0 the array looks like this:  1  7  2  8  9  5

  previous min value: 7 at offset: 1; found smaller value: 2 at offset: 2
  swapped the previous minimum value: 7 with with new minimum value: 2
After pass 1 the array looks like this:  1  2  7  8  9  5

  previous min value: 7 at offset: 2; found smaller value: 5 at offset: 5
  swapped the previous minimum value: 7 with with new minimum value: 5
After pass 2 the array looks like this:  1  2  5  8  9  7

  previous min value: 8 at offset: 3; found smaller value: 7 at offset: 5
  swapped the previous minimum value: 8 with with new minimum value: 7
After pass 3 the array looks like this:  1  2  5  7  9  8

  previous min value: 9 at offset: 4; found smaller value: 8 at offset: 5
  swapped the previous minimum value: 9 with with new minimum value: 8
After pass 4 the array looks like this:  1  2  5  7  8  9

SORTED   smallArray is:  1  2  5  7  8  9

Specify the array size: 0 to quit 5

Testing Selection Sort Ascending!

1 1 1 4 5
Testing Selection Sort Descending!

5 5 4 3 3
Testing Bubble Sort Ascending!

3 3 4 4 5
Testing Bubble Sort Descending!

4 4 4 1 1
Testing Insertion Sort Ascending!

1 1 1 5 5
Testing Insertion Sort Descending!

5 1 1 1 1

Specify the array size: 0 to quit 10

Testing Selection Sort Ascending!

3 3 3 3 3 5 6 6 8 9
Testing Selection Sort Descending!

9 9 7 6 5 3 3 3 1 1
Testing Bubble Sort Ascending!

1 1 1 2 3 5 5 9 9 10
Testing Bubble Sort Descending!

10 7 6 5 1 1 1 1 1 1
Testing Insertion Sort Ascending!

1 1 1 1 1 2 3 5 6 8
Testing Insertion Sort Descending!

10 7 9 7 4 6 2 4 3 2

Specify the array size: 0 to quit 0

Quick sort on bigArray took    : 20.0000 milliseconds.
Binary search on bigArray took : 0.00029 milliseconds.
Bubble sort on bigArray took   : 19000 milliseconds.
Selection sort on bigArray took: 3860 milliseconds.
Linear search  of bigArray took: 0.15380 milliseconds.
*SelectSortA of bigArray took  : 5340 milliseconds.
*SelectSortD of bigArray took  : 5340 milliseconds.
*BubbleSortA of bigArray took  : 21910 milliseconds.
*BubbleSortD of bigArray took  : 21900 milliseconds.
*InsertSortA of bigArray took  : 6820 milliseconds.
*InsertSortD of bigArray took  : 3970 milliseconds.

Algorithm      1000     5000    10000    20000    30000    40000    50000
==========  =======  =======  =======  =======  =======  =======  =======
selectSort  0.00000  40.0000  150.000    610.0     1360     2410     3780
linearSrch  0.00300  0.01500  0.03020  0.06040  0.09080  0.12080  0.15080
bubbleSort  0.00000  160.000    630.0     2500     5680    10090
quickSort   0.00000  0.00000  0.00000 10.00000  0.00000 10.00000 10.00000
binarySrch  0.00009  0.00010  0.00012  0.00012  0.00012  0.00013  0.00013
*slctSrtA   0.00000  50.0000  200.000    840.0     1880     3370     5310
*slctSrtD   0.00000  50.0000  210.000    830.0     1890     3390     5330
*bblSrtA    0.00000  210.000    810.0     3390     7740    13840
*bblSrtD   10.00000  200.000    830.0     3390     7730    13870
*insSrtA   10.00000  60.0000  270.000     1070     2430     4340     6840
*insSrtD    0.00000  40.0000  270.000   400.00     1500     1030     2430

Press any key to continue . . .
*/
