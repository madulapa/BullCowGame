#include "FBullCowGame.hpp"

using FString = std::string;
using int32 = int;

FBullCowGame::FBullCowGame()
{
    Reset();
}


int32 FBullCowGame::GetMaxTries() const
{
    return MyMaxTries;
}

int32 FBullCowGame::GetCurrentTry() const
{
    return MyCurrentTry;
}
int32 FBullCowGame::GetHiddenWordLength() const
{
    return MyHiddenWord.length();
}

bool FBullCowGame::IsGameWon() const
{
    return false;
}


EWordStatus FBullCowGame::CheckGuessValid(FString) const
{
    if (false)
    {
        return EWordStatus::Not_Isogram;
    }
    else if (false)
    {
        return EWordStatus::Not_Lowercase;
    }
    else if (Guess.length() != GetHiddenWordLength())
    {
        return EWordStatus::Wrong_Length;
    }
    else
    {
        return EWordStatus::OK;
    }
}
void FBullCowGame::Reset()
{
    constexpr int32 MAX_TRIES = 8;
     MyMaxTries = MAX_TRIES;
    
    const FString HIDDEN_WORD = "planet";
    MyHiddenWord = HIDDEN_WORD;
    
     MyCurrentTry = 1;
    
    return;
}

BullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
    MyCurrentTry++;
    int32 HiddenWordLength = MyHiddenWord.length();
    BullCowCount BullCowCount;
    
    for(int32 i = 0; i < HiddenWordLength; i++)
    {
        for(int32 j = 0; j < HiddenWordLength ; j++)
        {
            if(Guess[i] ==  MyHiddenWord[i])
            {
                if(i == j)
                    
                {
                    BullCowCount.Bulls++;
                }
                else
                {
                    BullCowCount.Cows++;
                }
            }
        }
    }
    
    return BullCowCount;
}

