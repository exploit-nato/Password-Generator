#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void gen(int len){
    FILE *file = fopen("password.txt", "w+");
    srand((unsigned int)(time(NULL)));
    int seed = rand() % 4;
    char nums[10] = "0123456789", lower_letters[26] = "abcdefghijklmnoqprstuvwyxz", upper_letters[26] = "ABCDEFGHIJKLMNOQPRSTUYWVXZ", symbols[21] = "!@#$^&*?()-+=~,.{}\\/_", pass[len];
    printf("Password:\n\r\n\r");
    for(int i = 0; i < len; i++){
        switch(seed){
            case 1: pass[i] = nums[rand() % sizeof(nums)]; seed = (rand() % 4); printf("%c", pass[i]); break;
            case 2: pass[i] = lower_letters[rand() % sizeof(lower_letters)]; seed = (rand() %4); printf("%c", pass[i]); break;
            case 3: pass[i] = symbols[rand() % sizeof(symbols)]; seed = (rand() % 4); printf("%c", pass[i]); break;
            case 4: pass[i] = upper_letters[rand() % sizeof(upper_letters)]; seed = (rand() % 4); printf("%c", pass[i]); break;
            default: pass[i] = symbols[rand() % sizeof(symbols)]; seed = (rand() % 4); printf("%c", pass[i]); break;
        }
    if(pass[i] == 32) pass[i] = symbols[rand() % sizeof(symbols)];
    }pass[len] = '\0'; fputs(pass,file); fclose(file);
}

int main(void){
    int len = 0;
    printf("Length Of Password: ");
    scanf("%d", &len);
    gen(len);
    fflush(stdin);
    printf("\n\r");
    getchar();
    return 0;
}
