/** very simple wrapper for a double curses window. The outer window 
 * shows the title and border. The inner window shows the textual contents.
 * This allows the separation of window contents from window display
 */
class CursedWindow {
 public:
  CursedWindow(std::string title, int rows, int cols, int y, int x);
  ~CursedWindow();
  std::string getContents();
  /** retrieve complete window contents*/
  void setContents(std::string text);
  /** prepare the window for being typed into */
  void setEditable();
  /** retrieve a single, non control charater from the user 
   * if the user types in cursor keys or delete keys
   * then automatically edit the buffer
   */
  int getChar();
  void putChar(int ch);
 private:
  WINDOW* displayWindow;
  WINDOW* contentWindow;  
  std::string title;
  /** when editing, remember where we see spaces so can
   update the text appropriately */
  int lastSpaceX;
  int rows;
  int cols;
  /** used when returning the contents of the window */
  char content[1024];
  int cursorX;
  int cursorY;
};
