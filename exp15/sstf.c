#include<stdio.h> 
#include<stdlib.h> 
 
int main() 
{ 
    int req[20], visited[20]={0}; 
    int n, head, i, count=0; 
    int seek=0, index, min, distance; 
 
    printf("Enter Number of Requests: "); 
    scanf("%d",&n); 
 
    printf("Enter Request Queue:\n"); 
    for(i=0;i<n;i++) 
        scanf("%d",&req[i]); 
 
    printf("Enter Initial Head Position: "); 
    scanf("%d",&head); 
 
    while(count<n) 
    { 
        min=9999; 
 
        for(i=0;i<n;i++) 
        { 
            if(!visited[i]) 
            { 
                distance=abs(req[i]-head); 
 
                if(distance<min) 
                { 
                    min=distance; 
                    index=i; 
                } 
            }  
 
        } 
 
        seek+=min; 
        head=req[index]; 
        visited[index]=1; 
        count++; 
    } 
 
    printf("Total Head Movement = %d\n",seek); 
 
    return 0; 
}
