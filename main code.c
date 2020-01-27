#include <stdio.h>
#include <math.h>
#include <string.h>

char zero_nine[10][10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
char eleven_nineteen[9][10] = {"eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
char num_into_ten[9][10] = {"ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
int i, temp, num, j;

void under_hundred(int num)
{
    for(i = 0; i < 10; i++) {
            if(num == i) {
                printf("%s\n\n", zero_nine[i]);
            }
            else if(num == 11 + i) {
                printf("%s\n\n", eleven_nineteen[i]);
            }
            else if(num == (i + 1) * 10) {
                printf("%s\n\n", num_into_ten[i]);;
            }
            else if(num > 10 * (i + 2) && num < 10 *(i + 3)) {
                printf("%s ", num_into_ten[i+1]);
                printf("%s\n\n", zero_nine[num -(10 * (i + 2))]);
            }
        }
}

void under_thousand(int num)
{
    for(i = 0; i < 10; i++) {
        if(num == (i + 1) * 100) {
                printf("%s hundred\n\n", zero_nine[i+1]);;
        }
        else if(num >= 100 * (i + 1) && num < 100 *(i + 2)) {
                printf("%s hundred and ", zero_nine[i + 1]);
                temp = num - (100 * (i + 1));
                under_hundred(temp);
            }
    }
}
void output(int num)
{
    if(num >= 0 && num < 100) {
        under_hundred(num);
    }
    else if(num >= 100 && num < 1000) {
        under_thousand(num);
    }
}

int main()
{
    while(1) {
        printf("Enter a number: ");
        scanf("%d", &num);
        printf("\n%d in alphabetical is: ", num);
        if(num >= 0) {
            output(num);
        }
        else {
            num = 0 - num;
            printf("minus ");
            output(num);
        }
    }

    return 0;
}
