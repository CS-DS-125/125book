# while_loops.py - An example of a while loop
#
# Author: Mark Liffiton
#

def main():
    print("A while loop!")
    i = 1
    val = 2
    while val < 1000:
        print(i, val)
        i = i + 1
        val = val * 2

    print("Why did it stop there?")

    print()

    print("Another while loop!")
    j = 0
    while j < 3:
        print(j)
        j = j + 1

    print("That one is less exciting, but more examples don't hurt!")

    print()

    print("You control this one.")
    k = 1
    while k > 0 and k < 1000:
        print("  You're stuck in a loop.")
        k = eval(input("  Enter a number to try to get out: "))
    print("You got out of the loop!")


main()

