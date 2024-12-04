#include <stdio.h>

int main() {

    int i, c, flag, j, tally, tempflag;

    int b1, b2;

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

    i = 1;
    j = 0;

    while (list[i][0] != -1){

        for(j = 1; list[i][j+1] != -1; j++){

            if (list[i][j] == 'A'){

                b1 = (list[i+1][j-1] == 'M' && list[i-1][j+1] == 'S') || (list[i+1][j-1] == 'S' && list[i-1][j+1] == 'M');
                b2 = (list[i-1][j-1] == 'M' && list[i+1][j+1] == 'S') || (list[i-1][j-1] == 'S' && list[i+1][j+1] == 'M');

                if (b1 && b2){

                    tally++;

                }

            }

        }

        i++;

    }

    printf("%i", tally);

}