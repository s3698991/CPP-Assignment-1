//Assignment 1: 3B and 5B

#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

// Compute Variance and Standard Deviation of array x
float varianceX(float arr_x[], int& rows) {
    // Compute mean 
    float sum = 0;
    for (int i = 0; i < rows; i++)
        sum += arr_x[i];
    float mean = sum / rows;

    // Compute sum squared differences with mean.
    float sqDiff = 0;
    for (int i = 0; i < rows; i++)
        sqDiff += (arr_x[i] - mean) * (arr_x[i] - mean);
    return sqDiff / rows;
}

float StandardDeviationX(float arr_x[], int rows) {
    return sqrt(varianceX(arr_x, rows));
}

// Compute Variance and Standard Deviation of array y
float varianceY(float arr_y[], int& rows) {
    // Compute mean 
    float sum = 0;
    for (int i = 0; i < rows; i++)
        sum += arr_y[i];
    float mean = sum / rows;

    // Compute sum squared differences with mean.
    float sqDiff = 0;
    for (int i = 0; i < rows; i++)
        sqDiff += (arr_y[i] - mean) * (arr_y[i] - mean);
    return sqDiff / rows;
}


float StandardDeviationY(float arr_y[], int rows) {
    return sqrt(varianceY(arr_y, rows));
}

// Compute Third Quartile 
void ThirdQuartile(float arr_x[], float arr_y[], int rows) {
    sort(arr_x, arr_x + rows);
    sort(arr_y, arr_y + rows);
    float Q3_x = arr_x[(rows * 3 / 4)];
    float Q3_y = arr_y[(rows * 3 / 4)];
    if (rows % 2 == 0) {
        Q3_x = (Q3_x + arr_x[(rows * 3 / 4 - 1)]) / 2;
        Q3_y = (Q3_y + arr_y[(rows * 3 / 4 - 1)]) / 2;
    }
    cout << "Q3_x = "<< Q3_x << "- Q3_y = " << Q3_y << endl;
}

int main() {
    // Example testing 
    float arr_x[] = { 8, 91, 63, 72, 40, 55 };
    float arr_y[] = { 7, 15, 36, 39, 40, 41 };
    int rows = sizeof(arr_x) / sizeof(arr_x[0]);
    cout << "Var_x= " << varianceX(arr_x, rows);
    cout << " - " << "Var_y= " << varianceY(arr_y, rows) << "\n";
    cout << "stdev_x=  " << StandardDeviationX(arr_x, rows);
    cout << " - " << "stdev_y = " << StandardDeviationY(arr_y, rows) << "\n";
    ThirdQuartile(arr_x, arr_y, rows);
    return 0;
}
