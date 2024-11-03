#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool is_square(int n) {
    if (n < 0) return false;
    
    int root = (int)sqrt(n);
    return root * root == n;
}