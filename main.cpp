//Leni Frank - main.cpp for Assignment 5-3 - 30.11.25

#include <iostream>
#include "bankingApp.h"

using namespace std;

int main() {
	try {
		BankingApp app;

		// Variables to temporarily store user input before sending to object
		double initialAmount;
		double monthlyDep;
		double interestRate;
		int numYears;

		// Collecting user input
		cout << "Initial Investment Amount: ";
		cin >> initialAmount;

		cout << "Monthly Deposit: ";
		cin >> monthlyDep;

		cout << "Annual Interest(%): ";
		cin >> interestRate;

		cout << "NUmber of Years: ";
		cin >> numYears;

		// Store values inside the BankingApp object
		app.setInitialInvestment(initialAmount);
		app.setMonthlyDeposit(monthlyDep);
		app.setAnnualInterest(interestRate);
		app.setNumYears(numYears);

		// Pause screen before showing output tables
		cout << "\nPress any key to continue...";
		cin.ignore();
		cin.get();

		//Display both reports
		app.displayReports();
	}

	catch (const exception& ex) {
		// If anything invalid was entered, the program explains what went wrong
		cout << "\nError: " << ex.what() << endl;

	}

	return 0;

}