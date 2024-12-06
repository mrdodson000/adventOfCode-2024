#include <stdio.h>
#include <string.h>
#include <windows.h>

int main() {

    LARGE_INTEGER frequency;
    LARGE_INTEGER start, end;
    double time_taken;

    QueryPerformanceFrequency(&frequency);

    QueryPerformanceCounter(&start);

    int c, i, j, dir, si, sj, count, a, b, loopflag, startlogger;

    c = getchar();
    i = 0;
    j = 0;
    si = 0;
    sj = 0;
    dir = 0;
    count = 0;
    loopflag = 1;
    startlogger = 0;

    int vinfo[200][200][4][3];

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

    for (a = 0; map[a][0] != -1; a++){

        for (b = 0; map[a][b] != -1; b++){

            if (map[a][b] == 'X') {

                map[a][b] = '#';
                dir = 0;
                loopflag = 1;

                memset(vinfo, 0, sizeof(vinfo));

                i = si;
                j = sj;

                while (i >= 0 && j >= 0 && map[i][j] != -1 && loopflag){

                    switch (dir) {

                        case 0:

                            if (map[i-1][j] == '#'){

                                if (vinfo[i-1][j][dir][0] == 0) {

                                    vinfo[i-1][j][dir][1] = 1;
                                    vinfo[i-1][j][dir][2] = 0;
                                    vinfo[i-1][j][dir][0]++;

                                }

                                else if (vinfo[i-1][j][dir][0] == 1 && 1 == vinfo[i-1][j][dir][1] && 0 == vinfo[i-1][j][dir][2]){

                                    loopflag = 0;
                                    count++;

                                }

                                dir = 1;

                            }

                            else {

                                i = i - 1;

                            }

                        break;

                        case 1:

                            if (map[i][j+1] == '#'){

                                if (vinfo[i][j+1][dir][0] == 0) {

                                    vinfo[i][j+1][dir][1] = 0;
                                    vinfo[i][j+1][dir][2] = -1;
                                    vinfo[i][j+1][dir][0]++;

                                }

                                else if (vinfo[i][j+1][dir][0] == 1 && 0 == vinfo[i][j+1][dir][1] && -1 == vinfo[i][j+1][dir][2]){

                                    loopflag = 0;
                                    count++;

                                }

                                dir = 2;

                            }

                            else {

                                j++;

                            }

                        break;

                        case 2:

                           if (map[i+1][j] == '#'){

                                if (vinfo[i+1][j][dir][0] == 0) {

                                    vinfo[i+1][j][dir][1] = -1;
                                    vinfo[i+1][j][dir][2] = 0;
                                    vinfo[i+1][j][dir][0]++;

                                }

                                else if (vinfo[i+1][j][dir][0] == 1 && 1 == vinfo[i+1][j][dir][1] && 0 == vinfo[i+1][j][dir][2]){

                                    loopflag = 0;
                                    count++;

                                }

                                dir = 3;

                            }

                            else {

                                i++;

                            }

                        break;

                        case 3:

                           if (map[i][j-1] == '#'){

                                if (vinfo[i][j-1][dir][0] == 0) {

                                    vinfo[i][j-1][dir][1] = 0;
                                    vinfo[i][j-1][dir][2] = 1;
                                    vinfo[i][j-1][dir][0]++;

                                }

                                else if (vinfo[i][j-1][dir][0] == 1 && 0 == vinfo[i][j-1][dir][1] && 1 == vinfo[i][j-1][dir][2]){

                                    loopflag = 0;
                                    count++;

                                }

                                dir = 0;

                            }

                            else {

                                j = j - 1;

                            }

                        break;

                    }
                    
                }
                
                map[a][b] = 'X';

            }

        }

    }

    printf("%i\n", count);

    QueryPerformanceCounter(&end);

    time_taken = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;

    time_taken = 1000*time_taken;

    printf("%f ms\n", time_taken);
    
}
