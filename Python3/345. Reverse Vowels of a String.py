class Solution:
    # def reverseVowels(self, s: str) -> str:
    #     vowel_set = set("aeiou")
    #     chars = list(s)
    #     vowels = []
    #     for c in chars:
    #         if c in vowel_set:
    #             vowels.append(c)
    #     vowels.reverse()
    #     j = 0
    #     for i, c in enumerate(chars[:]):
    #         if c in vowel_set:
    #             chars[i] = vowels[j]
    #             j += 1
    #     return ''.join(chars)

    def reverseVowels(self, s: str) -> str:
        # Use two pointers
        vowels = set("aeiouAEIOU")
        i, j = 0, len(s) - 1
        slist = list(s)
        while i < j:
            # Using two pointers
            # Now find a vowel at left side
            if slist[i] in vowels:
                # Find another vowel at right side
                while j > i and slist[j] not in vowels:
                    j -= 1
                # Finish reverse vowels process
                if j <= i:
                    break
                else:
                    slist[i], slist[j] = slist[j], slist[i]
                # Left cursor step right, and right cursor step left
                i += 1
                j -= 1
            # Step cursor
            else:
                i += 1

        return ''.join(slist)
