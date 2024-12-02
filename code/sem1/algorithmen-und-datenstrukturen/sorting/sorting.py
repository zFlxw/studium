import random
import timeit


def selection_sort(arr):
    for i in range(len(arr)):
        min = i
        for j in range(i + 1, len(arr)):
            if arr[j] < arr[min]:
                min = j

        arr[i], arr[min] = arr[min], arr[i]


def insertion_sort(arr, low=0, high=-1):
    if high == -1:
        high = len(arr)
    
    for i in range(low+1, high):
        key = arr[i]
        j = i - 1

        while j >= low and key < arr[j]:
            arr[j + 1] = arr[j]
            j -= 1

        arr[j + 1] = key


def shell_sort(arr):
    # Start with a big gap, then reduce the gap
    n = len(arr)
    gap = int(n // 2)

    # Do a gapped insertion sort for this gap size.
    # The first gap elements a[0..gap-1] are already in gapped
    # order keep adding one more element until the entire array
    # is gap sorted
    while gap > 0:

        for i in range(gap, n):

            # add a[i] to the elements that have been gap sorted
            # save a[i] in temp and make a hole at position i
            temp = arr[i]

            # shift earlier gap-sorted elements up until the correct
            # location for a[i] is found
            j = i
            while j >= gap and arr[j - gap] > temp:
                arr[j] = arr[j - gap]
                j -= gap

            # put temp (the original a[i]) in its correct location
            arr[j] = temp
        gap = gap // 2


def merge(left, right):
    list = []
    left_i, right_i = 0, 0

    while left_i < len(left) and right_i < len(right):
        if left[left_i] <= right[right_i]:
            list.append(left[left_i])
            left_i += 1
        else:
            list.append(right[right_i])
            right_i += 1

    while left_i < len(left):
        list.append(left[left_i])
        left_i += 1

    while right_i < len(right):
        list.append(right[right_i])
        right_i += 1

    return list


def merge_sort(arr):
    if len(arr) <= 1:
        return arr

    mid = len(arr) // 2

    left = arr[:mid]
    right = arr[mid:]

    left = merge_sort(left)
    right = merge_sort(right)

    return merge(left, right)


def partition(arr, low, high):
    pivot = arr[(low + high) // 2]
    left = low
    right = high

    while 1:
        while arr[left] < pivot:
            left += 1

        while arr[right] > pivot:
            right -= 1

        if left >= right:
            return right

        arr[left], arr[right] = arr[right], arr[left]
        left += 1
        right -= 1


def quick_sort(arr, low=0, high=None, cutoff=30):
    if not high:
        high = len(arr) - 1

    if low < high - cutoff:
        old_pivot_index = partition(arr, low, high)
        quick_sort(arr, low, old_pivot_index)
        quick_sort(arr, old_pivot_index + 1, high)
    else:
        insertion_sort(arr, low, high + 1)


def benchmark(sorting_algortihm, arr, runs, dbg=False):
    # A copy is necessary to prevent the original array from being sorted. This is necessary when using the same array
    # for multiple benchmarks.
    arr_copy = arr.copy()
    
    time = timeit.timeit(lambda: sorting_algortihm(arr_copy), number=runs)

    print(f"===== Benchmark for {sorting_algortihm.__name__} =====")
    print(f"Array Size: {len(arr)}")
    print(f"Runs: {runs}")
    print(f"Total time: {int(time * 1000)}ms")
    print(f"Avg. time (per run): {int(time * 1000 / runs)}ms")

    if dbg:
        print(f"Array (unsorted): {arr}")
        print(f"Array (sorted): {arr_copy}")


def main():
    arr = [i for i in range(1000)]
    random.shuffle(arr)
    runs = 100

    quick_sort(arr, 0, len(arr)-1)
    print(arr)

    #    benchmark(shell_sort, arr, runs, dbg=False)
    """ benchmark(
        merge_sort, arr, runs, dbg=False
    )  # Debug Mode doesnt work for mergesort, as it doesnt touch the original array """
   # benchmark(sorted, arr, runs)
    benchmark(quick_sort, arr, runs)


if __name__ == "__main__":
    main()
