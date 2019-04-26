#include "root.h"
#include "cpp.h"

/*
This class just adds a 'pattern' constructor to TChain
TChain::TChain(const char* name, const char* pattern)
will use `ls pattern` to find all files matching pattern. 
If they are root files, and if the contain a tree named name, 
this tree will be chained to this.
*/
void Chain(const char*, const char*, TChain*);
