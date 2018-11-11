class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        int i;
        set<string> email_sets;
        for (i = 0; i < emails.size(); i++)
        {
            // Delete elements between '+' and '@'
            string::size_type plus = emails[i].find('+');
            string::size_type at = emails[i].find('@');
            if (plus != emails[i].npos) 
                emails[i].erase(plus, at-plus);
            
            // Loop to delete '.' before '@' 
            string::size_type dot = emails[i].find('.');
            while (dot != emails[i].npos)
            {
                at = emails[i].find('@');
                if (dot > at) break;
                emails[i].erase(dot, 1);
                dot = emails[i].find('.');
            }
            email_sets.insert(emails[i]);
        }
        
        return email_sets.size();
    }
};