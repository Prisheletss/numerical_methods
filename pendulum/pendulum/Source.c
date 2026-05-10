# define _CRT_SECURE_NO_WARNINGS
# define _USE_MATH_DEFINES

# include <stdio.h>
# include <math.h>

# pragma warning(disable : 4996)



int main(int argc, char argv[]) {
	printf("programm started\n\r");

	FILE* cords = fopen("cords.txt", "w");
	if (cords == NULL) {
		perror("Error opening file");
		return 1;
	}


	float f_1 = M_PI, d = 0.01f, A = 0, B = 10, w = 0.05f, f, f_2;
	f = f_1 + w*d;

	fprintf(cords, "%f %f\n", f, (f - f_1) / d);


	for (int i = 0; i < 2500; i++) {
		f_2 = (f*(2+A*d) - B*d*d*sin(f) - f_1) / (1 + A*d);

		f_1 = f;
		f = f_2;

		fprintf(cords, "%f %f\n", f, (f - f_1) / d);
	}


	fclose(cords);
	printf("programm finished");
	return 0;
}