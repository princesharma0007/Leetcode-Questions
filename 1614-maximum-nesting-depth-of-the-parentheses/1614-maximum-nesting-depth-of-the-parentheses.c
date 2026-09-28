int maxDepth(char* s) {
    int i = 0;
    int count = 0;
    int max = 0; 

    while (s[i] != '\0') {
        if (s[i] == '(') {
            count++;
            if (count > max) {
                max = count;
            }
        }
        if (s[i] == ')') {
            count--;
        }
       i++;
    }

    return max;
}