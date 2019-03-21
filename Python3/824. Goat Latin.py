class Solution:
    def toGoatLatin(self, S: str) -> str:
        vowel = set("aeiou")
        ans = []
        for index, word in enumerate(S.split(' ')):
            if word[0].lower() in vowel:
                ans.append(word + "ma" + 'a' * (index + 1))
            else:
                ans.append(word[1:] + word[0] + "ma" + 'a' * (index + 1))
        return ' '.join(ans)
