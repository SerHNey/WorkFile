#include "Header.h"

int main() {
	system("chcp 1251 >null");
	kvadran_koren();
	fileread();
	return 0;
}
int filewrite()
	{
	FILE* fp;
	char* message = "";
	char* filename = "C://Users/admin/source/repos/WorkFile/WorkFile/vvod.txt";
	if ((fp = fopen(filename, "r")) == NULL)
	{
		perror("Error occured while opening data28.txt");
		exit(0);
	}
	fputs(message, fp);

	fclose(fp);
	}

int fileread() {
	char* message = "";	
	char* filename = "C://Users/admin/source/repos/WorkFile/WorkFile/vvod.txt";
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


int kvadran_koren() {
	double a = 3;
	double b = -14;
	double c = -5;
	double diskrimenant = sqrt(pow(b,2) - 4 * a * c);

	if (diskrimenant < 0) {
		printf("Действительных корней нет");
	}
	if (diskrimenant == 0) {
		c = (-b) / (2 * a);
		printf("Корень равен %f", c);
	}
	if (diskrimenant > 0) {
		c = (-b + diskrimenant) / (2 * a);
		printf("Корень равен 1 %f\n", c);
		c = (-b - diskrimenant) / (2 * a);
		printf("Корень равен 2 %f\n", c);
	}
	return 0;
}