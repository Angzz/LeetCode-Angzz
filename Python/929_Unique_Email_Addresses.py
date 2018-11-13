class Solution:
    def numUniqueEmails(self, emails):
        """
        :type emails: List[str]
        :rtype: int
        """
        return len(set(email[:email.find('+')].replace('.','') + email[email.find('@'):] for email in emails))
        