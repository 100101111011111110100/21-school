#include <stdio.h>
#include <stdlib.h>

#define X 25
#define Y 80
int ** gen_arr(int x,int y);

int main(){
    int **wisual_matrix=NULL;
    int **invis_matrix=NULL;
    if((wisual_matrix=gen_arr(X,Y))!=NULL&&(invis_matrix=gen_arr(X,Y))!=NULL){
        printf("%p\n",wisual_matrix);
        printf("%p\n",invis_matrix);
    }
    
    return 0;
}

// Необходимо ли выделять память для управляющей строки ?? 
//  Если я не буду использовать её в качестве инструмента управления ? 

int ** gen_arr(int x,int y){
    int ** a_ptr=(int **)malloc(sizeof(int *)*x+sizeof(int)*x*y);
    if(a_ptr!=NULL){
        int *a_p=NULL;
        for (size_t i = 0; i < x; i++){
            a_p=(int*)a_ptr + sizeof(int*)*x + i*y*sizeof(int);
        }
        
    }
    return a_ptr;
}

int life(int **a, int **b){
    while(1){
        for (int x = 0; x < X; x++){
            for (int y = 0; y < Y; y++){
                b[x][y];
            }
        }
    }
    return 0;
}

void copy(int *a,int *b){

}

int check_cord(int **array,int c_x,int c_y){
    int flag =0,n=0,n_x,n_y;
    int ch[8][2]={
        {-1,-1},{-1,0},{-1,1},
        {0,-1},{0,1},
        {1,-1},{1,0},{1,-1}
    };
    for (int i = 0; i < 8; i++){
        n_x=c_x+ch[i][0];
        n_y=c_y+ch[i][1];    
        if(array[n_x][n_y]=='*'){
            n++;
        }
    }
    if(array[c_x][c_y]==0 && n ==3){
        array[c_x][c_y]='*';
    }else if(array[c_x][c_y]=='*'){
        if(n==0 || n ==1 || n>=4){
            array[c_x][c_y]='0';
        }else{
            array[c_x][c_y]='*';
        }
    }
    return flag;
}
