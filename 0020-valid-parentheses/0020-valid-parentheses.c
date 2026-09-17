bool isValid(char* s) {
    int len = strlen(s);

    while (len > 0) {
        int found = 0;

        for (int i = 0; i < len - 1; i++) {

            if ((s[i] == '(' && s[i + 1] == ')') ||
                (s[i] == '[' && s[i + 1] == ']') ||
                (s[i] == '{' && s[i + 1] == '}')) {

                for (int j = i; j < len - 2; j++) {
                    s[j] = s[j + 2];
                }

                len = len - 2;
                found = 1;
                break;
            }
        }

        if (found == 0) {
            return 0;
        }
    }

    return 1;
}