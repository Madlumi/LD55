#pragma once
#include "util/mutil.h"


//tile map  
CI TS = 32; CI WW = 64; CI WH = 1024;
TFS{ V2 pos; V2 goal; V2 next; F ms;}minion;
TFS{ I type; }tile;
ARR(tile, map, WW*WH);
enum tile{ NONE, BLOCK, };
