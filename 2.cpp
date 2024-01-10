#include <iostream>
using namespace std;
int main() {
    int arr[] = {1, 2, 2, 3, 3, 3, 4, 5, 5};
    int count = 0;
    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]) - 1; i++) {
        if (arr[i] == arr[i + 1]) {
            count++;
        }
    }
    cout << "Количество элементов, идущих подряд и равных между собой: " << count << endl;
    return 0;
}