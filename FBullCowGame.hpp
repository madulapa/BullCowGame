#ifndef FBullCowGame_hpp
#define FBullCowGame_hpp

#include <stdio.h>
#include <string>

using FString = std::string;
using int32 = int;

struct BullCowCount
{
    int32 Bulls = 0;
    int32 Cows = 0;
    
};

enum class EWordStatus
{
    Invalid_Status,
    OK,
    Not_Isogram,
    Wrong_Length,
    Not_Lowercase
};



#endif /* FBullCowGame_hpp */

class FBullCowGame {
public:
    FBullCowGame(); //constructor
    
    int32 GetMaxTries() const;
    int32 GetCurrentTry() const;
    int32 GetHiddenWordLength() const;
    
    bool IsGameWon() const;
    EWordStatus CheckGuessValid(FString) const;
    
    void Reset();
    BullCowCount SubmitGuess(FString);
    
    
    //provide a method for counting bulls and cows and increasing turn number
    
private:
    //see constructor for initialization
    int32 MyCurrentTry;
    int32 MyMaxTries;
    FString MyHiddenWord;
    
    
};
