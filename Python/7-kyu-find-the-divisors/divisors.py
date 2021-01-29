def divisors(integer):
    return [i for i in range(2, integer // 2 + 1) if integer % i == 0] or "%d is prime" % integer
