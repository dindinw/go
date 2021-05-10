#include	"l.h"

char*	goroot;
char*	goarch;
char*	goos;


void
mywhatsys(void)
{
	char *s;

	goroot = getenv("GOROOT");
	goarch = getenv("GOARCH");
	goos = getenv("GOOS");

	if(goroot == nil) {
		s = getenv("HOME");
		if(s == nil)
			s = "/home/ken";
		goroot = mal(strlen(s) + 10);
		strcpy(goroot, s);
		strcat(goroot, "/go");
	}
	if(goarch == nil) {
		goarch = "amd64";
	}
	if(goos == nil) {
		goos = "linux";
	}
}



char*	hunk;
long	nhunk;
#define	NHUNK	(10UL<<20)

void*
mal(uint32 n)
{
	void *v;

	while(n & 7)
		n++;
	if(n > NHUNK) {
		v = malloc(n);
		memset(v, 0, n);
		return v;
	}
	if(n > nhunk) {
		hunk = malloc(NHUNK);
		nhunk = NHUNK;
	}

	v = hunk;
	nhunk -= n;
	hunk += n;

	memset(v, 0, n);
	return v;
}
