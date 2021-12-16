<h1 align ="center">
    C++ Note
</h1>

https://code.visualstudio.com/docs/cpp/config-linux

https://zhuanlan.zhihu.com/p/394595507

## Use VS Code to build a project
###  folder concists
tasks.json(compiler build settings)

launch.json(debugger settings)

c_cpp_properties.json(compiler path adn IntelliSense settings)

### build process
1.Terminal>Configure Defaulf Build Task
2.C/C++: g++ build active file
- 2.1 get tasks.json in .vscode folder
  
  The command setting specifies the program to run; in this case that is g++. The args array specifies the command-line arguments that will be passed to g++. These arguments must be specified in the order expected by the compiler.

  This task tells g++ to take the active file ({file}), compile it, and create an executable file in the current directory ({fileDirname}) with the same name as the active file but without an extension (${fileBasenameNoExtension}), resulting in helloworld for our example.

  The label value is what you will see in the tasks list; you can name this whatever you like.

  The "isDefault": true value in the group object specifies that this task will be run when you press Ctrl+Shift+B. This property is for convenience only; if you set it to false, you can still run it from the Terminal menu with Tasks: Run Build Task
```
{
	"version": "2.0.0",
	"tasks": [
		{
			"type": "cppbuild",
			"label": "C/C++: g++ build active file",
			"command": "/usr/bin/g++",
			"args": [
				"-fdiagnostics-color=always",
				"-g",
				"${file}",
				"-o",
				"${fileDirname}/${fileBasenameNoExtension}"
			],
			"options": {
				"cwd": "${fileDirname}"
			},
			"problemMatcher": [
				"$gcc"
			],
			"group": {
				"kind": "build",
				"isDefault": true
			},
			"detail": "compiler: /usr/bin/g++"
		}
	]
}
 ``` 

- 2.2 Run the build after modifying the task.json
  
  Terminal>configure Default Build Task:create task.json:tell VS Code how to build(compile),It can be modified where to save and execute file name

  Next build task, press Ctrl+Shift+B or Terminal>Run build Task
  Then we get launch.json:debugger setting

  Done! ./XXX to execute

modifying multiple .cpp files:

"${workspaceFolder}/*.cpp" instead of ${file}

change output file name:

${fileBasenameNoExtension} XXXX.out


## Debug
If I want to debug other than execute without debugger:
Run>Add Configuration...>C++(GDB/LLDB)>g++ build and debug active file

Get the launch.
```
{
  "version": "0.2.0",
  "configurations": [
    {
      "name": "g++ build and debug active file",
      "type": "cppdbg",
      "request": "launch",
      "program": "${fileDirname}/${fileBasenameNoExtension}",
      "args": [],
      "stopAtEntry": false,
      "cwd": "${workspaceFolder}",
      "environment": [],
      "externalConsole": false,
      "MIMode": "gdb",
      "setupCommands": [
        {
          "description": "Enable pretty-printing for gdb",
          "text": "-enable-pretty-printing",
          "ignoreFailures": true
        }
      ],
      "preLaunchTask": "g++ build active file",
      "miDebuggerPath": "/usr/bin/gdb"
    }
  ]
}
```
program:specify the program you want to debug
And the others like the defination in task.json.

stopAtEntry:set to true to stop on the main method when you start debugging

## basic cheat key
Tab: select IntelliSence recommand list member