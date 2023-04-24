/* Programmer: Justin Brown
* Date: 3/26/2023
* Class: CS-210
*/

//Pulling required libraries
#include <iostream>
#include <iomanip>

using namespace std;




//Task for accessing and interacting with the menu
void menuInterface() {

	//List of variables and data types
	float initialInvestment;
	float annualInterest;
	float monthlyDeposit;
	float months;
	float years;
	float totalAmount;
	float interestAmount;
	float yearTotalInterest;

	//Below prints out the menu interface for user
	cout << "***************************" << endl;
	cout << "****** Data Input ****** " << endl;
	cout << "Initial Investment Amount: " << endl;
	cout << "Monthly Deposit: " << endl;
	cout << "Annual Interest: " << endl;
	cout << "Number of years: " << endl;

	//Menu pauses and waits for user input
	system("pause");


	//Menu displays for input from user
	cout << " " << endl;
	cout << "Data Input " << endl;
	cout << "Initial Investment Amount: $ ";
	cin >> initialInvestment;
	cout << "Monthly Deposit: $ ";
	cin >> monthlyDeposit;
	cout << "Annual Interest: % ";
	cin >> annualInterest;
	cout << "Number of years: ";
	cin >> years;
	months = years * 12;

	system("pause");

	totalAmount = initialInvestment;

	cout << "\n\nBalance and Interest Without Additional Monthly Deposits " << endl;
	cout << "=" << endl;
	cout << "Year\t\tYear End Balance\tYear End Earned Interest" << endl;
	cout << "- " << endl;
	for (int i = 0; i < years; i++) {

	//Calculates yearly interest
	interestAmount = (totalAmount) * ((annualInterest / 100));


	//Calculates year end total
	totalAmount = totalAmount + interestAmount;

		//Prints total rounded to two decimal points
		cout << (i + 1) << "\t\t$" << " " << fixed << setprecision(2) << totalAmount << "\t\t\t$" << interestAmount << endl;
	}

	totalAmount = initialInvestment;

	//Displays the yearly data alongside monthly deposits
	cout << "\n\nBalance and Interest With Additional Monthly Deposits " << endl;
	cout << "=" << endl;
	cout << "Year\t\tYear End Balance\tYear End Earned Interest" << endl;
	cout << "-" << endl;
	for (int i = 0; i < years; i++) {

	//Sets yearly interest to zero at the start of the year
	yearTotalInterest = 0;
	for (int j = 0; j < 12; j++) {

	//Calculates the monthly interest
	interestAmount = (totalAmount + monthlyDeposit) * ((annualInterest / 100) / 12);

	//Calculates the month end interest
	yearTotalInterest = yearTotalInterest + interestAmount;

	//Calculates the month end total
	totalAmount = totalAmount + monthlyDeposit + interestAmount;

	}
	//Prints total rounded to two decimal points
	cout << (i + 1) << "\t\t\$" << fixed << setprecision(2) << totalAmount << " " << "\t\t$" << yearTotalInterest << endl;
	}
}
//Main function
int main() {
	menuInterface();
	return 0;
}