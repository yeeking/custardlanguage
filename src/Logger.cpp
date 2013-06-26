void Logger::log(std::string who, std::string what)
{
  boost::mutex::scoped_lock lock(log_mutex);
  doLog(who, what);
}
