#include "Header.h"

int main() {
	system("chcp 1251 >null");
	filewrite();
	char* filename = "vvod.txt";
	char cc[256];
	FILE* fp;
	float a, b, c;
	int bool = 0;
	if ((filename = fopen("vvod.txt", "r")))
	{
		fseek(filename, 0, SEEK_END);
		long size = ftell(filename);
		fseek(filename, 0, SEEK_SET);
		char* text = calloc(size, 1);
		for (size_t i = 0; i < size; i++)
		{
			text[i] = fgetc(filename);
		}
		for (size_t i = 0; i < size; i++)
		{
			if (text[i] == '\n') {
				bool = 1;
			}
			if (text[i] < -1 || text[i] >96) {
				printf("");
				return 1;
			}
		}
		fseek(filename, 0, SEEK_SET);
		if (bool == 1) {
			fscanf(filename, "%f\n%f\n%f", &a, &b, &c);
			printf("a = %f\nb = %f\nc = %f", a, b, c);
		}
		else
		{
			fscanf(filename, "%f %f %f", &a, &b, &c);
			printf("a = %f\nb = %f\nc = %f", a, b, c);
		}
	}
	kvadran_koren(a,b,c);

	return 0;
}
int filewrite()
	{
	float x1 = 1;
	FILE* answer = fopen("otvet.txt", "w+t");

	fprintf(answer, "x1 = %f", x1);
	//fputs(message, fp);

	fclose(answer);
	}

int fileread() {
	char* filename = "vvod.txt";
	char cc[256];
	FILE* fp; 

	if ((fp = fopen(filename, "r")) == NULL)
	{
		perror("Error occured while opening file");
		return 1;
	}
	// пока не дойдем до конца, считываем по 256 байт
	while ((fgets(cc, 256, fp)) != NULL)
	{
		printf("%s", cc);
	}
	fclose(fp);
	return 0;
}


int kvadran_koren(double a, double b, double c) {
	FILE* answer = fopen("otvet.txt", "w+t");

	


	double diskrimenant = sqrt(pow(b,2) - 4 * a * c);
	if (diskrimenant < 0) {
		printf("Действительных корней нет");
	}
	if (diskrimenant == 0) {
		c = (-b) / (2 * a);
		fprintf(answer, "x = %f", c);
		printf("Корень равен %f", c);
	}
	if (diskrimenant > 0) {
		c = (-b + diskrimenant) / (2 * a);
		fprintf(answer, "x1 = %f", c);
		printf("\nКорень равен 1 %f\n", c);
		c = (-b - diskrimenant) / (2 * a);
		fprintf(answer, "x2 = %f", c);
		printf("\nКорень равен 2 %f\n", c);
	}
	fclose(answer);
	return 0;
}