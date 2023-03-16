#include <iostream>
#include <string>
#include "dataStructures.h"
using namespace std;


// Function to display a patients details
void displayPatientDetails(patient* current) {
	// print the patient details
	cout << "\nPatient ID:  " << current->patientID;
	cout << "\nFirst Name:  " << current->firstName;
	cout << "\nLast Name:  " << current->lastName;
	cout << "\nAge:  " << current->age;
	cout << "\nGender:  " << current->gender;
	cout << "\nPhone:  " << current->phone;
	cout << "\nAddress:  " << current->address;
	cout << "\nSickness Description:  " << current->sicknessDesc;
	cout << "\nCurrent Visit Date:  " << current->visitDate;
	cout << "\nCurrent Visit Time:  " << current->visitTime;
	cout << "\nDisability Option:  " << current->disabilityOption;
	cout << "\nDoctor Name:  " << current->doctorName;
	cout << "\nMedicine Information:  " << current->medicineInfo;
	cout << "\n";
}


// A function to search based on the ID
patient* searchPatientByPatientID(string searchKey, patient* head) {
	current = head;
	while (current != NULL) {
		if (searchKey == current->patientID) {
			return current;
		}
		else {
			current = current->nextAddress;
		}
	}
	return NULL;
}


// Function to create and insert a new node to the end of any list
void createAndInsertNewNodeToTheEnd(string listName, string patientID, string firstName, string lastName, int age, string gender, string phone, string address, string sicknessDesc, string visitDate, string visitTime, string disabilityOption, string doctorName, string medicineInfo) {
	// Creating a new node and populate its content
	newNode = new patient;
	newNode->patientID = patientID;
	newNode->firstName = firstName;
	newNode->lastName = lastName;
	newNode->age = age;
	newNode->gender = gender;
	newNode->phone = phone;
	newNode->address = address;
	newNode->sicknessDesc = sicknessDesc;
	newNode->visitDate = visitDate;
	newNode->visitTime = visitTime;
	newNode->disabilityOption = disabilityOption;
	newNode->doctorName = doctorName;
	newNode->medicineInfo = medicineInfo;
	newNode->prevAddress = NULL;
	newNode->nextAddress = NULL;
	
	// Checking which list should the new node be added to
	if (listName == "waitingList") {
		// The list is waitingList
		if (waitingHead == NULL) {
			// There is nothing in the waiting list
			waitingHead = waitingTail = newNode;
		}
		else {
			// There are patients in the waiting list
			newNode->prevAddress = waitingTail;
			waitingTail->nextAddress = newNode;
			waitingTail = newNode;
		}
	}
	else if (listName == "visitHistoryList") {
		// The list is visitHistoryList
		if (visitHead == NULL) {
			// There is nothing in the visit history list
			visitHead = visitTail = newNode;
		}
		else {
			// There are patients in the visit history list
			newNode->prevAddress = visitTail;
			visitTail->nextAddress = newNode;
			visitTail = newNode;
		}
	}
}


// Function to insert a new patient to the end of temp list
void insertPatientToTheEndOfTempList() {
	// Checking if temp list is empty
	if (tempHead == NULL) {
		// Temp list is empty
		tempHead = tempTail = newNode;
	}
	else {
		// Temp list is not empty
		newNode->prevAddress = tempTail;
		tempTail->nextAddress = newNode;
		tempTail = newNode;
	}
}


// Function to duplicate the waiting list or visit history list as a temp list
void createTempList(patient *head) {
	// Making current to point to the first patient of the waiting list or visit history list
	current = head;

	// Checking if there are still patients in the waiting list or visit history list
	while (current != NULL) {
		// There are still patients in the waiting list or visit history list
		// Making a deep copy of the current patient in the waiting list or visit history list
		newNode = new patient;
		newNode->patientID = current->patientID;
		newNode->firstName = current->firstName;
		newNode->lastName = current->lastName;
		newNode->age = current->age;
		newNode->gender = current->gender;
		newNode->phone = current->phone;
		newNode->address = current->address;
		newNode->sicknessDesc = current->sicknessDesc;
		newNode->visitDate = current->visitDate;
		newNode->visitTime = current->visitTime;
		newNode->disabilityOption = current->disabilityOption;
		newNode->doctorName = current->doctorName;
		newNode->medicineInfo = current->medicineInfo;
		newNode->nextAddress = NULL;
		newNode->prevAddress = NULL;
		// Inserting the duplicated patient to the end of temp list
		insertPatientToTheEndOfTempList();
		// Point to the next patient in the waiting list or visit history list
		current = current->nextAddress;
	}
}


