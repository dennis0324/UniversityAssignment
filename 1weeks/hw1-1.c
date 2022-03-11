#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	FILE * fp; //파일 입출력
	int count = 0; //파일 데이터 읽으시 배열에 넣기위한 인덱스 카운트
	int lineInput = 0; //열의 개수를 입력받기 위한 변수
	int data[10000]; //데이터 저장 배열
	int big = 0; //최대 숫자
	int small = 0; //최소 숫자
	int i, j; //인덱스 변수

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
		if(feof(fp)) break;
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
	
	
	
	//출력
	for(i = 0; i < lineInput; i++)
		printf("%6d",i + 1);
	printf("\n");
	for(i = 0; i < lineInput* 6;i++)
		printf("=");
	printf("\n");
	for ( i = 0; i < count; i++) {
		//첫번째 0을 제외한 나머지 lineInput의 배수만 실행됨
		printf("%6d", data[i]);
		if ((i + 1) % lineInput == 0 && i > 0) {
			printf("\n");
			for (j = 0; j < lineInput; j++) {
				//i - lineInput은 첫번째 줄이 2번째 실행부터이기 lineInput 한번 빼준다.
				//최대 최소 값에 대한 비교와 출력을 해준다.
				//0을 제외하고 했기 때문에 다시 0시작으로 맞춰주기 위해 lineInput를 빼준다.
				if (data[i  + j- (lineInput - 1)] == small) printf("최솟값");
				else if (data[i + j - (lineInput - 1)] == big) printf("최댓값");
				else printf("%6s", " ");
			}
			printf("\n");
			//마무리 선 출력
			for (j = 0; j < lineInput * 6; j++)
				printf("-");
			printf("\n");
		}
		
	}

	return 0;
}
