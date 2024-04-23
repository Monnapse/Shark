"""
    Turn your html code into one line ready for Shark Rendering or other ESP applications.
    Made by Monnapse
    0.1.0
    
    python Shark.py path Path/To/Your/File.html
    or
    python Shark.py string test123"Test123"
"""

import sys

commands = []

def command(function):
    commands.append(function)

def r_cmd(args):
    args.pop(0)
    function_name = args.pop(0)

    arguments = []
    long_options = []

    for arg in args:
        if str.startswith(arg, "--"):
            long_options.append(arg)
        else:
            arguments.append(arg)

    for f in commands:
        if f.__name__ == function_name:
            
            f(*tuple(arguments))
            break

def start():
    r_cmd(sys.argv)

@command
def string(string: str):
    new_string = string.replace('\n', '\\n').replace('\t', '\\t').replace('\r', '\\r').replace('"', '\\"')
    print(new_string)
    return new_string

@command
def path(path: str):
    string = open(path, 'r').read()
    new_string = string.replace('\n', '\\n').replace('\t', '\\t').replace('\r', '\\r').replace('"', '\\"')
    print(new_string)
    return new_string

start()