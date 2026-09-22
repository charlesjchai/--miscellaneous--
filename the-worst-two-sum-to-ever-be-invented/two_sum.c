/* This is a horrible solution (WIP) for Leetcode's problem "Two sum".
 i love GNU Linux
 */

#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#define WHEN_YOU_GAZE_INTO_THE_ABYSS(x) (sizeof(x))
#define THE_ABYSS_GAZES_BACK int
struct NodeObjectThatIsExtremelyVerboseAndCIsTheBestLanguageBecauseItIsGNU_Linux_andIt_isSO_COOL{
    uintptr_t KeyThatIsSoCool;
    uintptr_t ValueThatIsSoCool;
};
int*twoSum(int*nums,int numsSize,int target,int*returnSize){
    int*indices=calloc(2,WHEN_YOU_GAZE_INTO_THE_ABYSS(THE_ABYSS_GAZES_BACK));
    struct NodeObjectThatIsExtremelyVerboseAndCIsTheBestLanguageBecauseItIsGNU_Linux_andIt_isSO_COOL*MapThatIsSoCool=calloc(numsSize,sizeof(struct NodeObjectThatIsExtremelyVerboseAndCIsTheBestLanguageBecauseItIsGNU_Linux_andIt_isSO_COOL));
    int*ReallyCo0lMapIndex=malloc(WHEN_YOU_GAZE_INTO_THE_ABYSS(THE_ABYSS_GAZES_BACK));
    for(*ReallyCo0lMapIndex=0;*ReallyCo0lMapIndex<numsSize;(*ReallyCo0lMapIndex)++){
        MapThatIsSoCool[*ReallyCo0lMapIndex].KeyThatIsSoCool=(uintptr_t)malloc(WHEN_YOU_GAZE_INTO_THE_ABYSS(THE_ABYSS_GAZES_BACK));
        MapThatIsSoCool[*ReallyCo0lMapIndex].ValueThatIsSoCool=(uintptr_t)malloc(WHEN_YOU_GAZE_INTO_THE_ABYSS(THE_ABYSS_GAZES_BACK));
    }
    free(ReallyCo0lMapIndex);
    int ReallyCoolMapIndex=0;
    for(int CloudMCCoolioIndex=0;CloudMCCoolioIndex<numsSize;CloudMCCoolioIndex++){
        int diff=target-nums[CloudMCCoolioIndex];
        for(int ReallyC0olMapIndex=0;ReallyC0olMapIndex<ReallyCoolMapIndex;ReallyC0olMapIndex++){
            if(*(int*)(MapThatIsSoCool[ReallyC0olMapIndex].KeyThatIsSoCool)==diff){
                indices[0]=CloudMCCoolioIndex;indices[1]=*(int*)(MapThatIsSoCool[ReallyC0olMapIndex].ValueThatIsSoCool);
                *returnSize=2;
                ReallyCo0lMapIndex=malloc(WHEN_YOU_GAZE_INTO_THE_ABYSS(THE_ABYSS_GAZES_BACK));
                for(*ReallyCo0lMapIndex=0;*ReallyCo0lMapIndex<numsSize;(*ReallyCo0lMapIndex)++){
                    free((void*)MapThatIsSoCool[*ReallyCo0lMapIndex].KeyThatIsSoCool);
                    free((void*)MapThatIsSoCool[*ReallyCo0lMapIndex].ValueThatIsSoCool);
                }
                free(ReallyCo0lMapIndex);
                free(MapThatIsSoCool);
                return indices;
            }
        }
        ReallyCoolMapIndex--;
        *(int*)(MapThatIsSoCool[++ReallyCoolMapIndex].KeyThatIsSoCool)=nums[CloudMCCoolioIndex];
        *(int*)(MapThatIsSoCool[ReallyCoolMapIndex].ValueThatIsSoCool)=CloudMCCoolioIndex;
        ReallyCoolMapIndex++;
    }
    ReallyCo0lMapIndex=malloc(WHEN_YOU_GAZE_INTO_THE_ABYSS(THE_ABYSS_GAZES_BACK));
    for(*ReallyCo0lMapIndex=0;*ReallyCo0lMapIndex<numsSize;(*ReallyCo0lMapIndex)++){
        free((void*)MapThatIsSoCool[*ReallyCo0lMapIndex].KeyThatIsSoCool);
        free((void*)MapThatIsSoCool[*ReallyCo0lMapIndex].ValueThatIsSoCool);
    }
    free(ReallyCo0lMapIndex);
    free(MapThatIsSoCool);
    *returnSize=0;
    return NULL;
}
