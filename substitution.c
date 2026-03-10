#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int invalid(string s);
string encrypt(string a, string b);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else
    {
        if (invalid(argv[1]) == 1)
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }
        else
        {
            string p = get_string("plaintext:  ");
            string c = encrypt(p, argv[1]);
            printf("ciphertext: %s\n", c);
        }
    }
    return 0;
}

int invalid(string s)
{
    int flag = 0;
    int length = strlen(s);
    if (length != 26)
    {
        flag = 1;
        return flag;
    }
    else
    {
        int a[26] = {0};
        for (int i = 0; i < length; i++)
        {
            // Any character isn't an alphabet
            if (!isalpha(s[i]))
            {
                flag = 1;
                return flag;
            }
            // Exists more than once
            else
            {
                // How many times does the letter exists
                int d = toupper(s[i]) - 'A';
                a[d]++;
            }
        }
        for (int i = 0; i < 26; i++)
        {
            if (a[i] != 1)
            {
                flag = 1;
                return flag;
            }
        }
    }
    return flag;
}

string encrypt(string a, string b)
{
    int length = strlen(a);
    for (int i = 0; i < length; i++)
    {
        if (islower(a[i]))
        {
            a[i] = tolower(b[a[i] - 'a']);
        }
        else if (isupper(a[i]))
        {
            a[i] = toupper(b[a[i] - 'A']);
        }
        else
        {
            continue;
        }
    }
    return a;
}