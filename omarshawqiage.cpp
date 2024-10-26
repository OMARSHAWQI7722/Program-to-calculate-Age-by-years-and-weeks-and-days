#include <iostream>
#include <ctime>
using namespace std;

int main() {
    int birthYear, birthMonth, birthDay;
    int currentYear, currentMonth, currentDay;

    
    time_t now = time(0);
    tm *ltm = localtime(&now);

    currentYear = 1900 + ltm->tm_year;
    currentMonth = 1 + ltm->tm_mon; 
    currentDay = ltm->tm_mday;

    
    cout << "Enter Your Birth Year: ";
    cin >> birthYear;
    cout << "Enter Your Birth Month (1-12): ";
    cin >> birthMonth;
    cout << "Enter Your Birth Day (1-31): ";
    cin >> birthDay;

    
    if (birthMonth < 1 || birthMonth > 12) {
        cout << "Error!! The Month is incorrect?!\n";
        return 1; 
    }
    if (birthDay < 1 || birthDay > 31) {
        cout << "Error!! The Number Of Day is incorrect?!\n";
        return 1; 
    }

    
    int ageYears = currentYear - birthYear;
    int ageMonths = currentMonth - birthMonth;
    int ageDays = currentDay - birthDay;

    
    if (ageDays < 0) {
        ageDays += 30; 
        ageMonths--;
    }
    if (ageMonths < 0) {
        ageMonths += 12;
        ageYears--;
    }

    int totalDays = ageYears * 365 + ageMonths * 30 + ageDays;
    int totalWeeks = totalDays / 7;

    cout << "Your Age is: " << ageYears << " Years" << endl;
    cout << "Your Age By Day is: " << totalDays << " Days" << endl;
    cout << "Your Age By Week is: " << totalWeeks << " Weeks" << endl;

    cout << "THIS PROGRAM IS DONE BY OMAR SHAWQI \nThanks.";
    
    return 0;
}