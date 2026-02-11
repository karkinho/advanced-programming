#include "actions/AddCommand.hpp"

AddCommand::AddCommand() {

}

AddCommand::~AddCommand() {
    delete recalculatePaths;
    delete removeCell;
}

void AddCommand::Execute() {
    
}