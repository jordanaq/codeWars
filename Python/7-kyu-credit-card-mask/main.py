# return masked string
def maskify(cc):
  temp  = ""

  if len(cc) > 4:
    for i in range(0, len(cc) - 4):
      temp = temp + '#'
      
    for i in range(len(cc) - 4, len(cc)):
      temp = temp + cc[i]

    return temp

  else:
    return cc
