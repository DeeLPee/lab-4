#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include <cctype>
#include <sstream>


using namespace std;


int main()
{
	// Grand total variables for daily tracking
	double grandTotalSales = 0.0;
	int totalCustomers = 0;
	char anotherCustomer = 'Y';


	// Outer loop to simulate an entire day's worth of orders
	do {
		string foodName;
		string size;
		char choice;
		bool running;
		running = true;
		char choiceS;
		double price = 0.0;
		int quantity = 0;
		string inventoryAuditAccumulator = "";


		// Running subtotal for the entire customer order
		double customerSubtotal = 0.0;


		// String accumulator tracking order line items for the receipt
		string orderAccumulator = "";


		while (running) {


			cout << left;
			cout << "Please select one of these four snacks: " << endl;
			cout << setw(12) << "Snacks         " << "    Small (s)" << "     Medium (m)" << "     Large (l)" << endl;
			cout << setw(12) << "A. Chips       " << "    $2.99" << "         $3.99" << "          $5.99" << endl;
			cout << setw(12) << "B. Cookies     " << "    $3.99" << "         $5.99" << "          $7.99" << endl;
			cout << setw(12) << "C. Pretzels    " << "    $5.99" << "         $8.99" << "          $9.99" << endl;
			cout << setw(12) << "D. Fruit Snacks    " << "$1.99" << "         $3.99" << "          $7.99" << endl;
			cout << "E. Checkout" << endl;
			cout << "What would you like to eat? ";
			cin >> choice;


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
					cout << "How many? ";
					cin >> quantity;
					break;
				case 'M':
					size = "Medium";
					price = 3.99;
					cout << "How many? ";
					cin >> quantity;
					break;
				case 'L':
					size = "Large";
					price = 5.99;
					cout << "How many? ";
					cin >> quantity;
					break;
				default: "error! please try again";
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
					cout << "How many? ";
					cin >> quantity;
					break;
				case 'M':
					size = "Medium";
					price = 5.99;
					cout << "How many? ";
					cin >> quantity;
					break;
				case 'L':
					size = "Large";
					price = 7.99;
					cout << "How many? ";
					cin >> quantity;
					break;
				default: "error! please try again";
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
					cout << "How many? ";
					cin >> quantity;
					break;
				case 'M':
					size = "Medium";
					price = 8.99;
					cout << "How many? ";
					cin >> quantity;
					break;
				case 'L':
					size = "Large";
					price = 9.99;
					cout << "How many? ";
					cin >> quantity;
					break;
				default: "error! please try again";
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
					cout << "How many? ";
					cin >> quantity;
					break;
				case 'M':
					size = "Medium";
					price = 3.99;
					cout << "How many? ";
					cin >> quantity;
					break;
				case 'L':
					size = "Large";
					price = 7.99;
					cout << "How many? ";
					cin >> quantity;
					break;
				default: "error! please try again";
					break;
				}


				


				break;


			case'E':
				cout << "Alright, moving to checkout." << endl;
				running = false;
				break;


			default:
				cout << "You failed to pick a correct menu option, try again." << endl;
				break;
			}


			// End of Phase 1, Step A: Print selected item & append to orderAccumulator string
			if (running && (toupper(choice) >= 'A' && toupper(choice) <= 'D')) {
				cout << left;
				cout << setw(20) << "Food = " << foodName << endl;
				cout << setw(20) << "Size = " << size << endl;
				cout << setw(20) << "Price = " << fixed << setprecision(2) << "$" << price << endl;


				double itemSubtotal = quantity * price;
				customerSubtotal += itemSubtotal;


				// Formatted string line item appended to accumulator with a newline
				ostringstream line;
				line << fixed << setprecision(2)
					<< foodName
					<< " (" << size << ") x"
					<< quantity
					<< " $" << price
					<< " = $" << itemSubtotal
					<< "\n";
				orderAccumulator += line.str();
				//orderAccumulator += foodName + " (" + size + ") x" + to_string(quantity) + "  $" + to_string(price) + " = $" + to_string(itemSubtotal) + "\n";


				char auditBuffer[100];
				snprintf(auditBuffer, sizeof(auditBuffer), "%-20s%-12d$%.2f\n", foodName.c_str(), quantity, price);
				inventoryAuditAccumulator += auditBuffer;
			}


		}


		string name;
		cout << "What's your name? ";
		cin >> name;


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


		// Calculate subtotal and discounts
		double subtotal = customerSubtotal > 0 ? customerSubtotal : (quantity * unitPrice);


		double discount = 0.00;
		if (toupper(member) == 'Y') {
			discount = subtotal * 0.10;
		}


		double discountedSubtotal = subtotal - discount;


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
		double tipAmount = 0.0;
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
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Enter Cashier Notes: ";
		getline(cin, cashierNotes);


		// Receipt refactored to use orderAccumulator
		cout << "==========================================RECIPT================================================\n";


		cout << left;
		cout << setw(27) << "Name = " << name << endl;
		cout << "Items:\n" << orderAccumulator << fixed << setprecision(2);
		if (toupper(member) == 'Y') {
			cout << "Thank you for being a member! You get 10% off." << endl;
		}
		cout << setw(27) << "Total = " << fixed << setprecision(2) << "$" << total << std::endl;


		// Loyalty Point Display (1 point per $3 total order amount, rounded down)
		int points = static_cast<int>(total) / 3;
		cout << "Loyalty Points:   ";
		for (int i = 0; i < points; i++) {
			cout << "*";
		}
		cout << endl;


		cout << " ===============================================================================================\n";


		cout << "\n\n========================= INVENTORY AUDIT ===========================\n";
		cout << left << setw(20) << "Food Name" << setw(12) << "Quantity" << setw(15) << "Unit Price" << endl;
		cout << "---------------------------------------------------------------------\n";
		cout << inventoryAuditAccumulator;


		// Accumulate grand totals for daily tracking
		grandTotalSales += total;
		totalCustomers++;


		// Ask if another customer is waiting
		cout << "\nIs there another customer? (y/n): ";
		cin >> anotherCustomer;
		cout << endl;


	} while (toupper(anotherCustomer) == 'Y');


	// Final EOD Summary Output
	cout << "\n========================= DAILY SUMMARY ===========================" << endl;
	cout << "Total Customers: " << totalCustomers << endl;
	cout << "Total Sales: $" << fixed << setprecision(2) << grandTotalSales << endl;
	cout << "==================================================================" << endl;


	return 0;
}
