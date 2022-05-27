#include <stdio.h>
#include <math.h>

void PrintExpressions(int n, float withoutParenthesis, float withParenthesis) {
    printf("Expression %i - without parenthesis: %f, with parenthesis: %f\n",
    n, withoutParenthesis, withParenthesis);
}

int main() {

    float expression_without_parenthesis, expression_with_parenthesis;

    // 1. Expression 1
    expression_without_parenthesis = 1 + 3 / 2;
    expression_with_parenthesis = 1 + (3/2);
    PrintExpressions(1, expression_without_parenthesis, expression_with_parenthesis);

    // 2. Expression 2
    expression_without_parenthesis = 2 - 3 * 4;
    expression_with_parenthesis = 2 - (3 * 4);
    PrintExpressions(2, expression_without_parenthesis, expression_with_parenthesis);

    // 3. Expression 3
    expression_without_parenthesis = 2 / 3 * 4;
    expression_with_parenthesis = (2 / 3) * 4;
    PrintExpressions(3, expression_without_parenthesis, expression_with_parenthesis);

    // 4. Expression 4
    expression_without_parenthesis = 2 * 3 / 4;
    expression_with_parenthesis = (2 * 3) / 4;
    PrintExpressions(4, expression_without_parenthesis, expression_with_parenthesis);

    // 5. Expression 5
    expression_without_parenthesis = 2 / 3 / 4;
    expression_with_parenthesis = (2 / 3) / 4;
    PrintExpressions(5, expression_without_parenthesis, expression_with_parenthesis);

    // 6. Expression 6
    expression_without_parenthesis = 4 / 3 * 2 / 5;
    expression_with_parenthesis = ((4 / 3) * 2) / 5;
    PrintExpressions(6, expression_without_parenthesis, expression_with_parenthesis);

    // 7. Expression 7
    expression_without_parenthesis = 6 * 3 / 4 * 5;
    expression_with_parenthesis = ((6 * 3) / 4) * 5;
    PrintExpressions(7, expression_without_parenthesis, expression_with_parenthesis);

    // 8. Expression 8
    expression_without_parenthesis = 4 * 3 * 3; // 4 * 3 ^ 2^
    expression_with_parenthesis = (4 * 3) * (4 * 3);
    PrintExpressions(8, expression_without_parenthesis, expression_with_parenthesis);

    // 9. Expression 9
    expression_without_parenthesis = 2 - pow(2, 3) * 2; // 2 - 2 ^ 3 * 2;
    expression_with_parenthesis = 2 - (pow(2, 3) * 2);
    PrintExpressions(9, expression_without_parenthesis, expression_with_parenthesis);

    // 10. Expression 10
    expression_without_parenthesis = 2.0 / 3.0 * 4 * 4;
    expression_with_parenthesis = (2.0 / 3.0) * pow(4, 2);
    PrintExpressions(10, expression_without_parenthesis, expression_with_parenthesis);

    // 11. Expression 11
    expression_without_parenthesis = 1 + 2 / 3 * 4 + 5;
    expression_with_parenthesis = 1 + ((2.0 / 3.0) * 4) + 5;
    PrintExpressions(11, expression_without_parenthesis, expression_with_parenthesis);

    // 12. Expression 12
    expression_without_parenthesis = 5 / 2 * 2 + 4 % 3 + 9 - 3;
    expression_with_parenthesis = (((5 / 2) * 2) + (4 % 3) + 9) - 3;
    PrintExpressions(12, expression_without_parenthesis, expression_with_parenthesis);

    return(0);
}