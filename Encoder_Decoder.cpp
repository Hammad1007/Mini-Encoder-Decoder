//Assumptions assumed:
//* Data members have been set as protected
//* In function vowel count, it displays the vowels, consonants, special characters
//* An extra function is of letter counting, added in the premium decoder class to count letters in premium decoder class
//* OperateDecoder works on the principle of decoding only, it only decodes the message
//* Decode function is not written in every calss as it is carrying out the same work in all the three classes
//* The programme shows multiple inheritance
//*                           PremiumDecoder <----- Decoder -----> SuperDecoder



// *************************************************************************************************************

#include <iostream>	// for cin and cout words
#include <stdlib.h>	
#include <conio.h>
#include <string>	// for string handling
#include <fstream>	// for file handling
#include <string.h>	// for strings
using namespace std;

// Function to show the interface of the console window
void Menu() {
	cout << "\t\t*******************Multi-Level Inheritance and Relationships*******************" << endl;
	cout << endl;
	cout << "Submitted by: " << "\tHammad Rashid" << "\n";
	cout << endl;
	cout << "\t\t\t\t****Welcome to Mini Encoder-Decoder Programme****" << endl;
	cout << endl;
}

// Prints the line where called
void LineFun() {
	cout << "\t\t<----------------------------------------------------------------------------->" << endl;
}

// Parent class
class Decoder {
protected:
	string message;
public:
	// Default Constructor
	Decoder() {
		cout << "Decoder() called.\n";
		message = '\0';
	}

	// Parameterized Constructor
	Decoder(string message) {
		this->message = message;
	}

	// Copy Constructor
	Decoder(const Decoder& decoder) {
		this->message = decoder.message;
	}

	// Setter
	void setmessage(string message) {
		this->message = message;
	}

	// Getter
	string getmessage() {
		return message;
	}

	// Take input from the user
	void Input() {
		cout << "Enter the message string: ";
		getline(cin, message);
	}

	// Display the user given string
	void Display() {
		cout << "The original text message is: " << message << endl;
	}

	// Function to decode the string
	void Decode() {
		char temp;
		int size = message.length();
		for (int i = 0; i < size; i++) {
			if (message[i] == 'V') {
				temp = 'A';
				message[i] = temp;
			}
			else if (message[i] == 'W') {
				temp = 'B';
				message[i] = temp;
			}
			else if (message[i] == 'X') {
				temp = 'C';
				message[i] = temp;
			}
			else if (message[i] == 'Y') {
				temp = 'D';
				message[i] = temp;
			}
			else if (message[i] == 'Z') {
				temp = 'E';
				message[i] = temp;
			}
			else if (message[i] == 'v') {
				temp = 'a';
				message[i] = temp;
			}
			else if (message[i] == 'w') {
				temp = 'b';
				message[i] = temp;
			}
			else if (message[i] == 'x') {
				temp = 'c';
				message[i] = temp;
			}
			else if (message[i] == 'y') {
				temp = 'd';
				message[i] = temp;
			}
			else if (message[i] == 'z') {
				temp = 'e';
				message[i] = temp;
			}
			else if (message[i] == ' ') {     
				temp = ' ';
				message[i] = temp;
			}
			else if (message[i] == '.') {
				temp = '.';
				message[i] = temp;
			}
			else if (message[i] == ',') {
				temp = ',';
				message[i] = temp;
			}
			else if (message[i] == ':') {
				temp = ':';
				message[i] = temp;
			}
			else if (message[i] == ';') {
				temp = ';';
				message[i] = temp;
			}
			else if (message[i] == '!') {
				temp = '!';
				message[i] = temp;
			}
			else if (message[i] == '-') {
				temp = '-';
				message[i] = temp; 
			}
			else {
				temp = message[i] + 5;
				message[i] = temp;
			}
		}
		cout << "String after being decoded: " << message << endl;
	}

	// Destructor
	~Decoder() {
		cout << "~Decoder() called.\n";
	}

};  // end of class


// Child class of Decoder class
class SuperDecoder : public Decoder {
public:

	// Default Constructor
	SuperDecoder() {
		cout << "SuperDecoder() called.\n";
	}

	// Function counts vowels, consonants and special characters such as comma, space, fullstop
	void No_of_Vowels() {
		int special_count = 0;     	// number of special characters n the string e.g spaces, commas etc
		int vowel_count = 0;       	// number of vowels in the string
		int consonant_count = 0;   	// number of consonants in the string
		int size = this->message.length();	// calculate the size of the string
		for (int i = 0; i < size; i++) {
			if (message[i] == 'A' || message[i] == 'a' || message[i] == 'E' || message[i] == 'e' || message[i] == 'I' || message[i] == 'i' || message[i] == 'O' || message[i] == 'o' || message[i] == 'U' || message[i] == 'u') {
				vowel_count++;
			}
			else if (message[i] == ' ' || message[i] == '\n' || message[i] == '\t' || message[i] == '-' || message[i] == '!' || message[i] == ',' || message[i] == '!' || message[i] == ';' || message[i] == ':' || message[i] == '.') {
				special_count++;
			}
			else {
				consonant_count++;
			}
		}
		cout << "The number of vowels are: " << vowel_count << endl;
		cout << "The number of consonants are: " << consonant_count << endl;
		cout << "The number of miscellanous characters are: " << special_count << endl;
	}

