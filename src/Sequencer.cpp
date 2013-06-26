//#include <boost/thread.hpp> 
//#include <iostream> 

Sequencer::Sequencer ()
{ 
  running = true;
}

Sequencer::~Sequencer ()
{
  std::cout<<"destroying sequencer.";
}

void Sequencer::start()
{
  custardLogOut("Sequencer", "start", "started!");
  while (running){
    for (int i = 0; i < 5; ++i)
      {
	wait(1);
	//custardLogOut("Sequencer", "start", "tick");
      }
  }
}

void Sequencer::stop()
{
  running = false;
}

void Sequencer::wait(int seconds) 
{ 
  boost::this_thread::sleep(boost::posix_time::seconds(seconds)); 
} 

