class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        """
        Use Sunday algorithm.
        """
        if haystack is None or needle is None:
            return -1
        elif needle == "":
            return 0
        else:
            lens, lenp = len(haystack), len(needle)
            if lens < lenp:
                return -1
            else:
                i = j = 0
                while i < lens and j < lenp:
                    # Char matches between string and pattern
                    if haystack[i] == needle[j]:
                        i += 1
                        j += 1
                    else:
                        # Mismatch, get index of next char in string as pin
                        pin = i + lenp - j
                        # Pin overhead, must be no matches any more
                        if pin >= lens:
                            return -1
                        else:
                            # Find occurrence of haystack[pin] in pattern
                            k = lenp - 1
                            while k >= 0 and needle[k] != haystack[pin]:
                                k -= 1
                            i, j = pin - k, 0
                return i - j if j == lenp else -1
