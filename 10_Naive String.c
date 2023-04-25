//10_Naive String.c
#include <stdio.h>
#include <string.h>
int match(char st[], char pat[]);
int main()
{
    char st[100], pat[100];
    int status;
    printf("*** Naive String Matching Algorithm ***\n");
    printf("Enter the string: ");
    fgets(st, 100, stdin);
    st[strcspn(st, "\n")] = '\0'; // remove trailing newline
    printf("Enter the pattern to match: ");
    fgets(pat, 100, stdin);
    pat[strcspn(pat, "\n")] = '\0'; // remove trailing newline
    status = match(st, pat);
    if (status == -1)
        printf("\nNo match found.\n");
    else
        printf("Match found at position %d.\n", status);
    return 0;
}
int match(char st[], char pat[])
{
    int n, m, i, j;
    n = strlen(st);
    m = strlen(pat);
    for (i = 0; i <= n - m; i++) {
        for (j = 0; j < m; j++) {
            if (st[i + j] != pat[j])
                break;
        }
        if (j == m)
            return i;
    }
    return -1;
}
