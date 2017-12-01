# -*- coding:utf-8 -*-
class Solution:
    def minNumberInRotateArray(self, rotateArray):
        # write code here
        if len(rotateArray) == 0:
            return 0
        front = 0
        rear = len(rotateArray) - 1
        mid = front
        while rotateArray[front] >= rotateArray[rear]:
            if rear - front == 1:
                mid = rear
                break
            mid = (front + rear) // 2
            if rotateArray[front] == rotateArray[mid] and rotateArray[mid] == rotateArray[rear]:
                return self.minInOrder(rotateArray, front, rear)

            if rotateArray[mid] >= rotateArray[front]:
                front = mid
            elif rotateArray[mid] <= rotateArray[rear]:
                rear = mid

        return rotateArray[mid]

    def minInOrder(self, rotateArray, front, rear):
        minNum = rotateArray[front]
        for temp in rotateArray[front:rear + 1]:
            if minNum >= temp:
                minNum = temp
        return minNum