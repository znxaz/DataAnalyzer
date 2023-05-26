#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <vector>
#include <string>

double sum(const std::vector<double>& values);
double average(const std::vector<double>& values);
double max(const std::vector<double>& values);
void reverse(std::vector<double>& values);
void shuffle(std::vector<double>& values);
double median(const std::vector<double>& values);
void writeDataToFile(const std::string& filename, std::vector<double>& numbers);
void readDataFromFile(const std::string& filename);

#endif 
