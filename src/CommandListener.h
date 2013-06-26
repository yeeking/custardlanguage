/** CommandListener interface / virtual template class thingy */
/** extende this if you want to receive commands, e.g. from the CustardShell */ 
class CommandListener {
 public:
  CommandListener();
  virtual ~CommandListener(){}
  void sendCommand(std::string& command);
 private:
  // this is the one to implement to receive commands
  virtual void doSendCommand(std::string& command) = 0;
};
