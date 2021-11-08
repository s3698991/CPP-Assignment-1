#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <algorithm>
using namespace std;
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
    cout << mod_A << "\n" << mod_B << endl;
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
    cout << median_a << "\n" << median_b << endl;
    mode_cal(arr_a, arr_b, rows);
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
