#include <iostream>
#include <fstream>
#include <vector>
#include <random>

using namespace std;

vector<pair<int, int>> sizes = {{64, 64}, {128, 128}, {256, 256}, {512, 512}, {1024, 1024}, {128, 256}, {256, 512}};

// funcion generadora de matrices
vector<vector<int>> generate_matrix(int rows, int cols) {
    vector<vector<int>> matrix(rows, vector<int>(cols));

    // crear un dispositivo aleatorio para obtener una semilla inicial
    random_device rd;
    
    // crear un generador de números aleatorios basado en Mersenne Twister
    mt19937 gen(rd());
    
    // definir una distribución uniforme para generar números enteros entre 0 y 99
    uniform_int_distribution<> dis(0, 99);

    for (int i = 0; i < rows; ++i) {  
        for (int j = 0; j < cols; ++j) {  
            matrix[i][j] = dis(gen);  // asignar un número aleatorio a cada posición de la matriz
        }
    }

    return matrix;
}

// funcion para guardar una matriz en un archivo .txt
void save_matrix(const vector<vector<int>>& matrix, const string& filename) {
    ofstream file(filename);
    for (const auto& row : matrix) {
        for (const int& num : row) {
            file << num << " ";
        }
        file << endl;
    }
    file.close();
}

int main() {
    for (const auto& size : sizes) {
        int rows = size.first;
        int cols = size.second;

        vector<vector<int>> matrix_A = generate_matrix(rows, cols);
        vector<vector<int>> matrix_B = generate_matrix(cols, rows);

        save_matrix(matrix_A, "matrix_" + to_string(rows) + "x" + to_string(cols) + "_A.txt");
        save_matrix(matrix_B, "matrix_" + to_string(cols) + "x" + to_string(rows) + "_B.txt");
    }
    cout << "Matrices generadas y guardadas." << endl;
    return 0;
}
