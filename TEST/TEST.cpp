#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include <cctype>
using namespace std;


int main()
{


	string foodName;
	string size;
	char choice;
	cout << left;
	cout << "Please select one of these four snacks: " << endl;
	cout << setw(12) << "Snacks         " << "    Small (s)" << "     Medium (m)" << "     Large (l)" << endl;
	cout << setw(12) << "A. Chips       " << "    $2.99" << "         $3.99" << "          $5.99" << endl;
	cout << setw(12) << "B. Cookies     " << "    $3.99" << "         $5.99" << "          $7.99" << endl;
	cout << setw(12) << "C. Pretzels    " << "    $5.99" << "         $8.99" << "          $9.99" << endl;
	cout << setw(12) << "D. Fruit Snacks    " << "$1.99" << "         $3.99" << "          $7.99" << endl;
	cout << "What would you like to eat? ";
	cin >> choice;
	char choiceS;
	double price;

	switch (toupper(choice))
	{
	case 'A':
		foodName = "Chips";
		cout << "What size would you like (s, m, l)? ";
		cin >> choiceS;
		switch (toupper(choiceS))
		{
		case 'S':
			size = "Small";
			price = 2.99;
			break;
		case 'M':
			size = "Medium";
			price = 3.99;
			break;
		case 'L':
			size = "Large";
			price = 5.99;
			break;
		}

		break;
	case 'B':
		foodName = "Cookies";
		cout << "What size would you like (s, m, l)? ";
		cin >> choiceS;
		switch (toupper(choiceS))
		{
		case 'S':
			size = "Small";
			price = 3.99;
			break;
		case 'M':
			size = "Medium";
			price = 5.99;
			break;
		case 'L':
			size = "Large";
			price = 7.99;
			break;
		}

		break;
	case 'C':
		foodName = "Pretzels";
		cout << "What size would you like (s, m, l)? ";
		cin >> choiceS;
		switch (toupper(choiceS))
		{
		case 'S':
			size = "Small";
			price = 5.99;
			break;
		case 'M':
			size = "Medium";
			price = 8.99;
			break;
		case 'L':
			size = "Large";
			price = 9.99;
			break;
		}

		break;
	case 'D':
		foodName = "Fruit Snacks";
		cout << "What size would you like (s, m, l)? ";
		cin >> choiceS;
		switch (toupper(choiceS))
		{
		case 'S':
			size = "Small";
			price = 1.99;
			break;
		case 'M':
			size = "Medium";
			price = 3.99;
			break;
		case 'L':
			size = "Large";
			price = 7.99;
			break;
		}

		break;
	default:
		cout << "You failed to pick a correct menu option, try again." << endl;
		break;
	}
	cout << left;
	cout << setw(20) << "Food = " << foodName << endl;
	cout << setw(20) << "Size = " << size << endl;
	cout << setw(20) << "Price = " << fixed << setprecision(2) << "$" << price << endl;

	int quantity;
	cout << "How many? ";
	cin >> quantity;


	double unitPrice;
	unitPrice = price;

	char member;
	cout << "Are you a member (y/n)? ";
	cin >> member;
	cout << left;
	cout << setw(27) << "Food =  " << foodName << std::endl;
	cout << setw(27) << "Quantity = " << quantity << endl;
	cout << setw(27) << "Unit Price = " << fixed << setprecision(2) << "$" << unitPrice << endl;
	cout << setw(27) << "Member = " << member << std::endl;

	//calculate subtotal
	double subtotal = quantity * unitPrice;

	double discount = 0.00;
	if (member == 'y') {
		discount = subtotal * 0.10;
	}

	double discountedSubtotal = subtotal - discount;

	//DiscountedSubtotal
   // Sales Taxes
	double stateTax = discountedSubtotal * 0.065;
	double countyTax = discountedSubtotal * 0.005;
	double municipalTax = discountedSubtotal * 0.02125;


	double totalTax = stateTax + countyTax + municipalTax;




	// Tax Table
	cout << left << setw(25) << "Tax"
		<< setw(12) << "Rate"
		<< right << setw(12) << "Amount" << endl;


	cout << left << setw(25) << "Arkansas State Tax"
		<< setw(12) << "6.5%"
		<< right << setw(12) << stateTax
		<< endl;


	cout << left << setw(25) << "Faulkner County Tax"
		<< setw(12) << "0.5%"
		<< right << setw(12) << countyTax
		<< endl;


	cout << left << setw(25) << "Conway Municipal Tax"
		<< setw(12) << "2.125%"
		<< right << setw(12) << municipalTax
		<< endl;




	// Tip Menu
	cout << "Tip Selection Amount" << endl;
	cout << "A. 15%   $" << discountedSubtotal * 0.15 << endl;
	cout << "B. 20%   $" << discountedSubtotal * 0.20 << endl;
	cout << "C. 25%   $" << discountedSubtotal * 0.25 << endl;
	cout << "D. Other Amount" << endl;




	// Tip Choice
	char tipChoice;
	double tipAmount;
	double otherAmount;


	cout << "What tip do you choose? ";
	cin >> tipChoice;

	switch (toupper(tipChoice))
	{
	case 'A':
		tipAmount = discountedSubtotal * 0.15;
		break;
	case 'B':
		tipAmount = discountedSubtotal * 0.20;
		break;
	case 'C':
		tipAmount = discountedSubtotal * 0.25;
		break;
	case 'D':
		cout << "What would you like to tip (EX. 0.2, 0.53)? ";
		cin >> otherAmount;
		tipAmount = discountedSubtotal * otherAmount;
		break;
	default:
		cout << "You failed to pick a correct menu option, try again." << endl;
	}

	double total = totalTax + tipAmount + discountedSubtotal;

	cout << " Your total is: " << total << endl;


	string cashierNotes;
	cin.ignore();
	cout << "Enter Cashier Notes: ";
	getline(cin, cashierNotes);

	//Receipt
	cout << "==========================================RECIPT================================================\n";

	//cout << left << setw(20) << "Food Name" << setw(12) << "Code" << right << setw(10) << "Quantity" << setw(15) << "UnitPrice" << setw(20) << "Total(Without Tax)" << endl;
	cout << left;
	cout << setw(27) << "Food =  " << foodName << endl;
	cout << setw(27) << "Quantity = " << quantity << endl;
	cout << setw(27) << "Unit Price = " << fixed << setprecision(2) << "$" << unitPrice << endl;
	if (member == 'y') {
		cout << "Thank you for being a member! You get 10% off." << endl;
	}
	cout << setw(27) << "Total (Without Tax) = " << fixed << setprecision(2) << "$" << total << std::endl;

	cout << " ===============================================================================================\n";

	cout << "\n\n========================= INVENTORY AUDIT ===========================\n";
	cout << left << setw(20) << "Food Name" << setw(12) << "Quantity" << setw(15) << "Unit Price" << endl;
	cout << "---------------------------------------------------------------------\n";
	cout << left << setw(20) << foodName << setw(12) << quantity << setw(15) << fixed << setprecision(2) << unitPrice << endl;

}