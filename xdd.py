import pandas as pd
import matplotlib.pyplot as plt

# Definir los tamaños de entrada y tiempos de ejecución de los algoritmos
data = {
    'Tamaño de entrada': [1000, 10000, 100000],
    
    # Insertion Sort
    'Insertion Sort - Desordenado': [15, 142062, 14443814],
    'Insertion Sort - Ordenado': [12, 148, 682],
    'Insertion Sort - Reversed': [6254, 284085, 28676698],
    'Insertion Sort - Parcialmente ordenado': [383, 16847, 1557117],
    
    # QuickSort
    'QuickSort - Desordenado': [299, 3857, 34735],
    'QuickSort - Ordenado': [7118, 3241, 52785699],
    'QuickSort - Reversed': [4759, 332330, 32196026],
    'QuickSort - Parcialmente ordenado': [1369, 60939, 5821214],
    
    # MergeSort
    'MergeSort - Desordenado': [862, 8754, 57359],
    'MergeSort - Ordenado': [691, 7010, 46497],
    'MergeSort - Reversed': [775, 5382, 47421],
    'MergeSort - Parcialmente ordenado': [297, 2699, 24999],
    
    # STL Sort
    'STL Sort - Desordenado': [380, 5744, 39479],
    'STL Sort - Ordenado': [159, 2126, 18272],
    'STL Sort - Reversed': [135, 2287, 13660],
    'STL Sort - Parcialmente ordenado': [106, 900, 10663]
}

# Crear un DataFrame con los datos
df = pd.DataFrame(data)

# Guardar el DataFrame en un archivo Excel
file_path = "/mnt/data/sorting_algorithm_results.xlsx"
df.to_excel(file_path, index=False)

# Función para generar gráficos de líneas para cada algoritmo
def plot_algorithm(algorithm_name, save_path):
    plt.figure(figsize=(10, 6))
    plt.plot(df['Tamaño de entrada'], df[f'{algorithm_name} - Desordenado'], label='Desordenado', marker='o')
    plt.plot(df['Tamaño de entrada'], df[f'{algorithm_name} - Ordenado'], label='Ordenado', marker='o')
    plt.plot(df['Tamaño de entrada'], df[f'{algorithm_name} - Reversed'], label='Reversed', marker='o')
    plt.plot(df['Tamaño de entrada'], df[f'{algorithm_name} - Parcialmente ordenado'], label='Parcialmente ordenado', marker='o')
    
    plt.xlabel('Tamaño de entrada')
    plt.ylabel('Tiempo de ejecución (µs)')
    plt.title(f'Tiempos de ejecución - {algorithm_name}')
    plt.legend()
    plt.grid(True)
    plt.savefig(save_path)
    plt.close()

# Crear gráficos para cada algoritmo
plot_algorithm('Insertion Sort', '/mnt/data/insertion_sort_times.png')
plot_algorithm('QuickSort', '/mnt/data/quicksort_times.png')
plot_algorithm('MergeSort', '/mnt/data/mergesort_times.png')
plot_algorithm('STL Sort', '/mnt/data/stl_sort_times.png')

file_path
