def fib(n):
    if n == 1 or n == 2:
        return 1
    pre = 1
    cur = 1
    for i in range(3, n + 1):
        temp = cur
        cur = pre + cur
        pre = temp
    return cur

if __name__ == '__main__':
    for i in range(1, 8):
        print(fib(i), end=' ')
