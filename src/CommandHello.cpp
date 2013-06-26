CommandHello::~CommandHello()
{
  std::cout << "deleting a command hello";
}

std::string CommandHello::doGetCommand()
{
  return "hello";
}

std::string CommandHello::doGetDescription()
{
  return "Prints out hello";
}
