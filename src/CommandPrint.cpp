CommandPrint::~CommandPrint()
{
  std::cout << "deleting a command print";
}

std::string CommandPrint::doGetCommand()
{
  return "print";
}

std::string CommandPrint::doGetDescription()
{
  return "Print a message out to the console.";
}
