#pragma once
#include <string>
using namespace std;

void displayPatientDetails(patient* current);
patient* searchPatientByPatientID(string searchKey, patient* head);
void createAndInsertNewNodeToTheEnd(string listName, string patientID, string firstName, string lastName, int age, string gender, string phone, string address, string sicknessDesc, string visitDate, string visitTime, string disabilityOption, string doctorName, string medicineInfo);
void insertPatientToTheEndOfTempList();
void createTempList(patient* head);
void sortListBasedOnPatientIDInDescending();
void moveBackward();
void moveForward();
void displayTempListPageByPage();
void deleteTempList();
void searchMultiplePatients(string searchBy, string searchKey, patient* head);
void sortListBasedOnTimeInAscending();