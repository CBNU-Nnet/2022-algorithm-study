# 2022 네스트넷 여름방학 알고리즘 스터디

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

</details><br>

## 스터디 진행 방식 🎲

1. `매주 5문제`가 출제됩니다. 
(백준에서 브/실/골 각 1문제 + 프로그래머스에서 2문제)
2. 선정된 문제 중 `3문제`를 풀어 `금요일`까지 `PR`을 작성합니다.
(추가적으로 푼 문제 또한 올리셔도 괜찮습니다)
3. `토 ~ 일`에는 다른 스터디원이 작성한 PR에 대해 `코드리뷰`를 해줘야 합니다.

[파일 구조 및 각종 규칙들은 여기서 확인해 주세요](https://github.com/CBNU-Nnet/2022-algorithm-study/issues/1/#issues)

<br>

## 문제집 📚

<table>
  <thead align='center'>
    <tr>
        <td></td>
        <td colspan='3'>백준</td>
        <td colspan='2'>프로그래머스</td>
    </tr>
    <tr>
        <td></td>
        <td>브론즈</td>
        <td>실버</td>
        <td>골드</td>
        <td>lv.1~2</td>
        <td>lv.2~3</td>
    </tr>
  </thead>
  <tbody align='center'>
    <tr> 
      <td>1주차</td>
      <td><a href="https://www.acmicpc.net/problem/16503">괄호 없는 사칙연산</a></td>
      <td><a href="https://www.acmicpc.net/problem/1699">제곱수의 합</a></td>
      <td><a href="https://www.acmicpc.net/problem/5639">이진 검색 트리</a></td>
      <td><a href="https://programmers.co.kr/learn/courses/30/lessons/64061">크레인 인형 뽑기</a></td>
      <td><a href="https://programmers.co.kr/learn/courses/30/lessons/60058">괄호 변환</a></td>
    </tr>
  </tbody>
</table>


## 🙋‍♂️ 출석부 🙋‍♀️

|     | 최문형 | 이동우 | 조현창 | 김동용 | 이승현 | 김성호 | 허원일 | 김나영 | 임종훈 | 홍범순 | 김예경 |
|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|
| 1주차 |     |     |     |     |     |     |     |     |     |     |     |

