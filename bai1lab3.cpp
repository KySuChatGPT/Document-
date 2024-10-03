#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int partition(vector<int>& arr, int low, int high, int option) {
    int pivot;
    if (option == 1) {
        int mid = low + (high - low) / 2;
        pivot = arr[mid];
        swap(arr[mid], arr[high]);  
    } else if (option == 2) {
        pivot = arr[high];
    }
    
    int i = low - 1;
    
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    
    swap(arr[i + 1], arr[high]); 
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high, int option) {
    if (low < high) {
        int pi = partition(arr, low, high, option);
        quickSort(arr, low, pi - 1, option);  
        quickSort(arr, pi + 1, high, option); 
    }
}

void SortElements(string filename, int k, int option) {
    ifstream file(filename);  
    vector<int> numbers;
    int num;
    
    if (file.is_open()) {
        while (file >> num) {  
            numbers.push_back(num);
        }
        file.close();
    } else {
        cerr << "Unable to open file" << endl;
        return;
    }

    quickSort(numbers, 0, numbers.size() - 1, option);

    for (size_t i = 0; i < static_cast<size_t>(k) && i < numbers.size(); i++) {  
        cout << numbers[i] << "\n";
    }
    cout << endl;
}
