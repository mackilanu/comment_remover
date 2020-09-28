#include <stdio.h>

#define MAX_LINELEN 100

#define IN_COMMENT 1
#define NOT_IN_COMMENT 0

int get_line(char line[], int lim);
void read_file(char name[]);

int main()
{
    read_file("testfile.c");

    return 0;
}

int get_line(char s[], int lim)
{
    int c, i;

    for(i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if(c == '\n')
        s[++i] = '\n';

    s[i] = '\0';
    return i;
}

void read_file(char name[])
{
    FILE *fp;

    fp = fopen(name, "r");

    char c;

    if(!fp)
        perror("Could not open file!\n");
    
    int num_slashes = 0;
    while((c = getc(fp)) != EOF) {
        
        if(c == '/') {
            num_slashes++;
            if(num_slashes == 2) {
                
            }
        } else if(num_slashes == 2){
            if(c == '\n')
                num_slashes = 0;
        }else {
            putchar(c);
        }

    }

    fclose(fp);
}

