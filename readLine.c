#include <stdio.h>
#include <string.h>

#define MAXLINE 100
#define MAXSTORED 500000
#define MAXLINES 5000

char *ptrLines[MAXLINES];

int getLine(char *s, int maxLength)
{
    int i;
    i = 0;
    while ((*s = getchar()) != EOF && *s != '\n' && i < maxLength)
    {
        i++;
        s++;
    }

    return i;
}

int readLine(char *plines[], int maxlines, char *storedLines)
{
    int len;
    char line[MAXLINE];
    char *p = storedLines + (strlen(storedLines) - 1);
    int numOfLines = 0;
    while ((len = getLine(line, MAXLINE)) > 0)
    {
        if (numOfLines >= 5000 || (strlen(p) + len) > MAXSTORED)
        {
            return -1;
        }
        else
        {
            line[len] = '\0';
            strcpy(p, line);
            plines[numOfLines++] = p;
            p += len + 1;
        }
    }

    return numOfLines;
}

void writeLines(char *lines[], int num_of_lines)
{
    while (num_of_lines-- > 0)
    {
        printf("%s\n", *lines++);
    }
}

int main(int argc, char const *argv[])
{

    char line[MAXLINE];
    char storedLines[MAXSTORED];

    int numOfLines = 0;
    numOfLines = readLine(ptrLines, MAXLINES, storedLines);

    writeLines(ptrLines, numOfLines);
    return 0;
}
