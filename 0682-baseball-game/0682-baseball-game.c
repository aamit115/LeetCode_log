int calPoints(char** operations, int operationsSize) {
    int stack[1000], top = -1;
    for (int i = 0; i < operationsSize; i++) {
        if (strcmp(operations[i], "C") == 0) {
            top--;}
        else if (strcmp(operations[i], "D") == 0) {
            int x = 2 * stack[top];
            stack[++top] = x;}
        else if (strcmp(operations[i], "+") == 0) {
            int x = stack[top] + stack[top - 1];
            stack[++top] = x;}
        else {stack[++top] = atoi(operations[i]);}}
    int sum = 0;
    for (int i = 0; i <= top; i++)
        sum += stack[i];
    return sum;
}