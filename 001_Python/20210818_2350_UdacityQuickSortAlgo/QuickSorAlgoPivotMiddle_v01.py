"""Implement quick sort in Python.
Input a list.
Output a sorted list."""

# For this version, implement with picking pivot as the middle
# --> will partition by swapping elements arount pivot.
# return new pivot index position
# And then sort recursively both sides around the pivot.

def quicksort(array):
    # pick pivot in the middle :

    def qsort(left,right):
        print(f'qsort({left},{right})')
        print(array)
        start = left
        end = right

        index = int((left+right)/2)
        pivot = array[index]
        # scroll all this array until left meets right
        while(left < right):
            # search on left item to swap
            while array[left] < pivot:
                left += 1
           # search on right item to swap
            while array[right] > pivot:
                right -= 1
            if left <= right: # then we can swap
                tmp = array[left]
                array[left] = array[right]
                array[right] = tmp
                left += 1
                right -= 1
        # end while()
        # exit when left >= right
 
        # then need to sort start to left and then left+1 to right
        if start < left-1:
            qsort(start,left-1)
        if left < end:
            qsort(left,end)



    qsort(0,len(array)-1)
    return array

test = [21, 4, 1, 3, 9, 20, 25, 6, 21, 14]
print(quicksort(test))
