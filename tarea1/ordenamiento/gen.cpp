#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

// Tamaños de las listas
vector<int> sizes = {1000, 10000, 100000, 1000000};

// Función para generar listas
vector<vector<int>> generate_lists(int size) {
    vector<vector<int>> datasets;

    // Lista completamente desordenada
    vector<int> random_list(size);
    iota(random_list.begin(), random_list.end(), 0);  // Llena con 0, 1, 2, ..., size-1
    shuffle(random_list.begin(), random_list.end(), mt19937{random_device{}()});
    datasets.push_back(random_list);

    // Lista ordenada ascendentemente
    vector<int> sorted_list(size);
    iota(sorted_list.begin(), sorted_list.end(), 0);
    datasets.push_back(sorted_list);

    // Lista ordenada descendente
    vector<int> reverse_list(size);
    iota(reverse_list.begin(), reverse_list.end(), 0);
    reverse(reverse_list.begin(), reverse_list.end());
    datasets.push_back(reverse_list);

    // Lista semi-ordenada
    vector<int> partial_list(size);
    iota(partial_list.begin(), partial_list.begin() + size/2, 0); // Mitad ordenada
    shuffle(partial_list.begin() + size/2, partial_list.end(), mt19937{random_device{}()});
    datasets.push_back(partial_list);

    return datasets;
}

// Función para guardar las listas en archivos
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
