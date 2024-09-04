#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

// funcion para leer una matriz de un archivo .txt
vector<vector<int>> read_matrix(const string& filename, int rows, int cols) {
    vector<vector<int>> matrix(rows, vector<int>(cols));
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Error: Could not open file " << filename << endl;
        exit(1);
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            file >> matrix[j][i];
        }
    }

    file.close();
    return matrix;
}

vector<vector<int>> read_matrixA(const string& filename, int rows, int cols) {
    vector<vector<int>> matrix(rows, vector<int>(cols));
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Error: Could not open file " << filename << endl;
        exit(1);
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            file >> matrix[i][j];
        }
    }

    file.close();
    return matrix;
}

// funcion que implementa el algoritmo iterativo cubico de multiplicacion de matrices (3 for anidados)
// pero antes habiendo traspuesto la matriz B (cambiando el orden de lectura de las matrices en la funcion read_matrix)
vector<vector<int>> multiply(const vector<vector<int>>& A, const vector<vector<int>>& B, int N) {
    vector<vector<int>> C(N, vector<int>(N, 0));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[j][k];
            }
        }
    }

    return C;
}

// funcion para guardar una matriz en un archivo .txt
void save_matrix(const vector<vector<int>>& matrix, const string& filename) {
    ofstream file(filename);

    if (!file.is_open()) {
        cerr << "Error: Could not open file " << filename << endl;
        exit(1);
    }

    for (const auto& row : matrix) {
        for (const auto& elem : row) {
            file << elem << " ";
        }
        file << endl;
    }

    file.close();
}

int main() {
    
    int N = 256;
    string filename_A = "matrix_256x512_A.txt";
    string filename_B = "matrix_512x256_B.txt";
    string filename_C = "matrix_I_C2.txt"; // archivo de salida

    vector<vector<int>> A = read_matrixA(filename_A, N, N);
    vector<vector<int>> B = read_matrix(filename_B, N, N);

    auto start = high_resolution_clock::now();

    vector<vector<int>> C = multiply(A, B, N);

    auto stop = high_resolution_clock::now();

    save_matrix(C, filename_C);

    // calcula la duracion de la multiplicacion de matrices
    auto duration = duration_cast<microseconds>(stop - start);

    // imprimer la duracion
    cout << "Time taken by matrix multiplication: " << duration.count() << " microseconds" << endl;

    return 0;
}

// source> https://www.geeksforgeeks.org/strassens-matrix-multiplication/
// Time Complexity: T(N) = 7T(N/2) + O(N^2) => O(N^Log7)
// which is approximately O(N^2.8074) Code Contributed By:
// lucasletum
