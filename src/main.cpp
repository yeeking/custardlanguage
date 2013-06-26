/**
 * Note that I use a unity build 
 * so everything is included here
 */
#include <iostream>
#include <string>
#include <map>

#include <stdio.h>  
#include <boost/thread.hpp> 
#include <boost/thread/mutex.hpp>
#include <panel.h>

#include "main.h"

#include "Logger.h"
#include "Command.h"
#include "CommandPrint.h"
#include "CommandHello.h"
#include "CommandFactory.h"
#include "CommandListener.h"
#include "Interpreter.h"
#include "Help.h"
#include "Sequencer.h"
#include "CursedWindow.h"
#include "CursedInterface.h"

#include "Logger.cpp"
#include "Command.cpp"
#include "CommandPrint.cpp"
#include "CommandHello.cpp"
#include "CommandFactory.cpp"
#include "CommandListener.cpp"
#include "Interpreter.cpp"
#include "Help.cpp"
#include "Sequencer.cpp"
#include "CursedWindow.cpp"
#include "CursedInterface.cpp"

CursedInterface* gui;
Sequencer* seq;
Interpreter* inter;

// used to protect thread unsafe io operations
boost::mutex io_mutex;

void startSequencer() 
{ 
  seq = new Sequencer();
  seq->start();
} 

void startInterpreter()
{
  inter = new Interpreter();
  inter->start();
  gui->addCommandListener(inter);
  inter->addLogger(gui);
}

void custardLogOut(std::string className, std::string method, std::string message)
{
  // this makes the call to cout thread safe
  boost::mutex::scoped_lock lock(io_mutex);
  std::cout << className << "::" << method << " " << message << "\r" << std::endl; 
}

void custardConsoleOut(char message)
{
  boost::mutex::scoped_lock lock(io_mutex);
  std::cout << message << std::flush;
}

int main ()
{
  //boost::thread* t1 = new boost::thread(startSequencer); 
  //  t1->join();
  
  // ** basis test
  setenv("TERM", "nsterm", 1);	
  gui = new CursedInterface();
  gui->setHelpText("Start typing!");
  boost::thread* t2 = new boost::thread(startInterpreter); 
  gui->startEditor();
  //t2->join();
  delete gui;
  delete t2;
   delete inter;
  //  ** end basic test

  // ** test the command fac
  // CommandFactory* fac = new CommandFactory();
  // Command* cmd = fac->getCommand("hello");
  // if (cmd!=0){
  //   std::cout << cmd->getDescription();
  // }
  // else {
  //   std::cout << "Invalid";
  // }
  // delete fac;
  // ** end test the command fac
  
}


