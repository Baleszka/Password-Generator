#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char alphabet[26] = {
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
    'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'
};
int numbers[10] = {1,2,3,4,5,6,7,8,9,0};
char special[10] = {'@','&','$','%','_','[',']','<','>','#'};

void shufflepassword(char pass[], int passlen){
    srand(time(NULL));
    for (int i = 0; i < passlen; i++) {
        int j = rand() % passlen;
        char temp = pass[i];
        pass[i] = pass[j];
        pass[j] = temp;
    }
}

void create_pass(char pass[], int passlen,int letteramt,int numamt, int specamt, char alphabet[26], int numbers[10], char special[10]){
    int index = 0;
    srand(time(NULL));
    for (int i = 0; i < letteramt; i++) {
        pass[index++] = alphabet[rand() % 26];
    }
    for (int i = 0; i < numamt; i++) {
        pass[index++] = '0' + numbers[rand() % 10];
    }
    for (int i = 0; i < specamt; i++) {
        pass[index++] = special[rand() % 10];
    }
    pass[passlen] = '\0';
}

int main(){
    int passlen;
    int letteramt;
    int numamt;
    int specamt;
    char shuffleyn;
    char password[100];
    printf("\nWelcome to the password generator!\n");
    printf("Follow the instructions to generate a password!\n");
    printf("----------------------------------------------------\n");
    while(1){
        printf("Enter how long you want your password to be: ");
        if (scanf("%d", &passlen)==1)
        {
            printf("\nThe following amounts you will need to enter must add up to the total length of your password!");
            printf("\nEnter how many letters you want your password to have: ");
            if(scanf("%d",&letteramt)==1){
                printf("\nEnter how many numbers you want your password to have: ");
                if(scanf("%d", &numamt)==1){
                    printf("\nEnter how many special characters you want your password to have: ");
                    if (scanf("%d", &specamt)==1)
                    {
                        printf("Enter if you would like to shuffle your password to make it more secure (y/n): ");
                        while (getchar() != '\n');
                        if (scanf("%c", &shuffleyn) == 1) {
                            if (shuffleyn == 'y') {
                                create_pass(password, passlen, letteramt, numamt, specamt, alphabet, numbers, special);
                                shufflepassword(password, passlen);
                                printf("Your password is: %s\n", password);
                                break;
                            } else if (shuffleyn == 'n') {
                                create_pass(password, passlen, letteramt, numamt, specamt, alphabet, numbers, special);
                                printf("Your password is: %s\n", password);
                                break;
                            } else {
                                printf("Please enter y or n!\n");
                                continue;
                            }
                        }
                    }
                    else{
                        printf("Please enter an integer!\n");
                        while (getchar() != '\n');
                        continue;
                    }
                    
                }
                else{
                    printf("Please enter an integer!\n");
                    while (getchar() != '\n');
                    continue;
                }
            }
            else{
                printf("\nPlease enter an integer!\n");
                while (getchar() != '\n');
                continue;
            }
        }
        else{
            printf("Please enter an integer!\n");
            while (getchar() != '\n');
            continue;
        }
        
    }
    return 0;
}