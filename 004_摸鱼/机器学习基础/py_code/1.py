def main():
    ans = []
    for num in range(1, 1001):
        if num % 3 == 0 and '5' in str(num):
            ans.append(num)
    print(ans)

if __name__ == '__main__':
    main()
