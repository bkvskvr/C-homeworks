#include <iostream>
#include <fstream>
#include <cctype>
#include <string>

using namespace std;

int main() {
    ifstream inFile("input2.txt");
    ofstream outFile("output2.txt");

    if (!inFile || !outFile) {
        cout << "Error opening file" << endl;
        return 1;
    }

    char c;
    string currentWord = "";
    bool flag = false;

    while (inFile.get(c)) {
        if (c == ' ' || c == '\n') {
            if (!currentWord.empty()) {
                if (flag) {
                    currentWord[0] = toupper(currentWord[0]);
                    flag = false;
                }

                if (currentWord == "der" || currentWord == "die" || currentWord == "das") {
                    flag = true;
                }

                outFile << currentWord;
                currentWord = "";
            }

            outFile << c;
        }
        else {
            currentWord += c;
        }
    }

    if (!currentWord.empty()) {
        if (flag) {
            currentWord[0] = toupper(currentWord[0]);
        }
        outFile << currentWord;
    }

    inFile.close();
    outFile.close();

    return 0;
}