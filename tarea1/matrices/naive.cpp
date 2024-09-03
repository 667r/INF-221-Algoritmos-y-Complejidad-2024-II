#include <iostream>
#include <fstream>
#include <vector>
#include <chrono> // Include chrono for timing

using namespace std;
using namespace std::chrono;

// Function to read a matrix from a .txt file
vector<vector<int>> read_matrix(const string& filename, int rows, int cols) {
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

// Function to multiply two matrices
vector<vector<int>> multiply(const vector<vector<int>>& A, const vector<vector<int>>& B, int N) {
    vector<vector<int>> C(N, vector<int>(N, 0));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return C;
}

// Function to save a matrix to a .txt file
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
    string filename_C = "matrix_I_C1.txt"; // File to store the result

    vector<vector<int>> A = read_matrix(filename_A, N, N);
    vector<vector<int>> B = read_matrix(filename_B, N, N);

    // Start the timer
    auto start = high_resolution_clock::now();

    // Perform the matrix multiplication
    vector<vector<int>> C = multiply(A, B, N);

    auto stop = high_resolution_clock::now();

    // Save the result matrix to a file
    save_matrix(C, filename_C);

    // Calculate the duration
    auto duration = duration_cast<microseconds>(stop - start);

    // Print the duration
    cout << "Time taken by matrix multiplication: " << duration.count() << " microseconds" << endl;

    return 0;
}
//src> https://www.geeksforgeeks.org/strassens-matrix-multiplication/
