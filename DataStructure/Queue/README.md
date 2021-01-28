## **Queue 큐 자료구조**

### ***

### **⚙ Queue란**

- 연속된 저장공간의 뒷단(rear)에서는 삽입, 앞단(front)에서는 삭제 연산만 이루어지는 **유한 순서 리스트**

- FIFO(First in First out) 방식으로 가장 먼저 삽입된 데이터가 가장 먼저 삭제되는 구조다.

![큐](https://user-images.githubusercontent.com/55940552/106095118-8af0bc80-6176-11eb-804b-2bd6dc72b35a.png)   



### **⚙ Queue의 표현**

- **순차 표현(1차원 배열을 이용한 순차표현)**

  - front, rear 인덱스를 값으로 가진다.
  - 큐의 크기를 나타내는 변수를 가진다.
  - front == rear, 공백 상태임을 의미한다.
  - rear에서 삽입되므로 rear가 점차 증가하여 rear == MAX-1인 경우 큐는 포화 상태임을 의미한다

  **[문제점]**

  - 점차 rear가 증가하면 포화 상태로 도달

    - 원소가 큐에 가득차있지 않을 수도 있다.

      > front 측에서 삭제가 일어났다면 그만큼 공간이 비어있기 때문이다.

    - 포화 상태 도달 시 첫번째 원소의 위치를 [0]번 인덱스부터 위치하게 한다.

    - front의 위치를 기준으로 rear의 위치를 다시 지정한다.

  - 큐 원소 이동에 따른 지연시간을 발생 시킨다.

- **원형 큐**

  

  ![Untitled Diagram](https://user-images.githubusercontent.com/55940552/106107659-87ffc700-618a-11eb-8187-c0b5e805ee6b.png)   

  

  - 순차 표현 시 원형 큐를 이용하면 원소의 이동 없이 이용 가능
  - front, rear를 0으로 초기화
  - 원소 삽입 시 우선적으로 큐가 **포화 상태**임을 확인한다.
    - 포화 상태가 아니라면 : rear를 1 증가, 해당 위치에 data 삽입

  ```c
  // 큐에 데이터를 삽입하는 함수
  int QueueEnQueue(int value) {
  	// 큐가 포화상태라면
  	if (QueueFull()) {
  		printf("Queue is full!");
  		return 0; // 0 리턴 후 함수 종료
  	}
  
  	// 포화 상태가 아니라면
  	// 큐의 뒷단에 값을 삽입하고
  	queue[rear] = value;
  	rear++; // 뒷단의 인덱스를 나타내는 변수를 증가 시켜준다.
  
  	// 증가된 뒷단 인덱스를 의미하는 변수가 큐의 최대원소와 같으면
  	if (rear == MAX)
  		rear = 0; // 뒷단의 인덱스 변수를 0으로 초기화(원형 큐)
  
  	return 1; // 삽입이 완료된 상태라면 1을 리턴 
  }
  ```

  

  - 원소 삭제 시 우선적으로 큐가 **공백 상태**임을 확인한다.
    - 공백 상태가 아니라면 : front를 1 증가, 해당 위치의 data를 삭제

  ```c
  // 큐에 데이터를 삭제하는 함수
  int queueDequeue(int *value) {
  	// 큐가 공백 상태라면
  	if (QueueEmpty()) {
  		printf("Queue is Empty!");
  		return 0;
  	}
  
  	// 큐의 가장 앞단에 있는 데이터를 value에 저장
  	*value = queue[front];
  	front++; // front 증가
  
  	// 데이터 삽입 시 : 0, 1, 2... 인덱스에 삽입
  	// 데이터 삭제 시 : 3, 4, 5... 인덱스에 데이터들이 삭제
  	// FIFO 방식으로 가장 먼저들어온 데이터가 가장 먼저 나간다는 방식
  
  	// 가장 먼저들어온 데이터를 나타내는 front가 최대 원소 개수와 같아진다면
  	if (front == MAX) {
  		front = 0; // 0으로 초기화
  	}
  	return 1;
  }
  ```



### **⚙ 큐 구현**

- **단순 1차원 배열을 통한 순차 큐 구현**

  [Queue.c](https://github.com/Lee-HyeongSeok/SW_expert_examples/tree/main/DataStructure/Queue/SW_Expert_Reference_Code)

- **구조체를 이용한 순차 큐 구현**

  [Queue_Structure.c](https://github.com/Lee-HyeongSeok/SW_expert_examples/tree/main/DataStructure/Queue/KPU_Class)

- **구조체를 이용한 원형 큐 구현**

  [CircularQueue.c](https://github.com/Lee-HyeongSeok/SW_expert_examples/tree/main/DataStructure/Queue/Circular_Queue)

- **클래스를 이용한 원형 큐 구현**

  [CircularQueueCpp.cpp](https://github.com/Lee-HyeongSeok/SW_expert_examples/tree/main/DataStructure/Queue/Circular_Queue_CPP)

***

**[출처]**

[SW Expert Academy](https://swexpertacademy.com/main/visualcode/main.do#/home/editor//)

[진짜 개발자 블로그](https://galid1.tistory.com/483)

[한국산업기술대학교](https://portal.kpu.ac.kr/)