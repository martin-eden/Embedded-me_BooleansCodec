// Booleans codec test

/*
  Author: Martin Eden
  Last mod.: 2025-11-09
*/

#include <me_BooleansCodec.h>

#include <me_Console.h>

void RunWriteTest()
{
  Console.Print("( Booleans write test");
  Console.Indent();

  Console.Write("False: ");
  me_BooleansCodec::Write(false, Console.GetOutputStream());
  Console.EndLine();

  Console.Write("True: ");
  me_BooleansCodec::Write(true, Console.GetOutputStream());
  Console.EndLine();

  Console.Unindent();
  Console.Print(") Done");
}

void RunReadTest()
{
  const TUint_1 NumRuns = 3;
  TUint_1 RunNumber;
  TBool Bool;

  Console.Print("( Booleans read test");
  Console.Indent();

  Console.Write("We'll read");
  Console.Print(NumRuns);
  Console.Write("values from input and print their boolean value");
  Console.EndLine();

  for (RunNumber = 1; RunNumber <= NumRuns; ++RunNumber)
  {
    Console.Write("Value");
    Console.Print(RunNumber);
    Console.Write(":");

    if (!me_BooleansCodec::Read(&Bool, Console.GetInputStream()))
      Console.Write("Failed to parse it");
    else
    {
      if (Bool)
        Console.Write("true");
      else
        Console.Write("false");
    }

    Console.EndLine();
  }

  Console.Unindent();
  Console.Print(") Done");
}

void setup()
{
  Console.Init();
  RunWriteTest();
  RunReadTest();
}

void loop()
{
}

/*
  2025-11-09
*/
