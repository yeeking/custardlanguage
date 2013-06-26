class CommandHello : public Command 
{
public:
  ~CommandHello();

private:
  std::string doGetCommand();
  std::string doGetDescription();
};
