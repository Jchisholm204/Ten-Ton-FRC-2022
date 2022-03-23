
#include "commands/IndexCommands/Stop.hpp"


IndexCommands::Stop::Stop(IndexSubsystem* sys_index) : index{sys_index}{
  AddRequirements(sys_index);
}

// Called when the command is initially scheduled.
void IndexCommands::Stop::Initialize() {
  index->setTop(0);
  index->setBottom(0);
  index->setFeed(0);
}

bool IndexCommands::Stop::IsFinished(){
  return false;
}
