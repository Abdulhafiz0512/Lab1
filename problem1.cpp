#include <iostream>
#include <cmath>
#include <string>
using namespace std;
void displayPattern(int n) {
    for ( int i=n; i>=0 ; i--){
        for ( int j=0; j<=i; j++){
            cout<< "*";
        }
        cout << endl;
    }
}
int getType(int n){
    int digit_count=0;
    if ( n=0){
        digit_count=1;
    } else
    {
        while ( n!=0){
            n/10;
            digit_count++;
        }
    }    if (n%2==0){
        cout<<" Even number";
    } else {
        cout <<" Odd number";
    }
    return 1;
}
void calculateWindChill(double temperature, double windSpeed) {
    if (temperature < -58,  temperature > 41,  windSpeed < 2) {
        cout << "Wrong parameters" << std::endl;
        return;
    }
    double twc = 35.74 + 0.6215 * temperature - 35.75 * pow(windSpeed, 0.16) + 0.4275
                                                                               * temperature * pow(windSpeed, 0.16);
    cout << "The wind chill index is " << twc << std::endl;
}
int countDigitOccurrences(int num, int digit) {
    int counter=0;
    while ( num!=0) {
        int remainder=num % 10;
        if (remainder=digit) {
            counter++;
        }
        num/10;
    }
    return counter;
}
void findDigitFrequency(int number) {
}
// p5
string digitToWord(int digit) {
    string words[] = {"zero", "one", "two", "three", "four", "five", "six", "seven",
                      "eight", "nine"};
    return words[digit];
}
string numberToWords(int number) {
    string result;
    while (number > 0) {
        int digit = number % 10;
        result = digitToWord(digit) + " " + result;
        number /= 10;
    }
    return result;
}
//p6
void solveQuadraticEquation(double a, double b, double c, double& discriminant,
                            double& r1, double& r2) {
    discriminant = b * b - 4 * a * c;
    if (discriminant >= 0) {
        r1 = (-b + sqrt(discriminant)) / (2 * a);
        r2 = (-b - sqrt(discriminant)) / (2 * a);
    }
}
//p7
void solveEquation(double a, double b, double c, double d, double e, double f, double&
x, double& y, bool& isSolvable) {
    double determinant = a * d - b * c;
    if (determinant != 0) {
        x = (e * d - b * f) / determinant;
        y = (a * f - e * c) / determinant;
        isSolvable = true;
    } else {
        isSolvable = false;
    }
}
//p8
bool something(double& x1, double& y1, double& x2, double& y2, double& x3, double& y3,
               double& x4, double& y4) {
    double vector1_x = x2 - x1;
    double vector1_y = y2 - y1;
    double vector2_x = x4 - x3;
    double vector2_y = y4 - y3;
    double dotProduct = vector1_x * vector2_x + vector1_y * vector2_y;
    return dotProduct == 0;
}
// Function to check if vectors AB and CD are orthogonal using dot product
bool areVectorsOrthogonal(double x1, double y1, double x2, double y2,
                          double x3, double y3, double x4, double y4) {
    return 1;
}
// p9
int octal2Dec(const int& octalNumber) {
    int decimalNumber = 0;
    int base = 1;
    int tempOctalNumber = octalNumber;
    while (tempOctalNumber != 0) {
        int lastDigit = tempOctalNumber % 10;
        tempOctalNumber /= 10;
        decimalNumber += lastDigit * base;
        base *= 8;
    }
    return decimalNumber;
}
void revChar(char& c) {
    if (c >= 'A' && c <= 'Z') {
        c = c + 32;
    } else if (c >= 'a' && c <= 'z') {
        c = c - 32;
    }
}
double avgOfEvenPlaces(int n) {
    int count = 0;
    int sum = 0;
    int digitPlace = 0;
    while (n != 0) {
        digitPlace++;
        if (digitPlace % 2 == 0) {
            sum += n % 10;
            count++;
        }
        n /= 10;
    }
    if (count == 0) {
        return 0.0;
    }
    return static_cast<double>(sum) / count;
}
//p12
double sqrtApproximation(double n) {
    const double epsilon = 0.0001;
    double lastGuess = 1.0;
    double nextGuess;
    do {
        nextGuess = (lastGuess + (n / lastGuess)) / 2;
        if (abs(nextGuess - lastGuess) < epsilon) {
            break;
        }
        lastGuess = nextGuess;
    } while (true);
    return nextGuess;
}
//p13
int enc(char a, int k) {
    int charValue = static_cast<int>(a);
    return charValue - 3 * k * k + 10;
}
//p14
char dec(int code, int k) {
    return static_cast<char>(code + 3 * k * k - 10);
}
// p15
bool isKaprekar(int n) {
    long long square = static_cast<long long>(n) * n;
    int numDigits = 0;
    int divisor = 1;
    while (square / divisor > 0) {
        numDigits++;
        divisor *= 10;
    }
    for (int i = 1; i < numDigits; i++) {
        divisor /= 10;
        int part1 = square / divisor;
        int part2 = square % divisor;
        if (part1 + part2 == n && part2 > 0) {
            return true;
        }
    }
    return false;
}
//p16
bool isPalindrome(const string& str) {
    string reversed = str;
    reverse(reversed.begin(), reversed.end());
    return str == reversed;
}
bool isLychrel(int n) {
    for (int i = 0; i < 50; i++) { // Iterate up to 50 times
        string originalStr = to_string(n);
        string reversedStr = originalStr;
        reverse(reversedStr.begin(), reversedStr.end());
        int reversedNum = stoi(reversedStr);
        n += reversedNum;
        if (isPalindrome(to_string(n))) {
            return false; // Found a palindrome
        }
    }
    return true; // No palindrome found after 50 iterations
}
// p17
int countDigits(int num) {
    int count = 0;
    while (num != 0) {
        count++;
        num /= 10;
    }
    return count;
}
bool isNarcissistic(int num) {
    int numDigits = countDigits(num);
    int sum = 0;
    int temp = num;
    while (temp != 0) {
        int digit = temp % 10;
        sum += pow(digit, numDigits);
        temp /= 10;
    }
    return sum == num;
}
// p18
int yearToCentury(int year) {
    return (year % 100 == 0) ? (year / 100) : (year / 100 + 1);
}
// p19
int totalMinutes(int hour1, int minute1, int hour2, int minute2) {
    int totalMin1 = hour1 * 60 + minute1;
    int totalMin2 = hour2 * 60 + minute2;
    return abs(totalMin2 - totalMin1);
}
// p20
bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
int daysInMonth(int year, int month) {
    if (month == 2) {
        return isLeapYear(year) ? 29 : 28;
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    } else {
        return 31;
    }
}
int daysSinceStartOfYear(int year, int month, int day) {
    int days = day;
    for (int m = 1; m < month; m++) {
        days += daysInMonth(year, m);
    }
    return days;
}
int daysBetweenDates(int year1, int month1, int day1, int year2, int month2, int day2)
{
    int days1 = daysSinceStartOfYear(year1, month1, day1);
    int days2 = daysSinceStartOfYear(year2, month2, day2);
    int totalDays = 0;
    for (int year = year1; year < year2; year++) {
        totalDays += isLeapYear(year) ? 366 : 365;
    }
    return totalDays + days2 - days1;
}
int main() {
    cout << "PROBLEM_1" << endl;
    int num_1;
    cin >> num_1;
    cout << " Enter the number for num_1: ";
    displayPattern(num_1);
    cout << "PROBLEM_2" << endl;
    int num_2;
    cout << " Enter the second number for num_2: ";
    cin >> num_2;
    getType(num_2);
    cout << " PROBLEM_3" << endl;
    double temperature, windSpeed;
    cout << "Enter the temperature in Fahrenheit between -58Â°F and 41Â°F: ";
    cin >> temperature;
    cout << "Enter the wind speed (>= 2) in miles per hour: ";
    cin >> windSpeed;
    calculateWindChill(temperature, windSpeed);
    cout << "PROBLEM_4" << endl;
    int num_4;
    cout << " Enter thw three number for num_4: ";
    cin >> num_4;
    for (int i = 0; i < 10; i++) {
        int frequency = countDigitOccurrences(num_4, i);
        cout << " The frequnecy" << i << " = " << frequency << endl;
    }
    cout << "Problem 5" << endl;
    int number2;
    cout << "Input: ";
    cin >> number2;
    cout << "Output: " << numberToWords(number2) << endl;
    cout << "Problem 6" << endl;
    double a, b, c, discriminant, r1, r2;
    cout << "Enter the coefficients (a, b, c) of the quadratic equation: ";
    cin >> a >> b >> c;
    solveQuadraticEquation(a, b, c, discriminant, r1, r2);
    if (discriminant > 0) {
        cout << "The roots of the quadratic equation are: " << r1 << " and " << r2 <<
             endl;
    } else if (discriminant == 0) {
        cout << "The quadratic equation has one root: " << r1 << endl;
    } else {
        cout << "The quadratic equation has no real roots." << endl;
    }
    cout << "Problem 7" << endl;
    double a, b, c, d, e, f, x, y;
    bool isSolvable;
    cout << "Enter the coefficients (a, b, c, d, e, f) of the linear equations: ";
    cin >> a >> b >> c >> d >> e >> f;
    solveEquation(a, b, c, d, e, f, x, y, isSolvable);
    if (isSolvable) {
        cout << "The solution to the system of equations is: x = " << x << ", y = " <<
             y << endl;
    } else {
        cout << "The equation has no solution." << endl;
    }
    cout << "Problem 8" << endl;
    double x1, y1, x2, y2, x3, y3, x4, y4;
    cout << "Enter the coordinates of points A, B, C, D (x1 y1 x2 y2 x3 y3 x4 y4): ";
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    if (something(x1, y1, x2, y2, x3, y3, x4, y4)) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }
    cout << "Problem 9" << endl;
    string octalStr;
    cout << "Enter an octal number: ";
    cin >> octalStr;
    int octalNumber = stoi(octalStr);
    int decimalEquivalent = octal2Dec(octalNumber);
    cout << "The decimal equivalent of " << octalStr << " is " << decimalEquivalent <<
         endl;
    cout << "Problem 10" << endl;
    char c;
    cout << "Enter a character: ";
    cin >> c;
    revChar(c);
    cout << "Reversed character: " << c << endl;
    cout << " Problem 11" << endl;
    int num;
    cout << "Enter an integer: ";
    cin >> num;
    double average = avgOfEvenPlaces(num);
    if (average != 0.0) {
        cout << "Average of digits in even places: " << average << endl;
    } else {
        cout << "No digits in even places found." << endl;
    }
    cout << "Problem 12" << endl;
    double n;
    cout << "Enter a number to find its square root: ";
    cin >> n;
    double squareRoot = sqrtApproximation(n);
    cout << "Approximated square root of " << n << " is: " << squareRoot << endl;
    cout << "Problem 13" << endl;
    char c;
    int k = rand() % 91 + 10;
    cout << "Enter 8 characters: ";
    for (int i = 0; i < 8; i++) {
        cin >> c;
        int encryptedCode = enc(c, k);
        cout << encryptedCode << " ";
    }
    cout << endl;
    cout << "KEY:" << k << endl;
    cout << " Problem 14" << endl;
    int key;
    cout << "Enter key: ";
    cin >> key;
    int encryptedCode;
    cout << "Enter the encrypted code separated by spaces: ";
    for (int i = 0; i < 8; i++) {
        cin >> encryptedCode;
        char decryptedChar = dec(encryptedCode, key);
        cout << decryptedChar;
    }
    cout << endl;
    cout << "Problem 15 " << endl;
    int num;
    cout << "Enter a number: ";
    cin >> num;
    if (isKaprekar(num)) {
        cout << num << " is a Kaprekar number." << endl;
    } else {
        cout << num << " is not a Kaprekar number." << endl;
    }
    cout << "Problem 16 " << endl;
    int num;
    cout << "Enter a number: ";
    cin >> num;
    if (isLychrel(num)) {
        cout << num << " is a Lychrel number." << endl;
    } else {
        cout << num << " is not a Lychrel number." << endl;
    }
    cout << "Problem 17 " << endl;
    int count = 0;
    int num = 1;
    cout << "The first 15 narcissistic decimal numbers are:" << endl;
    while (count < 15) {
        if (isNarcissistic(num)) {
            cout << num << endl;
            count++;
        }
        num++;
    }
    cout << " Problem 18 " << endl;
    int year;
    cout << "Enter a year: ";
    cin >> year;
    int century = yearToCentury(year);
    cout << "The century for year " << year << " is: " << century << endl;
    cout << "Problem 19 " << endl;
    int hour1, minute1, hour2, minute2;
    cout << "Enter the first time (hours minutes): ";
    cin >> hour1 >> minute1;
    cout << "Enter the second time (hours minutes): ";
    cin >> hour2 >> minute2;
    int minutes = totalMinutes(hour1, minute1, hour2, minute2);
    cout << "Total minutes between the two times: " << minutes << " minutes" << endl;
    cout << "Problem 20 " << endl;
    int year1, month1, day1, year2, month2, day2;
    cout << "Enter Year 1: ";
    cin >> year1;
    cout << "Enter Month 1: ";
    cin >> month1;
    cout << "Enter Day 1: ";
    cin >> day1;
    cout << "Enter Year 2: ";
    cin >> year2;
    cout << "Enter Month 2: ";
    cin >> month2;
    cout << "Enter Day 2: ";
    cin >> day2;
    int days = daysBetweenDates(year1, month1, day1, year2, month2, day2);
    cout << "Days between the two dates: " << days << endl;
    return 0;
}