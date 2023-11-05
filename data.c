include <stdio.h>
include <stdlib.h>
include <kod.txt>
#define MAX_SIZE 100

typedef struct {
    char data[MAX_SIZE];
    int top;
} Stack;

void init(Stack *s) {
    s->top = -1;
}

void push(Stack *s, char c) {
    if (s->top < MAX_SIZE - 1) {
        s->top++;
        s->data[s->top] = c;
    } else {
        printf("Stack is full.\n");
    }
}

char pop(Stack *s) {
    if (s->top >= 0) {
        char c = s->data[s->top];
        s->top--;
        return c;
    } else {
        return '\0'; // Empty stack, return null character
    }
}

int isEmpty(Stack *s) {

 return s->top == -1;
}

int main() {
    Stack stack;
    init(&stack);

    FILE *dosya = fopen("kod.txt", "r");
    if (dosya == NULL) {
        printf("Dosya açma hatası.\n");
        return 1;
    }

    int satir = 1;
    char karakter;
    while ((karakter = fgetc(dosya)) != EOF) {
        if (karakter == '(') {
            push(&stack, karakter);
        } else if (karakter == ')') {
            if (isEmpty(&stack)) {
                printf("Hata: Satır %d - Kapatılmamış parantez.\n", satir);
            } else {
                pop(&stack);
   }
        } else if (karakter == '\n') {
            satir++;
        }
    }

    while (!isEmpty(&stack)) {
        printf("Hata: Satir %d - Kapatilmamis parantez.\n", satir);
        pop(&stack);
    }

    fclose(dosya);

 return 0;
}
