#include <stdio.h>
#include <string.h>

#define INPUT_COUNT 5
#define THRESHOLD 1.5

char *get_question(int i, float *weight)
{
    switch(i) {
        case 0:
            *weight = 0.8;
            return "\tDo you like computers? ";
            break;
        case 1:
            *weight = 0.7;
            return "\tDo you like programming? ";
            break;
        case 2:
            *weight = 0.5;
            return "\tAre you dedicated? ";
            break;
        case 3:
            *weight = 0.5;
            return "\tAre you willing to give up your social life? ";
            break;
        case 4:
            *weight = 0.8;
            return "\tCan you copy/paste? ";
            break;
        default:
            return "ERROR";
    }
}

int get_input(char input_buff, float *input )
{
    if(input_buff == 'y' || input_buff == 'Y') {
        *input = 1.0;
    }
    else if(input_buff == 'n' || input_buff == 'N') {
        *input = 0.0;
    }
    else {
        //ERROR: INVALID INPUT
        return -1;
    }

    return 0;
}

void output(float p, float p_max)
{
    if(p > THRESHOLD) {
        printf("\n\t\033[1;32mYES: Learn C\033[0m");
    }
    else {
        printf("\n\t\033[1;31mNo: Learn Javascript\033[0m");
    }


    printf("\n\n P = %2.1f", p);
    printf("\n\n%P = %2.1f%%", (p / p_max) * 100);

    return;
}

void title()
{
    printf("\nPerceptron: Answer y/n\n\n");

    return;
}

int main()
{
    title();
    char input;

    //x = input, w = weights, p = perceptron
    float x[INPUT_COUNT];
    float w[INPUT_COUNT];
    float p = 0.0; 
    float p_max = 0.0; 

    for(int i = 0; i < INPUT_COUNT; i++) {

        char *str = get_question(i, &w[i]);
        if(!strcmp("ERROR", str)) {
            fprintf(stderr, "ERROR: No question defined. Check inputs!");
            return 1;
        }

        printf("%s", str);
        printf("\033[1;33m");
        scanf(" %c", &input);
        printf("\033[0m");

        if(get_input(input, &x[i]) != 0) {
            fprintf(stderr, "ERROR: Invalid input. Program Terminated!");
            return 1;
        }

        while(getchar() != '\n');
        
        p += x[i] * w[i];
        p_max += 1 * w[i];

    }
    output(p, p_max);

    return 0;
}






