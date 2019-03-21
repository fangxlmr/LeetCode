class Solution:
#    def reorderLogFiles(self, logs: List[str]) -> List[str]:
#        letter_logs = list(filter(lambda x: x.split(' ')[1].isalpha(), logs))
#        digit_logs = list(filter(lambda x: x.split(' ')[1].isdigit(), logs))
#        letter_logs.sort(key=lambda x: x.partition(' ')[2])
#        return letter_logs.extend(digit_logs)

#    def reorderLogFiles(self, logs):
#        """
#        A better coding style from discuss.
#        https://leetcode.com/problems/reorder-log-files/discuss/192144/Python-1-liner
#        """
#        l = [log for log in logs if log[-1].isalpha()]
#        d = [log for log in logs if log[-1].isdigit()]
#        return sorted(l, key=lambda x: (x[x.find(" "):], x[:x.find(" ")])) + d

    def reorderLogFiles(self, logs):
        """
        Official solution is the best.
        """
        def f(log):
            id_, rest = log.split(" ", 1)
            return (0, rest, id_) if rest[0].isalpha() else (1,)

        return sorted(logs, key=f)
