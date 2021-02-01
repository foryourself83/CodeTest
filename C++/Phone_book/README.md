# Phone_book
## Problem
### 전화번호 목록
전화번호부에 적힌 전화번호 중, 한 번호가 다른 번호의 접두어인 경우가 있는지 확인하려 합니다.   
전화번호가 다음과 같을 경우, 구조대 전화번호는 영석이의 전화번호의 접두사입니다.
### 제한 사항
  - phone_book의 길이는 1 이상 1,000,000 이하입니다.
  - 각 전화번호의 길이는 1 이상 20 이하입니다.
### 입출력 예
phone_book|return
"119","97674223","1195524421"|false
"123","456","789"|true
"12","123","1235", "567", "88"|false
#### 입출력 예제
```
입출력 예 #1
앞에서 설명한 예와 같습니다.
```
```
입출력 예 #2
한 번호가 다른 번호의 접두사인 경우가 없으므로, 답은 true입니다.
```
```
입출력 예 #3
첫 번째 전화번호, “12”가 두 번째 전화번호 “123”의 접두사입니다. 따라서 답은 false입니다.
```

## Codetest Url
  - [here](<https://programmers.co.kr/learn/courses/30/lessons/42577>)
  
## Explanation
### 필요 지식
 - std, vector, algorithm
### 함수  
  - solution(vector<int> numbers)
    더하기, 정렬, 중복 제거를 수행하는 함수.
  - main(void)
    데이터를 입력하고 soulution 함수를 실행하는 함수     
### Algorithm
#### sort
##### Fuction
  오름차순으로 정렬하며 내림차순이 필요할 경우 `greater<자료형>()`를 이용한다. 
```C++
  template <class _RanIt, class _Pr>
_CONSTEXPR20 void sort(const _RanIt _First, const _RanIt _Last, _Pr _Pred) { // order [_First, _Last)
    _Adl_verify_range(_First, _Last);
    const auto _UFirst = _Get_unwrapped(_First);
    const auto _ULast  = _Get_unwrapped(_Last);
    _Sort_unchecked(_UFirst, _ULast, _ULast - _UFirst, _Pass_fn(_Pred));
}

template <class _RanIt>
_CONSTEXPR20 void sort(const _RanIt _First, const _RanIt _Last) { // order [_First, _Last)
    _STD sort(_First, _Last, less<>{});
```
