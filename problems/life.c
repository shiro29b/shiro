# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# define WINDOWS
# ifdef WINDOWS
# include <Windows.h>
# endif


void draw(char *buf,int **curr,int noRows,int noColumns) {
    int len=0;
    for (int i=0;i<noRows;i++) {
        for (int j=0; j<noColumns; j++) {
            len=len+sprintf(buf+len, "%c",curr[i][j]?'*':' ');
        }
        len=len+sprintf(buf+len, "\n");
    }
    system("cls");
    printf("%s", buf);
    fflush(stdout);
}



int cntneig(int **curr,int row,int column) {
    int neigh= 0;
    for (int i=row-1; i<=row+1;i++) {
        for (int j=column-1; j<=column+1 j++) {
            if (i==row && j==column)
                continue;
            if(curr[i][j]) {
                neigh++;
            }
        }
    }
    return neigh;
}

int update(int **curr,int noRows,int noColumns,int **next) {
    for (int i=1;i<noRows-1;i++) {
        for (int j = 1; j < noColumns - 1; j++) {
            int neigh = cntneig(curr,i,j);
            if (curr[i][j])
            {
                if (neigh==2 || neigh==3)
                {
                    next[i][j] = 1;
                }
                else
                {
                    next[i][j] = 0;
                }
            }
            else
            {
                if (neigh==3)
                {
                    next[i][j] = 1;
                }
                else
                {
                    next[i][j] = 0;
                }
            }
        }
    }
}




void initializeGrid(int **grid,int noRows,int noColumns,double fill) {
    for (int i=1;i<noRows-1;i++) {
        for (int j=1; j<noColumns-1; j++) {
            if ((1.0 * rand())/RAND_MAX<fill) {
                grid[i][j] = 1;
            }
        }
    }
}



int **newGrid(int noRows, int noColumns) {
    int **a=(int **)calloc(noRows,sizeof(int *));
    for (int i=0;i<noRows;i++) {
        a[i]=(int *)calloc(noColumns,sizeof(int));
    }
    return a;
}



int main(int argc, char *argv[]) {
    int noRows=100;
    int noColumns=100;
    double fill=0.5;
    int del=400;
    int **current=newGrid(noRows,noColumns);
    int **next=newGrid(noRows,noColumns);
    char *buffer=(char *)calloc(noRows*noColumns,sizeof(char)+1);
    srand(time(0));
    initializeGrid(current,noRows,noColumns,fill);
    long generation = 0;
    while (1) {
        draw(buffer,current,noRows,noColumns);
        update(current,noRows,noColumns,next);
        int **temp=current;
        current=next;
        next=temp;
        printf("gen : %d%s", generation++, generation % 3 == 0 ? "." : generation % 3 == 1 ? ".." : "...");
#ifdef WINDOWS
        Sleep(del);
#endif
    }
}
