#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>

using namespace std;
using namespace std::chrono;

/* Function to sort array using insertion sort */
void insertionSort(vector<int>& arr)
{
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1], that are
        // greater than key, to one position ahead
        // of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

/* Function to read a vector from a .txt file */
vector<int> readVectorFromFile(const string& filename)
{
    vector<int> arr;
    ifstream file(filename);
    if (file.is_open()) {
        int num;
        while (file >> num) {
            arr.push_back(num);
        }
        file.close();
    } else {
        cerr << "Unable to open file: " << filename << endl;
    }
    return arr;
}

/* Function to write a vector to a .txt file */
void writeVectorToFile(const vector<int>& arr, const string& filename)
{
    ofstream file(filename);
    if (file.is_open()) {
        for (const int& num : arr) {
            file << num << " ";
        }
        file.close();
    } else {
        cerr << "Unable to open file: " << filename << endl;
    }
}

// Driver method
int main()
{
    string input_filename = "dataset_1000_0.txt";  // Change the filename as needed
    string output_filename = "sorted_dataset_1000_0.txt";  // Change the output filename as needed

    // Read the vector from the file
    vector<int> arr = readVectorFromFile(input_filename);

    auto start = high_resolution_clock::now();

    // Sort the vector using Insertion Sort
    insertionSort(arr);

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);

    // Write the sorted vector to the output file
    writeVectorToFile(arr, output_filename);

    cout << "Sorting completed in " << duration.count() << " microseconds" << endl;

    return 0;
}
