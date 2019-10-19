#include <iostream>
#include <string>
#include "FBullCowGame.hpp"

using FText = std::string;
using int32 = int;

    void PrintIntro();
    FText GetGuess();
    void PlayGame();
    bool AskPlayAgain();

 FBullCowGame BCGame;

int main()
{
    bool WantsPlayAgain = false;
    do
    {
    PrintIntro();
    PlayGame();
    WantsPlayAgain = AskPlayAgain();
    }
    while(WantsPlayAgain == true);
    
    return 0;
}

void PrintIntro()
{
    //loop for the number of turns asking for guesses
   //constexpr int32 NUMBER_OF_TURNS = 5;
    std::cout << "Welcome to Bulls and Cows, a fun wordgame\n";
    std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
    std::cout << " letter isogram i am thinking of?\n";
    std::cout << std::endl;
    
    return;
}



FText GetValidGuess()
{
    EWordStatus Status = EWordStatus::Invalid_Status;
    {
        int32 CurrentTry = BCGame.GetCurrentTry();
        FText Guess = "";
        std::cout << "Try " << CurrentTry;
        std::cout << "Take a guess: ";
        std::getline(std::cin, Guess);
        return Guess;
        
        
        EWordStatus Status = BCGame.CheckGuessValid(Guess);
        switch (Status)
        {
            case EWordStatus::Wrong_Length:
                std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n";
                break;
            case EWordStatus::Not_Isogram:
                std::cout << "Please enter a word without repeating letters.\n";
                break;
            case EWordStatus::Not_Lowercase:
                std::cout << "Please enter an all lowercase word";
                break;
            default:
                return Guess;
        }
        std::cout << std::endl;
    }
    while(Status == EWordStatus::OK);
}


void PlayGame()
{
    BCGame.Reset();
    int32 MaxTries = BCGame.GetMaxTries();
   
    //loop for num turns asking for guesses
    //TODO change FOR to WHILE once validating tries
    
    for(int32 i = 0; i <= MaxTries ; i++)
    {
        FText Guess = GetValidGuess(); //TODO check loop validity
        
      
        //submit valid guess to game
        BullCowCount BullCowCount =  BCGame.SubmitGuess(Guess);
        
        //Print nums of bulls and cows
        std::cout << "Bulls =  " << BullCowCount.Bulls;
        std::cout << "Cows =  " << BullCowCount.Cows;
        std::cout << std::endl;
    }
}

bool AskPlayAgain()
{
    std::cout << "Do you want to play again? (y/n) ";
    FText Response = "";
    ;
    std::getline(std::cin, Response);

   return (Response[0] == 'y') || (Response[0] == 'Y');
    
}


