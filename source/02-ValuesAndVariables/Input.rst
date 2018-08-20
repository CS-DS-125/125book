
.. index:: input statement

Input
-----

So far, every program we've seen and run will do the exact same thing every
time it runs.  Most useful programs *don't* do the same thing every time
because they operate with some kind of **input**.  That is, when the program
runs, it takes in information from outside of itself and uses that
information to change how it runs.  By using input, a program can solve a
variety of problems without having to change the code itself.

For example, look at the :ref:`example program <operators_example>` from the
previous section.  It would be more useful if it asked the user 
for the number of days to convert each time it runs.

Python has a built-in function called ``input()`` that provides a way to get
user input.  The ``input()`` function allows the programmer to provide a
**prompt string** in the code. When the program is run, the prompt is display.
Whatever the user then types (followed by pressing *Enter*) is returned by
the function to and can be used by the program. 

.. admonition:: Syntax Pattern

   ``input()`` is most frequently used in **input statements** with
   the following form:

   ::

      <variable> = input("<prompt>")

   See how this is an example of :ref:`variable assignment
   <assignment-statement>`?  This will take the string of characters typed in
   by the user after the prompt and assign it to the given variable.

Try running the following example a number of times, typing different things in
the input box that appears each time.

.. activecode:: input01

    name = input("Please enter your name: ")
    print("Hello,", name)

One critical detail of the ``input()`` function is that it returns a **string**
value.  Even if you asked the user to enter their age, you would get back a
string like ``"19"``.  If you want to use that as a number in your program
(e.g., if you want to do arithmetic with it), you have to convert it into the
appropriate type using the ``int()`` or ``float()`` functions we saw earlier in
:ref:`type-conversion-functions`.  The following code runs, but it doesn't do
what you might expect (another *semantic error*).  Try fixing it so it runs
correctly:

.. activecode:: input02

   age = input("What is your age in years? ")
   days = age * 365
   print("That is", days, "days!")

Often we put the conversion function in the input statement itself.
Here, in a corrected version of the above example, the first line of the
program both asks for user input and converts that input to an ``int``:

.. activecode:: input03

   age = int(input("What is your age in years? "))
   days = age * 365
   print("That is", days, "days!")

.. caution::

   But watch out!  Try running the above code and type in something that
   *isn't* an integer.  
   
   Code that needs to work correctly in all cases without
   crashing has to do more work to check for such errors and handle them
   gracefully.  Starting out, your code will probably not include much error
   checking, so you should be careful to provide appropriate inputs when you
   run it.

If we want to modify the example from the previous section to be more useful,
then we need to add an input statement.  Here, we've separated out the type
conversion from the input statement to make the addition more explicit:

.. activecode:: input_example

   str_days = input("Please enter the number of days you wish to convert: ")
   days = int(str_days)

   # Convert days to hours
   hours = days * 24
   # Convert hours to minutes
   minutes = hours * 60
   # Convert days to *whole* weeks
   weeks = days // 7
   # Find the remainder as remaining days
   remaining_days = days % 7

   # Print our results
   print(days, "days is:")
   print(hours, "hours")
   print(minutes, "minutes")
   print(weeks, "weeks and", remaining_days, "days")

In the program above, the variable ``str_days`` refers to the string
that is entered by the user. Even though this string may be ``100``,
it is still a string of characters ('1', '0', and '0') and not a
number when it is entered by the user.

To convert it to an integer, we use the ``int()`` function.
The result is stored in the ``days`` variable.
Now, each time you run the program, you can enter a new value 
for the number of days to be converted.

