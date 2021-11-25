#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <math.h>
using namespace std;

float cal_mean(float arr[], int n) // n is number of elements in the set
{
    float sumOfArr = 0;
    for (int i = 0; i < n; i++)
        sumOfArr = sumOfArr + arr[i];
    return sumOfArr / n;
}
float XiMeanSubstract(float arr[], int n, float y) {
    float sum = 0;

    for (int i = 0; i < n; i++)
        sum = sum + pow((arr[i] - cal_mean(arr, n)), y);
    return sum;
}
//Function to Calculate s (Standard Deviation)

float sDeviation(float arr[], int n) {
    return sqrt(XiMeanSubstract(arr, n, 2) / (n-1));
}
//4B: Function to calculate Mean Absolute Deviation
void mad(float arr[], int n){
    //Calculate sum of absolute  |Xi - mean|
    float sumAbsolute = 0;

    for (int i = 0; i < n; i++)
        sumAbsolute = sumAbsolute + abs(arr[i] - cal_mean(arr, n));
    //Return MAD
    cout<<"Mean Absolute Deviation is: " + to_string( sumAbsolute / n)<<endl;
}

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

//6B: Function to calculate Skewness
void skewness(float arr[], int n) {
    float b = XiMeanSubstract(arr, n, 3) / (n * pow(sDeviation(arr, n), 3));
    float a = sDeviation(arr,n);
    cout<< "Standard Deviation is: " + to_string(a) + "\n" << "Skewness is: "+ to_string(b) <<endl;
}
//7B: Function to calculate Kurtosis
void kurtosis(float arr[], int n) {
    cout<< "kurtosis is: " + to_string((XiMeanSubstract(arr, n, 4) / ((n - 1) * pow((sDeviation(arr, n)), 4)))-3)<<endl;
}


void cal_covariance(float arr1[], float arr2[], int n) // n is number of elements in each of the sets
{
    float sum = 0;
    for (int i = 0; i < n; i++)
        sum = sum + (arr1[i] - cal_mean(arr1, n)) * (arr2[i] - cal_mean(arr2, n)); //This is the formula to calculate covariance
    cout <<"cov(x_y)= " + to_string(sum / (n - 1)) <<endl;
}

void cal_correlationCoefficient(float arr1[], float arr2[], int n)
{

    float sum_arr1 = 0, sum_arr2 = 0, sumOfArr1XArr2 = 0;
    float squareSum_arr1 = 0, squareSum_arr2 = 0;

    for (int i = 0; i < n; i++)
    {
        //The sum of elements of 1st and 2nd set .
        sum_arr1 = sum_arr1 + arr1[i];
        sum_arr2 = sum_arr2 + arr2[i];

        // sum of elements of 1st array * elements of 2nd set.
        sumOfArr1XArr2 = sumOfArr1XArr2 + arr1[i] * arr2[i];

        // sum of square of each elements in each sets.
        squareSum_arr1 = squareSum_arr1 + arr1[i] * arr1[i];
        squareSum_arr2 = squareSum_arr2 + arr2[i] * arr2[i];
    }

    // Calculate correlation coefficient using this formula:
    float co_co =(n * sumOfArr1XArr2 - sum_arr1 * sum_arr2)
                 / sqrt((n * squareSum_arr1 - sum_arr1 * sum_arr1) * (n * squareSum_arr2 - sum_arr2 * sum_arr2));
    cout <<"r(x_y)= " + to_string(co_co)<<endl;
}
void mode_cal (const float ar_a[], const float ar_b [], int rows) {
    float mod_A = 0;
    float mod_B = 0;
    int count_a = 0;
    int count_b = 0;
    for (int j = 0; j < rows; j++) {
        float temp_ele_a = ar_a[j];
        int temp_count_a = 0;
        for (int p = 0 ; p < rows; p++)
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
        for (int p = 0 ; p < rows; p++)
            if (ar_b[p] == temp_ele_b)
                temp_count_b++;
        if (temp_count_b > count_b) {
            mod_B = temp_ele_b;
            count_b = temp_count_b;
        }
    }
    string final = "X= " + to_string(mod_A)+ "; " + "Y= " + to_string(mod_B) + '\n';
    cout << final;
}
void median_cal(float arr_a[], float arr_b [], int rows) {
    float median_a, median_b;
    sort(arr_a, arr_a + rows);
    sort(arr_b, arr_b + rows);
    median_a = arr_a[(rows / 2)];
    median_b = arr_b[(rows / 2)];
    if (rows % 2 == 0) {
        median_a = (median_a + arr_a[rows / 2 - 1]) / 2;
        median_b = (median_b + arr_b[rows / 2 - 1]) / 2;
    }
    string final = "X= " + to_string(median_a)+ "; " + "Y= " + to_string(median_b) + "\n";
    cout << final;
}
void store_data(int rows, const string& file_name) {
    string data_a, data_b;
    float arr_a [rows];
    float arr_b [rows];
    ifstream file(file_name);
    if (file.is_open()) {
        string line;
        int i = 0;
        getline(file, line);
        while (!file.eof()){
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
    mode_cal(arr_a,arr_b,rows);
    ThirdQuartile(arr_a, arr_b, rows);
    mad(arr_a,rows);
    mad(arr_b,rows);
    skewness(arr_a,rows);
    skewness(arr_b,rows);
    kurtosis(arr_a,rows);
    kurtosis(arr_b,rows);
    cal_covariance(arr_a, arr_b, rows);
    cal_correlationCoefficient(arr_a, arr_b, rows);
}

void read_file(const string file_name){
    int row = -1;
    ifstream file;
    file.open(file_name);
    if (file.is_open()) {
        string line;
        while(!file.eof()) {
            getline(file,line);
            row++;
        }
    }
    else{
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
