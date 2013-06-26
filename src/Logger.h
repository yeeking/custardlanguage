/** Logger interface (virtual private interface/ template pattern). Implement this to provide a logging service */
class Logger 
{
 public:
  void log(std::string who, std::string what);
  virtual  ~Logger(){}
 private:
  virtual void doLog(std::string who, std::string what) = 0;
  boost::mutex log_mutex;
};
