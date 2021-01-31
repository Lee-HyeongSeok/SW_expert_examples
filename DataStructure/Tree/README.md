## **Tree 트리 - 자료구조**

***



### **⚙ 트리란?**

- 그래프의 일종
- 여러 노드가 하나의 노드를 가리킬 수 없는 구조
- 회로가 없고, 서로 다른 두 노드를 잇는 길이 하나뿐인 그래프 
- 계층적인 구조를 나타내는 자료구조
- 부모와 자식 관계의 노드들로 이루어진다.

![Tree](https://user-images.githubusercontent.com/55940552/106389393-67539d80-6426-11eb-867e-bb6237461196.png)   



### **⚙ 트리의 특징**

- DAG(Directed Acyclic Graphs, 방향성 비순환 그래프)의 한 종류이다.
  - Loop, Cycle이 존재하지 않는다.
- N개의 노드를 가지면 N-1개의 간선을 가진다.
- Root 노드에서 특정 노드로 가는 경로는 유일하다.
- 모든 자식 노드는 한 개의 부모 노드만을 가진다.



### **⚙ 트리 구성**

- 레벨(Level) : 트리 각 층의 번호
- 높이(Height) : 트리가 가지는 최대 레벨
- 차수(Degree) : 각 노드가 가지고 있는 자식 노드의 개수

![1](https://user-images.githubusercontent.com/55940552/106389557-2f992580-6427-11eb-9073-e1c2adffc546.png)   



### **⚙ 트리의 종류**

- **이진 트리(Binary Tree)**

  - 각 노드가 최대 두 개의 자식을 갖는다.

  - 순회 방식

    1. 전위 순회(Pre Order Traversal) : 현재 노드 - 왼쪽 자식 - 오른쪽 자식 순으로 탐색

    2. 중위 순회(In Order Traversal) : 왼쪽 자식 - 현재 노드 - 오른쪽 자식 순으로 탐색

    3. 후위 순회(Post Order Traversal) : 왼쪽 자식 - 오른쪽 자식 - 현재 노드 순으로 탐색

       ```c
       // 전위 순회
       // 자식 노드보다 루트 노드를 먼저 방문한다.
       void preOrder(int root) {
       	int child = 0;
       	printf("%d ", root); // 루트 출력
       
       	for (int i = 0; i < MAX_CHILD; i++) {
       		// 루트의 자식 노드 2개를 순차적으로 child 변수에 삽입한다.
       		child = tree[root].child[i]; 
       		
       		// 자식 노드가 존재하면
       		if (child != -1) {
       			// 자식 노드 번호를 통해 재귀 탐색
       			preOrder(child);
       		}
       	}
       }
       
       // 중위 순회
       void inOrder(int root) {
       	int child = 0;
       
       	child = tree[root].child[0];
       
       	if (child != -1)
       		inOrder(child);
       	printf("%d ", root);
       
       	child = tree[root].child[1];
       	if (child != -1)
       		inOrder(child);
       }
       
       // 후위 순회
       void postOrder(int root) {
       	int child = 0;
       
       	for (int i = 0; i < MAX_CHILD; i++) {
       		child = tree[root].child[i]; // 왼쪽 자식, 오른쪽 자식 노드 탐색
       
       		// 자식 노드 존재 시
       		if (child != -1) {
       			postOrder(child); // 최하단 까지 내려감 
       		}
       	}
       	printf("%d ", root);
       }
       ```

       

  - 이진 트리 종류

    1. 완전 이진 트리 : 각 노드는 0개 이상, 2개 이하의 자식 노드를 불균형적으로 할당 
    2. 전 이진 트리 : 각 노드는 0개 이상, 2개 이하의 자식 노드를 가지고 새 노드를 <br>가장 왼쪽부터 할당
    3. 포화 이진 트리 : 각 노드는 2개의 자식 노드를 가지며, 모든 노드가 꽉 차있을 경우를 말한다.

- **이진 탐색 트리(Binary Search Tree)**
  - 왼쪽 노드는 부모 노드의 값보다 작거나 같고, 오른쪽 노드는 부모 노드의 값보다<br> 크거나 같아야 하는 성질을 만족하는 트리
- **균형 트리**
  - O(log N) 시간에 삽입과 탐색을 할 수 있는 균등하게 자식 노드가 설정된 트리
  - ex) Red-Black Tree, AVL Tree

   

### **⚙ 트리 구현**

![2](https://user-images.githubusercontent.com/55940552/106390141-4b51fb00-642a-11eb-8566-ff7fe98b68f0.png)   



**[입력]**

1	// 테스트 케이스

12 11	// 전체 노드 개수(N), 간선의 개수(N-1)

1 2 1 3 2 4 2 5 3 6 3 7 4 8 4 9 5 10 5 11 6 12	// (parent, child) 쌍으로 입력



**[출력]**

1 2 4 8 9 5 10 11 3 6 12 7	// 전위 순회

8 4 9 2 10 5 11 1 12 6 3 7	// 중위 순회

8 9 4 10 11 5 2 12 6 7 3 1	// 후위 순회

***

**[출처]**

[SW Expert Academy](https://swexpertacademy.com)

[한국산업기술대학교](http://www.kpu.ac.kr/index.do?sso=ok)



 

