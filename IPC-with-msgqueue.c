#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

struct msg {
    long type;
    char text[100];
};

int main() {
    key_t key = 1234;
    int msgid = msgget(key, 0666 | IPC_CREAT);

    struct msg message;
    message.type = 1;

    strcpy(message.text, "Hello Message Queue!");

    msgsnd(msgid, &message, sizeof(message.text), 0);

    printf("Message sent: %s\n", message.text);

    msgrcv(msgid, &message, sizeof(message.text), 1, 0);

    printf("Message received: %s\n", message.text);

    msgctl(msgid, IPC_RMID, NULL);

    return 0;
}
