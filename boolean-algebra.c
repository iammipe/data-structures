#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include <math.h>

int gcd(int, int);
int lcm(int, int);
void distributivnost(int, int, int);
void distributivnost2(int, int, int);
void komutativnostGCD(int, int);
void komutativnostLCM(int, int);

int main() {
	int num1, num2, num3;

	printf("Upisite tri broja iz skupa B = {1,2,3,5,6,10,15,30}\n");

	printf("\n");
	printf("Upisite prvi broj: ");
	scanf("%d", &num1);
	printf("Upisite drugi broj: ");
	scanf("%d", &num2);
	printf("Upisite treci broj: ");
	scanf("%d", &num3);
	printf("\n");



	printf("Najveca zajednicka mjera: %d\n", gcd(abs(num1), abs(num2)));
	printf("Najmanji zajednicki visekratnik: %d\n", lcm(num1, num2));
	printf("\n-----------------------DISTRIBUTIVNOST =>------------------------\n\n");
	distributivnost(num1, num2, num3);
	printf("\n-----------------------DISTRIBUTIVNOST <=------------------------\n\n");
	distributivnost2(num1, num2, num3);
	printf("\n-----------------------KOMUTATIVNOST  GCD------------------------\n\n");
	komutativnostGCD(num1, num2);
	printf("\n-----------------------KOMUTATIVNOST  LCM------------------------\n\n");
	komutativnostLCM(num1, num2);
	printf("\n\n\n");
	return 0;

}



int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
	return b == 0 ? a : (abs(a*b) / gcd(abs(a), abs(b)));
}

void distributivnost(int a, int b, int c) {
	printf("Treba dokazati da vrijedi:\n\t\ta + (b*c) = a+b * a+c\n\n\tNZM(a, NZV(b,c)) = NZV( NZM(a,b), NZM(a,c))\n");
	printf("\n\tNZM(%d, NZV(%d,%d)) = NZV( NZM(%d,%d), NZM(%d,%d))\n\n", a, b, c, a, b, a, c);
	printf("\t\t\t%d = %d\n", gcd(abs(a), lcm(abs(b), abs(c))), lcm(gcd(abs(a), abs(b)), gcd(abs(a), abs(c))));
}

void distributivnost2(int a, int b, int c) {
	printf("Treba dokazati da vrijedi:\n\t\ta * (b+c) = a*b + a*c\n\n\tNZV(a, NZM(b,c)) = NZM( NZV(a,b), NZV(a,c))\n");
	printf("\n\tNZV(%d, NZM(%d,%d)) = NZM( NZV(%d,%d), NZV(%d,%d))\n\n", a, b, c, a, b, a, c);
	printf("\t\t\t%d = %d\n", lcm(abs(a), gcd(abs(b), abs(c))), gcd(lcm(abs(a), abs(b)), lcm(abs(a), abs(c))));
}

void komutativnostGCD(int a, int b) {
	printf("Treba dokazati da vrijedi:\n\t a + b = b + a\n\n\tNZM(a,b) = NZM(b,a)\n");
	printf("\n\tNZM(%d,%d) = NZM(%d,%d)\n\n", a, b, b, a);
	printf("\t\t%d = %d\n", gcd(abs(a), abs(b)), gcd(abs(b), abs(a)));
}

void komutativnostLCM(int a, int b) {
	printf("Treba dokazati da vrijedi:\n\t a * b = b * a\n\n\tNZV(a,b) = NZV(b,a)\n");
	printf("\n\tNZV(%d,%d) = NZV(%d,%d)\n\n", a, b, b, a);
	printf("\t\t%d = %d\n", lcm(abs(a), abs(b)), lcm(abs(b), abs(a)));
}