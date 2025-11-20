# Poiners-in-C-and-C-Own-
Poiners in C and C++

1) pInt = &number
PInt는 Number의 주소를 가짐. 
즉, 지도에 보물섬의 위치가 적힌 상태

2) Pint 
단순히 Number의 주소값 
(보물섬 지도가 어디 있는지) 

3)*pInt
그 주소로 가서 확인한 Number의 실제값 
(보물섬에서 실제 금괴 꺼냄) 

4)&pint 
포인터 변수 pint자체가 메모리에서 어디에 저장돼있는지 
(그지도가 서랍 어느 칸인지)

5) 요약
pInt → 주소(지도)
*pInt → 그 주소의 실제 값(보물)
&pInt → 지도가 들어있는 서랍 위치

# 포인터 기술 정리 
1. C++에서 포인터는 ‘핵심’이 아니라 ‘하위 기술’이 됐다

C 언어에서는 포인터가 곧 메모리 관리의 모든 것이지만,
C++에서는 포인터가 언어 체계의 중심에 있지 않다.
왜냐면 C++에는 포인터를 “굳이” 직접 쓰지 않아도 되는 구조가 이미 깔려 있기 때문이다.

<h3> C++에서 포인터를 덜 쓰게 만드는 요소들</h3>
1. 참조(Reference)

2. RAII(Resource Acquisition Is Initialization)

3. 스마트 포인터(unique_ptr, shared_ptr 등)

4. STL 컨테이너(vector, string, map 등)
   
<h3> C++에는 포인터 책이 거의 없는 이유 (Why There Are So Few Books on C++ Pointers?) </h3>

<h3> C++개발자</h3>
이미 C 포인터를 알고 C++로 넘어온 사람이 많음 
C++ 입문자는 포인터보다 STL/클래스 위주로 진행
현대 C++ 개발자는 raw 포인터를 거의 직접 다루지 않음
그래서 "C++ 포인터만 전문적으로 공부하려고 하는" 독자가 거의 없음.

<h3> C++ 포인터가 더 쉽나? </h3>
결론: 기초 개념은 C보다 쉽다. 하지만 전체 시스템은 더 어렵다.
<h3>더 쉬운 이유</h3>
1. 참조(reference) 때문에 포인터를 덜 쓰며 코드가 단순해짐
2. new/delete 대신 스마트 포인터가 알아서 메모리 관리
3. C보다 타입 시스템이 강력해서 실수가 덜 난다

<h3>더 어려운 이유</h3>

1. C++은 “포인터 조작”보다
2. 소유권(ownership)
3. 수명(lifetime)
4. RAII
5. 스마트 포인터 내부 구조
이 훨씬 더 어렵고 깊다.
</br> 결론: 문법 개념만 보면 C++ 포인터는 더 단순
실전 메모리 모델은 C++이 더 복잡


<h2> 추천하는 공부 순서 </h2>
<p>C++ 포인터를 잘하고 싶다면 책 한 권보다 이 3개 조합이 훨씬 세다.
</p> 
1) C 포인터 책 1권
- Understanding and Using C Pointers → C 포인터 이해가 모든 기초.

2) C++ 객체 수명(라이프타임) + RAII
- Effective C++ 시리즈(특히 RAII 파트)

3) 스마트 포인터 & Modern C++
- Effective Modern C++
- C++ Primer (pointer & smart pointer section)

<h3> 서적 / 책 Reference </h3>
1.https://product.kyobobook.co.kr/detail/S000028165879(https://www.oreilly.com/library/view/understanding-and-using/9781449344535/?utm_source=chatgpt.com)

2. https://www.aladin.co.kr/shop/wproduct.aspx?ItemId=33784887&srsltid=AfmBOopMrjLslcHXAYl1kVhlBa4S_-fxEbVwUntlOqn3PuK18epC6zZS&utm_source=chatgpt.com#8994506799_CommentReview
3. https://www.oreilly.com/library/view/pointers-in-c/9781484269275/?utm_source=chatgpt.com
