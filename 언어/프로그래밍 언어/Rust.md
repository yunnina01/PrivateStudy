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
3. [복합 데이터 타입](#anchor3)
4. [수명, 소유권, 대여](#anchor4)
5. [데이터 심화](#anchor5)

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
fn is_even(n: i32) -> bool {
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
            Some(_) => println!("{}", line),
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
#### [ 보통 함수를 이용한 API 실험 ]
``` Rust
#![allow(unused_variables)]                             // 컴파일러 경고 완화

type File = String;                                     // 타입 별칭 생성, 컴파일러는 구분하지 않음

fn open(f: &mut File) -> bool {
    true
}

fn close(f: &mut File) -> bool {
    true
}

#[allow(dead_code)]                                     // 사용하지 않는 함수에 대한 컴파일러 경고 완화
fn read(f: &mut File, save_to: &mut Vec<u8>) -> ! {     // ! 반환 타입은 함수가 어떤 값도 반환하지 않음을 컴파일러에 알려줌
    unimplemented!()                                    // 프로그램을 중단시키는 매크로
}

fn main() {
    let mut f1 = File::from("f1.txt");
    open(&mut f1);
    // read(f1, vec![]);
    close(&mut f1);
}
```

#### [ Rust의 특별한 반환 타입 ]
유닛 타입으로 알려진 ()는 길이가 0인 튜플로, 함수가 아무 값도 반환하지 않음을 표한하는 데 이용된다.  
반환 타입이 없는 함수나 세미콜론으로 끝나는 표현식은 ()를 반환한다.  
느낌표 기호(!)는 Never 타입으로, 함수가 실행 후 호출 위치로 절대 돌아가지 않음을 나타내며 특히 함수가 중단될 것을 보장한다.

#### [ struct ]
struct를 사용하면 다른 타입들로 구성된 복합 타입을 만들 수 있다.

``` Rust
#[derive(Debug)]                        // File이 println!과 fmt! 매크로와 함께 동작할 수 있게 함
struct File {
    name: String,
    data: Vec<u8>,
}

fn main() {
    let f1 = File {
        name: String::from("f1.txt"),
        data: Vec::new(),
    };

    let f1_name = &f1.name;
    let f1_length = &f1.data.len();

    println!("{:?}", f1);
    println!("{} is {} bytes long", f1_name, f1_length);
}
```

#### [ impl ]
Rust에서는 메서드를 정의하기 위해 impl 블록을 사용하는데 struct와 enum 블록과는 물리적으로 구분되어 있다.

``` Rust
#[derive(Debug)]
struct File {
    name: String,
    data: Vec<u8>,
}

impl File {
    fn new(name: &str) -> File {
        File {
            name: String::from(name),
            data: Vec::new(),
        }
    }
}

fn main() {
    let f1 = File::new("f1.txt");

    let f1_name = &f1.name;
    let f1_length = f1.data.len();

    println!("{:?}", f1);
    println!("{} is {} bytes long", f1_name, f1_length);
}
```

#### [ 오류 반환 ]
오류 발생을 알리는 가장 간단한 방법 중 하나는 전역 변수의 값을 확인하는 것이다.  
시스템 프로그래밍에서는 운영 체제에서 정의된 전역 변수와 상호 작용할 필요가 있어 흔한 관용적인 방식이다.  
불안정한 프로그램이 되는 등 잘못되기 쉬운 방식이라 일반적으로 권장하지 않는다.

``` Rust
static mut ERROR: i32 = 0;              // 전역 변수(또는 정적 가변)으로 정적 수명을 가져 프로그램 수명 동안 유효

// ...

fn main() {
    let mut f = File::new("something.txt");

    read(f, buffer);
    unsafe {                            // Rust가 안전성을 보장 못하는 비정상적인 작업(정적 가변 변수 접근) 수행을 한다는 지시
        if ERROR != 0 {
            panic!("An error has occurred while reading the file");
        }
    }

    close(f);
    unsafe {
        if ERROR != 0 {
            panic!("An error has occurred while closing the file");
        }
    }
}
```
<br>

오류 처리에 대한 Rust식 접근 방법은 일반적인 경우와 오류가 발생한 경우 둘 다 표현하는 Result 타입을 사용하는 것이다.  
Result는 Ok와 Err 두 가지 상태를 가지며, 다재다능하기 때문에 표준 라이브러리 전반에 걸쳐 사용된다.  
Result는 Rust의 표준 라이브러리에서 열거형으로 정의된다.

``` Rust
use rand::prelude::*;                                           // rand 크레이트에서 공통 트레이트와 타입을 가져옴

fn one_in(denominator: u32) -> bool {                           // 산발적인 오류를 일으키는 도움 함수
    thread_rng().gen_ratio(1, denominator)                      // thread_rng(): 스레드 로컬 난수 생성기 생성
}                                                               // get_ratio(n, m): n/m 확률을 가지는 불값 반환

#[derive(Debug)]
struct File {
    name: String,
    data: Vec<u8>,
}

impl File {
    fn new(name: &str) -> File {
        File {
            name: String::from(name),
            data: Vec::new(),
        }
    }

    fn new_with_data(name: &str, data: &Vec<u8>) -> File {
        let mut f = File::new(name);
        f.data = data.clone();
        f
    }

    fn read(self: &File, save_to: &mut Vec<u8>) -> Result<usize, String> {
        let mut tmp = self.data.clone();
        let read_length = tmp.len();
        save_to.reserve(read_length);                           // 저장 공간 확인
        save_to.append(&mut tmp);
        Ok(read_length)
    }
}

fn open(f: &mut File) -> Result<File, String> {
    if one_in(10_000) {
        let err_msg = String::from("Permission denied");
        return Err(err_msg);
    }
    Ok(f)
}

fn close(f: &mut File) -> Result<file, String> {
    if one_in(10_000) {
        let err_msg = String::from("Interrupted by signal!");
        return Err(err_msg);
    }
    Ok(f)
}

fn main() {
    let f1_data: Vec<u8> = vec![114, 117, 115, 116, 33];
    let mut f1 = File::new_with_data("1.txt", &f1_data);

    let mut buffer: Vec<u8> = vec![];

    f1 = open(f1).unwrap();                                     // Ok로부터 T를 풀어 T를 남김
    let f1_length = f1.read(&mut buffer).unwrap();              // unwrap(): 오류 타입에 호출하면 오류 메시지 없이 프로그램 중단
    f1 = close(f1).unwrap();

    let text = String::from_utf8_lossy(&buffer);                // Vec<u8>을 String으로 변환

    println!("{:?}", f1);
    println!("{} is {} bytes long", &f1.name, f1.length);
    println!("{}", text);
}
```

Result를 이용하면 컴파일러가 지원하는 코드 정확성을 얻는다.  
프로그램은 오류 발생 시 중단되겠지만 최소한 프로그램을 명시적으로 만들었다.

#### [ 열거형 ]
열거형은 다수의 알려진 열것값을 표현할 수 있는 타입이다.  
열거형은 Rust의 패턴 일치 기능과 함께 사용하면 탄탄하고 읽기 쉬운 코드를 만드는 데 도움이 된다.  
Rust의 열거형은 구조체처럼 imple 블록을 통해 메서드를 정의할 수 있으며, 일반적인 상수 집합보다 더 강력하다.  
열거형은 열것값에 데이터를 포함시켜 구조체 같은 성격을 띄게 하는 것도 가능하다.

``` Rust
#[derive(Debug)]                                                // 자동 생성 코드를 통해 열거형 출력
enum Event {
    Update,
    Delete,
    Unknown,
}

type Message = String;

fn parse_log(line: &'static str) -> (Event, Message) {
    let parts: Vec<&str> = line.splitn(2, ' ').collect();       // collect(): line.splitn()로 생성된 반복자를 써서 Vec<T> 반환
    if parts.len() == 1 {                                       // 두 부분으로 나누지 못한 경우
        return (Event::Unknown, String::from(line))
    }

    let event = parts[0];
    let rest = String::from(parts[1]);

    match event {
        "UPDATE" | "update" => (Event::Update, rest),
        "DELETE" | "delete" => (Event::Delete, rest),
        _ => (Event::Unknown, String::from(line)),
    }
}

fn main() {
    let log = "BEGIN Transaction XK342
    UPDATE 234:LS/32231 {\"price\": 31.00} -> {\"price\": 40.00}
    DELETE 342:L0/22111";

    for line in log.lines() {
        let parse_result = parse_log(line);
        println!("{:?}", parse_result);
    }
}
```

#### [ 트레이트로 공통 동작 정의 ]
트레이트는 다양한 타입이 동일한 작업을 수행하려고 한다는 것을 컴파일러에게 알려준다.  
다수의 타입에 트레이트를 구현할 수 있도록 허용함으로써 코드 재사용과 무비용 추상화를 할 수 있다.  
트레이트는 Rust의 제네릭 시스템과 견고한 타입 검사의 기초가 된다.  
약간 오용한다면 객체 지향 언어에서 흔한 상속 형태도 지원할 수 있다.

``` Rust
#[!allow(unused_variables)]

#[derive(Debug)]
struct File;

trait Read {
    fn read(self: &Self, save_to: &mut Vec<u8>) -> Result<usize, String>;
}

impl Read for File {
    fn read(self: &File, save_to: &mut Vec<u8>) -> Result<usize, String> {
        Ok(0)
    }
}

fn main() {
    let f = File{};
    let mut buffer = vec!();
    let n_bytes = f.read(&mut buffer).unwrap();
    println!("{} byte(s) read from {:?}", n_bytes, f);
}
```
<br>

println!, print!, writeln!, write!, format!은 모두 Display와 Debug 트레이트에 의존하며,  
이 트레이트들은 {}를 콘솔에 어떻게 출력할지 프로그래머가 제공한 트레이트 구현에 의존한다.  
Debug 트레이트의 자동 구현을 이용하는 것이 기본적으로 가능하지만, 다른 출력을 얻고자 한다면 별도의 구현이 필요하다.  
Display는 fmt() 메서드가 구현된 타입에 쓸 수 있으며, 해당 메서드는 fmt::Result를 반환해야 한다.

``` Rust
#![allow(dead_code)]

use std::fmt;
use std::fmt::{Display};

#[derive(Debug, PartialEq)]
enum FileState {
    Open,
    Closed,
}

#[derive(Debug)]
struct File {
    name: String,
    data: Vec<u8>,
    state: FileState,
}

impl Display for FileState {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        match *self {
            FileState::Open => write!(f, "OPEN"),
            FileState::Closed => write!(f, "CLOSED"),
        }
    }
}

impl Display for File {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        write!(f, "<{} ({})>", self.name, self.state)           // self.state에 대해서는 FileState의 Display 구현에 의존
    }
}

impl File {
    fn new(name: &str) -> File {
        File {
            name: String::from(name),
            data: Vec::new(),
            state: FileState::Closed,
        }
    }
}

fn main() {
    let f1 = File::new("f1.txt");
    // ...
    println!("{:?}", f1);                                       // File { ... }
    println!("{}", f1);                                         // <f1.txt (CLOSED)>
}
```

#### [ 타입 공개 ]
Rust는 기본적으로 모든 것을 비공개로 간주한다.  
pub 키워드를 사용해서 필요한 것들을 공개할 수 있다.

``` Rust
#[derive(Debug, PartialEq)]
pub enum FileState {                        // 타입을 공개하면 그 안의 열것값들도 모두 공개됨
    Open,
    Closed,
}

#[derive(Debug)]
pub struct File {
    pub name: String,
    data: Vec<u8>,
    pub state: FileState,
}

impl File {
    pub fn new(name: &str) -> File {        // 구조체가 공개되었더라도 메서드의 공개 여부는 명시적으로 지정해 주어야 함
        File {
            name: String::from(name),
            data: Vec::new(),
            state: FileState::Closed,
        }
    }
}

fn main() {
    let f1 = File::new("f1.txt");
    // ...
    println!("{:?}", f1);
}
```

#### [ 인라인 문서 만들기 ]
코드에 문서 주석을 추가하는 방법에는 2가지 방식이 있다.  
///는 일반적인 형태로, 바로 이어지는 항목을 참조하는 문서를 생성한다.  
//!는 컴파일러가 코드 전체를 훑을 때 현재 항목을 참조하며, 관례적으로 현재 모듈에 대한 주석에 사용되지만 다른 곳에도 사용 가능하다.

``` Rust
//! 한 번에 한 단계씩 파일을 시뮬레이트한다.

/// 아마도 파일 시스템에 있을
/// '파일'을 나타낸다.
#[derive(Debug)]
pub struct File {
    name: String,
    data: Vec<u8>,
}

impl File {
    /// 새 파일은 비어 있다고 가정하지만 이름은 필요하다.
    pub fn new(name: &str) -> File {
        File {
            name: String::from(name),
            data: Vec::new(),
        }
    }

    /// 파일 길이를 바이트로 반환한다.
    pub fn len(&self) -> usize {
        self.data.len()
    }

    /// 파일 이름을 반환한다.
    pub fn name(&self) -> String {
        self.name.clone()
    }
}

fn main () {
    let f1 = File::new("f1.txt");

    let f1_name = f1.name();
    let f1_length = f1.len();

    println!("{:?}", f1);
    println!("{} is {} bytes long", f1_name, f1_length);
}
```
<br>

* **rustdoc으로 한 소스 파일의 문서 만들기** : rustdoc {file.rs}  
* **카고로 크레이트와 의존성에 대한 문서 만들기** : cargo doc

※ cargo doc --open을 실행하면 웹 브라우저가 자동으로 열린다.  
※ cargo doc --no-deps를 실행하면 의존성 패키지는 무시하기 때문에 rustdoc이 해야 할 작업을 상당히 제한할 수 있다.

***
### 수명, 소유권, 대여 <a id="anchor4"></a>
값의 수명은 값에 접근해도 문제 없는 기간을 의미한다.  
함수의 지역 변수는 함수 실행을 마칠 때까지, 전역 변수는 프로그램이 가동되는 동안 살아 있다.  

Rust에서 소유권은 해당 값이 더 이상 필요 없을 때 깨끗이 지우는 것과 관련이 있다.  
단, 소유자는 프로그램의 다른 부분이 값에 접근하는 것을 막거나 데이터 도난을 보고할 수 없다.  

값을 대여한다는 것은 값에 접근함을 의미한다.  
대여의 의미는 값에는 소유자가 하나뿐이며, 프로그램의 많은 부분에서 공동 접근이 가능하다는 점을 강조하기 위해 사용한다.

#### [ 소유권 이동 ]
Rust 코드에서 이동은 데이터 이동이 아니라 소유권 이동을 말한다.  
소유권은 컴파일 시 모든 값의 사용이 유효한지 그리고 모든 값이 깨끗하게 파괴되는지 검사하는 과정을 말한다.  

``` Rust
// 이 코드를 컴파일하면 오류가 발생한다.
fn main() {
    let sat_a = CubeSat { id: 0 };          // sat_a의 소유권은 main()에 있음
    
    let a_status = check_status(sat_a);     // check_status() 함수의 sat_id 매개변수로 소유권 이동
    // ...                                  // sat_a의 소유권이 main()으로 돌아오지 않음
    let a_status = check_status(sat_a);     // 접근 무효
}
```

#### [ 원시 타입의 특수한 행위 ]
Rust의 원시 타입은 Copy 트레이트를 구현해 놓았다.  
Copy를 구현한 타입은 복제하지 않고서는 사용할 수 없을 때에 한해 복제된다.  
공식적으로 원시 타입은 '복사 의미'를 가지고, 다른 타입들은 '이동 의미'를 가진다.

``` Rust
fn use_value(_val: i32) {
}

fn main() {
    let a = 123;
    use_value(a);           // a가 복사되어 use_value()의 _val로 소유권이 넘어감
    println!("{}", a);
}
```

#### [ 소유자 ]
소유자는 값의 수명이 끝나면 값을 정리한다.  
값이 범위를 넘어가거나 다른 어떤 이유로 수명이 끝난다면 파괴자가 호출된다.  
파괴자는 값에 대한 참조를 지우고 메모리를 해제함으로써 프로그램으로부터 값의 흔적을 지우는 함수다.  
컴파일러가 모든 값의 수명을 추적하는 과정의 일부로 파괴자를 호출하는 코드를 삽입한다.  

타입에 커스텀 파괴자를 넣으려면 Drop을 구현해야 한다.  
이는 일반적으로 메모리를 할당하기 위해 unsafe 블록을 사용하는 곳에서 필요로 한다.  
Drop은 하나의 메서드 drop(&mut self)를 가지며, 필요한 정리 활동을 하는 데 이용한다.  

값은 절대로 소유자보다 오래 지속될 수 없으며, 값의 소유자는 자신의 데이터에 특별한 접근 권한을 가지고 있지 않다.  
또한, 다른 곳에서 불법적으로 점유하는 것을 제한할 능력도 없다.  
소유자는 자신의 값을 대여하는 코드의 다른 부분에 대해 아무것도 하지 못한다.

#### [ 소유권 이동 방식 ]
Rust 프로그램 안에서 소유권을 다른 변수로 옮기려면 할당이나 함수 인자나 반환값으로 전달하는 방법을 사용한다.

``` Rust
fn check_status(sat_id: CubeSat) -> CubeSat {
    println!("{:?}: {:?}" sat_id, StatusMessage::Ok);
    sat_id
}

fn main() {
    let sat_a = CubeSat { id: 0 };      // 변수 바인딩(할당)
    let sat_a = check_status(sat_a);    // 새로운 let 바인딩으로 초기화
    // ...
    let sat_a = check_status(sat_a);
}
```

#### [ 소유권 문제 해결 ]
**1. 완전한 소유권이 필요하지 않을 때 참조를 사용**  
필요한 접근 수준을 낮추는 방식으로 소유권을 요청하는 대신 함수 정의에 '대여'를 이용할 수 있다.  
읽기 전용 접근은 &T, 읽기-쓰기 접근은 &mut T를 사용한다.

``` Rust
fn send(to: &mut CubeSat, msg: Message) {
    to.mailbox.messages.push(msg);
}
```

**2. 오래 지속되는 값은 더 적게 사용**  
오래 지속되는 객체가 포함된 접근 방식을 사용하는 대신 더 분리되고 일시적인 객체를 만드는 것이 좋다.

``` Rust
#![allow(unused_variables)]

#[derive(Debug)]
struct CubeSat {
    id: u64,
}

#[derive(Debug)]
struct Mailbox {
    messages: Vec<Message>,
}

#[derive(Debug)]
struct Message {
    to: u64,
    content: String,
}

struct GroundStation {}

impl Mailbox {
    fn post(&mut self, msg: Message) {
        self.messages.push(msg);
    }

    fn deliver(&mut self, recipient: &CubeSat) -> Option<Message> {
        for i in 0..self.messages.len() {
            if self.messages[i].to == recipient.id {
                let msg = self.messages.remove(i);      // 반복이 이루어지는 동안 컬렉션 변경
                return Some(msg);                       // 바로 다음 줄의 return으로 인해 적법하다고 인정됨
            }
        }
        None
    }
}

impl GroundStation {
    fn connect(&self, sat_id: u64) -> CubeSate {
        CubeSat {
            id: sat_id,
        }
    }

    fn send(&self, mailbox: &mut Mailbox, msg: Message) {
        mailbox.post(msg);
    }
}

impl CubeSat {
    fn recv(&self, mailbox: &mut Mailbox) -> Option<Message> {
        mailbox.deliver(&self)
    }
}

fn fetch_sat_ids() -> Vec<u64> {
    vec![1, 2, 3]
}

fn main() {
    let mut mail = Mailbox { messages: vec![] };
    let base = GroundStation {};
    let sat_ids = fetch_sat_ids();

    for sat_id in sat_ids {
        let sat = base.connect(sat_id);
        let msg = Message { to: sat_id, content: String::from("hello") };
        base.send(&mut mail, msg)
    }

    let sat_ids = fetch_sat_ids();

    for sat_id in sat_ids {
        let sat = base.connect(sat_id);
        let msg = sat.recv(&mut mail);
        println!("{:?}: {:?}", sat, msg);
    }
}
```

**3. 값의 사본 만들기**  
복제(deep copy에 준하는 전체 구조와 값의 복제)와 복사(shallow copy에 준하는 최소한의 복사)를 통해 사본을 만들 수 있다.

| 복제 | 복사 |
| --- | --- |
| std::clone::Clone에 의해 정의 | std::marker::Copy에 의해 정의 |
| 느리고 비쌀 수 있음 | 언제나 빠르고 쌈 |
| 항상 명시적, .clone() 메서드 호출이 언제나 필요 | 항상 암묵적 |
| 원래 값과 달라질 수 있음 | 원래 값을 비트 대 비트로 사본을 만드므로 언제나 동일 |
<br>

Rust 프로그래머가 항상 Copy만 쓰지 않는 이유  
  * Copy 트레이트는 성능에 미치는 영향이 미미해야 함을 암시한다.  
  이는 숫자 같은 경우에는 해당되지만 String 같은 임의의 큰 타입에는 해당되지 않는다.

  * Copy는 동일한 복사본을 만들기 때문에 참조를 제대로 다룰 수 없다.  
  T에 대한 참조를 복사하면 T의 두 번째 소유자를 만들어 내거나 만들려고 한다.  
  참조가 삭제될 때마다 T를 삭제하려고 시도할 수 있어 문제를 일으킬 수 있다.

  * 어떤 타입은 Clone 트레이트를 오버로드한다.  
  예를 들어 std::rc::Rc&lt;T&gt;는 .clone()이 호출될 대 추가적인 참조를 만드는 목적으로 Clone을 이용한다.
<br>

``` Rust
// #[derive(Debug, Clone, Copy)]
struct CubeSat {
    id: u64,
}

// #[derive(Debug, Clone, Copy)]
enum StatusMessage {
    Ok,
}

// Copy, Clone 트레이트 수동 구현
impl Copy for CubeSat { }

impl Copy for status StatusMessage { }

impl Clone for CubeSat {
    fn clone(&self) -> Self {
        CubeSat { id: self.id }                         // 새로운 객체 직접 생성
    }
}

impl Clone for StatusMessage {
    fn clone(&self) -> Self {
        *self                                           // self 역참조
    }
}

fn check_status

fn main() {
    let sat_a = CubeSat { id : 0 };
    let a_status = check_status(sat_a.clone());         // 복제
    println!("a: {:?}", a_status.clone());

    let a_status = check_status(sat_a);                 // 복사
    println!("a: {:?}", a_status);
}
```

**4. 데이터를 특별한 타입으로 감싸기**  
래퍼(wrapper) 타입은 기본적으로 가능한 것보다 더 많은 유연성을 제공하지만, 안전성 보장을 위한 런타임 비용이 발생한다.  
std::rc::Rc는 일반적으로 타입 매개 변수 T를 받고 Rc&lt;T&gt;로 표기된다.  
Rc&lt;T&gt;는 '타입 T의 참조 카운트값'을 의미하며, T의 공유 소유권을 제공한다.  
공유 소유권은 모든 소유자가 삭제되기 전까지 T가 메모리에서 삭제되는 것을 막는다.  
참조 생성 시(Clone) 내부 카운트가 1 늘어나고 참조가 사라지면(Drop) 1 줄어들며, 카운트가 0으로 떨어지면 T도 없어진다.  

Rc&lt;T&gt;는 변경을 허용하지 않으므로 변경을 위해서는 래퍼로 감싸야 한다.  
Rc&lt;RefCell&lt;T&gt;&gt;는 내부 변경을 수행하는 데 사용할 수 있는 타입이다.  
내부 변경이 가능한 객체는 겉으로는 불변이지만 내부 값은 바뀔 수 있다.  
Rc&lt;RefCell&lt;T&gt;&gt;는 T에 대한 공유 읽기-쓰기 접근을 허용하면서 Rc&lt;T&gt;에 비해 런타임 비용이 추가 발생한다.  

다른 타입으로 감싸서 더 많은 기능을 타입에 추가하면 일반적으로 런타임 성능이 떨어진다.  
Clone 구현이 금지해야 할 정도로 비싸다면 Rc&lt;T&gt;는 간편한 대안이다. (모두 공유 소유권 허용)

``` Rust
use std::rc::Rc;
use std::cell::RefCell;

#[derive(Debug)]
struct GroundStation {
    radio_freq: f64,
}

fn main() {
    let base: Rc<RefCell<GroundStation>> = Rc::new(RefCell::new(GroundStation {
        radio_freq: 87.65
    }));
    println!("base: {:?}", base);

    {
        let mut base_2 = base.borrow_mut();
        base_2.radio_freq -= 12.34;
        println!("base_2: {:?}", base_2);
    }
    println!("base: {:?}", base);

    let mut base_3 = base.borrow_mut();
    base_3.radio_freq += 43.21;
    println!("base: {:?}", base);
    println!("base_3: {:?}", base_3);
}
```
<br>

※ 다중 스레드 코드에서는 Rc&lt;T&gt;를 Arc&lt;T&gt;로, Rc&lt;RefCell&lt;T&gt;&gt;를 Arc&lt;Mutex&lt;T&gt;&gt;로 대체하는 것이 낫다.  
※ arc는 원자적 참조 카운터를 의미한다.

***
### 데이터 심화 <a id="anchor5"></a>
