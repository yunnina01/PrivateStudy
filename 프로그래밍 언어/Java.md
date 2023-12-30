# Java (Java 11)

백준 알고리즘 문제를 해결하며 정리한 Java 언어에 대한 내용입니다.
<br><br>

***
* **BufferedReader / BufferedWriter**  
BufferedReader는 Scanner와, BufferedWriter는 System.out.println()과 유사한 기능이다.  
입력된 데이터가 버퍼를 거쳐 전달되므로 데이터 처리 효율성을 높여 속도가 빠르다.  
BufferedReader는 Enter만 경계로 인식하고, readline()시 데이터가 String으로 고정된다.  
BufferedWriter는 버퍼를 사용하므로 flush() / close()를 반드시 호출해야 한다.  
또한, 자동개행기능이 없기 때문에 개행을 위해서는 '\n'을 추가해주어야 한다.

``` Java
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = null;
        
        st = new StringTokenizer(br.readline());
        bw.write(st.nextToken() + "\n");
        bw.flush();
        bw.close();
    }
}
```
<br>

* **-> (Lambda Expression)**  
람다식은 식별자없이 실행가능한 함수를 말하며, Python의 lambda와 비슷하다고 보면 된다.  
함수를 따로 만들지 않고 코드 한 줄로 함수를 생성하여 호출할 수 있기 때문에, 가독성이 좋다.  

``` Java
public class Main {
    public static void main(String[] args) {
        Point[] points = new Point[5];

        points[0] = new Point(1, 2);
        points[1] = new Point(1, 3);
        Arrays.sort(points, (p1, p2) -> p1.y - p2.y);
    }
}

class Point {
    int x, y;

    Point(int x, int y) {
        this.x = x;
        this.y = y;
    }
}
```
<br>

* **offer / poll / peek**  
LinkedList의 Stack / Queue 전용 메소드로, ErrorHandling이 되어 있지 않다.  
offer은 값을 추가해주는 함수로, add와 달리 오류발생 시 Exception이 일어나지 않는다.  
메모리 한계까지 만들지 않는 이상 용량 제한이 발생하기 어려우므로 어느 것을 써도 상관없다.  
poll은 값을 빼내는 함수로, remove와 달리 값이 없으면 null을 반환한다.  
peek은 값을 확인하는 함수로, get(getFirst, getLast)이나 element와 달리 값이 없으면 null을 반환한다.  

``` Java
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Queue<Integer> queue = new LinkedList<>();
        queue.offer(3);
        queue.peek();
        queue.poll();
    }
}
```
<br>
