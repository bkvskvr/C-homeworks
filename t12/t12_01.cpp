#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;
int main() {
    double x, y, z;
    cout<<"x= ";
    cin>>x;
    cout<<"y= ";
    cin>>y;

    z=pow(x, y);
    cout<<"z= "<<z<<endl;
    cout<<"scientific z= "<<z<<" = "<<scientific<<z<<"\n";
}