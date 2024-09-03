#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

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
    string input_filename = "dataset_100000_0.txt";  // Change the filename as needed
    string output_filename = "sorted_stl_100000_0.txt";  // Change the output filename as needed

    // Read the vector from the file
    vector<int> arr = readVectorFromFile(input_filename);

    auto start = high_resolution_clock::now();

    // Sort the vector using STL sort
    sort(arr.begin(), arr.end());

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);

    // Write the sorted vector to the output file
    writeVectorToFile(arr, output_filename);

    cout << "STL sort completed in " << duration.count() << " microseconds" << endl;

    return 0; 
}

