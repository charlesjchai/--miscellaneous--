/* 1980s developers were CRAZY, <setjmp.h> could legitimately
   become the topic of a blockbuster sci-fi film. Program ONLY
   compiles in C89. */

#include <stdio.h>
#include <setjmp.h>

static jmp_buf one;
static jmp_buf two;
static unsigned int state;
static struct {
    int day;
    unsigned int state;
} saveFile;

#define TOLD_CHARLES (1U << 0)
#define EVER_TOLD_CHARLES (1U << 1)

void tallputs(const char *str);

main()
{
    volatile int day;
    for (day = 4; day <= 7; ++day) {
        switch (day) {
        case 4:
            tallputs("--- Today is Thursday, day of strange incident. ---");
            puts("Charles: Dude no way, is school canceled??\n"
                 "[REDACTED]: YEAHHHHHHHHHH\n"
                 "Charles: Hold on, WHERE IS ZE PHONE??");

            if (setjmp(one) != 0) {
                tallputs("[REDACTED] successfully jumps to checkpoint 'one'.\n"
                         "It is Thursday.");
                day = saveFile.day;
                puts("[REDACTED]: You should wear your costume tomorrow.\n"
                     "Charles: Uhh... sure I guess?\n"
                     "[REDACTED] will remember that.");
                state |= TOLD_CHARLES;
                state |= EVER_TOLD_CHARLES;
                break;
            }
            saveFile.day = day;
            tallputs("[REDACTED] places checkpoint 'one'.");
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

            if (setjmp(two) == 0) {
                if (!(state & TOLD_CHARLES)) {
                    saveFile.state = state;
                    puts("[REDACTED] places checkpoint 'two'.");
                }
            } else {
                tallputs("[REDACTED] successfully jumps to checkpoint 'two'.\n"
                         "It is Saturday. [REDACTED] remembers telling Charles.");
                saveFile.state |= EVER_TOLD_CHARLES;
                state = saveFile.state;
            }

            if (state & TOLD_CHARLES) {
                tallputs("[REDACTED] is warping to checkpoint 'two'...");
                longjmp(two, 0);
            }
            if (state & EVER_TOLD_CHARLES) {
                puts("[REDACTED]: Hey Charles, your costume on Friday was very nice.\n"
                     "Charles: Bro what, I never wore a costume on Friday, ur trippin gng\n"
                     "\t -^\n"
                     "\t(oO)\n"
                     "\t(__)\n\n"
                     "[REDACTED]: Yeah sure, Greasy Joe.");
            }
            break;
        case 7:
            tallputs("--- Today is Sunday, day of the sun. ---");
            if (!(state & (TOLD_CHARLES | EVER_TOLD_CHARLES))) {
                tallputs("[REDACTED] is warping to checkpoint 'one'...");
                longjmp(one, 0);
            }
            puts("Charles: Bro, what was that all about??");
            break;
        }
    }
    return 0;
}

void tallputs(const char *str) {
    printf("\n%s\n\n", str);
}
