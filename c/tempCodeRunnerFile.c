int *sortNums = sortArray(nums, count);
    // for (int i = 0; i < count; i++)
    // {
    //     printf("%d ", *(sortNums + i));
    // }
    // printf("\n");
    // int result[2] = {0, 0};
    // for (int i = 0; *(sortNums + i) < target && i < count; i++)
    // {
    //     //printf("%d ", *(sortNums + i)); 1 2 7
    //     result[0] = *(sortNums + i);
    //     while (*(sortNums + i + 1) != target - result[0])
    //     {
    //         i = i + 1;
    //     }
    //     result[1] = *(sortNums + i + 1);
    // }
    // for (int i = 0; i < 2; i++)
    // {
    //     printf("%d ", result[i]);
    // }