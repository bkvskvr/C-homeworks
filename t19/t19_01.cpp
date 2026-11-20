#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;

    cout << "Enter number of customers: ";
    cin >> n;

    if (!cin || n <= 0) {
        cout << "Invalid number of customers!" << endl;
        return 1;
    }

    vector<double> t(n);
    vector<double> c(n);

    for (int i = 0; i < n; i++) {
        cout << "Enter service time for customer " << i + 1 << ": ";
        cin >> t[i];

        if (!cin || t[i] < 0) {
            cout << "Invalid service time!" << endl;
            return 1;
        }
    }

    c[0] = 0;

    for (int i = 1; i < n; i++) {
        c[i] = max(0.0, c[i - 1] + t[i - 1] - 1);
    }

    cout << "\nWaiting times:" << endl;

    for (int i = 0; i < n; i++) {
        cout << "Customer " << i + 1
             << ": " << c[i] << " minutes" << endl;
    }

    int min_customer = 0;
    int max_customer = 0;

    for (int i = 1; i < n; i++) {
        if (t[i] < t[min_customer])
            min_customer = i;

        if (c[i] > c[max_customer])
            max_customer = i;
    }

    cout << "\nCustomer with minimum service time: "
         << min_customer + 1 << endl;

    cout << "Minimum service time: "
         << t[min_customer] << " minutes" << endl;

    cout << "Customer with maximum waiting time: "
         << max_customer + 1 << endl;

    cout << "Maximum waiting time: "
         << c[max_customer] << " minutes" << endl;

    return 0;
}