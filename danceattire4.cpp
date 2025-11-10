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
	int i = 0;
	int h = 0;
	int quantity1 = 0, quantity2 = 0, membership;
	double subtotal = 0.00, total = 0.00, membership_total = 0.00;
	double CLOTHES_PRICE = 0.00, SHOES_PRICE = 0.00;
	double discount_rate = 0.00;
	string selection, size;
	string program;
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
	switch (membership)
	{
	case 0:
		cout << "You won't get a discount." << endl;
		discount_rate = 0.00;
		break;
	case 1:
		cout << "You get a 20% off discount." << endl;
		discount_rate = 0.20;
		break;
	case 2:
		cout << "You get a 10% off discount"<< endl;
		discount_rate = 0.10;
		break;
	default:
		cout << "You won't get a discount." << endl;
		discount_rate = 0.00;
	}

	cout << "Enter 'S' to start shopping: " << endl;
	cin >> program;
	cout << endl;

	while (program == "S" || program ==  "C")
	{
		cout << "Would you like to order (C) for clothes or (S) for shoes? ";
		cin >> selection;
		cout << endl;
		//Clothing
		if (selection == "C")
		{
			cout << "Enter ONE type of dance clothing: (Leotard, Tights, Shorts, Leggings, Tops, or Jackets) ";
			cin >> clothing;
			cout << "How many would you like to purchase? ";
			cin >> quantity1;
			cout << endl;
			//Clothes Price Ranges
			if (clothing == "Leggings" || "Shorts") //Clothes
				CLOTHES_PRICE = 15.99;
			else if (clothing == "Jackets" || "Tops")
				CLOTHES_PRICE = 19.99;
			else
				CLOTHES_PRICE = 6.99;
		}
		//Shoes 
		else if (selection == "S")
		{
			cout << "Enter ONE type of dance shoe (Ballet, Pointe, Tap, Turners, or Jazz): ";
			cin >> shoes;
			cout << "How many would you like to purchase? ";
			cin >> quantity2;
			//Shoes Price Ranges
			if (shoes == "Tap" || "Pointe") //Shoes
				SHOES_PRICE = 25.99;
			else if (shoes == "Jazz" || "Ballet")
				SHOES_PRICE = 15.99;
			else
				SHOES_PRICE = 5.99;
		}
		else
		{
			cout << "ERROR!";
			system("pause");
			InFile.close();
			OutFile.close();
			return 1;
		}
		//Calculate
		cout << fixed << showpoint << setprecision(2);
		subtotal = (CLOTHES_PRICE * quantity1) + (SHOES_PRICE * quantity2);
		total = (subtotal * TAX) + subtotal + total;
		cout << "Would you like to continue or stop shopping? ( Enter \"C\" to continue or \"E\" to end) ";
		cin >> program;
		cout << endl;
	}
	do
	{
		if (membership != 0)
		{
			membership_total = (total * discount_rate);
			cout << "Your membership discount was successful!" << endl;
			total = membership_total;
			cout << "Press \"O\" to open membership benefits or press \"S\" to stop program.";
			cin >> program;
			cout << endl;
			true;
			if (program == "O")
			{
				cout << "To be continued. Please try again later." << endl;
			}
		}
		else
		{
			false;
		}
		
	} while (false);
	{
		cout << "Your order was successful!" << endl;
	}	


	//Output to report.txt
	OutFile << fixed << showpoint << setprecision(2);
	OutFile << "*-*-*-*-*-*-*-*-*-*-" << endl;
	OutFile << "Customer Name: " << name << endl;
	OutFile << "*-*-*-*-*-*-*-*-*-*-" << endl;
	OutFile << setfill('.') << left << setw(25) << " Clothing: " << clothing << endl;
	for (i = 0; i < quantity1;)
	{
		i++;
		//Figure out sizes
		cout << "What clothes size? ";
		cin >> size1;
		cout << endl;
		OutFile  << " Size " << i << ": " << setfill('.') << right << setw(20) << size1 <<  endl;
	}
	OutFile << setfill('.') << left << setw(25) << " Quantity: " << quantity1 << endl;
	OutFile << " Price per clothing: $" << CLOTHES_PRICE << endl;
	OutFile << "*-*-*-*-*-*-*-*-*-*-" << endl;
	OutFile << setfill('.') << left << setw(25) << " Shoes: " << shoes << endl;
	for (h = 0; h < quantity2;)
	{
		h++;
		//Figure out sizes
		cout << "What shoes size? ";
		cin >> size2;
		cout << endl;
		OutFile << " Size " << h << ": " << setfill('.') << right << setw(20)
			<< size2 << endl;
	}
	OutFile << setfill('.') << left << setw(27) << " Quantity: " << quantity2 << endl;
	OutFile << " Price per shoe: $" << SHOES_PRICE << endl;
	OutFile << "Subtotal = $" << subtotal << endl;
	OutFile << " Total = $" << total << endl;
	OutFile << "*-*-*-*-*-*-*-*-*-*-" << endl;
	OutFile << "Thank you for shopping with us!" << endl;
	OutFile << "*-*-*-*-*-*-*-*-*-*-" << endl;


	//Cart
	InFile >> name >> quantity1 >> clothing >> size1 >> CLOTHES_PRICE >> shoes >> size2 >> SHOES_PRICE;
	InFile >> subtotal >> total >> membership_total;
	InFile.close();
	OutFile.close();
	return 0;
}
