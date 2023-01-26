#include <strdio.h>
#include <iostream>
#include <string>
using namespace std;

//credit card checksum validator
bool numberStringCheck(const string& s){
	int len = s.length();
	
	for(int i = 0; i < len; i++){
		if(s[i] < '0' || s[i] > '9')
			return false;
	}
	
	return false;
}

//driver function
int main(){
	string creditCardNumber;
	
	cout << "This program will check if credit card number is valid." << endl;
	
	while(true){
		cout << "Enter your credit card number: ";
		cin >> creditCardNumber;
		
		if(creditCardNumber == "exit")
			break;
		
		else if(!numberStringCheck(creditCardNumber)){
			cout << "Invalid input. Input the correct credit card numbers";
			continue;
		}
		
		int len = creditCardNumber.length();
		int doubleCheckEven = 0;
		
		//every second digit doubled starting from right to left
		//if its a two digit number, add both digits to even single digit number
		for(int i = len - 2; i >= 0; i = i - 2){
			int doubleEven = ((creditCardNumber[i] - 48) * 2);
			
			if(doubleEven > 9){
				doubleEven = (doubleEven / 10) + (doubleEven % 10);
			}
			
			doubleCheckEven += doubleEven;
		}
		
		//add every odd digit from right to even digit
		for(int i = len - 1; i >= 0; i = i - 2){
			doubleCheckEven += (creditCardNumber[i] - 48);
		}
		
		//validate final sequence of numbers if multiple of 10
		cout << (doubleEvenSum % 10 == 0 ? "valid credit card number" : "invalid credit card number") << endl;
		continue;
	}
	
	return 0;
}
