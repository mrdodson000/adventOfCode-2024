#include <stdio.h>

int main() {

    int i, c, flag, j, tally, tempflag;

    c = getchar();
    i = 0;
    j = 0;
    flag = 0;
    tally = 0;
    tempflag = 1;

    char list[200][1000];

    while (c != EOF)
    {
        list[i][j] = c;

        j++;

        c = getchar();

        if (c == '\n'){

            list[i][j] = -1;

            i++;

            j = 0;

            c = getchar();

        }

    }

    flag = 1;

    for(j = 0; j < 1000; j++){

        list[i][j] = -1;

    }

    i = 0;
    j = 0;

    while (list[i][0] != -1) {

        if (list[i+3][0] == -1) {

            flag = 0;

        }

        if (i < 3){

            while(list[i][j] != -1){

                if(list[i][j+3] == -1){

                    tempflag = 0;

                }

                if (list[i][j] == 'X'){

                    if (j >= 3 && tempflag){

                        if (list[i][j-1] == 'M' && list[i][j-2] == 'A' && list[i][j-3] == 'S') {

                            tally++;

                        }

                        if (list[i][j+1] == 'M' && list[i][j+2] == 'A' && list[i][j+3] == 'S') {

                            tally++;

                        }

                        if (list[i+1][j] == 'M' && list[i+2][j] == 'A' && list[i+3][j] == 'S') {

                            tally++;
                        
                        }

                        if (list[i+1][j-1] == 'M' && list[i+2][j-2] == 'A' && list[i+3][j-3] == 'S') {

                            tally++;
                        
                        }

                        if (list[i+1][j+1] == 'M' && list[i+2][j+2] == 'A' && list[i+3][j+3] == 'S') {

                            tally++;
                        
                        }

                    }

                    if (j < 3){

                        if (list[i][j+1] == 'M' && list[i][j+2] == 'A' && list[i][j+3] == 'S') {

                            tally++;

                        }

                        if (list[i+1][j] == 'M' && list[i+2][j] == 'A' && list[i+3][j] == 'S') {

                            tally++;
                        
                        }

                        if (list[i+1][j+1] == 'M' && list[i+2][j+2] == 'A' && list[i+3][j+3] == 'S') {

                            tally++;
                        
                        }

                    }

                    if (tempflag == 0){

                        if (list[i][j-1] == 'M' && list[i][j-2] == 'A' && list[i][j-3] == 'S') {

                            tally++;

                        }

                        if (list[i+1][j] == 'M' && list[i+2][j] == 'A' && list[i+3][j] == 'S') {

                            tally++;
                        
                        }

                        if (list[i+1][j-1] == 'M' && list[i+2][j-2] == 'A' && list[i+3][j-3] == 'S') {

                            tally++;
                        
                        }

                    }


                }

                j++;

            }

            j = 0;

        }

        if (i >= 3 && flag){

            while(list[i][j] != -1){

                if(list[i][j+3] == -1){

                    tempflag = 0;

                }

                if (list[i][j] == 'X'){

                    if (j >= 3 && tempflag){

                        if (list[i][j-1] == 'M' && list[i][j-2] == 'A' && list[i][j-3] == 'S') {

                            tally++;

                        }

                        if (list[i][j+1] == 'M' && list[i][j+2] == 'A' && list[i][j+3] == 'S') {

                            tally++;

                        }

                        if (list[i+1][j] == 'M' && list[i+2][j] == 'A' && list[i+3][j] == 'S') {

                            tally++;
                        
                        }

                        if (list[i-1][j] == 'M' && list[i-2][j] == 'A' && list[i-3][j] == 'S') {

                            tally++;
                        
                        }

                        if (list[i-1][j-1] == 'M' && list[i-2][j-2] == 'A' && list[i-3][j-3] == 'S') {

                            tally++;
                        
                        }

                        if (list[i-1][j+1] == 'M' && list[i-2][j+2] == 'A' && list[i-3][j+3] == 'S') {

                            tally++;
                        
                        }


                        if (list[i+1][j-1] == 'M' && list[i+2][j-2] == 'A' && list[i+3][j-3] == 'S') {

                            tally++;
                        
                        }

                        if (list[i+1][j+1] == 'M' && list[i+2][j+2] == 'A' && list[i+3][j+3] == 'S') {

                            tally++;
                        
                        }

                    }

                    if (j < 3){

                        if (list[i-1][j+1] == 'M' && list[i-2][j+2] == 'A' && list[i-3][j+3] == 'S') {

                            tally++;
                        
                        }

                        if (list[i-1][j] == 'M' && list[i-2][j] == 'A' && list[i-3][j] == 'S') {

                            tally++;
                        
                        }

                        if (list[i][j+1] == 'M' && list[i][j+2] == 'A' && list[i][j+3] == 'S') {

                            tally++;

                        }

                        if (list[i+1][j] == 'M' && list[i+2][j] == 'A' && list[i+3][j] == 'S') {

                            tally++;
                        
                        }

                        if (list[i+1][j+1] == 'M' && list[i+2][j+2] == 'A' && list[i+3][j+3] == 'S') {

                            tally++;
                        
                        }

                    }

                    if (tempflag == 0){

                        if (list[i][j-1] == 'M' && list[i][j-2] == 'A' && list[i][j-3] == 'S') {

                            tally++;

                        }

                        if (list[i+1][j] == 'M' && list[i+2][j] == 'A' && list[i+3][j] == 'S') {

                            tally++;
                        
                        }

                        if (list[i+1][j-1] == 'M' && list[i+2][j-2] == 'A' && list[i+3][j-3] == 'S') {

                            tally++;
                        
                        }

                        if (list[i-1][j-1] == 'M' && list[i-2][j-2] == 'A' && list[i-3][j-3] == 'S') {

                            tally++;
                        
                        }

                        if (list[i-1][j] == 'M' && list[i-2][j] == 'A' && list[i-3][j] == 'S') {

                            tally++;
                        
                        }

                    }

                }

                j++;

            }

            j = 0;

        }

        if (flag == 0){

            while(list[i][j] != -1){

                if(list[i][j+3] == -1){

                    tempflag = 0;

                }

                if (list[i][j] == 'X'){

                    if (j >= 3 && tempflag){

                        if (list[i][j-1] == 'M' && list[i][j-2] == 'A' && list[i][j-3] == 'S') {

                            tally++;

                        }

                        if (list[i][j+1] == 'M' && list[i][j+2] == 'A' && list[i][j+3] == 'S') {

                            tally++;

                        }

                        if (list[i-1][j] == 'M' && list[i-2][j] == 'A' && list[i-3][j] == 'S') {

                            tally++;
                        
                        }

                        if (list[i-1][j-1] == 'M' && list[i-2][j-2] == 'A' && list[i-3][j-3] == 'S') {

                            tally++;
                        
                        }

                        if (list[i-1][j+1] == 'M' && list[i-2][j+2] == 'A' && list[i-3][j+3] == 'S') {

                            tally++;
                        
                        }

                    }

                    if (j < 3){

                        if (list[i-1][j+1] == 'M' && list[i-2][j+2] == 'A' && list[i-3][j+3] == 'S') {

                            tally++;
                        
                        }

                        if (list[i-1][j] == 'M' && list[i-2][j] == 'A' && list[i-3][j] == 'S') {

                            tally++;
                        
                        }

                        if (list[i][j+1] == 'M' && list[i][j+2] == 'A' && list[i][j+3] == 'S') {

                            tally++;

                        }

                    }

                    if (tempflag == 0){

                        if (list[i][j-1] == 'M' && list[i][j-2] == 'A' && list[i][j-3] == 'S') {

                            tally++;

                        }

                        if (list[i-1][j-1] == 'M' && list[i-2][j-2] == 'A' && list[i-3][j-3] == 'S') {

                            tally++;
                        
                        }

                        if (list[i-1][j] == 'M' && list[i-2][j] == 'A' && list[i-3][j] == 'S') {

                            tally++;
                        
                        }

                    }

                }
                
                j++;

            }

            j = 0;

        }

        i++;

        tempflag = 1;

    }

    printf("%i", tally);

}