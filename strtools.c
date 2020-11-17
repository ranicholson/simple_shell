#include "holberton.h"
/**
 * _strcmp - compares two strings
 * @s1: string 1
 * @s2: string 2
 *
 * Return: an int value less than greater to or equal to 0
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 == *s2)
		{
			s1++;
			s2++;
		}
		else
			return (-1);
	}
	return (0);
}
/**
 * _strdup - duplicates one string into another
 * @str: the string to be duplicated
 *
 * Return: a pointer to a duplicate of the string
 */
char *_strdup(char *str)
{
    char *ar;
    unsigned int i, size;

    if (str == NULL)
        return (NULL);
    for (size = 0; *(str + size) != '\0'; size++)
        ;
    ar = malloc((size + 1) * sizeof(char));
    if (ar == NULL)
        return (NULL);
    for (i = 0; str[i] != '\0'; i++)
    {
        ar[i] = str[i];
    }
    ar[i] = '\0';
    return (ar);
}
