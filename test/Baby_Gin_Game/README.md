## * Baby Gin Game	in S/W expert self study   
#### * cpp

#### * 문제
			* 0~9 사이의 숫자 카드에서 임의의 카드 6장을 뽑았을 때   
			* 3장의 카드가 연속적인 번호를 가지면 run   
			* 3장의 카드가 동일한 번호를 가지면 triple   
			* 6장의 카드가 run과 triple로만 구성된 경우를 Baby-Gin이라고 한다.   
			* 6장의 숫자를 입력 받아 Baby-Gin 여부를 판단하는 프로그램 작성   

#### * 입력 예   

```c
667767	-> 	두 개의 triplet 이므로 Baby-Gin (666,777)
054060	-> 	한 개의 run과 한 개의 triplete이므로 Baby-Gin (456, 000)
101123	-> 	한 개의 triplet가 존재하지만 023이 run이 아니므로 Lose
```