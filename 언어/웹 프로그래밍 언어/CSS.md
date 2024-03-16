# CSS (CSS3)

### CSS란?
Cascading Style Sheet의 약어로, 마크업 언어가 실제로 표시되는 방법을 기술하는 스타일 언어이다.  
HTML과 XHTML에 주로 사용되며, XML에서도 사용가능하다.  
텍스트의 색상이나 크기, 이미지 크기나 위치, 표의 색상, 배치 방법 등 웹 문서의 디자인 요소를 담당한다.
<br>

***
### 목차
1. [스타일 정보 위치](#anchor1)
2. [스타일 우선순위](#anchor2)
3. [선택자](#anchor3)
4. [속성 선택자](#anchor4)
5. [가상 클래스](#anchor5)
6. [글꼴 관련 스타일](#anchor6)
7. [텍스트 스타일](#anchor7)
8. [목록 스타일](#anchor8)
9. [색상 관련 스타일](#anchor9)
10. [배경 관련 스타일](#anchor10)
11. [레이아웃 관련 스타일](#anchor11)
12. 

***
### 스타일 정보 위치 <a id="anchor1"></a>
``` HTML, CSS
<!doctype html>
<html>
    <head>
        <meta charset="utf-8">
        <title>CSS 위치</title>
        <style>                                                                    /* 내부 스타일 시트 */
            p {
                color:blue;
            }
        </style>
        <link href="외부 스타일 파일 경로" rel="stylesheet" type="text/css">        <!-- 외부 스타일 시트 -->
</html>
```

***
### 스타일의 우선순위 <a id="anchor2"></a>
* **스타일 상속**  
부모 요소로부터 자식 요소로 단계별로 스타일이 적용되기 때문에,  
'계단식'이라는 의미를 가진 '캐스케이딩(cascading)'이라는 단어가 '스타일시트'를 수식하는 말로 붙게 되었다.  
주의할 점은, 스타일의 모든 속성이 부모 요소에서 자식 요소로 상속되는 것은 아니다.

* **스타일의 우선순위**  
하나의 요소에 여러 스타일 규칙이 정의되어 있다면 가장 나중에 정의된 스타일을 적용한다.  
스타일 규칙에 '**!important**'를 추가하면 해당 스타일 규칙이 가장 높은 우선순위를 갖게 된다.

***
### 선택자 <a id="anchor3"></a>
| 선택자 | 설명 | 기본형 | 비고 |
| :---: | --- | --- | --- |
| **전체 선택자** | 모든 요소에 스타일 적용 | * { 속성:속성 값; ··· } |
| **태그 선택자** | 특정 태그에 스타일 적용 | 태그 { 속성:속성 값; ··· } |
| **클래스 선택자** | 특정 부분에 스타일 적용 | .클래스 이름 { 속성:속성 값; ··· } | class 속성을 이용해 적용 |
| **id 선택자** | 특정 부분에 스타일 적용 | #id 이름 { 속성:속성 값; ··· } | id 속성을 이용해 적용 |
| **하위 선택자** | 모든 하위 요소에 스타일 적용 | 상위 요소 &nbsp;&nbsp;&nbsp; 하위 요소 { 속성:속성 값; ··· } |
| **자식 선택자** | 자식 요소에만 스타일 적용 | 부모 요소 > 자식 요소 { 속성:속성 값; ··· } |
| **인접 형제 선택자** | 첫 동생 요소에 스타일 적용 | 요소1 + 요소2 { 속성:속성 값; ··· } |
| **형제 선택자** | 형제 요소에 스타일 적용 | 요소1 ~ 요소2 { 속성:속성 값; ··· } |
| **그룹 선택자** | 스타일 한꺼번에 정의 | 요소1, 요소2, ··· { 속성:속성 값; ··· } |

***
### 속성 선택자 <a id="anchor4"></a>
| 형식 | 설명 | 기본형 |
| :---: | --- | --- |
| **[속성]** | 지정한 속성을 가지고 있는 요소에 스타일 적용 | [속성] { 속성:속성 값; ··· } |
| **[속성 = 값]** | 주어진 속성과 값이 일치하는 요소에 스타일 적용 | [속성 = 값] { 속성:속성 값; ··· } |
| **[속성 ~= 값]** | 비교할 값 중 하나만 일치해도 스타일 적용 | [속성 ~= 값] { 속성:속성 값; ··· } |
| **[속성 ^= 값]** | 지정한 문자로 시작하는 속성 값에만 스타일 적용 | [속성 ^= 값] { 속성:속성 값; ··· } |
| **[속성 $= 값]** | 지정한 문자로 끝나는 속성에만 스타일 적용 | [속성 $= 값] { 속성:속성 값; ··· } |
| **[속성 &#124;= 값]** | 속성이 지정한 값으로 시작하면 스타일 적용 | [속성 &#124;= 값] { 속성:속성 값; ··· } |
| **[속성 &#42;= 값]** | 사용자가 지정한 속성 값이 포함되어 있으면 스타일 적용 | [속성 *= 값] { 속성:속성 값; ··· } |

***
### 가상 클래스 <a id="anchor5"></a>
| 선택자 | 설명 | 기본형 |
| :---: | --- | --- |
| **:link** | 방문하지 않은 링크에 스타일 적용 | a:link { 속성:속성 값; ··· } |
| **:visited** | 한 번 이상 방문한 링크에 스타일 적용 | a:visited { 속성:속성 값; ··· } |
| **:active** | 링크를 클릭했을 때의 스타일 적용 | a:active { 속성:속성 값; ··· } |
| **:hover** | 요소 위로 마우스 포인터를 올렸을 때 스타일 적용 | 태그:hover { 속성:속성 값; ··· } |
| **:focus** | 요소에 초점이 맞춰졌을 때 스타일 적용 | 태그:focus { 속성:속성 값; ··· } |
| **:root** | 문서 안의 루트 요소에 스타일 적용 |
| **:nth-child(n)** | n번째 자식 요소에 스타일 적용 | 요소 자식:nth-child(n) |
| **:nth-last-child(n)** | 뒤에서 n번째 자식 요소에 스타일 적용 | 요소 자식:nth-lask-child(n) |
| **:nth-of-type(n)** | n번째 나타나는 요소에 스타일 적용 |
| **:nth-last-of-type(n)** | 뒤에서 n번째 나타나는 요소에 스타일 적용 |
| **:first-child** | 첫 번째 자식 요소에 스타일 적용 |
| **:last-child** | 마지막 자식 요소에 스타일 적용 |
| **:first-of-type** | 형제 관계 중 첫 번째 요소에 스타일 적용 | 태그:first-of-type { 속성:속성 값; ··· } |
| **:last-of-type** | 형제 관계 중 마지막 요소에 스타일 적용 | 태그:last-of-type { 속성:속성 값; ··· } |
| **:only-child** | 부모 요소 안의 자식 요소가 하나일 때 스타일 적용 |
| **:only-of-type** | 해당 요소가 유일한 요소일 때 스타일 적용 |
| **:target** | 앵커의 목적지가 되는 부분의 스타일 지정 | #앵커:target { 속성:속성 값; ··· } |
| **:enabled** | 요소를 사용할 수 있는 상태로 지정 | 태그:enabled { 속성:속성 값; ··· } |
| **:disabled** | 요소를 사용할 수 없는 상태로 지정 | 태그:disabled { 속성:속성 값; ··· } |
| **:checked** | 라디오 버튼이나 체크박스가 선택되었을 때 스타일 적용 | 태그:checked { 속성:속성 값; ··· } |
| **::before** | 요소의 내용 앞에 스타일 적용 | 태그::before { 속성:속성 값; ··· } |
| **::after** | 요소의 뒤에 스타일 적용 | 태그::after { 속성:속성 값; ··· } |
| **::selection** | 커서가 드래그되어 선택되는 영역의 스타일 지정 | ::selection { 속성:속성 값; ··· } |
| **:not** | 괄호 안의 요소를 제외한 모든 부분에 스타일 적용 | :not(태그) { 속성:속성 값; ··· } |

***
### 글꼴 관련 스타일 <a id="anchor6"></a>
| 속성 | 설명 | 기본형 |
| :---: | --- | --- |
| **font-family** | 글꼴 지정 | font-family:"글꼴 이름", ["글꼴 이름", "글꼴 이름" ··· ] |
| **@font-face** | 웹 폰트 사용 | @font-face { font-family:글꼴 이름; src:url(글꼴 파일 경로) format(파일 유형); } |
| **font-size** | 글자 크기 조절 | font-size:속성 값; |
| **font-style** | 이탤릭체로 표현 | font-style:속성 값; |
| **font-variant** | 작은 대문자로 표시 | font-variant:속성 값; |
| **font-weight** | 글자 굵기 지정 | font-weight:속성 값; |
| **font** | 글꼴 속성 한꺼번에 묶어서 표현 | 태그 {font:font-size/line-height font-family font-variant ··· } |

***
### 텍스트 스타일 <a id="anchor7"></a>
| 속성 | 설명 | 기본형 |
| :---: | --- | --- |
| **direction** | 텍스트의 쓰기 방향 지정 | direction:속성 값; |
| **text-align** | 텍스트 정렬 | text-align:속성 값; |
| **text-shadow** | 텍스트에 그림자 효과 추가 | text-shadow:h-shadow 값 | v-shadow 값 | blur 값 | color 값; |
| **text-overflow** | 넘치는 텍스트 표기 | text-overflow:속성 값; |
| **text-decoration** | 텍스트에 줄 표시 | text-decoration:속성 값; |
| **text-indent** | 텍스트 들여쓰기 | text-indent:속성 값; |
| **text-transform** | 텍스트 대 · 소문자 변환 | text-transform:속성 값; |
| **letter-spacing** | 텍스트(낱글자) 간격 조절 | letter-spacing:속성 값; |
| **word-spacing** | 텍스트(단어) 간격 조절 | word-spacing:속성 값; |
| **ling-height** | 줄간격 조절 | line-height:속성 값; |
| **white-space** | 공백 처리 방법 지정 | white-space:속성 값; |

***
### 목록 스타일 <a id="anchor8"></a>
| 속성 | 설명 | 기본형 |
| :---: | --- | --- |
| **list-style-type** | 목록의 불릿과 번호 스타일 지정 | list-style-type:속성 값; |
| **list-style-position** | 목록에 들여쓰는 효과 내기 | list-style-position:속성 값; |
| **list-style-image** | 불릿 대신 이미지 넣기 | list-style-images:url(이미지 파일 경로); |
| **list-style** | 리스트 속성 한꺼번에 표시 | list-style:list-style-type list-style-position list-style-image; |

***
### 색상 관련 스타일 <a id="anchor9"></a>
| 속성 | 설명 | 기본형 | 비고 |
| :---: | --- | --- | --- |
| **color** | 글자색 바꾸기 | color:색상 값; | 16진수 / rgb / hsl / 색상 이름 표기법 |
| **rgba** | 투명도 조절 | rgba(red 값, green 값, blue 값, alpha 값); |
| **hsla** | 투명도 조절 | hsla(hue 값, saturation 값, lightness 값, alpha 값); |

***
### 배경 관련 스타일 <a id="anchor10"></a>
| 속성 | 설명 | 기본형 | 비고 |
| :---: | --- | --- | --- |
| **background-color** | 배경색 지정 | background-color:색상 값; |
| **background-image** | 웹 요소에 이미지 삽입 | background-image:url(파일 경로); |
| **background-repeat** | 배경 이미지 반복 | background-repeat:속성 값; | repeat, repeat-x, repeat-y, no-repeat |
| **background-position** | 배경 이미지 위치 조절 | background-position:가로 세로; | 위치, 길이, 키워드 |
| **background-attachment** | 배경 이미지 고정 | background-attachment:fixed or scroll; |
| **background** | 배경 속성 한꺼번에 지정 | background:image repeat position attachment |
| **background-size** | 배경 이미지 크기 조절 | background-size:속성 값; | auto, 크기 값, 백분율, cover, contain |
| **background-clip** | 배경 적용 범위 조절 | background-clip:속성 값; | border-box, padding-box, content-box |
| **background-origin** | 배경 이미지 위치 기준 조절 | background-origin:속성 값; | border-box, padding-box, content-box |
| **linear-gradient** | 선형 그라데이션 | linear-gradient(각도 or 위치, color-stop, [color-stop ··· ] ) |
| **radial-gradient** | 원형 그라데이션 | radial-gradient(위치, 모양 color-stop, [color-stop ··· ]) |


***
### 레이아웃 관련 스타일 <a id="anchor11"></a>
| 속성 | 설명 | 기본형 |
| :---: | --- | --- |
| **** |  |  |
| **** |  |  |
| **** |  |  |
| **** |  |  |
| **** |  |  |
| **** |  |  |
| **** |  |  |
| **** |  |  |
| **** |  |  |
| **** |  |  |
