# define _CRT_SECURE_NO_WARNINGS
# define _USE_MATH_DEFINES

# include <stdio.h>
# include <math.h>

//# pragma warning(disable : 4996)



int main(int argc, char argv[]) {
	printf("programm started\n\r");

	FILE* cords = fopen("cords.txt", "w");
	if (cords == NULL) {
		perror("Error opening file");
		return 1;
	}


	float x_1 = 100, y_1 = 0, d = 0.05f, g = 100, a = 0.0004f, f = M_PI / 2, v = 1, x, y, x_2, y_2;
	x = x_1 + v*d * cos(f);
	y = y_1 + v*d * sin(f);

	fprintf(cords, "%f %f\n%f %f\n", x_1, y_1, x, y);


	for (int i = 0; i < 25000; i++) {
		x_2 = (x * (2 - g*d*d / pow(x*x + y*y, 1.5) + a*d) - x_1) / (1 + a*d);
		y_2 = (y * (2 - g*d*d / pow(x*x + y*y, 1.5) + a*d) - y_1) / (1 + a*d);

		fprintf(cords, "%f %f\n", x_2, y_2);

		x_1 = x, y_1 = y;
		x = x_2, y = y_2;
	}


	fclose(cords);
	printf("programm finished");
	return 0;
}