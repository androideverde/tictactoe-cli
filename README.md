# tictactoe-cli
C++ CLI tic-tac-toe game

## Generating the project
In order to build this on a Mac using XCode, you'll need to run the `./tictactoe-cli/generate_project.sh` script. After running it you'll find an XCode project file generated in `./tictactoe-cli/build/tictactoe-cli.xcodeproj`. Double-click on it to load the project into XCode.

## Building from the Command Line
Once the project is generated, you can build it without using XCode UI with the following command in a terminal from directory `./tictactoe-cli`:
```
  xcodebuild -project build/tictactoe-cli.xcodeproj -target tictactoe-cli -configuration Debug
```

## How to run the game
- From within XCode: Load the XCode project and launch the build
- From the Command Line: Launch the executable in `./tictactoe-cli/build/Debug/tictactoe-cli` built by XCode
