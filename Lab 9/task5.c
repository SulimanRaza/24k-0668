#include <stdio.h>
#include <string.h>
int main(void)
{
    char text[100], cipher_text[100], keyword[50], expanded_key[100];
    printf("Enter sentence: ");
    fgets(text, 100, stdin);
    text[strcspn(text, "\n")] = '\0';
    printf("\n Enter key: ");
    fgets(keyword, 50, stdin);
    keyword[strcspn(keyword, "\n")] = '\0';

    int text_len = strlen(text), key_len = strlen(keyword);
    int text_vals[text_len], key_vals[text_len], cipher_vals[text_len];
    char final_cipher[text_len];

    for (int i = 0; i < text_len; i++)
    {
        if (text[i] >= 'a' && text[i] <= 'z')
        {
            text[i] = text[i] - 32;
        }
    }

    for (int i = 0; i < key_len; i++)
    {
        if (keyword[i] >= 'a' && keyword[i] <= 'z')
        {
            keyword[i] = keyword[i] - 32;
        }
    }

    for (int i = 0; i < text_len; i++)
    {
        if (text[i] == ' ')
        {
            text_vals[i] = 20;
        }
        else
        {
            text_vals[i] = (int)text[i];
        }
    }

    int key_index = 0;
    for (int i = 0; i < text_len; i++)
    {
        if (key_index == key_len)
        {
            key_index = 0;
        }
        expanded_key[i] = keyword[key_index];
        key_index++;
    }

    for (int i = 0; i < text_len; i++)
    {
        if (expanded_key[i] == ' ')
        {
            key_vals[i] = 20;
        }
        else
        {
            key_vals[i] = (int)expanded_key[i];
        }
    }

    for (int i = 0; i < text_len; i++)
    {
        if (text_vals[i] == 20)
        {
            continue;
        }
        else
        {
            text_vals[i] = text_vals[i] - 64;
        }
    }

    for (int i = 0; i < text_len; i++)
    {
        if (key_vals[i] == 20)
        {
            continue;
        }
        else
        {
            key_vals[i] = key_vals[i] - 64;
        }
    }

    for (int i = 0; i < text_len; i++)
    {
        cipher_vals[i] = text_vals[i] + key_vals[i];
    }

    for (int i = 0; i < text_len; i++)
    {
        cipher_vals[i] = cipher_vals[i] % 26;
    }

    for (int i = 0; i < text_len; i++)
    {
        cipher_vals[i] = cipher_vals[i] + 64;
    }

    for (int i = 0; i < text_len; i++)
    {
        final_cipher[i] = (char)cipher_vals[i];
    }

    printf("\n Finally, Our Ciphertext would be: \n");
    for (int i = 0; i < text_len; i++)
    {
        printf("%c", final_cipher[i]);
    }
}
