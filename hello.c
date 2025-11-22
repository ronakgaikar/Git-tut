#include <graphics.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    srand(time(0));
    int target = rand() % 100 + 1;
    int guess;
    char msg[50];

    while (1) {
        cleardevice();
        settextstyle(3, 0, 2);
        outtextxy(100, 100, "Guess the number (1–100): ");

        // Input from user via console (since graphics.h doesn’t take text input)
        printf("Enter your guess: ");
        scanf("%d", &guess);

        if (guess == target) {
            setcolor(GREEN);
            sprintf(msg, "Correct! The number was %d", target);
            outtextxy(100, 200, msg);
            break;
        } else if (guess < target) {
            setcolor(RED);
            outtextxy(100, 200, "Too low! Try again.");
        } else {
            setcolor(RED);
            outtextxy(100, 200, "Too high! Try again.");
        }

        delay(1000);
    }

    getch();
    closegraph();
    return 0;
}
