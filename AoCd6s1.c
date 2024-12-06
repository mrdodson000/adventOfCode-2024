#include <stdio.h>

int main() {

    int c, i, j, dir, si, sj, count;

    c = getchar();
    i = 0;
    j = 0;
    si = 0;
    sj = 0;
    dir = 0;
    count = 0;

    char map[200][200];

    while(c != EOF){

        map[i][j] = c;
        j++;
        c = getchar();

        if (c == '^'){

            si = i;
            sj = j;

        }

        if (c == '\n' || c == EOF) {

            map[i][j] = -1;
            i++;
            j = 0;
            c = getchar();

        }

    }

    while (map[i-1][j] != -1){

        map[i][j] = -1;
        j++;

    }

    i = si;
    j = sj;

    while (i >= 0 && j >= 0 && map[i][j] != -1) {

        switch (dir){

            case 0:

                map[i][j] = 'X';

                if (map[i-1][j] == '#'){

                    dir = 1;

                }

                else {

                    i = i-1;

                }

            break;

            case 1:

                map[i][j] = 'X';

                if (map[i][j+1] == '#'){

                    dir = 2;

                }

                else {

                    j++;

                }

            break;

            case 2:

                map[i][j] = 'X';

                if (map[i+1][j] == '#'){

                    dir = 3;

                }

                else {

                    i = i + 1;

                }

            break;

            case 3:

                map[i][j] = 'X';

                if (map[i][j-1] == '#'){

                    dir = 0;

                }

                else {

                    j = j - 1;

                }

            break;

        }

    }

    for (i = 0; map[i][0] != -1; i++){

        for (j = 0; map[i][j] != -1; j++){

            if (map[i][j] == 'X'){

                count++;

            }

        }

    }

    printf("%i", count);
    
}
