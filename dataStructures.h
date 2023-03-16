#pragma once
#include <string>
using namespace std;


// Data structure for patient
struct patient {
	string patientID;
	string firstName;
	string lastName;
	int age;
	string gender;
	string phone;
	string address;
	string sicknessDesc;
	string visitDate;
	string visitTime;
	string disabilityOption;
	string doctorName = "";
	string medicineInfo = "";
	patient *nextAddress;
	patient *prevAddress;
};


// Declaration of global pointers for patient
extern patient *newNode, *waitingHead, *waitingTail, *current, *visitHead, *visitTail, *tempHead, *tempTail;


// Data structure for nurse
struct nurse {
	string username;
	string password;
};


// Declaration of global pointer for nurse
extern nurse *nurse1;


// Data structure for doctor
struct doctor {
	string username;
	string password;
};


// Declaration of global pointer for doctor
extern doctor *doctor1;

// Declaration of a global variable to keep track of the total number of patients
extern int totalPatientCount;

// Declaration of a global variable to keep track of the number of patients in the waiting list
extern int waitingListSize;