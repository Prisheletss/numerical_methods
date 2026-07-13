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


	float f_1 = M_PI/3, d = 0.01f, k = 5, L = 10, g = 10, w = 0, f, f_2;
	f = f_1 + w * d;

	fprintf(cords, "%f %f %f %f\n", f, w, 0, 0);

	float x_2, x_1 = 0, x = 0;


	for (int i = 0; i < 5000; i++) {
		f_2 = (1/2) * (f-f_1)*(f-f_1) + (k*g/L) * d*d * sin(2*f);
		f_2 /= cos(f)*cos(f) - k;
		f_2 += 2*f - f_1;

		x_2 = L * (f_2 - 2*f + f_1) + g*d*d * sin(f);
		x_2 /= -cos(f);
		x_2 += 2*x - x_1;


		f_1 = f;
		f = f_2;

		x_1 = x;
		x = x_2;


		fprintf(cords, "%f %f %f %f\n", f, (f - f_1) / d, x, (x-x_1)/d);
	}


	fclose(cords);
	printf("programm finished");
	return 0;
}