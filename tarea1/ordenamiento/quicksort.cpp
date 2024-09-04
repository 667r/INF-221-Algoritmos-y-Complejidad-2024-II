#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>

using namespace std;
using namespace std::chrono;

// función para crear las particiones que se utilizan dentro del quicksort
int partition(vector<int>& arr, int low, int high)
{
    // elije el pivote  
    int pivot = arr[high];

    // indice del elemento más pequeño
    int i = low - 1;

    // traversa el arreglo y si el elemento es menor que el pivote, lo intercambia
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    // mueve el pivote a la posición correcta
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// funcion que implementa el quicksort
void quickSort(vector<int>& arr, int low, int high)
{
    if (low < high) {
        // indice de partición 
        int pi = partition(arr, low, high);

        // ordena los ementos antes y después de la partición
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// función para leer un vector de un archivo .txt
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

// función para escribir un vector en un archivo .txt
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
    string input_filename = "dataset_100000_1.txt";  // aca se puede cambiar el nombre del archivo de entrada
    string output_filename = "sorted_quick_100000_1.txt";  // lo mismo con el archivo de salida

    vector<int> arr = leerVector(input_filename);

    auto start = high_resolution_clock::now();

    // ordena el vector utilizando quicksort
    quickSort(arr, 0, arr.size() - 1);

    // detiene el reloj
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);

    escribirVector(arr, output_filename);

    cout << "Quick sort completed in " << duration.count() << " microseconds" << endl;

    return 0;
}
