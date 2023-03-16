#include <iostream>
#include "dataStructures.h"
#include "supportingFunctionsHeaders.h"
#include "nurseFunctionsHeaders.h"
#include "doctorFunctionsHeaders.h"
using namespace std;

// Initialization of global pointers
patient *newNode, *waitingHead, *waitingTail, *current, *visitHead, *visitTail, *tempHead, *tempTail;
nurse *nurse1;
doctor *doctor1;
int totalPatientCount;
int waitingListSize;


// Function to create predefined records in waiting list and visit history list
void createPredefinedRecords() {
	// Initialize the global pointers to NULL
	nurse1 = NULL;
	doctor1 = NULL;
	newNode = waitingHead = waitingTail = current = visitHead = visitTail = tempHead = tempTail = NULL;

	// Define nurse1
	nurse1 = new nurse;
	nurse1->username = "nurse";
	nurse1->password = "nurse123";

	// Define doctor1
	doctor1 = new doctor;
	doctor1->username = "doctor";
	doctor1->password = "doctor123";

	// Creating the records
	createAndInsertNewNodeToTheEnd("waitingList", "P006", "Izaan", "Cooley", 23, "Female", "013-4023216", "6, Jalan Gembira, Taman Roti, 56000 KL.", "Diabetes mellitus", "10 / 7 / 2021", "09:00", "Yes", "Dr.Bob", "Metformin");
	createAndInsertNewNodeToTheEnd("waitingList", "P007", "Milo", "Maddox", 3, "Male", "013-9131539", "36, Jalan Sayang, Taman Canai, 56000 KL.", "Ebola", "24 / 8 / 2021", "09:40", "No", "Dr.Bob", "Inmazeb");
	createAndInsertNewNodeToTheEnd("waitingList", "P008", "Ariana", "Gentry", 49, "Female", "013-2572168", "21, Jalan Cemerlang, Taman Roti, 56000 KL.", "Diabetes mellitus", "31 / 10 / 2021", "11:00", "Yes", "Dr.Bob", "Metformin");
	createAndInsertNewNodeToTheEnd("waitingList", "P009", "Lindsey", "Draper", 68, "Male", "018-2241113", "48, Jalan Kaya, Taman Canai, 48200 Selangor.", "Ebola", "10 / 11 / 2021", "14:00", "Yes", "Dr.Bob", "Inmazeb");
	createAndInsertNewNodeToTheEnd("waitingList", "P010", "Jayden", "Gray", 39, "Female", "013-2145388", "39, Jalan Mee, Taman Canai, 48200 Selangor.", "Diabetes mellitus", "24 / 12 / 2021", "17:20", "No", "Dr.Bob", "Metformin");
	createAndInsertNewNodeToTheEnd("visitHistoryList", "P001", "Romeo", "Weston", 30, "Male", "013-9075287", "89, Jalan Gembira, Taman Roti, 56000 KL.", "Whipworm infection", "24 / 1 / 2021", "09:20", "No", "Dr.Bob", "Albendazole");
	createAndInsertNewNodeToTheEnd("visitHistoryList", "P002", "Lauren", "Allan", 95, "Female", "017-2353400", "32, Jalan Pandai, Taman Cemerlang, 56000 KL.", "Arthritis", "10 / 3 / 2021", "10:20", "No", "Dr.Bob", "NSAIDs");
	createAndInsertNewNodeToTheEnd("visitHistoryList", "P003", "Nela", "English", 72, "Male", "016-7623839", "19, Jalan Sayur, Taman Bersih, 56123 KL.", "Hookworm infection", "26 / 4 / 2021", "14:20", "No", "Dr.Bob", "Mebendazole");
	createAndInsertNewNodeToTheEnd("visitHistoryList", "P004", "Cheyanne", "Harrington", 27, "Female", "018-6236772", "6, Jalan Roti, Taman Telur, 56000 KL.", "Hookworm infection", "21 / 5 / 2021", "15:00", "Yes", "Dr.Bob", "Mebendazole");
	createAndInsertNewNodeToTheEnd("visitHistoryList", "P005", "Harleen", "Rowe", 14, "Male", "012-7880937", "1, Jalan Ikan, Taman Nelayan, 56000 KL.", "Arthritis", "3 / 6 / 2021", "17:00", "Yes", "Dr.Bob", "NSAIDs");

	// Set the patient count to 10
	totalPatientCount = 10;

	// Set the waiting list size to 5
	waitingListSize = 5;
}


// Function to determine the login type
int login() {
	string username, password;

	// Ask user to enter the username
	cout << "\nEnter username: ";
	getline(cin, username);

	// Ask user to enter the password
	cout << "\nEnter password: ";
	getline(cin, password);

	// Checking the login type
	if (username == nurse1->username && password == nurse1->password) {
		// The login is a nurse login
		return 1;
	}
	else if (username == doctor1->username && password == doctor1->password) {
		// The login is a doctor login
		return 2;
	}
	else {
		// The credentials entered was neither a nurse nor a doctor login
		return -1;
	}
}


