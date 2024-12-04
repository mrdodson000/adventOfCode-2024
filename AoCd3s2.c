#include <stdio.h>
#include <math.h>

int main()
{
    int c, a, b, i, tally, flag, flag2, flag3;

    char checker;

    c = getchar();
    a = 0;
    b = 0;
    i = 0;
    tally = 0;

    flag = 1;
    flag2 = 0;
    flag3 = 1;

    char buffer[20];

    for(i = 0; i < 20; i++){

        buffer[i] = c;

        c = getchar();

    }

    char* arr = buffer;

    while (flag)
    {

        /*if you delete the two following if statements this code also solves Part 1*/
        
        if(sscanf(arr, "do(%c", &checker) == 1 && checker == ')') {

            flag3 = 1;

        }

        if(sscanf(arr, "don't(%c", &checker) == 1 && checker == ')') {

            flag3 = 0;

        }


        if(flag3 == 1 && sscanf(arr, "mul(%i,%i%c", &a, &b, &checker) == 3 && checker == ')'){

            printf("%i %i\n", a, b);

            tally = tally + (a)*(b);

        }

        for(i = 1; i < 20; i++){

            buffer[i-1] = buffer[i];

            if(i == 19 && flag2 == 0){

                buffer[i] = c;

                c = getchar();

            }

            if(i == 19 && flag2 == 1){

                buffer[i] = EOF;

            }

        }


        if(c == EOF){

            flag2 = 1;
            
        }

        if(buffer[0] == EOF){

            flag = 0;
            
        }


    }

    printf("%i ", tally);

}
