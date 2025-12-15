//Leni Frank - bankingApp.h for Assignment 5-3 - 30.11.25

#ifndef AIRGEAD_BANKING_BANKINGAPP_H_
#define AIRGEAD_BANKING_BANKINGAPP_H_

#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

// BakingAPP class stores investment details and generates compund-interes reports both with and without montly deposits
class BankingApp {
public:
	// Default constructor initializes all internal data
	BankingApp();

	// Setters for user input
	void setInitialInvestment(double t_amount);
	void setMonthlyDeposit(double t_deposit);
	void setAnnualInterest(double t_interest);
	void setNumYears(int t_years);

	// Display both final reports to the user
	void displayReports() const;

private:
	// Internal state following the bank's naming conventions
	double m_initialInvestment;
	double m_monthlyDeposit;
	double m_annualInterest;
	int m_numYears;

	// Struct used to store results of one full year
	struct YearSummary {
		int year;
		double endBalance;
		double earnedInterest;
	};

	// Perform all actual conpound interest calc - first ignores monthly deposits; second adds them
	vector<YearSummary> calculateWithoutDeposits() const;
	vector<YearSummary> calculateWithDeposits() const;

	// Helper that computes interest for one month
	double calculateMonthlyInterest(double t_balance, double t_interestRate) const;
};

#endif
