# 지역별 환자 관리 프로그램

BST와 heap을 활용하여 지역별 환자 정보를 확인하고 갱신하는 프로그램이다.
자세한 정보는 스펙문서 참조

---

## Main class

* Location_BST: 지역 정보를 담고 있는 BST, Location_Node들이 BST로 이루어진 구조이며, 각 Location_Node들이 BST로 이루어진 구조이며 각 Location_Node들의 Patient_BST를 참조할 수 있어 명령을 받으면 이 BST에서 구체적인 동작을 관리할 수 있다.

* Patient_BST: 각 Location_BST의 노드마다 하나씩 연결된 BST이다. 환자의 정보를 갖는 patient node들을 queue에서 pop되어 최종적으로는 이 BST에 삽입될 것이다. Search,
insert, delete와 같은 가장 낮은 단계에서의 연산이 구체적으로 함수로 정의되어 있다.

* Location_MaxHeap: BPOP명령어를 받으면 Location_BST에서 해당하는 환자를 삭제할 때, 환자들이 삭제된 기록을 담는 heap이다. 각 지역별로 총 몇 명의 환자들이 삭제되었는지
max_heap의 방식으로 기록하고 있으며 BPOP이 일어날 때마다 계속 heap의 구조를 갱신해줘야 한다.




---

## Commands

* LOAD: data.txt에서 환자의 정보를 읽어 patient_queue에 모두 저장한다. 텍스트 파일이 없거나 자료구조에 이미 데이터가 기록되어 있으면 에러코드 100을 출력한다.

* ADD: LOAD외에 patient_queue에 데이터를 직접 추가하기 위한 명령어이다. 환자의 이름, 체온, 기침 여부, 지역을 입력하며 이중에 하나라도 없으면 에러코드 200을 출력한다.

* QPOP: patient_queue에 담겨있는 환자 데이터를 Location_BST로 옮긴다. 인자로 숫자를 전달하며 이 숫자만큼 데이터를 이동한다. 이 숫자가 만약 queue에 저장된 데이터 수보
다 크면 에러코드 300을 출력한다.

* SEARCH: 인자로 이름을 전달하며 해당하는 이름의 환자의 정보를 Location_BST에서 찾아서 출력한다. 만약 해당 이름이 없으면 에러코드 400을 출력한다.

* PRINT: 자료구조의 데이터들을 출력하는 명령어이다. 첫번째 인자로 B 또는 H를 전달하며 B이면 Location_BST, H이면 Location_MaxHeap을 출력한다. 물론 출력방식도 인자로
전달해야 하며 이 중 하나라도 없거나 Location_Maxheap에 데이터가 없는 경우 에러코드 500을 출력한다.

* BPOP: BST에 저장된 환자 정보를 지운 후, Location_Maxheap의 지역별 환자 수를 갱신한다. 이름 인자가 입력되지 않은 경우, 이름의 정보가 bst에 없을 경우 에러코드 600을 출
력한다.





---

## Flowchart

