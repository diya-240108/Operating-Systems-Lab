#include <stdio.h> 
 
int main() 
{ 
    int n, indexBlock, blocks[20], i; 
 
    printf("Enter Index Block: "); 
    scanf("%d", &indexBlock); 
 
    printf("Enter Number of Blocks: "); 
    scanf("%d", &n); 
 
    printf("Enter Block Numbers:\n");  
 
 
    for(i = 0; i < n; i++) 
    { 
        scanf("%d", &blocks[i]); 
    } 
 
    printf("\nIndex Block : %d\n", indexBlock); 
 
    printf("Allocated Blocks : "); 
 
    for(i = 0; i < n; i++) 
    { 
        printf("%d ", blocks[i]); 
    } 
 
    printf("\n"); 
 
    return 0; 
}
