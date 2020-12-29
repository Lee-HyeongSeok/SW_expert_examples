## * 깊이 우선 탐색(DFS, Depth-First Search)   
#### 출처 : SW expert reference code   
#### 깊이 우선 탐색 출처 : https://gmlwjd9405.github.io/2018/08/14/algorithm-dfs.html   
***   

#### 그래프 탐색   

		- 하나의 정점으로부터 시작하여 차례대로 모든 정점을 한 번씩 방문하는 것   

#### 깊이 우선 탐색 DFS   
		- 미로 탐색 시 한 방향으로 갈 수 있을 때까지 가다가 막다른 길에 도달하면 가장 가까운 갈림길로 돌아와서 다른 방향으로 재탐색   
		- 넓게 탐색하기 전에 __깊게__ 탐색하는 방법   
		- 모든 노드를 전사 탐색하고자 할 때 사용   
		
![asd](https://user-images.githubusercontent.com/55940552/103302727-a6698a00-4a47-11eb-8b53-1d8713dd3f85.PNG)   

		- 방문한 노드에 대해서는 검은색으로 표시   
		- 인접 노드가 없다면 종료   

