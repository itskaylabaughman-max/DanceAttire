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
	int quantity1, quantity2, membership;
	double subtotal = 0.00, total = 0.00, membership_total = 0.00;
	double CLOTHES_PRICE = 0.00, SHOES_PRICE = 0.00;
	double discount_rate = 0.00;
	string name, purchasing, size1, size2, clothing, shoes;
	//Friendly Introduction Banner
	cout << "*-*-*-*-*-*-*-*-*-*-" << endl;
	cout << "Welcome to our Dance Attire Store!" << endl; 
	cout << "*-*-*-*-*-*-*-*-*-*-" << endl;
	cout << "Clothing:" << endl;
	cout << "*-*-*-*-*-*-*-*-*-*-" << endl;
	cout << "Leggings and Shorts = " << 15.99 << endl; 
	cout << "Jackets and Tops = $" << 19.99 << endl; 
	cout << "Tights and Leotards =  $" << 6.99 << endl;
	cout << "*-*-*-*-*-*-*-*-*-*-" << endl;
	cout << "Shoes:" << endl;
	cout << "*-*-*-*-*-*-*-*-*-*-" << endl;
	cout << "Tap and Pointe shoes = $" << 25.99 << endl;
	cout << "Jazz and Ballet shoes = $" << 15.99 << endl; 
	cout << "Turners = $" << 5.99 << endl;
 
	//Ask for name
	cout << "Enter your name: ";
	cin >> name;
	cout << endl;
	//Membership
	cout << "Are you a member?" << endl;
	cout << "Membership Type: Not a member = 0 Premium = 1 or Original = 2 ";
	cin >> membership;
	cout << endl;
	switch(membership)
	{
	case 0:
		cout << "You won't get a discount";
		discount_rate = 0.00;
		break;
	case 1:
		cout << "You get a 20% off discount";
		discount_rate = 0.20;
		break;
	case 2:
		cout << "You get a 10% off discount";
		discount_rate = 0.10;
		break;
	default:
		cout << "You won't get a discount";
		discount_rate = 0.00;
	}
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

	//Price Ranges
	if (clothing == "Leggings" || "Shorts") //Clothes
		CLOTHES_PRICE = 15.99;
	else if (clothing == "Jackets" || "Tops")
		CLOTHES_PRICE = 19.99;
	else
		CLOTHES_PRICE = 6.99;
	if (shoes == "Tap" || "Pointe") //Shoes
		SHOES_PRICE = 25.99;
	else if (shoes == "Jazz" || "Ballet")
		SHOES_PRICE = 15.99;
	else
		SHOES_PRICE = 5.99;
	cout << endl;
	//Calculate
	cout << fixed << setprecision(2);
	subtotal = (CLOTHES_PRICE * quantity1) + (SHOES_PRICE * quantity2);
	total = (subtotal * TAX) + subtotal;
	if (membership == 1 || membership == 2)
	{
		membership_total = total - (total * discount_rate);
	}
	else
	{
		membership_total = total;
	}
	//Output to report.txt
	OutFile << fixed << setprecision(2);
	OutFile << "*-*-*-*-*-*-*-*-*-*-" << endl;
	OutFile << "Customer Name: " << name << endl;
	OutFile << "*-*-*-*-*-*-*-*-*-*-" << endl;
	OutFile << setfill('.') << left << setw(35) << " Clothing: " << clothing << endl;
	OutFile << setfill('.') << left << setw(35) << " Size: " << size1 << endl;
	OutFile << setfill('.') << left << setw(35) << " Quantity: " << quantity1 << endl;
	OutFile << " Price per clothing: $" << CLOTHES_PRICE << endl;
	OutFile << "*-*-*-*-*-*-*-*-*-*-" << endl;
	OutFile << setfill('.') << left << setw(35) << " Shoes: " << shoes << endl;
	OutFile << setfill('.') << left << setw(35) << " Size: " << size2 << endl;
	OutFile << setfill('.') << left << setw(35) << " Quantity: " << quantity2 << endl;
	OutFile << " Price per shoe: $" << SHOES_PRICE << endl;
	OutFile << "Subtotal = $" << subtotal << endl;
	OutFile << " Total = $" << total << endl;
	OutFile << " Membership Total = $" << membership_total << endl; 
	OutFile << "*-*-*-*-*-*-*-*-*-*-";
		

	//Cart
	InFile >> name >> quantity1 >> clothing >> size1 >> CLOTHES_PRICE >> shoes >> size2 >> SHOES_PRICE;
	InFile >> subtotal >> total >> membership_total;
	InFile.close();
	OutFile.close();
	return 0;
}
