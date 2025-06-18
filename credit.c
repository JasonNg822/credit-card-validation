#include <stdio.h>
#include <string.h>
#include "cs50.h"

int luhn (string card);
int luhn_vm (string card);

int main (void)
{
    string card = get_string("Number: ");
    if (strlen(card) == 15 && luhn(card) && card[0] == '3' && (card[1] == '4' || card[1] == '7'))
    {
        printf("American Express\n");
    }
    else if (strlen(card) == 16 && card[0] == '5' && (card[1] == '1' || card[1] == '2' || card[1] == '3' || card[1] == '4' || card[1] == '5'))
    {
        printf("Master Card\n");
    }
    else if (strlen(card) == 13 && luhn(card) && card[0] == '4')
    {
        printf("Visa Card\n");
    }
    else if (strlen(card) == 16 && luhn_vm(card) && card[0] == '4')
    {
        printf("Visa Card\n");
    }
    else
    {
        printf("INVALID\n");
    }
}


int luhn (string card)
{
    int sum = 0;
    int total = 0;
    char a = card[1];
    char b = card[3];
    char c = card[5];
    char d = card[7];
    char e = card[9];
    char f = card[11];
    char g = card[13];
    int a0 = 0;

    int a1[] = {(card[1] - 48) * 2,
                (card[3] - 48) * 2,
                (card[5] - 48) * 2,
                (card[7] - 48) * 2,
                (card[9] - 48) * 2,
                (card[11] - 48) * 2,
                (card[13] - 48) * 2,};

    int a2[] = {(card[0] - 48),
                (card[2] - 48),
                (card[4] - 48),
                (card[6] - 48),
                (card[8] - 48),
                (card[10] - 48),
                (card[12] - 48),
                (card[14] - 48)};

    for (int i = 0; i < strlen(card)/2; i++)
    {
        if (a1[i] >= 10)
        {
            int tens = a1[i]/10;
            int ones = a1[i] % 10;
            a1[i] = tens + ones;
        }
        sum += a1[i];
    }
    for (int j = 0; j < (strlen(card)/2) + 1; j++)
    {
        total += a2[j];
    }
    int final = sum + total;
    if (final % 10 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


int luhn_vm (string card)
{
    int sum = 0;
    int total = 0;
    char a = card[0];
    char b = card[2];
    char c = card[4];
    char d = card[6];
    char e = card[8];
    char f = card[10];
    char g = card[12];
    char h = card[14];
    int a0 = 0;

    int a1[] = {(card[0] - 48) * 2, 
                (card[2] - 48) * 2, 
                (card[4] - 48) * 2, 
                (card[6] - 48) * 2, 
                (card[8] - 48) * 2, 
                (card[10] - 48) * 2, 
                (card[12] - 48) * 2, 
                (card[14] - 48) * 2};

    int a2[] = {(card[1] - 48), 
                (card[3] - 48), 
                (card[5] - 48), 
                (card[7] - 48), 
                (card[9] - 48), 
                (card[11] - 48), 
                (card[13] - 48), 
                (card[15] - 48)};
                
    for (int i = 0; i < 8; i++)
    {
        if (a1[i] >= 10)
        {
            int tens = a1[i]/10;
            int ones = a1[i] % 10;
            a1[i] = tens + ones;
        }
        sum += a1[i];
    }
    for (int j = 0; j < 8; j++)
    {
        total += a2[j];
    }
    int final = sum + total;
    if (final % 10 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
