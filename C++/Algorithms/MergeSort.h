#ifndef MERGE_SORT_H
#define MERGE_SORT_H

template <typename T>
void merge(T *array, int starting, int mid, int ending)
{
    int size = ending-starting;
    T* temp = new T[size];
    int counter1 = starting,counter2 = mid+1,counter3=0;
    while(counter1<=mid && counter2<=ending)
    {
        if(array[counter1]<array[counter2])
            temp[counter3++] = array[counter1++];
        else
            temp[counter3++] = array[counter2++];
    }
    while(counter1<=mid)
    {
        temp[counter3++] = array[counter1++];
    }
    while(counter2<=ending)
    {
        temp[counter3++] = array[counter2++];
    }
    for(int i=0;i<counter3;i++)
        array[i+starting] = temp[i];
    delete[] temp;
}

template <typename T>
void mergeSort(T *array, int starting, int ending)
{
    int mid = (ending + starting)/2;
    if(starting<ending)
    {
        mergeSort(array,starting,mid);
        mergeSort(array,mid+1,ending);
        merge(array,starting,mid,ending);
    }
}

#endif