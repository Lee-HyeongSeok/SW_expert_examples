## **Bipartite Matching 이분 매칭 알고리즘**

***



### **🔑이분 매칭 알고리즘이란?**

- 집단 A가 집단 B를 선택하는 방법에 대한 알고리즘
- 가장 효과적인 매칭은 그래프 형태로 표현하는 것
- 효과적인 매칭이란 **최대 매칭**을 의미하는데, 집단 A의 모든 정점이 각각 요구하는<br> 정점을 선택했을 때 가장 많이 연결되는 경우를 찾는 문제 
- 네트워크 플로우의 한 종류, 네트워크 플로우와 연계되는 알고리즘이다.



### **🔑문제**

![Untitled Diagram](https://user-images.githubusercontent.com/55940552/105634764-14686c00-5ea3-11eb-8626-b8280a654970.png)



- **DFS(깊이 우선 탐색)로 해결**

  1. A 집단의 첫 번째 노드가 연결할 수 있는 B 집단의 노드와 연결

  2. A 집단의 두 번째 노드가 연결할 수 있는 B 집단의 노드와 연결 

     > **만약 이미 A 집단의 첫 번째 노드와 연결된 상태라면**
     >
     > - A 집단의 두 번째 노드가 B 집단의 다른 노드를 찾는다.

     > **연결할 다른 노드가 없는 경우라면**
     >
     > - 첫 번째 노드에게 B 집단의 다른 노드와 연결할 수 있는지 요청
     >
     >   > 다른 노드에 연결 가능하면 첫 번째 노드가 다른 노드와 연결
     >   >
     >   > 두 번째 노드가 첫 번째 노드와 연결되어 있던 노드와 연결된다. 



1. **1번 정점에서 DFS를 실행하여 처음 방문하는 A 정점과 매칭**

![1](https://user-images.githubusercontent.com/55940552/105636137-2a2d5f80-5eaa-11eb-90d9-0ee68be8ae5b.png)

2. **2번 정점에서 DFS를 실행하는데 A 정점은 이미 1번 정점과 매칭되어 있다.**
   - 다시 **1번 정점**으로 돌아가서 **A 번 정점** 이외에 매칭 가능한 정점이 있다면 대신 매칭해준다.
   - **1번 정점**에서 간선이 존재하는 인접 노드 탐색 시 **정점 B**가 매칭된다.
   - **1번 정점**과 **B번 정점**을 연결하는 간선이 존재하지 않았다면 매칭에 실패했다.
   - **1번 정점**이 **A번 정점**에서 **B번 정점**으로 옮겨진 후 **2번 정점**은 **A 정점**에 연결된다.

![22](https://user-images.githubusercontent.com/55940552/105636182-87291580-5eaa-11eb-829b-d4faba735ba6.png)

3. **이어서 3번 정점에서 DFS를 통해 C번 정점과 연결**

![2](https://user-images.githubusercontent.com/55940552/105636140-2b5e8c80-5eaa-11eb-8e49-42a0c0a7c149.png)

4. **4번 정점에서 DFS를 통해 C번 정점과 연결, 하지만 이미 3번 정점과 C번 정점이 연결되어 있는 상태**
   - **3번 정점**으로 돌아가서 **3번 정점** 인접 노드 탐색
   - **4번 정점**은 **C번 정점**과 연결 이후 **3번 정점**은 원래의 C번 정점에서 **D번 정점**으로 이동 후 종료 

![3](https://user-images.githubusercontent.com/55940552/105636141-2b5e8c80-5eaa-11eb-9884-1ca93df3eea0.png)

4. **최대 매칭 결과는 D번 정점**



### **SW Expert Algorithm example(Reference Code)**

**[입력]**

1	// 테스트 케이스

4	// A 집단의 노드 개수

5	// B 집단의 노드 개수

10	// 간선의 수

1 1	// A 집단의 1번 정점과 B 집단의 1번 정점 연결

1 2	// A 집단의 1번 정점과 B 집단의 2번 정점 연결

1 3	// ...

2 1

2 3

2 4

3 3

3 4

4 3

4 5



**[출력]**

#1	4 	// 첫 번째 테스트 케이스의 출력결과는 B 집단의 4번 정점, 최대 매칭



```c++
#include <iostream>

using namespace std;

#define MAX 1000

int countA, countB;
int matchA[MAX];
int matchB[MAX];
int adj[MAX][MAX];
int visited[MAX];

int dfs(int a) {
	int b = 0;

	// a정점을 이미 방문 했다면
	if (visited[a])
		return 0; // 0 리턴

	// a정점 미방문 상태
	visited[a] = 1; // 방문 상태로 만들어줌

	// 아직 연결 안한 부분이 있는지 검사
	for (b = 0; b < countB; ++b) {
		// 새로운 정점과 연결이 안되어있다면
		if (adj[a][b] && (matchB[b] == -1 || dfs(matchB[b]))) {

			// 연결 해준다
			matchA[a] = b;
			matchB[b] = a;
			return 1;
		}
	}
	return 0;
}

int bipartiteMatch(void) {
	int size = 0;
	int start = 0;
	int i = 0;

	for (start = 0; start < countA; ++start) {
		for (i = 0; i < countA; i++) {
			visited[i] = 0;
		}

		if (dfs(start)) {
			size++;
		}
	}
	return size;
}

void init() {
	for (int i = 0; i < countA; i++) {
		matchA[i] = -1;

		for (int j = 0; j < countB; j++) {
			adj[i][j] = 0;
		}
		for (int z = 0; z < countB; z++)
			matchB[z] = -1;
	}
}

int main() {
	int T = 0;
	int adjCount = 0;
	int a, b;

	cin >> T; // 테스트 케이스 입력 

	for (int test_case = 1; test_case <= T; test_case++) {
		cin >> countA;
		cin >> countB;

		init();

		cin >> adjCount;

		for (int i = 0; i < adjCount; i++) {
			cin >> a;
			cin >> b;
			adj[a - 1][b - 1] = 1;
		}

		cout << "#" << test_case << " " << bipartiteMatch() << endl;
	}
	return 0;
}
```





***

**[출처]**

[air.log](https://velog.io/@max9106/Algorithm-%EC%9D%B4%EB%B6%84-%EB%A7%A4%EC%B9%ADBipartite-Matching)

[안경잡이개발자 블로그](https://m.blog.naver.com/PostView.nhn?blogId=ndb796&logNo=221240613074&proxyReferer=https:%2F%2Fwww.google.com%2F)

[SW expert Academy Reference Code-Algorithm](https://swexpertacademy.com/main/visualcode/main.do#/home/editor/R/57c78445a4c12ab823c2fbdf)