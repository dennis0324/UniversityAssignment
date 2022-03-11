#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
int tax_calculate(int);
void payment_calculate(int, int*);
int moneyvalue[5] = { 10000,5000,1000,500,100 }; //1000 5000 1000 500 100

int main() {
	FILE* fp;
	int usedMoney, tax;
	int payment[5]; //10000, 5000, 1000, 500, 1000
	fp = fopen("data.txt", "r+");

	if (fp == NULL) {
		printf("file not found");
		return 0;
	}
	while (!feof(fp)) {
		fscanf(fp, "%d", &usedMoney);
		tax = tax_calculate(usedMoney);
		payment_calculate(tax + usedMoney, payment);

		printf("사용금액(%d) + 세금(%d) = %d\n", usedMoney, tax, usedMoney + tax);
		printf("1만원 %d개\n", payment[0]);
		printf("5천원 %d개\n", payment[1]);
		printf("1천원 %d개\n", payment[2]);
		printf("5백원 %d개\n", payment[3]);
		printf("1백원 %d개\n", payment[4]);
		printf("===========================================\n");
	}
	fclose(fp);
	return 0;
}

int tax_calculate(int m) {
	if (m >= 10000) return m * 0.35; //1000이상 
	else if (m >= 7000) return m * 0.27; //7000이상 10000미만
	else if (m >= 3000) return m * 0.2; //3000이상 7000미만
	else if (m >= 1000) return m * 0.15; //1000이상 3000미만
	else return m * 0; //0이상 1000미만
}

void payment_calculate(int t, int* p) {
	for (int i = 0; i < 5; i++) {
		p[i] = t / moneyvalue[i]; //내야할 개수를 얻어야 하기 때문에 몫으로 가져옴
		t %= moneyvalue[i]; //내고 남은 가격을 구해야 하기 때문에 나머지로 가져옴
	}

}