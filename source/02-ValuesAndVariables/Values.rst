
.. index:: value, data, data type, type, integer, string, floating point
   single: type; str
   single: type; int
   single: type; float

Values and Data Types
---------------------

Computers, and the programs that direct them, operate on **data**.  Data is
information.  When the example program from the previous chapter reads in text
from a file, that text is data.  Each word it extracts from that text is a
piece of data.  The number it calculates, counting the number of words starting
with a given letter, is data.  That letter itself is data.

Storing and manipulating data is at the heart of everything a computer can do.
In order to write programs, then, we will have to learn how to tell the
computer to store and manipulate data.  We'll start with individual pieces of
data.

In programming, we use the word **value**, rather than data or datum, to talk
about a specific piece of information -- like a word or a number -- that a
program works with.  A few values we have seen so far are ``0``, ``1``, and
``"Hello, World!"``.

There are many kinds of data.  You might already have noticed that ``1`` is a
very different kind of thing than ``"Hello, World!"``.  Therefore, values are
classified into different **data types**.

``'Cat'`` is text information. The text data type is called **string**, because
text is a string, or sequence, of characters.  In Python, strings are always
enclosed in quotations marks, like this: ``'Cat'``, or this ``"Cat"``.

``93`` is numeric information. There are a few different numeric data types.
This particular value is an example of the **integer** data type.

A value's data type controls what the computer can do with that value.  Because
``'Cat'`` is a string and ``93`` is an integer, certain kinds of actions (what
we will call 'operations') make sense with one but not with the other.  For
example, if we try to divide two strings we get an error.

.. activecode:: types01

   print("Cat" / "Dog")

On the other hand, dividing two integers is an action the computer *can* perform:

.. activecode:: types02

   print(81 / 9)

If you are not sure what the type of a particular value is, the ``type()``
function can tell you:

.. activecode:: types03

   print('The type of "Hello, World!" is:')
   print(type("Hello, World!"))
   print('The type of 17 is:')
   print(type(17))
   print('The type of "17" is:')
   print(type("17"))

   # Try writing a line of code here to find the type of 123.45

Not surprisingly, strings belong to the type ``str`` and integers belong
to the type ``int``.  Less obviously, numbers with a decimal point belong to a
type called ``float``, because these numbers are stored in the computer in a
format called *floating point*.

.. activecode:: types04

   print('The type of 123.45 is:')
   print(type(123.45))

What about values like ``"17"`` and ``"123.45"``? They look like numbers, but they
are in quotation marks like strings.

.. activecode:: types05

   print('The type of "17" is:')
   print(type("17"))
   print('The type of "123.45" is:')
   print(type("123.45"))

They’re strings!  It's important to understand and remember that ``"17"`` and
``17`` are *very* different things to Python.

Strings
^^^^^^^

We have used two different kinds of quotation marks to create strings: single
``'`` and double ``"``.  Python will take whatever follows a quotation mark as
the contents of a string up until it finds a matching quotation mark.  Strings
enclosed in one kind of quote symbol can *contain* the other kind.  For example
single quotations ``'`` can be wrapped in double ``"`` and double ``"`` can be
wrapped in single.

.. activecode:: stringvals01

   print("This is a string.")
   print('This is also a string.')
   print("I'm okay with this string's apostrophes.")
   print('And this string quotes the earlier, "This is a string."')

What do you think will happen if a string contains a quotation mark of the same
kind that encloses it?

