class MaxHeap(object):
    def __init__(self, size):
        self.heap = [0]*size
        self.currentPosition = -1

    def insert(self, data):
        self.currentPosition += 1
        self.heap[self.currentPosition] = data
        self.fixUp()

    def fixUp(self):
        if not self.isFull():
            index = self.currentPosition
            parentIndex = int((index-1)/2)
            while parentIndex >= 0 and self.heap[index] > self.heap[parentIndex]:
                temp = self.heap[index]
                self.heap[index] = self.heap[parentIndex]
                self.heap[parentIndex] = temp
                index = parentIndex
                parentIndex = int((index-1)/2)
        else:
            print('ERROR: heap is full')

    def isFull(self):
        if self.currentPosition < len(self.heap):
            return False
        return True

    def printHeap(self):
        for i in range(0, self.currentPosition+1):
            print(self.heap[i], end=' ')
        print('\n')

    def getMax(self):
        result = self.heap[0]
        self.heap[0] = self.heap[self.currentPosition]
        self.currentPosition -= 1
        self.fixDown(0)
        return result

    def fixDown(self, index):
        if index <= self.currentPosition:
            leftChildPosition = 2*index+1
            rightChildPosition = 2*index+2
            if leftChildPosition <= self.currentPosition:
                if self.heap[index] < self.heap[leftChildPosition]:
                    temp = self.heap[leftChildPosition]
                    self.heap[leftChildPosition] = self.heap[index]
                    self.heap[index] = temp
                    self.fixDown(leftChildPosition)
            if rightChildPosition <= self.currentPosition:
                if self.heap[index] < self.heap[rightChildPosition]:
                    temp = self.heap[rightChildPosition]
                    self.heap[rightChildPosition] = self.heap[index]
                    self.heap[index] = temp
                    self.fixDown(rightChildPosition)