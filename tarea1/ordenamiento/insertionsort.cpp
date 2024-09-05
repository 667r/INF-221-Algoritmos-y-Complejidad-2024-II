#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>

using namespace std;
using namespace std::chrono;

// funcion para ordenar un vector utilizando insertion sort
void insertionSort(vector<int>& arr)
{
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        // mueve los elementos del arreglo que son
        // mas grandes que key a una posición adelante
        // que la actual.
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// funcion para leer un vector de un archivo .txt
vector<int> leerVector(const string& filename)
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
        cerr << "No se puede abrir el archivo: " << filename << endl;
    }
    return arr;
}

// funcion para escribir un vector a un archivo .txt
void escribirVector(const vector<int>& arr, const string& filename)
{
    ofstream file(filename);
    if (file.is_open()) {
        for (const int& num : arr) {
            file << num << " ";
        }
        file.close();
    } else {
        cerr << "No se puede abrir el archivo: " << filename << endl;
    }
}

int main()
{
    string input_filename = "dataset_1000_3.txt";          // aca se puede cambiar el nombre del archivo de entrada
    string output_filename = "sorted_dataset_1000_3.txt";  // lo mismo con el de salida

    vector<int> arr = leerVector(input_filename);

    auto start = high_resolution_clock::now();

    // ordena el vector utilizando insertion sort
    insertionSort(arr);

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);

    escribirVector(arr, output_filename);

    cout << "Sorting completed in " << duration.count() << " microseconds" << endl;

    return 0;
}

// source del algoritmo: https://www.geeksforgeeks.org/insertion-sort-algorithm/