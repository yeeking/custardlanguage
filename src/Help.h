class Help : public CommandListener {
 public:
  Help();
  ~Help();
 private:
  /** from the CommandListener Interface */
  void doSendCommand(std::string cmd);
};
