#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	FILE * fp; //파일 입출력
	char * resultBigSmall[2] = { "최댓값","최솟값" };
	int count = 0; //파일 데이터 읽으시 배열에 넣기위한 인덱스 카운트
	int lineInput = 0; //열의 개수를 입력받기 위한 변수
	int data[10000]; //데이터 저장 배열
	int getFileNum; //파일 입력 임시 변수
	int big = 0; //최대 숫자
	int small = 0; //최소 숫자
	int line; //총 나와야 할 행의 개수 
	int i, j; //인덱스 변수

	int whileCounting = 0;
	scanf("%d", &lineInput);

	fp = fopen("data.txt", "r+");
	//파일을 찾을 수 없을 경우에 이 코드를 안전하게 종료하는 부분
	if (fp == NULL) {
		printf("파일이 존재하지 않습니다.");
		return 0;
	}
	//파일을 입력을 계속 읽어드리고 eof가 나오면 자동으로 멈추게 함
	while (1) {
		fscanf(fp, "%d", &data[count]);//데이터 입력 받기
		//while 조건식에다가 넣지 않은 이유는 while의 실행 순서에 의해서 인덱스 밖의 범위까지 값을 넣는다.
		if (feof(fp)) break;
		//받은 데이터 최소 최대 구분 small,big이 인덱스 값이 저장되어있음
		if (data[big] < data[count])
			big = count;
		else if (data[small] > data[count])
			small = count;
		count++;
	}
	//받은 데이터 값으로 변환중
	big = data[big]; //최댓값으로 바꿔줌
	small = data[small]; //최솟값으로 바꿔줌
	line = count / lineInput;

	//출력
	for (i = 0; i < lineInput; i++)
		printf("%6d", i + 1);
	printf("\n");
	for (i = 0; i < lineInput * 6; i++)
		printf("=");
	printf("\n");
	for (i = 0; i < count / lineInput + 1; i++) {
		whileCounting++;
		//첫번째 0을 제외한 나머지 lineInput의 배수만 실행됨
		for (j = 0; j < lineInput; j++)
			if (i * lineInput + j <= count){
				printf("%6d", data[i * lineInput+ j]);
				whileCounting++;
			}//현재 출력 인덱스가 입력 받아 둔 인덱스보다 작을 경우 출력하지 않음

		printf("\n");

		for (j = 0; j < lineInput; j++) {
			whileCounting++;
			//현재 출력 인덱스의 값이 최소 최대와 같을 때 출력
			if (data[i * lineInput + j] == small) printf("최솟값");
			else if (data[i * lineInput + j] == big) printf("최댓갓");
			else printf("%6s", " ");
		}
		printf("\n");
		//나머지 선 출력
		for (j = 0; j < lineInput * 6; j++)
		{
			whileCounting++;
			printf("-");
		}
		printf("\n");

	}
	printf("%d",whileCounting);
	return 0;
}
