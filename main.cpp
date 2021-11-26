#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <math.h>
using namespace std;

// Function to calculate Mean(Average)
float cal_mean(float arr[], int n)
{
    float sumOfArr = 0;
    for (int i = 0; i < n; i++)
        sumOfArr = sumOfArr + arr[i];
    return sumOfArr / n;
}

//Function to calculate Sigma of (Xi-mean)^y
float XiMeanSubstract(float arr[], int n, float y) {
    float sum = 0;

    for (int i = 0; i < n; i++)
        sum = sum + pow((arr[i] - cal_mean(arr, n)), y);
    return sum;
}

//1B: Function to calculate median
void median_cal(float arr_a[], float arr_b[], int rows) {
    float median_a, median_b;
    sort(arr_a, arr_a + rows);
    sort(arr_b, arr_b + rows);
    median_a = arr_a[(rows / 2)];
    median_b = arr_b[(rows / 2)];

    if (rows % 2 == 0) {
        median_a = (median_a + arr_a[rows / 2 - 1]) / 2;
        median_b = (median_b + arr_b[rows / 2 - 1]) / 2;
    }

    string final = "median_x= " + to_string(median_a) + " - " + "median_y= " + to_string(median_b) + "\n";
    cout << final;
}

//2B: Function to calculate mode
void mode_cal(const float ar_a[], const float ar_b[], int rows) {
    float mod_A = 0;
    float mod_B = 0;
    int count_a = 0;
    int count_b = 0;

    for (int j = 0; j < rows; j++) {
        float temp_ele_a = ar_a[j];
        int temp_count_a = 0;
        for (int p = 0; p < rows; p++)
            if (ar_a[p] == temp_ele_a)
                temp_count_a++;
        if (temp_count_a > count_a) {
            mod_A = temp_ele_a;
            count_a = temp_count_a;
        }
    }
    for (int j = 0; j < rows; j++) {
        float temp_ele_b = ar_b[j];
        int temp_count_b = 0;
        for (int p = 0; p < rows; p++)
            if (ar_b[p] == temp_ele_b)
                temp_count_b++;
        if (temp_count_b > count_b) {
            mod_B = temp_ele_b;
            count_b = temp_count_b;
        }
    }

    string final = "mode_x= " + to_string(mod_A) + " - " + "mode_y= " + to_string(mod_B) + '\n';
    cout << final;
}

//3B: Function to Calculate Variance
void cal_variance(float arrX[], float arrY[], int n) {
    float varX = XiMeanSubstract(arrX, n, 2) / (n - 1);
    float varY = XiMeanSubstract(arrY, n, 2) / (n - 1);

    cout << "var_x= " + to_string(varX) + " - " + "var_y= " + to_string(varY) << endl;
}

//3B: Function to Calculate s (Standard Deviation)
float sDeviation(float arr[], int n) {
    return sqrt(XiMeanSubstract(arr, n, 2) / (n - 1));
}

//4B: Function to calculate Mean Absolute Deviation
void mad(float arrX[], float arrY[], int n) {
    //Calculate sum of absolute  |Xi - mean|
    float sumAbsoluteX = 0;
    float sumAbsoluteY = 0;

    for (int i = 0; i < n; i++)
        sumAbsoluteX = sumAbsoluteX + abs(arrX[i] - cal_mean(arrX, n));

    for (int i = 0; i < n; i++)
        sumAbsoluteY = sumAbsoluteY + abs(arrY[i] - cal_mean(arrY, n));
    //Return MAD
    cout << "mad_x= " + to_string(sumAbsoluteX / n) + " - " + "mad_y= " + to_string(sumAbsoluteY / n) << endl;
}

//5B: Function to calculate Third Quartile 
void ThirdQuartile(float arr_x[], float arr_y[], int rows) {
    sort(arr_x, arr_x + rows);
    sort(arr_y, arr_y + rows);

    float Q3_x = arr_x[(rows * 3 / 4)];
    float Q3_y = arr_y[(rows * 3 / 4)];

    if (rows % 2 == 0) {
        Q3_x = (Q3_x + arr_x[(rows * 3 / 4 - 1)]) / 2;
        Q3_y = (Q3_y + arr_y[(rows * 3 / 4 - 1)]) / 2;
    }

    cout << "Q3_x = " << Q3_x << " - Q3_y = " << Q3_y << endl;
}

