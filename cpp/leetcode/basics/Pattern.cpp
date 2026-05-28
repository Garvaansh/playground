#include <iostream>
#include <string>
#include <algorithm>
using namespace std; 

string toLowerCase(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

string trimString(const string& str) {
    size_t start = str.find_first_not_of(' ');
    size_t end = str.find_last_not_of(' ');
    return (start == string::npos) ? "" : str.substr(start, end - start + 1);
}

void rectangle(int, int, string);
void hollow_rect(int, int, string);
void left_triangle(int, string);
void right_triangle(int, string);
void inverted_left_triangle(int, string);
void floyds_triangle(int);
void butterfly(int,string);
void equilateral_triangle(int, string);
void diamond(int, string);
void number_pat(int);
void binary_pat(int);
void parallelogram(int,string);
void palindrome(int);
void zigzag(int,string);

int main() {
    int x, y;
    string z;
    string a;

    cout << "Patterns: \n"
        "1. rectangle \t\t2. hollow rectangle \t\t 3. left triangle \n"
        "4. right triangle \t5. inverted left triangle \t 6. Equilateral Triangle \n"
        "7. Diamond Pattern \t8. Parallelogram \t\t 9. Butterfly pattern \n"
        "10. Floyd Triangle \t11. Binary pattern \t\t 12.Numbers pattern (idk what to call it :/) \n"
        "13. Palindrome pattern \t14. Zig-Zag pattern" << endl;
    cout << "Enter the pattern you want from above: ";
    getline(cin, z);  // Correctly read pattern input

    z = trimString(z);

    // Convert input pattern to lowercase for consistent matching
    string pattern = toLowerCase(z);

    if (pattern == "rectangle") {
        cout << "Enter the rows and/or columns of your pattern: ";
        cin >> x >> y;

    cout << "Enter the letter/char you'd like your pattern in: ";
    cin >> a;  // This works fine as it is
        rectangle(x, y, a);
    }
    else if (pattern == "hollow rectangle") {
        cout << "Enter the rows and/or columns of your pattern: ";
        cin >> x >> y;

    cout << "Enter the letter/char you'd like your pattern in: ";
    cin >> a;  // This works fine as it is
        hollow_rect(x, y, a);
    }
    else if (pattern == "left triangle") {
        cout << "Enter the rows and/or columns of your pattern: ";
        cin >> x;

    cout << "Enter the letter/char you'd like your pattern in: ";
    cin >> a;  // This works fine as it is
        left_triangle(x, a);
    }
    else if (pattern == "right triangle") {
        cout << "Enter the rows and/or columns of your pattern: ";
        cin >> x;

    cout << "Enter the letter/char you'd like your pattern in: ";
    cin >> a;  // This works fine as it is
        right_triangle(x, a);
    }
    else if (pattern == "inverted left triangle") {
        cout << "Enter the rows and/or columns of your pattern: ";
        cin >> x;
    cout << "Enter the letter/char you'd like your pattern in: ";
    cin >> a;  // This works fine as it is
        inverted_left_triangle(x, a);
    }

    else if (pattern == "equilateral triangle") {
        cout << "Enter the rows and/or columns of your pattern: ";
        cin >> x;
    cout << "Enter the letter/char you'd like your pattern in: ";
    cin >> a;  // This works fine as it is
        equilateral_triangle(x, a);
    }
    else if (pattern == "diamond") {
        cout << "Enter the rows and/or columns of your pattern: ";
        cin >> x;
    cout << "Enter the letter/char you'd like your pattern in: ";
    cin >> a;  // This works fine as it is
        diamond(x, a);
    }

    else if (pattern == "parallelogram") {
        cout << "Enter the rows and/or columns of your pattern: ";
        cin >> x;
    cout << "Enter the letter/char you'd like your pattern in: ";
    cin >> a;  // This works fine as it is
        parallelogram(x, a);
    }

    else if (pattern == "floyd triangle") {
        cout << "Enter the rows and/or columns of your pattern: ";
        cin >> x;
    floyds_triangle(x);
    }

    else if (pattern == "numbers pattern") {
        cout << "Enter the rows and/or columns of your pattern: ";
        cin >> x;
    number_pat(x);
    }

    else if (pattern == "binary pattern") {
        cout << "Enter the rows and/or columns of your pattern: ";
        cin >> x;
    binary_pat(x);
    }
    
    else if (pattern == "palindrome pattern") {
        cout << "Enter the rows and/or columns of your pattern: ";
        cin >> x;
    palindrome(x);
    }
    
    else if (pattern == "butterfly") {
        cout << "Enter the rows and/or columns of your pattern: ";
        cin >> x;
    cout << "Enter the letter/char you'd like your pattern in: ";
    cin >> a;  // This works fine as it is
        butterfly(x, a);
    }
    else if (pattern == "butterfly") {
        cout << "Enter the rows and/or columns of your pattern: ";
        cin >> x;
    cout << "Enter the letter/char you'd like your pattern in: ";
    cin >> a;  // This works fine as it is
        butterfly(x, a);
    }

    else if (pattern == "zigzag") {
        cout << "Enter the rows and/or columns of your pattern: ";
        cin >> x;
    cout << "Enter the letter/char you'd like your pattern in: ";
    cin >> a;  // This works fine as it is
        zigzag(x, a);
    }

    else {
        cout << "Invalid pattern. Please enter 'rectangle', 'hollow rectangle', 'left triangle', 'right triangle', or 'inverted right triangle'." << endl;
    }

    return 0;
}


void rectangle(int row, int col, string inp) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << inp << " ";
        }
        cout << "\n";
    }
}

