#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int compare(const void *a, const void *b) 
{

    return (*(int *)a - *(int *)b);

}


int main()
{

    int i, j, c, listSwitch, index; 

    i = 0;
    c = getchar();
    listSwitch=0;
    index=0;

    int tempList[5];
    int list1[1000];
    int list2[1000];
    int list3[1000];

    for(i=0; i < 1000; i++) {

        list1[i]=0;
        list2[i]=0;
        list3[i]=0;
        
    }

    i=0;

    while (c != EOF) {

        if (c >= '0' && c <= '9') {

            tempList[i]=(c - '0' );

            i++;

        }

        if (i == 5 && listSwitch == 0) {

            i=0;

            for (i=0; i<5;i++) {

                list1[index]=list1[index]+tempList[i]*((int)pow(10, 4- i));

            }

            i = 0;
            listSwitch = 1;

        }

        if (i == 5 && listSwitch == 1) {

            for (i=0; i<5; i++) {

                list2[index]=list2[index]+tempList[i]*((int)pow(10, 4- i));

            }

            i = 0;
            listSwitch = 0;
            index = index + 1;
            
        }

        c = getchar();

    }

    qsort(list1, 1000, sizeof(int), compare);

    qsort(list2, 1000, sizeof(int), compare);

    index=0;
    c=0;

    for(i = 0; i < 1000; i++){

        index = index + abs(list1[i]-list2[i]);
        
    }

    printf("%i", index);

    return 0;

}
