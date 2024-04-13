#pragma once
#include "util/mutil.h"


//tile map 
CI TS = 32; CI WW = 160; CI WH = 160;
TFS{ V2 pos; V2 goal;}minion;
TFS{ I type; }tile;
ARR(tile, map, WW*WH);
enum tile{ NONE, BLOCK, };
