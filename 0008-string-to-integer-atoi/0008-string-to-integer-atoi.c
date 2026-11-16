 int myAtoi(char* s) {
    int i = 0, sign = 1;
    long long num = 0;
    
 while (s[i] == ' ') {
        i++;
    }

    if (s[i] == '-' || s[i] == '+') {
        if (s[i] == '-') {
            sign = -1;
        }
        i++;
    }

    while (s[i] >= '0' && s[i] <= '9') {
        int digit = s[i] - '0';

    long long limit = (sign == 1) ? INT_MAX : -(long long)INT_MIN;
        if (num > (limit - digit) / 10) {
            return sign == 1 ? INT_MAX : INT_MIN;
        }
        num = num * 10 + digit;
        i++;
    }

    return (int)(num * sign);
}
