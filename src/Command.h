/** This interface represents a command in the custard language 
 * Implementing classes should override the virtual private methods and the virtual constructor
 */

/*
* It uses the template method of defining interfaces
* Here is a well argued case for the 'template method' of defining interfaces
* where the public interface of a base class is non-virtual
* and the implementationa of the interface methods in the base class
* call private functions which are defined as virtual
*
* http://www.gotw.ca/publications/mill18.htm
*/
class Command 
{
public:
  std::string getCommand();
  std::string getDescription();
//  int execute();
  virtual ~Command(){}

private: 
  virtual std::string doGetCommand() = 0;
  virtual std::string doGetDescription() = 0;

};
