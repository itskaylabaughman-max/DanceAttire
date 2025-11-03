#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

//Declare Constant Variables
const double TAX = 0.06;
const string Store = "cart.txt";
const string Receipt = "report.txt"; //Receipt

int main()
{
	ifstream InFile; // input file stream variable
	ofstream OutFile; //output file stream variable
	InFile.open(Store);
	OutFile.open(Receipt);
	//Variables 
	int quantity1, quantity2;
	double subtotal = 0.00, total = 0.00;
	double CLOTHES_PRICE = 19.99, SHOES_PRICE = 9.99;
	string name, size1, size2, clothing, shoes;
	//Friendly Introduction Banner
	cout << "*-*-*-*-*-*-*-*-*-*-" << endl;
	cout << "Welcome to our Dance Attire Store!" << endl;
	cout << "*-*-*-*-*-*-*-*-*-*-" << endl;
	cout << "Clothing = $" << 19.99 << endl; 
	cout << "Shoes = $" << 9.99 << endl;
	cout << "*-*-*-*-*-*-*-*-*-*-" << endl;

	//Ask for name
	cout << "Enter your name: ";
	cin >> name;
	cout << endl;
	//Clothing
	cout << "Enter ONE type of dance clothing: (Leotard, Tights, Shorts, Leggings, Tops, or Jackets :";
	cin >> clothing;
	cout << "How many would you like to purchase? ";
	cin >> quantity1;
	cout << "What size? ";
	cin >> size1;
	cout << endl;

	//Shoes 
	cout << "Enter ONE type of dance shoe (Ballet, Pointe, Tap, Turners, or Jazz): ";
	cin >> shoes;
	cout << "How many would you like to purchase? ";
	cin >> quantity2;
	cout << "What size? ";
	cin >> size2;

	//Calculate
	cout << fixed << showpoint << setprecision(2);
	subtotal = (CLOTHES_PRICE * quantity1) + (SHOES_PRICE * quantity2);
	total = (subtotal * TAX) + subtotal;
	//Output to report.txt
	OutFile << fixed << showpoint << setprecision(2);
	OutFile << "*-*-*-*-*-*-*-*-*-*-" << endl;
	OutFile << "Customer Name: " << name << endl;
	OutFile << "*-*-*-*-*-*-*-*-*-*-" << endl;
	OutFile << setfill('.') << left << setw(20) << " Clothing: " << clothing << endl;
	OutFile << setfill('.') << left << setw(20) << " Size: " << size1 << endl;
	OutFile << setfill('.') << left << setw(20) << " Quantity: " << quantity1 << endl;
	OutFile << " Price per clothing: $" << CLOTHES_PRICE << endl;
	OutFile << "*-*-*-*-*-*-*-*-*-*-" << endl;
	OutFile << setfill('.') << left << setw(20) << " Shoes: " << shoes << endl;
	OutFile << setfill('.') << left << setw(20) << " Size: " << size2 << endl;
	OutFile << setfill('.') << left << setw(20) << " Quantity: " << quantity2 << endl;
	OutFile << " Price per shoe: $" << SHOES_PRICE << endl;
	OutFile << "Subtotal = $" << subtotal << endl;
	OutFile << " Total = $" << total << endl;
	OutFile << "*-*-*-*-*-*-*-*-*-*-";
	OutFile << "Thank you for shopping with us!" << endl;

	InFile.close();
	OutFile.close();
	return 0;
}
