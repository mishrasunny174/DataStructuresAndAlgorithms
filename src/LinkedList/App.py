from LinkedList import LinkedList

list = LinkedList()

list.insertBegin(101)
list.insertBegin(10)
list.insertBegin(102)
list.insertBegin(120)
list.insertEnd(130)

for item in list.traverse():
    print(item, end=' ')

print('\n'+'-'*20)

list.remove(10)

for item in list.traverse():
    print(item, end=' ')