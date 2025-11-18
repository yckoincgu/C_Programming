#include <stdio.h>

int main() {
    char source[] = "You are welcome.";
    char copy[50];

    int i;
    for (i = 0; source[i] != '\0'; i++) {
        copy[i] = source[i];
    }
    copy[i] = '\0';

    printf("Copied string: %s\n", copy);

    return 0;
}
///////+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+
///////| Y  | o  | u  |    | a  | r  | e  |    | w  | e  | l  | c  | o  | m  | e  | .  | \0 |
///////+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+
//Index: 0    1    2    3    4    5    6    7    8    9    10   11   12   13   14   15