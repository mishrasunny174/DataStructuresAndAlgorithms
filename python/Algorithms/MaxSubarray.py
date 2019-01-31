#!/usr/bin/env python3
import math


def maxSubArray(Array):
    return _maxSubArray(Array, 0, len(Array)-1)


def _maxSubArray(Array, start, end):
    if start == end:
        return start, end, Array[start]
    else:
        mid = int((start+end)/2)
        leftStart, leftEnd, leftSum = _maxSubArray(Array, start, mid)
        rightStart, rightEnd, rightSum = _maxSubArray(Array, mid+1, end)
        crossStart, crossEnd, crossSum = _crossSubArray(Array, start, mid, end)
        if leftSum >= rightSum and leftSum >= crossSum:
            return leftStart, leftEnd, leftSum
        elif rightSum >= leftSum and rightSum >= crossSum:
            return rightStart, rightEnd, rightSum
        else:
            return crossStart, crossEnd, crossSum


def _crossSubArray(Array, start, mid, end):
    leftSum = -math.inf
    sum = 0
    leftLow = -1
    for i in range(mid, start, -1):
        sum += Array[i]
        if sum > leftSum:
            leftSum = sum
            leftLow = i
    sum = 0
    rightSum = -math.inf
    rightHigh = end
    for i in range(mid, end):
        sum += Array[i]
    if sum > rightSum:
        rightSum = sum
        rightHigh = i
    return leftLow, rightHigh, leftSum+rightSum


def main():
    size = int(input("Enter array size: "))
    array = [int(input("Enter {} element: ".format(i))) for i in range(size)]
    print(array)
    result = maxSubArray(array)
    print("Max subarray is {} with sum {}".format(
        [array[i] for i in range(result[0], result[1]+1)], result[2]))


if __name__ == "__main__":
    main()
