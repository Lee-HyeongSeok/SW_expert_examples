## **Linked List - 연결 리스트 자료구조**

***

### **목차**

- **ArrayList와 LinkedList**

  - [1] ArrayList 선형 리스트란

    - ArrayList 선형 리스트 특징

  - [2] LinkedList 연결 리스트란

    - LinkedList 연결 리스트 특징
    - LinkedList 연결 리스트 종류

    

- **연결 리스트 구현**

  - 1차원 배열을 이용한 구현
  - 포인터를 이용한 구현

  

- **단순 연결 리스트를 이용한 다양한 구현**

***



### **⚙ ArrayList(선형리스트)와 LinkedList(연결리스트)**

**1. ArrayList 선형 리스트란**

> 배열과 같이 연속되는 메모리에 저장되는 리스트

- 연접 리스트(Dense List) 또는 축차 구조(Sequential Structure)라고도 한다.<br> 

  **1-1. ArrayList 선형 리스트 특징**

  - 가장 간단한 자료구조

  - 접근 속도가 빠르다.

  - 중간에 자료를 사입하기 위해서는 연속된 빈 공간이 있어야 한다.

  - 자료의 개수가 n개일 때 

  > 삽입 시 평균 이동 횟수 : (n+1)/2
  >
  > 삭제 시 평균 이동 횟수 : (n-1)/2

  ![ArrayList](https://user-images.githubusercontent.com/55940552/105946651-038a4700-60ab-11eb-85a3-9a6a578c828a.png) 

<br> 

**2. LinkedList 연결 리스트란**

> 자료들을 임의의 메모리에 저장 시키지만 자료 항목의 순서에 따라 노드의 포인터<br> 부분을 이용하여 서로 연결 시킨 자료 구조

- 메모리 주소를 이용한 리스트

  **2-1. LinkedList 연결 리스트 특징**

  - 메모리 공간이 연속적이지 않아도 된다.
  - 포인터를 찾는 시간이 필요하기 때문에 접근 속도가 느리다.
  - 중간에 연결이 끊길 시 다음 노드를 찾기 힘들다.
  - 트리에 적합한 자료 구조
  - 노드의 삽입, 삭제 작업이 용이하다.<br> 

  **2-2. LinkedList 연결 리스트 종류**

1. **단순 연결 리스트(Single Linked List)**

![단순](https://user-images.githubusercontent.com/55940552/105948967-42ba9700-60af-11eb-85b3-f987f2dd41a2.png) 

2. **단순 원형 연결 리스트(Single Circular Linked List)**

![단순원형](https://user-images.githubusercontent.com/55940552/105948968-42ba9700-60af-11eb-9952-a5cfb64f26c6.png) 

3. **이중 연결 리스트(Double Linked List)**

![이중연결](https://user-images.githubusercontent.com/55940552/105948964-41896a00-60af-11eb-8971-f92d9cd0380c.png) 

4. **이중 원형 연결 리스트(Double Circular Linked List)**

![이중원형](https://user-images.githubusercontent.com/55940552/105948965-42220080-60af-11eb-978d-dbd12a751527.png) <br> 

***



### **⚙ 연결 리스트 구현 방법 - 단순 연결 리스트(SLL)**

- **1차원 배열을 이용한 구현**
  
  - 구현이 간단하다.
  
  - 삽입, 삭제 시 오버헤드 발생 가능
  
  - 항목 개수 제한
  
  - 순차적 메모리 공간할당 특징으로 **순차적 표현(Sequential Representation)**이라고 한다.   
  
    [1차원 배열을 이용한 구현](https://github.com/Lee-HyeongSeok/SW_expert_examples/tree/main/DataStructure/Linked_List/1%EC%B0%A8%EC%9B%90%EB%B0%B0%EC%97%B4%EA%B5%AC%ED%98%84)
  
    [1차원 배열을 이용한 구현 - SW expert academy](https://github.com/Lee-HyeongSeok/SW_expert_examples/tree/main/DataStructure/Linked_List/SW_Expert_Reference_Code)   
    
    ![Untitled Diagram (2)](https://user-images.githubusercontent.com/55940552/108474600-effd8500-72d2-11eb-96e4-d46f243de134.png) 
    
    <br> 
    
    
  
- **포인터를 이용한 구현**
  
  - 구현이 복잡하다.
  
  - 삽입, 삭제가 효율적이다.
  
  - 데이터를 저장할 공간이 제한적이지 않다.
  
  - 메모리를 효율적으로 사용할 수 있다.
  
  - 메모리 공간이 연속적으로 구성되지 않는다.
  
  - 하나의 노드 구조체에 <데이터, 다음 노드 주소를 가리키는 포인터> 쌍이 존재한다.
  
  - 삽입 연산 시 새로운 노드를 동적할당 하여 head 노드와 연결해준다.<br> 
  
  - **삭제 연산**
  
    ![delete](https://user-images.githubusercontent.com/55940552/105963491-65a37600-60c4-11eb-9035-581cc7be92f2.png)<br> 
  
  - **삽입 연산**
  
    ![insert](https://user-images.githubusercontent.com/55940552/105963484-64724900-60c4-11eb-8456-bad0b1add025.png) 
  

<br> 



***



### **⚙ 단순 연결 리스트를 이용한 다양한 구현**

- 📌 [포인터를 이용한 단순 연결 리스트 구현](https://github.com/Lee-HyeongSeok/SW_expert_examples/tree/main/DataStructure/Linked_List/%EB%85%B8%EB%93%9C%EA%B5%AC%ED%98%84)
- 📌 [포인터를 이용한 다항식 연산 연결 리스트 구현](https://github.com/Lee-HyeongSeok/SW_expert_examples/tree/main/DataStructure/Linked_List/%EB%8B%A4%ED%95%AD%EC%8B%9D)
- 📌 [head, tail 포인터를 이용한 Stack 구현](https://github.com/Lee-HyeongSeok/SW_expert_examples/tree/main/DataStructure/Linked_List/LinkedList_stack%EA%B5%AC%ED%98%84)   





***

**[출처]**

[SW Expert Academy](https://swexpertacademy.com/main/visualcode/main.do#/home/mainlayout)

[한국산업기술대학교](https://portal.kpu.ac.kr/portal/default/stu)

[코딩 팩토리 블로그](https://coding-factory.tistory.com/228)