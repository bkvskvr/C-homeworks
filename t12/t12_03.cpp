#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;
int main() {
    unsigned int n;
    cout<<"enter n: ";
    cin>>n;
    cout<<string(50, '+')<<endl;
    for (int i=1;i<=n;i++) {
        cout<<setw(7)<<i<<" ";
    }
    cout<<endl;
    cout<<string(50, '+')<<endl;
    for (int i=1;i<=n;i++) {
        cout<<setw(7)<<pow(i, 0.5)<<setprecision(3)<<" "; // setw - set width
    }
}