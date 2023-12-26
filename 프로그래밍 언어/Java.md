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
        StringTokenizer st = new StringTokenizer(br.readline());
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        bw.write(st.nextToken() + "\n");
        bw.flush();
        bw.close();
    }
}
```
<br>

