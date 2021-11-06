/* C implementation QuickSort */
#include <iostream>
using namespace std;

// A utility function to swap two elements
void swap(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}

/* This function takes last element as pivot, places
 * the pivot element at its correct position in sorted
 * array, and places all smaller (smaller than pivot)
 * to left of pivot and all greater elements to right
 * of pivot */
int partition(int arr[], int low, int high) {
	int pivot = arr[high];
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++) {
		if (arr[j] <= pivot) {
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

/* The main function that implements QuickSort
 * arr[] --> Array to be sorted,
 * low --> Starting index,
 * high --> Ending index
 */
void quickSort(int arr[], int low, int high) {
	if (low < high) {
		/* pi is partitioning index, arr[p] is now
		at right place */
		int pi = partition(arr, low, high);

		// Separately sort elements before
		// partition and after partition
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

void print_array(int arr[], int size) {
	int i;
	for (i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

// A function to calculate mean  
float mean(float arr[], int n) // n is number of elements in the set
{
	float sum = 0;
	for (int i = 0; i < n; i++)
		sum = sum + arr[i];
	return sum / n;
}

// A function to calculate covariance of 2 set 
float covariance(float arr1[], float arr2[], int n) // n is number of elements in each of the sets, they have to be equal to find the covariance
{
	float sum = 0;
	for (int i = 0; i < n; i++)
		sum = sum + (arr1[i] - mean(arr1, n)) * (arr2[i] - mean(arr2, n));
	return sum / (n - 1);
}



// Driver program to test above functions
int main(int argc, char* argv[])
{
	int* arr = NULL;
	int n;
	if (argc == 2)
		n = atoi(argv[1]);
	else
		n = 5;

	arr = new int[n];
	for (int i = 0; i < n; i++)
		arr[i] = (i * (i + 1)) % n;

	cout << "Non-sorted array: \n";
	print_array(arr, n);
	quickSort(arr, 0, n - 1);
	cout << "Sorted array: \n";
	print_array(arr, n);

	delete[] arr;

//Hoang's part: Calculate Covairance

	// Example set of data
	float arr1[] = { 2.1, 3.2, 15.6, 9.9, 20.4};
	int n1 = sizeof(arr1) / sizeof(arr1[0]);	// To find the amount of element in a array 1 

	float arr2[] = { 4.9, 6.0, 23.5, 7.7, 15.15};
	int n2 = sizeof(arr2) / sizeof(arr2[0]);	// To find the amount of element in a array 2

	if (n1 == n2)
		cout <<"cov(x_y)= " << covariance(arr1, arr2, n1) << endl;
	else
		cout << "Can not find covariance because there needs to be the same amount of elements in each set." << endl;

	return 0;
}
