/** Ncurses based GUI class which provides a four panel GUI. 
 * Also implements the Logger interface so it can log errors etc.
*/
class CursedInterface : public Logger 
{
public:
  CursedInterface();
  ~CursedInterface();
  /** update the help text window with the sent string */
  void setHelpText(std::string text);
  /** update the contents of the program list window */
  void setProgramText(std::string text);
  /** update the contents of the data window which will typically
      change as the result of a command */
  void setDataText(std::string text);
  /** add a listener to notify when text is entered to the editor window */
  void addCommandListener(CommandListener* listener);
  /** starts reading chars from the editor window*/
  void startEditor();
 private:
  CommandListener* commandListener;
  //WINDOW* windows[4];
  CursedWindow* dataWindow;
  CursedWindow* programWindow;
  CursedWindow* editorWindow;
  CursedWindow* helpWindow;
  void returnCursorToEditWindow();
  /** from the Logger interface */
  void doLog(std::string who, std::string what);
};
