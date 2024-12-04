#include <stdio.h>
#include <math.h>

int main()
{

    int c, or, countUp, countDown, counter, i, hold;

    c = getchar();
    or = 0;
    i = 0;
    countUp = 0;
    countDown = 0;
    counter = 0;
    hold = 0;

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

                i++;

            }

            or = 0;

            cache[i] = -1;

            printf("%i ",cache[i]);

            for(i = 0; cache[i+1] != -1; i++){

                if(cache[i]<cache[i+1] && cache[i] + 1 <= cache[i+1] && cache[i+1] <= cache[i]+3){

                    countUp++;

                }

                if(cache[i]>cache[i+1]&&cache[i] - 1 >= cache[i+1] && cache[i+1] >= cache[i] - 3) {

                    countDown++;

                }

                counter++;

            }

            printf("%i %i %i",counter, countUp, countDown);

            if(counter == countUp || counter == countDown){

                hold++;

            }

            counter = 0;

            countUp = 0;

            countDown = 0;

             i = 0;

             printf("\n");

        }

        c = getchar();


    }

    printf("%i", hold);

}