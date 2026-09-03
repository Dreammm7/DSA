class Solution:
    def isPalindrome(self, s: str, i: int, j: int) -> bool:
        while i < j:
            if s[i] != s[j]:
                return False
            i += 1
            j -= 1
        return True

    def check(self, a: str, b: str) -> bool:
        i, j = 0, len(a) - 1
        while i < j and a[i] == b[j]:
            i += 1
            j -= 1
        return self.isPalindrome(a, i, j) or self.isPalindrome(b, i, j)

    def checkPalindromeFormation(self, a: str, b: str) -> bool:
        return self.check(a, b) or self.check(b, a)
     