s1 = 0
s2 = 0

def max2(a, n):
    global s1, s2
    if a[0] >= a[1]:  # Python列表从0开始，调整索引
        s1 = 0
        s2 = 1
    else:
        s1 = 1
        s2 = 0
    
    for j in range(2, n):
        if a[j] > a[s1]:
            s2 = s1
            s1 = j
        elif a[j] > a[s2]:
            s2 = j

def calculate_min(a, n):
    # 创建数组副本，避免修改原数组
    arr = a.copy()
    current_n = n
    while current_n > 2:
        max2(arr, current_n)
        arr[s1] = arr[s1] * arr[s2] + 1
        arr[s2] = arr[current_n - 1]  # 最后一个元素
        current_n -= 1
    return arr[0] * arr[1] + 1

def min2(a, n):
    global s1, s2
    if a[0] <= a[1]:  # Python列表从0开始，调整索引
        s1 = 0
        s2 = 1
    else:
        s1 = 1
        s2 = 0
    
    for j in range(2, n):
        if a[j] < a[s1]:
            s2 = s1
            s1 = j
        elif a[j] < a[s2]:
            s2 = j

def calculate_max(a, n):
    # 创建数组副本，避免修改原数组
    arr = a.copy()
    current_n = n
    while current_n > 2:
        min2(arr, current_n)
        arr[s1] = arr[s1] * arr[s2] + 1
        arr[s2] = arr[current_n - 1]  # 最后一个元素
        current_n -= 1
    return arr[0] * arr[1] + 1

def main():
    num = int(input())
    a = []
    for _ in range(num):
        a.append(int(input()))
    
    # 创建副本用于不同计算
    b = a.copy()
    
    min_val = calculate_min(a, num)
    max_val = calculate_max(b, num)
    
    print(f"Max=max-min={max_val}-{min_val}={max_val - min_val}")

if __name__ == "__main__":
    main()