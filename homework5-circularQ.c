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

#define MAX_QUEUE_SIZE 4			// ��� MAX_QUEUE_SIZE�� 4�� �ʱ�ȭ

typedef char element;		// char���� element
typedef struct {
	element queue[MAX_QUEUE_SIZE];		// char���� ť �迭
	int front, rear;			// ť�� �� �հ� �� �� ����
}QueueType;


QueueType *createQueue();			// ����ü��  �����ͷ� ����
int isEmpty(QueueType *cQ);
int isFull(QueueType *cQ);
void enQueue(QueueType *cQ, element item);
void deQueue(QueueType *cQ, element* item);
void printQ(QueueType *cQ);
void debugQ(QueueType *cQ);

element getElement();


int main(void)
{
	setvbuf(stdout, NULL, _IONBF, 0);		// ��� ���� ��Ȱ��ȭ
	printf("[������]   [2019038028]\n");


	QueueType *cQ = createQueue();			// ����ü ������
	element data;

	char command;		// command�� �Է½�ų ����

	do{			// do while ��
		printf("\n-----------------------------------------------------\n");
		printf("                     Circular Q                   \n");
		printf("------------------------------------------------------\n");
		printf(" Insert=i,  Delete=d,   PrintQ=p,   Dubug=b,   Quit=q \n");		// Ŀ�ǵ��� ����
		printf("------------------------------------------------------\n");

		printf("Command = ");		// command�� �Է��϶�� ��¹�

		scanf(" %c", &command);		// command�� �Է�

		switch(command) {		// command�� ���� switch��
		case 'i': case 'I':		// i�� ���
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
	element item;		// char���� item����
	printf("Input element = ");		// element�� �Է��϶�� ��¹�
	scanf(" %c", &item);		// item�Է�
	return item;		// item ��ȯ
}


/* complete the function */
int isEmpty(QueueType *cQ)		// cQ�迭�� ����ִ��� Ȯ���ϴ� �Լ�
{
	if(cQ->front == cQ->rear)		// ���� rear == front
		return -1;		// -1�� ��ȯ
    return 0;		//  �ƴϸ� 0�� ��ȯ
}

/* complete the function */
int isFull(QueueType *cQ)		// cQ�迭�� �� ���ִ��� Ȯ���ϴ� �Լ�
{
	if(cQ->rear == MAX_QUEUE_SIZE -1)		// ���� rear�� �� ĭ�� ��ĭ �ڶ��
		return -1;		// -1�� ��ȯ
   return 0;		// �ƴϸ� 0�� ��ȯ
}


/* complete the function */
void enQueue(QueueType *cQ, element item)		// item �Է� �Լ�
{
	cQ->rear = (cQ->rear+1)%MAX_QUEUE_SIZE;		// modulo ����
	if(isFull(cQ) == -1){		// ���� isFull�Լ��� -1�� ��ȯ������
		printf("����");		// �����޼��� ���
		return;	// �Լ� ����
	}
	cQ -> queue[cQ->rear] = item;		// �ƴϸ� rear�� item �ʱ�ȭ

	return;		// �Լ� ����
}

/* complete the function */
void deQueue(QueueType *cQ, element *item)		// delete �Լ�
{
	if(isEmpty(cQ) == -1){		// ���� isEmpty�Լ��� -1�� ��ȯ �ߴٸ�
		printf("����");		// �����޼��� ���
		return;		// �Լ� ����
	}
	cQ->front = (cQ->front+1) % MAX_QUEUE_SIZE;		// �ƴϸ� queue �տ� �ִ� item�� ����
    return;	// �Լ� ����
}


void printQ(QueueType *cQ)		// ���� ť�� ������ ������ִ� �Լ�
{
	int i, first, last;		// �� �迭�� �� ����

	first = (cQ->front + 1)%MAX_QUEUE_SIZE;		// first�� modulo�������� ����
	last = (cQ->rear + 1)%MAX_QUEUE_SIZE;		// last�� modulo�������� ����

	printf("Circular Queue : [");				// Circular Queue ��¹�

	i = first;		// i�ʱⰪ�� first��
	while(i != last){		// i�� last�ϋ� ����
		printf("%3c", cQ->queue[i]);	// �� ���
		i = (i+1)%MAX_QUEUE_SIZE;		// i�� ���� modulo�������� ���

	}
	printf(" ]\n");		// ��
}


void debugQ(QueueType *cQ)		// ����� �Լ�
{

	printf("\n---DEBUG\n");		// ����׹� ���
	for(int i = 0; i < MAX_QUEUE_SIZE; i++)		// i < MAX_QUEUE_SIZE ����
	{
		if(i == cQ->front) {		// i�� front�� ��ġ���
			printf("  [%d] = front\n", i);		// i = front ���
			continue;		// ���
		}
		printf("  [%d] = %c\n", i, cQ->queue[i]);		// �ƴϸ� i�� ��ġ�� ���� queue��� ���� ���

	}
	printf("front = %d, rear = %d\n", cQ->front, cQ->rear);		// front, rear�� ��ġ ���
}
