bool isAnagram(char* s, char* t) {
    if (!s || !t)
        return false;
    if (strlen(s) != strlen(t))
        return false;

    int table[26] = {};
    for (int i = 0; i < strlen(s); i++)
        table[s[i] - 'a']++;
    for (int i = 0; i < strlen(s); i++)
        table[t[i] - 'a']--;

    for (int i = 0; i < 26; i++) {
        if (table[i])
            return false;
    }
    return true;
}
