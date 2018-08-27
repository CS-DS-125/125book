# if_statement.py - How to branch to different sections of code
#
# Author: Mark Liffiton
#

def main():
    print("I [this program] am very smart.")
    print("I can tell you whether a number is larger or smaller than 5.")
    print()
    val = eval(input("Try me.  Enter a number: "))
    print()

    if val > 5:
        print(val, "is greater than 5!")
    else:
        print("Well, it's not greater than 5, but I need to check something...")
        if val < 5:
            print("Okay,", val, "is less than 5.")
        else:
            print("Ooh!  You entered 5!")

    # Be careful!
    # Equality checks have to use == (two equals signs),
    # because = (a single equals sign) is used for assignment!
    # We'll talk more about that later, if it seems odd to you now.
    if val == 42:
        print("42!")


main()

