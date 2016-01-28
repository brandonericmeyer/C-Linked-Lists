// Section CS362 - Data Structures
// File Name: IMP.cpp
// Student: Brandon Meyer
// Homework Number: Week 7, Program 6
// Description: Implementation file for week 7 - Linked lists.
// Started on: June 16, 2015
// Last Changed: June 23, 2015

#include "MeyerHeader.h"

//*********************************************************************
// FUNCTION: read_file
// DESCRIPTION: Reads a file.
// INPUT:
// Parameters: head - pointer to the first node, last - pointer to the last node,
//  phone - holds the phone num, rent - holds the rent, status - holds the status
// CALLS TO: insert
//**********************************************************************
void read_file(apartment *&head, apartment *&last, string phone, double rent, bool status)
{
	ifstream inFile;
	ofstream outFile;

	string line;
	string file_name;
	string storeNum;
	string storeRent;
	string storeStatus;
	string load_data_option;
	string proceed_or_try_choice;
	bool file_success = false;
	char read_in = ' ';
	char x;

	cout << DISPLAY_LOAD_Q1;

	cin >> load_data_option;

	load_data_option[0] = toupper(load_data_option[0]);

	if (load_data_option != "Y" && load_data_option != "N")
	{
		do
		{
			if (load_data_option != "Y" && load_data_option != "N")
			{
				cin.clear();
				
				cin.ignore(10000, '\n');
			}

			cout << endl << DISPLAY_LOAD_INVALID << endl;

			cout << endl << DISPLAY_LOAD_Q1;

			cin >> load_data_option;

			load_data_option[0] = toupper(load_data_option[0]);
			
		} while (load_data_option != "Y" && load_data_option != "N");
	}

	do
	{
		if (load_data_option[0] == 'Y')
		{
			cout << endl << DISPLAY_FILE_Q1;

			cin >> file_name;

			inFile.open(file_name.c_str());

			if (inFile)
			{
				if (!(inFile >> x))
				{
					cout << endl << DISPLAY_EMPTY_Q1 << endl;

					file_success = true;
				}
				else
				{
					inFile.putback(x);

					while (getline(inFile, line)) // Read to the end of the file.
					{

						for (int i = 0; i < line.length(); i++)
						{
							if (i >= 0 && i < 12)
							{
								storeNum = storeNum + line[i];

								phone = storeNum;
							}
							else if (i >= 13)
							{
								storeRent = storeRent + line[i];

								rent = atof(storeRent.c_str());

								if (isspace(line[i]))
								{
									i = line.length() - 1;
								}
							}

							if (i == line.length() - 1)
							{
								storeStatus = line[i];

								status = atoi(storeStatus.c_str());
							}
						} // end for

						insert(head, last, phone, rent, status); // insert in to list.

						phone = "";
						
						storeRent = "";
						
						storeNum = "";

					} // end while

				inFile.close(); // Calls to find functions will re-open the file from the top position to be read in.

				file_success = true;
				}
			}
			else if (!(inFile))
			{
				cout << endl << DISPLAY_PB_LOAD << endl;

				while (!(inFile) && file_success == false)
				{
			    	cin.clear();
						
				    cin.ignore(10000, '\n');
				
					cout << endl << DISPLAY_T_P;

					cin >> proceed_or_try_choice;

					proceed_or_try_choice[0] = toupper(proceed_or_try_choice[0]);

					if (proceed_or_try_choice == "T")
					{
						inFile.clear();
						
						cin.ignore(10000, '\n');

						cout << endl << DISPLAY_FILE_Q1;

						cin >> file_name;

						inFile.open(file_name.c_str());

						if (!(inFile))
						{
							cout << endl << DISPLAY_PB_LOAD << endl;

						}
						else if (inFile)
						{
							file_success = true;
						}
					}
					else if (proceed_or_try_choice == "P")
					{
						ofstream fileName(NEW_FILE.c_str(), ios::out); // Write new file out.

						inFile.open(NEW_FILE.c_str());

						if (inFile)
						{
							cout << endl << DISPLAY_Q1_SUC << endl;
						}

						file_success = true;

					}
					else
					{
						cout << endl << DISPLAY_LOAD_INVALID << endl;
					}
				}
			}
		}
		else if (load_data_option[0] == 'N')
		{
			ofstream fileName(NEW_FILE.c_str(), ios::out);

			inFile.open(NEW_FILE.c_str());

			if (inFile)
			{
				cout << endl << DISPLAY_Q1_SUC << endl;

				file_success = true;
			}
		}

	} while (file_success == false);

	inFile.close();
	
	outFile.close();

}
//*********************************************************************
// FUNCTION: user_menu
// DESCRIPTION: Main user menu displayed to user.  Can access show, delete, modify, add, or exit from program.
// INPUT:
// Parameters: head - pointer to the first node, last - pointer to the last node,
//  phone - holds the phone num, rent - holds the rent, status - holds the status
// CALLS TO: delete_stored_data, exit_prompt, showList, modifyRent, and add_rental.
//**********************************************************************
void user_menu(apartment *&head, apartment *&last, string phone, double rent, bool status)
{
	string user_options;
	bool exit_program = false;
	bool emptyStatus = false;

	while (exit_program != true)
	{
		cout << endl << DISPLAY_MENU_1 << endl
		 << DISPLAY_MENU_2 << endl
		 << DISPLAY_MENU_3 << endl
		 << DISPLAY_MENU_5 << endl
		 << DISPLAY_MENU_4 << endl;

		cout << endl << ASK_USER;

		cin >> user_options;

		user_options[0] = toupper(user_options[0]);

		while (user_options.length() != 1)
		{
			cout << endl << DISPLAY_LOAD_INVALID << endl;

			cin.clear();

			cin.ignore(10000, '\n');

			cout << endl << ASK_USER;

			cin >> user_options;

			user_options[0] = toupper(user_options[0]);
		}

		switch (user_options[0])
		{
		case 'S':
			showList(head);
			break;
		case 'A':
			add_rental(head, last, phone, rent, status);
			break;
		case 'D':
			delete_stored_data(head, last, phone);
			break;
		case 'M':
			modifyRent(head);
			break;
		case 'E':
			exit_prompt(head, exit_program);
			break;
		default:
			cout << endl << DISPLAY_LOAD_INVALID << endl;

			cin.clear();

			cin.ignore(10000, '\n');

			break;
		}
	}
}
//*********************************************************************
// FUNCTION: modifyRent
// DESCRIPTION: Function to modify the rent.
// INPUT:
// Parameters: current - pointer to the head head.
//**********************************************************************
void modifyRent(apartment *&current)
{
	apartment *temp = current;
	ifstream inFile;
	string line;
	string storeNum;
	string storeRent;
	string storeSign;
	string phone;
	double rent;
	bool searchNum = false;
	char x;
	int size = 0;
	int arrayPos = 0;

	inFile.open(FILE_TO_MOD.c_str());

	if (inFile)
	{
		if (!(inFile >> x))
		{
			cout << endl << DISPLAY_EMPTY_Q1 << endl;
		}
		else
		{
			inFile.putback(x);

			while (getline(inFile, line)) // Read to the end of the file and count lines to be used in dynamic array.
			{
				size++;
			}

			string* arrayPhone = new (nothrow)string[size];

			if (arrayPhone == NULL)  // Checking for allocation
			{
				cout << endl << MEMORY_PB << endl;
			}
			else
			{
				inFile.clear();
				
                inFile.seekg(0, ios::beg); // Reset to the start of the file.

				while (getline(inFile, line)) // Read to the end of the file.
				{
					for (int i = 0; i < line.length(); i++) // Store phone number
					{
						if (i >= 0 && i < 12)
						{
							storeNum = storeNum + line[i];

							phone = storeNum;

						}
						else if (i >= 13) // Store rent.
						{
							storeRent = storeRent + line[i];

							rent = atof(storeRent.c_str());

							if (i == 13)
							{
								storeSign = line[i]; // Store sign. (+ or -)
							}
						}
					}

					while (temp != NULL) // Search node list for phone number to modify.
					{
						if (phone == temp->phone)
						{
							if (storeSign == "+")
							{
								temp->rent = temp->rent + rent;
							}
							else if (storeSign == "-")
							{
								temp->rent = temp->rent + rent;
							}
							
							arrayPhone[arrayPos] = temp->phone;

							if (arrayPos != size)
							{
								arrayPos++;
							}

							searchNum = true;
						}

						temp = temp->next;

					} // end while - search node list

					phone = "";
					
					storeRent = "";
					
					storeNum = "";
					
					temp = current; // Reset to the top of the node list.

				} // end while to read in

				if (searchNum == false)
				{
					cout << endl << NO_MATCHES << endl;
				}
				else
				{
					cout << endl << DISPLAY_PHONE << setw(24) << NEW_MONTHLY_TITLE << endl;

					// Dashed lines
					cout << setfill('-') << setw(13) << " "; // Creates dashes '-'.
					cout << setfill(' ') << setw(7) << " "
						<< setfill('-') << setw(13) << " "; // Creates dashes '-'.
					cout << setfill(' ') << setw(2) << " " << endl;;

					// Sets decimal place to two spaces.
					cout.setf(ios::fixed);
					
					cout.setf(ios::showpoint);
					
					cout.precision(2);

					temp = current; // Reset to the top of the node list.

					for (int i = 0; i < size; i++) // If we find two listings in the array, delete one.
					{
						for (int j = size - 1; i < j; j--)
						{
							if (arrayPhone[i] == arrayPhone[j])
							{
								arrayPhone[j] = "";
							}
						}
					}

					for (int i = 0; i < size; i++) // Display updated rentals.
					{
						while (temp != NULL)
						{
							if (arrayPhone[i] == temp->phone)
							{
								cout << temp->phone << setw(15)
									<< temp->rent << endl;
							}

							temp = temp->next;

						} // end while

						temp = current;

					}  // end for
				}

				delete[] arrayPhone;
			}
		}
		inFile.close(); // Calls to find functions will re-open the file from the top position to be read in
		
		temp = NULL;
	}
	else
	{
		cout << endl << NO_EXIST_MODS << endl;
	}

}

