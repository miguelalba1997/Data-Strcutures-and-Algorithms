
arr = ['a','a','c','d','d']
def find_doubles(arr):
        count = 1
        dict = {}
        for i in range(len(arr)):
                temp = arr[i]
                if temp in dict:
                    print(temp)
                    return temp
                else:
                    dict[temp] = count
        print("No Doubles!")
        return -1
find_doubles(arr)