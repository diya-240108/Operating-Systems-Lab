#include <stdio.h> 
 
int main() 
{ 
    int n, blocks[20], i; 
 
    printf("Enter Number of Blocks: "); 
    scanf("%d", &n); 
 
    printf("Enter Block Numbers:\n"); 
 
    for(i = 0; i < n; i++) 
    { 
        scanf("%d", &blocks[i]); 
    } 
 
    printf("\nLinked Allocation:\n"); 
 
    for(i = 0; i < n - 1; i++) 
    { 
        printf("%d --> ", blocks[i]); 
    } 
 
    printf("%d --> NULL\n", blocks[n - 1]); 
 
    return 0; 
}
