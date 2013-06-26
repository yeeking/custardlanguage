class Sequencer 
{
public:
  //  boost::thread getThread();
   /** start the sequencer */
   void start();
   /** stop the sequencer */
   void stop();
   /** set the command sequence */
   Sequencer();
   ~Sequencer();
private:
   void wait(int seconds);     
   bool running;
   //boost::thread sequencer_thread;
};
