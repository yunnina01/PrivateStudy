# HTML (HTML5)

### HTML이란?
Hypertext Markup Language의 약어로, 웹사이트의 모습을 기술하기 위한 마크업 언어이다.  
프로그래밍 언어가 아니라 마크업 정보를 표현하는 마크업 언어로, 문서의 내용 이외의 문서의 구조나 서식 같은 것을 포함한다.  
웹사이트에서 흔히 볼 수 있는 htm이나 html 확장자가 바로 이 언어로 작성된 문서이다.
<br>

***
### 목차
1. [특수 기호](#anchor1)
2. [HTML 구조](#anchor2)
3. [HTML5 시맨틱 태그](#anchor3)
4. [블록 레벨 태그](#anchor4)
5. [인라인 태그](#anchor5)
6. [목록 관련 태그](#anchor6)
7. [표 관련 태그](#anchor7)
8. [하이퍼링크 태그](#anchor8)
9. [이미지 관련 태그](#anchor9)
10. [멀티미디어 관련 태그](#anchor10)
11. [폼 관련 태그](#anchor11)

***
### 특수 기호 <a id="anchor1"></a>
<img src="https://github.com/yunnina01/PrivateStudy/assets/100751725/52e5ed5f-e217-44df-9517-5b0700b69a2f" width="800"/><br>

※ [HTML 특수문자 리스트](http://kor.pe.kr/util/4/charmap2.htm)

***
### HTML 구조 <a id="anchor2"></a>
``` HTML
<!doctype html>                       <!-- 문서 유형을 HTML5로 선언 -->
<html>                                <!-- 문서의 시작과 끝을 표시 -->
    <head>                            <!-- 웹 브라우저가 알아두어야 할 정보 입력 / 외부 파일 링크 -->
        <meta charset="utf=8">        <!-- 문자 인코딩 지정 -->
        <title>HTML 구조</title>      <!-- 문서 제목 -->
    </head>
    <body>                            <!-- 웹 브라우저에 표시될 내용 입력 -->
        <p>HTML</p>
    </body>
</html>
```

***
### HTML5 시맨틱 태그 <a id="anchor3"></a>
| 태그 | 설명 |
| :---: | --- |
| **header** | 머리말(제목) 지정 |
| **nav** | 문서를 연결하는 내비게이션 링크 |
| **hn** | 제목 표시 |
| **hgroup** | 제목과 부제목 묶어주기 |
| **section** | 콘텐츠 영역 나타내기 |
| **article** | 실제 콘텐츠 내용 넣기 |
| **aside** | 본문 이외의 내용 표시하기 |
| **footer** | 제작 정보와 저작권 정보 표시하기 |
| **address** | 사이트 제작자 정보, 연락처 정보 나타내기 |
| **div** | 콘텐츠를 묶어 시각적 효과(CSS) 적용 |

***
### 블록 레벨 태그 (텍스트를 묶어서 처리하는 태그) <a id="anchor4"></a>
| 태그 | 설명 | 속성 |
| :---: | --- | --- |
| **p** | 단락 생성 |
| **blockquote** | 인용문 넣기 | cite |
| **pre** | 입력하는 그대로 화면에 표시하기 |

***
### 인라인 태그 <a id="anchor5"></a>
| 태그 | 설명 | 속성 |
| :---: | --- | --- |
| **mark** | 형광펜 효과 내기 | background-color(CSS) |
| **time** | 날짜 또는 시간 정보 표시하기 | datetime |
| **strong** | 중요한 내용을 굵게 표시해 강조하기 |
| **em** | 중요한 내용을 기울여 표시해 강조하기 |
| **b** | 굵게 표시하기 |
| **i** | 이탤릭체로 표시하기 |
| **q** | 인용한 내용 표시하기 | cite |
| **ruby** | 일본어 발음 표시하기 |
| **span** | 줄바꿈 없이 영역 묶기 | style |
| **s** | 취소선 표시하기 |

***
### 목록 관련 태그 <a id="anchor6"></a>
| 태그 | 설명 | 속성 |
| :---: | --- | --- |
| **ul** | 순서 없는 목록 | list-style-type(CSS) |
| **ol** | 순서 있는 목록 | type, start, reversed |
| **li** | 목록의 항목 표시 |
| **dl** | 정의 목록 생성 (사전식 구성) |
| **dt** | 정의 목록의 제목 표시 |
| **dl** | 정의 목록의 설명 표시 |

***
### 표 관련 태그 <a id="anchor7"></a>
| 태그 | 설명 | 속성 |
| :---: | --- | --- |
| **table** | 표 생성 | summary |
| **caption** | 표에 간단한 제목 표시 |
| **tr** | 행 추가 |
| **td** | 셀 추가 | colspan, rowspan |
| **th** | 제목이 들어간 셀 추가 | colspan, rowspan |
| **col** | 여러 줄에 걸쳐 있는 열 하나 지정 | style |
| **colgroup** | 여러 개의 col 요소를 하나의 그룹화 | span, style |
| **thead** | 여러 열을 하나의 그룹으로 묶어 표의 헤더 지정 |
| **tbody** | 여러 열을 묶어 표의 본문으로 지정 |
| **tfoot** | 여러 열을 묶어 표의 푸터로 지정 |

***
### 하이퍼링크 태그 <a id="anchor8"></a>
| 태그 | 설명 | 속성 |
| :---: | --- | --- |
| **a** | 원하는 문서나 사이트로 연결 | href, target, title, text-decoration(CSS), color(CSS) |
| **앵커** | 한 페이지 안에서 원하는 곳으로 이동 |

***
### 이미지 관련 태그 <a id="anchor9"></a>
| 태그 | 설명 | 속성 |
| :---: | --- | --- |
| **img** | 이미지 넣기 | src, width, height, alt, title, usemap |
| **figure** | 캡션 대상 지정 |
| **figcaption** | 캡션 설명 붙이기 | color(CSS), font-weight(CSS), font-style(CSS) |

***
### 멀티미디어 관련 태그 <a id="anchor10"></a>
| 태그 | 설명 | 속성 |
| :---: | --- | --- |
| **video** | 비디오 파일 삽입 | src, width, height, controls, preload, autoplay, loop |
| **audio** | 오디오 파일 삽입 | src, controls, preload, autoplay, loop |
| **source** | 여러 미디어 파일 지정 | src, type, codecs |

***
### 폼 관련 태그 <a id="anchor11"></a>
| 태그 | 설명 | 속성 |
| :---: | --- | --- |
| **form** | 폼 생성 | method, name, action, target |
| **filedset** | 폼 요소 그룹화 | id, disabled, form, name |
| **legend** | fieldset 태그로 나눠진 구역의 제목 지정 |
| **label** | 폼 요소에 캡션 지정 | for |
| **input** | 사용자가 정보를 입력하는 태그 | type, id, name, value, readonly, placeholder, maxLength, required, ... |
| **select** | 드롭다운 목록 생성 | id, size, multiple |
| **optgroup** | 드롭다운 목록의 항목 그룹화 | label |
| **datalist** | 데이터 목록 생성 | id |
| **option** | 드롭다운 목록 / 데이터 목록 항목 추가 | value, selected(select), label(datalist) |
| **textarea** | 텍스트 영역 생성 | name, cols, rows |
| **button** | 버튼 생성 | type(submit, reset, button), class |
| **output** | 결과 출력 | name, for |
| **progress** | 진행 상태 표시 | value, max |
| **meter** | 값이 차지하는 크기 표시 | value, min, max, low, high, optimum |
<br>