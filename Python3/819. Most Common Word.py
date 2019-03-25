class Solution:
   # def mostCommonWord(self, paragraph: str, banned: List[str]) -> str:
   #     words = re.findall(r"\w+", paragraph.lower())
   #     count = collections.Counter(words)
   #     for word in banned:
   #         if word in count:
   #             count.pop(word)
   #     return max(count, key=count.get)

    def mostCommonWord(self, paragraph: str, banned: List[str]) -> str:
        # Solution without using re module
        # but this solution cannot support all test cases provided by LeetCode
        words = [word.strip("!?',;.") for word in paragraph.lower().split()]
        count = collections.Counter(words)
        for word in banned:
            if word in count:
                count.pop(word)
        return max(count, key=count.get)
