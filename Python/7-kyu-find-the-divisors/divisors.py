def divisors(integer):
    res = []
    
    for i in range(2, integer // 2 + 1):
        if integer % i == 0:
            res.append(i)
    
    if res == []:
        return str(integer) + " is prime"
    else:
        return res
