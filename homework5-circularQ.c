/*
 ============================================================================
 Name        : homework5-circularQ.c
 Author      : Ji Un Song
 Version     :
 Copyright   :
 Description :
 ============================================================================
 */

/*
 * circularQ.c
 *
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 4			// 상수 MAX_QUEUE_SIZE를 4로 초기화

typedef char element;		// char형의 element
typedef struct {
	element queue[MAX_QUEUE_SIZE];		// char형의 큐 배열
	int front, rear;			// 큐의 맨 앞과 맨 뒤 변수
}QueueType;


QueueType *createQueue();			// 구조체를  포인터로 선언
int isEmpty(QueueType *cQ);
int isFull(QueueType *cQ);
void enQueue(QueueType *cQ, element item);
void deQueue(QueueType *cQ, element* item);
void printQ(QueueType *cQ);
void debugQ(QueueType *cQ);

element getElement();


int main(void)
{
	setvbuf(stdout, NULL, _IONBF, 0);		// 출력 버퍼 비활성화
	printf("[송지운]   [2019038028]\n");


	QueueType *cQ = createQueue();			// 구조체 포인터
	element data;

	char command;		// command를 입력시킬 변수

	do{			// do while 문
		printf("\n-----------------------------------------------------\n");
		printf("                     Circular Q                   \n");
		printf("------------------------------------------------------\n");
		printf(" Insert=i,  Delete=d,   PrintQ=p,   Dubug=b,   Quit=q \n");		// 커맨드의 종류
		printf("------------------------------------------------------\n");

		printf("Command = ");		// command를 입력하라는 출력문

		scanf(" %c", &command);		// command를 입력

		switch(command) {		// command에 따른 switch문
		case 'i': case 'I':		// i일 경우
			data = getElement();		//
			enQueue(cQ, data);
			break;
		case 'd': case 'D':
			deQueue(cQ,&data);
			break;
		case 'p': case 'P':
			printQ(cQ);
			break;
		case 'b': case 'B':
			debugQ(cQ);
			break;
		case 'q': case 'Q':
			break;
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q');


	return 0;
}


QueueType *createQueue()
{
	QueueType *cQ;
	cQ = (QueueType *)malloc(sizeof(QueueType));
	cQ->front = 0;
	cQ->rear = 0;
	return cQ;
}

element getElement()
{
	element item;		// char형의 item변수
	printf("Input element = ");		// element를 입력하라는 출력문
	scanf(" %c", &item);		// item입력
	return item;		// item 반환
}


/* complete the function */
int isEmpty(QueueType *cQ)		// cQ배열이 비어있는지 확인하는 함수
{
	if(cQ->front == cQ->rear)		// 만약 rear == front
		return -1;		// -1을 반환
    return 0;		//  아니면 0을 반환
}

/* complete the function */
int isFull(QueueType *cQ)		// cQ배열이 꽉 차있는지 확인하는 함수
{
	if(cQ->rear == MAX_QUEUE_SIZE -1)		// 만약 rear가 끝 칸의 한칸 뒤라면
		return -1;		// -1을 반환
   return 0;		// 아니면 0을 반환
}


/* complete the function */
void enQueue(QueueType *cQ, element item)		// item 입력 함수
{
	cQ->rear = (cQ->rear+1)%MAX_QUEUE_SIZE;		// modulo 연산
	if(isFull(cQ) == -1){		// 만약 isFull함수가 -1을 반환했으면
		printf("에러");		// 에러메세지 출력
		return;	// 함수 종료
	}
	cQ -> queue[cQ->rear] = item;		// 아니면 rear에 item 초기화

	return;		// 함수 종료
}

/* complete the function */
void deQueue(QueueType *cQ, element *item)		// delete 함수
{
	if(isEmpty(cQ) == -1){		// 만약 isEmpty함수가 -1을 반환 했다면
		printf("에러");		// 에러메세지 출력
		return;		// 함수 종료
	}
	cQ->front = (cQ->front+1) % MAX_QUEUE_SIZE;		// 아니면 queue 앞에 있는 item을 제거
    return;	// 함수 종료
}


void printQ(QueueType *cQ)		// 현재 큐의 값들을 출력해주는 함수
{
	int i, first, last;		// 각 배열에 들어갈 변수

	first = (cQ->front + 1)%MAX_QUEUE_SIZE;		// first를 modulo연산으로 구현
	last = (cQ->rear + 1)%MAX_QUEUE_SIZE;		// last를 modulo연산으로 구현

	printf("Circular Queue : [");				// Circular Queue 출력문

	i = first;		// i초기값을 first로
	while(i != last){		// i가 last일떄 까지
		printf("%3c", cQ->queue[i]);	// 값 출력
		i = (i+1)%MAX_QUEUE_SIZE;		// i의 값을 modulo연산으로 상승

	}
	printf(" ]\n");		// 끝
}


void debugQ(QueueType *cQ)		// 디버그 함수
{

	printf("\n---DEBUG\n");		// 디버그문 출력
	for(int i = 0; i < MAX_QUEUE_SIZE; i++)		// i < MAX_QUEUE_SIZE 까지
	{
		if(i == cQ->front) {		// i가 front의 위치라면
			printf("  [%d] = front\n", i);		// i = front 출력
			continue;		// 계속
		}
		printf("  [%d] = %c\n", i, cQ->queue[i]);		// 아니면 i의 위치의 값이 queue라는 것을 출력

	}
	printf("front = %d, rear = %d\n", cQ->front, cQ->rear);		// front, rear의 위치 출력
}
