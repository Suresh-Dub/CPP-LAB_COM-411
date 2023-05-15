// • To run and debug the project on the online GDB compiler.

#include <iostream>

using namespace std;

int main() {
    int n, sum = 0;
    cout << "Enter the number of integers to sum: ";
    cin >> n;

    int* nums = new int[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter integer " << i+1 << ": ";
        cin >> nums[i];
    }

    for (int i = 0; i < n; i++) {
        sum += nums[i];
    }

    cout << "The sum of the integers is: " << sum << endl;

    delete[] nums;

    return 0;
}

To run and debug this project on the online GDB compiler, follow these steps:

Go to the website https://www.onlinegdb.com/ and create a new C++ project by clicking on "Create a New Project" button.
Copy and paste the above code in the code editor.
Click on the "Compile & Run" button to compile and run the program.
Enter the number of integers to sum and the integers themselves when prompted by the program.
The output of the program will be displayed in the output panel.
To debug the program, click on the "Debug" button next to the "Compile & Run" button.
Set breakpoints in the code editor by clicking on the line number.
Click on the "Start Debugging" button.
Follow the program execution by clicking on the "Step Over" button to execute the current line of code or the "Step Into" button to step into the function calls.
The values of variables can be seen in the "Locals" panel.
To stop debugging, click on the "Stop Debugging" button.
