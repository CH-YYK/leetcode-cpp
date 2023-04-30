def maxAtEnd(arr):
    if len(arr) <= 1:
        return arr
    else:
        if arr[0] > arr[1]:
            return [arr[1]] + maxAtEnd([arr[0]] + arr[2:])
        else:
            return [arr[0]] + maxAtEnd(arr[1:])


def bubble(arr):
    if len(arr) <= 1:
        return arr
    else:
        maxAtEndArr = maxAtEnd(arr)
        return bubble(maxAtEndArr[0:-1]) + [maxAtEndArr[-1]]


def maxAtEnd2(arr, i):
    if i == len(arr) - 1:
        return None
    else:
        if arr[i] > arr[i+1]:
            arr[i], arr[i+1] = arr[i+1], arr[i]
        maxAtEnd2(arr, i+1)


def bubble2(arr, i):
    if i == len(arr) - 1:
        return None
    else:
        maxAtEnd2(arr, i)
        bubble2(arr, i+1)


if __name__ == "__main__":
    arr = [6, 3, 1, 2, 5, 4]
    print(maxAtEnd2(arr, 0))

    print(arr)
    bubble2(arr, 0)
    print(arr)