![image](https://user-images.githubusercontent.com/67624104/118355397-be7f1780-b5aa-11eb-9279-04a6e3391650.png)


* 가장 먼저 command.txt에서 명령어를 읽어온다.

* 가장 처음에는 LOAD가 와야 할 것이다. LOAD 혹은 ADD 명령어가 들어온 경우 data.txt에서 환자정보를 전부 patient_queue에 담거나 ADD인자의 값을 담는다.

* QPOP명령어가 들어온 경우 queue에서 인자로 들어온 수만큼 pop하여 location_BST에 값을 insert한다. 물론 이 수가 큐의 size보다 크면 예외처리를 구현한다.
 
* SEARCH명령어가 들어온 경우 먼저 Location_BST가 명령어를 받고, 내부적으로 각 LocationNode의 patient_BST마다 search를 시킨다.
 
* PRINT명령어가 들어온 경우 B, H 값과 출력 방식에 맞게 각각 BST를 출력하고 예외처리도 구현한다.
 
* BPOP명령어가 들어온 경우 SEARCH에서의 경우와 비슷하게 먼저 location_BST가 명령어를 받고 내부적으로 LocationNode의 patient_BST에서 delete를 시킨 후, 해당하는
location을 반환하여 location_maxheap에게 전달한다. 값을 전달받은 Location_Max_heap에서는 힙 구조를 update까지 한다.

* 각 과정이 끝나면 다음 명령어를 받으며 명령이 더 이상 없을 때까지 위의 과정을 반복한다.




---

## Result & Analysis

1. Data.txt, command.txt

![image](https://user-images.githubusercontent.com/67624104/118355497-4402c780-b5ab-11eb-8705-b7c466ebfcb1.png)


2. Log.txt

![image](https://user-images.githubusercontent.com/67624104/118355509-50872000-b5ab-11eb-905a-4c822682bf4d.png)

- Data.txt의 LOAD가 성공했음을 알 수 있다.

- LOAD를 또 했더니 에러코드 100가 출력 되었다.

- ADD가 성공했음을 알 수 있다.

- ADD에 인자를 두 개 덜 주었더니 에러코드 200이 출력 되었다.

- Data.txt에 12개, ADD로 1개 넣어서 현재 큐의 크기는 13인데 15만큼 POP하려 하여 에러코드 300이 출력되는 것을 확인할 수 있다.

- QPOP 7, QPOP 6은 성공적으로 수행되어 13개의 데이터를 전부 뽑아내었음을 추측할 수 있다.

- PRINT B만 입력하고 출력 방식은 입력하지 않아 에러코드 500이 나오는 것을 확인할 수 있다.

- Location_BST에서 Gwangju부터 시작하여 사람들이 LEVEL ORDER로 출력되는 것을 확인할 수 있다.

- In order 방식이기 때문에 부산부터 사람들이 In-order로 출력되는 것을 확인할 수 있다.

- Tom을 성공적으로 Bpop해왔다.

- Tom이 서울 사람이었기 때문에 heap에서 seoul이 1로 출력 되는 것을 볼 수 있다.

- 없는 사람을 BPOP하려 하여 에러코드 600이 나왔다.


![image](https://user-images.githubusercontent.com/67624104/118355547-7f9d9180-b5ab-11eb-81cf-79fa6061c93f.png)


- Soondl가 제대로 BPOP되었음을 알 수 있다.

- 다시 heap을 출력해보니 soondl의 지역인 인천이 추가되었다.

- 없는 사람을 search하여 에러코드 400이 나왔다.

- Kwang을 search하면 존재하기 때문에 값이 제대로 나온다.

- Erin이 제대로 BPOP되었음을 알 수 있다.

- Erin이 없어진 상태로 제대로 출력되는 것을 볼 수 있다.

- T 옵션이 들어가면 에러코드 500이 나오는 것을 확인할 수 있다.
 
- Emily를 성공적으로 BPOP한 것을 확인할 수 있다.

- Emily가 인천사람이었기 때문에 Incheon의 count가 2가 되어 가장 위로 갱신된 것을 확인할 수 있다.





---

## Consideration

* Ifstream.eof()함수가 어떤 경우에는 잘 동작하고 어떤 경우에는 segmentation fault 유발
 -> 본인이 진단한 문제: eof함수는 파일의 끝이냐 아니냐를 의미하는게 아니라 eof를 읽었냐 안 읽었냐로 값을 return한다. 즉 글의 맨 마지막에 개행문자를 넣지 않았다면 eof까지 읽어들여서 참의 값을 반환할 것이다. 그러나 마지막에 개행문자를 넣었다면 개행문자까지만 읽고 eof를 읽지 않았기 때문에 다시 line을 읽어오려 할 건데 여기서 segmentation fault가 발생하게 되는 것이다.
 
 * 소멸자 호출 시 null 인 변수도 delete될 때 문제가 없다는 점을 항상 상기하자.
