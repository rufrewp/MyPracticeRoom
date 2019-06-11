#include <stdio.h>
#include <math.h>
int strlen(const char *str)
{
	int count = 0;
	int i = 0;
	while (str[i] != 0)
	{
		count++;
		i++;
	}
	return count;
}
char *find(const char *str, const char *substr)
{
	int i = 0;
	int j = 0;
	int result = -1;

	while (substr[j] != 0)
	{
		if (str[i] == 0)
			return NULL;

		if (str[i] == substr[j])
		{
			if (result == -1)
				result = i;
			i++;
			j++;
		}
		else if (result != -1)
		{
			i = result + 1;
			j = 0;
			result = -1;
		}
		else
			i++;
	}
	return str + result;
}
void delete(const char *str, const char *substr)
{
	int i = 0;
	int j;
	int substr_length = strlen(substr);
	char *index = find(str, substr);
	if (index == NULL)
		return;
	int f = 1;
	for (int i = 0; i < f; ++i)
	{
		++f;
		index[i] = index[substr_length + i];
		if (index[substr_length + i] == 0)
			break;
	}
	for (j = 1; j < substr_length; j++)
	{
		index[i + j] = 0;
	}
}
void strcpy(char *dest, int len, const char *src)
{
	int i = 0;

	for (i = 0; i < len - 1; i++)
	{
		dest[i] = src[i];
		if (src[i] == 0)
			return;
	}
	dest[i] = 0;
}
void strcat(char *dest, int len, const char *first, const char *second)
{
	int i = 0;
	int first_length = strlen(first);
	for (i = 0; i < len - 1; i++)
	{
		if (i < first_length)
			dest[i] = first[i];
		else
		{
			dest[i] = second[i - first_length];
			if (second[i - first_length] == 0)
				return;
		}
	}
	dest[i] = 0;
}
_Bool insert(const char *src, const char *str, int index, char *dest, int len)
{
	int i = 0;
	int j = 0;
	if ((strlen(src) + strlen(str) + 1 > len) || (index < 0 || index > strlen(src) - 1))
		return 0;

	while (i < index)
	{
		dest[i] = src[i];
		i++;
	}
	while (str[j] != 0)
	{
		dest[i] = str[j];
		i++;
		j++;
	}
	j = index;
	while (src[j] != 0)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = 0;
	return 1;
}
void main()
{
	char string[100];
	char substring[100];
	char buffstring[200];
	printf("String: ");
	gets(string);
	printf("\n substring : ");
	gets(substring);
	printf("\n\n strlen function calculated initial string length");
	printf("\n\t returned %d", strlen(string));
	printf("\n\n find function searched for substring in the initial string");
	printf("\n\t returned adress %x", find(string, substring));
	if (find(string, substring) != NULL)
		printf("\n\twhich is position #%d in initial string", find(string, substring) - string + 1);
	printf("\n\nstrcpy function copied initial string in buffstring");
	strcpy(buffstring, 200, string);
	printf("\n\twith non-limiting buffer length value (200)");
	printf("\n\t\tbuffstring content: %s", buffstring);
	strcpy(buffstring, strlen(string) / 2 + 1, string);
	printf("\n\twith limiting buffer length value (%d)", strlen(string) / 2 + 1);
	printf("\n\t\tbuffstring content: %s", buffstring);
	printf("\n\nstrcat function concatenated initial string & substring into buffstring");
	strcat(buffstring, 200, string, substring);
	printf("\n\twith non-limiting buffer length value (200)");
	printf("\n\t\tbuffstring content: %s", buffstring);
	strcat(buffstring, strlen(string) + strlen(substring) / 2, string, substring);
	printf("\n\twith limiting buffer length value (%d)", strlen(string) + strlen(substring) / 2);
	printf("\n\t\tbuffstring content: %s", buffstring);
	printf("\n \n insert function tried to insert substring into initial string");
	printf("\n \t using non-limiting buffer length value (200) & correct index (%d)", strlen(string) / 2);
	printf("\n \t \t returned %s", insert(string, substring, strlen(string) / 2, buffstring, 200) ? "true" : "false");
	printf("\n \t \t buffstring content: %s", buffstring);
	printf("\n \t using limiting buffer length value (%d)", (strlen(string) + strlen(substring)) / 4 * 3);
	printf("\n \t\ treturned %s", insert(string, substring, strlen(string) / 2, buffstring, (strlen(string) + strlen(substring)) / 4 * 3) ? "true" : "false");
	printf("\n \t using incorrect index (%d)", strlen(string) + 5);
	printf("\n \t \t returned %s", insert(string, substring, strlen(string) + 5, buffstring, 200) ? "true" : "false");
	printf("\n \n delete function tried to remove substring from initial string");
	delete(string, substring);
	printf("\n \t string content: %s", string);	
	_getch();
}
