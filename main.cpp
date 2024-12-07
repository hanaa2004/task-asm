#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

// Function to convert any base to decimal
int toDecimal(const string& number, int base) {
    int result = 0;
    int power = 0;
    for (int i = number.size() - 1; i >= 0; --i) {
        char digit = number[i];
        int value = (digit >= '0' && digit <= '9') ? digit - '0' : toupper(digit) - 'A' + 10;
        result += value * pow(base, power++);
    }
    return result;
}

// Function to convert decimal to any base
string fromDecimal(int decimal, int base) {
    if (decimal == 0) return "0";
    string result;
    while (decimal > 0) {
        int remainder = decimal % base;
        char digit = (remainder < 10) ? '0' + remainder : 'A' + remainder - 10;
        result = digit + result;
        decimal /= base;
    }
    return result;
}

int main() {
    int choice;
    do {
        cout << "Number System Converter\n";
        cout << "1. Convert Binary to Decimal\n";
        cout << "2. Convert Octal to Decimal\n";
        cout << "3. Convert Hexadecimal to Decimal\n";
        cout << "4. Convert Decimal to Binary\n";
        cout << "5. Convert Decimal to Octal\n";
        cout << "6. Convert Decimal to Hexadecimal\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        string input;
        int decimalValue;
        switch (choice) {
            case 1:
                cout << "Enter binary number: ";
                cin >> input;
                cout << "Decimal: " << toDecimal(input, 2) << endl;
                break;
            case 2:
                cout << "Enter octal number: ";
                cin >> input;
                cout << "Decimal: " << toDecimal(input, 8) << endl;
                break;
            case 3:
                cout << "Enter hexadecimal number: ";
                cin >> input;
                cout << "Decimal: " << toDecimal(input, 16) << endl;
                break;
            case 4:
                cout << "Enter decimal number: ";
                cin >> decimalValue;
                cout << "Binary: " << fromDecimal(decimalValue, 2) << endl;
                break;
            case 5:
                cout << "Enter decimal number: ";
                cin >> decimalValue;
                cout << "Octal: " << fromDecimal(decimalValue, 8) << endl;
                break;
            case 6:
                cout << "Enter decimal number: ";
                cin >> decimalValue;
                cout << "Hexadecimal: " << fromDecimal(decimalValue, 16) << endl;
                break;
            case 7:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
        cout << endl;
    } while (choice != 7);

    return 0;
}


// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.