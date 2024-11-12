#include <stdio.h>

//Recursive function for calculating sum of first 10 numbers
int add(int *n) {
    //Base case
    if (*n == 0) {
        return 0;
    }

    int current = *n;  // Store current *n in a variable before decrementing it
    (*n)--;
    //Recursive case: add the value of the current to the sum of previous numbers
    return current + add(n);
}

int main() {
    int n = 10;  // We want the sum of the first 10 numbers
    int sum = add(&n);  // Pass the address of n to the recursive function

    printf("The sum of the first 10 numbers is: %d\n", sum);
    return 0;
}
