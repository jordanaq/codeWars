def divisors(integer):
    res = [i for i in range(2, integer // 2 + 1) if integer % i == 0]
    
    return "%d is prime" % integer if res == [] else res