void right_triangle(int row, string inp) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j <= i; j++) {
            cout << inp << " ";
        }
        cout << "\n";
    }
}

void inverted_left_triangle(int row, string inp) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < (row - i); j++) {
            cout << inp << " ";
        }
        cout << "\n";
    }
}

void left_triangle(int row, string inp) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < (row - i - 1); j++) {
            cout << "  "; // Two spaces for better alignment
        }
        for (int j = 0; j <= i; j++) {
            cout << inp << " ";
        }
        cout << "\n";
    }
}

void hollow_rect(int row, int col, string inp) {
    for (int i = 0; i < row; i++) {
        if (i == 0 || i == (row - 1)) {
            for (int j = 0; j < col; j++) {
                cout << inp << " ";
            }
        } else {
            for (int j = 0; j < col; j++) {
                if (j == 0 || j == (col - 1)) {
                    cout << inp << " ";
                } else {
                    cout << "  ";
                }
            }
        }
        cout << "\n";
    }
}

void floyds_triangle(int row) {
    int count = 1;  // Starting number for Floyd's triangle
    for(int i = 0; i < row; i++) {
        for(int j = 0; j <= i; j++) {
            cout << count << " ";
            count++; }
            cout << endl;
            }
}

void butterfly(int row, string inp) {
for( int i = 0; i < row; i++ ) {
    for( int j = 0; j <= i; j++) {
        cout << inp ; }
    int space = 2*(row - i - 1);
    for ( int j = 0; j < space ; j++) {
        cout << " " ;
    }
    for( int j = 0; j <= i; j++) {
        cout << inp ; }
        
        cout << "\n" ;
        }

for( int i = (row - 1);i>= 0; i-- ) {
    for( int j = 0; j <= i; j++) {
        cout << inp ; }
    int space = 2*(row - i - 1);
    for ( int j = 0; j < space ; j++) {
        cout << " " ;
    }
    for( int j = 0; j <= i; j++) {
        cout << inp ; }

        cout << "\n" ;
        }
}

void equilateral_triangle(int row, string inp) {
        for (int i = 1; i <= row; i++) {
        // Print leading spaces
        for (int j = i; j < row; j++) {
            cout << " ";
        }
        
        // Print stars for the ith row
        for (int j = 1; j <= (2*i - 1); j++) {
            cout << inp;
        }
        
        // Move to the next line
        cout << endl;
    }
}

void diamond(int row, string inp) {
        for (int i = 1; i <= row; i++) {
        // Print leading spaces
        for (int j = i; j < row; j++) {
            cout << "  ";
        }
        
        // Print stars for the ith row
        for (int j = 1; j <= (2*i - 1); j++) {
            cout << inp << " ";
        }
        
        // Move to the next line
        cout << endl;
    }
    for (int i = row; i >= 1; i--) {
        // Print leading spaces
        for (int j = i; j < row; j++) {
            cout << "  ";
        }
        
        // Print stars for the ith row
        for (int j = 1; j <= (2*i - 1); j++) {
            cout << inp << " ";
        }
        
        // Move to the next line
        cout << endl;
    }
}

void number_pat(int row) {
        int current;  // This will store the starting number for each row
    int diagonal = 1;  // This will be used to fill diagonally
    
    for (int i = 1; i <= row; i++) {
        current = i;  // Start with row number
        for (int j = 1; j <= i; j++) {
            cout << current << " ";
            current += (row - j);  // Increment by decreasing diagonal steps
        }
        cout << endl;
    }
}

void binary_pat(int row) {
    for (int i = 1; i <= row; i++) { 
        for (int j = 1; j <= i; j++) { 
            if ((i+j)%2 == 0) {
                cout << "1 ";
            } 
            else {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}

void parallelogram(int row, string inp) {
    for (int i = 1; i <= row; i++) {
        for (int j = 1 ; j <= (row - i) ; j++) {
            cout << " ";
        }
        for ( int j = 1 ; j <= row ; j++) {
            cout << inp << " ";
        }
    cout << endl;
    }
}

void palindrome(int row) {
    for (int i = 1; i <= row ; i++) {
        int j;
        for (j = 1; j <= (row - i) ; j++) {
            cout << "  ";
        }
        int k = i;
        for ( ; j <= row; j++) {
            cout << k-- << " ";
        }
        k = 2;
        for ( ; j <= (row + i - 1); j++) {
            cout << k++ << " ";
        }
        cout << endl;
    }
}

void zigzag( int row,string inp) {
    for (int i = 1; i <= 3; i++) {
    for (int j = 1; j <= row ; j++) {
        if ( (i+j)%4 == 0 || (i == 2) && (j%4 == 0)) {
            cout << inp << " " ;
        }
        else {
        cout << "  ";
        }
    }
    cout << endl;
    }
}