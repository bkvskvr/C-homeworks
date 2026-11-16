#include <iostream>
#include <stack>
#include <vector>
#include <stdexcept>

namespace stack_selfmade {
    template<typename T>
    class Stack {
    private:
        T data;
        Stack<T>* next = nullptr;

    public:
        Stack() = default;
        Stack(const Stack&) = delete;
        Stack& operator=(const Stack&) = delete;

        ~Stack() {
            while (!empty()) pop();
        }

        void push(T value) {
            Stack<T>* newNode = new Stack<T>();
            newNode->data = value;
            newNode->next = this->next;
            this->next = newNode;
        }

        void pop() {
            if (this->next) {
                Stack<T>* temp = this->next;
                this->next = this->next->next;
                temp->next = nullptr;
                delete temp;
            }
            else
                throw std::runtime_error("Stack is empty");
        }

        T top() {
            if (this->next)
                return this->next->data;
            throw std::runtime_error("Stack is empty");
        }

        bool empty() {
            return this->next == nullptr;
        }
    };
}

template<typename T>
int input_stack(std::vector<T>& a) {
    stack_selfmade::Stack<T> s;
    T value;

    std::cout << "Enter until we input zero\n";

    while (true) {
        std::cout << "Enter element: ";
        if (!(std::cin >> value))
            throw std::runtime_error("Invalid input");
        if (value == 0) break;
        s.push(value);
        a.push_back(value);
    }

    return (int)a.size();
}

template<typename T>
void print_stack(const std::vector<T>& a) {
    stack_selfmade::Stack<T> s;
    std::stack<T> stl;

    for (T value : a) {
        s.push(value);
        stl.push(value);
    }

    std::cout << "Selfmade stack: ";
    while (!s.empty()) {
        std::cout << s.top() << " ";
        s.pop();
    }

    std::cout << "\nSTL stack: ";
    while (!stl.empty()) {
        std::cout << stl.top() << " ";
        stl.pop();
    }
    std::cout << std::endl;
}

int main() {
    try {
        std::vector<int> a;
        int n = input_stack(a);
        std::cout << "Number of elements: " << n << std::endl;
        print_stack(a);

        std::vector<double> b;
        int m = input_stack(b);
        std::cout << "Number of elements: " << m << std::endl;
        print_stack(b);
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}