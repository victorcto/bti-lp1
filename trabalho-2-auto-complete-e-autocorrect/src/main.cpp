#include "Database.hpp"
#include "Interface.hpp"
#include "Autocomplete.hpp"
#include "Autocorrect.hpp"
#include "Test.hpp"
using namespace std;

int main(int argc, char* argv[]){
    bool isTest = argc == 3;
    Interface* interface = new Interface();

    if(argc < 2){
        interface->argumentError();
        return EXIT_FAILURE;
    }
    
    std::string arg = argv[1];
    
    interface->setProgramName(arg);
    interface->setFileName(arg);

    Database* db = new Database(interface->getFileName());

    if(!db->readFile()){
        interface->printFileReadingErrorMessage();
        return EXIT_FAILURE;
    }

    Autocomplete* autocomplete = new Autocomplete(db);
    Autocorrect* autocorrect = new Autocorrect(db);
    while(!cin.eof()){
        if(!isTest)
        {
            if(!interface->askForUserInput()) continue;
            std::string userInput = interface->getUserInput();
            
            auto Vcomp = autocomplete->getAutocompleteSet(userInput);
            auto Vcorr = autocorrect->getAutocorrectSet(userInput, isTest);
            interface->printWordsContainer(Vcomp, Vcorr);    
        }
        else
        {
            auto tester = new Test(autocomplete, autocorrect, interface);
            tester->testApplication(); 

            delete tester;
            break;
        }
    }
    
    delete autocomplete;
    delete autocorrect;
    delete db;
    return 0;
}