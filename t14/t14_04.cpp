#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream inFile("input4.txt");

    if (!inFile) {
        cerr << "Error opening file!" << endl;
        return -1;
    }

    string line;
    int count_closed = 0;
    int count_opened = 0;

    while (getline(inFile, line)) {
        for (int i = 0; i < line.length(); i++) {
            if (line.substr(i, 4) == "<td>") {
                count_opened++;
            }
            else if (line.substr(i, 5) == "</td>") {
                count_closed++;
            }

            if (count_closed > count_opened) {
                cout << "Incorrect order of tags" << endl;
                inFile.close();
                return 0;
            }
        }
    }

    if (count_opened != count_closed) {
        cout << "Incorrect number of tags" << endl;
    }
    else {
        cout << "The file is correct" << endl;
    }

    inFile.close();
    return 0;
}