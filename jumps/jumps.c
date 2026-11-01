/* 1980s developers were CRAZY, <setjmp.h> could legitimately
   become the topic of a blockbuster sci-fi film. */

#include <stdio.h>
#include <setjmp.h>
#include <string.h>

static jmp_buf one;
static jmp_buf two;
static long state;

#define TOLD_CHARLES 0x1

void tallputs(const char *str);

main()
{
    int day;
    extern jmp_buf one;
    extern jmp_buf one;
    extern long state;
    for (day = 4; day <= 7; ++day) {
        switch (day) {
        case 4:
            tallputs("--- Today is Thursday, day of strange incident. ---");
            puts("Charles: Dude no way, is school canceled??\n"
                "[REDACTED]: YEAHHHHHHHHHH\n"
                "Charles: Hold on, WHERE IS ZE PHONE??\n");
            if (setjmp(one) != 0) {
                tallputs("<< SERVER: [REDACTED] has successfully jumped to checkpoint 'one'. >>\n"
                    "It is Thursday.\n");
                puts("[REDACTED]: You should wear your costume tomorrow.\n"
                    "Charles: Uhh... sure I guess?\n");
                state |= TOLD_CHARLES;
                puts("<< SERVER: [REDACTED] has updated the global state. >>");
                break;
            }
            tallputs("<< SERVER: [REDACTED] placed checkpoint 'one'. >>");
            puts("[REDACTED]: So, what's your costume?\n"
                "Charles: Oh, just some guy with spiky hair.");
            break;
        case 5:
            tallputs("--- Today is Friday, day of costumes. ---");
            if (state & TOLD_CHARLES) {
                puts("[REDACTED]: Hey Charles, I see you dressed up today.\n"
                    "Charles: I'm not Charles today.\n"
                    "[REDACTED]: Wait, then who are you?\n"
                    "Charles?: I keep telling you, I'm not Charles. I don't like having a name, but you can call me Greasy Joe if you want.\n"
                    "[REDACTED]: Ok, Greasy Joe.");
                break;
            }
            puts("[REDACTED]: Charles, why are you not wearing your costume?\n"
                "Charles: Oh, I just wanted to save it for tomorrow.\n"
                "[REDACTED]: That's fair.");
            break;
        case 6:
            tallputs("--- Today is Saturday, day of the candy hoarding. ---");
            // TODO
            break;
        case 7:
            tallputs("--- Today is Sunday, day of the sun. ---");
            // TODO
            break;
        }
    }
    return 0;
}

void tallputs(const char *str) {
    printf("\n%s\n\n", str);
}
