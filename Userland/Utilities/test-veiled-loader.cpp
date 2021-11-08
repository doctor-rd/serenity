#include <AK/String.h>
#include <LibCore/Process.h>
#include <unistd.h>

int main(int, char**)
{
  unveil("/bin/About", "x");
  unveil(nullptr, nullptr);

  // This fails because it is not unveiled
  Core::Process::spawn("/usr/lib/Loader.so");

  // This works because the kernel is still allowed to execute Loader.so
  Core::Process::spawn("/bin/About");

  return 0;
};
