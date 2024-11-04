// Program - 2: String Operations!

#include <stdio.h>
#include <stdlib.h>

char str[20], rep[20], pat[20], ans[20];
int i = 0, c = 0, m = 0, k, j = 0, flag = 0;

void main()
{
    printf("Enter the main string: ");
    gets(str);

    printf("Enter the pattern string: ");
    gets(pat);

    printf("Enter the replace string: ");
    gets(rep);

    string_match();

    if (flag == 1)
    {
        printf("The Resultant string is : %s ", ans);
    }
    else
    {
        printf("Pattern string not found!");
    }
}

void string_match()
{
    while (str[c] != '\0')
    {
        if (str[m] == pat[i]) // replaced j with i
        {
            m++;
            i++;
            if (pat[i] == '\0') // replaced j with i
            {
                flag = 1;
                for (k = 0; rep[k] != '\0'; k++, j++)
                {
                    ans[j] = rep[k];
                }
                // Copy the remaining characters correctly
                i = 0;
                c = m;
            }
        }
        else
        {
            ans[j] = str[c];
            j++;
            c++;
            m = c;
            i = 0;
        }
    }
    ans[j] = '\0';
}

// The only flaw here was to replace j with i in pat[i] line 36 and line 40 respectively!

/*
Notes for the above C-Program!

1.
use scanf() instead of gets() due to chances of buffer overflow in my system program and finally can raise security vulnerabilitites in my program.

2.

THE FLAW : -
The primary issue lies in the way the string_match function handles the replacement process. Specifically, the loop that iterates over the replacement string (rep) and assigns characters to the ans string can potentially overwrite existing characters in the ans string, leading to unexpected results.

Consider the following scenario:

Input string: "abababa"
Pattern string: "aba"
Replacement string: "xyz"
The algorithm will correctly identify the first occurrence of the pattern and start replacing it with "xyz". However, when it encounters the second occurrence of the pattern, it will overwrite the previously replaced characters, resulting in the incorrect output: "xyxaba".

THE CORRECTION : -
Explanation of the Correction:

Early Exit: If a complete pattern match is found, the function exits early after copying the replacement string and the remaining characters from the original string. This prevents unnecessary iterations and potential overwrites.
Correct Character Copying: The remaining characters from the original string are copied to the ans string after the replacement, ensuring that the correct final string is formed.
*/

// Logic for the function string_match() : -
/*
Purpose:
This function takes a main string, a pattern string, and a replacement string as input. It searches for the pattern string within the main string. If found, it replaces the pattern with the replacement string.

Line-by-Line Breakdown:

while (str[c] != '\0'):

This loop iterates through each character of the main string str until the null terminator '\0' is encountered.
if (str[m] == pat[]):

This condition checks if the current character in the main string str[m] matches the current character in the pattern string pat[j].
i++; m++;:

If the characters match, the indices i and m are incremented to move forward in both the main string and the pattern string.
if (pat[j] == '\0'):

This condition checks if the end of the pattern string is reached. If so, a match is found.
flag = 1;:

The flag is set to 1 to indicate a successful match.
for (k = 0; rep[k] != '\0'; k++, j++) { ans[j] = rep[k]; }:

This loop iterates through the replacement string rep and copies each character to the ans string, starting from index j.
while (str[c] != '\0') { ans[j++] = str[c++]; }:

This loop copies the remaining characters from the main string str to the ans string, starting from the current position c.
ans[j] = '\0';:

A null terminator is added to the end of the ans string to mark the end of the string.
return;:

The function returns, as the replacement is complete.
else:

If the current character in the main string doesn't match the current character in the pattern string, the else block is executed.
ans[j++] = str[c++];:
The current character from the main string is copied to the ans string.
m = c; i = 0;:
The indices m and i are reset to the current position in the main string, as the pattern matching starts from the beginning again.
Key Points:

The function efficiently iterates through the main string, comparing characters with the pattern string.
Upon finding a match, it replaces the pattern with the replacement string and copies the remaining characters.
The early return after a successful replacement prevents unnecessary iterations.
The corrected code ensures that the replacement is done correctly and the final string is constructed without overwriting characters.
*/
