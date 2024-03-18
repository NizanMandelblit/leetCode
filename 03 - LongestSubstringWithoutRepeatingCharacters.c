/**
 * @file 03 - LongestSubstringWithoutRepeatingCharacters.c
 *
 * @author Nizan Mandelblit
 * @brief
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/
 * Given a string s, find the length of the longest
 * substring without repeating characters.
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lengthOfLongestSubstringRecursive(char *s, long max) {
  if (s == NULL)
    return max;

  int arr[26] = {0};
  char *ptr = s;
  int i = 0;
  int counter = 0;
  while (*ptr) {
    if (arr[(*ptr - 'a')]) {
      if (counter > max) {
        return lengthOfLongestSubstringRecursive((s + 1), counter);
      } else {
        return lengthOfLongestSubstringRecursive((s + 1), max);
      }
    } else {
      counter++;
      arr[(*ptr - 'a')] = 1;
    }
    ptr++;
  }

  return max;
}

int lengthOfLongestSubstring(char *s) {
  return lengthOfLongestSubstringRecursive(s, 0);
}

int main(int argc, char **argv) {
  printf("abcabcbb result is %d\r\n", lengthOfLongestSubstring("abcabcbb"));
  printf("bbbbb result is %d\r\n", lengthOfLongestSubstring("bbbbb"));
  printf("pwwkew result is %d\r\n", lengthOfLongestSubstring("pwwkew"));

  return 0;
}
