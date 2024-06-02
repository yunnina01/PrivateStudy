# Rust

### Rust란?
메모리 안정성과 성능 및 편의성에 중점을 둔 프로그래밍 언어이다.  
가비지 컬렉터 없이 메모리 안정성을 제공하는 대표적인 언어로, C++의 대체제로 등장하였다.  
Rust를 대표하는 키워드는 안정성, 속도, 병렬 프로그래밍, 함수 프로그래밍, 시스템 프로그래밍이 있다.
<br>

***
### 목차
1. [Rust 소개](#anchor1)
2. [Rust 언어의 기초](#anchor2)
3. [복합 데이터 타입](#anchor2)

***
### Rust 소개 <a id="anchor1"></a>
#### [ Rust의 생김새와 느낌 ]
* **일반적인 흐름 제어 매커니즘**  
for 반복문과 continue 키워드를 포함한다.

* **메서드 문법**  
Rust는 객체 지향 언어가 아니어서 상속 등을 지원하지는 않지만, 객체 지향 언어에 있는 메서드 관련 요소를 가져왔다.

* **고차 프로그래밍**  
함수는 인자로도, 반환값으로도 쓰일 수 있다.

* **타입 애너테이션(type annotation)**  
상대적으로 적게 쓰이지만 가끔씩 컴파일러에 일종의 힌트를 줄 때 필요하다.

* **조건부 컴파일(conditional compilation)**  
if cfg!(...); 같은 코드는 프로그램을 릴리스 버전으로 만들 때에는 포함되지 않는다.

* **암묵적 반환**  
Rust에는 return 키워드가 있지만 보통 생략한다.  
Rust는 표현 기반 언어(expression-based language)다.

#### [ Rust의 목표 ]
Rust는 컴파일 시에 잘못된 데이터에 접근하는 것을 방지한다.  
이를 통해 프로그램에 눈에 띄는 성능 손실 없이 메모리 안전성을 보장한다.

* **안정성**  
댕글링 포인터(dangling pointer), 데이터 경합(data race), 버퍼 오버플로, 반복자 무효화(iterator invalidation)로부터 자유롭다.

* **생산성**  
Rust는 제네릭, 정교한 데이터 타입, 패턴 매칭, 클로저를 제공한다.  
Rust의 빌드 시스템이자 종합적인 패키지 관리자인 카고는 여러 추가적인 기능을 제공한다.  
  * cargo new는 새로운 디렉터리에 Rust 프로젝트의 뼈대를 만든다. (cargo init은 현재 디렉터리를 이용)  
  * cargo build는 의존성 패키지를 다운로드하고 코드를 컴파일한다.  
  * cargo run은 cargo build를 실행하고 나서 생성된 실행 파일을 실행한다.  
  * cargo doc은 현재 프로젝트의 모든 의존성 패키지에 대한 HTML 문서를 만든다.

* **통제력**  
프로그래머는 Rust로 데이터 구조의 메모리 배치 방식과 그 접근 패턴을 세밀하게 제어할 수 있다.

#### [ Rust의 원칙 ]
* 언어의 최우선 사항은 안전성이다.  
* Rust의 데이터는 기본적으로 불변형이다.  
* 컴파일 시 검사를 강력하게 우선시한다. 안전성은 '무비용 추상화'여야 한다.

#### [ Rust의 큰 특징 ]
* **성능**  
Rust는 메모리 안전성을 가비지 컬렉터에 의존하지 않는다.  
또한, Rust 컴파일러는 프로그램의 크기와 속도를 적극적으로 최적화한다.  
  * 캐시 친화적인 데이터 구조가 기본적으로 제공된다.  
  * 최신 패키지 관리자인 카고는 수많은 오픈 소스 패키지를 쉽게 활용할 수 있게 해준다.  
  * 메서드는 동적 디스패치를 명시적으로 요청하지 않는 한 늘 정적으로 디스패치된다.  
    이로 인해 컴파일러는 코드를 강력하게 최적화할 수 있으며, 때로는 함수 호출 비용을 완전히 없앨 수도 있다.

* **동시성**  
* **메모리 효율성**  

#### [ Rust의 단점 ]
* 순환 데이터 구조를 모델링하기 어렵다.  
* 컴파일 시간이 느리다.  
* Rust 컴파일러는 매우 엄격하다.  
* Rust는 큰 언어다.  
* 보안 문제에서 완전히 자유롭지 않고, 소프트웨어 공학의 모든 병폐에 대한 해결법이 아니다.

#### [ Rust의 사용 분야 ]
Rust는 시스템 프로그래밍 언어로 설계되었지만 범용 언어이다.  
Rust는 명령행 유틸리티, 데이터 처리, 애플리케이션 확장, 자원이 제한된 환경, 서버 애플리케이션,  
데스크톱 애플리케이션, 데스크톱, 모바일, 웹, 시스템 프로그래밍 등의 분야에 성공적으로 진출했다.

***
### Rust 언어의 기초 <a id="anchor2"></a>
#### [ 실행 프로그램 만들기 ]
* **rustc로 단일 파일 컴파일** : rustc {file.rs} 명령 실행  
* **카고로 Rust 프로젝트 컴파일** : cargo run

#### [ Rust 문법 개요 ]
Rust는 변수, 숫자, 함수 및 다른 언어에서 볼 수 있는 낯익은 기능을 가지고 있다.  
예를 들어 블록은 중괄호({, })로 구분하고, 단일 등호 기호(=)를 할당 연산자로 사용하며, 공백 제한이 없다.

``` Rust
fn main() {
    let a = 10;                     // 컴파일러가 데이터 타입 추론
    let b: i32 = 20;                // 데이터 타입 지정
    let c = 30i32;                  // 리터럴 형식 + 타입 애너테이션
    let d = 30_i32;                 // 가독성을 위한 밑줄 추가 (기능적 요소는 없음)
    let e = add(add(a, b), add(c, d));

    println!("( a + b ) + ( c + d ) = {}", e);
}

fn add(i: i32, j: i32) -> i32 {
    i + j                           // return 생략 (세미콜론을 붙이면 의미가 달라져 i32 타입이 아닌 ()(유닛) 타입 반환)
}
```

#### [ 정수와 부동 소수점 수 ]
Rust는 다양한 숫자 타입을 포함하며, 바이트 단위로 크기를 선언한다.  
타입 간 변환은 언제나 명시적으로 일어난다. (ex: 16비트 정수를 32비트 정수로 자동 변환하지 않음)  
Rust의 수는 메서드를 가질 수 있다.

| 데이터 타입 | 설명 |
| :---------: | --- |
| **i8, i16, i32, i64, i128** | 8비트에서 128비트 크기의 부호 있는 정수 |
| **u8, u16, u32, u64, u128** | 8비트에서 128비트 크기의 부호 없는 정수 |
| **f32, f64** | 32비트, 64비트 종류가 있는 부동 소수점 수 |
| **isize, usize** | CPU의 '네이티브' 크기를 따르는 정수 |

``` Rust
fn main() {
    let three = 0b11;
    let thirty = 0o36;
    let three_hundred = 0x12C;

    println!("base 10: {} {} {}", three, thirty, three_hundred);        // base 10: 3 30 300
    println!("base 2:  {:b} {:b} {:b}", three, thirty, three_hundred);  // base 2:  11 11110 100101100
    println!("base 8:  {:o} {:o} {:o}", three, thirty, three_hundred);  // base 8:  3 36 454
    println!("base 16: {:x} {:x} {:x}", three, thirty, three_hundred);  // base 16: 3 1e 12c
}
```

#### [ 수의 비교 ]
Rust는 서로 다른 데이터 타입은 비교할 수 없다.  
컴파일러 오류를 해결하려면 as 연산자를 사용하여 피연산자 중 하나를 다른 타입으로 변환해야 한다.  
작은 타입을 큰 타입으로 변환하는 것이 가장 안전하며, 이를 승격(promotion)이라고 부르기도 한다.  
경우에 따라서는 as 키워드가 지나친 제약이 될 수 있기 때문에, as키워드 대신 Rust 메서드를 사용할 수 있다.

``` Rust
use std::convert::TryInto;

fn main() {
    let a: i32 = 10;
    let b: u16 = 100;

    if a < (b as i32) {
        println!("Ten is less than one hundred");
    }

    let b_ = b.try_into().unwrap();
    if a < b_ {
        println!("Ten is less than one hundred");
    }
}
```

#### [ 유리수, 복소수 그리고 다른 숫자 타입 ]
Rust에서 특수한 숫자 타입을 사용하려면 num 크레이트를 사용한다.  (크레이트는 Rust의 패키지를 의미)

``` Rust
use num::complex::Complex;

fn main() {
    let a = Complex { re: 2.1, im: -1.2 };    // 리터럴 구문 (Rust 언어의 일부로 제공)
    let b = Complex::new(11.1, 22.2);         // new() 정적 메서드 (Rust 언어의 일부로 정의되지 않음)
    let result = a + b;

    println!("{} + {}i", result.re, result.im);
}
```

use 키워드는 크레이트를 지역 범위로 가져오고, 이름 공간 연산자(::)는 무엇을 가져올지 제한한다.  
Rust에는 생성자가 없는 대신 모든 타입에 리터럴 형태가 있다.  
간결함을 위해 많은 타입이 new() 메서드를 구현하지만, 이러한 관례가 Rust 언어의 일부는 아니다.

#### [ 흐름 제어 ]
Rust에서는 흐름 제어를 위해 for, continue, while, loop, break, if, if else, else: 조건 분기, match 등의 키워드를 사용한다.  

for 반복문은 Rust에서 반복을 처리하는 핵심이다.  
다른 언어와는 달리 블록이 끝나고 나면 해당 collection에 다시 접근할 수 없다.  
프로그램에서 collection을 다시 사용하고 싶다면 참조를 사용해야 한다.

| 단축 형태 | 동등한 형태 | 접근 |
| :------: | ----------- | --- |
| **for item in collection** | for item in IntoIterator::into_iter(collection) | 소유권 |
| **for item in &collection** | for item in collection.iter() | 읽기 전용 |
| **for item in &mut collection** | for item in collection.iter_mut() | 읽고 쓰기 |

블록 내에서 지역 변수를 사용하지 않는 경우라면 관례적으로 밑줄(_)을 사용한다.  
배제 범위 구문(n..m)이나 포함 범위 구문(n..=m)과 함께 사용하면 반복 횟수를 정확히 정할 수 있다.  
반복문에서 for item in collection 구문으로 collection을 직접 처리하기가 불가능할 때 수동으로 접근하는 방법을 사용한다.  
하지만 수동으로 접근하는 방법은 성능과 안전 측면에서 문제를 일으키므로 일반적으로 권장하는 방식은 아니다.

``` Rust
for _ in 0..10 {                  // 익명 반복문
    // ...
}

let collection = [1, 2, 3, 4, 5];
for i in 0..collection.len() {    // 수동 접근
    let item = collection[i];
    // ...
}
```
<br>

Rust에는 for와 while보다 더 다양한 방식으로 반복을 제어할 수 있는 loop 키워드가 있다.  
loop는 코드 블록을 계속해서 실행하며 절대 중단하지 않는다.  
break 키워드를 만나거나 프로그램이 외부에서 종료될 때까지 loop는 계속 실행된다.  
무한 반복문을 만들 때는 loop를 사용하는 것이 더 선호되는 방식이다.  
loop는 장시간 실행되어야 하는 서버 등을 구현할 때 자주 이용한다.

``` Rust
loop {
    let requester, request = accept_request();
    let result = process_request(request);
    send_response(requester, result);
}
```
<br>

break 키워드는 반복문에서 벗어나기 위해 사용하며, 일반적인 방식으로 동작한다.  
루프 레이블을 사용하여 중첩된 반복문에서 벗어날 수 있으며, 루프 레이블은 아포스트로피(')가 앞에 붙은 식별자다.

``` Rust
'outer: for x in 0.. {
    for y in 0.. {
        for z in 0.. {
            if x + y + z > 1000 {
                break 'outer;
            }

            // ...
        }
    }
}
```
<br>

Rust는 truthy나 falsy 값의 개념이 없다. 즉, true에 사용할 수 있는 유일한 값은 true이며 false의 경우에는 false를 사용한다.  

Rust에서 if/else 블록을 사용할 수 있지만 더 안전한 대안은 match이다.  
match는 해당 타입의 가능한 모든 값에 대한 분기를 처리하지 않으면 컴파일러 오류가 발생한다.  
match는 발생 가능한 여러 값을 검사할 수 있도록 정교하고 간결한 구문을 제공한다.
* 포함 범위(n ..= m)로 범위 내의 값에 일치한다.  
* 불 OR(|)은 각각의 모든 경우에 일치한다.  
* 밑줄(_)은 모든 경우에 일치한다.

일치된 항목은 기본적으로 다음 옵션으로 넘겨지지 않고 일치하는 상황이 생기면 그 즉시 결과를 반환한다.

``` Rust
fn main() {
    let needle = 42;
    let haystack = [1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862];

    for item in &haystack {
        let result = match item {
            42 | 132 => "hit!",
            _ => "miss",
        };

        if result == "hit!" {
            println!("{}: {}", item, result);
        }
    }
}
```

#### [ 표현식 기반 언어 ]
Rust는 표현식 기반 언어로, 표현식 기반 프로그래밍 언어에서 모든 표현식은 값을 반환하며 거의 모든 것이 하나의 표현식이다.  
그 예로 return 키워드를 생략하거나 조건 표현식을 통해 값을 할당할 수 있다.  
또한, break 키워도 역시 값을 반환한다. 이를 이용하면 무한 반복문에서 값을 반환할 수 있다.

``` Rust
fn is_even(n: i32) -> boll {
    n % 2 == 0
}

fn main() {
    let n = 123456;
    let description = if is_even(n) {
        "even"
    } else {
        "odd"
    };
    println!("{} is {}", n, description);

    let m = loop {
        break 123;
    };
    println!("{}", m);
}
```

표현식이 아닌 부분을 문장(statement)이라고 하며, 러스트에서는 다음 세 가지 경우에 해당한다.
* 표현식이 세미콜론(;)으로 끝날 때  
* 할당 연산자(=)로 값에 이름이 바인딩될 때  
* struct 및 enum 키워드로 생성된 타입과 함수(fn)를 포함하는 타입 선언

공식적으로는 첫 번째 형식은 표현문, 나머지 두 가지는 선언문이라고 부른다.  
Rust에서는 어떤 값도 ()(유닛 타입)으로 표현되지 않는다.

#### [ 함수 정의 ]
Rust의 함수에는 매개 변수의 타입과 함수의 반환 타입을 지정해야 한다.

``` Rust
fn add(i: i32, j: i32) -> i32 {
    i + j
}
```

#### [ 참조 사용 ]
참조는 다른 값을 대신하는 값으로, 복제본을 만드는 대신 값의 주소를 저장하고 데이터가 필요한 경우 역참조하여 사용할 수 있다.  
참조는 참조 연산자(&)을 사용하여 생성하고 역참조 연산자(*)를 사용하여 역참조한다.  
이 연산자들은 단항 연산자 역할을 하므로 피연산자는 하나만 필요하다.

``` Rust
fn main() {
    let needle = 0o204;
    let haystack = [1, 1, 2, 5, 15, 52, 203, 877, 4140, 21147];

    for item in &haystack {
        if *item == needle {
            println!("{}", item);
        }
    }
}
```

#### [ 고급 함수 정의 ]
Rust의 안전 검사는 모든 데이터 접근 시도가 유효한지 확인하는 수명 시스템(life-time system)에 토대를 두고 있다.  
주어진 수명에 바인딩된 모든 값은 해당 수명에 바인딩된 다른 값들의 마지막 접근이 끝날 때까지 지속되어야 한다.  
모든 매개 변수가 수명을 가지지만 컴파일러가 대부분 자체적으로 추론할 수 있다.  
함수를 호출할 때는 수명 애너테이션이 필요하지 않다.  
수명 매개 변수는 고수준의 코드를 유지하면서 프로그래머에게 제어 기능을 제공하는 방편이다.

``` Rust
fn add_with_lifetimes<'a, 'b>(i: &'a i32, j: &'b i32) -> i32 {
    *i + *j
}

fn main() {
    let a = 10;
    let b = 20;
    let res = add_with_lifetimes(&a, &b);

    println!("{}", res);
}
```
<br>

제네릭 함수는 다양한 입력 타입을 다루는 함수를 말하며, 특정 타입 대신 대문자가 있으면 제네릭 타입을 의미한다.  
일반적으로 T, U, V 변수가 사용되나 임의의 다른 대문자 변수가 올 수 있고, E는 오류 타입을 나타내는 데 자주 사용된다.  
제네릭으로 상당한 코드 재사용이 가능하고, 강타입 언어의 사용성을 크게 높일 수 있다.

``` Rust
use std::ops::{Add};
use std::time::{Duration};

fn add<T: Add<Output = T>>(i: T, j: T) -> T {
    i + j
}

fn main() {
    let floats = add(1.2, 3.4);
    let ints = add(10, 20);
    let durations = add(Duration::new(5, 0), Duration::new(10, 0));

    println!("{}", floats);
    println!("{}", ints);
    println!("{:?}", durations);
}
```

Rust의 모든 연산자는 트레이트의 메서드에 대한 간편 문법이며, 위와 같은 방식으로 연산자 오버로딩을 지원한다.  
컴파일하는 동안 a + b는 a.add(b)로 변환된다.  
T 타입이 반드시 덧셈을 지원해야 한다면, 함수 정의에 타입 변수와 함께 트레이트 제약을 포함시켜야 한다.  
<T: Add<Output = T>>는 타입 T가 std::ops:Add를 반드시 구현해야 함을 뜻한다.  
트레이트 제약을 가진 단일 타입 변수 T를 사용하면 인자와 결괏값의 타입이 동일한 타입이라는 점을 확실히 하게 된다.  

#### [ 문자열 타입 ]
String과 &str 모두 텍스트를 나타내지만 서로 별개의 고유한 타입이다.  
String은 다른 언어에서 알던 문자열 타입과 가장 가까우며,  
두 문장을 하나로 합치는 것, 새 텍스트를 기존 문자열에 덧붙이는 것, 공백을 없애는 것 등의 연산을 지원한다.  

str은 고성능이지만 상대적으로 기능이 빈약한 타입이다.  
일단 생성되면 str값은 확장하거나 줄일 수 없지만, 정상적인 UTF-8 문자임은 보증된다.  
str은 보통 &str 형태로 쓰이며, &str(문자열 슬라이스 또는 문자열 조각)은 str 데이터의 참조와 길이를 포함한 작은 타입이다.  
변수를 str 타입에 할당하는 시도는 할 수 없으며, str 값은 임의의 길이일 수 있으므로 참조에 의해 로컬 변수로만 저장할 수 있다.  

String은 소유된 타입으로, 소유자는 데이터를 변경할 수 있으며 범위를 벗어날 때 소유한 값을 삭제할 책임이 있다.  
&str은 대여된 타입이다. 실무적인 용어로, &str은 읽기 전용 데이터인 반면 String은 읽기-쓰기가 가능하다.  
문자열 리터럴(ex: "String Literal")은 &str 타입으로, 수명 매캐 변수를 포함한 전체 타입 시그너처는 &'static str이다.  

이 외에도 Rust에는 여러 다른 문자열 타입이 존재한다.  
* **char** : 4바이트로 인코딩된 단일 문자로, 내부 표현은 UCS-4/UTF-32와 동일하다.  
* **[u8]** : 대개 바이너리 데이터 스트림을 처리할 때 볼 수 있는 원시 바이트의 슬라이스다.  
* **Vec&lt;u8&gt;** : 원시 바이트의 벡터로, 일반적으로 [u8] 데이터를 소비할 때 생성된다. String은 Vec&lt;u8&gt;, str은 [u8]을 감싼 것이다.  
* **std::ffi::OsString** : 플랫폼 네이티브 문자열이다.  
* **std::path::Path** : 파일 시스템 경로를 처리하는 데 특화된 문자열과 비슷한 타입이다.

#### [ 배열, 슬라이스, 벡터 ]
배열은 동일한 타입의 요소를 가진 연속적인 메모리 블록이다.  
배열 내의 항목을 바꿀 수는 있지만 그 크기는 변경할 수 없다. 즉, 너비가 고정되어 있으며 매우 가볍다.  
배열의 크기는 타입 시스템에서 중요하다. (ex: [u8; 3]과 [u8; 4]는 다른 타입)  
배열의 범위를 벗어난 항목을 요청하면 잘못된 데이터를 반환하는 대신 프로그램이 종료된다. (Rust 용어로 패닉)

``` Rust
fn main() {
    let one             = [1, 2, 3];
    let two: [u8; 3]    = [1, 2, 3];
    let blank1          = [0; 3];
    let blank2: [u8; 3] = [0; 3];

    let arrays = [one, two, blank1, blank2];

    for a in &arrays {
        print!("{:?}: ", a);
        for n in a.iter() {
            print!("\t{} + 10 = {}", n, n + 10);
        }

        let mut sum = 0;
        for i in 0..a.len() {
            sum += a[i];
        }
        println!("\t(Σ{:?} = {})", a, sum);
    }
}
```
<br>

슬라이스는 동적인 크기를 가지는 배열과 비슷한 객체로, 배열과 마찬가지로 확장하거나 축소할 수 없다.  
컴파일 시 크기를 알 수 있는지 여부로 배열([T; n])과 슬라이스([T]) 간의 타입 시그너처 차이를 설명할 수 있다.  
슬라이스는 특정 크기에 묶이지 않아 배열에서 슬라이스를 생성하는 것이 쉽고 값싸다.  
슬라이스의 또 다른 중요한 용도는 배열(및 다른 슬라이스)의 뷰(view) 역할을 하는 것이다.  

벡터(Vec&lt;T&gt;)는 확장 가능한 T의 리스트로, Rust 코드에서는 벡터를 매우 흔하게 사용한다.  
크기 변경 시 추가적인 점검을 하기 때문에 배열에 비해 성능이 약간 떨어지지만 이러한 단점을 추가적인 유연성으로 만회한다.  
Vec&lt;T&gt;는 Vec::with_capacity()를 통해 크기에 대한 힌트를 줄 수 있을 때 가장 잘 작동한다.  
추정치를 제공함으로써 운영 체제가 메모리를 할당해야 하는 횟수를 최소화할 수 있다.

#### [ 서드 파티 코드 ]
Rust의 표준 라이브러리에는 난수 생성기나 정규식 지원 등 다른 언어가 제공하는 많은 기능이 빠져 있다.  
즉, 프로젝트에서 서드 파티 크레이트를 함께 쓰는 것이 일반적이다.  
크레이트는 Rust 커뮤니티에서 사용하는 용어로, 다른 언어에서는 이를 패키지, 배포본 또는 라이브러리라고 한다.  
서드 파티 코드를 사용하기 위해서는 다음과 같은 카고 명령행 도구를 사용한다.
1. **cargo install cargo-edit**  
2. **cargo add {크레이트}**  

Cargo.toml 파일을 통해 크레이트의 의존성이 포함되었는지 확인할 수 있다.  

rustup은 카고와 더불어 편리한 명령행 도구로, 카고로 프로젝트를 관리했다면 rustup으로는 러스트 설치를 관리한다.  
rustup은 러스트 툴체인을 관리하며 컴파일러의 여러 버전을 선택할 수 있다.  
여러 플랫폼용 프로젝트를 컴파일할 수 있고 안정 버전을 유지하면서 개발 중인 최신 버전의 컴파일러를 실험할 수도 있다.

#### [ 명령행 인자 자원 ]
정규식과 마찬가지로 명령행 인자 처리에 대한 Rust 자체 지원은 인색한 편이다.  
더 향상된 API는 clap이라는 서드 파티 크레이트를 통해 이용할 수 있다. (다른 방식도 있음)

``` Rust
use regex::Regex;
use clap::{App, Arg};

fn main() {
    let args = App::new("grep-lite").version("0.1").about("searches for patterns")
            .arg(Arg::with_name("pattern").help("The pattern to search for").takes_value(true).required(true))
            .get_matches();
    
    let pattern = args.value_of("pattern").unwrap();
    let re = Regex::new(pattern).unwrap();

    let quote = "Ever face, every shop, bedroom window, public-house, and
    dark square is a picture feverishly turned--in search of what?
    It is the same with books. What do we seek through millions of pages?";
    
    for line in quote.lines() {
        match re.find(line) {
            Some(_) => println!("{}", line),
            None => (),
        }
    }
}
```

#### [ 파일 읽기, 표준 입력 읽기 ]
파일 읽기의 일반적인 패턴은 File 객체를 연 다음 BufReader로 감싸는 것이다.  
BufReader는 버퍼링된 I/O를 제공하여 하드 디스크가 바쁠 경우 운영 체제에 대한 시스템 호출을 줄일 수 있다.  

완전한 명령행 유틸리티는 표준입력(stdin)을 읽을 수 있어야 한다.  
처리할 항목이 파일이든 표준 입력이든 상관없이 제네릭 함수를 사용해서 해당 기능을 추상화할 수 있다.

``` Rust
use std::fs::File;
use std::io;
use std::io::BufReader;
use std::io::prelude::*;
use regex::Regex;
use clap::{App, Arg};

fn process_lines<T: BufRead + Sized>(reader: T, re: Regex) {
    for line_ in reader.lines() {       // BufReader::lines()는 각 줄의 맨 뒤 개행 문제를 제거함
        let line = line_.unwrap();
        match re.fine(&line) {          // re.find()는 &str 타입을 인자로 받음
            Some(_) => println!("{}", line);
            None => (),
        }
    }
}

fn main() {
    let args = App::new("grep-lite").version("0.1").about("searches for patterns")
            .arg(Arg::with_name("pattern").help("The pattern to search for").takes_value(true).required(true))
            .arg(Arg::with_name("input").help("file to search").takes_value(true).required(true))
            .get_matches();
    
    let pattern = args.value_of("pattern").unwrap();
    let re = Regex::new(pattern).unwrap();

    let input = args.value_of("input").unwrap();
    
    if input == "-" {
        let stdin = io::stdin();
        let reader = stdin.lock();
        process_lines(reader, re);
    } else {
        let f = File::open(input).unwrap();
        let reader = BufReader::new(f);
        process_lines(reader, re);
    }
}
```

***
### 복합 데이터 타입 <a id="anchor3"></a>
