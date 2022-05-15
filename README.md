# 2022 네스트넷 자료구조, 알고리즘 스터디

## GitHub에 코드 올리는 방법 ❔

<details><summary>자세히</summary>

### 0. 초기 환경 설정

1. #### 맨 처음, 이 repository를 `fork` 한다.

   <p align="center">
    <img src="https://user-images.githubusercontent.com/74577714/162030249-6f63fc17-7886-453c-b2e2-a9f1a5256646.png" style="zoom:50%;"/>
   </p>

2. #### `fork` 받은 저장소를 자신의 컴퓨터에 clone 받은 뒤 자신의 이름으로 된 폴더를 생성한다.

   앞으로 올리는 모든 파일들은 `자신의 이름`으로 된 폴더 안에 올려야 한다

   <p align="center">
    <img src="https://user-images.githubusercontent.com/74577714/162030843-41e1056b-a4b5-486c-91fc-8d466cc750c4.png" style="zoom:50%;"/>
   </p>

   ```bash
   $ git clone [fork한 자신의 repository 주소]
   $ cd 2022-algorithm-study

   $ mkdir -p [자신의 이름]
   ```

   **주의**: IDE로 폴더를 열때 `자신의이름` 폴더를 열어야 `.ide` 같은 에디터 설정 파일들이 엉뚱한데 추가되지 않는다

3. #### upstream 주소 추가

   ```bash
   $ git remote add upstream https://github.com/CBNU-Nnet/2022-algorithm-study.git
   $ git remote -v
   ```
<br>

### 1. 저장소 최신으로 업데이트

커밋 내역을 깔끔하게 하기 위해서 `-r` 옵션 사용

```bash
$ git pull -r upstream main
```

<br>

### 2. 문제별로 커밋 생성

* 문제별 고민 시간은 최대 1시간을 넘기지 않는 것이 좋다.

* 코드 리뷰를 진행하므로 최대한 가독성이 좋게 작성하려고 노력해보기

* 커밋하는 방법

  ```bash
  $ git add .
  $ git status
  $ git commit -m "[1주차] : 최문형 - 1998 토마토 Gold5 (#10)"
  $ git push origin main
  ```

* #### 커밋 메시지 생성 규칙

  [{주차}] : {이름} - {문제번호 문제이름 티어} (#문제집issue번호)

  ex) `[1주차] : 최문형 - 1998 토마토 Gold5 (#10)`

  > 커밋 메시지에 issue 번호를 포함시키면, 추후에 issue에 해당 커밋들을 모아서 확인할 수 있다.

* #### 문제집 `issue` 번호

  GitHub `issue` 탭에서 확인할 수 있다.

<br>

### 3. 해당 문제집의 문제들을 다 풀고나면 PR 생성

`fork` 해 온 저장소로 이동해서 Pull Request를 생성한다.

* #### 제목

  [{주차}] {이름} (#문제집issue번호)

  ex) `[1주차] 최문형 (#10)`

* #### 내용

  풀이 간단하게 설명, 문제풀면서 어려웠던 점, 소요시간 등 적어두기

- 주차별 과제의 경우 reviewer 모두 지정하기

<br>

### 4. 코드리뷰 후 merge

* 코드 리뷰 내용은 자유롭게 작성하기
  - 코드에 대해서 궁금한 점 질문
  - 코드에 대한 칭찬
  - 코드 개선 아이디어 건의 (성능, 클린코드 등)
  - 등등 ..
* 코드 리뷰가 끝난 뒤 필요에 따라 추가로 리팩토링하고 커밋 (커밋 형식은 자유)

</details><br>

## 스터디 진행 방식 🎲

0. `소그룹`으로 나누어 진행됩니다.
1. `팀별 공동과제`는 `매주 1문제`가 출제됩니다.
2. 공동과제와 개인이 푼 문제는 `PR`에 올립니다.
3. 각 조원끼리는 꼭 `코드리뷰`를 해줘야 합니다.

[파일 구조 및 각종 규칙들은 여기서 확인해 주세요](https://github.com/CBNU-Nnet/2022-algorithm-study/issues/1/#issues)

<br>

## 문제집 📚

<details>
   <summary>1 ~ 2주차 문제집</summary>
   <br>
<table>
  <thread>
    <tr>
      <td>주차 / 그룹</td>
      <td>해바라기반</td>
      <td>슬기로운반</td>
      <td>지혤로운반</td>
      <td>장미반</td>
    </tr>
  </thread>
  <tbody>
    <tr>
      <td>1주차</td>
      <td><a href="https://www.acmicpc.net/problem/1541">잃어버린 괄호</a></td>
      <td colspan="3"><a href="https://www.acmicpc.net/problem/10869">사칙연산</a></td>
    </tr>
    <tr>
       <td>2주차</td>
       <td><a href="https://www.acmicpc.net/problem/1283">단축키 지정</a></td>
       <td colspan="3"><a href="https://www.acmicpc.net/problem/1267">핸드폰 요금</a></td>
    </tr>
  </tbody>
</table>
<hr>
</details>

||브론즈 문제|실버 문제|골드 문제|
|:--:|:-:|:-:|:-:|
|3주차|[첼시를 도와줘!](https://www.acmicpc.net/problem/11098)|[중앙값 제거](https://www.acmicpc.net/problem/23758)|[소셜 네트워킹 어플리케이션](https://www.acmicpc.net/problem/7511)
|4주차|[뚜기뚜기메뚜기](https://www.acmicpc.net/problem/10545)|[소-난다!](https://www.acmicpc.net/problem/19699)|[트리인가?](https://www.acmicpc.net/problem/6416)
|5주차|[터널의 입구와 출구](https://www.acmicpc.net/problem/5612)|[기타줄](https://www.acmicpc.net/problem/1049)|[개똥벌레](https://www.acmicpc.net/problem/3020)
<br>

## 🙋‍♂️ 출석부 🙋‍♀️

||이동우|조현창|최문형|이승현|김동용|이진원|임수연|김예경|김예원|허정윤|허원일|엄예진|
|:--:|:--:|:--:|:--:|:--:|:--:|:--:|:--:|:--:|:--:|:--:|:--:|:--:|
|1주차|✔️|✔️|✔️|✔️|✔️|||✔️|✔️|||✔️|
|2주차|✔️|✔️|✔️|✔️||||✔️|✔️|✔️||✔️|
|3주차||✔️|✔️|✔️||✔️|✖️||✔️|||✔️|
|4주차|||✔️|||||||✔️||✔️|
