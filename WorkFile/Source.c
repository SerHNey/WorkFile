#include "Header.h"

int main() {
	system("chcp 1251 >null");
	char* fil� = "vvod.txt";
	FILE* fp;
	float a, b, c;
	int razdel = 0;

	if ((fil� = fopen("vvod.txt", "r")))
	{
		fseek(fil�, 0, SEEK_END); // ��������� ��������� � ����� �����
		long size = ftell(fil�); // ��������� ��������� ���������
		fseek(fil�, 0, SEEK_SET); // ������������� ��������� � ������ �����
		char* text = calloc(size, 1);
		for (size_t i = 0; i < size; i++) // ��������� ������
		{
			text[i] = fgetc(fil�);
		}
		for (size_t i = 0; i < size; i++) // ��������� ������ �� �����������
		{
			if (text[i] == '\n') {
				razdel = 1;
			}
			if (text[i] < -1 || text[i] >96) {
				printf("");
				return 1;
			}
		}
		fseek(fil�, 0, SEEK_SET);
		if (razdel == 1) {
			fscanf(fil�, "%f\n%f\n%f", &a, &b, &c);
			printf("a = %f\nb = %f\nc = %f", a, b, c);
		}
		else
		{
			fscanf(fil�, "%f %f %f", &a, &b, &c);
			printf("a = %f\nb = %f\nc = %f", a, b, c);
		}
	}
	if (a != 0) {
		kvadran_koren(a,b,c);
	}
	else
	{
		printf("\n��� ��� ����������� a = %f, �� ���������� ��������� �� ��������", a);
	}
	return 0;
}


int kvadran_koren(double a, double b, double c) {
	FILE* ovtev = fopen("otvet.txt", "w+t");
	double diskrimenant = sqrt(pow(b,2) - 4 * a * c);
	if (diskrimenant < 0) {
		fprintf(ovtev, "���, ��� ������������ = %f , ������ ��������� ���", diskrimenant);
		printf("\n�������������� ������ ���");
	}
	if (diskrimenant == 0) {
		c = (-b) / (2 * a);

		fprintf(ovtev, "��� ��� ������������ ����� =%f , �� ����� ��������� � ����� = %f", diskrimenant, c);
		printf("\n��� ��� ������������ ����� =%f , �� ����� x1,x2 ��������� � ����� = %f", diskrimenant, c);
	}
	if (diskrimenant > 0) {
		fprintf(ovtev, "������������ = %f ", diskrimenant);
		printf("\n������������ = %f ", diskrimenant);
		c = (-b + diskrimenant) / (2 * a);
		fprintf(ovtev, "x1 = %f", c);
		printf("\n������ ����� 1 = %f", c);
		c = (-b - diskrimenant) / (2 * a);
		fprintf(ovtev, "x2 = %f", c);
		printf("\n������ ����� 2 = %f\n", c);
	}
	fclose(ovtev);
	return 0;
}