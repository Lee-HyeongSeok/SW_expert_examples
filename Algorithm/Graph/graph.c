#define _CRT_SECURE_NO_WARNING

#include <stdio.h>
#include <malloc.h>

typedef struct { // ������ ������ ���
	int vertex;
	AdjlistNode *next;
}AdjlistNode;

typedef struct { // ������ ������ ��带 ����ų �� �ִ� ����� ���� ���, �ش� ���� ����� ������ ����
	int num_members;
	AdjlistNode *head;
	AdjlistNode *tail;
}AdjList;

typedef struct { // ����, ����, ����� ������ ������ ���(�׷���)
	int num_vertices;
	AdjList *adjListArr;
}Graph;

AdjlistNode * createNode(int v) { // ������ ������ ��带 ����
	AdjlistNode * newNode = (AdjlistNode*)malloc(sizeof(AdjlistNode));

	newNode->vertex = v;
	newNode->next = NULL;

	return newNode; // ������ ��� ����
}

Graph * createGraph(int n) { // ��� ���� ���� ��� ����
	Graph * graph = (Graph*)malloc(sizeof(Graph));
	graph->num_vertices = n; // ���� ���� ����
	// �ϳ��� ���� ����� ������ �ּҸ� ������� ��� ����
	graph->adjListArr = (AdjList*)malloc(n * sizeof(AdjList)); 

	// ������ �׷��� �ʱ�ȭ
	for (int i = 0; i < n; i++) {
		graph->adjListArr[i].head = graph->adjListArr[i].tail = NULL;
		graph->adjListArr[i].num_members = 0;
	}

	return graph; // ��� ���� 
}

// �����ߴ� �׷��� �Ҹ� �Լ�
void destroyGraph(Graph * graph) {
	if (graph) { // �ش� �׷����� null�� �ƴ� ��
		if (graph->adjListArr) { // �ش� �׷����� ����� ��尡 ������ ��
			for (int v = 0; v < graph->num_vertices; v++) { // �ʱ� �������� ������ �������� loop
				AdjlistNode * adjListPtr = graph->adjListArr[v].head; // �ش� ������ �׷��� ����� ����� ����Ű�� ��带 �޾ƿ�
				
				while (adjListPtr) { // ����� ����Ű�� ��尡 �����Ѵٸ�
					// �����ϱ� ���� ���� ����� ����Ű�� ����� ���� ���� ��ü
					AdjlistNode *tmp = adjListPtr; 
					adjListPtr = adjListPtr->next;
					free(tmp); // ������ ���� ��� ����(ù ��° ����ü)
				}
			}
			free(graph->adjListArr); // ������ ������ ���� ��� ����(�� ��° ����ü)
		}
		free(graph); // ������ �׷��� ��� ����(�� ��° ����ü)
	}
}

// ���, ��� ����, ���� ����
void addEdge(Graph *graph, int src, int dest) {
	AdjlistNode *newNode = createNode(dest); // ��� ���� �� ���� ������ ���ڷ� �ѱ�
	if (graph->adjListArr[src].tail != NULL) { 
		// ��� ������ �ε����� �Ͽ� ���� ��尡 ���� ���� ��带 ����Ŵ
		graph->adjListArr[src].tail->next = newNode;
		graph->adjListArr[src].tail = newNode;
	}
	else { // ��� ������ �ε����� �ϴ� ����� ���� ��尡 NULL�̶��
		graph->adjListArr[src].head = graph->adjListArr[src].tail = newNode;
	}
	graph->adjListArr[src].num_members++; // ����� ���̹Ƿ� �ش� ������ ���� ����

	newNode = createNode(src); // ���� �������� ��� ������ �̾��ִ� ����
	if (graph->adjListArr[dest].tail != NULL) {
		graph->adjListArr[dest].tail->next = newNode;
		graph->adjListArr[dest].tail = newNode;
	}
	else {
		graph->adjListArr[dest].head = graph->adjListArr[dest].tail = newNode;
	}
	graph->adjListArr[dest].num_members++;
}

// �׷��� ���
void displayGraph(Graph * graph, int i) {
	AdjlistNode * adjListPtr = graph->adjListArr[i].head; // �׷��� ����� ����Ű�� ��� ����
	while (adjListPtr) {
		printf("%d ", adjListPtr->vertex); // ����
		adjListPtr = adjListPtr->next; // ������ ����Ű�� ���� ���� �̵�
	}
	printf("\n");
}

int main(int argc, char *argv[]) {
	int T, V, E, Q, sv, ev;

	scanf("%d", &T); // �׽�Ʈ ���̽� �Է�

	for (int test_case = 1; test_case <= T; test_case++) {
		scanf("%d %d %d", &V, &E, &Q); // ��������, ��������, ���� ����

		Graph * graph = createGraph(V); // �׷��� ����

		for (int i = 0; i < E; i++) {
			scanf("%d %d", &sv, &ev); // ��� ����, ���� ����
			addEdge(graph, sv, ev); // �׷��� �߰�
		}
		printf("#%d\n", test_case);
		for (int i = 0; i < Q; i++) { // ���� ������ŭ loop
			scanf("%d", &sv); // �Է��� ������ ����� ������ ���
			displayGraph(graph, sv);
		}
		if (test_case == 2) { // ������ ������ ��
			destroyGraph(graph); // �����ߴ� �׷��� ����
		}
	}

	return 0;
}