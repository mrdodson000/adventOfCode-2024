#include <stdio.h>
#include <math.h>

int main()
{

    int c, or, countUp, countDown, counter, i, hold, badLevels, j;

    c = getchar();
    or = 0;
    i = 0;
    countUp = 0;
    countDown = 0;
    counter = 0;
    hold = 0;
    badLevels = 0;
    j = 0;

    int head[2];
    int cache[100];

    while(c != EOF) {

        if(c >= '0' && c <='9') {

            head[or] = c - '0';

            or++;

        }

        if(c == ' '){

            if(or == 1){

                cache[i] = head[0];

                printf("%i ",cache[i]);

                i++;

            }

            if(or == 2){

                cache[i] = head[0]*10 + head[1];

                printf("%i ",cache[i]);

                i++;

            }

            or = 0;

        }

        if(c == '\n') {

            if(or == 1){

                cache[i] = head[0];

                printf("%i ",cache[i]);

                i++;

            }

            if(or == 2){

                cache[i] = head[0]*10 + head[1];

                printf("%i ",cache[i]);

                i++;

            }

            or = 0;

            cache[i] = -1;

            printf("%i ",cache[i]);

            for(i = 0; cache[i] != -1; i++){

                 for(j = 0; cache[j] != -1; j++){

                    if (j != i) {

                        if (j + 1 == i && cache[j+2] == -1){

                            counter++;
                            countUp++;
                            countDown++;

                        }

                        else if (cache[j + 1] == -1){

                            counter++;
                            countUp++;
                            countDown++;
                            
                        }

                        else if (j + 1 == i && cache[j+2] != -1){

                            if(cache[j]<cache[j+2] && cache[j] + 1 <= cache[j+2] && cache[j+2] <= cache[j]+3){

                            countUp++;

                            }

                            if (cache[j]>cache[j+2]&&cache[j] - 1 >= cache[j+2] && cache[j+2] >= cache[j] - 3){

                            countDown++;

                            }

                            counter++;

                        }

                        else {

                            if (cache[j]<cache[j+1] && cache[j] + 1 <= cache[j+1] && cache[j+1] <= cache[j]+3){

                            countUp++;

                            }

                            if (cache[j]>cache[j+1]&&cache[j] - 1 >= cache[j+1] && cache[j+1] >= cache[j] - 3){

                            countDown++;

                            }

                            counter++;

                        }

                    }

                 }

                printf("| %i %i %i %i ", counter, countUp, countDown, i);

                if(counter == countUp || counter == countDown){

                badLevels++;

                }

                counter = 0;

                countUp = 0;

                countDown = 0;

            }

            printf("| %i ", badLevels);

            if (badLevels > 0) {

                hold++;

            }

            badLevels = 0;

            i = 0;

             printf("\n");

        }

        c = getchar();


    }

    printf("%i", hold);

}