#include <iostream>
using namespace std;


void generate_seating(int** seating, int rows, int cols) {   // int** allocate memory of rows & columns since the 2d array isn't a fixed value
    cout << "Seating Arrangement: " << endl;
    for (int i = 0; i < rows; i++) {                        // accessing each row on the seating chart
        for (int j = 0; j < cols; j++) {                    // accessing each col on the seating char
            if (seating[i][j] == 0) {
                cout << "O ";                               // available seating
            } else {
                cout << "X ";                               // reserved seating
            }
        }
        cout << endl;                                       // next row
    }
}
void reserve_seat(int** seating, int row, int col) {
    if (seating[row][col] == 0) {                           // if seat available
        seating[row][col] = 1;                              // if seat reserved
    } else {
        cout << "Seat at row: " << row << ", col:  " << col << " is already reserved try again." << endl;
    }
}
int main() {
    int Urows, Ucols;

    // ask user for number of rows and columns
    cout << "Enter number of rows: ";
    cin >> Urows;
    cout << "Enter number of seats per row: ";
    cin >> Ucols;

    // creating a 2D array for seating (using dynamic allocation)
    int** seating = new int*[Urows];
    for (int i = 0; i < Urows; i++) {
        seating[i] = new int[Ucols]{0};                     // initialize all seats to be avalible
    }

    // generate and display the initial seating arrangement
    generate_seating(seating, Urows, Ucols);

    // allow user to reserve seats (using while loop)
    while (true) {
        cout << "Enter seat to reserve by row (or -9 to exit): ";
        int rRow;
        cin >> rRow;
        if (rRow == -9) break; // Exit condition

        cout << "Enter seat to reserve by column: ";
        int rCol;
        cin >> rCol;

        if (rRow >= 0 && rRow < Urows && rCol >= 0 && rCol < Ucols) {               // to check if the reserved seat is invalid
            reserve_seat(seating, rRow, rCol);
        } else {
            cout << "Invalid seat position try again. \n" << endl;
        }

        // Display the updated seating arrangement after the reservation
        generate_seating(seating, Urows, Ucols);
    }
    
    // preventing any crashes (using free dynamically allocated memory)
    for (int i = 0; i < Urows; i++) {
        delete[] seating[i];
    }
    delete[] seating;

    return 0;
}
