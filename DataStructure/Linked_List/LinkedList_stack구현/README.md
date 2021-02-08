## **단순 연결 리스트를 이용한 스택 구현**



***



### **⚙ 단순 연결 리스트 구성**

- main에서 사용자의 데이터를 입력 받아 삽입을 위한 **ListType 구조체**
  - ListType 구조체는 head, tail, size로 구성되어 있다.
  - head : 가장 처음 삽입된 노드를 가리키기 위한 포인터
  - tail : 항상 마지막에 존재하는 노드를 가리키기 위한 포인터
  - size : 스택에 원소들의 개수를 저장하는 변수



- 사용자에게 입력받은 데이터를 저장하기 위한 노드 **ListNode 구조체**
  - ListNode 구조체는 data, link로 구성되어 있다.
  - data : 사용자에게 입력받은 데이터를 저장하기 위한 변수
  - link : 다음 노드를 가리키기 위한 포인터

![stack](https://user-images.githubusercontent.com/55940552/107188385-e3537400-6a2a-11eb-8566-315e81e93215.png)   



***



### **⚙ 단순 연결 리스트 스택 연산**

- 삽입 연산 - Push()
- 삭제 연산 - Pop()
- 스택 내 원소 출력 - printStack()



### **삽입 연산 - Push()**

![push](https://user-images.githubusercontent.com/55940552/107190068-ad63bf00-6a2d-11eb-989b-ca5737e93aa1.png)



### **삭제 연산 - Pop()**

![ㅁ](https://user-images.githubusercontent.com/55940552/107191407-742c4e80-6a2f-11eb-8cba-e30864323e18.png)

