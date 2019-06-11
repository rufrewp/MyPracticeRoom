#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include <malloc.h>
void incrementHeapVariable()
{
	int* numberPointer = (int*)malloc(sizeof(int));
	scanf_s("%d", numberPointer);
	printf("%x %d ", numberPointer, *numberPointer);
	*numberPointer += 1;
	printf("%x %d", numberPointer, *numberPointer);
	free(numberPointer);
}
void writeArray(int* arr, int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}
void readArray(int* arr, int n)
{
	int i;
	for (i = 0; i < n; i++)
		scanf_s("%d", arr + i);
}
void sort(int* arr, int n) //Bubble sort
{
	int i;
	int buff;
	_Bool unsorted;
	do
	{
		unsorted = false;
		for (i = 0; i < n - 1; i++)
			if (arr[i] > arr[i + 1])
			{
				unsorted = true;
				break;
			}
		if (unsorted)
		{
			for (i = 0; i < n - 1; i++)
				if (arr[i] > arr[i + 1])
				{
					buff = arr[i];
					arr[i] = arr[i + 1];
					arr[i + 1] = buff;
				}
		}
		else
			break;

	} while (unsorted);
}

void sortHeapArray(int* arr, int n)
{
	readArray(arr, n);
	printf("%d\n", n);
	writeArray(arr, n);
	sort(arr, n);
	writeArray(arr, n);
}
int strlen(const char* str)
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
char* find(const char* str, const char* substr)
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

char* delete(char* str, const char* substr)
{
	int i = 0;
	int j = 0;
	int str_length = strlen(str);
	int substr_length = strlen(substr);
	char* index = find(str, substr);
	char* newstr;
	if (index == NULL)
		return NULL;
	newstr = (char*)malloc(str_length - substr_length + 1);
	for (;;)
	{
		if (str + i == index)
			break;
		newstr[i] = str[i];
		i++;
	}
	for (;;)
	{
		newstr[i] = index[substr_length + j];
		if (index[substr_length + i] == 0)
			break;
		i++;
		j++;
	}
	return newstr;
}
char* strcpy(const char* src)
{
	int i = 0;
	int len = strlen(src);
	char* newstr = (char*)malloc(len * sizeof(char) + 1);
	for (i = 0; i < len; i++)
	{
		newstr[i] = src[i];
	}
	return newstr;
}
char* strcat(const char* first, const char* second)
{
	int i = 0;
	int first_length = strlen(first);
	int second_length = strlen(second);
	char* newstr = (char*)malloc((first_length + second_length) * sizeof(char) + 1);
	for (i = 0; i < first_length; i++)
	{
		newstr[i] = first[i];
	}
	for (i = 0; i < second_length; i++)
	{
		newstr[first_length + i] = second[i];
	}
	newstr[first_length + i] = 0;
	return newstr;
}

char* insert(const char* src, const char* str, int index)
{
	int i = 0;
	int j = 0;
	char* newstr = (char*)malloc((strlen(src) + strlen(str)) * sizeof(char) + 1);
	while (i < index)
	{
		newstr[i] = src[i];
		i++;
	}
	while (str[j] != 0)
	{
		newstr[i] = str[j];
		i++;
		j++;
	}
	j = index;
	while (src[j] != 0)
	{
		newstr[i] = src[j];
		i++;
		j++;
	}
	newstr[i] = 0;
	return newstr;
}
int main()
{
	int N;
	int* arr;
	printf("string size: ");
	scanf_s("%d", &N);
	arr = (int*)malloc(N * sizeof(int));
	sortHeapArray(arr, N);
	free(arr);
	printf("type any nubmer:");
	incrementHeapVariable();
	_getch();
}