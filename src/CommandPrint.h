class CommandPrint : public Command 
{
public:
  ~CommandPrint();

private:
  std::string doGetCommand();
  std::string doGetDescription();
};
