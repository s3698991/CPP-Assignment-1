#include <iostream>
using namespace std;

//Function to calculate Mean
float mean(float arr[], int n) {
	//Calculate sum of array
	float sum = 0;

	for (int i = 0; i < n; i++)
		sum = sum + arr[i];
	return sum / n;    
}
//Function to calculate Xi - Mean
float XiMeanSubstract(float arr[], int n, float y) {
	float sum = 0;

	for (int i = 0; i < n; i++)
		sum = sum + pow((arr[i] - mean(arr, n)), y);
	return sum;
}
//Function to Calculate s (Standard Deviation)
float sDeviation(float arr[], int n) {
	return sqrt(XiMeanSubstract(arr, n, 2) / (n-1));
}
//4B: Function to calculate Mean Absolute Deviation 
float mad(float arr[], int n){
	//Calculate sum of absolute  |Xi - mean|
	float sumAbsolute = 0;

	for (int i = 0; i < n; i++)
		sumAbsolute = sumAbsolute + abs(arr[i] - mean(arr, n));
	//Return MAD
	return sumAbsolute / n;
}
//6B: Function to calculate Skewness
float skewness(float arr[], int n) {
	return XiMeanSubstract(arr, n, 3) / (n * pow(sDeviation(arr, n), 3));
}
//7B: Function to calculate Kurtosis
float kurtosis(float arr[], int n) {
	return (XiMeanSubstract(arr, n, 4) / ((n - 1) * pow((sDeviation(arr, n)), 4)))-3;
}
//Main function
void main() {
	float arr[] = { 3, 2, 1, 4, 6, 9, 2, 7, 11, 5, 15 };
	//Find length of array = Byte size of array divided by byte of object
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << "Standard Deviation is: " << sDeviation(arr, n) << endl;
	cout << "Skewness is: " << skewness(arr, n) << endl;
	cout << "kurtosis is: " << kurtosis(arr, n) << endl;
}