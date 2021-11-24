//Assignment 1: 3B and 5B

#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

// Compute Variance and Standard Deviation
float variance(float arr[], int& rows) {
    // Compute mean 
    float sum = 0;
    for (int i = 0; i < rows; i++)
        sum += arr[i];
    float mean = sum / rows;

    // Compute sum squared differences with mean.
    float sqDiff = 0;
    for (int i = 0; i < rows; i++)
        sqDiff += (arr[i] - mean) * (arr[i] - mean);
    return sqDiff / rows;
}

float StandardDeviation(float arr[], int rows) {
    return sqrt(variance(arr, rows));
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
    cout << "Var_x= " << variance(arr_x, rows);
    cout << " - " << "Var_y= " << variance(arr_y, rows) << "\n";
    cout << "stdev_x=  " << StandardDeviation(arr_x, rows);
    cout << " - " << "stdev_y = " << StandardDeviation(arr_y, rows) << "\n";
    ThirdQuartile(arr_x, arr_y, rows);
    return 0;
}
