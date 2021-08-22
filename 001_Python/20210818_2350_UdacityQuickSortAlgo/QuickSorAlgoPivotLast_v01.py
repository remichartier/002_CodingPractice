"""Implement quick sort in Python.
Input a list.
Output a sorted list."""

# Note : method always starting with last element as pivot

def quicksort(array):
    # quick sort with pivot
    # Then quick sort left_side of pivot and quick_sort right side of pivot
    # Then combine left_array + Pivot + Right Array
    # but reminder : it is an "in place" Algorithm
    #left = 0
    #right = len(array) -1

    def sort(left,right):
        pivot = right
        #for pos in range(left,right + 1):
        pos = left
        while pos != pivot and pos < right :
            # compare value at pos and value at pivot
            # if array(pivot) < array(pos), need to move pivot...
            if array[pivot] < array[pos]:
                tmp = array[pos]
                array[pos] = array[pivot-1]
                array[pivot-1] = array[pivot]
                array[pivot] = tmp
                pivot -= 1
                pos = left
            else:
                pos +=1                
        # end loop
        # Now sort right array, since left array already sorted
        if left < pivot -1:
            sort(left,pivot-1)
        if pivot+1 < right:
            sort(pivot+1,right)


    sort(0,len(array)-1)
    return array

test = [21, 4, 1, 3, 9, 20, 25, 6, 21, 14]
print(quicksort(test))