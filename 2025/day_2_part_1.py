from typing import List, Tuple
range_data: List[Tuple[int, int]] = []
ans = 0

def get_invalid_ids():
    global ans
    for a, b in range_data:
        for i in range(a, b + 1):
            res = str(i)
            sz = len(res)
            if sz % 2 == 0:
                half = sz // 2
                if res[:half] == res[half:]:
                    ans += i
    print(f"Total Sum of Invalid IDs: {ans}")

if __name__ == "__main__":
    input_str = input().strip().strip(',')
    str_ranges = input_str.split(',')
    for item in str_ranges:
        if '-' in item:
            start, end = item.split('-')
            range_data.append((int(start), int(end)))
    
    get_invalid_ids()
