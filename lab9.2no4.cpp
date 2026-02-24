#include <stdio.h>
#include <string.h>
#include <ctype.h>

int checkLogin(char *login, char *passwd);
int checkValidPass(char *ps);

int main() {
    char login[64], password[64];
    printf("Enter login : "); fgets(login, 64, stdin); login[strcspn(login, "\n")] = 0;
    printf("Enter password : "); fgets(password, 64, stdin); password[strcspn(password, "\n")] = 0;

    if (checkLogin(login, password) == 1) {
        printf("Welcome\n");
    } else {
        printf("Incorrect login or password\n");
    }

    if (checkValidPass(password)) {
        printf("Accepted\n");
    } else {
        printf("Reject\n");
    }
}

int checkValidPass(char *ps) {
    int accepted = 0;
    int len = strlen(ps);
    int digits = 0, uppers = 0;
    int firstIsNum = isdigit(ps[0]);

    for (int i = 0; i < len; i++) {
        if (isdigit(ps[i]))  digits++;
        if (isupper(ps[i]))  uppers++;
    }

    int repeatUpper = 0;
    for (int i = 0; i < len && !repeatUpper; i++) {
        if (isupper(ps[i])) {
            for (int j = i + 1; j < len; j++) {
                if (ps[i] == ps[j]) { repeatUpper = 1; break; }
            }
        }
    }

    // 4.1: Length = 5 and at least 1 digit
    if (len == 5 && digits >= 1)
        accepted = 1;

    // 4.2: Length 5-8, first char NOT a number, >=2 uppercase, >=2 digits
    if (len >= 5 && len <= 8 && !firstIsNum && uppers >= 2 && digits >= 2)
        accepted = 1;

    // 4.3: Length 5-8, >=2 uppercase, NO repeated uppercase, >=2 digits
    if (len >= 5 && len <= 8 && uppers >= 2 && !repeatUpper && digits >= 2)
        accepted = 1;

    return accepted;
}

int checkLogin(char *login, char *passwd) {
    if (!strcmp(login, "student1") && !strcmp(passwd, "mypass"))
        return 1;
    else
        return 0;
}
