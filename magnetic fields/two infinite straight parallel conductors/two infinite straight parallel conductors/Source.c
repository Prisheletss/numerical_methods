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


	float d = 0.00005f, a = -1, t;
	float s0, sa, s, Bx, By, handler;
	float x, y;



	for (int x0 = 0; x0 < 2; x0++)
	{
		for (int i = 0; i < 5; i++) {
			x = x0;
			y = d + 0.125*i + 0.125;

			fprintf(cords, "%f %f\n", x, y);

			t = 25000 + 25000 * i;
			for (int j = 0; j < t; j++) {
				s0 = 1 / (x * x + y * y);
				sa = a / ((x - 1) * (x - 1) + y * y);
				s = s0 + sa;

				Bx = -y * s;
				By = x * s - sa;

				x += d * Bx;
				y += d * By;

				fprintf(cords, "%f %f\n", x, y);
			}
		}
	}
	



	fclose(cords);
	printf("programm finished");
	return 0;
}