## **Page Replacement Algorithm 페이지 교체 알고리즘**

***

### **⚙ 페이지 교체 알고리즘 - 요구 페이징 시스템**

- 프로세스가 특정 페이지 요구 시 해당 페이지를 물리 메모리에 로딩한다.

- 메모리에 필요한 페이지가 존재할 경우는 진행, 존재하지 않을 경우 문제

  > 존재하지 않을 경우,
  >
  > 하드 디스크에서 페이지를 찾아 빈 프레임에 로딩하는데, 페이지를 로딩할 빈 프레임이 없는<br> 경우라는 문제를 직면할 수 있음
  >
  > **이 때 사용하는 것이 새로 로딩할 페이지와 교체될 프레임을 찾는 알고리즘이 페이지 교체 알고리즘**

   



### **⚙ 페이지 교체 알고리즘**

- FIFO(First in First Out)

  - 메모리에 기록된지 가장 오래된 페이지를 교체

  - 즉, 처음 들어왔던 페이지가 가장 오래된 페이지로 가장 먼저 교체된다.

  - 각 페이지가 기록된 시간을 페이지에 기록하거나, 페이지가 올라온 순서를 Queue에 저장

  - **Queue**는 자료의 입출력을 FIFO 방식으로 다루기 때문

    [FIFO 페이지 교체 알고리즘 구현](https://github.com/Lee-HyeongSeok/SW_expert_examples/blob/main/PageReplacementAlgorithm/FIFO.c)   

    

- LRU(Least Recently Used)

  - 가장 오래 사용되지 않은 페이지를 교체하는 알고리즘
  - 페이지가 사용될 시간을 과거 데이터를 바탕으로 예측하여 교체
  - 예측 방법으로 가장 오랜 기간 사용되지 않은 페이지를 교체하는 방식
  - FIFO 알고리즘보다 효율적이다.

   

- LFU(Least Frequently Used)

  - 참조 횟수가 가장 작은 페이지를 교체하는 알고리즘

  - 교체 대상 페이지가 여러 개일 경우 LRU 알고리즘을 따라 가장 오래 사용되지 않은 페이지로 교체

    [LFU 페이지 교체 알고리즘 구현](https://github.com/Lee-HyeongSeok/SW_expert_examples/blob/main/PageReplacementAlgorithm/LFU.c)   

   

- MFU(Most Frequently Used)
  - 참조 횟수가 가장 많은 페이지를 교체하는 알고리즘
  - 참조 횟수가 적은 페이지 : 최근에 사용된 것, 앞으로 사용될 가능성이 높다는 판단
  - 구현에 상당한 비용이 든다.

***

**[출처]**

[한국산업기술대학교](https://www.kpu.ac.kr)

[POCS 블로그](https://medium.com/pocs/%ED%8E%98%EC%9D%B4%EC%A7%80-%EA%B5%90%EC%B2%B4-page-replacement-%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-650d58ae266b)

