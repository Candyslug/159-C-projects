
int GetMax(const int nums[]) {
    int buff = nums[0];
    // iterate through the numbers
    // and update a buffer with the new highest value found
    for (int i = 0; i < 3; i++) {
        if (nums[i] > buff) {
            buff = nums[i];
        }
    }
    return buff;
}

int GetMin(const int nums[]) {
    int buff = nums[0];
    // iterate through the numbers
    // and update a buffer with the new lowest value found
    for (int i = 0; i < 3; i++) {
        if (nums[i] < buff) {
            buff = nums[i];
        }
    }
    return buff;
}

float GetMean(const int nums[]) {
    float ret = 0.0f;
    // convert total to float to ensure
    // it can be accurately divisible
    // and result in a number with decimal point
    ret = (float)(nums[0] + nums[1] + nums[2]) / 3.0f;
    return ret;
}

int GetRange(const int nums[]) {
    int max = GetMax(nums);
    int min = GetMin(nums);
    return max - min;
}

float GetMeanMaxRange(const int nums[]) {
    float max = (float)GetMax(nums);
    float mean = GetMean(nums);
    return max - mean;
}

int GetAbs(const int num) {
    int ret = num;
    // if number is negative, make it positive
    if (ret < 0) {
        ret = ret * -1;
    }
    return ret;
}