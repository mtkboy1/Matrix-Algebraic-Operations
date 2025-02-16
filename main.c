#include<stdio.h>
#include<stdlib.h>
#include"matrix.h"

int main(int argc, char** argv){ //argc - кол-во аргументов argv, argv - массив строк
    struct matrix m;
    m.width = 3;
    m.height = 2;
    int mat[2][3] = {
        {1,0,3},
        {1,0,3}
    };
    struct matrix m1;
    m1.width = 2;
    m1.height = 3;
    int mat1[3][2] = {
        {2,1},
        {3,2},
        {2,5}
    };
    set_matrix(&m,&mat);
    set_matrix(&m1,&mat1);
    mult_matrix(&m,&m1);
    //sum_matrix(&m,&m1);
    //sum_matrix(&m,&m);
    free(m.mat);
    free(m1.mat);
   // printf("\n%p and %i", (void*) a, *a);
    return 0;
}