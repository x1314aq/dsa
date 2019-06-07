/**
 * hihoCoder 1039 字符消除
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max_num;


void erase(char *str, int i, int j) {
    int n = j - i;
    while(n-- && str[j])
        str[i++] = str[j++];
    str[i] = 0;
}

void eliminate(char *str) {
    int i, j = 0;
    int len = strlen(str);
    for(i = 0; i < len; i++) {
        if(str[i] == 1) {
            j = i + 1;
            while(str[j] == 1) j++;
            break;
        }
    }
    if(j == 0) return;
    erase(str, i, j);
    eliminate(str);
}

void one_step(char *str) {
    int temp = 0;
    int loop, len, i, j;
    do {
        loop = 0;
        len = strlen(str);
        for(i = 0; i < len - 1;) {
            j = i + 1;
            if(str[i] == str[j]) {
                loop = 1;
                temp++;
                while(str[i] == str[j]) {
                    str[j++] = 1;
                    temp++;
                }
                str[i] = 1;
            }
            i = j;
        }
        if(loop) eliminate(str);
    } while(loop);
    if(temp > max_num)
        max_num = temp;
}

void new_str(char *src, char *dest, int len, int i, char c) {
    if(i == 0) {
        dest[0] = c;
        strcpy(&dest[1], src);
        return;
    }
    memcpy(dest, src, i);
    dest[i] = c;
    if(i < len)
        memcpy(&dest[i + 1], &src[i], len - i);
    dest[len + 1] = 0;
}

void solver(char *str) {
    char back[105];
    int len = strlen(str);
    for(int i = 0; i <= len; i++) {
        new_str(str, back, len, i, 'A');
        one_step(back);
    }
    for(int i = 0; i <= len; i++) {
        new_str(str, back, len, i, 'B');
        one_step(back);
    }
    for(int i = 0; i <= len; i++) {
        new_str(str, back, len, i, 'C');
        one_step(back);
    }
}

int main() {
    int n;
    char str[105];
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%s", str);
        max_num = 0;
        solver(str);
        printf("%d\n", max_num);
    }
    return 0;
}
