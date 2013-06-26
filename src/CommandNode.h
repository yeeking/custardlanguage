/** represents a node in the CommandTree. Each node is linked to its parent node and one or two  
 * following nodes
 */
class CommandNode 
{
 public:
  CommandNode(Command* command);
  ~CommandNode();
  /** return the node which precedes this one */
  CommandNode* getPrevious();
  /** return the next node. The next node is selected by running the
      tests associated with the available nodes and returning node with the positive result. 
   */
  CommandNode* getNext();
  /** Set the node which succeeds this one. test should be a test, which if it is true, 
   * causes this node to be returned by getNext()
   */
  void setNext(CommandNode* node);
  /** Set the node which precedes this one
   */
  void setPrevious(CommandNode* node);
  /** execute the test associated with this node and return the result */
  bool doTest();
 private:
  //TestFunctor test;
  //CommandFunctor func;
  Command* command;
  CommandNode* previous;
  CommandNode* nextLeft;
  CommandNode* nextRight;
};
