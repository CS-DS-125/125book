
.. index:: value, data, data type, type, integer, string, floating point
   single: type; str
   single: type; int
   single: type; float

Values and Data Types
---------------------

Computers are very fast and very precise, but they don't understand things the
way humans do. At a very deep level computers only really work with 0's and 1's. 
Absolutely everything they do is some combination or transformation of 0's and 1's. 

So for a computer, the word 'cat' is just more 0's and 1's in some particular
configuration. If I ask a child to multiply 'cat' times 'dog', they would probably
laugh. The answer ('cog?', 'dat?') might be amusing but the question itself doesn't
make any sense. For a computer, since both 'cat' and 'dog' are really numbers, multiplying
the two together doesn't seem wrong. It wouldn't know that both the question and the
answer are nonsense.

Every human has developed a bunch of mental categories that help us to understand the
world. We have a mental category for numbers and math, and a seperate
category for pets. We know that a square root can be applied to 92 but not to our cat.  
Your computer doesn't have any categories at all built in, so humans have to help,
so our interactions with computers are less likely to produce nonsense. 

Any information we give to a program is called **data**. Data that is used by a program
is almost always classified into a **data type**. 

'Cat' is text information. The text data type is called **string**. 
93 is numeric information. There are a few different numeric data types. This particular
example's data type would be **integer**. 

By classifying 'Cat' as a string and 93 as an integer, we have told the computer that
certain kinds of actions (what we will call 'operations') make sense with one but not
with the other. For example, if the computer knows that 'Cat' is a string, and I ask it to
calculate the square root of cat, it will tell me I've made a mistake that can't be done
with a string. If I ask it to capitalize 93, it will tell me I've made a mistake, that 
can't be done with an integer.

Now since we've been using these obvious examples, you might think that the data type
issue isn't terribly important. You are not going to ask the computer to do arithmetic
on pets. However, once you start coding you'll find these types of errors to be both
subtle and pretty common. 

So pay attention to this next bit. It's important that you become really comfortable
with basic data types. 

A **value** is any of the basic pieces of information -- like a word or a
number -- that a program works with.  The values we have seen so far are ``1``,
``2``, and ``"Hello, World!"``.  Values manipulated by a program are also
referred oto as **data**.  If you've guessed that these are going to be key
part of data science, you've guessed right.

There are many kinds of data, and values belong to different **data types**:
``2`` is an **integer**, and ``"Hello, World!"`` is a **string**, so called because
it contains a string or sequence of characters. You (and the interpreter) can
recognize strings in code because they are enclosed in quotation marks.

If you are not sure what the type of a particular value is, the ``type()``
function can tell you:

.. activecode:: types01

   print('The type of "Hello, World!" is:')
   print(type("Hello, World!"))
   print('The type of 17 is:')
   print(type(17))

   # Try writing a line of code to find the type of 123.45

Not surprisingly, strings belong to the type ``str`` and integers belong
to the type ``int``.  Less obviously, numbers with a decimal point belong to a
type called ``float``, because these numbers are stored in the computer in a
format called *floating point*.

.. activecode:: types02

   print('The type of 123.45 is:')
   print(type(123.45))

What about values like ``"17"`` and ``"123.45"``? They look like numbers, but they
are in quotation marks like strings.

.. activecode:: types03

   print('The type of "17" is:')
   print(type("17"))
   print('The type of "123.45" is:')
   print(type("123.45"))

They’re strings!  It's important to understand and remember that ``"17"`` and
``17`` are *very* different things to Python.

Strings
^^^^^^^

If you look closely, you'll see we have used two different kinds of quotation
marks to create strings: single ``'`` and double ``"``.  Both are valid in
Python.  Strings enclosed in one kind of quote symbol can *contain* the other kind.

.. activecode:: strings01

   print("This is a string.")
   print('This is also a string.')
   print("I'm okay with this string's apostrophes.")
   print('And this string quotes the earlier, "This is a string."')

What do you think will happen if a string contains a quotation mark of the same
kind that encloses it?

.. activecode:: strings02
    :nocanvas:

    print('What happens in 'this' case?')

There is a syntax error because the quotation mark that we want to be inside
the string actually ends the string, and then the rest of the line is invalid
Python syntax.

.. index::
   single: string; escaping

To put a quote character inside a string that is the same as the one used to
start and end the string, the character can be **escaped** by putting a
backslash ``\`` in front of it, as in ``"The string \"four\" is four characters
long."``.

.. activecode:: strings03
    :nocanvas:

    print('Okay, so \'this\' works.')

And by the way:  since strings are sequences of characters, and emoji are characters...

.. activecode:: strings04

   print('My password is ✓🐎🔋✂😕')


Numbers
^^^^^^^

When you type a large integer, you might be tempted to use commas between
groups of three digits, as in 1,000,000. This is not a valid *integer* in
Python, but it is valid syntax:

.. activecode:: numbers01

   print(1,000,000)

Well, that’s not what we expected at all! Python interprets ``1,000,000`` as a
comma-separated sequence of integers, which it prints with spaces between.

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
doesn’t do what *thought* or *wanted* it to do.  In this case, Python's rule
about what commas mean doesn't exactly match what we might assume about them
based on using commas in other domains.

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
they are really numeric data.  Python provides a few **type conversion**
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
    print(3.14, int(3.14))
    print(3.9999, int(3.9999))   # This does *not* round to the closest int!
    print(-3.999, int(-3.999))   # Note that the result is closer to zero
    print(3.0, int(3.0))

    print(17, int(17))           # int() even works on integers

    print('"2345"', int("2345")) # parse a string to produce an int

    # What will this do?
    print('"23bottles"', int("23bottles"))

The error caused by the last line shows that a string given to ``int()`` has to
be a syntactically valid integer.  Anything else will cause the function to
fail and raise a runtime error.

The ``float()`` function converts an integer, float, or syntactically valid
string into a float.

.. activecode:: typeconv02
    :nocanvas:

    print("Printing values of different types & their conversion to floats.")
    print(123, float(123))
    print('"123"', float("123"))
    print('"123.45"', float("123.45"))
    print(123.45, float(123.45))

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
