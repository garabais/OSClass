#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char **argv)
{
  int i;

  if(argc < 2){
    printf(2, "usage: kill pid...\n");
    exit();
  }
  for(i=1; i<argc; i++) {
	int pid = atoi(argv[i]);
	if (pid != 1) {
		kill(pid);
	} else {
		printf(2, "Kill init is forbidden\n");
	}
  }
  exit();
}
