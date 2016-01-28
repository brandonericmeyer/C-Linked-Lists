// Section CS362 - Data Structures
// File Name: main.cpp
// Student: Brandon Meyer
// Homework Number: Week 7, Program 6
// Description: Week 7 - Linked lists using apartment rentals.
// Started on: June 16, 2015
// Last Changed: June 23, 2015

#include "MeyerHeader.h"

int main( )
{
	apartment *head = NULL;
	apartment *last = NULL;
	string phone = "";
	double rent = 0;
	bool status = false;

	cout << "Welcome to apartment modifer v2!" << endl << endl;
	
	read_file(head, last, phone, rent, status);  // Reads in list.

	user_menu(head, last, phone, rent, status);// Shows user menu.
	
	deletePointers(head); // Deletes head pointer.

	system("Pause");
   	return 0;
}
