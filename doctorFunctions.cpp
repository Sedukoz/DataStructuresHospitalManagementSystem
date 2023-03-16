#include <iostream>
#include "dataStructures.h"
#include "supportingFunctionsHeaders.h"
using namespace std;


// Function to search for a patient from the visit history list and modify
void searchPatientAndModify() {
	// Variables declaration
	string patientID, newDetail, isContinue;
	patient *result;
	int choice;

	while (true) {
		// Asking and getting the patient ID from the user
		cout << "\nPlease enter the patient ID of the patient whose contents need to be modified: ";
		getline(cin, patientID);

		// Searching the patient from the visit history list using the patient ID entered earlier
		result = searchPatientByPatientID(patientID, visitHead);
		// Validating the result
		if (result == NULL) {
			// There is no match found
			continue;
		}
		else {
			// There is a match found
			break;
		}
	}
	// Displaying the details of the matched patient
	displayPatientDetails(result);
	while (true) {
		int flag = 0;
		// Asking and getting the option from the user
		cout << "\nBelow are the options that you can modify:\n1. First Name\n2. Last Name\n3. Phone Number\n4. Address\n5. Sickness Description\n6. Doctor Name\n7. Medicine Information\nPlease select one of them by specifying the number associated to each of them: ";
		cin >> choice;
		cin.ignore();

		// Checking the option entered
		switch (choice) {
			case 1:
				// User wishes to change the first name
				cout << "\nEnter the new first name of the patient: ";
				getline(cin, newDetail);
				// Updating the first name of the patient
				result->firstName = newDetail;
				flag = 1;
				break;
			case 2:
				// User wishes to change the last name
				cout << "\nEnter the new last name of the patient: ";
				getline(cin, newDetail);
				// Updating the last name of the patient
				result->lastName = newDetail;
				flag = 1;
				break;
			case 3:
				// User wishes to change the phone number
				cout << "\nEnter the new phone number of the patient: ";
				getline(cin, newDetail);
				// Updating the phone number of the patient
				result->phone = newDetail;
				flag = 1;
				break;
			case 4:
				// User wishes to change the address
				cout << "\nEnter the new address of the patient: ";
				getline(cin, newDetail);
				// Updating the address of the patient
				result->address = newDetail;
				flag = 1;
				break;
			case 5:
				// User wishes to change the sickness description
				cout << "\nEnter the new sickness description of the patient: ";
				getline(cin, newDetail);
				// Updating the sickness description of the patient
				result->sicknessDesc = newDetail;
				flag = 1;
				break;
			case 6:
				// User wishes to change the doctor name
				cout << "\nEnter the new doctor name of the patient: ";
				getline(cin, newDetail);
				// Updating the doctor name of the patient
				result->doctorName = newDetail;
				flag = 1;
				break;
			case 7:
				// User wishes to change the medicine information
				cout << "\nEnter the new medicine information of the patient: ";
				getline(cin, newDetail);
				// Updating the medicine information of the patient
				result->medicineInfo = newDetail;
				flag = 1;
				break;
			default:
				// User entered an invalid choice
				cout << "\nInvalid choice entered!";
		}
		if (flag == 0) {
			// User entered an invalid choice
			continue;
		}
		// Displaying the details of the matched patient
		displayPatientDetails(result);
		while (true) {
			// Asking the user if they want to continue updating more details of the matched patient
			cout << "\nDo you wish to continue in updating more details of the patient? (Yes/No): ";
			getline(cin, isContinue);
			if (isContinue == "Yes") {
				// User wishes to continue updating
				break;
			}
			else if (isContinue == "No") {
				// User wishes not to continue
				return;
			}
			else {
				// User entered invalid choice
				cout << "\nInvalid choice entered!";
			}
		}
	}
}


// Function to sort and display the vist history list based on patient ID in descending order
void sortAndDisplayVisitHistoryListBasedOnPatientIDInDescending() {
	// Duplicating the visit history list as a temp list
	createTempList(visitHead);
	// Checking if the temp list is empty or not
	if (tempHead == NULL) {
		// The temp list is empty, which also means that the visit history list is empty
		cout << "\nThe visit history list is empty! Cannot be displayed!";
	}
	else {
		// The temp list is not empty
		// Sorting the temp list based on patient ID in descending order using the insertion sort algorithm
		sortListBasedOnPatientIDInDescending();
		// Displaying the temp list in a page by page manner
		displayTempListPageByPage();
		// Deleting the temp list
		deleteTempList();
	}
}


// Function to search for patients in the visit history list based on sickness description or first name
void searchPatientsBasedOnSicknessOrFirstName() {
	// Variables declaration
	int choice;
	string searchKey;

	while (true) {
		// Asking and getting the choice of operation from the user
		cout << "\nYou can search patients based on either one of the following:\n1. Sickness Description\n2. First Name\nPlease select one of the following by entering the number associated to each of them: ";
		cin >> choice;
		cin.ignore();
		// Asking and getting the searching keyword from the user
		cout << "\nPlease enter the searching keyword: ";
		getline(cin, searchKey);
		// Checking if the choice was to search by sickness description or by first name
		if (choice == 1) {
			// User wants to search by sickness description
			searchMultiplePatients("sicknessDesc", searchKey, visitHead);
			break;
		}
		else if (choice == 2) {
			// User wants to search by first name
			searchMultiplePatients("firstName", searchKey, visitHead);
			break;
		}
		else {
			// User entered an invalid choice
			cout << "\nInvalid choice entered!";
		}
	}
}