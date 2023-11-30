#include <stdio.h>
#include <stdlib.h>


void delete(FILE* p_f, FILE* p_new_f){
    int p;
    while(feof(p_f) == 0){
        p = fgetc(p_f);
        if (p == 32) continue;
        p = fputc(p, p_new_f);
    }
}


int main(){
    FILE* p_f = fopen("aaa.txt", "r");
    FILE* p_new_f = fopen("new_file.txt", "w");
    delete(p_f, p_new_f);
    fclose(p_f);
    fclose(p_new_f);
}