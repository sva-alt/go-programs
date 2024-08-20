#include <stdio.h>

int main() {
    
    int count = 1;
    while ( count < 5 ) {
        count += count;
    }
    printf("%d \n", count);
}
