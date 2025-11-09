// Boolean values text coder-decoder

/*
  Author: Martin Eden
  Last mod.: 2025-11-09
*/

#pragma once

#include <me_BaseTypes.h>
#include <me_BaseInterfaces.h>

namespace me_BooleansCodec
{
  TBool Read(TBool * Result, IInputStream *);
  TBool Write(TBool Value, IOutputStream *);
}

/*
  2025-11-09
*/
