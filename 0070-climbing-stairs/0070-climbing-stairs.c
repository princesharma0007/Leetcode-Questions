int climbStairs(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;

    int a = 1; 
    int b = 2;           
    int current = 0;          
    for (int i = 3; i <= n; i++) {
        current = b + a; 
        a = b;           
        b = current;                   
    }

    return current;
}
