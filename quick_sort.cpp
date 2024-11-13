#include <iostream>
#include <stack>

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quicksort(int arr[], int low, int high) {
    std::stack<int> stack;
    stack.push(low);
    stack.push(high);

    while (!stack.empty()) {
        high = stack.top(); stack.pop();
        low = stack.top(); stack.pop();

        int pivot = partition(arr, low, high);

        if (pivot - 1 > low) {
            stack.push(low);
            stack.push(pivot - 1);
        }

        if (pivot + 1 < high) {
            stack.push(pivot + 1);
            stack.push(high);
        }
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int arr[] = { 10, 7, 8, 9, 1, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "before sort: ";
    printArray(arr, n);

    quicksort(arr, 0, n - 1);

    std::cout << "after sort: ";
    printArray(arr, n);

    return 0;
}