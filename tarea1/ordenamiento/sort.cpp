#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

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
    string output_filename = "sorted_stl_100000_3.txt";  // lo mismo con el de salida

    // leer el vector
    vector<int> arr = leerVector(input_filename);

    auto start = high_resolution_clock::now();

    // ordena utilizando la función sort de la STL de c++
    sort(arr.begin(), arr.end()); 

    // calcula el tiempo que tomó ordenar el vector
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);

    // escribe eñ vector ordenado en un archivo .txt
    escribirVector(arr, output_filename);

    cout << "STL sort completed in " << duration.count() << " microseconds" << endl;

    return 0; 
}
//source del algoritmo>  https://www.geeksforgeeks.org/sort-algorithms-the-c-standard-template-library-stl/