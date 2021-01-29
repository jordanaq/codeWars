#include <string>


std::string encrypt(std::string text, int n)    //Encrypts string text by removing every other char n times
{
  for (int i = 0; i < n; i++) {
    std::string partOne = "";   //Creates two temp strings for the even and odd chars
    std::string partTwo = "";

    for (unsigned int g = 0; g < text.size(); g++) {    //Adds even chars to partOne and odd ones to partTwo
      if (g % 2 == 0) partOne += text[g];
      else partTwo += text[g];
    }

    text = partTwo + partOne;   //Combining the parts into an encrypted string
  }   //for loop repeats this process n times


  return text;
}


std::string decrypt(std::string encryptedText, int n)
{
  for (int i = 0; i < n; i++) {
    std::string temp = "";    //Makes a temp string so I can still look at original chars

    std::string partOne = encryptedText.substr(0, encryptedText.size() / 2);    //Splits the string into two halves down the middle
    std::string partTwo = encryptedText.substr(encryptedText.size() / 2,
        encryptedText.size() - partOne.size());;

    for (unsigned int g = 0; g < partTwo.size(); g++) {   //Adds the chars from each part string in order
      temp += partTwo[g];
      if (!(g == partOne.length())) temp += partOne[g];   //If statement stops the loop from adding garbage data to string
    }   //for loop repeats this process n times

    encryptedText = temp;   //Sets the now unencrypted text equal to the original variable so we can repeat process
  }


  return encryptedText;
}
