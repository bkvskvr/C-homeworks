#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream inFile("input3.txt");
    ofstream outFile("output3.txt");

    if (!inFile || !outFile) {
        cout << "Error opening files" << endl;
        return 1;
    }

    char c;
    string word = "";

    while (inFile.get(c)) {
        if (c == '\n' || c == ' ' || c == ',' ||
            c == '.' || c == '!' || c == '?') {

            for (int i = static_cast<int>(word.size()) - 1; i >= 0; i--) {
                outFile << word[i];
            }

            word = "";
            outFile << c;
        }
        else {
            word += c;
        }
    }

    for (int i = static_cast<int>(word.size()) - 1; i >= 0; i--) {
        outFile << word[i];
    }

    inFile.close();
    outFile.close();

    return 0;
}