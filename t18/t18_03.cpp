#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;
namespace homework18 {

template<typename T>
class BlackBox {
private:
    T data[100];
    int n;

public:
    BlackBox() {
        n = 0;
    }

    BlackBox(const T* arr, int size) {
        if (size < 0 || size > 100)
            throw runtime_error("Invalid array size!");

        n = size;

        for (int i = 0; i < n; i++)
            data[i] = arr[i];
    }

    void push(T value) {
        if (n >= 100)
            throw runtime_error("BlackBox is full!");

        data[n] = value;
        n++;
    }

    T pop() {
        if (n == 0)
            throw runtime_error("BlackBox is empty!");

        int i = rand() % n;
        T value = data[i];

        data[i] = data[n - 1];
        n--;

        return value;
    }

    T xpop() const {
        if (n == 0)
            throw runtime_error("BlackBox is empty!");

        int i = rand() % n;

        return data[i];
    }

    bool empty() const {
        return n == 0;
    }

    int size() const {
        return n;
    }
};

}

using namespace homework18;

int main() {
    srand(time(0));

    try {
        BlackBox<int> box;

        box.push(10);
        box.push(20);
        box.push(30);
        box.push(40);
        box.push(50);

        cout << "Number of elements: "
             << box.size() << endl;

        cout << "Random element (xpop): "
             << box.xpop() << endl;

        cout << "Number of elements: "
             << box.size() << endl;

        cout << "Random element (pop): "
             << box.pop() << endl;

        cout << "Number of elements: "
             << box.size() << endl;

        int a[] = {1, 2, 3, 4, 5};

        BlackBox<int> box2(a, 5);

        cout << "\nElements from array:" << endl;

        while (!box2.empty()) {
            cout << box2.pop() << " ";
        }

        cout << endl;

        BlackBox<string> box3;

        box3.push("apple");
        box3.push("banana");
        box3.push("orange");

        cout << "\nRandom string: "
             << box3.xpop() << endl;

        cout << "Removing strings:" << endl;

        while (!box3.empty()) {
            cout << box3.pop() << " ";
        }

        cout << endl;

        cout << "\nTrying to pop from empty box:" << endl;
        cout << box3.pop() << endl;
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}