#include<stdio.h> 
#include<stdlib.h> 
 
int main() 
{ 
    int req[20], n, head, i; 
    int seek = 0; 
 
    printf("Enter Number of Requests: "); 
    scanf("%d",&n); 
 
    printf("Enter Request Queue:\n"); 
    for(i=0;i<n;i++) 
        scanf("%d",&req[i]); 
 
    printf("Enter Initial Head Position: "); 
    scanf("%d",&head); 
 
    for(i=0;i<n;i++) 
    { 
        seek += abs(req[i] - head); 
        head = req[i]; 
    } 
 
    printf("Total Head Movement = %d\n",seek); 
 
    return 0; 
}
