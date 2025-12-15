//Leni Frank - bankingApp.cpp for Assignment 5-3 - 30.11.25

#include "bankingApp.h"

// Constructor initializes all values to zero
BankingApp::BankingApp()
	: m_initialInvestment(0.0),
	m_monthlyDeposit(0.0),
	m_annualInterest(0.0),
	m_numYears(0) {}

// Setter functions to validate incoming values before storing them
void BankingApp::setInitialInvestment(double t_amount) {
	if (t_amount < 0) {
		throw invalid_argument("Initial investment must be non-negative.");
	}
	m_initialInvestment = t_amount;
}

void BankingApp::setMonthlyDeposit(double t_deposit) {
	if (t_deposit < 0) {
		throw invalid_argument("Monthly deposit must be non-negative.");
	}
	m_monthlyDeposit = t_deposit;
}

void BankingApp::setAnnualInterest(double t_interest) {
	if (t_interest < 0) {
		throw invalid_argument("Annual interest must be non-negative.");
	}
	m_annualInterest = t_interest;
}

void BankingApp::setNumYears(int t_years) {
	if (t_years <= 0) {
		throw invalid_argument("Number of years must be positive.");
	}
	m_numYears = t_years;
}

// Helper function calculaes one month of interest
double BankingApp::calculateMonthlyInterest(double t_balance, double t_interestRate) const {
	double monthlyRate = (t_interestRate / 100.0) / 12.0;
	return t_balance * monthlyRate;
}

// Function to calculate compound interest WITHOUT monthly deposits
vector<BankingApp::YearSummary> BankingApp::calculateWithoutDeposits() const {
	vector<YearSummary> results;
	double balance = m_initialInvestment;

	for (int year = 1; year <= m_numYears; year++) {
		//Total earned interest over this year
		double interestEarned = 0.0;

		for (int month = 1; month <= 12; month++) {
			double interest = calculateMonthlyInterest(balance, m_annualInterest);
			interestEarned += interest;
			// Compound
			balance += interest;
		}

		results.push_back({ year, balance, interestEarned });
	}

	return results;

}

// Function calculates compound interest WITH monthly deposits
vector<BankingApp::YearSummary> BankingApp::calculateWithDeposits() const {
	vector<YearSummary> results;
	double balance = m_initialInvestment;

	for (int year = 1; year <= m_numYears; year++) {
		double interestEarned = 0.0;

		for (int month = 1; month <= 12; month++) {
			balance += m_monthlyDeposit;
			double interest = calculateMonthlyInterest(balance, m_annualInterest);
			interestEarned += interest;
			balance += interest;
		}

		results.push_back({ year, balance, interestEarned });

	}

	return results;

}

// Function to print BOTH full reports
void BankingApp::displayReports() const {
	auto noDep = calculateWithoutDeposits();
	auto withDep = calculateWithDeposits();

	cout << "\n\n BALANCE AND INTEREST WITHOUT MONTHLY DEPOSITS" << endl;
	cout << "Year\t\tYear End Balance\tYear End Earned Interest" << endl;
	cout << " --------------------------------------------------------------------------------- " << endl;

	for (const auto &y : noDep) {
		cout << "   " << y.year
			<< "\t\t$ " << y.endBalance
			<< "\t\t$ " << y.earnedInterest
			<< endl;
	}

	cout << "\n\n BALANCE AND INTEREST WITH ADDITIONAL $" << m_monthlyDeposit << " MONTHLY DEPOSITS" << endl;
	cout << "  Year\t\tYear End Balance\tYear End Earned Interest " << endl;
	cout << " --------------------------------------------------------------------------------- " << endl;

	for (const auto& y : withDep) {
		cout << "   " << y.year
			<< "\t\t$ " << y.endBalance
			<< "\t\t$ " << y.earnedInterest
			<< endl;
	}

	cout << endl;

}