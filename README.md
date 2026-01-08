# 코딩 테스트 문제 풀이 및 주요 내용 정리
> [https://www.acmicpc.net/workbook/view/21405](https://www.acmicpc.net/workbook/view/21405)

본 레포지토리는 백준 알고리즘 워크북을 기반으로 문제 풀이 과정에서 사용된 주요 문법, 라이브러리, 알고리즘 개념 등을 정리하기 위한 공간입니다.

해결한 문제의 코드와, 문제를 해결하며 새롭게 알게 된 표준 라이브러리 활용법, 유용한 함수 및 문법 요소, 자주 사용되지만 헷갈리기 쉬운 개념들을 중심으로 정리하는 것을 목표로 합니다.

이를 통해 이후 유사 문제를 풀거나, 관련 내용을 참고하고자 할 때 빠르게 개념을 떠올리고 적용할 수 있는 참고용 문서 역할을 수행하도록 구성하였습니다.

![Language](https://img.shields.io/badge/Language-C++-blue)

## 주요 내용 정리

### 📌 목차

- [1. 표준 정수 한계 상수 헤더 `<climits>`](#1-표준-정수-한계-상수-헤더-climits)
- [2. 문자열 - 숫자 간 형변환](#2-문자열---숫자-간-형변환)
- [3. 입출력 형태 지정 헤더 `<iomanip>`](#3-입출력-형태-지정-헤더-iomanip)
- [4. 수학 함수 헤더 `<cmath>`](#4-수학-함수-헤더-cmath)
- [5. 투 포인터 (Two pointer) 알고리즘](#5-투-포인터-two-pointer-알고리즘)
- [6. 슬라이딩 윈도우 (Sliding Window) 알고리즘](#6-슬라이딩-윈도우-sliding-window-알고리즘)
- [7. map과 unordered_map의 시간 복잡도 분석](#7-map과-unordered_map의-시간-복잡도-분석)


### 1. 표준 정수 한계 상수 헤더 `<climits>`

C++ 표준 라이브러리에서 제공하는 정수 제한 헤더 파일로 정수의 최댓값, 최솟값 등에 대한 상수값을 제공한다. 

```c++
#include <climits>

CHAR_BIT // char 형식 변수의 비트 수, 8
CHAR_MAX // char 형식 변수 최댓값, 127
CHAR_MIN // char 형식 변수 최솟값, -128

SHRT_MAX // short 형식 변수의 최댓값, 32767
SHRT_MIN // short 형식 변수의 최솟값, -32768

INT_MAX // int 형식 변수의 최댓값, 2147483647
INT_MIN // int 형식 변수의 최솟값, -2147483648

LONG_MAX // long 형식 변수의 최댓값, 9223372036854775807
LONG_MIN // long 형식 변수의 최솟값, -9223372036854775808

LLONG_MIN // long long 형식 변수의 최댓값, 9223372036854775807
LLONG_MAX // long long 형식 변수의 최솟값, -9223372036854775808
```

자료형의 크기는 OS가 체택한 데이터 모델과 컴파일러에 따라 다르다.<br>
`LONG_MAX, LONG_MIN`과 `LLONG_MAX, LLONG_MIN`의 값은 64bit Linux / macOS의 경우 `long`과 `long long` 모두 64bit의 크기를 가지기에 위 결과와 같이 동일하다.<br>
그러나 동일 64bit인 Windows 운영체제의 경우 `long` 타입과 `long long` 타입은 각각 `32bit`, `64bit`의 메모리 크기를 가지기에 결과값이 다른 것을 알 수 있다.<br>

결과적으로 운영체제에 따라 자료형의 크기가 달라 보일 수 있지만, 운영체제가 사용하는 `데이터 모델(ABI)`과 컴파일러와 같은 환경에 따라 자료의 크기가 결정된다.

<br>

### 2. 문자열 - 숫자 간 형변환

다음 모든 문자열-숫자간 형변환은 `string` 헤더 파일을 통해 사용 가능하다.
```c++
#include <string>
...
```

<br>

`stoi` 함수: 문자열을 `int`타입으로 변환하고자 할 경우 사용한다. `string`의 문자 시퀀스를 형식 `int`값으로 변환하고 이를 반환한다.
```c++
int stoi(
    const string& str,
    size_t* idx = 0,
    int base = 10);

int stoi(
    const wstring& str,
    size_t* idx = 0,
    int base = 10);
```
```c++
stoi("100") // 100 (Integer)
```

<br>

`to_string` 함수: 숫자형 값을 `string` 타입으로 변환한다.
```c++
string to_string(int value);
string to_string(unsigned int value);
string to_string(long value);
string to_string(unsigned long value);
string to_string(long long value);
string to_string(unsigned long long value);
string to_string(float value);
string to_string(double value);
string to_string(long double value);
```
```c++
to_string(100) // "100" (String)
```

<br>

추가로 문자형(`char`타입) 변수와 정수간 변환은 아래와 같이 아스키 연산을 통해 구현할 수 있다.
```c++
// 문자 -> 정수
char c_number = '7';
int i_number = c_number - '0'; // 7 (Integer)

// 정수 -> 문자
int i_number = 7;
char c_number = i_number + '0'; // '7' (Character)
```

단, 이러한 아스키 연산을 통한 형변환은 오직 `단일 문자`와 `0~9`의 정수간 변환에서만 사용 가능하다.
<br>이는 내부적으로 비트를 통해 값을 저장하는 `char`타입 변수가 아스키 코드와 매핑되는데, 0 ~ 9까지의 값이 실제 숫자 `0~9`를 가리키기에 적용 가능한 형변환 방식이다.

<br>

### 3. 입출력 형태 지정 헤더 `<iomanip>`

`iomanipulator`를 사용하여 C++에서 출력 포멧을 조절 가능하다. 아래의 헤더 파일을 포함하여 이를 사용할 수 있다.

```c++
#include <iomanip>
...
```

<br>

manipulator는 "조작자", "조종자"라는 뜻을 가지며, `iomanip` 헤더에서는 다양한 조작자를 제공한다.

`fixed`: 실수 출력 형식을 고정 소수점 형식으로 지정한다. 즉 총 자릿수가 아닌 소수점 아래 자릿수 기준으로 출력하게 한다.

`setprecision`: 출력할 소수점 아래 자릿수를 인자로 전달한 길이로 지정한다.
```c++
T5 setprecision(streamsize Prec);
```

<br>

아래의 예시 코드를 통해 fixed와 setprecision을 사용하여 출력 포멧을 설정한 경우에 대해 알아보면
```c++
cout << fixed << setprecision(4);
cout << 123.456789 << endl;
cout << 0.001234567 << endl; 
cout << 123456.0;     
```
fixed를 사용할 경우 
```c++
// fixed 사용
123.4568
0.0012
123456.0000
```
위와 같은 결과가 출력되며, 이는 `setprecision`의 인자를 통해 전달된 길이 4가 소수점 밑 자릿수의 크기로 사용되어 출력된 것을 알 수 있다.
```c++
// fixed 사용 X
123.5
0.001235
1.235e+05
```
위 결과는 fixed를 사용하지 않은 경우로, 숫자 자료형의 전체 `유효숫자` 자릿수를 지정한 결과가 출력된다.

결과적으로 가독성 측면에서 의미있는 유효숫자를 중심으로 출력하고자 할 경우 `fixed`를 사용하지 않고 `setprecision`만 사용하는 것이 좋으며

정확한 계산 결과를 필요로 할 경우 `fixed`를 통한 부동소수점 형식으로 정확한 소수 자릿수까지 출력할 수 있다.

<br>

### 4. 수학 함수 헤더 `<cmath>`

C++ 표준 라이브러리에 포함되어 있는 `<cmath>`는 실제 공학 연산에서 사용하는 다양한 수식들을 손쉽게 접근할 수 있도록 정리되어 있다.

`ceil(x)`: x값을 정수 올림하여 반환한다.
```c++
float ceil(float x);
double ceil(double x);
long double ceil(long double x);
```

<br>

`floor(x)`: x값을 정수 내림하여 반환한다.
```c++
float floor(float x);
double floor(double x);
long double floor(long double x);
```

<br>

`abs(x)`: 인자로 전달한 x값을 절대값으로 반환한다.
```c++
int abs(int j);
long int abs(long int j);
long long int abs(long long int j);
float abs(float j);
double abs(double j);
long double abs(long double j);
float fabs(float x);
double fabs(double x);
long double fabs(long double x);
```

`pow(x, y)`: x의 y 제곱 연산을 반환한다.
```c++
float pow(float x, float y);
double pow(double x, double y);
long double pow(long double x, long double y);
```

`exp(x)`: 자연상수 e의 x 제곱 연산을 반환한다.
```c++
float exp(float x);
double exp(double x);
long double exp(long double x);
```

`sqrt(x)`: x의 제곱근을 반환한다.
```c++
float sqrt(float x);
double sqrt(double x);
long double sqrt(long double x);
```

`삼각함수 관련`: 인자로 전달된 값이 radian 값으로 되어 이에 대한 삼각함수 계산값을 반환한다.
```c++
// 아크코싸인
float acos(float x);
double acos(double x);
long double acos(long double x);

// 아크싸인
float asin(float x);
double asin(double x);
long double asin(long double x);

// 아크탄젠트
float atan(float x);
double atan(double x);
long double atan(long double x);

// 코싸인
float cos(float x);
double cos(double x);
long double cos(long double x);

// 싸인
float sin(float x);
double sin(double x);
long double sin(long double x);

// 탄젠트
float tan(float x);
double tan(double x);
long double tan(long double x);

// 역쌍곡코싸인
float acosh(float x);
double acosh(double x);
long double acosh(long double x);

// 역쌍곡싸인
float asinh(float x);
double asinh(double x);
long double asinh(long double x);

// 역쌍곡탄젠트
float atanh(float x);
double atanh(double x);
long double atanh(long double x);

// 쌍곡코싸인
float cosh(float x);
double cosh(double x);
long double cosh(long double x);

// 쌍곡싸인
float sinh(float x);
double sinh(double x);
long double sinh(long double x);

// 쌍곡탄젠트
float tanh(float x);
double tanh(double x);
long double tanh(long double x);
```

<br>

### 5. 투 포인터 (Two pointer) 알고리즘

투포인터 알고리즘은 배열 리스트와 같은 자료형에 접근해야 할 때 두 개의 점의 위치를 기록하며 처리하는 방식이다.

이중 반복문을 이용할 경우 시간 복잡도가 `O(N^2)`이지만, 투포인터 방식으로 해결할 경우 `O(N)`의 시간 복잡도로 해결 가능하다.

<br>

`N`개의 자연수가 저장된 배열에서 연속된 특정 구간의 합이 `K`가 되는 부분을 찾는 예제를 통해 확인해보겠다.

```c++
int N = 7, K = 6;
int arr[7] = {1, 3, 2, 4, 2, 1, 5};
```

투포인터가 아닌, 이중 반복문을 통해 해결할 경우

```c++
for (int i = 0; i < N; i++) {
    int sum = 0;
    for (int j = i; j < N; j++) {
        sum += arr[j];
        
        if (sum == K) {
            // i ~ j까지 구간 가능
        }
    }
}
```

결과적으로 원하는 정답을 구할 순 있지만 `O(N^2)`의 시간복잡도에서<br>
N의 값이 매우 커진다면 문제가 된다. 아래는 투포인터 알고리즘을 사용한 예시이다. 

기본 알고리즘은 `arr[start]` ~ `arr[end]`까지의 합을 `sum`이라 할 때

1. `sum > K` : `sum -= arr[start]; start++;` 
2. `sum < K` : `sum += arr[end]; end++;`
3. `sum = K` : `count++; end++; sum += arr[end]`

```c++
int start = 0, end = 0;
int sum = 0;
int count = 0;

while (true) {
    if (sum >= K) {
        if (sum == 0) {
            count++;
            // start ~ end 구간 기록
        }
        sum -= arr[start];
        start++;

        continue;
    }

    if (end == N) break;
    sum += arr[end];
    end++;
}
```

동일한 결과를 나타내지만, `start`와 `end` 포인터가 각각 최대 N번만 이동하며 연산을 처리하기에 `O(N + N) => O(N)`의 시간복잡도로 문제를 해결할 수 있었다.

사이 구간을 분석할 때 유용하며, 구간의 시작점인 `start(left)`와 `end(right)` 부분의 인덱스를 가리키는 변수가 해당 알고리즘의 핵심이다. 

<br>

### 6. 슬라이딩 윈도우 (Sliding Window) 알고리즘

슬라이딩 윈도우 알고리즘은 투포인터 알고리즘의 특수 형태로 볼 수 있다.

배열 리스트와 같은 자료형의 정해진 구간을 탐색하고자 할 때 사용하며<br>
투포인터와 방식은 동일하나 구간의 `길이(window)가 고정`되어 있다고 생각하면 된다.

```c++
string solve() {
    needSameNumberCnt = ceil(9.0 * M / 10);

    int casesNumber = (N - M) + 1;
    map<int, int> m;

    int left = 0, right = M - 1;
    for (int i = left; i <= right; i++) { // O(M) => O(N)
        m[A[i]]++;
        if (m[A[i]] >= needSameNumberCnt) return CAN;
    }

    for (int i = 1; i < casesNumber; i++) { // O(N-M) => O(N)
        m[A[left]]--;
        m[A[right+i]]++;
        if (m[A[right+i]] >= needSameNumberCnt) return CAN;
        left++;
    }

    return CANT;
}
```

해당 코드는 슬라이딩 윈도우 알고리즘을 적용하여, 빈도 수를 카운팅하는 문제 해결 함수이다.<br>
고정된 길이 M의 구간을 검사하며 구간 내 동일 숫자의 개수를 확인하는 과정을 거친다.<br>

`O(N)`인 선형 시간 내에서 문제를 해결할 수 있다.

<br>

### 7. map과 unordered_map의 시간 복잡도 분석

C++의 STL 컨테이너 중 하나인 `map`에 대하여 시간 복잡도 측면에서 분석해보고자 한다.

```c++
#include <map>
```

기본적으로 map은 `key`값과 `value`값 쌍을 저장하는 컨테이너로 작동하지만 `map`, `unordered_map`은 내부 구조에 따라 시간 복잡도가 다르다.


1. `map`은 이진 탐색 트리 구조를 가지며 순서를 가진다. key, value로 이루어진 pair쌍은 key값에 따라 오름차순으로 자동 정렬된다.

```c++

map<int, int> m1;
m1.insert(make_pair(3, 30));
m1.insert(make_pair(2, 50));
m1.insert(make_pair(1, 10));
for (map<int, int>::iterator it = m1.begin(); it != m1.end(); it++) {
    cout << it->first << endl;
}
```

```bash
1
2
3
```

즉 순서가 존재하며, 검색과 삽입/삭제의 시간 복잡도는 모두 

```math
O(logN)
```

으로, 이진 탐색 트리 내에서 삽입과 삭제가 빈번할 경우 자동으로 정렬되기에 성능 저하를 일으킬 수 있는 문제점이 있다.

2. `unordered_map`은 `Hash Table`을 통해 구현된 자료구조로 이름에서 알 수 있듯이, 정렬되지 않은 `map`으로 볼 수 있다. 삽입과 삭제, 탐색 모두 평균적으로

```math
O(1)
```

의 상수 시간 복잡도를 가지고 있다. 물론 해시 테이블을 통해 구현된 자료구조이기에 해시 충돌과 같은 문제가 발생할 경우,<br>
최악의 경우로 시간 복잡도 `O(N)`을 가진다.

시간적 영역에서 `unordered_map`은 대다수의 경우에서 `map`보다 성능적으로 우수하지만, 공간적 영역에서 `map`보다 일반적으로 많은 메모리를 차지한다.
<br>

`map`, `unordered_map` 모두에서 자주 사용하는 메서드들을 간략히 정리하면 아래와 같다.

```c++
map<int, int> m; // unordered_map<int, int> m;

...

m.begin(); // 변수의 시작 이터레이터 반환
m.end(); // 변수의 마지막 원소 다음 이터레이터 반환
m.empty(); // 저장된 원소가 없으면 true
m.erase(key); // 특정 위치의 원소 혹은 지정 범위 안 원소 삭제
m.find(key); // 찾고자 하는 키값의 이터레이터 반환
m.insert({key, value}); // 키-벨류 쌍 원소 추가
m.size(); // 원소 개수 반환
m[key]
m.at(key) // 특정 키값에 해당하는 벨류 반환
```

