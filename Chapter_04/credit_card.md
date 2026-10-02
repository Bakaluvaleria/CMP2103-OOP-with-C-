```cpp
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

// 1. Read input and clean it
string getCleanedInput(bool &all_digits) {
    string line, card;
    cout << "Enter card number: ";
    getline(cin, line);

    all_digits = true;
    for (char c : line) {
        if (c == ' ' || c == '-') continue;
        if (!isdigit(static_cast<unsigned char>(c))) { all_digits = false; break; }
        card += c;
    }
    return card;
}

// 2. Extract prefix (first 3 digits)
string getPrefix(const string &card) {
    return card.substr(0, min(3, (int)card.length()));
}

// 3. Check if prefix is matched (4, 5, 6, or 37)
bool isPrefixMatched(const string &card) {
    if (card.empty()) return false;
    char d1 = card[0];
    string first_two = card.substr(0, min(2, (int)card.length()));
    return d1 == '4' || d1 == '5' || d1 == '6' || first_two == "37";
}

// 4a. Sum of odd places (from the right, not doubled)
int sumOddPlaces(const string &card) {
    int sum = 0;
    for (int i = card.length() - 1; i >= 0; i -= 2)
        sum += card[i] - '0';
    return sum;
}

// 4b. Sum of double even places
int sumDoubleEvenPlaces(const string &card) {
    int sum = 0;
    for (int i = card.length() - 2; i >= 0; i -= 2) {
        int doubled = (card[i] - '0') * 2;
        sum += (doubled > 9) ? doubled - 9 : doubled;
    }
    return sum;
}

// 5. Final validity decision
bool isValid(bool all_digits, int size, bool matched, int sum_odd, int sum_even) {
    return all_digits && size >= 13 && size <= 16
           && matched && (sum_odd + sum_even) % 10 == 0;
}

// 6. Print results
void printResults(const string &prefix, bool matched, int size,
                  int sum_odd, int sum_even, bool valid) {
    cout << boolalpha;
    cout << "\nPrefix: " << prefix << "\n";
    cout << "Matched: " << matched << "\n";
    cout << "Size: " << size << "\n";
    cout << "Sum of Odd Numbers: " << sum_odd << "\n";
    cout << "Sum of double even numbers: " << sum_even << "\n";
    cout << "Valid: " << valid << "\n";
}

int main() {
    bool all_digits;
    string card = getCleanedInput(all_digits);

    int size = card.length();
    string prefix = getPrefix(card);
    bool matched = isPrefixMatched(card);
    int sum_odd = sumOddPlaces(card);
    int sum_even = sumDoubleEvenPlaces(card);
    bool valid = isValid(all_digits, size, matched, sum_odd, sum_even);

    printResults(prefix, matched, size, sum_odd, sum_even, valid);
    return 0;
}
```




# Credit Card validation program documentation

**Author:** Valeria  
**Date:** October 2, 2026  

This program checks whether a credit card number is valid. It cleans the input, extracts the prefix, checks that the card starts with an accepted issuer prefix (4, 5, 6 or 37), checks that the length is 13 to 16 digits, and applies the Luhn algorithm (Mod 10 check). The program is broken into small functions, each with one job, and main coordinates them.

---

## Function Descriptions

### 1. `string getCleanedInput(bool &all_digits)`
* **Purpose:** Reads the card number from the user and cleans it.
* **Return Value:** A string containing only the digits of the card number. The reference parameter `all_digits` is set to `false` if any invalid character was entered.
* **Explanation:** Reads the whole line with `getline`, skips spaces and dashes, and stops and flags `all_digits = false` when it meets any other non-digit character. All later functions rely on this output being digits only.

---

### 2. `string getPrefix(const string &card)`
* **Purpose:** Extracts the first 3 digits of the card number for display.
* **Return Value:** A string with the first 3 digits (or fewer if the card is shorter than 3 digits).
* **Explanation:** Uses `substr(0, min(3, length))`. The prefix is kept as a string so leading zeros are not lost.

---

### 3. `bool isPrefixMatched(const string &card)`
* **Purpose:** Checks whether the card starts with an accepted issuer prefix.
* **Return Value:** `true` if the card starts with 4, 5, 6 or 37; otherwise `false`.
* **Explanation:** Returns `false` for an empty card. Otherwise it compares the first digit against 4, 5 and 6, and the first two digits against "37".

---

### 4. `int sumOddPlaces(const string &card)`
* **Purpose:** Sums the digits in odd places, counting from right to left (1st, 3rd, 5th, ...).
* **Return Value:** An `int` with the total of the odd-place digits.
* **Explanation:** Starts at the last digit and moves left two positions at a time, adding each digit without doubling it.

---

### 5. `int sumDoubleEvenPlaces(const string &card)`
* **Purpose:** Doubles the digits in even places, counting from right to left (2nd, 4th, ...), and sums them.
* **Return Value:** An `int` with the total of the processed even-place digits.
* **Explanation:** Starts at the second-to-last digit and moves left two positions at a time. Each digit is doubled; if the result is greater than 9, 9 is subtracted (the same as adding its two digits, e.g. 12 becomes 1 + 2 = 3) before adding it to the sum.

---

### 6. `bool isValid(bool all_digits, int size, bool matched, int sum_odd, int sum_even)`
* **Purpose:** Makes the final decision on whether the card number is valid.
* **Return Value:** `true` if every check passes; otherwise `false`.
* **Explanation:** Combines four conditions: the input was digits only, the size is between 13 and 16, the prefix is matched, and `(sum_odd + sum_even) % 10 == 0`.

---

### 7. `void printResults(const string &prefix, bool matched, int size, int sum_odd, int sum_even, bool valid)`
* **Purpose:** Displays the results in the required output format.
* **Return Value:** None (`void`).
* **Explanation:** Prints the prefix, whether it matched, the size, the sum of odd places, the sum of doubled even places, and the final validity. `boolalpha` makes the booleans print as `true` or `false`.

---

### 8. `int main()`
* **Purpose:** Coordinates the whole program.
* **Return Value:** `0` on successful completion.
* **Explanation:** Calls `getCleanedInput`, computes the size, then calls `getPrefix`, `isPrefixMatched`, `sumOddPlaces` and `sumDoubleEvenPlaces`. It passes those results to `isValid` and finally to `printResults`. It contains no validation logic itself.
*