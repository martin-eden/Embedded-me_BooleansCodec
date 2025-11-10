// Booleans text codec implementation

/*
  Author: Martin Eden
  Last mod.: 2025-11-10
*/

#include <me_BooleansCodec.h>

#include <me_BaseTypes.h>
#include <me_BaseInterfaces.h>
#include <me_StreamTools.h>
#include <me_StreamsCollection.h>
#include <me_WorkmemTools.h>
#include <me_StreamTokenizer.h>

using namespace me_BooleansCodec;

static const TAddressSegment
  TrueEncoding = me_WorkmemTools::FromAsciiz("Y"),
  FalseEncoding = me_WorkmemTools::FromAsciiz("N");

/*
  Write boolean to output stream
*/
TBool me_BooleansCodec::Write(
  TBool Value,
  IOutputStream * OutputStream
)
{
  me_StreamsCollection::TWorkmemInputStream DataStream;
  TAddressSegment DataSeg;

  if (Value)
    DataSeg = TrueEncoding;
  else
    DataSeg = FalseEncoding;

  DataStream.Init(DataSeg);

  return me_StreamTools::SaveStreamTo(&DataStream, OutputStream);
}

/*
  Read boolean from input stream
*/
TBool me_BooleansCodec::Read(
  TBool * Result,
  IInputStream * InputStream
)
{
  const TUint_1 BufferSize = 4;
  TUint_1 Buffer[BufferSize];
  TAddressSegment BuffSeg;
  me_StreamsCollection::TWorkmemOutputStream BuffStream;
  TAddressSegment DataSeg;

  BuffSeg = { .Addr = (TAddress) &Buffer, .Size = BufferSize };

  BuffStream.Init(BuffSeg);

  if (!me_StreamTokenizer::GetEntity(&BuffStream, InputStream))
    return false;

  DataSeg = BuffStream.GetProcessedSegment();

  if (me_WorkmemTools::AreEqual(DataSeg, TrueEncoding))
    *Result = true;
  else if (me_WorkmemTools::AreEqual(DataSeg, FalseEncoding))
    *Result = false;
  else
    return false;

  return true;
}

/*
  2025-11-09
*/
