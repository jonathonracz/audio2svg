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
            return ! str.startsWith (StringRef ("-"));
        });
}

String retrieveArgumentForOption (const StringArray& parameters, const String& option)
{
    int argIndex = parameters.indexOf (option);
    jassert (argIndex >= 0);
    if (argIndex == parameters.size() - 1)
        return {};

    return parameters [argIndex + 1];
};

void retrieveIntForOption (const StringArray& parameters, const String& option, int& result)
{
    String argString = retrieveArgumentForOption (parameters, option);
    if (argString.isNotEmpty() && argString.containsAnyOf ("0123456789"))
        result = argString.getIntValue();
}

void printHelp()
{
    std::cout << "audio2svg - create an SVG vector from an audio file's waveform.\n\n"
              << "Options:\n"
              << "    --help    Print this help"
              << "    -i        Input audio file\n"
              << "    -o        Output SVG file\n"
              << "    [-w]      SVG frame width (default: 640)\n"
              << "    [-h]      SVG frame height (default: 480)\n"
              << std::flush;
}

int main (int argc, char* argv[])
{
    StringArray args = JUCEApplicationBase::getCommandLineParameterArray();
    StringArray options = getOptions (args);

    StringArray requiredOptions = { "-i", "-o" };
    for (const String& option : requiredOptions)
    {
        if (!options.contains (option))
        {
            std::cerr << "Missing required argument: " << option << std::endl;
            return 1;
        }
    }

    StringArray validOptions = { "-w", "-h", "--help" };
    validOptions.addArray (validOptions);
    for (const String& option : options)
    {
        if (!validOptions.contains (option))
        {
            std::cerr << "Unknown argument: " << option << std::endl;
            return 1;
        }
    }

    if (args.contains ("--help"))
        printHelp();

    File inputFile (retrieveArgumentForOption (args, "-i"));
    File outputFile (retrieveArgumentForOption (args, "-o"));

    int width = 640;
    retrieveIntForOption (args, "-w", width);

    int height = 480;
    retrieveIntForOption (args, "-h", height);

    return 0;
}