// Function to sort the temp list based on patient ID in descending order using the insertion sort algorithm
void sortListBasedOnPatientIDInDescending() {
	// Checking if there is nothing in the temp list or if there is only 1 patient in the temp list
	if (tempHead == NULL || tempHead->nextAddress == NULL) {
		// Return back because there is nothing or there is only 1 patient in the temp list
		return;
	}

	// target is pointing the second patient of the temp list
	patient* target = tempHead->nextAddress;
	// current is pointing the first patient of the temp list
	current = tempHead;
	// nextTarget is pointing the third patient of the temp list
	patient* nextTarget = target->nextAddress;

	// Continue checking if there is next patient in the temp list
	while (target != NULL) {
		while (target->patientID > current->patientID) {
			if (current->prevAddress != NULL && target->patientID > current->prevAddress->patientID) {
				// There is a patient before current and target's patient ID is larger than of the patient before current
				current = current->prevAddress;
			}
			else {
				// There is no patient before current or the target's patient ID is smaller than of the patient before current
				break;
			}
		}
		if (target->patientID > current->patientID) {
			if (target->nextAddress == NULL) {
				// Target is the last patient in the temp list
				target->prevAddress->nextAddress = NULL;
				tempTail = target->prevAddress;
			}
			else {
				// Target is not the last patient in the temp list
				target->prevAddress->nextAddress = target->nextAddress;
				target->nextAddress->prevAddress = target->prevAddress;
			}
			if (current->prevAddress == NULL) {
				// Current is the first patient in the temp list
				target->nextAddress = current;
				current->prevAddress = target;
				target->prevAddress = NULL;
				tempHead = target;
			}
			else {
				// Current is not the first patient in the temp list
				current->prevAddress->nextAddress = target;
				target->nextAddress = current;
				target->prevAddress = current->prevAddress;
				current->prevAddress = target;
			}
		}
		// Moving on to the next patient of the temp list
		target = nextTarget;
		if (nextTarget != NULL) {
			// There is still a patient after target
			nextTarget = nextTarget->nextAddress;
			current = target->prevAddress;
		}
	}
}


// Function to move the current pointer to point to the previous patient
void moveBackward() {
	// Checking if there is a patient before current
	if (current->prevAddress != NULL) {
		// There is a patient before current
		// Making current to point to the previous patient
		current = current->prevAddress;
	}
	else {
		// The current is the first patient already
		cout << "\nThis is the end of the list!";
		system("PAUSE");
	}
}


// Function to move the current pointer to point to the next patient
void moveForward() {
	// Checking if there is a patient after current
	if (current->nextAddress != NULL) {
		// There is a patient after current
		// Making current to point to the next patient
		current = current->nextAddress;
	}
	else {
		// The current is the last patient already
		cout << "\nThis is the end of the list!";
		system("PAUSE");
	}
}


// Function to display the temp list in a page by page manner
void displayTempListPageByPage() {
	// The decision of the user
	int decision = 0;
	// Making current to point to the first patient of the temp list
	current = tempHead;

	// Continue checking if decision is not to exit
	while (decision != 3) {
		// Clear the screen
		system("CLS");
		// Displaying the details of the current patient
		displayPatientDetails(current);
		// Asking and getting the decision from the user
		cout << "\n\n1. Previous Page\t2. Next Page\t3. Exit\nPlease enter one of the following: ";
		cin >> decision;
		cin.ignore();
		// Checking if the decision was to move to the next page or previous page
		if (decision == 1) {
			// Moving to the previous page
			moveBackward();
		}
		else if (decision == 2) {
			// Moving to the next page
			moveForward();
		}
	}
}


