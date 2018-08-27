# random_values.py - Example of using random.randint()
#
# Author: Mark Liffiton
#

# This is needed to use the randint function below.
# We're importing the module random, which contains
# a function we want to use.
import random

def main():
    print("Random numbers!")
    print("These will be different every time you run the program.")
    print()

    for i in range(10):
        # This is new!  We're calling the randint() function,
        # which lives inside a "module" called random.
        # We use the pattern <modulename>.<functionname>() to call
        # functions that are part of modules.
        value = random.randint(0,100)
        print(value)

    print()
    print("Remember, you can use the help function!  e.g. help(random.randint)")

main()

