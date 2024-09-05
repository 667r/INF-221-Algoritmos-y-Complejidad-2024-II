#include<bits/stdc++.h>
using namespace std;

// función auxiliar para intercambiar los valores a los que apuntan dos punteros
void swapValue(int *a, int *b)
{
    int *temp = a;  // Almacena el valor de 'a' en un temporal
    a = b;  // Asigna el valor de 'b' a 'a'
    b = temp;  // Asigna el valor temporal a 'b'
    return;
}

// función auxiliar para intercambiar los valores a los que apuntan dos punteros
void InsertionSort(int arr[], int *begin, int *end)
{
    // Obtener los índices izquierdo y derecho del subarreglo a ordenar
    int left = begin - arr;
    int right = end - arr;

    // Recorre desde el segundo elemento hasta el final del subarreglo
    for (int i = left + 1; i <= right; i++)
    {
        int key = arr[i];  // Almacena el valor actual
        int j = i - 1;

        /* Mueve los elementos de arr[0..i-1] que son mayores que 'key'
           a una posición adelante de su posición actual */
        while (j >= left && arr[j] > key)
        {
            arr[j + 1] = arr[j];  // Desplaza el elemento hacia la derecha
            j = j - 1;
        }
        arr[j + 1] = key;  // Inserta 'key' en su posición correcta
    }

    return;
}

// función para particionar el arreglo y devolver el punto de partición
int* Partition(int arr[], int low, int high)
{
    int pivot = arr[high];  // Selecciona el pivote como el último elemento
    int i = (low - 1);  // Índice del elemento más pequeño

    // Recorre los elementos del arreglo
    for (int j = low; j <= high - 1; j++)
    {
        // Si el elemento actual es menor o igual al pivote
        if (arr[j] <= pivot)
        {
            i++;  // Incrementa el índice de los elementos más pequeños
            swap(arr[i], arr[j]);  // Intercambia los elementos
        }
    }
    swap(arr[i + 1], arr[high]);  // Coloca el pivote en su posición correcta
    return (arr + i + 1);  // Devuelve el puntero al pivote
}

// funcion que encuentra el valor medio entre tres valores
int *MedianOfThree(int *a, int *b, int *c)
{
    // encuentra el valor mediano entre a, b y c
    if (*a < *b && *b < *c)
        return (b);

    if (*a < *c && *c <= *b)
        return (c);

    if (*b <= *a && *a < *c)
        return (a);

    if (*b < *c && *c <= *a)
        return (c);

    if (*c <= *a && *a < *b)
        return (a);

    if (*c <= *b && *b <= *c)
        return (b);
}

// funcion auxiliar para el introsort
void IntrosortUtil(int arr[], int *begin, int *end, int depthLimit)
{
    // Calcula el tamaño del subarreglo
    int size = end - begin;

    // Si el tamaño del subarreglo es pequeño, usa InsertionSort
    if (size < 16)
    {
        InsertionSort(arr, begin, end);
        return;
    }

    // Si la profundidad es cero, usa HeapSort
    if (depthLimit == 0)
    {
        make_heap(begin, end + 1);  // Crea un heap
        sort_heap(begin, end + 1);  // Ordena el heap
        return;
    }

    // De lo contrario, usa el concepto de mediana de tres para encontrar un buen pivote
    int *pivot = MedianOfThree(begin, begin + size / 2, end);

    // Intercambia el pivote con el último elemento
    swapValue(pivot, end);

    // Realiza QuickSort
    int *partitionPoint = Partition(arr, begin - arr, end - arr);
    IntrosortUtil(arr, begin, partitionPoint - 1, depthLimit - 1);
    IntrosortUtil(arr, partitionPoint + 1, end, depthLimit - 1);

    return;
}

// implemetación de Introsort
void Introsort(int arr[], int *begin, int *end)
{
    int depthLimit = 2 * log(end - begin);  // Calcula la profundidad máxima

    // Realiza Introsort recursivo
    IntrosortUtil(arr, begin, end, depthLimit);

    return;
}

//source del algoritmo> https://www.geeksforgeeks.org/internal-details-of-stdsort-in-c/