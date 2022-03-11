  /*
    작성일: 2022.03.07
  	작성자: 20194043 고동현
   	프로그램명: 중복최대최소출력프로그램
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	FILE * fp; //파일 입출력
	int count = 0; //파일 데이터 읽으시 배열에 넣기위한 인덱스 카운트
	int seperateCount = 0; //열의 개수를 입력받기 위한 변수
	int data[10000]; //데이터 저장 배열
	int getFileNum; //파일 입력 임시 변수
	int big = 0; //최대 숫자
	int small = 0; //최소 숫자
	int i, j; //인덱스 변수
	int column, row; //추후에 사용하는 
	int currentLine = 0; //0-2까지의 줄 위치를 표시해주는 장치이다.
	scanf("%d", &seperateCount);

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
	//받은 인덱스 값을 최대 최소 값으로 변환중
	big = data[big]; //최댓값으로 바꿔줌
	small = data[small]; //최솟값으로 바꿔줌
	for(i  = 0;i < seperateCount; i++)
		printf("%6d",i + 1);
	printf("\n");
	for(i = 0; i < seperateCount; i++)
		printf("======");
	printf("\n");
    for(i =0;i<=count;i++){
        column = i % seperateCount; //열의 값을 구해줌
		row = i / seperateCount; //행의 값을 구해줌
		if(currentLine == 0) //출력하는 선을 구별한다. 
			printf("%6d",data[i]);//1첫번째 줄이라면 단순 출력을
		else if(currentLine == 1){
			if (data[i] == small) //2번째 줄이라면 최소 최대 출력
				printf("최솟값");
			else if(data[i] == big)
				printf("최댓값");
			else
				printf("%6s"," ");
		}
		//현재 행의 열 출력 행가 같을 경우 새줄로 넘겨준다.
		//마지막 행이 완벽하게 끝나지 않은 경우를 대비해서 for i인덱스와 count를 비교해준다.
		if(column == seperateCount -1 || i == count){
			//현재 줄이 2미만 일때 증가
			if(currentLine < 2 ){
				printf("\n");
				i -= column + 1;
				currentLine++;
			}
			
			//현재 줄이 3이상일때 구분선 표시 및 현재 줄 0설정
			else{
				for(j = 0; j < seperateCount; j++)
					printf("------");
				printf("\n");
				if(row == count / seperateCount) continue; //마지막까지 실행완료 후 무한루프를 막기위함
				currentLine = 0;
			}
		}
    }
	return 0;
}
