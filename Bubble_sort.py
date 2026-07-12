import random
import time
import matplotlib.pyplot as plt


def bubble_sort(arr):
    n = len(arr)

    for i in range(n):
        for j in range(n - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]


def calculate_time(sort_function, arr):
    temp = arr.copy()

    start = time.perf_counter()
    sort_function(temp)
    end = time.perf_counter()

    return end - start


sizes = [100, 200, 400, 800, 1000]

times = []

for size in sizes:

    arr = [random.randint(1, 1000) for _ in range(size)]

    execution_time = calculate_time(bubble_sort, arr)

    times.append(execution_time)

    print(f"Size = {size}, Time = {execution_time:.6f} seconds")


plt.plot(sizes, times, marker='o')
plt.title("Bubble Sort Time ")
plt.xlabel("Array Size")
plt.ylabel("Time (seconds)")
plt.grid(True)
plt.show()
