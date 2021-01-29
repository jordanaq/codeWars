string solution(int number){
  // convert the number to a roman numeral
  string output = "";


  while (number > 0) {
    if (number >= 1000) output+= "M", number -= 1000;
    else if (number >= 900) output+= "CM", number -= 900;
    else if (number >= 500) output+= "D", number -= 500;
    else if (number >= 400) output+= "CD", number -= 400;
    else if (number >= 100) output+= "C", number -= 100;
    else if (number >= 90) output+= "XC", number -= 90;
    else if (number >= 50) output+= "L", number -= 50;
    else if (number >= 40) output+= "XL", number -= 40;
    else if (number >= 10) output+= "X", number -= 10;
    else if (number >= 9) output+= "IX", number -= 9;
    else if (number >= 5) output+= "V", number -= 5;
    else if (number >= 4) output+= "IV", number -= 4;
    else if (number >= 1) output+= "I", number -= 1;
  }


  return output;
}
