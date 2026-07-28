#include "basic_01.h"

void fibonacci()
{
    int a = 0, b = 1, next, i, number;
    std::cout << "Enter the number of elements: ";
    std::cin >> number;

    if(number <= 0)
    {
        std::cout << "Please enter a positive integer." << std::endl;
        return;
    }

    std::cout << a << " " << b << " "; //printing 0 and 1

    for (i = 2; i < number; ++i) //loop starts from 2 because 0 and 1 are already printed
    {
        next = a + b;
        std::cout << next << " ";
        a = b;
        b = next;
    }
}

void reverse_number()
{
    int num, reversed = 0, remainder;
    std::cout << "Enter an integer: ";
    std::cin >> num;

    while (num != 0)
    {
        remainder = num % 10; // get the last digit
        reversed = reversed * 10 + remainder; // append it to the reversed number
        num /= 10; // remove the last digit from num
    }

    std::cout << "Reversed Number: " << reversed << std::endl;
}

// Helper function to print the array contents
void printArray(const int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << (i < size - 1 ? ", " : "");
    }
    std::cout << std::endl;
}

void reverse_array() {
    const int N = 6;
    int arr[N] = {10, 20, 30, 40, 50, 60}; 

    std::cout << "Original Array: ";
    printArray(arr, N);

    // Swap elements from opposite ends of the array, iterating only halfway
    for (int i = 0; i < N / 2; ++i) {
        int temp = arr[i];         // 1. Store the front element
        arr[i] = arr[N - 1 - i];   // 2. Overwrite front with back element
        arr[N - 1 - i] = temp;     // 3. Overwrite back with original front (temp)
    }

    std::cout << "Reversed Array: ";
    printArray(arr, N);
}