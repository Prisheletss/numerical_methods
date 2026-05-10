# define _CRT_SECURE_NO_WARNINGS
# define _USE_MATH_DEFINES

# include <stdio.h>
# include <math.h>

# pragma warning(disable : 4996)



float curve(float x, float b) {
	return x * tan(b);
}



int main(int argc, char argv[]) {
	FILE* file = fopen("cords.txt", "w");
	if (file == NULL) {
		perror("Error opening file");
		return 1;
	}

	printf("procces started");

	float x_1 = 0, y_1 = 0, d = 0.001f, a = 0.1f, f = M_PI/4, b = -M_PI/6, v = 15, g = 10, x_2, y_2, x, y, x_3, y_3, x_4, y_4;
	x = x_1 + v * d * cos(f);
	y = y_1 + v * d * sin(f);


	fprintf(file, "%f %f\n%f %f\n", x_1, y_1, x, y);

	int bounces = 0, i = 0;
	while ((y >= curve(x, b)) && (i < 10000)) {
		i++;
		x_2 = (x * (2 + a * d) - x_1) / (1 + a * d);
		y_2 = (y * (2 + a * d) - y_1 - g * d * d) / (1 + a * d);

		y_1 = y;
		y = y_2;
		x_1 = x;
		x = x_2;

		if (y <= curve(x, b)) {
			bounces++;

			if (b != 0) {
				// intersection
				x_2 = (y - (y_1 - y) * x / (x_1 - x)) / (tan(b) - (y_1 - y) / (x_1 - x));
				y_2 = x_2 * tan(b);

				x_3 = cos(b)*cos(b) * (x_1*tan(b)*tan(b) + 2*(y_2-y_1)*tan(b) + 2*x_2 - x_1);
				y_3 = y_1 + (x_3-x_1)*tan(b);

				x_4 = cos(b)*cos(b) * (x*tan(b)*tan(b) + 2*(y_2-y)*tan(b) + 2*x_2 - x);
				y_4 = y + (x_4-x) * tan(b);

				x = x_3, y = y_3;
				x_1 = x_4, y_1 = y_4;
			}
			else if (b == 0) {
				y_1 = -y_1;
				y = -y;
			}
		}

		fprintf(file, "%f %f\n", x, y);
	}
	printf(" %d; %f v %f; %d", i, y, x * tan(b), bounces);


	// line
	for (float j = 0; j < x; j += 0.5f) {
		fprintf(file, "%f %f\n", j, j * tan(b));
	}


	fclose(file);
	return 0;
}