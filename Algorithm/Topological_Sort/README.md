## **Topological Sort - 위상 정렬**

***

### **⚙ 위상 정렬 이란**

- 어떤 일을 하는 순서를 찾는 알고리즘
- 방향 그래프에 존재하는 각 정점들의 선행 순서를 위배하지 않으면서 모든 정점을 나열



### **⚙ 위상 정렬 특징**

- 하나의 방향 그래프에서는 여러 가지 위상 정렬 가능
- 선택되는 정점의 순서를 **위상 순서(Topological Order)**라 한다.
- 남아 있는 정점 중에 진입 차수가 0인 정점이 없다면 알고리즘 중단



### **⚙ SW expert Academy Reference Code Exam**

**[입력]**

1

8 8

2 1

3 1

4 2

6 3

8 3

5 4

7 5

5 6



**[출력]**

7 8 5 6 4 3 2 1   



### **⚙ 알고리즘 설명**

**1. 초기 상태의 방향 그래프**

![초기상태](https://user-images.githubusercontent.com/55940552/105864641-7b1d8f00-6035-11eb-8f56-a612bcdab692.png)   



   

**2. 큐를 사용하여 진입 차수가 0인 정점들을 제거하여 위상 순서를 나타낸다**

- 처음 진입 차수가 0인 두 정점 7과 8이 큐에 삽입된다.

![2](https://user-images.githubusercontent.com/55940552/105864835-aef8b480-6035-11eb-913c-5234b18963e0.png)   





**3. 큐에 존재하는 7 삭제 후 7이 가리키던 5를 큐에 삽입한다.**

- 5는 진입 차수가 0이기 때문이다.

![7제거](https://user-images.githubusercontent.com/55940552/105864983-d5b6eb00-6035-11eb-86b0-943abac435d9.png)   



**4. 큐에 존재하는 8을 삭제 한다.**

- 8이 가르키던 3을 삽입하지 않는 이유는 3의 진입 차수는 1이기 때문이다(0이 아니기 때문)

![8제거](https://user-images.githubusercontent.com/55940552/105865001-d8b1db80-6035-11eb-8610-4c3055f3ce1b.png)   



**5. 큐에 존재하는 5를 삭제하면서 5가 가리키던 6과 4를 큐에 삽입한다.**

![5제거](https://user-images.githubusercontent.com/55940552/105864999-d8194500-6035-11eb-85c9-920d703609a4.png)   



**6. 큐에 존재하는 6을 삭제하면서 6이 가리키던 3을 큐에 삽입한다.**

- 3은 6이 삭제되면 진입 차수가 0이 되기 때문이다.

![6제거](https://user-images.githubusercontent.com/55940552/105864996-d8194500-6035-11eb-85ec-f71b13e8c460.png)   

**7. 큐에 존재하는 4를 삭제하면서 4가 가리키던 2를 큐에 삽입한다.**

![4제거](https://user-images.githubusercontent.com/55940552/105864991-d780ae80-6035-11eb-86f4-8d4a768e5232.png)   

**8. 큐에 존재하는 3을 삭제한다.**

- 1은 아직 2가 가리키고 있기 때문에 진입 차수가 1이므로 큐에 삽입하지 않는다.

![3제거](https://user-images.githubusercontent.com/55940552/105865920-bec4c880-6036-11eb-9232-7cc72ef9dad4.png)   

   

**9. 큐에 존재하는 2를 삭제하면서 진입 차수가 0이 된 1을 큐에 삽입한다.**

![2제거](https://user-images.githubusercontent.com/55940552/105864989-d6e81800-6035-11eb-8afa-cb085bdb73f0.png)   

**10. 큐에 존재하는 1을 삭제하면서 알고리즘 수행 완료**

- 결과는 7-8-5-6-4-3-2-1





***

**[출처]**

[SW Expert Academy](https://swexpertacademy.com/main/visualcode/main.do#/home/editor/R/57c783f6a4c12ab823c2fbdd)

[블로그](https://gmlwjd9405.github.io/2018/08/27/algorithm-topological-sort.html)