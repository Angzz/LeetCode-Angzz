class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {

        // Time Consume : 36ms
        /* 
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
        */

        // Time Consume : 20ms
        set<string> email_sets;
        for (string email : emails)
        {
            string::size_type pos = email.find('@');
            string local_name = email.substr(0, pos);
            string domain_name = email.substr(pos+1);
            pos = local_name.find('+');
            local_name = local_name.substr(0, pos);
            local_name.erase(std::remove(local_name.begin(), local_name.end(), '.'), local_name.end());
            email = local_name+'@'+domain_name;
            email_sets.insert(email);
        }
        return email_sets.size();
    }
};