	// Function counts number of words in the string
	void No_of_Words() {
		int word_count = 0;
		int i{};
		bool flag = false;
		while (message[i]) {
			if (message[i] == ' ' || message[i] == '\n' || message[i] == '\t' || message[i] == '-' || message[i] == '!' || message[i] == ',' || message[i] == '!' || message[i] == ';' || message[i] == ':') {
				flag = false;
			}
			else if (flag == false) {
				flag = 1;
				word_count++;
			}
			i++;
		}
		cout << "Number of words: " << word_count << endl;
	}

	// Destructor
	~SuperDecoder() {
		cout << "~SuperDecoder() called.\n";
	}

};  // end of class


// Child class of Decoder class
class PremiumDecoder : public Decoder {
public:

	// Default Constructor
	PremiumDecoder() {
		cout << "PremiumDecoder() called.\n";
	}

	// Function counts vowels, consonants and special characters such as comma, space, fullstop
	void No_of_Vowels() {
		int special_count = 0;     // number of special characters n the string e.g spaces, commas etc
		int vowel_count = 0;       // number of vowels in the string
		int consonant_count = 0;   // number of consonants in the string
		int size = this->message.length();
		for (int i = 0; i < size; i++) {
			if (message[i] == 'A' || message[i] == 'a' || message[i] == 'E' || message[i] == 'e' || message[i] == 'I' || message[i] == 'i' || message[i] == 'O' || message[i] == 'o' || message[i] == 'U' || message[i] == 'u') {
				vowel_count++;
			}
			else if (message[i] == ' ' || message[i] == '\n' || message[i] == '\t' || message[i] == '-' || message[i] == '!' || message[i] == ',' || message[i] == '!' || message[i] == ';' || message[i] == ':' || message[i] == '.') {
				special_count++;
			}
			else {
				consonant_count++;
			}
		}
		cout << "The number of vowels are: " << vowel_count << endl;
		cout << "The number of consonants are: " << consonant_count << endl;
		cout << "The number of miscellanous characters are: " << special_count << endl;
	}

	// Function counts number of words in the string
	int No_of_Words() {
		int word_count = 0;
		int i{};
		bool flag = false;
		while (message[i] != '\0') {
			if (message[i] == ' ' || message[i] == '\n' || message[i] == '\t' || message[i] == '-' || message[i] == '!' || message[i] == ',' || message[i] == '!' || message[i] == ';' || message[i] == ':') {
				flag = false;
			}
			else if (flag == false) {
				flag = true;
				word_count++;
			}
			i++;
		}
		cout << "Number of words are: " << word_count << endl;
		return word_count;
	}

	// Function reverses the string
	void Reverse() {
		char rev_temp;
		int size = message.length();
		for (int i = 0; i < size / 2; i++) {
			rev_temp = message[i];
			message[i] = message[size - i - 1];
			message[size - i - 1] = rev_temp;
		}
		cout << "Reversed decoded string is: " << message << endl;
	}

	// Additional function to Count the number of letters in the string
	int No_of_Letters() {
		int letter_count = 0;   	// variable to count letters, initialized to 0
		for (int i = 0; message[i] != '\0'; i++) {
			if (message[i] >= 65 || message[i] <= 90 && message[i] >= 97 || message[i] <= 122 && message[i] != ' ' || message[i] != ',' || message[i] != '.' || message[i] != '-' || message[i] != '!') {
				letter_count++;
			}
		}
		cout << "Number of letters are: " << letter_count << endl;
		return letter_count;
	}

	// Destructor
	~PremiumDecoder() {
		cout << "~PremiumDecoder() called.\n";
	}

};  // end of class


// Function to Decode the string using the Decoder
void OperateDecoder(Decoder &Instance) {
	Instance.Decode();
}

// Function to Decode the string using the Super Decoder
void OperateDecoder(SuperDecoder& Instance) {
	Instance.Decode();
	cout << endl;
	Instance.No_of_Vowels();
	cout << endl;
	Instance.No_of_Words();
}

// Function to Decode the string using the Premium Decoder 
void OperateDecoder(PremiumDecoder& Instance) {
	Instance.Decode();
	cout << endl;
	Instance.No_of_Letters();
	cout << endl;
	Instance.No_of_Vowels();
	cout << endl;
	Instance.No_of_Words();
	cout << endl;
	Instance.Reverse();
}

// Main Driver
int main() {
	system("Color B0");

   	// Menu function sets the interface
	Menu();

	cout << endl;

	Decoder d1;	// decoder class object
	d1.setmessage("Hammad Rashid");

	cout << "The set string is: " << d1.getmessage() << endl;

	cout << endl;

	OperateDecoder(d1);  // covers all the functionas of the Decoder class

	cout << endl;

	LineFun();  // prints a line

	cout << endl;

	SuperDecoder sd1;	// super decoder class object
	sd1.Input();

	cout << endl;

	sd1.Display();

	cout << endl; 

	OperateDecoder(sd1);  // covers all the functionas of the SuperDecoder class

	cout << endl;

	LineFun();   

	cout << endl;

	PremiumDecoder pd1;	// premium decoder class object
	pd1.Input();

	cout << endl;

	pd1.Display();

	cout << endl;

	OperateDecoder(pd1);  // covers all the functionas of the PremiumDecoder class

	cout << endl;

	LineFun();

	cout << endl;

	cout << "\n\n\t\t\t\t\t***************Thank You***************" << endl;

	system("Pause");
	return 0;

} // Main ends here
