#include <iostream>
#include <stdio.h>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <random>

using namespace std;

int main() {
    char alphabet[26] = {
        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
        'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'
    };
    int numbers[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    char special[10] = {'@', '&', '$', '%', '_', '[', ']', '<', '>', '#'};
    int letteramt, numamt, specamt, passlen;
    char shuffle;
    string password;

    cout << "\nWelcome to the password generator!";
    cout << "\nFollow the instructions to generate a password!";
    cout << "\n----------------------------------------------------";

    while (true) {
        try {
            cout << "\nEnter the length of password: ";
            if (scanf("%d", &passlen) != 1) {
                while (getchar() != '\n');
                continue;
            }

            cout << "\nThe values you will be prompted to choose must add up to the length of the password!";
            cout << "\nEnter the amount of characters you want your password to have: ";
            if (scanf("%d", &letteramt) != 1) {
                while (getchar() != '\n');
                continue;
            }

            cout << "\nEnter the amount of numbers you want your password to have: ";
            if (scanf("%d", &numamt) != 1) {
                while (getchar() != '\n');
                continue;
            }

            cout << "\nEnter the amount of special characters you want your password to have: ";
            if (scanf("%d", &specamt) != 1) {
                while (getchar() != '\n');
                continue;
            }

            if (letteramt + numamt + specamt != passlen) {
                cout << "Error: The values must add up to the length of the password!\n";
                continue;
            }

            for (int i = 0; i < letteramt; i++) {
                password += alphabet[rand() % 26];
            }
            for (int i = 0; i < numamt; i++) {
                password += '0' + numbers[rand() % 10];
            }
            for (int i = 0; i < specamt; i++) {
                password += special[rand() % 10];
            }

            cout << "Enter if you would like to shuffle your password or not to make it more secure (y/n): ";
            while (getchar() != '\n');
            scanf("%c", &shuffle);
            if (shuffle == 'y') {
                random_device rd;
                mt19937 g(rd());
                std::shuffle(std::begin(password), std::end(password), g);
            }

            cout << "Your password is: " << password << "\n";
            break;
        }
        catch (const exception& e) {
            cerr << "An error occurred: " << e.what() << '\n';
            while (getchar() != '\n');
            continue;
        }
    }

    return 0;
}