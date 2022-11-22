//  main.cpp
//  CurrencyConverter
//  Created by mwcsur on 5/14/22.
//

#include <iostream>
#include <filesystem>
//using namespace std;


void printWelcomeMenu();

void printMainMenu();

void print(std::string);

int getUserInput();

bool processInput(int in);

int main(int argc, const char * argv[]) {
    int userIn=0;
    bool go=true;
    //main loop
    while(go){
    
        //print welcome menu
        printWelcomeMenu();
        
        printMainMenu();
    
        //get user input
        userIn=getUserInput();
    
        //process input
        go=processInput(userIn);

    }
    
    return 0;
}

bool processInput(int in){
    bool done=false;
    switch (in) {
        case 1:
        {
            print("Getting USD Rates");
            print(std::filesystem::current_path());
            int res = system("/usr/bin/python3  /Users/darianlopez/Documents/CurrencyConverter/CurrencyConverter/CurrencyConverter/main.py USD");
            done=true;
            break;
        }
        case 2:
        {
            print("Getting CAD Rates");
            int res = system("/usr/bin/python3  /Users/darianlopez/Documents/CurrencyConverter/CurrencyConverter/CurrencyConverter/main.py CAD");
            done=true;
            break;
        }
        case 3:
        {
            print("Getting JPY Rates");
            int res = system("/usr/bin/python3  /Users/darianlopez/Documents/CurrencyConverter/CurrencyConverter/CurrencyConverter/main.py JPY");
            done=true;
            break;
        }
        case 4:
        {
            print("Getting GBP Rates");
            int res = system("/usr/bin/python3  /Users/darianlopez/Documents/CurrencyConverter/CurrencyConverter/CurrencyConverter/main.py GBP");
            done=true;
            break;
        }
        case 5:
        {
            print("Getting AUD Rates");
            int res = system("/usr/bin/python3  /Users/darianlopez/Documents/CurrencyConverter/CurrencyConverter/CurrencyConverter/main.py AUD");
            done=true;
            break;
        }
        case 6:
            print("GoodBye");
            done=true;
            break;
            
        default:
            break;
    }
    
    return done;
}

void printWelcomeMenu(){
    print("\nWelcome To the Currency Converter.\nPlease Choose From the Options Below!\n");
}


void printMainMenu(){
    print("1---USD\n2---CAD\n3---JPN\n4---GPB\n5---AUD\n6---Quit\n");
}

int getUserInput(){
    std::cout<<"Enter a choice: "<<std::endl;
    int choice =-1;
    std::cin >> choice;
    return choice;
}

void print(std::string str){
    std::cout<<str<<std::endl;
}

