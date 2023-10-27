# Python (Python 3)

백준 문제를 풀며 공부한 PYTHON에 대해 정리한 내용들입니다.
<br><br>

***
* **sys.stdin.readline**  
빠른 입출력을 위해 사용되며, 개행문자까지 입력받으므로 .rstrip()을 해주는 것이 좋다.  
다음 코드처럼 사용할 수 있다.

``` Python
import sys

input = sys.stdin.readline
a = input().rstrip()
```
<br>

* **bisect left / bisect right**  
이진 탐색을 쉽게 구현하게 해주는 함수이다.  
이진 탐색이기 때문에 리스트는 정렬되어 있어야 한다.  
bisect_left는 lower bound , bisect_right는 upper bound로 생각하면 된다.  
참고 : [bisect](https://docs.python.org/ko/3/library/bisect.html)

``` Python
from bisect import bisect left, bisect right

lst = [1, 3, 8, 3, 5, 6, 3, 7, 5]
lst.sort()
print(bisect_left(lst, 3), bisect_right(lst, 5), sep = '\n')
```
<br>

* **Counter**  
리스트의 각 요소들이 몇 번 나오는지 딕셔너리 형태로 반환해 준다.

``` Python
from collections import Counter

lst = [1, 3, 3, 3, 5, 5, 10]
dic = Counter(lst)
```
<br>

* **deque**  
스택과 큐의 기능을 모두 가지는 자료구조로, 출입구가 앞뒤로 존재한다.

``` Python
from collections import deque

dq = deque([2, 3])
dq.appendleft(1)
dq.append(4)
dq.popleft()
dq.pop()
```
<br>

* **enumerate**  
리스트의 원소에 순서값을 부여해주는 함수이다.  
리스트의 원소와 인덱스를 튜플 형태로 반환해 준다.

``` Python
lst = ['A', 'B', 'C', 'D']
for i, item in enumerate(lst, start = 1):
        print(f'{i}번째 값은 {item}입니다.')
```
<br>

* **permutation / combination**  
permutation(순열)은 리스트에서 몇 개를 골라 순서를 고려해 나열한 경우의 수를 말하며,  
combination(조합)은 리스트에서 순서를 고려하지 않고 몇 개를 골라 나열한 경우의 수를 말한다.

``` Python
from itertools import permutations, combinations

lst = ['A', 'B', 'C', 'D']
nPr = permutations(lst, 2)
nCr = combinations(lst, 2)
```
<br>

* **deepcopy**  
객체를 복사할 때, 객체가 가진 모든 멤버(값과 참조형식)를 복사하며,  
중첩된 mutable 변수에 대해서도 완전히 독립성이 유지되는 복사이다.

``` Python
from copy import deepcopy

lst = ['A', 'B', 'C']
copylst = deepcopy(lst)
```
<br>

* **defaultdict**  
딕셔너리를 만드는 dict클래스의 서브클래스이다.  
인자(숫자, 리스트, 셋 등)로 주어진 객체의 기본값을 딕셔너리값의 초기값으로 지정할 수 있다.  
참고 : [defaultdict](https://dongdongfather.tistory.com/69)

``` Python
from collections import defaultdict

int_dict = defaultdict(int)
list_diect = defaultdict(list)
set_dict = defaultdict(set)
```
<br>

* **cmp_to_key**  
sorted와 같은 정렬 함수의 key의 매개변수에 함수를 전달할 때 사용한다.
직접 정렬하는 함수를 만들어 key에 적용시키는 방식이다.

``` Python
from functools import cmp_to_key

nums = map(int, input().split())
nums.sort(key = cmp_to_key(lambda x, y : -1 if x < y else 1))
```
<br>
