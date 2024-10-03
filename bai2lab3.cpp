#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Student {
    string ID;
    string Name;
    string Gender;
    float Avg;
};

int partition(vector<Student>& students, int low, int high, int option) {
    float pivot;
    if (option == 1) {
        int mid = low + (high - low) / 2;
        pivot = students[mid].Avg;
        swap(students[mid], students[high]);  // Move pivot to the end
    } else if (option == 2) {
        pivot = students[high].Avg;
    }
    
    int i = low - 1;
    
    for (int j = low; j < high; j++) {
        if (students[j].Avg < pivot) {
            i++;
            swap(students[i], students[j]);
        }
    }
    
    swap(students[i + 1], students[high]); 
    return i + 1;
}

void quickSort(vector<Student>& students, int low, int high, int option) {
    if (low < high) {
        int pi = partition(students, low, high, option);
        quickSort(students, low, pi - 1, option);  
        quickSort(students, pi + 1, high, option); 
    }
}

void SortElements(string filename, int k, int option) {
    ifstream file(filename);  
    vector<Student> students;
    string line, token;
    
    if (file.is_open()) {
        while (getline(file, line)) {  
            stringstream ss(line);
            Student student;
            
            getline(ss, student.ID, ',');
            getline(ss, student.Name, ',');
            getline(ss, student.Gender, ',');
            getline(ss, token, ',');
            student.Avg = stof(token);  
            
            students.push_back(student);
        }
        file.close();
    } else {
        cerr << "Unable to open file" << endl;
        return;
    }

    quickSort(students, 0, students.size() - 1, option);


    for (size_t i = 0; i < static_cast<size_t>(k) && i < students.size(); i++) {
        cout << students[i].ID << " " << students[i].Name <<  " "
             << students[i].Gender << " "  << students[i].Avg << endl;
    }
}
