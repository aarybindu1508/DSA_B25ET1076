#include <stdio.h>

#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

void sendData(int data)
{
    if ((rear + 1) % SIZE == front)
    {
        printf("Transmit buffer is full!\n");
        return;
    }

    if (front == -1)
        front = 0;

    rear = (rear + 1) % SIZE;
    queue[rear] = data;

    printf("Data transmitted: %d\n", data);
}

void receiveData()
{
    int data;

    if (front == -1)
    {
        printf("Receive buffer is empty!\n");
        return;
    }

    data = queue[front];
    printf("Data received: %d\n", data);

    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % SIZE;
    }
}

void display()
{
    int i;

    if (front == -1)
    {
        printf("Buffer is empty!\n");
        return;
    }

    printf("Buffer data: ");

    i = front;

    while (1)
    {
        printf("%d ", queue[i]);

        if (i == rear)
            break;

        i = (i + 1) % SIZE;
    }

    printf("\n");
}

int main()
{
    int choice, data;

    do
    {
        printf("\n--- UART Communication ---\n");
        printf("1. Send Data\n");
        printf("2. Receive Data\n");
        printf("3. Display Buffer\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter data to send: ");
                scanf("%d", &data);
                sendData(data);
                break;

            case 2:
                receiveData();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 4);

    return 0;
}