//*********************************************************************
// FUNCTION: write_data
// DESCRIPTION: Writes data out to a file specified by user.
// INPUT:
// Parameters: current - points to head node, fileName - file name specified by user.
//**********************************************************************
void write_data(apartment *&current, string & fileName)
{
	ofstream outFile;

	outFile.open(fileName.c_str());

	while (current != NULL)
	{
		outFile << current->phone << " " << floor(current->rent * 100) / 100 << " " << current->status << endl; // Uses two digit display.

		current = current->next;
	}

	outFile.close();
}
//*********************************************************************
// FUNCTION: exit_prompt
// DESCRIPTION: Exits program after prompting the user to save data.
// INPUT:
// Parameters: current - points to head node, exit_program - true is returned to exit.
//**********************************************************************
void exit_prompt(apartment *&current, bool & exit_program)
{
	ifstream inFile;
	string save_data;
	string continueOn;
	string fileName;
	bool success = false;

	cout << endl << ASK_TO_SAVE;

	cin >> save_data;

	save_data[0] = toupper(save_data[0]);

	do
	{
		if (save_data == "Y")
		{
			cout << endl << FILE_NAME_INPUT;

			cin >> fileName;

			inFile.open(fileName.c_str());

			if (inFile)
			{
				cout << endl << WARN_OVER << endl;

				cout << endl << GO_ON;

				cin >> continueOn;

				continueOn[0] = toupper(continueOn[0]);

				if (continueOn == "Y")
				{
					write_data(current, fileName); //writeover new data.

					cout << endl << IT_OVERWRITE << endl;

					success = true;
				}
				else if (continueOn == "N")
				{
					success = false;

					inFile.close();
				}
				else
				{
					do
					{
						if (continueOn != "Y" && continueOn != "N")
						{
							cin.clear();
							cin.ignore(10000, '\n');
						}

						cout << endl << DISPLAY_LOAD_INVALID << endl;

						cout << endl << WARN_OVER << endl;

						cout << endl << GO_ON;

						cin >> continueOn;

						continueOn[0] = toupper(continueOn[0]);

					} while (continueOn != "Y" && continueOn != "N");

					if (continueOn == "Y")
					{
						write_data(current, fileName); //writeover new data.

						cout << endl << IT_OVERWRITE << endl;

						success = true;
					}
					else if (continueOn == "N")
					{
						success = false;

						inFile.close();

					}
				}
			}
			else
			{
				ofstream Name(fileName.c_str(), ios::out); //Write new file.

				cout << endl << FILE_1E << fileName << FILE_2E << endl;

				success = true;

			}

		}
		else if (save_data == "N")
		{
			cout << endl << NO_SAVE << endl;
			
			success = true;
		}
		else
		{
			while (save_data != "N" && save_data != "Y")
			{
				if (save_data != "N" && save_data != "Y")
				{
					cin.clear();
					
					cin.ignore(10000, '\n');
				}

				cout << endl << ERROR_INVALID << endl;

				cout << endl << ASK_TO_SAVE;

				cin >> save_data;

				save_data[0] = toupper(save_data[0]);
			}
		}
	} while (success == false);

	cout << endl << BYE << endl;

	exit_program = true;

	inFile.close();
}
//*********************************************************************
// FUNCTION: deletePointers
// DESCRIPTION: Deletes program pointer's from main.
// INPUT:
// Parameters: current - points to head node
//**********************************************************************
void deletePointers(apartment *&current)
{
	apartment *freeNode, *nextNode;  // Create 2 temporary pointers 

	freeNode = current;            // Point freeNode to first node in list 

	while (freeNode != NULL) {       // while not at end of list... 

		nextNode = freeNode->next;   // point nextNode to the node 
		// following freeNode 

		delete freeNode;             // de-allocate the node freeNode 
		// points to 

		freeNode = nextNode;         // point freeNode to next node 
		// in list 
	} // end while 

	// After all nodes have been de-allocated	
	current = NULL;
}
//*********************************************************************
// FUNCTION: isEmpty
// DESCRIPTION: Checks if the node list is empty.
// INPUT:
// Parameters: head - points to head node
//**********************************************************************
bool isEmpty(apartment *&head)
{
	return(head == NULL);
}
//*********************************************************************
// FUNCTION: insertAsFirstElement
// DESCRIPTION: Inserts in to the first node.
// INPUT:
// Parameters: head - pointer to the first node, last - pointer to the last node,
//  phone - holds the phone num, rent - holds the rent, status - holds the status
//**********************************************************************
void insertAsFirstElement(apartment *&head, apartment *&last, string phone, double rent, bool status)
{
	apartment *temp = new (nothrow) apartment;

	if (temp == NULL) 
	{
		cout << endl << MEMORY_PB << endl;
	}
	else
	{
		temp->phone = phone;
		
		temp->rent = rent;
		
		temp->status = status;
		
		temp->next = NULL;
		
		head = temp;
		
		last = temp;
	}
}
//*********************************************************************
// FUNCTION: insert
// DESCRIPTION: Inserts after the first node, calls insertAsFirstElement.
// INPUT:
// Parameters: head - pointer to the first node, last - pointer to the last node,
//  phone - holds the phone num, rent - holds the rent, status - holds the status
// CALLS TO: insertAsFirstElement
//**********************************************************************
void insert(apartment *&head, apartment *&last, string phone, double rent, bool status)
{
	if (isEmpty(head))
	{
		insertAsFirstElement(head, last, phone, rent, status);
	}
	else
	{
		apartment *temp = new (nothrow) apartment;

		if (temp == NULL)
		{
			cout << endl << MEMORY_PB << endl;
		}
		else
		{
			temp->phone = phone;
			
			temp->rent = rent;
			
			temp->status = status;
			
			temp->next = NULL;
			
			last->next = temp;
			
			last = temp;
		}
	}
}
//*********************************************************************
// FUNCTION: showList
// DESCRIPTION: Displays list in correct format.
// INPUT:
// Parameters: current - pointer to the first node
// CALLS TO: isEmpty
//**********************************************************************
void showList(apartment *current)
{
	string showStatus;

	if (isEmpty(current))
	{
		cout << endl << EMPTY_LIST_SR << endl;
	}
	else
	{

		cout << endl << DISPLAY_PHONE << setw(15) << MONTHLY_RENT << setw(9) << STATUS << endl;

		// Dashed lines
		cout << setfill('-') << setw(13) << " "; // Creates dashes '-'.
		cout << setfill(' ') << setw(2) << " "
			<< setfill('-') << setw(13) << " "; // Creates dashes '-'.
		cout << setfill(' ') << setw(2) << " "
			<< setfill('-') << setw(10) << " "; // Creates dashes '-'.
		cout << setfill(' ') << endl; // Resets back to blank space.

		// Sets decimal place to two spaces.
		cout.setf(ios::fixed);
		
		cout.setf(ios::showpoint);
		
		cout.precision(2);

		while (current != NULL)
		{
			if (current->status)
			{
				showStatus = "rented";
			}
			else
			{
				showStatus = "available";
			}

			cout << current->phone << setw(15)
				 << current->rent << setw(12)
				 << showStatus << endl;

			current = current->next;
		}
	}
}
//*********************************************************************
// FUNCTION: add_rental
// DESCRIPTION: Used in adding a rental to the node list.
// INPUT:
// Parameters: head - pointer to the first node, last - pointer to the last node,
//  phone - holds the phone num, rent - holds the rent, status - holds the status
// CALLS TO: validate_phone_number, validate_monthlyRent, validate_status
//**********************************************************************
void add_rental(apartment* &head, apartment* &last, string phone, double rent, bool status)
{
	string prompt_for_another_renter;

	do
	{
		phone = validate_phone_number();  // Call for phone number validation.

		rent = validate_monthlyRent(); // Call for rent validation.

		status = validate_status();  // Call for status validation.

		insert(head, last, phone, rent, status);

		cout << endl << ASK_FOR_MORE;  // Prompt for another entry.

		cin >> prompt_for_another_renter;

		prompt_for_another_renter[0] = toupper(prompt_for_another_renter[0]);

		while (prompt_for_another_renter != "Y" && prompt_for_another_renter != "N")
		{
			if (prompt_for_another_renter != "Y" && prompt_for_another_renter != "N")
			{
				cin.clear();
				cin.ignore(10000, '\n');
			}

			cout << endl << ERROR_INVALID_RENT << endl;

			cout << endl << ASK_FOR_MORE;

			cin >> prompt_for_another_renter;

			prompt_for_another_renter[0] = toupper(prompt_for_another_renter[0]);
		}
		
	} while (prompt_for_another_renter == "Y");
}
//*********************************************************************
// FUNCTION: validate_phone_number
// DESCRIPTION: Validates that the phone number entered by user is valid format.
// OUTPUT:
// Return Val: returns validated_phone_number as a string.
//**********************************************************************
string validate_phone_number()
{
	string line;
	string individual_number_read = "";
	string validated_phone_number;
	bool valid_format = false;

	while (valid_format == false)
	{
		cout << endl << ENTER_PHONE;

		cin >> line;

		// Start error checking.
		if (line.length() != 12)
		{
			cout << endl << ERROR_NUM_LENGTH;
		}
		else
		{
			for (int single_digit = 0; single_digit < 12; single_digit++) // Goes through one digit at a time to error check phone number entered in.
			{
				individual_number_read = (1, line.at(single_digit));

				if (isalpha(individual_number_read[0]))  // Checks that a letter has not been entered, only digits.
				{
					cout << endl << ERROR_NUM_INVALID_1;

					single_digit = 12;

					valid_format = false;
				}
				else if (individual_number_read == "-")
				{
					if (single_digit != 3 && single_digit != 7)  // Checks that dash is in correct place.
					{
						cout << endl << ERROR_NUM_INVALID_2;

						single_digit = 12;

						valid_format = false;
					}
				}
				else  if (single_digit == 11)
				{
					if (isalpha(individual_number_read[0]))  // Checks that a letter has not been entered, only digits.
					{
						cout << endl << ERROR_NUM_INVALID_1;

						single_digit = 12;

						valid_format = false;
					}
					else if (individual_number_read == "-")
					{
						if (single_digit != 3 || single_digit != 7) // Checks that dash is in correct place.
						{
							cout << endl << ERROR_NUM_INVALID_2;

							single_digit = 12;

							valid_format = false;
						}
					}
					else
					{
						valid_format = true;  // Break while loop on last digit if it checks out ok.

						validated_phone_number = line;  // Store in phone number array.
					}
				}
			}
		}
	}

	return validated_phone_number;
}
//*********************************************************************
// FUNCTION: validate_monthlyRent
// DESCRIPTION: Validates monthly rent entered in by user, returns validated amount.
// OUTPUT:
// Return Val: monthly_rent_validated - the validated monthly rent.
//**********************************************************************
double validate_monthlyRent()
{
	double monthly_rent_validated = 0;

	cout << endl << ENTER_RENT;

	cin >> monthly_rent_validated;

	// Checking for correct format including decimal/non zero answer.
	while (cin.fail() || (cin.peek() != '\r' && cin.peek() != '\n') || (monthly_rent_validated == 0))
	{
		cout << endl << ERROR_NOT_VALID << endl;

		cout << endl << RENT_REENTER;

		cin.clear();

		while (cin.get() != '\n'); // or cin.ignore(1000, '\n');

		cin >> monthly_rent_validated;
	}

	return monthly_rent_validated;
}
//*********************************************************************
// FUNCTION: validate_status
// DESCRIPTION: Validates the status entered by the user is in correct format 1 or 0.
// OUTPUT:
// Return Val: validated_status - validated 1 or 0 returned.
//**********************************************************************
bool validate_status()
{
	string Y_or_N;
	bool validated_status = false;

	do
	{
		cout << endl << APT_RENTED;

		cin >> Y_or_N;

		Y_or_N[0] = toupper(Y_or_N[0]);

		if (Y_or_N != "Y" && Y_or_N != "N")
		{
			cout << endl << ERROR_INVALID_STATUS << endl;

			cin.clear();

			cin.ignore(10000, '\n');
		}

	} while (Y_or_N != "Y" && Y_or_N != "N");

	if (Y_or_N == "Y")
	{
		validated_status = 1;
	}
	else
	{
		validated_status = 0;
	}

	return validated_status;
}

