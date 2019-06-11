#include "stdio.h"
#include "locale.h"

//enum Exam { TFKP, FOE, STU, VM, MotEPIV, EKOLOGY };
enum MarkEnum { A = 5, B = 4, C = 3, D = 2};

struct BookList
{
	char *exam;
	char *hasPassed;
	enum MarkEnum mark;
};

struct RecordBook
{
	char* lastName;
	char* firstName;
	char* middleName;
	int number;
	struct BookList bookList[3][2];
};

int main()
{
	setlocale(LC_ALL, "RUS");

	struct RecordBook rb;
	rb.lastName = "������";
	rb.firstName = "�������";
	rb.middleName = "��������";
	rb.number = 17168;

	printf("�������� ������ �%d\n", rb.number);
	printf("��� ��������: %s %s %s\n\n", rb.lastName, rb.firstName, rb.middleName);
	
	rb.bookList[0][0].exam = "��������"; rb.bookList[0][0].hasPassed = "��ר�"; rb.bookList[0][0].mark = A;
	rb.bookList[0][1].exam = "���"; rb.bookList[0][1].hasPassed = "�� ��ר�"; rb.bookList[0][1].mark = D;

	rb.bookList[1][0].exam = "��"; rb.bookList[1][0].hasPassed = "��ר�"; rb.bookList[1][0].mark = B;
	rb.bookList[1][1].exam = "������"; rb.bookList[1][1].hasPassed = "��ר�"; rb.bookList[1][1].mark = C;

	rb.bookList[2][0].exam = "����"; rb.bookList[2][0].hasPassed = "��ר�"; rb.bookList[2][0].mark = B;
	rb.bookList[2][1].exam = "�������"; rb.bookList[2][1].hasPassed = "��ר�"; rb.bookList[2][1].mark = A;
	

	for (int i = 0; i < 3; i++)
	{
		printf("%d �������:\n", i + 1);
		for (int j = 0; j < 2; j++)
		{
			printf("%s ", rb.bookList[i][j].exam);
			printf("%s ", rb.bookList[i][j].hasPassed);
			printf("%d ", rb.bookList[i][j].mark);
			printf("\n");
		}
		printf("\n");
	}


	return 0;
}