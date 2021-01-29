# PickTwoAndAdd
## Problem
### 두 개 뽑아서 더하기
정수 배열 numbers가 주어집니다. numbers에서 서로 다른 인덱스에 있는 두 개의 수를 뽑아 더해서 만들 수 있는 모든 수를 배열에 오름차순으로 담아 return 하도록 solution 함수를 완성해주세요.
### 제한 사항
  - numbers의 길이는 2 이상 100 이하입니다.
  - numbers의 모든 수는 0 이상 100 이하입니다.
### 입출력 예
numbers|result
[2,1,3,4,1]|[2,3,4,5,6,7]
[5,0,2,7]|[2,5,7,9,12]
### 출력 형식
solution 함수에서는 로그 데이터 lines 배열에 대해 초당 최대 처리량을 리턴한다.
#### 입출력 예제
```
입출력 예 #1

2 = 1 + 1 입니다. (1이 numbers에 두 개 있습니다.)
3 = 2 + 1 입니다.
4 = 1 + 3 입니다.
5 = 1 + 4 = 2 + 3 입니다.
6 = 2 + 4 입니다.
7 = 3 + 4 입니다.
따라서 [2,3,4,5,6,7] 을 return 해야 합니다.
```
```
입출력 예 #2

2 = 0 + 2 입니다.
5 = 5 + 0 입니다.
7 = 0 + 7 = 5 + 2 입니다.
9 = 2 + 7 입니다.
12 = 5 + 7 입니다.
따라서 [2,5,7,9,12] 를 return 해야 합니다.
```

## Codetest Url
  - [here](<https://programmers.co.kr/learn/courses/30/lessons/68644>)
  
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
  오름차순으로 정렬하며 내림차순이 필요할 경우 greater를 이용한다. 
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
#### unique
##### Function
  앞, 뒤의 값을 비교하기 때문에 정렬을 한 후에 사용하여야 하며, 중복된 값을 삭제후 변경되지 않은 값은 유지된 상태에서   
  자신이 바꾼 vector의 end()을 반환합니다.
```C++
  // FUNCTION TEMPLATE unique
template <class _FwdIt, class _Pr>
_NODISCARD _CONSTEXPR20 _FwdIt unique(_FwdIt _First, _FwdIt _Last, _Pr _Pred) {
    // remove each satisfying _Pred with previous
    _Adl_verify_range(_First, _Last);
    auto _UFirst      = _Get_unwrapped(_First);
    const auto _ULast = _Get_unwrapped(_Last);
    if (_UFirst != _ULast) {
        for (auto _UFirstb = _UFirst; ++_UFirst != _ULast; _UFirstb = _UFirst) {
            if (_Pred(*_UFirstb, *_UFirst)) { // copy down
                while (++_UFirst != _ULast) {
                    if (!_Pred(*_UFirstb, *_UFirst)) {
                        *++_UFirstb = _STD move(*_UFirst);
                    }
                }

                _Seek_wrapped(_Last, ++_UFirstb);
                return _Last;
            }
        }
    }

    _Seek_wrapped(_Last, _ULast);
    return _Last;
}

template <class _FwdIt>
_NODISCARD _CONSTEXPR20 _FwdIt unique(_FwdIt _First, _FwdIt _Last) { // remove each matching previous
    return _STD unique(_First, _Last, equal_to<>{});
}
```
##### Etc
  - 중복된 값 삭제
  unique 함수를 이용하여 중복제거 후 변경되지 않은 부분을 vector.end()를 이용하여 삭제할 수 있습니다.
  ```C++
  vector.erase(unique(vector.begin(), vector.end()), vector.end());
  ```

  
