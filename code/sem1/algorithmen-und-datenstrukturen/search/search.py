import timeit, random


def binary_search(arr, element):
    low, high = 0, len(arr) - 1
    while high >= low:
        mid = (low + high) // 2
        if arr[mid] == element:
            return mid

        if arr[mid] > element:
            high = mid - 1
        else:
            low = mid + 1

    return -1


def linear_search(arr, element):
    for i in range(len(arr)):
        if arr[i] == element:
            return i

    return -1


def main():
    arr = [x for x in range(100000000)]
    el = random.randint(0, len(arr) - 1)
    runs = 10

    bin_search_ms = timeit.timeit(lambda: binary_search(arr, el), number=runs)
    #lin_search_ms = timeit.timeit(lambda: linear_search(arr, el), number=runs)

    print(f"Binary Search: {bin_search_ms * 1000}ms ({bin_search_ms / runs * 1000}ms per run)")
   # print(f"Linear Search: {lin_search_ms * 1000}ms ({lin_search_ms / runs * 1000}ms per run)")


if __name__ == "__main__":
    main()
