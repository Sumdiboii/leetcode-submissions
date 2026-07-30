# class Solution:

#   def reverseWords(self, s: str) -> str:
#     # Split the string by spaces (automatically handles multiple/leading/trailing spaces)
#     words = s.split()

#     # Reverse the list of words
#     words.reverse()

#     # Join the reversed list back into a single string with a single space separator
#     return " ".join(words)
class Solution:

  def reverseWords(self, s: str) -> str:
    res = []
    i = 0
    n = len(s)

    while i < n:
      # Pointer 1: Skip any leading/extra spaces
      while i < n and s[i] == " ":
        i += 1
      if i >= n:
        break

      # Pointer 2: Find the end of the current word
      j = i
      while j < n and s[j] != " ":
        j += 1

      # Extract the word using the two pointers and store it
      res.append(s[i:j])

      # Move the outer pointer past the word
      i = j

    # Reverse the list of words manually or via built-in reverse
    res.reverse()

    # Join them back with a single space
    return " ".join(res)