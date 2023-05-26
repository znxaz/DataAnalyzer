#include "functions.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <stdexcept>

double sum(const std::vector<double>& values) {
    return std::accumulate(values.begin(), values.end(), 0.0);
}

double average(const std::vector<double>& values) {
    double sum = std::accumulate(values.begin(), values.end(), 0.0);
    return sum / values.size();
}

double max(const std::vector<double>& values) {
    if (values.empty()) {
        throw std::runtime_error("Cannot find maximum value in an empty vector.");
    }
    return *std::max_element(values.begin(), values.end());
}

void reverse(std::vector<double>& values) {
    std::reverse(values.begin(), values.end());
}

void shuffle(std::vector<double>& values) {
    std::random_shuffle(values.begin(), values.end());
}

double median(const std::vector<double>& values) {
    if (values.empty()) {
        throw std::runtime_error("Cannot find median value in an empty vector.");
    }

    std::vector<double> sortedValues = values;
    std::sort(sortedValues.begin(), sortedValues.end());

    if (sortedValues.size() % 2 == 0) {
        size_t mid = sortedValues.size() / 2;
        return (sortedValues[mid - 1] + sortedValues[mid]) / 2.0;
    }
    else {
        size_t mid = sortedValues.size() / 2;
        return sortedValues[mid];
    }
}

void writeDataToFile(const std::string& filename, std::vector<double>& numbers) {
    using namespace std;
    string data;

    // Open the file in append mode and write some data
    ofstream file(filename, ios::app);
    if (file.is_open()) {
        // Prompt the user to enter data to be written
        cout << "Please enter the data to write to the file (type 'q' to quit):\n";
        while (getline(cin, data)) {
            if (data == "q") {
                break;
            }

            // Validate input as numeric data
            try {
                double number = stod(data);
                file << number << "\n";
                numbers.push_back(number);
            }
            catch (const std::exception& e) {
                cout << "Invalid input. Only numeric data is accepted.\n";
            }
        }
        file.close();
        cout << "Data written to the file.\n";
    }
    else {
        cout << "Failed to open the file for writing.\n";
        exit(1);
    }
}

void readDataFromFile(const std::string& filename) {
    using namespace std;
    string data;

    // Open the file in read mode and read the data
    ifstream readFile(filename);
    if (readFile.is_open()) {
        cout << "File contents:\n";
        while (getline(readFile, data)) {
            cout << data << "\n";
        }
        readFile.close();
    }
    else {
        cout << "Failed to open the file for reading.\n";
        exit(1);
    }
}
