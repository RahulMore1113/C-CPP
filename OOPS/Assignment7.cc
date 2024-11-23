#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    map<string, int> populationMap = {
        {"Maharashtra", 125}, {"Uttar Pradesh", 225}, {"Bihar", 120},
        {"West Bengal", 100}, {"Madhya Pradesh", 90}, {"Tamil Nadu", 80},
        {"Rajasthan", 78}, {"Andhra Pradesh", 53}, {"Odisha", 47},
        {"Kerala", 38}, {"Telangana", 37}, {"Assam", 35}, {"Jharkhand", 38},
        {"Karnataka", 68}, {"Gujarat", 70}, {"Punjab", 31}, {"Chhattisgarh", 30},
        {"Haryana", 29}, {"UT Delhi", 19}, {"UT Jammu and Kashmir", 14},
        {"Uttarakhand", 12}, {"Himachal Pradesh", 8}, {"Tripura", 4},
        {"Meghalaya", 4}, {"Manipur", 3}, {"Nagaland", 2}, {"Goa", 2},
        {"Arunachal Pradesh", 2}, {"UT Puducherry", 2}, {"Mizoram", 1},
        {"UT Chandigarh", 1}, {"Sikkim", 1}, {"UT Dadra and Nagar Haveli and Daman and Diu", 1},
        {"UT Andaman and Nicobar Islands", 1}, {"UT Lakshadweep", 0}, {"UT Ladakh", 0}
    };

    populationMap.erase(--populationMap.end());

    cout << "Total states and UT of India: " << populationMap.size() << '\n';
    
    for (const auto& entry : populationMap) {
        cout << entry.first << ": " << entry.second << " million\n"; // Using entry.first and entry.second
    }

    char c;
    do {
        string state;
        cout << "\nEnter the state you want to know the population of: ";
        cin >> state;

        auto iter = populationMap.find(state);
        if (iter != populationMap.end())
            cout << state << "'s population is " << iter->second << " million\n";
        else
            cout << "State is not in populationMap" << '\n';

        cout << "Do you want to continue? (y/n): ";
        cin >> c;
    } while (c == 'y' || c == 'Y');

    return 0;
}
