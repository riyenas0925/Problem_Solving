package Programmers.Level2;

public class Solution {
    public static void main(String[] args) {
        String s = "one4seveneight";
        String[] arr = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
        for (int i = 0; i < arr.length; i++) {
            if (s.contains(arr[i])) {
                s = s.replaceAll(arr[i], Integer.toString(i));
            }
        }
        System.out.println(Integer.parseInt(s));
    }
}