int longestValidParentheses(char* s) {
    int n = strlen(s);
    int open = 0, close = 0;
    int res = 0;
    // Left to right
    for (int i = 0; i < n; i++) {
        if (s[i] == '(')
            open++;
        else
            close++;
        if (open == close) {
            res = (res > open + close) ? res : open + close;
        }
        else if (close > open) {
            open = close = 0;
        }
    }
    // Right to left
    open = close = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '(')
            open++;
        else
            close++;

        if (open == close) {
            res = (res > open + close) ? res : open + close;
        }
        else if (open > close) {
            open = close = 0;
        }
    }
    return res;
}
//learned concept from codestorywithMIK