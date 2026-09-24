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
}