#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;

void itogi(const char* filename) {
    ifstream f(filename);

    if (!f.is_open()) {
        cout << "Error opening file!" << endl;
        return;
    }

    string line, name, token;

    cout << "\nResults:" << endl;

    while (getline(f, line)) {
        stringstream ss(line);

        if (!(ss >> name))
            continue;

        int correct = 0;
        int total = 0;

        while (ss >> token) {
            int i, j, answer;

            if (sscanf(token.c_str(), "%dx%d=%d", &i, &j, &answer) == 3) {
                if (i * j == answer)
                    correct++;

                total++;
            }
        }

        double percent = 0;

        if (total > 0)
            percent = 100.0 * correct / total;

        cout << name << ": " << percent << "%" << endl;
    }

    f.close();
}

int main() {
    srand(time(0));

    int m, n;

    cout << "Number of players: ";
    cin >> m;

    cout << "Number of questions: ";
    cin >> n;

    if (m <= 0 || n <= 0)
        return 1;

    ofstream f("game.txt");

    if (!f.is_open()) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    for (int k = 0; k < m; k++) {
        string name;

        cout << "\nEnter name: ";
        cin >> name;

        f << name;

        for (int q = 0; q < n; q++) {
            int i = rand() % 20 + 1;
            int j = rand() % 20 + 1;
            int answer;

            cout << i << " x " << j << " = ";
            cin >> answer;

            f << " " << i << "x" << j << "=" << answer;

            if (answer == i * j) {
                cout << "Correct!" << endl;
            }
            else {
                cout << "Wrong!" << endl;
            }
        }

        f << endl;
    }

    f.close();

    itogi("game.txt");

    return 0;
}