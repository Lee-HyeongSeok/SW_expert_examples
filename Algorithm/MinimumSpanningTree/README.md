## **Minimum Spanning Tree(최소 신장 트리)**

***

   

### **⚙Spanning Tree란**

- 그래프 내의 모든 정점을 포함하는 트리
- 그래프의 최소 연결 부분 그래프로 간선의 수가 가장 적어야 한다.
- n개의 정점을 가지는 그래프의 최소 간선의 수는 (n-1)개
- 그래프에서 일부 간선을 선택해서 만든 트리



### **⚙Spanning Tree 특징**

- DFS, BFS를 이용해서 탐색 도중에 허용된 간선만 수집하면 신장 트리를 찾을 수 있다.

- 현재 예제에서는 크루스칼 알고리즘을 사용하여 최소 신장 트리를 찾는다.

- 모든 정점들이 연결되어 있어야 하고 사이클을 허용해서는 안된다.

  **[사이클이란]**

  > 세 개의 정점이 서로 연결되어 있어 원 형태를 이루는 구조

- n개의 정점을 정확히 (n-1)개의 간선으로 연결한다.



### **⚙Minimum Spanning Tree(MST) 란**

- Spanning Tree 중에서 사용된 간선들의 가중치 합이 최소인 트리
- 네트워크에 있는 모든 정점들을 가장 적은 수의 간선과 비용으로 연결하는 것

![최소신장트리](https://user-images.githubusercontent.com/55940552/105037302-201df200-5aa1-11eb-8b95-7812a6ea958f.PNG)

   



### **⚙Minimum Spanning Tree(MST) 특징**

- 간선의 가중치 합이 최소여야 한다.
- n개 정점을 가지는 그래프에 대해 반드시 (n-1)개의 간선만을 사용해야 한다.
- 사이클이 포함되어서는 안된다.



### **⚙Minimum Spanning Tree(MST) 구현 방법**

1. **Kruskal MST Algorithm**

   - 네트워크의 모든 정점을 최소 비용으로 연결하는 최적 해답을 구하는 방법

   - 사이클을 이루지 않는 최소 비용 간선을 선택한다.

     > 1. 그래프의 간선들을 가중치 오름차순으로 정렬한다.
     >    
     >    - 예제에서는 Merge Sort 사용
     >    
     >      ```c
     >      void MergeSort(int s, int e) {
     >      	if (s < e) {
     >      		int m = (s + e) / 2; // s 에서 e까지 거리의 중간을 찾아낸다.
     >      		MergeSort(s, m); // s에서부터 m 까지 합병 정렬 실시
     >      		MergeSort(m + 1, e); // m+1에서부터 e까지 합병 정렬 실시
     >      
     >      		int left = s, right = m + 1, pointer = s;
     >      
     >      		// 정렬될 원소가 올바른 위치에 있는지 검사
     >      		while (left <= m && right <= e) {
     >      			// 연결된 엣지의 가중치가 가장 작은 값을 검사
     >      			if (edge[left].w <= edge[right].w) {
     >      				// tmp 배열에 가중치가 가장 작은 간선을 저장
     >      				tmp[pointer++] = edge[left++];
     >      			}
     >      			else {
     >      				tmp[pointer++] = edge[right++];
     >      			}
     >      		}
     >      		// 나머지 남은 값을 처리하는 부분
     >      		while (left <= m)
     >      			tmp[pointer++] = edge[left++];
     >      		while (right <= e)
     >      			tmp[pointer++] = edge[right++];
     >      
     >      		// tmp에 저장된 최소 신장 엣지들을 edge에 다시 저장
     >      		for (int i = s; i <= e; i++) {
     >      			edge[i] = tmp[i];
     >      		}
     >      	}
     >      }
     >      ```
     >    
     >      
     > 2. 정렬된 간선 리스트에서 순서대로 사이클을 형성하지 않는 간선을 선택한다.
     >    - 가장 낮은 가중치를 먼저 선택
     >    
     >    - 사이클 형성 간선 제외
     >    
     >      ```c
     >      int find_root(int x) {
     >      	if (disjoint_set[x] == x)
     >      		return x;
     >      	// 정점 x와 연결된 다른 정점에 대해 재귀 호출
     >      	disjoint_set[x] = find_root(disjoint_set[x]);
     >      
     >      	return disjoint_set[x];
     >      }
     >      ```
     >    
     >      
     > 3. 해당 간선을 현재 MST의 집합에 추가한다.

2. **Prim MST Algorithm**

   - 시작 정점에서부터 출발해서 신장 트리 집합을 단계적으로 확장해나가는 방법

     > 1. 시작 단계에서는 시작 정점만이 MST 집합에 포함된다.
     > 2. 앞 단계에서 만들어진 MST 집합에 인접한 정점들 중 최소 간선으로 연결된 <br>정점을 선택하여 트리를 확장한다.
     > 3. 위 과정을 트리가 (n-1)개 간선을 가질때 까지 반복한다.



### **⚙SW Expert Academy Reference Code**

**[입력]**

1(테스트 케이스 개수)

5 8(정점의 개수, 간선의 개수)

1 2 4(정점 1과 2의 거리가 4)

1 3 9(정점 1과 3의 거리가 9)

1 4 21(....)

2 3 8

2 4 17

3 4 16

5 2 20

5 4 30



**[출력]**



Draw Vertex 1

Draw Vertex 2

Draw Vertex 3

Draw Vertex 4

Draw Vertex 5



#1

Union 1-2

Union 1-3

Union 1-4

Union 5-1



***

[출처]

[SW Expert Academy](https://swexpertacademy.com/main/visualcode/main.do#/home/editor//)

[HeeJeong Kwon 블로그](https://gmlwjd9405.github.io/2018/08/28/algorithm-mst.html)

[dnjscksdn98.log 블로그](https://velog.io/@dnjscksdn98/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-%EC%B5%9C%EC%86%8C-%EC%8B%A0%EC%9E%A5-%ED%8A%B8%EB%A6%AC)