.. activecode:: stringvals02

    print('I'm a string!')
    print("What happens in this "odd" case?")

These produce syntax errors because the quotation mark that we want to be
inside the string actually ends the string, and then the rest of the line is
invalid Python syntax. See if you can get the code above to work by changing
the type of quotation marks used.

.. index::
   single: string; escaping

There is another way to fix this issue. To include a quote character 
that is the same as the one used to start and end the string, the character 
can be **escaped** by putting a backslash ``\`` in front of it, as in ``"The string
\"four\" is four characters long."``.

.. activecode:: stringvals03

    print('Okay, so \'this\' works.')

Escaping with backslashes is used in many instances when we want Python to read
something as text, not just with quotation marks.

And by the way: since strings are sequences of characters, and emoji are
just sequences of characters...

.. activecode:: stringvals04

   print('My password is ✓🐎🔋✂😕')


Numbers
^^^^^^^

When you type a large integer, you might be tempted to use commas between
groups of three digits, as in 1,000,000. This is not a valid *integer* in
Python, but it is valid syntax:

.. activecode:: numbers01

   print(1,000,000)

Well, that’s not what we expected at all! Python interprets ``1,000,000`` as
three comma-separated integers, which it prints with spaces between.

.. note::

   The ``print()`` function will print as many different values as you give it,
   as long as they are separated by commas.  The values will be separated by
   spaces in the output.

   For example:

   ::

      >>> print("Hello, World!", 1, 2, 123.45)
      Hello, World! 1 2 123.45

.. index:: semantic error, error message
   single: error; semantic

This is the first example we have seen of a **semantic error**: the code is
*syntactically* valid and runs without producing an error message, but it
doesn’t do what we *thought* or *wanted* it to do.  In this case, Python's rule
about what commas mean doesn't exactly match what we might assume about them
based on using commas in everyday writing.

.. caution::

   Programming languages are formal languages with strict, precise rules about
   what is valid code and what that code means.  The computer will do exactly
   what you tell it to do... so be careful about what you tell it to do!

   
.. index:: int(), float(), str(), truncation
   single: type; conversion

.. _type-conversion-functions:

Type Conversion Functions
^^^^^^^^^^^^^^^^^^^^^^^^^

Often data is in one form and we need it in another.  For example, if a data
set is stored in a text format, every value will be stored as a string even if
it is really numeric data.  Python provides a few **type conversion**
functions that will *attempt* to convert data from one type into another.  Each
of the three data types we've seen so far has a matching function that converts
into that type:

- ``int()``
- ``float()``
- ``str()``

The ``int()`` function can convert a floating point number or a string into an
int.  When given a floating point number, it *discards* the decimal portion of
the number, called *truncation towards zero* on the number line.  For example:

.. activecode:: typeconv01

    print("Printing values of different types & their conversion to ints.")
    print('The float 3.0 converts to', int(3.0))
    print('The float 3.14 converts to', int(3.14))
    
    # This following does *not* round to the closest int!
    print('The float 3.9999 converts to', int(3.9999))  
    
    # Note that the result is closer to zero
    print('The float -3.999 converts to', int(-3.999))
    
    # A string can also produce an int
    print('The string "2345" converts to', int("2345")) 

Python won't always succeed in converting from one data type to another.

.. activecode:: typeconv02

    # What will this do?
    print('"23bottles"', int("23bottles"))

The error shows that a string given to ``int()`` has to 
be a syntactically valid integer.  Anything else will cause an error.

The ``float()`` function converts an integer, float, or syntactically valid
string into a float.

.. activecode:: typeconv03
    :nocanvas:

    print("Printing values of different types & their conversion to floats.")
    print('The integer 123 converts to', float(123))
    print('The string "123" converts to', float("123"))
    print('The string "123.45" converts to', float("123.45"))
    print('The float 123.45 converts to', float(123.45))

And finally, ``str()`` can convert just about anything into a string.  The
applications of this are a bit less common, but it's worth remembering it
exists.

.. admonition:: Check your understanding

   .. fillintheblank:: cyu_values01

      For each value, write its type - int, float, or str - to the right.

      ``1234``: |blank|

      ``12.34``: |blank|

      ``"1234"``: |blank|

      ``'12.34'``: |blank|

      ``"Hello, 1234!"``: |blank|

      -   :int: Correct.
          :<class 'int'>: That's technically right, but we usually just say or write ``int``.
          :x: Incorrect.  Re-read above about data types.
      -   :float: Correct.
          :<class 'float'>: That's technically right, but we usually just say or write ``float``.
          :x: Incorrect.  Re-read above about data types.
      -   :str: Correct.
          :string: Correct, but the type is formally called ``str``.
          :<class 'str'>: That's technically right, but we usually just say or write ``str``.
          :x: Incorrect.  Re-read above about data types.
      -   :str: Correct.
          :string: Correct, but the type is formally called ``str``.
          :<class 'str'>: That's technically right, but we usually just say or write ``str``.
          :x: Incorrect.  Re-read above about data types.
      -   :str: Correct.
          :string: Correct, but the type is formally called ``str``.
          :<class 'str'>: That's technically right, but we usually just say or write ``str``.
          :x: Incorrect.  Re-read above about data types.

   .. mchoice:: cyu_values02
      :multiple_answers:
      :answer_a: 'Average'
      :answer_b: '"Cheese!", she exclaimed.'
      :answer_c: 'Euler's Identity'
      :answer_d: '👁️❤️🐍'
      :answer_e: "Hello, World!"
      :correct: a,b,d,e
      :feedback_a: Nothing wrong with this one.
      :feedback_b: Strings can contain quotation marks that aren't the same as the marks delimiting (surrounding) the string.
      :feedback_c: Strings cannot contain qutation marks that are the same as the marks delimiting (surrounding) the string unless they are escaped (see above).
      :feedback_d: Emoji (or more broadly, Unicode characters) are allowed.
      :feedback_e: A classic string.

      Which of the following are valid strings in Python?  (Mark all that are correct.)

   .. fillintheblank:: cyu_values03

      For each type conversion function call, write the value it will produce to the right.

      ``int(1234)``: |blank|

      ``int(8.8)``: |blank|

      ``float("1234")``: |blank|

      ``float(42.42)``: |blank|

      -   :1234: Correct.
          :x: Incorrect.  Applying ``int()`` to an integer will produce the same value, unchanged.
      -   :8: Correct.  
          :9: Incorrect.  ``int()`` doesn't round to the nearest integer; it always rounds down.
          :x: Incorrect.  See above to review type conversion functions.
      -   :1234.0: Correct.
          :1234: Almost, but written that way it is an integer.  Floats are always written with a decimal point and a digit after it, even if the digit is just 0.
          :x: Incorrect.  See above to review type conversion functions.
      -   :42.42: Correct.
          :x: Incorrect.  See above to review type conversion functions.
