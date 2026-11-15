#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;

int main() {
    ifstream inFile("input.txt");

    if (!inFile) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    double x = 0;
    double sum = 0;
    char c;

    if (inFile >> x) {
        sum = x;
    }

    while (inFile >> c) {
        if (c == '=') {
            break;
        }

        inFile >> x;

        if (c == '+') {
            sum += x;
        }
        else if (c == '-') {
            sum -= x;
        }
    }

    cout << "Result: " << sum << endl;

    inFile.close();
    return 0;
}