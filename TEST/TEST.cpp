#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
using namespace std;


int main()
{
	string foodName;
	cout << "What would you like to eat? ";
	getline(cin, foodName);
	

	char itemCode;
	cout << "What is the item code letter? ";
	cin >> itemCode;

	int quantity;
	cout << "How many? ";
	cin >> quantity;


	double unitPrice;
	cout << "What is the cost? ";
	cin >> unitPrice;

	char member;
	cout << "Are you a member (y/n)? ";
	cin >> member;
	cout << left;
	cout << setw(27) << "Food =  " << foodName << std::endl;
	cout << setw(27) << "Item Code = " << itemCode << std::endl;
	cout << setw(27) << "Quantity = " << quantity << endl;
	cout << setw(27) << "Unit Price = " << fixed << setprecision(2) << "$" << unitPrice << endl;
	cout << setw(27) << "Member = " <<  member << std::endl;

	//calculate subtotal
	double subtotal = quantity * unitPrice;

	double discount = 0.00;
	if (member == 'y') {
		discount = subtotal * 0.10;
	}

	double discountedSubtotal = subtotal - discount;

	string cashierNotes;
	cin.ignore();
	cout << "Enter Cashier Notes: ";
	getline(cin, cashierNotes);

	//Receipt
	cout << "==========================================RECIPT================================================\n";

	//cout << left << setw(20) << "Food Name" << setw(12) << "Code" << right << setw(10) << "Quantity" << setw(15) << "UnitPrice" << setw(20) << "Total(Without Tax)" << endl;
	cout << left;
	cout << setw(27) << "Food =  " << foodName << std::endl;
	cout << setw(27) << "Item Code = " << itemCode << std::endl;
	cout << setw(27) << "Quantity = " << quantity << endl;
	cout << setw(27) << "Unit Price = " << fixed << setprecision(2) << "$" << unitPrice << endl;
	if (member == 'y') {
		cout << "Thank you for being a member! You get 10% off." << endl;
	}
	cout << setw(27) << "Total (Without Tax) = " << fixed << setprecision(2) << "$" << discountedSubtotal << std::endl;

	cout << " ===============================================================================================\n";

	cout << "\n\n========================= INVENTORY AUDIT ===========================\n";
	cout << left << setw(20) << "Food Name" << setw(12) << "Code" << right << setw(12) << "Quantity" << setw(15) << "Unit Price" << endl;
	cout << "---------------------------------------------------------------------\n";
	cout << left << setw(20) << foodName << setw(12) << itemCode << right << setw(12) << quantity << setw(15) << fixed << setprecision(2) << unitPrice << endl;
}
