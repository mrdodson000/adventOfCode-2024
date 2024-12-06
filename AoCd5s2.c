#include <stdio.h>
#include <windows.h>

int rules[1000][1000];

int main() {

    LARGE_INTEGER frequency;
    LARGE_INTEGER start, end;
    double time_taken;

    QueryPerformanceFrequency(&frequency);

    QueryPerformanceCounter(&start);

    int c, i, j, a, b, flag, flag2, index, temp, failure;

    c = getchar();
    flag = 1;
    index = 0;
    i = 0;
    j = 0;

    for(i = 0; i < 1000; i++){

        for(j = 0; j < 1000; j++){

            rules[i][j] = 1;

        }

    }

    char buffer[24];

    i = 0;

    while (i < 24){

        buffer[i] = c;

        c = getchar();

        i++;

    }

    char *pntbuffer = buffer;
    int linebuffer[100];

    while(sscanf(pntbuffer, "%i|%i", &a, &b) == 2){

        rules[b][a] = 0;


        for (i = 0; i < 24; i++){

            if (i > 17){

                buffer[i] = c;

                c = getchar();

            }

            else {

                buffer[i] = buffer[i+6];

            }

        }

    }

    for (i = 0; i < 24; i++){

        if(i == 23){

            buffer[i] = c;

            c = getchar();

        }

        else{

            buffer[i] = buffer[i+1];

        }

    }
    
    while(buffer[0] != -1){

        j = 0;

        flag = 1;

        while(flag){

            if(sscanf(pntbuffer, "%i%c", &a, &b) == 2 && b == ','){

                linebuffer[j] = a;

                j++;

            }

            if(sscanf(pntbuffer, "%i%c", &a, &b) == 2 && b == '\n'){

                linebuffer[j] = a;

                j++;

                flag = 0;

            }

            for (i = 0; i < 24; i++){

                if(i > 20 && flag2){

                    buffer[i] = c;

                    c = getchar();

                }

                else if(i > 20 && flag2 == 0){

                    buffer[i] = -1;

                }

                else{

                    buffer[i] = buffer[i+3];

                }

            }

        }

        linebuffer[j] = -1;

        i = 0;

        flag = -1;
        failure = -1;

        while (linebuffer[i] != -1){

            j = i;

            while (linebuffer[j] != -1){

                if (rules[linebuffer[i]][linebuffer[j]] == 0){

                    flag = j;

                }

                j++;
        
            }

            if (flag >= 0){

                temp = linebuffer[i];

                for (a = i; a < flag; a++){

                    linebuffer[a] = linebuffer[a+1];

                }

                linebuffer[flag] = temp;

                failure = 1;

                i = i-1;

            }

            flag = -1;

            i++;
            
        }

        if (failure == 1){

            index = index + linebuffer[i/2];

        }

    }

    printf("%i\n", index);

    QueryPerformanceCounter(&end);

    time_taken = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;

    time_taken = 1000*time_taken;

    printf("%f ms\n", time_taken);

}

