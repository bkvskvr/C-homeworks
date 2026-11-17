#include <iostream>

using namespace std;
namespace homework18 {

template<typename T>
class Array {
private:
    int n;
    T* a;

public:
    Array(int size) {
        n = size;
        a = new T[n];
    }

    ~Array() {
        delete[] a;
    }

    void input() {
        for (int i = 0; i < n; i++) {
            cout << "a[" << i << "] = ";
            cin >> a[i];
        }
    }

    void output() {
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }

    void bubbleSort() {
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (a[j] > a[j + 1]) {
                    T temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;
                }
            }
        }
    }

    static void bubbleSort(T arr[], int size) {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    T temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }
};

}

using namespace homework18;

int main() {
    int n;

    cout << "Enter array size: ";
    cin >> n;

    if (!cin || n <= 0)
        return 1;

    Array<int> a(n);

    cout << "Enter elements:" << endl;
    a.input();

    cout << "Original array: ";
    a.output();

    a.bubbleSort();

    cout << "Sorted array: ";
    a.output();

    double b[] = { 5.5, 2.2, 8.8, 1.1, 3.3 };

    Array<double>::bubbleSort(b, 5);

    cout << "Sorted double array: ";

    for (int i = 0; i < 5; i++) {
        cout << b[i] << " ";
    }

    cout << endl;

    return 0;
}