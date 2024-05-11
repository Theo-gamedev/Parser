# File parser

This repository contains a simple parser that I made during my first year of programming studies.

## Features

This parser read a text file and store the chosen part of its content in a map.
The key is the name of the property given in the file.

One file can contain multiple part. There are defined by their name between square brackets.

The file must be formatted like this:
```
[part1]
{
	property1 = value1
	property2 = value2
	property3 = value3
}
[part2]
{
	property1 = value1
	property2 = value2
	property3 = value3
}
```

## Installation

To use this project, follow these steps:

1. Clone the repository: `git clone https://github.com/your-username/your-repo.git`
2. Run the project: `Parsing`

## Usage

To use this project, add the Parser.h and Parser.cpp files to your project and include the Parser.h file in your source code.

```cpp
#include "Parser.h"

int main()
{
	Values data("FileName.txt", "ObjectName");
	
	// print the content of the map
	for (auto [_key, _value] : data.GetMap())
	{
		std::cout << _key << " " << _value << "\n";
	}


	return 0;
}
```
in this example, the file FileName.txt contains the following content:
```
[ObjectName]
{
	property1 = value1
	property2 = value2
	property3 = value3
}
```

For more information, see the project example where I use this parser to read a sprite configuration file.
I show how to use the parser to read the file and how to use the data to initialize an object.
