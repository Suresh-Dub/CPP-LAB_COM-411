#include <iostream>

using namespace std;

class Calculator {
public:
    int x, y;

    Calculator() {
        x = 0;
        y = 0;
    }

    Calculator(int a, int b) {
        x = a;
        y = b;
    }

    virtual void add() {
        cout << "Sum: " << x + y << endl;
    }

    virtual void subtract() {
        cout << "Difference: " << x - y << endl;
    }
};

class AdvancedCalculator : public Calculator {
public:
    AdvancedCalculator() {
        x = 0;
        y = 0;
    }

    AdvancedCalculator(int a, int b) {
        x = a;
        y = b;
    }

    void multiply() {
        cout << "Product: " << x * y << endl;
    }

    void divide() {
        if (y == 0) {
            cout << "Division is not possible" << endl;
        }
        else if (x % y != 0) {
            cout << "Division is not possible, remainder is not zero" << endl;
        }
        else {
            cout << "Quotient: " << x / y << endl;
        }
    }
};

int main() {
    int a, b;

    cout << "Enter first number: ";
    cin >> a;

    cout << "Enter second number: ";
    cin >> b;

    Calculator* calc = new Calculator(a, b);
    calc->add();
    calc->subtract();

    AdvancedCalculator* advCalc = new AdvancedCalculator(a, b);
    advCalc->multiply();
    advCalc->divide();

    delete calc;
    delete advCalc;

    return 0;
}
