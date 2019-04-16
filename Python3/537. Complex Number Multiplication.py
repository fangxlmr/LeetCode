class Solution:
    def complexNumberMultiply(self, a: str, b: str) -> str:
        (a1, a2) = tuple(int(x) for x in a.strip('i').split('+'))
        (b1, b2) = tuple(int(y) for y in b.strip('i').split('+'))
                
        c1 = a1 * b1 - a2 * b2
        c2 = a1 * b2 + b1 * a2

        return "{0}+{1}i".format(c1, c2)
