# PIPEX

Pipex is a 42 school project aimed to better understand shell redirection and pipes, by handling them in C.

This pipex program takes an input file, performs a command on it, pipes the result to another command which then writes its result to an output file. The result is virtually identical to this kind of shell command:
```
$ < input_file command1 | command2 > output file
```

## Usage
To compile, use ```make```, ```make all``` or ```make bonus```.

### Regular pipex execution
Pipex can handle 2 or more commands. To execute:

```
$ ./pipex input_file command1 command2 ... commandn output_file
```
The output will be written to the specified output file. If the output file exists, it will be overwritten. This replicates the shell command:
```
$ < input_file command1 | command2 | ... | commandn > output_file
```

Each command can be given arguments and options if surrounded by quotation marks. For example:
```
$ ./pipex example.txt "cat" "grep x" "sed s/l/.../g" outfile.txt
```
