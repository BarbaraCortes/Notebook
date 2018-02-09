/* Zeller's algorithm determines the day of the week for a given a day, month and year */
enum {SABADO, DOMINGO, SEGUNDA, TERCA, QUARTA, QUINTA, SEXTA};

int day_of_week(int d, int m, int y) {
	if (m == 1 || m == 2) {
		m += 12;
		y--;
	}
	int K = y%100;
	int J = y/100;
	return (d + (m+1)*26/10 + K + (K)/4 + J/4 - 2*J) % 7;
}
