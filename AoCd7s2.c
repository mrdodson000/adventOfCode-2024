#include <stdio.h>
#include <math.h>

int checker(int array[100], unsigned long long operand, int index){

    if (index == 0) {
        return (operand == array[index]);
    }

    if (operand % array[index] == 0) {
        if (checker(array, operand / array[index], index - 1)) {
            return 1;
        }
    }

    int i = 0;
    while ((array[index] % (int)(pow(10,i))) != array[index]){
        i++;
    }

    if ((operand - array[index]) % (int)pow(10,i) == 0){
        if (checker(array, (operand - array[index]) / (int)pow(10,i), index - 1)){
            return 1;
        }
    }

    if (checker(array, operand - array[index], index - 1)) {
        return 1;
    }

    return 0;

}

unsigned long long bigPow(int x, int y){
    unsigned long long result = 1;
    while (y > 0){
        result = result * x;
        y = y - 1;
    }
    return result;
}

int main(){

    int c, switchState, i, numbufferIndex, linebufferIndex;
    unsigned long long operand, tally;

    c = getchar();
    switchState = 0;
    numbufferIndex = 0;
    int linebuffer[100];
    int numbuffer[100];
    operand = 0;
    tally = 0;

    while (c != EOF){

        if (c >= '0' && c <= '9'){

            numbuffer[numbufferIndex] = c - '0';
            numbufferIndex++;

        }

        if (c == ':'){

            operand = 0;

            for (i = numbufferIndex - 1; i >= 0; i = i - 1){
                
                operand = operand + (numbuffer[i]*bigPow(10, numbufferIndex - 1 - i));

            }

        }

        if (c == ' ' && switchState == 1){

            linebuffer[linebufferIndex] = 0;

            for (i = numbufferIndex - 1; i >= 0; i = i - 1){
                
                linebuffer[linebufferIndex] = linebuffer[linebufferIndex] + (numbuffer[i]*(int)pow(10, numbufferIndex - 1 - i));

            }

            numbufferIndex = 0;
            linebufferIndex++;

        }

        if (c == ' ' && switchState == 0){

            switchState = 1;
            numbufferIndex = 0;
            linebufferIndex = 0;

        }

        if (c == '\n'){

            linebuffer[linebufferIndex] = 0;

            for (i = numbufferIndex - 1; i >= 0; i = i - 1){
                
                linebuffer[linebufferIndex] = linebuffer[linebufferIndex] + (numbuffer[i]*(int)pow(10, numbufferIndex - 1 - i));

            }

            int *array = linebuffer;

            if (checker(array, operand, linebufferIndex) == 1){

                tally = tally + operand;

            }

            for (int i = 0; i <= linebufferIndex; i++) {

                linebuffer[i] = 0;

            }

            numbufferIndex = 0;
            linebufferIndex = 0;
            switchState = 0;

        }

        c = getchar();

    }

    printf("%llu\n", tally);

}
