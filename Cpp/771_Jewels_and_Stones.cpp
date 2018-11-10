class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int num = 0;
        char *j = (char *) J.c_str();
        char *s = (char *) S.c_str();
        for (int i = 0; i < J.size(); i++,j++)
            for (int k = 0; k < S.size(); k++)
                if (*j == s[k]) num++;
        return num;
    }
};