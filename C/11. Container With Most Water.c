int min (int x, int y) {
    return x < y ? x : y;
}

int max (int x, int y) {
    return x > y ? x : y;
}


int maxArea(int* height, int heightSize) {
    int S, left, right;

    S = 0;
    left  = 0;
    right = heightSize - 1;
    while (left < right) {
        S = max(S, min(height[left], height[right]) * (right - left));
        if (height[left] < height[right]) {
            ++left;
        } else {
            --right;
        }
    }
    return S;
}