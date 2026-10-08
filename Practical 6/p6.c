#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *top = NULL;

void push(int value)
{
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

void display()
{
    struct Node *temp = top;

    printf("Stack: ");

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

void pop()
{
    struct Node *temp;

    if (top == NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        temp = top;
        printf("Popped element = %d\n", top->data);
        top = top->next;
        free(temp);
    }
}

void peek()
{
    if (top == NULL)
        printf("Stack is empty\n");
    else
        printf("Top element = %d\n", top->data);
}

int main()
{
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);

    display();
    peek();
    
    pop();
    pop();

    printf("\nStack after popping elements\n");

    display();

    peek();

    return 0;
}
