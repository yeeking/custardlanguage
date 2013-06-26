/** The main language interpreter class. */
class Interpreter : public CommandListener
{
public:
   /** start the interpreter */
   void start();
   /** stop the  interpreter */
   void stop();
   void addLogger(Logger* logger);
   /** set the command sequence */
   Interpreter();
   ~Interpreter();
 private:
   Logger* logger;
   CommandFactory* cmdFac;
   bool running;
   void interpret(std::string& cmd);
   /** receive a command */
   void doSendCommand(std::string& command);
   /** prepare the sent string for interpreting e.g. remove white space from either end */
   void prepString(std::string& input);
};