//*********************************************************************
// FUNCTION: delete_stored_data
// DESCRIPTION: Displays list of phone numbers, allows user to delete a number by entering it in.
// INPUT:
// Parameters: current - pointer to the first node, last - pointer to the last node,
//  phone - holds the phone num
// OUTPUT:
// CALLS TO: isEmpty, validate_phone_number, deleteNode
//**********************************************************************
void delete_stored_data(apartment* &current, apartment* &last, string phone)
{
	if (isEmpty(current))
	{
		cout << endl << EMPTY_LIST_SR << endl;
	}
	else
	{
		int count = 1;
		
		bool success = false;

		apartment *temp = NULL;

		temp = current;

		cout << endl << ENTER_NUMBER << endl << endl;

		// find count for the next for loop to display correctly.
		while (temp != NULL)
		{
			if (count % 6 == 0)
			{
				cout << endl;
			}
			else
			{
				cout << setw(15) << temp->phone << setw(15);

				temp = temp->next;
			}
			count++;
		}

		phone = validate_phone_number(); // Ask for a validated number to find/delete.

		deleteNode(current, phone, success);

		if (success)
		{
			cout << endl << NUM_FOUND << endl;

			if (isEmpty(current)) // Checking on last phone number deletion.  
			{
				cout << endl << NUM_DEL << endl;
			}
		}
		else
		{
			cout << endl << phone << NUM_DEL_2 << endl;
		}

		if (!(isEmpty(current)) && success == true)
		{
			deleteNode(current, phone, success); // Calling again to check for successful deletion.

			if (!(success))
			{
				cout << endl << NUM_DEL << endl;
			}
			else
			{
				cout << endl << NUM_DEL_3 << endl;
			}
		}
	}
}

//*********************************************************************
// FUNCTION: deleteNode
// DESCRIPTION: Displays list of phone numbers, allows user to delete a number by entering it in.
// INPUT:
// Parameters: head - pointer to the first node, last - pointer to the last node,
//  phone - holds the phone num, success - used in determining if deletion was a success
//**********************************************************************
void deleteNode(apartment* &head, string phone, bool& success)
{
	apartment *here,                           // Node being checked
		*prev;                           // Node prior to node being checked

	success = false;                         // Name not found yet

	if (head->phone == phone) {        // If delName found in first node,
		here = head;
		head = head->next;		      //  Delete top item
		delete here;
		success = true;
	}
	else {                                   // Not top item, so search...

		prev = head;                      // Initialize prev and here to 
		here = head->next;                // first 2 nodes in list

		// Look for delName (while not end of list and name doesn't match)
		while ((here != NULL) && (here->phone != phone)) {
			prev = here;               // move prev down one
			here = here->next;         // move here down one
		}

		if (here != NULL) {               // If found, delete item from list
			prev->next = here->next;
			delete here;
			success = true;
		}

	}	// End else (not top Item)

	return;
}
