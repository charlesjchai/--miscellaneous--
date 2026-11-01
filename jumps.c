#include <stdio.h>
#include <setjmp.h>
#include <string.h>

jmp_buf one;
jmp_buf two;

int main(void) {
    int day;
    for (day = 4; day < 8; ++day) {
        switch (day % 7) {
        case 0:
            puts("Today is Sunday, day of the sun.");
            break;
        case 1:
            puts("Today is Monday, the embodiment of pain and stress.");
            break;
        case 4:
            puts("--- Today is Thursday, day of ZE gas leak. ---");
            if (setjmp(one) != 0) {
                // TODO
            }
            puts("Charles: Dude no way, is school canceled??\n"
                "[REDACTED]: YEAHHHHHHHHHH"
                "Charles: Hold on, WHERE IS ZE PHONE??");
            break;
        case 5:
            puts("Today is Friday, day of costumes.");
            break;
        case 6:
            puts("Today is Saturday, day of the candy hoarding.");
            break;
        }
    }
    return 0;
}
