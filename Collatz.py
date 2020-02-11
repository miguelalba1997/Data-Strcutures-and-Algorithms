 
def collatz(n, count):
    #global count 
    if n == 1:
        return count
    elif n % 2:
        count += 1
        print(count)
        collatz(3*n + 1, count)
    elif !n % 2:
        count += 1
        print(count)
        collatz(n/2, count)     
	
		
collatz(1005, 0)

