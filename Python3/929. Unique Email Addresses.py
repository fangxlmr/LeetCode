class Solution:
    def numUniqueEmails(self, emails: List[str]) -> int:
        s = set()
        for email in emails:
            user, domain = email.split('@')
            user = user.partition('+')[0].replace('.', '')
            s.add(user + '@' + domain)
        return len(s)
