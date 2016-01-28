// Section CS362 - Data Structures
// File Name: header.cpp
// Student: Brandon Meyer
// Homework Number: Week 7, Program 6
// Description: Header file for week 7 - Linked lists.
// Started on: June 16, 2015
// Last Changed: June 23, 2015

#ifndef H_header
#define H_header
#define NULL 0

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <cctype>
#include <cmath>
#include <iomanip>
#include <cstddef>

using namespace std;

struct apartment
{
	string phone;
	double rent;
	bool status;
	apartment* next; // link nodes
};

// read_file constants
const string DISPLAY_LOAD_Q1 = "Would you like to load existing data (Y/N)? ";
const string DISPLAY_LOAD_INVALID = "Invalid Choice.  Try again.";
const string DISPLAY_FILE_Q1 = "Enter the filename you wish to load: ";
const string DISPLAY_EMPTY_Q1 = "The file has been found, but the list is empty.";
const string DISPLAY_PB_LOAD = "Error - Cannot load file.";
const string DISPLAY_T_P = "Enter 'T' to try again or 'P' to proceed without loading data: ";
const string DISPLAY_Q1_SUC = "File has been successfully created!";
const string NEW_FILE = "RENTALS.txt";

// show_rentals constants
const string DISPLAY_PHONE = "Phone Number";
const string MONTHLY_RENT = "Monthly Rent";
const string STATUS = "Status";
const string EMPTY_LIST_SR = "Error - the list is empty";

//// user_menu constants
const string DISPLAY_MENU_1 = "S - Show Rental(s)";
const string DISPLAY_MENU_2 = "A - Add Rental(s)";
const string DISPLAY_MENU_3 = "D - Delete Rental(s)";
const string DISPLAY_MENU_5 = "M - Modify Rent";
const string DISPLAY_MENU_4 = "E - Exit the Program";
const string ASK_USER = "Enter your choice: ";
const string ERROR_INVALID = "Error - INVALID choice entered.";
const string ERROR_EMPTY_LIST = "No apartment rentals are stored.";

// modifyRental constants
const string FILE_TO_MOD = "MODS.txt";
const string MEMORY_PB = "Error - memory could not be allocated";
const string NO_MATCHES = "There were no matches found to modify!";
const string NEW_MONTHLY_TITLE = "New Monthly Rent";
const string NO_EXIST_MODS = "File MODS.txt does not exist.";

// delete_stored_data constants
const string ENTER_NUMBER = "Please choose a phone number below to delete:";
const string NUM_FOUND = "Phone number has been found!";
const string NOT_FOUND = "Phone number not found!";
const string NUM_DEL = "Phone number has been successfully deleted.";
const string NUM_DEL_2 = " not found in list.";
const string NUM_DEL_3 = "Error - Failed deletion.";

// add_rental
const string ASK_FOR_MORE = "Would you like to add another renter? (Y or N): ";
const string ERROR_INVALID_RENT = "ERROR - Invalid input.  Please try again.";

// validate_status constants
const string APT_RENTED = "Is the apartment currently rented(Y / N) ? ";
const string ERROR_INVALID_STATUS = "ERROR - INVALID FORMAT.";

// validate_monthlyRent constants
const string ENTER_RENT = "Enter the total monthly rent: ";
const string ERROR_NOT_VALID = "ERROR - Invalid format, ex: 1250.00";
const string RENT_REENTER = "Please re-enter the total monthly rent: ";

// validate_phone_number constants
const string ENTER_PHONE = "Enter the phone number: ";
const string ERROR_NUM_LENGTH = "ERROR - Number must be a length of 12, including dashes!";
const string ERROR_NUM_INVALID_1 = "ERROR - Invalid format, alphabetic letter. ex: 222-222-2222";
const string ERROR_NUM_INVALID_2 = "ERROR - Invalid format, ex: 222-222-2222";

// exit_prompt constants
const string ASK_TO_SAVE = "Would you like to save to a file (Y/N) ? ";
const string WILL_SAVE = "Data will be saved.";
const string NO_SAVE = "Data will not be saved.";
const string FILE_NAME_INPUT = "Enter a filename: ";
const string WARN_OVER = "WARNING - you are about to overwrite an existing file";
const string IT_OVERWRITE = "File has been overwritten.";
const string GO_ON = "Would you like to continue (Y/N)? ";
const string BYE = "Good-Bye...";
const string FILE_1E = "File ";
const string FILE_2E = " has been saved.";

// Prototypes
bool isEmpty(apartment *&head);
bool validate_status();
string validate_phone_number();
double validate_monthlyRent();
void read_file(apartment *&head, apartment *&last, string phone, double rent, bool status);
void user_menu(apartment *&head, apartment *&last, string phone, double rent, bool status);
void insertAsFirstElement(apartment *&head, apartment *&last, string phone, double rent, bool status);
void insert(apartment *&head, apartment *&last, string phone, double rent, bool status);
void showList(apartment *current);
void add_rental(apartment *&head, apartment *&last, string phone, double rent, bool status);
void delete_stored_data(apartment* &current, apartment* &last, string phone);
void exit_prompt(apartment *&current, bool & exit_program);
void write_data(apartment *&current, string & fileName);
void deletePointers(apartment *&current);
void modifyRent(apartment *&current);
void deleteNode(apartment* &head, string phone, bool& success);
#endif
