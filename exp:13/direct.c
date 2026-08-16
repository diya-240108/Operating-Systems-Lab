#include <stdio.h> 
 
struct student 
{ 
    int regno; 
    char name[20]; 
}; 
 
int main() 
{ 
    FILE *fp; 
    struct student s; 
 
    fp = fopen("random.dat", "wb+"); 
 
    printf("Enter Register Number: "); 
    scanf("%d", &s.regno); 
 
    printf("Enter Name: "); 
    scanf("%s", s.name); 
 
    fwrite(&s, sizeof(s), 1, fp); 
 
    rewind(fp); 
 
    fread(&s, sizeof(s), 1, fp); 
 
    printf("\nRecord Found\n"); 
    printf("Reg No : %d\n", s.regno); 
    printf("Name   : %s\n", s.name); 
 
    fclose(fp); 
 
    return 0; 
}