// Function to delete all the patients in the temp list
void deleteTempList() {
	// Continue checking if there are still patients in the temp list
	while (tempHead != NULL) {
		// There are still patients in the temp list
		// Removing the first patient in the temp list
		current = tempHead;
		tempHead = tempHead->nextAddress;
		delete current;
	}
	// The temp list is already empty
	tempTail = NULL;
}


// Function to search for multiple patients in the waiting list or visit history list based on the 
// searching keyword entered by the user. If there is a match, the details of the patient will get
// printed out
void searchMultiplePatients(string searchBy, string searchKey, patient *head) {
	// Make current to point to the first patient in the waiting list or visit history list
	current = head;
	// count to keep track of the number of searches found
	int count = 0;

	cout << "\nThe patients' details that contain the " << searchKey << " in " << searchBy << " are as below : \n";
	// Continue checking if current is pointing to a patient
	while (current != NULL) {
		// current is pointing to a patient
		// Checking if the user wants to search by first name or sickness description
		if (searchBy == "firstName") {
			// User wants to search by first name
			// Checking if the search key is found in the first name of the current patient
			if (current->firstName.find(searchKey) != string::npos) {
				// Search key found
				// Displaying the details of the patient
				displayPatientDetails(current);
				count++;
			}
		}
		else if (searchBy == "sicknessDesc") {
			// User wants to search by sickness description
			// Checking if the search key is found in the sickness description of the current patient
			if (current->sicknessDesc.find(searchKey) != string::npos) {
				// Search key found
				// Displaying the details of the patient
				displayPatientDetails(current);
				count++;
			}
		}
		// Move current to point to the next patient
		current = current->nextAddress;
	}
	// Checking if there is no match found
	if (count == 0) {
		// There is no match found
		cout << "\nNo searches were found!";
	}
}


// Function to sort a list based on Time in Ascending order
void sortListBasedOnTimeInAscending() {
	// Checking if there is nothing in the temp list or if there is only 1 patient in the temp list
	if (tempHead == NULL || tempHead->nextAddress == NULL) {
		// Return back because there is nothing or there is only 1 patient in the temp list
		return;
	}
	// target is pointing the second patient of the temp list
	patient* target = tempHead->nextAddress;
	// current is pointing the first patient of the temp list
	current = tempHead;
	// nextTarget is pointing the third patient of the temp list
	patient* nextTarget = target->nextAddress;

	// Continue checking if there is next patient in the temp list
	while (target != NULL) {
		while (target->visitTime < current->visitTime) {
			if (current->prevAddress != NULL && target->visitTime < current->prevAddress->visitTime) {
				// There is a patient before current and target's visit time is smaller than of the patient before current
				current = current->prevAddress;
			}
			else {
				// There is no patient before current or the target's visit time is larger than of the patient before current
				break;
			}
		}
		if (target->visitTime < current->visitTime) {
			if (target->nextAddress == NULL) {
				// Target is the last patient in the temp list
				target->prevAddress->nextAddress = NULL;
				tempTail = target->prevAddress;
			}
			else {
				// Target is not the last patient in the temp list
				target->prevAddress->nextAddress = target->nextAddress;
				target->nextAddress->prevAddress = target->prevAddress;
			}
			if (current->prevAddress == NULL) {
				// Current is the first patient in the temp list
				target->nextAddress = current;
				current->prevAddress = target;
				target->prevAddress = NULL;
				tempHead = target;
			}
			else {
				// Current is not the first patient in the temp list
				current->prevAddress->nextAddress = target;
				target->nextAddress = current;
				target->prevAddress = current->prevAddress;
				current->prevAddress = target;
			}
		}
		// Moving on to the next patient of the temp list
		target = nextTarget;
		if (nextTarget != NULL) {
			// There is still a patient after target
			nextTarget = nextTarget->nextAddress;
			current = target->prevAddress;
		}
	}
}