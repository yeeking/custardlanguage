CommandListener::CommandListener ()
{
}

void CommandListener::sendCommand(std::string& command)
{
  doSendCommand(command);
}
