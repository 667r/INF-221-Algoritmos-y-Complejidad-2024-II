#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>

using namespace std;
using namespace std::chrono;

// mergea dos sub arreglos de arr[]
// el primer sub arreglo es arr[left..mid]
// el segundo sub arreglo es arr[mid+1..right]
void merge(vector<int>& arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // creo vectores temporales
    vector<int> L(n1), R(n2);

    // copia los datos a los vectores temporales L[] y R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0;
    int k = left;

    // mergea los vectores temporales en arr[left..right]
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // copia los elementos restantes de L[], si hay alguno
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // copia los elementos restantes de R[], si hay alguno
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// funcion de merge sort
void mergeSort(vector<int>& arr, int left, int right)
{
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
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

// funcion para escribir un vector en un archivo .txt
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
    string input_filename = "dataset_100000_3.txt";  // aca se puede cambiar el nombre del archivo de entrada
    string output_filename = "sorted_merge_100000_3.txt";  // lo mismo con el de salida

    vector<int> arr = leerVector(input_filename);

    auto start = high_resolution_clock::now();

    // ordena el vector utilizando merge sort
    mergeSort(arr, 0, arr.size() - 1);

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);

    // escribe el vector ordenado en un archivo .txt
    escribirVector(arr, output_filename);

    cout << "Merge sort completed in " << duration.count() << " microseconds" << endl;

    return 0;
}