//6B: Function to calculate Skewness
void skewness(float arrX[], float arrY[], int n) {
    float aX = sDeviation(arrX, n);
    float bX = XiMeanSubstract(arrX, n, 3) / (n * pow(aX, 3));

    float aY = sDeviation(arrY, n);
    float bY = XiMeanSubstract(arrY, n, 3) / (n * pow(aY, 3));

    cout << "stdev_x= " + to_string(aX) + " - " + "stdev_y= " + to_string(aY) << endl;
    cout << "skew_x= " + to_string(bX) + " - " + "skew_y= " + to_string(bY) << endl;
}
//7B: Function to calculate Kurtosis
void kurtosis(float arrX[], float arrY[], int n) {
    float cX = (XiMeanSubstract(arrX, n, 4) / ((n - 1) * pow((sDeviation(arrX, n)), 4))) - 3;
    float cY = (XiMeanSubstract(arrY, n, 4) / ((n - 1) * pow((sDeviation(arrY, n)), 4))) - 3;
    cout << "kurt_x= " + to_string(cX) + " - " + "kurt_y= " + to_string(cY) << endl;
}

//1C: Function to calculate Covariance
void cal_covariance(float arr1[], float arr2[], int n)
{
    float sum = 0;

    for (int i = 0; i < n; i++)
        sum = sum + (arr1[i] - cal_mean(arr1, n)) * (arr2[i] - cal_mean(arr2, n)); //This is the formula to calculate covariance

    cout << "cov(x_y)= " + to_string(sum / (n - 1)) << endl;
}

//2C: Function to calculate Correlation Coefficient
float cal_correlationCoefficient(float arr1[], float arr2[], int n)
{

    float sum_arr1 = 0, sum_arr2 = 0, sumOfArr1XArr2 = 0;
    float squareSum_arr1 = 0, squareSum_arr2 = 0;

    for (int i = 0; i < n; i++)
    {
        //The sum of elements of 1st and 2nd set .
        sum_arr1 = sum_arr1 + arr1[i];
        sum_arr2 = sum_arr2 + arr2[i];

        //The sum of elements of 1st array * elements of 2nd set.
        sumOfArr1XArr2 = sumOfArr1XArr2 + arr1[i] * arr2[i];

        //The sum of square of each elements in each sets.
        squareSum_arr1 = squareSum_arr1 + arr1[i] * arr1[i];
        squareSum_arr2 = squareSum_arr2 + arr2[i] * arr2[i];
    }

    // Calculate correlation coefficient using this formula:
    float co_co = (n * sumOfArr1XArr2 - sum_arr1 * sum_arr2)
        / sqrt((n * squareSum_arr1 - sum_arr1 * sum_arr1) * (n * squareSum_arr2 - sum_arr2 * sum_arr2));

    return co_co;
}

//3C: Function to calculate linear regreesion
void cal_linearRegression(float arr1[], float arr2[], int n)
{
    float stdevX = sDeviation(arr1, n);
    float stdevY = sDeviation(arr2, n);
    float co_coXY = cal_correlationCoefficient(arr1, arr2, n);
    float a = (co_coXY * stdevY) / stdevX; //using the formula in the requirement
    float meanX = cal_mean(arr1, n);
    float meanY = cal_mean(arr2, n);
    float b = meanY - a * meanX; // using the formula in the requirement

    cout << "r(x_y)= " + to_string(co_coXY) << endl;
    cout << "y= " << a << "x+ " << b << endl;
}

void store_data(int rows, const string& file_name) {
    string data_a, data_b;
    float* arr_a = new float[rows];
    float* arr_b = new float[rows];
    ifstream file(file_name);
    if (file.is_open()) {
        string line;
        int i = 0;
        getline(file, line);
        while (!file.eof()) {
            getline(file, data_a, ',');
            if (data_a.empty()) {
                data_a = "0";
            }
            arr_a[i] = stof(data_a);
            getline(file, data_b, '\n');
            if (data_b.empty()) {
                data_b = "0";
            }
            arr_b[i] = stof(data_b);
            i++;
        }
        file.close();
    }
    else {
        cerr << "Error: File cannot readable" << endl;
    }
    median_cal(arr_a, arr_b, rows);
    mode_cal(arr_a, arr_b, rows);
    cal_variance(arr_a, arr_b, rows);
    ThirdQuartile(arr_a, arr_b, rows);
    mad(arr_a, arr_b, rows);
    skewness(arr_a, arr_b, rows);
    kurtosis(arr_a, arr_b, rows);
    cal_covariance(arr_a, arr_b, rows);
    cal_correlationCoefficient(arr_a, arr_b, rows);
    cal_linearRegression(arr_a, arr_b, rows);
    delete[] arr_a;
    delete[] arr_b;
}

void read_file(const string file_name) {
    int row = -1;
    ifstream file;
    file.open(file_name);
    if (file.is_open()) {
        string line;
        while (!file.eof()) {
            getline(file, line);
            row++;
        }
    }
    else {
        cerr << "Error: File cannot be read";
        exit(1);
    }
    file.close();
    store_data(row, file_name);
}

int main() {
    string file_name;
    cout << "Enter the file name:";
    cin >> file_name;
    read_file(file_name);
}

