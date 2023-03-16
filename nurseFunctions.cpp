#include <iostream>
#include <string>
#include "dataStructures.h"
#include "supportingFunctionsHeaders.h"
//for the ctime function
#pragma warning (disable : 4996)
using namespace std;


//function to add new patient into the end of waiting list.
void addPatientToWaitingList() {
	//initialize the variable here
	string firstName;
	string lastName;
	int age;
	string gender;
	string phone;
	string address;
	string sicknessDesc = "NULL";
	string visitDate;
	string visitTime;
	string disabilityOption;
	string doctorName = "NULL";
	string medicineInfo = "NULL";
	
	//id has bug P001P001P001
	string flag = "Yes";
	while (flag == "Yes") {
		string patientID;
		//auto increase the totalpatientcount global variable by 1 whenever user click this function
		totalPatientCount++;
		waitingListSize++;

		//auto increment id and patient id will become P00(totalPatientcount)
		if (totalPatientCount >= 1 && totalPatientCount < 10) {
			patientID.append("P");
			patientID.append("00");
			patientID.append(to_string(totalPatientCount));
		}
		//when the total patient count is more than 10, it will become P0(total patient count)
		else if (totalPatientCount >= 10 && totalPatientCount < 100) {
			patientID.append("P");
			patientID.append("0");
			patientID.append(to_string(totalPatientCount));
		}

		//ask user to input the patient basic detail
		cout << "\nPlease enter patient First Name: ";
		getline(cin, firstName);
		cout << "\nPlease enter patient last Name: ";
		getline(cin, lastName);
		cout << "\nPlease enter patient age: ";
		cin >> age;
		cin.ignore();
		cout << "\nPlease enter patient Gender (Male/Female):  ";
		getline(cin, gender);
		cout << "Please enter patient phone: ";
		getline(cin, phone);
		cout << "Please enter patient address: ";
		getline(cin, address);

		//get the current time by using ctime function
		time_t now = time(0);
		tm* ltm = localtime(&now);
		visitDate = to_string(ltm->tm_mday) + " / " + to_string(1 + ltm->tm_mon) + " / " + to_string(1900 + ltm->tm_year);
		visitTime = to_string(ltm->tm_hour) + ":" + to_string(ltm->tm_min);

		cout << "\nPlease enter patient doctor name: ";
		getline(cin, doctorName);
		cout << "\nPlease enter patient disability Option (Yes/No): ";
		getline(cin, disabilityOption);

		// assign new node to patient 
		newNode = new patient;
		//assign all the patient detaiil into linked list
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

		//when waiting head is null, mean the list is empty and can insert the new node into the list.
		if (waitingHead == NULL) {
			waitingHead = waitingTail = newNode;
			cout << "\nNew patient added" << endl;
		}
		else {
			newNode->prevAddress = waitingTail;
			waitingTail->nextAddress = newNode;
			waitingTail = newNode;
			cout << "\nNew patient added" << endl;
		}

		cout << "\nWould you like to add another patient? (Yes/No): ";
		getline(cin, flag);
		cout << endl;
	}
}


// call the patient to be treat and move it into visit history list.
void callPatient() {
	//if  the list is empty, end the function.
	if (waitingHead == NULL) {
		return;
	}
	//assign the current pointer to the head of the list 
	current = waitingHead;
	waitingHead = waitingHead->nextAddress;
	if (waitingHead == NULL) {
		waitingTail = NULL;
	}
	else {
		waitingHead->prevAddress = NULL;
	}
	if (visitHead == NULL) {
		visitHead = visitTail = current;
		current->prevAddress = NULL;
		current->nextAddress = NULL;
		cout << "\nPatient has been remove from waiting list and insert into visit list" << endl;
	}
	else {
		current->nextAddress = NULL;
		visitTail->nextAddress = current;
		current->prevAddress = visitTail;
		visitTail = current;
		cout << "\nPatient has been remove from waiting list and insert into visit list" << endl;
	}
	waitingListSize--;
}


// Search Menu function (add parameters to search fucntions)
void searchPatientBasedOnPatientIDOrFirstName() {
	int option;
	string searchKey;
	do {
		// Search menu options
		cout << "\nPlease select one of the following (Enter the number): ";
		cout << "\n1- Search Patient by patient ID ";
		cout << "\n2- Search Patient by first name ";
		cout << "\n3- Exit ";
		cout << "\nEnter your option: ";
		cin >> option;
		cin.ignore();
		switch (option) {
		case 1:
			// Search by ID:
			cout << "\nEnter the Patient ID: ";
			getline(cin, searchKey);
			current = searchPatientByPatientID(searchKey, waitingHead);
			if (current == NULL) {
				cout << "\nNo match was found!";
			}
			else {
				displayPatientDetails(current);
			}
			break;
		case 2:
			//Search by first name
			cout << "\nEnter the Patient first name: ";
			getline(cin, searchKey);
			searchMultiplePatients("firstName", searchKey, waitingHead);
			break;
		case 3:
			break;
		default:
			cout << "\nInvalid Input, Try again";
		}
	} while (option != 3);
}


// Function to sort And Display Waiting List Based On Visit Time
void sortAndDisplayWaitingListBasedOnVisitTimeInAscending() {
	createTempList(waitingHead);
	// check if the list is empty
	if (tempHead == NULL) {
		cout << "\nThe waiting list is empty. ";
	}
	else {
		// run sorting functions in succession:
		sortListBasedOnTimeInAscending();
		displayTempListPageByPage();
		deleteTempList();
	}
}

// Function to show the waiting list
void displayWaitingList() {
	current = waitingHead;
	// checking if the list is empty
	cout << "\n\t\t\t~~~~~ PATIENT WAITING LIST ~~~~~\n";
	while (current != NULL) {
		displayPatientDetails(current);
		current = current->nextAddress;
	}
	cout << "\nThis is the end of the waiting list!";
	cout << "\n\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
}


//function to move disable patient to the front of the list
void changePatientOrderOnWaitingList() {
	//assign a new temp pointer to patient
	patient* temp;
	//return when the list is empty
	if (waitingHead == NULL || waitingHead->nextAddress == NULL) {
		return;
	}
	//assign the current pointer to the end of the linked list
	current = waitingTail;
	int i = waitingListSize;
	temp = current->prevAddress;

	while (i > 0) {
		if (current->disabilityOption == "Yes" && current->prevAddress != NULL) {
			if (current->nextAddress == NULL) {
				current->prevAddress->nextAddress = NULL;
				waitingTail = current->prevAddress;
			}
			else {
				current->prevAddress->nextAddress = current->nextAddress;
				current->nextAddress->prevAddress = current->prevAddress;
			}
			current->nextAddress = waitingHead;
			waitingHead->prevAddress = current;
			current->prevAddress = NULL;
			waitingHead = current;
		}
		current = temp;
		if (temp != NULL) {
			temp = temp->prevAddress;
		}
		i--;
	}
	displayWaitingList();
}