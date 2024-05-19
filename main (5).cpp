#include <iostream>
using namespace std;

// Функція для додавання частини рядка
void myAppend(char* dest, const char* src, size_t subpos, size_t sublen) {
    // Знайти довжину dest
    size_t dest_len = 0;
    while (dest[dest_len] != '\0') {
        dest_len++;
    }
    
    // Копіювати символи з src до dest
    for (size_t i = 0; i < sublen; i++) {
        dest[dest_len + i] = src[subpos + i];
    }
    
    // Додати нульовий символ в кінці
    dest[dest_len + sublen] = '\0';
}

int main() {
    // Введення рядка з консолі
    string input;
    cout << "Enter a string: ";
    getline(cin, input);
    
    // Копіювати рядок в масив символів
    char inputArray[100];
    size_t i;
    for (i = 0; i < input.size(); i++) {
        inputArray[i] = input[i];
    }
    inputArray[i] = '\0';
    
    // Створити вихідний рядок
    char destArray[200] = "Hello, ";
    string destString = "Hello, ";
    
    // Викликати власну функцію
    myAppend(destArray, inputArray, 0, input.size());
    
    // Викликати метод append класу string
    destString.append(input, 0, input.size());
    
    // Вивести результати
    cout << "Result using myAppend: " << destArray << endl;
    cout << "Result using string::append: " << destString << endl;
    
    return 0;
}