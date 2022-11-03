#include "Header.h"

int main() {
	system("chcp 1251 >null");
	char* filе = "vvod.txt";
	FILE* fp;
	float a, b, c;
	int razdel = 0;

	if ((filе = fopen("vvod.txt", "r")))
	{
		fseek(filе, 0, SEEK_END); // Переносит указатель в конец файла
		long size = ftell(filе); // Возращает положение указателя
		fseek(filе, 0, SEEK_SET); // Устанавливает указатель в начало файла
		char* text = calloc(size, 1);
		for (size_t i = 0; i < size; i++) // Считываем строку
		{
			text[i] = fgetc(filе);
		}
		for (size_t i = 0; i < size; i++) // Проверяем строку на разделители
		{
			if (text[i] == '\n') {
				razdel = 1;
			}
			if (text[i] < -1 || text[i] >96) {
				printf("");
				return 1;
			}
		}
		fseek(filе, 0, SEEK_SET);
		if (razdel == 1) {
			fscanf(filе, "%f\n%f\n%f", &a, &b, &c);
			printf("a = %f\nb = %f\nc = %f", a, b, c);
		}
		else
		{
			fscanf(filе, "%f %f %f", &a, &b, &c);
			printf("a = %f\nb = %f\nc = %f", a, b, c);
		}
	}
	if (a != 0) {
		kvadran_koren(a,b,c);
	}
	else
	{
		printf("\nТак как коэффициент a = %f, то квадратное уравнение не решается", a);
	}
	return 0;
}


int kvadran_koren(double a, double b, double c) {
	FILE* ovtev = fopen("otvet.txt", "w+t");
	double diskrimenant = sqrt(pow(b,2) - 4 * a * c);
	if (diskrimenant < 0) {
		fprintf(ovtev, "Так, как дискриминант = %f , корней уравнения нет", diskrimenant);
		printf("\nДействительных корней нет");
	}
	if (diskrimenant == 0) {
		c = (-b) / (2 * a);

		fprintf(ovtev, "Так как дискрименант равен =%f , то корни одинаковы и равны = %f", diskrimenant, c);
		printf("\nТак как дискрименант равен =%f , то корни x1,x2 одинаковы и равны = %f", diskrimenant, c);
	}
	if (diskrimenant > 0) {
		fprintf(ovtev, "Дискриминант = %f ", diskrimenant);
		printf("\nДискриминант = %f ", diskrimenant);
		c = (-b + diskrimenant) / (2 * a);
		fprintf(ovtev, "x1 = %f", c);
		printf("\nКорень равен 1 = %f", c);
		c = (-b - diskrimenant) / (2 * a);
		fprintf(ovtev, "x2 = %f", c);
		printf("\nКорень равен 2 = %f\n", c);
	}
	fclose(ovtev);
	return 0;
}