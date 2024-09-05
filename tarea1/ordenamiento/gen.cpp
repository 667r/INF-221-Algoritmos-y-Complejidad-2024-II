#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

// tamaños de los datasets
vector<int> sizes = {1000, 10000, 100000};

// funcion que genera los datasets  
vector<vector<int>> generate_lists(int size) {
    vector<vector<int>> datasets;

    // lista aleatoria
    vector<int> random_list(size);
    iota(random_list.begin(), random_list.end(), 0);  // llena con 0, 1, 2, ..., size-1
    // crear un generador de números aleatorios basado en Mersenne Twister
    shuffle(random_list.begin(), random_list.end(), mt19937{random_device{}()}); 
    datasets.push_back(random_list);

    // lista ordenada ascendentemente
    vector<int> sorted_list(size);
    iota(sorted_list.begin(), sorted_list.end(), 0);
    datasets.push_back(sorted_list);

    // lista ordenada descendientemente
    vector<int> reverse_list(size);
    iota(reverse_list.begin(), reverse_list.end(), 0);
    reverse(reverse_list.begin(), reverse_list.end());
    datasets.push_back(reverse_list);

    // lista parcialmente ordenada
    vector<int> partial_list(size);
    // llenar todo el vector con valores consecutivos
    iota(partial_list.begin(), partial_list.end(), 0);
    // barajar la segunda mitad del vector
    shuffle(partial_list.begin() + size/2, partial_list.end(), mt19937{random_device{}()});
    datasets.push_back(partial_list);

    return datasets;
}

// funcion para guardar los datasets en archivos .txt
void save_lists(const vector<vector<int>>& datasets, const string& prefix) {
    for (size_t i = 0; i < datasets.size(); ++i) {
        ofstream file(prefix + to_string(i) + ".txt");
        for (const int& num : datasets[i]) {
            file << num << " ";
        }
        file.close();
    }
}

int main() {
    for (int size : sizes) {
        vector<vector<int>> datasets = generate_lists(size);
        save_lists(datasets, "dataset_" + to_string(size) + "_");
    }
    cout << "Listas generadas y guardadas." << endl;
    return 0;
}
