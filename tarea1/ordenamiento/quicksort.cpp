#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>

using namespace std;
using namespace std::chrono;

int partition(vector<int>& arr, int low, int high)
{
    // Choose the pivot
    int pivot = arr[high];

    // Index of smaller element
    int i = low - 1;

    // Traverse the array and move smaller elements on the left side
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    // Move the pivot element to the correct position
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// QuickSort function implementation
void quickSort(vector<int>& arr, int low, int high)
{
    if (low < high) {
        // Partitioning index, arr[p] is now at the right place
        int pi = partition(arr, low, high);

        // Recursively sort elements before partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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

// Driver code
int main()
{
    string input_filename = "dataset_1000_0.txt";  // Change the filename as needed
    string output_filename = "sorted_quick_1000_0.txt";  // Change the output filename as needed

    // Read the vector from the file
    vector<int> arr = readVectorFromFile(input_filename);

    auto start = high_resolution_clock::now();

    // Sort the vector using Quick Sort
    quickSort(arr, 0, arr.size() - 1);

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);

    // Write the sorted vector to the output file
    writeVectorToFile(arr, output_filename);

    cout << "Quick sort completed in " << duration.count() << " microseconds" << endl;

    return 0;
}
