#include <stdio.h>
#include <stdlib.h>

#define X 25
#define Y 80
int ** gen_arr(int x,int y);
int life( int **b);
void output(int **array);


int main(){
    int **wisual_matrix=NULL;
    int **invis_matrix=NULL;
    if((wisual_matrix=gen_arr(X,Y))!=NULL&&(invis_matrix=gen_arr(X,Y))!=NULL){
        printf("%p\n",invis_matrix);
        life( invis_matrix);
        //printf("%p\n",wisual_matrix);
        
    }
    
    return 0;
}

// Необходимо ли выделять память для управляющей строки ?? 
//  Если я не буду использовать её в качестве инструмента управления ? 

int ** gen_arr(int x,int y){
    int ** a_ptr=(int **)malloc(sizeof(int *)*x+sizeof(int)*x*y);
    if(a_ptr!=NULL){
        for (int i = 0; i < x; i++){
            a_ptr[i]=(int*)(a_ptr + sizeof(int*)*x + i*y*sizeof(int));
            printf("!%d %p!\n",i,a_ptr[i]);
        }
    }
    return a_ptr;
}
// int **a,
int life( int **b){
    int check_cord(int **array,int c_x,int c_y);
    int i=1;
    
    while(i){
        for (int x = 0; x < X; x++){
            for (int y = 0; y < Y; y++){
                printf("!%d %p!\n",x,b[x]);
                // b[x][y]='0';
                // printf("[%d][%d]==%d\n",x,y,b[x][y]);
            }
        }
        output(b);
        i--;
    }
    return 0;
}

// void copy(int *a,int *b){

// }

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


void output(int **array){
    for(int x=0;x<X;x++){
        for(int y=0;y<Y;y++){
            printf("%d",array[x][y]);
        }
        putchar('\n');
    }
}