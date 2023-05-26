#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <numeric>
using namespace std; 

#include "functions.h"


int main() {
    using namespace std;
    string filename, data;
    vector<double> numbers;

    // Prompt the user to enter the filename
    cout << "Enter the filename: ";
    getline(cin, filename);

    // Write data to file
    writeDataToFile(filename, numbers);

    // Ask the user if they want to perform additional operations
    char choice;
    cout << "Do you want to perform additional operations on the data? (Y/N): ";
    cin >> choice;

    while (tolower(choice) == 'y') {
        // Open the file in read mode and read the data
        readDataFromFile(filename);

        // Perform additional operations based on user's choice
        cout << "\nAvailable operations:\n";
        cout << "1. Calculate the sum\n";
        cout << "2. Calculate the average\n";
        cout << "3. Find the maximum value\n";
        cout << "4. Reverse the order of elements\n";
        cout << "5. Shuffle the elements\n";
        cout << "6. Calculate the median\n";

        cout << "Enter the operation number (1-6): ";
        int operation;
        cin >> operation;

        switch (operation) {
        case 1:
            cout << "Sum: " << sum(numbers) << endl;
            break;
        case 2:
            cout << "Average: " << average(numbers) << endl;
            break;
        case 3:
            cout << "Maximum value: " << max(numbers) << endl;
            break;
        case 4:
            reverse(numbers);
            cout << "Elements reversed.\n";
            break;
        case 5:
            shuffle(numbers);
            cout << "Elements shuffled.\n";
            break;
        case 6:
            cout << "Median: " << median(numbers) << endl;
            break;
        default:
            cout << "Invalid operation number.\n";
            break;
        }

        // Ask the user if they want to perform more operations
        cout << "Do you want to perform more operations? (Y/N): ";
        cin >> choice;
    }

    return 0;
}


