/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic startup code for a JUCE application.

  ==============================================================================
*/

#include "JuceHeader.h"

StringArray getOptions (const StringArray& parameters)
{
    StringArray ret = parameters;
    ret.strings.removeIf (
        [](const String& str) -> bool {
            return !str.startsWith (StringRef ("--")) && !str.startsWith (StringRef ("-"));
        });
}

int main (int argc, char* argv[])
{
    StringArray args = JUCEApplicationBase::getCommandLineParameterArray();


    return 0;
}
