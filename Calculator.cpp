#include <iostream>
#include <cmath>
#include <string>
using namespace std;

void getNumbers(double&, char&, double&);
void addition(double&, double&);
void subtraction(double&, double&);
void multiplication(double&, double&);
void division(double&, double&);
void power(double&, double&);
void squareRoot(double&);

int main() {
	char op;
	double num1, num2;

	string start = "y";

	//Header
	cout << "Calculator by Josue Ramirez";
	cout << "\nWelcome! This is a simple calculator, it CANNOT do complex math." << endl;

	while (start == "y" || start == "Y") {	//Loops if user wants to continue using the calculator
		getNumbers(num1, op, num2);	//Gets the operands and operator

		if (op == '+') {	//Calculates numbers depending on the operator
			addition(num1, num2);
		}
		else if (op == '-') {
			subtraction(num1, num2);
		}
		else if (op == '*') {
			multiplication(num1, num2);
		}
		else if (op == '/') {
			division(num1, num2);
		}
		else if (op == '^') {
			power(num1, num2);
		}

		cout << "\nContinue? (Y/N): ";	//Asks user if they want to continue using the calculator
		cin >> start;

		while (start != "N" && start != "n" && start != "Y" && start != "y") {	//Makes sure user inputs Y or N and not another letter
			cout << "\nContinue? (Y/N): ";
			cin >> start;
		}
	}
	return 0;
}

void getNumbers(double& num1, char& op, double& num2) {
	cout << "\nEnter the first number and then press ENTER. If you want the square root (s) still enter a number.\n";	//Asks user to input the first number (Will do infinite loop if a letter is entered)
	cin >> num1;

	cout << "\nEnter operator (+, -, *, /, ^, s) and then press ENTER.\n";	//Asks user to enter the operator

	cout << num1 << " ";	//Shows user what they inputed so far

	cin >> op;

	while (op != '+' && op != '-' && op != '*' && op != '/' && op!= '^' && op!= 's') {	//Makes sure user enters an operator
		cout << "\nERROR: Did not enter an operator and then press ENTER.";
		cout << "\nEnter operator; +, -, *, /, ^, s\n";

		cout << num1 << " "; //Shows user what they inputed so far

		cin >> op;
	}
	
	if (op == 's') {
		squareRoot(num1);

		return;
	}

	cout << "\nEnter the second number and then press ENTER.\n";	//Asks user to input the second number (Will do infinite loop if a letter is entered)

	cout << num1 << " " << op << " ";	//Shows user what they inputed so far

	cin >> num2;

	if (op == '/') {	//Makes sure user doesn't divide by zero
		while (num2 == 0) {
			cout << "\nERROR: Cannot divide by zero.";
			cout << "\nEnter the second number and then press ENTER.\n";
			cout << num1 << " " << op << " ";
			cin >> num2;
		}
	}
}

void addition(double& addNum1, double& addNum2) {
	double addResult;

	addResult = addNum1 + addNum2;

	cout << "\nResult:\n";
	cout << addNum1 << " + " << addNum2 << " = " << addResult << endl;
}

void subtraction(double& subNum1, double& subNum2) {
	double subResult;

	subResult = subNum1 - subNum2;

	cout << "\nResult:\n";
	cout << subNum1 << " - " << subNum2 << " = " << subResult << endl;
}

void multiplication(double& mulNum1, double& mulNum2) {
	double mulResult;

	mulResult = mulNum1 * mulNum2;

	cout << "\nResult:\n";
	cout << mulNum1 << " * " << mulNum2 << " = " << mulResult << endl;
}

void division(double& divNum1, double& divNum2) {
	double divResult;

	divResult = divNum1 / divNum2;

	cout << "\nResult:\n";
	cout << divNum1 << " / " << divNum2 << " = " << divResult << endl;
}

void power(double& pwNum1, double& pwNum2) {
	double pwResult;

	pwResult = pow(pwNum1, pwNum2);

	cout << "\nResult:\n";
	cout << pwNum1 << " ^ " << pwNum2 << " = " << pwResult << endl;
}

void squareRoot(double& sqNum) {
	double sqResult;

	sqResult = sqrt(sqNum);

	cout << "\nResult:";
	cout << "\nThe square root of " << sqNum << " is " << sqResult << endl;
}
