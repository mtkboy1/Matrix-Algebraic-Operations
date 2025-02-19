#include<stdio.h>
#include<stdlib.h>
struct matrix{
    int** mat;
    int width;
    int height;
};
void set_matrix(struct matrix* m, int** massive){
    m->mat= calloc(m->height,sizeof(int*));
    int rows = malloc(sizeof(int)*m->height);
    for(int i=0; i<m->height; i++){
        m->mat[i] = calloc(rows,sizeof(int));
        for(int j=0; j<m->width; j++){
            int res = *massive;
            m->mat[i][j] = res;
            massive++;
        }
    }
}
void sum_matrix(struct matrix* m, struct matrix* m1){
    for(int i=0; i<m->height; i++){
        for(int j=0; j<m->width; j++){
            int res = m1->mat[i][j];
            m->mat[i][j] = m->mat[i][j]+res;
            printf("%i\n",m->mat[i][j]);
        }
    }
}
void mult_num_matrix(struct matrix* m, int mult){
    for(int i=0; i<m->height; i++){
        for(int j=0; j<m->width; j++){
            m->mat[i][j] *= mult;
            printf("%i\n",m->mat[i][j]);
        }
    }
}
void mult_matrix(struct matrix* m, struct matrix* m1){
    if(m1->width!=m->height){ //CHECK WIDTH OF m1 AND HEIGHT OF m
        return;
    }
    int rows = malloc(sizeof(int)*m1->height);
    int** res = calloc(m->width,sizeof(int*));
    for(int i=0; i<m1->height; i++){
        res[i] = calloc(rows,sizeof(int));
        for(int j=0; j<m1->width; j++){
            for(int j1=0; j1<m->width; j1++){
                int a = m->mat[j][j1];
                int b = m1->mat[i][j];
                res[i][j1] += a*b;
            }
        }
    }
    free(m->mat);
    m->mat = res;
    m->height = m1->height;
    for(int i=0; i<m->height; i++){
        for(int j=0; j<m->width; j++){
            if(j!=m->width-1){
                printf("%i,",m->mat[i][j]);
            } else {
                printf("%i",m->mat[i][j]);
            }
        }
        printf("\n\n");
    }
}
void transpositon(struct matrix* m){
    int height = m->height;
    m->height = m->width;
    m->width = height;
    int** push = calloc(m->height,sizeof(int*));
    int rows = malloc(sizeof(int)*m->height);
    for(int i=0; i<m->height; i++){
        push[i] = calloc(rows,sizeof(int));
        for(int j=0; j<m->width; j++){
            push[i][j] = m->mat[j][i];
        }
    }
}