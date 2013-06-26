/** Ncurses based GUI class which provides a four panel GUI. */
CursedInterface::CursedInterface()
{
  // curses setup
  initscr();
  cbreak();
  noecho();
  keypad(stdscr, TRUE);
  refresh();
  dataWindow = new CursedWindow("DATA", 10, 20, 0, 30);
  programWindow = new CursedWindow("PROGRAM", 10, 30, 0, 0);
  helpWindow = new CursedWindow("HELP", 6, 50, 10, 0);
  editorWindow = new CursedWindow("COMMAND", 3, 50, 16, 0);
  doupdate();
}

void CursedInterface::startEditor()
{
  //wgetch();
  int c;
  editorWindow->setEditable();
  std::string s;
  while(c = editorWindow->getChar() != '\n'){ 
    //setHelpText("test");
    //    if (commandListener!= 0){
    s = editorWindow->getContents();
    commandListener->sendCommand(s);
    //commandListener->sendCommand("testcmd");
    //setHelpText(editorWindow->getContents());
    // }
  }
  
}

CursedInterface::~CursedInterface()
{
  endwin();
  delete dataWindow;
  delete programWindow;
  delete editorWindow;
  delete helpWindow;
}

void CursedInterface::setHelpText(std::string text)
{
  helpWindow->setContents(text);
}


void CursedInterface::setProgramText(std::string text)
{
  programWindow->setContents(text);
}

void CursedInterface::setDataText(std::string text)
{
  dataWindow->setContents(text);
}

void CursedInterface::addCommandListener(CommandListener* listener)
{
  this->commandListener = listener;
}


/** private stuff */

void CursedInterface::returnCursorToEditWindow()
{
}

/** Logger interface implementation */

void CursedInterface::doLog(std::string who, std::string what)
{
  std::stringstream ss;
  ss << who << " said " << what; 
  setHelpText(ss.str());
}
