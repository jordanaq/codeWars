def square_digits(num):
    result = ""

    while num > 0:      #Loops until we've gone through every digit
        result = str(pow(num % 10, 2)) + result     #Concatenates the squared value as a string
        num = num // 10

    return int(result)      #returns the final string as an int
