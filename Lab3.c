#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the stack
#define MAX_SIZE 100

// Define the precedence of operators
int getPrecedence(char op) 
{
    switch(op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0; // for operands
    }
}

// Function to convert infix expression to postfix
void infixToPostfix(char infix[], char postfix[]) 
{
    char stack[MAX_SIZE];
    int top = -1;
    int i, j;

    for (i = 0, j = 0; infix[i] != '\0'; i++) 
    {
        char token = infix[i];

        if ((token >= 'a' && token <= 'z') || (token >= 'A' && token <= 'Z')) 
        {
            postfix[j++] = token; // Operand, directly add to postfix
        } 
        else if (token == '(') 
        {
            stack[++top] = token; // Left parenthesis, push onto the stack
        } 
        else if (token == ')') 
        {
            // Right parenthesis, pop and add to postfix until a matching '(' is found
            while (top != -1 && stack[top] != '(') 
            {
                postfix[j++] = stack[top--];
            }
            if (top != -1) 
            {
                top--; // Pop the '(' from the stack
            }
        } 
        else 
        {
            // Operator, pop and add to postfix until the stack is empty or the top has lower precedence
            while (top != -1 && getPrecedence(stack[top]) >= getPrecedence(token)) {
                postfix[j++] = stack[top--];
            }
            stack[++top] = token; // Push the current operator onto the stack
        }
    }

    // Pop any remaining operators from the stack and add to postfix
    while (top != -1) 
    {
        postfix[j++] = stack[top--];
    }

    postfix[j] = '\0'; // Null-terminate the postfix expression
}

void main() 
{
    char infix[MAX_SIZE], postfix[MAX_SIZE];

    // Input infix expression using scanf
    printf("Enter an infix expression: ");
    scanf("%s", infix);
    

    // Convert infix to postfix
    infixToPostfix(infix, postfix);

    // Output the postfix expression
    printf("Postfix expression: %s\n", postfix);

}
