Interpreter::Interpreter()
{
  running = true;
  cmdFac = new CommandFactory();
}

Interpreter::~Interpreter()
{
  delete cmdFac;
}

/** implementation of the CommandListener Interface */
void Interpreter::doSendCommand(std::string& command)
{
  // check for a space at the end. Only interpret then
  interpret(command);
}


void Interpreter::start()
{
  //custardLogOut("Interpreter", "start", "started!");
  
}

void Interpreter::stop()
{
  running = false;
  // Reset terminal to normal "cooked" mode 
  //system("stty cooked"); 
}

void Interpreter::addLogger(Logger* logger)
{
  this->logger = logger;
}

// private stuff
void Interpreter::interpret(std::string& command)
{
  Command* cmd0;
  bool hasSpace = false;
  if (command[command.length() - 1] == ' '){// ends with a space
    hasSpace = true;
  }
  prepString(command);
  cmd0 = cmdFac->getCommand(command);
  if (logger){
    ///logger->log("I::i", "'"+cmd+"'");
    if (cmd0!=0){
      logger->log("inter:", cmd0->getDescription());
      if (hasSpace){ 
	// we have a valid command ending with a space
	// add it to the command tree
	
      }
    }
    else {
      logger->log("Int::int", "invalid");
    }
  }

  // iterate the commands in the cmd string

  // look each one up in the known commands list

  // call execute on the command

  // collect an error as well, for unknown commands

  // that's the end of the line for the command
  //delete cmd;
}

void Interpreter::prepString(std::string& input)
{
  size_t pos;
  pos = input.find_first_of(' ', 0);
  if (pos != -1){// did find a space
    //logger->log("int:prep", "found a space, trimming ");
    input.erase(pos, input.length()-1);
  }
}
