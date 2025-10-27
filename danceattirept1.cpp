//Dance Attire
//Clothing and Shoe Sales
#include <iostream>
#include <string>
using namespace std;

//Declare Constant Variables
const double TAX = 0.06;
const double SHOES_PRICE = 15.99;
const double CLOTHES_PRICE = 20.99;

int main() 
{
//Variables 
	int quantity1, quantity2;
	double subtotal, total;
	string name, size1, size2, clothing, shoes;
//Ask for name
	cout << "Enter your name: ";
	cin >> name;
	cout << endl;

//Clothing
	cout << "Enter ONE type of dance clothing: (Leotards, Tights, Bottoms, Tops, or Jackets :";
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
	cout << endl;
//Calculate
	subtotal = (CLOTHES_PRICE * quantity1) + (SHOES_PRICE * quantity2);
	total = (subtotal * TAX) + subtotal;
//Output
	cout << "You have purchased: " << quantity1 << " " << size1 << " " << clothing << " and "
		<< quantity2 << " " << shoes << " shoes " << " Size: " << size2 << endl;
	cout << "Subtotal: " << subtotal << endl;
	cout << "Total: " << total << endl;
	cout << "Thank you for purchasing " << name << "!" << endl;
	system("pause");
	return 0;
}
