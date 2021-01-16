#define _CRT_SECURE_NO_WARNING

#include <stdio.h>
#include <malloc.h>

typedef struct { // 정점을 가지는 노드
	int vertex;
	AdjlistNode *next;
}AdjlistNode;

typedef struct { // 정점을 가지는 노드를 가리킬 수 있는 헤더와 테일 노드, 해당 노드와 연결된 개수도 가짐
	int num_members;
	AdjlistNode *head;
	AdjlistNode *tail;
}AdjList;

typedef struct { // 정점, 간선, 헤더와 테일을 가지는 노드(그래프)
	int num_vertices;
	AdjList *adjListArr;
}Graph;

AdjlistNode * createNode(int v) { // 간선을 가지는 노드를 생성
	AdjlistNode * newNode = (AdjlistNode*)malloc(sizeof(AdjlistNode));

	newNode->vertex = v;
	newNode->next = NULL;

	return newNode; // 생성된 노드 리턴
}

Graph * createGraph(int n) { // 모든 것을 가진 노드 생성
	Graph * graph = (Graph*)malloc(sizeof(Graph));
	graph->num_vertices = n; // 간선 개수 대입
	// 하나의 노드와 연결된 노드들의 주소를 담기위한 노드 생성
	graph->adjListArr = (AdjList*)malloc(n * sizeof(AdjList)); 

	// 생성한 그래프 초기화
	for (int i = 0; i < n; i++) {
		graph->adjListArr[i].head = graph->adjListArr[i].tail = NULL;
		graph->adjListArr[i].num_members = 0;
	}

	return graph; // 노드 리턴 
}

// 생성했던 그래프 소멸 함수
void destroyGraph(Graph * graph) {
	if (graph) { // 해당 그래프가 null이 아닐 때
		if (graph->adjListArr) { // 해당 그래프에 연결된 노드가 존재할 때
			for (int v = 0; v < graph->num_vertices; v++) { // 초기 정점부터 간선의 개수까지 loop
				AdjlistNode * adjListPtr = graph->adjListArr[v].head; // 해당 정점의 그래프 노드의 헤더가 가리키는 노드를 받아옴
				
				while (adjListPtr) { // 헤더가 가리키는 노드가 존재한다면
					// 삭제하기 위해 현재 헤더가 가리키는 노드의 다음 노드로 교체
					AdjlistNode *tmp = adjListPtr; 
					adjListPtr = adjListPtr->next;
					free(tmp); // 정점을 가진 노드 삭제(첫 번째 구조체)
				}
			}
			free(graph->adjListArr); // 간선의 개수를 가진 노드 삭제(두 번째 구조체)
		}
		free(graph); // 마지막 그래프 노드 삭제(세 번째 구조체)
	}
}

// 노드, 출발 정점, 도착 정점
void addEdge(Graph *graph, int src, int dest) {
	AdjlistNode *newNode = createNode(dest); // 노드 생성 시 도착 정점을 인자로 넘김
	if (graph->adjListArr[src].tail != NULL) { 
		// 출발 정점을 인덱스로 하여 꼬리 노드가 도착 정점 노드를 가리킴
		graph->adjListArr[src].tail->next = newNode;
		graph->adjListArr[src].tail = newNode;
	}
	else { // 출발 정점을 인덱스로 하는 노드의 꼬리 노드가 NULL이라면
		graph->adjListArr[src].head = graph->adjListArr[src].tail = newNode;
	}
	graph->adjListArr[src].num_members++; // 연결된 것이므로 해당 정점의 간선 증가

	newNode = createNode(src); // 도착 정점에서 출발 정점을 이어주는 동작
	if (graph->adjListArr[dest].tail != NULL) {
		graph->adjListArr[dest].tail->next = newNode;
		graph->adjListArr[dest].tail = newNode;
	}
	else {
		graph->adjListArr[dest].head = graph->adjListArr[dest].tail = newNode;
	}
	graph->adjListArr[dest].num_members++;
}

// 그래프 출력
void displayGraph(Graph * graph, int i) {
	AdjlistNode * adjListPtr = graph->adjListArr[i].head; // 그래프 헤더가 가리키는 노드 대입
	while (adjListPtr) {
		printf("%d ", adjListPtr->vertex); // 정점
		adjListPtr = adjListPtr->next; // 정점이 가리키는 다음 노드로 이동
	}
	printf("\n");
}

int main(int argc, char *argv[]) {
	int T, V, E, Q, sv, ev;

	scanf("%d", &T); // 테스트 케이스 입력

	for (int test_case = 1; test_case <= T; test_case++) {
		scanf("%d %d %d", &V, &E, &Q); // 정점개수, 간선개수, 질문 개수

		Graph * graph = createGraph(V); // 그래프 생성

		for (int i = 0; i < E; i++) {
			scanf("%d %d", &sv, &ev); // 출발 정점, 도착 정점
			addEdge(graph, sv, ev); // 그래프 추가
		}
		printf("#%d\n", test_case);
		for (int i = 0; i < Q; i++) { // 질문 개수만큼 loop
			scanf("%d", &sv); // 입력한 정점과 연결된 정점들 출력
			displayGraph(graph, sv);
		}
		if (test_case == 2) { // 마지막 루프일 때
			destroyGraph(graph); // 생성했던 그래프 삭제
		}
	}

	return 0;
}