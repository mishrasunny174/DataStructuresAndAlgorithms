from Heap import MaxHeap

heap = MaxHeap(10)

heap.insert(20)
heap.insert(10)
heap.insert(1)
heap.insert(0)
heap.insert(50)
heap.printHeap()
print('\n')
print(heap.getMax())
print('\n')
heap.printHeap()
