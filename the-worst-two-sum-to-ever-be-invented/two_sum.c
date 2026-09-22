/* This is a horrible solution (WIP) for Leetcode's problem "Two sum".
 i love GNU Linux
 */

#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
struct NodeObjectThatIsExtremelyVerboseAndCIsTheBestLanguageBecauseItIsGNU_linux_andIt_isSO_COOL{
    uintptr_t KeyThatIsSoCool;
    uintptr_t ValueThatIsSoCool;
};
int*twoSum(int*nums,int numsSize,int target,int*returnSize){
    int*indices=calloc(2,4);
    struct NodeObjectThatIsExtremelyVerboseAndCIsTheBestLanguageBecauseItIsGNU_linux_andIt_isSO_COOL*MapThatIsSoCool=calloc(numsSize,sizeof(struct NodeObjectThatIsExtremelyVerboseAndCIsTheBestLanguageBecauseItIsGNU_linux_andIt_isSO_COOL));
    int*ReallyCo0lMapIndex=malloc(4);
    for(*ReallyCo0lMapIndex=0;*ReallyCo0lMapIndex<numsSize;(*ReallyCo0lMapIndex)++){
        MapThatIsSoCool[*ReallyCo0lMapIndex].KeyThatIsSoCool=(uintptr_t)malloc(4);
        MapThatIsSoCool[*ReallyCo0lMapIndex].ValueThatIsSoCool=(uintptr_t)malloc(4);
    }
    free(ReallyCo0lMapIndex);
    int ReallyCoolMapIndex=0;
    for(int CloudMCCoolioIndex=0;CloudMCCoolioIndex<numsSize;CloudMCCoolioIndex++){
        int diff=target-nums[CloudMCCoolioIndex];
        if(*(int*)(MapThatIsSoCool[ReallyCoolMapIndex].KeyThatIsSoCool)==diff){
            indices[0]=CloudMCCoolioIndex;indices[1]=*(int*)(MapThatIsSoCool[ReallyCoolMapIndex].ValueThatIsSoCool)==diff;
            break;
        }
        ReallyCoolMapIndex--;
       *(int*)(MapThatIsSoCool[++ReallyCoolMapIndex].KeyThatIsSoCool)=nums[CloudMCCoolioIndex];
       *(int*)(MapThatIsSoCool[ReallyCoolMapIndex].ValueThatIsSoCool)=CloudMCCoolioIndex;
        ReallyCoolMapIndex++;
    }
    returnSize=malloc(4);
   *returnSize=8;
    return indices;
}
