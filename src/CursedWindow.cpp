CursedWindow::CursedWindow(std::string title, int rows, int cols, int y, int x)
{
  this->title = title;
  displayWindow = newwin(rows, cols, y, x);
  contentWindow = newwin(rows-2, cols-2, y+1, x+1);
  box(displayWindow, 0, 0);
  mvwprintw(displayWindow, 0, 1, title.c_str());
  wrefresh(displayWindow);
  wrefresh(contentWindow);
  this->rows = rows;
  this->cols = cols;
}

CursedWindow::~CursedWindow()
{
  delwin(contentWindow);
  delwin(displayWindow);
}

void CursedWindow::setEditable()
{
  keypad(contentWindow, TRUE);
  wmove(contentWindow, 0, 0);
  //wrefresh(windows[2]);
}

int CursedWindow::getChar()
{
  int c, width, height, distFromSpace;
  c = wgetch(contentWindow);
  getyx(contentWindow, cursorY, cursorX);
  getmaxyx(contentWindow, height, width);
  switch(c){
  case KEY_DC:
    waddch(contentWindow, 'x');
    break;
  case KEY_DOWN:
    wmove(contentWindow, cursorY+1, cursorX);
    break;
  case KEY_UP:
    wmove(contentWindow, cursorY-1, cursorX);
    break;
  case KEY_LEFT:
    wmove(contentWindow, cursorY, cursorX-1);
    break;
  case KEY_RIGHT:
    wmove(contentWindow, cursorY, cursorX+1);
    break;
  case KEY_BACKSPACE:
    wmove(contentWindow, cursorY, cursorX-1);
    wdelch(contentWindow);
    break;
   case ' ':
     lastSpaceX = cursorX;
  //   waddch(contentWindow, '\n');
     //waddch(contentWindow, c);
  default:
    if (cursorX < width-1){
      waddch(contentWindow, c);
    }
    else {
      distFromSpace = cursorX - lastSpaceX;
      // need to drop the text down at the last space
      // wmove(contentWindow, y, lastSpaceX);
      // waddch(contentWindow, '\n');
      // wmove(contentWindow, y+1, lastSpaceX+distFromSpace);
      waddch(contentWindow, c);
      
    }
    break;
  }
  return c;
}

void CursedWindow::putChar(int ch)
{
  waddch(contentWindow, ch);
  wrefresh(contentWindow);
}


std::string CursedWindow::getContents()
{
  //std::stringstream s; 
  int read;
  std::string str;
  const char* tempC;
  // point the constant char at the buffer
  tempC = content;
  // remember where we are in the curses window
  getyx(contentWindow, cursorY, cursorX);
  // read from the window into the char buffer
  read = mvwinnstr(contentWindow, 0, 0, content, 1024);
  // copy from the char buffer into the string
  str.reserve(read);
  str.assign(tempC, read);
  //return contents.str();
  wmove(contentWindow, cursorY, cursorX);  
  return str;
}

void CursedWindow::setContents(std::string text){
  
  werase(contentWindow);
  mvwprintw(contentWindow, 0, 0, "%s", text.c_str());
  wrefresh(contentWindow);

}
  
