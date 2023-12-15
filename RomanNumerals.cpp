#include <iostream>
#include <limits>
#include <string>
#include <utility> // Include for std::pair

using namespace std;

std::string buildNumeral(int num);

int main() {
    int number;
    while (true) {
        cout << "Enter a number: \n";
        cin >> number;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Numbers only \n";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
    }
    cout << "You entered: " << buildNumeral(number) << endl;
    return 0;
}

std::string buildNumeral(int num) {
    std::string result;
    std::pair<int, std::string> roman[] = {
        std::make_pair(1000, "M"), std::make_pair(900, "CM"), 
        std::make_pair(500, "D"), std::make_pair(400, "CD"),
        std::make_pair(100, "C"), std::make_pair(90, "XC"), 
        std::make_pair(50, "L"), std::make_pair(40, "XL"),
        std::make_pair(10, "X"), std::make_pair(9, "IX"), 
        std::make_pair(5, "V"), std::make_pair(4, "IV"), 
        std::make_pair(1, "I")
    };

    for (const auto &pair : roman) {
        while (num >= pair.first) {
            result += pair.second;
            num -= pair.first;
        }
    }

    return result;
}

