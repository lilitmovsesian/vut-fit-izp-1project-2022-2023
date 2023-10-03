/*
Lilit Movsesian
xmovse00
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define size 60
int isvalidarg (int arg, char arg2[]);
int comparethesymbols (char contact[], int lenc, char argv2[]);

typedef struct {
char arr[101];
}Contacttonum;

Contacttonum changename (int len, char names2[]);
Contacttonum changetel (int len, char tel2[]);

int main (int argc, char* argv[])
{
/*The main function reads the data from stdin using fgets
and copies it to two strings. For cycle performs the
comparison by calling the functions described below*/
	int i=0, k, f=0;
	char names [size][102];
	char tel [size][102];
	char buffer[102];
	if (!isvalidarg (argc, argv[1]))
		return 1;
	while ((i < size) && (fgets (buffer, 102, stdin) != NULL))
	{
		buffer[strcspn(buffer, "\r\n")] = '\0';
		strcpy (names[i], buffer);
		fgets (buffer, 102, stdin);
		buffer[strcspn(buffer, "\r\n")] = '\0';
		strcpy (tel[i], buffer);
		i++;
	}
	if (argc == 1)
	{
		for (k=0; k<i; k++)
		{
			printf ("%s, %s\n", names[k], tel[k]);
		}
		return 0;
	}
	printf ("Contacs found:\n\n");
	for (k=0; k<i; k++)
	{
		Contacttonum nn = changename ((int)strlen(names[k]), names[k]);
		Contacttonum ll =  changetel ((int)strlen(tel[k]),  tel[k]);
		if (comparethesymbols (nn.arr,(int)strlen(names[k]), argv[1]) || comparethesymbols (ll.arr,(int)strlen(tel[k]), argv[1]))
		{
			printf ("%s, %s\n", names[k], tel[k]);
			f = 1;
		}
	}
	if (f == 0)
		printf ("Not found\n");
	return 0;
}

int comparethesymbols (char contact[], int lenc, char argv2[])
{
/*This function compares the symbols of contact and t9
search argument using strstr. To avoid errors caused
by writing additional characters to strings, I used
this mechanism which ignores the similarities beyond
the length of the name or telephone number */
	int lena = strlen(argv2);
	char *sub;
	sub = strstr (contact, argv2);
	if (sub != NULL)
	{
		int position = sub - contact;
		if (position + lena <= lenc)
			return 1;
		else
			return 0;
	}
	else
		return 0;
}

Contacttonum changetel (int len, char tel2[])
{
/*This function changes plus sign in telephone number,
writes it to a string by index,then copies it to a
structure and returns the
resulting structure */
	Contacttonum tel;
	char temptel[len];
	strcpy (temptel, tel2);
	for (int i=0; i<len; i++)
	{
		if (temptel[i] == '+')
			temptel[i] = '0';
	}
	strcpy (tel.arr, temptel);
	return tel;
}

Contacttonum changename (int len, char names2[])
{
/*This function changes every letter of the name
to a digit sign, writes it to a string by index,
then copies it to a structure and returns the
resulting structure */
	Contacttonum namesnum;
	char newname[len];
	for (int i=0; i<len; i++)
	{
		switch (names2[i])
		{
			case 'a':
			case 'A':
			case 'b':
			case 'B':
			case 'c':
			case 'C':
			newname[i] = '2';
			break;
			case 'd':
			case 'D':
			case 'e':
			case 'E':
			case 'f':
			case 'F':
			newname[i] = '3';
			break;
			case 'g':
			case 'G':
			case 'h':
			case 'H':
			case 'i':
			case 'I':
			newname[i] = '4';
			break;
			case 'j':
			case 'J':
			case 'k':
			case 'K':
			case 'l':
			case 'L':
			newname[i] = '5';
			break;
			case 'm':
			case 'M':
			case 'n':
			case 'N':
			case 'o':
			case 'O':
			newname[i] = '6';
			break;
			case 'p':
			case 'P':
			case 'q':
			case 'Q':
			case 'r':
			case 'R':
			case 's':
			case 'S':
			newname[i] = '7';
			break;
			case 't':
			case 'T':
			case 'u':
			case 'U':
			case 'v':
			case 'V':
			newname[i] = '8';
			break;
			case 'w':
			case 'W':
			case 'x':
			case 'X':
			case 'y':
			case 'Y':
			case 'z':
			case 'Z':
			newname[i] = '9';
			break;
			default:
			newname[i] = '-';
			break;
		}
	}
	strcpy (namesnum.arr, newname);
	return namesnum;
}

int isvalidarg (int arg, char arg2[])
{
/*This function terminates the program if
there are too many arguments or argument
contains invalid characters*/
	for (int i=0; i<(int)strlen(arg2); i++)
	{
		if (arg2[i] != '0' && arg2[i] != '1' && arg2[i] != '2' && arg2[i] != '3' && arg2[i] != '4' && arg2[i] != '5' && arg2[i] != '6' && arg2[i] != '7' && arg2[i] != '8' && arg2[i] != '9')
		{
			printf ("Invalid argument.\n");
			return 0;
		}
	}
	if (arg > 2)
	{
		printf ("Too many arguments for the program.\n");
		return 0;
	}
	else
		return 1;
}
