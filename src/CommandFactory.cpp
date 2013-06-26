CommandFactory::CommandFactory ()
{
  // initialise the set of known commands
  //pair<map<std::string,Command*>::iterator,bool> ret;
  Command* print;
  Command* hello;
  print = new CommandPrint();
  hello = new CommandHello();
  cmdDict.insert ( std::pair<std::string, Command*>(print->getCommand(),print));
  cmdDict.insert ( std::pair<std::string, Command*>(hello->getCommand(),hello));
}

CommandFactory::~CommandFactory()
{
  // iterate the command dictionary and delete the command objects
  CommandMapIterator it;    
  for ( it=cmdDict.begin() ; it != cmdDict.end(); it++ ) 
    {
      delete (*it).second;
    }

}

Command* CommandFactory::getCommand(const std::string& command)
{
  CommandMapIterator it;
  
  it = cmdDict.find(command);
  //it = cmdDict.find("print");
  if (it == cmdDict.end()){
    return 0;
    //return new CommandPrint();
  }
  else {
    return it->second;
  }
}
