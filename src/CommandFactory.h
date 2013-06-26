typedef std::map<std::string,Command*>::iterator CommandMapIterator;

class CommandFactory 
{
public:
  CommandFactory();
  ~CommandFactory();
  /** converts a string into the associated command object 
   */
  Command* getCommand(const std::string& command);
private:
  std::map<std::string, Command*> cmdDict;
};
