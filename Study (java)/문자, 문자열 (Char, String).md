# 문자열

## 문자열 기본
### length
* 문자열의 길이 반환
* 길이에 NULL 포함 X
```java
String str = "abcde"
str.length()    // 5 NULL 포함 안함
```

### isEmpty
* 문자열이 비었는지 검사
```java
String str = new String();
if(str.isEmpty) // true
```

### charAt
* 인덱스에 해당하는 문자 반환
```java
String str = "abcde";
str.charAt(2)   // 'c'
```

## 문자열 비교
### equals
* 문자열이 같은지 비교
* 자바에서는 == 으로 문자열 비교 못함
```java
String str1 = "abc";
String str2 = "abc";
str1.equals(str2)    // true
```

### compareTo
* 문자열과 매개변수를 사전 순으로 비교
* 문자열과 매개변수가 같으면 -> 0
* 문자열이 매개변수보다 앞이면 -> -1
* 문자열이 매개변수보다 뒤면 -> 1
```java
String str1 = "aaa";
String str2 = "bbb";
str1.compareTo(str2);   // aaa가 bbb보다 사전순으로 앞이기 때문에 -1 출력
```

```java
String str1 = "ccca";
String str2 = "cccz";
str1.compareTo(str2);   //마지막 문자 하나만 다르면 사전 순 차이만큼 반환 -25
```

## 문자열 자르기
### substring
```java
str.substring(start);        // start부터 끝까지
str.substring(start, end);   // start부터 end위치 까지
```

```java
String str = "abcdefghijk"; // str의 인덱스는 0부터 시작
str.substring(3);           // "defghijk"
str.substring(3, 5);        // "def"
```

## 문자열 치환
### replace
* 모든 문자열을 치환
* str.replace(기존문자, 대체문자)
```java
String str = "abc abc abc";
str.replace("abc", "xyz");      // "xyz xyz xyz"
str.replace('a', 'A');          // "Abc Abc Abc"
```

### replaceAll
* 특수문자가 사용된 것을 바꿀때는 사용 불가 (정규식에서 특수문자를 사용하기 때문)
* str.replaceAll(정규식, 대체문자)
```java
String str = "abc abc abc";
str = str.replaceAll("abc", "xyz");    // "xyz xyz xyz"
```

### replaceFirst
* 첫번째 찾은 문자열만 치환
```java
String str = "abc abc abc";
str = str.replaceFirst("abc", "xyz");    // "xyz abc abc"
```