// Function to display the nurse menu and execute corresponding nurse functions
void nurseMenu() {
	int choice;
	string isLogout;

	// Displaying the nurse menu
	cout << "\nWelcome, nurse!";
	while (true) {
		cout << "\nList of operations available for nurse:\n1. Add a new patient to the waiting list.\n2. Change patient order based on disability option automatically.\n3. View all patients on the original waiting list.\n4. Calling the patient to be treaed.\n5. Search patient from waiting list based on Patient ID or First Name.\n6. Sort the waiting list by patient current visit time, display in ascending order.\n7. Logout\nPlease enter your choice: ";
		cin >> choice;
		cin.ignore();
		switch (choice) {
			case 1:
				// Add a patient to waiting list
				addPatientToWaitingList();
				break;
			case 2:
				// Change patient order automatically based on priority on waiting list
				changePatientOrderOnWaitingList();
				break;
			case 3:
				// Display the waiting list
				displayWaitingList();
				break;
			case 4:
				// Call the patient
				callPatient();
				break;
			case 5:
				// Search patients from the waiting list based on patient ID or first name
				searchPatientBasedOnPatientIDOrFirstName();
				break;
			case 6:
				// Sort and display the waiting list based on visit time in ascending order
				sortAndDisplayWaitingListBasedOnVisitTimeInAscending();
				break;
			case 7:
				// Logout
				while (true) {
					// Asking the user if they really want to log out
					cout << "\nAre you sure you want to log out? (Yes/No): ";
					getline(cin, isLogout);
					if (isLogout == "Yes") {
						// User wants to log out
						return;
					}
					else if (isLogout == "No") {
						// User does not want to log out
						break;
					}
					else {
						// User entered neither "Yes" nor "No"
						cout << "\nInvalid input!";
					}
				}
				break;
			default:
				// User entered invalid choice
				cout << "\nInvalid choice entered!";
		}
	}
}


// Function to display the doctor menu and execute corresponding doctor functions
void doctorMenu() {
	int choice;
	string isLogout;

	// Displaying the doctor menu
	cout << "\nWelcome, doctor!";
	while (true) {
		cout << "\nList of operations available for doctor:\n1. View all patients on the original waiting list.\n2. Search specific patient from the patient's visit history and modify patient records.\n3. Sort and display all records from the patient's visit history list based on patient ID in descending order.\n4. Search patients from the patient's visit history list based on sickness description or first name.\n5. Logout\nPlease enter your choice: ";
		cin >> choice;
		cin.ignore();
		switch (choice) {
			case 1:
				// Display the waiting list
				displayWaitingList();
				break;
			case 2:
				// Search a patient from the visit history list and modify
				searchPatientAndModify();
				break;
			case 3:
				// Sort and display the visit history list based on patient ID in descending order
				sortAndDisplayVisitHistoryListBasedOnPatientIDInDescending();
				break;
			case 4:
				// Search patients from the visit history list based on sickness description or first name
				searchPatientsBasedOnSicknessOrFirstName();
				break;
			case 5:
				// Logout
				while (true) {
					// Asking the user if they really want to log out
					cout << "\nAre you sure you want to log out? (Yes/No): ";
					getline(cin, isLogout);
					if (isLogout == "Yes") {
						// User wants to log out
						return;
					}
					else if (isLogout == "No") {
						// User does not want to log out
						break;
					}
					else {
						// User entered neither "Yes" nor "No"
						cout << "\nInvalid input!";
					}
				}
				break;
			default:
				// User entered invalid choice
				cout << "\nInvalid choice entered!";
		}
	}
}


// Main function
int main() {
	// Declaration of variables
	int choice, result;
	string isExit;

	// Creating predefined records
	createPredefinedRecords();

	cout << "\nWelcome to Klinik Sulaiman's Patient Queue Based Management System!";
	while (true) {
		// Printing and asking the user to enter the choice of operation
		cout << "\nThese are the operations that you can perform: \n1. Login\n2. Exit System\nPlease select one of the following by entering the number associated to each of them (eg. 1): ";
		cin >> choice;
		cin.ignore();

		if (choice == 1) {
			// User wants to login
			result = login();
			
			// Check if user wants to login as nurse or doctor
			if (result == 1) {
				// User login as nurse
				nurseMenu();
			}
			else if (result == 2) {
				// User login as doctor
				doctorMenu();
			}
			else {
				// Invalid credentials entered
				cout << "\nInvalid username or password entered!";
			}
		}

		else if (choice == 2) {
			// User wants to exit the system
			while (true) {
				cout << "\nAre you sure you want to exit the system (Yes/No): ";
				getline(cin, isExit);
				if (isExit == "Yes") {
					// User really wants to exit the system
					cout << "\nThanks for using the system! See you later!";
					return 0;
				}
				else if (isExit == "No") {
					// User does not want to exit the system
					break;
				}
				else {
					// User entered invalid input
					cout << "\nInvalid input!";
				}
			}
		}
		else {
			// User entered invalid choice
			cout << "\nInvalid choice entered!";
		}
	}
	return 0;
}