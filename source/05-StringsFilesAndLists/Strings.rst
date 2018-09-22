Strings
-------

We've been using strings from the beginning, and so you already have a general
idea of what they are and know how to do a few things with them.  Here, we'll
go into more detail and show you more ways you can use and manipulate strings.


.. index:: sequence, character
.. index:: [] operator, bracket operator
.. index:: operator;bracket

A String is a Sequence
~~~~~~~~~~~~~~~~~~~~~~

The first detail to add is that **a string is a sequence**.  And where have we
seen "sequence" before?  Earlier, we saw that a sequence can be given to a
``for`` loop, and the loop will iterate over each of the elements in the given
sequence.

If a for loop accepts any sequence, and if a string is a sequence, then
something like the following should work:

.. activecode:: strings01

   word = "Sequence"
   for thing in word:
       print(thing)

Try it out.  What can we learn from that?

We see that it prints out each individual **character** in the string.  That
is, each time the ``for`` loop gets a new item from the string, it gets a single
character.  Therefore, we can see that **a string is a sequence of characters**.

There are many other tools we can use with sequences, and we'll go over several
below.  All of these apply to *any* sequence, not just strings.  Recall that
*lists* are sequences as well.  Most of the following tools and patterns work
with lists just like they do with strings.  We'll focus on strings here and get
to lists shortly.

.. index:: indexing

Indexing
::::::::

In addition to iterating over a sequence in a ``for`` loop, there are other
things we can do with sequences.  One of the most important is called
**indexing**.  Indexing is a tool that lets us get a single element out of a
sequence.  In the case of a string, it lets us get a single character out of
the string.

To perform indexing, we use the ``[]`` or "bracket" operator with an integer:

.. activecode:: strings02

   fruit = 'banana'
   letter = fruit[1]
   print(letter)

The second statement extracts the character at index position 1 from the
``fruit`` variable and assigns it to the ``letter`` variable.  The expression
in the brackets is called an **index**. The index indicates which character in
the sequence you want (hence the name).

But why did it print 'a' and not 'b'?  For most people, the first letter of
'banana' is 'b,' not 'a.' But in Python and most other programming languages,
an index is an **offset** from the beginning of the string, and the offset of
the first letter is zero.

.. activecode:: strings03

   fruit = 'banana'
   letter = fruit[0]
   print(letter)

So 'b' is the letter "at index [or position] 0" of 'banana,' 'a' is the letter
"at index 1," and 'n' is the letter "at index 2."

.. figure:: figs/string.svg
   :alt: String Indexes

   String Indexes


You can use any expression, including variables and operators, as an
index, but the value of the index has to be an integer. Otherwise you
get:

.. index:: exception!TypeError, TypeError

.. code:: python

   >>> letter = fruit[1.5]
   TypeError: string indices must be integers

.. index:: len() function

Using ``len()`` with Strings
::::::::::::::::::::::::::::

Recall the ``len()`` built-in function.  We can now see that it always returns the number of elements in a sequence.  If the sequence we give it is a string, we get back the number of characters in the string.

To get the last letter of a string, you might be tempted to try something like
this:

.. index:: exception!IndexError
.. index:: IndexError

.. activecode:: strings04

   fruit = 'banana'
   length = len(fruit)
   last_letter = fruit[length]
   print(last_letter)

The reason for the ``IndexError`` is that there is no letter in "banana"
with the index 6. Since we started counting at zero, the six letters are
numbered 0 to 5. To get the last character, you have to subtract 1 from
``length``:

.. activecode:: strings05

   fruit = 'banana'
   length = len(fruit)
   last_letter = fruit[length-1]
   print(last_letter)

.. index:: index;negative, negative index

Alternatively, you can use negative indices, which count backward from the end
of the string. The expression ``fruit[-1]`` yields the last letter,
``fruit[-2]`` yields the second to last, and so on.

.. activecode:: strings06

   word = 'backwards'
   print(word[-1])
   print(word[-2])
   print(word[-3])
   print(word[-4])
   # and so on...

.. index:: traversal, loop;traversal

Traversal Through a String with a Loop
::::::::::::::::::::::::::::::::::::::

A lot of computations involve processing a string one character at a time.
Often they start at the beginning, select each character in turn, do something
to it, and continue until the end. This pattern of processing is called a
*traversal*.  We've seen above that we can accomplish this with a ``for`` loop,
using a string as its sequence.  Another way to write a traversal is with a
``while`` loop:

.. activecode:: strings07

   fruit = 'pomegranate'
   index = 0
   while index < len(fruit):
       letter = fruit[index]
       print(letter)
       index = index + 1

This loop traverses the string and displays each letter on a line by itself.
The loop condition is ``index < len(fruit)``, which can be considered to be
saying, "As long as ``index`` is still a valid index of ``fruit``" because all
valid indexes are *less* than the length of the string.  So when ``index`` is
equal to the length of the string, the condition is false, and the loop stops
executing.

With each value for ``index`` counting up from 0, the body of the loop uses indexing
to get the character at that index from the string, and it prints it out.

.. admonition:: Check your understanding

   Write a ``while`` loop that starts at the last character in the string and
   works its way *backwards* to the first character in the string, printing each
   letter on a separate line, except backwards.

   .. activecode:: strings_cyu01


.. index:: slice operator, operator;slice
.. index:: string slicing
.. index:: slice;string

Slicing
:::::::

If we want a portion of a string, rather than a single character, we can use
**slicing**.  A segment of a string is called a **slice**. Selecting a slice is
similar to selecting a character:

.. activecode:: strings08

   s = 'Monty Python'
   print(s[0:5])
   print(s[6:12])

To perform slicing, place a ``:`` inside the ``[]`` brackets with an index
written before and after it.  The operator returns the portion of the string
from the first index up to *but not including* the second index.

If you omit the first index (before the colon), the slice starts at the
beginning of the string.  If you omit the second index, the slice goes to the
end of the string:

.. activecode:: string09

   s = 'Monty Python'
   print(s[:5])
   print(s[6:])


.. index:: mutability, immutability
.. index:: TypeError, exception;TypeError

Strings are Immutable
:::::::::::::::::::::

It is tempting to use the indexing operator on the left side of an assignment,
with the intention of changing a character in a string. For example:

.. code:: python

   >>> greeting = 'Hello, world!'
   >>> greeting[0] = 'J'
   TypeError: 'str' object does not support item assignment

The "object" in this case is the string and the "item" is the character you
tried to assign. For now, an **object** is the same thing as a value, but we
will refine that definition later. An **item** is one of the values in a
sequence.

The reason for the error is that strings are **immutable**, which means you
can’t change an existing string. The best you can do is create a new string
that is a variation on the original:

.. activecode:: string10

   greeting = 'Hello, world!'
   new_greeting = 'J' + greeting[1:]
   print(new_greeting)

This example concatenates a new first letter onto a slice of ``greeting``. It
has no effect on the original string.


.. index:: counter

Looping and Counting
::::::::::::::::::::

The following program counts the number of times the letter 'a' appears in a
string:

.. activecode:: strings11

   word = 'banana'
   count = 0
   for letter in word:
       if letter == 'a':
           count = count + 1
   print(count)

This program demonstrates another pattern of computation called a **counter**.
The variable ``count`` is initialized to 0 and then incremented each time an
"a" is found. When the loop exits, ``count`` contains the result: the total
number of a’s.  We used this pattern back in the :ref:`word count example
program <wordcount_example>`.


.. index:: in operator, operator;in
.. index:: Boolean operator
.. index:: operator;Boolean

The ``in`` Operator
:::::::::::::::::::

The word ``in`` is a Boolean operator that takes two strings and returns
``True`` if the first appears as a substring in the second:

.. code:: python

   >>> 'a' in 'banana'
   True
   >>> 'seed' in 'banana'
   False

The ``in`` operator is commonly used in conditionals, as demonstrated in the
following example:

.. activecode:: strings12

   letters = 'abcde'
   fruit = 'pomegranate'
   for letter in letters:
       if letter in fruit:
           print(letter, "is in", fruit)
       else:
           print(letter, "is not in", fruit)


.. index:: string;comparison
.. index:: comparison;string

String Comparison
~~~~~~~~~~~~~~~~~

The comparison operators work on strings. To see if two strings are equal:

.. activecode:: strings13

   word = input("What's the word?")
   if word == 'banana':
       print('Alright, banana!')

Other comparison operations are useful for putting words in alphabetical order:

.. activecode:: strings14

   word = input("What's the word?")
   if word < 'banana':
       print('Your word, ' + word + ', comes before banana.')
   elif word > 'banana':
       print('Your word, ' + word + ', comes after banana.')
   else:
       print('Alright, banana!')

Python does not handle uppercase and lowercase letters the same way that
people do. All the uppercase letters come before all the lowercase
letters, so if you enter "Pineapple," for example:

::

   Your word, Pineapple, comes before banana.

A common way to address this problem is to convert strings to a standard
format, such as all lowercase, before performing the comparison.  The next
section includes a way to do that.


.. index:: object, method

``string`` Objects and Methods
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Strings in Python can do a lot more than just hold a sequence of characters.
Strings are an example of Python **objects**.

.. admonition:: Objects

   An object contains both data (the actual string itself) and **methods**,
   which are functions that are built into the object and can modify or perform
   operations on it.

   As another way of putting it, objects "know things" and "can do things":

   * Objects "know things": an object holds *data*.
   * Objects "can do things": an object contains *code* (the methods).

Python has a function called ``dir()`` which lists the methods available for an
object. The ``type()`` function shows the type of an object and the ``dir()``
function shows the available methods.

.. code:: python

   >>> stuff = 'Hello world'
   >>> type(stuff)
   <class 'str'>
   >>> dir(stuff)
   ['capitalize', 'casefold', 'center', 'count', 'encode',
   'endswith', 'expandtabs', 'find', 'format', 'format_map',
   'index', 'isalnum', 'isalpha', 'isdecimal', 'isdigit',
   'isidentifier', 'islower', 'isnumeric', 'isprintable',
   'isspace', 'istitle', 'isupper', 'join', 'ljust', 'lower',
   'lstrip', 'maketrans', 'partition', 'replace', 'rfind',
   'rindex', 'rjust', 'rpartition', 'rsplit', 'rstrip',
   'split', 'splitlines', 'startswith', 'strip', 'swapcase',
   'title', 'translate', 'upper', 'zfill']

While the ``dir()`` function lists the methods, a better source of
documentation for string methods is the official Python documentation:
`https://docs.python.org/3/library/stdtypes.html#string-methods <https://docs.python.org/3/library/stdtypes.html#string-methods>`_.

.. note::

   The official Python documentation uses a syntax that might be confusing. For
   example, in ``find(sub[, start[, end]])``, the brackets indicate optional
   arguments. So ``sub`` is required, but ``start`` is optional, and if you
   include ``start``, then ``end`` is optional.

.. index:: dot notation

Methods, like any other function, can be called to execute them.  Calling a
method is similar to calling a function (it takes arguments and returns a
value) but to access a method within an object, we use :ref:`dot notation
<dot-notation>` just like when accessing functions within modules.

.. index:: upper() method

For example, the method ``upper()`` takes a string and returns a new string
with all uppercase letters:

.. activecode:: strings15

   word = 'banana'
   print(word)
   new_word = word.upper()
   print(new_word)

This form of dot notation specifies the name of the method, ``upper()``, and the
name of the string to apply the method to, ``word``. The empty parentheses
indicate that this method takes no argument.

.. index:: find() method

The ``find()`` string method searches for the position of one string within
another:

.. activecode:: strings16

   word = 'banana'
   index = word.find('a')
   print("'a' is found at index", index)
   index = word.find('nan')
   print("'nan' is found at index", index)

In this example, we invoke ``find()`` on ``word`` and pass in the string we are
looking for as a parameter.

The ``find()`` method can optionally take a second argument: the index where it
should start searching.

.. activecode:: strings17

   word = 'banana'
   index = word.find('a', 4)
   print("'a' is found at index", index)
   index = word.find('nan', 4)
   print("'nan' is found at index", index)

The final call to ``find()`` there returns ``-1`` to indicate the search string
was *not* found.  The string ``'nan'`` *is* present in ``'banana'``, but the
second argument started the search at index 4, beyond where ``'nan'`` starts.

.. index:: strip() method

One common task is to remove white space (spaces, tabs, or newlines) from the
beginning and end of a string using the ``strip()`` method:

.. activecode:: strings18

   line = '  Here we go  '
   print(line.strip())

.. index:: startswith() method

Some methods such as ``startswith()`` return Boolean values.

.. activecode:: strings19

   line = 'Have a nice day'
   print(line.startswith('Have'))
   print(line.startswith('h'))

Note that ``startswith()`` requires case to match, so sometimes we take a line
and map it all to lowercase before we do any checking using the ``lower()``
method.

.. code:: python

   >>> line = 'Have a nice day'
   >>> line.startswith('h')
   False
   >>> line.lower()
   'have a nice day'
   >>> line.lower().startswith('h')
   True


.. index:: count() method

.. admonition:: Check your understanding

   There is a string method called ``count()`` that counts the occurrence of
   one string within another.  Read about this method in `Python string method
   documentation <https://docs.python.org/3/library/stdtypes.html#str.count>`_
   and write a short program that uses ``count()`` to count the number of times
   the letter 'a' occurs in 'banana'.

Parsing Strings
~~~~~~~~~~~~~~~

Often, we want to look into a string and find a substring. For example
if we were presented a series of lines formatted as follows:

``From stephen.marquard@uct.ac.za   Sat Jan  5 09:14:16 2008``

and we wanted to pull out only the second half of the address (i.e.,
``uct.ac.za``) from each line, we can do this by using the ``find()``
method and string slicing.

First, we will find the position of the at-sign in the string. Then we
will find the position of the first space *after* the at-sign. And then
we will use string slicing to extract the portion of the string which we
are looking for.

.. activecode:: strings20

   data = 'From stephen.marquard@uct.ac.za Sat Jan  5 09:14:16 2008'
   atpos = data.find('@')
   print(atpos)
   sppos = data.find(' ',atpos)
   print(sppos)
   host = data[atpos+1:sppos]
   print(host)

We use the optional arguments for the ``find()`` method that allow us to
specify the position in the string where we want ``find()`` to start searching.
When we slice, we extract the characters from "one beyond the at-sign" and up
to *but not including* the index of the next space character.

The `documentation for the find method
<https://docs.python.org/3/library/stdtypes.html#str.find>`_ describes the
optional arguments.


.. index:: format() method, string formatting

String Formatting
~~~~~~~~~~~~~~~~~

The ``format()`` string method is one of the most commonly used.  It allows us
to construct strings, replacing parts of the strings with the data stored in
variables or calculated in expressions.  Let's look at an example:

.. activecode:: strings21

   count = 12
   countchar = 'a'
   print("{} words start with '{}'.".format(count, countchar))

The syntax might look a little strange.  It is calling the ``format()`` method
via dot notation, but instead of writing a string variable to the left of the
dot, we wrote a string literal.  This is commonly how ``format()`` is called.

.. index:: format string

The string literal (from which the ``format()`` method is called) is known as a
**format string**.  The format string should contain one or more
**placeholders**, written as ``{}`` (known as "curly braces").  Then, each
argument given to the ``format()`` method is placed into the string in place of
each of the placeholders in order.

Each placeholder can contain information inside the ``{}`` curly braces that
specifies how the value included there should be formatted.  There are many
options for controlling how the string is formatted, but the more commonly-used
options control how floating point values are printed and allow for aligning
values in columns.  The following example demonstrates both.

.. activecode:: strings22

   # An ugly table
   print("Index  Value")
   for i in range(8):
      print(i*5, i*0.125)

   print()

   # A well-formatted table
   print("Index  Value")
   for i in range(8):
      print("{:>5}  {:5.3}".format(i*5, i*0.125))

In the format string here, ``"{:>5}  {:5.3}"``, the first placeholder is
``{:>5}``.  It includes a ``:`` to start the formatting options, the ``>``
makes the value "right-aligned" and the ``5`` controls how many characters the
value is placed in.  So it always uses 5 characters, and it places the value on
the right hand side of that space.  The second placeholder, ``{:5.3}`` uses 5
characters, again, and the ``.3`` makes it place 3 digits after the decimal
point, again regardless of the value itself.  Values are left-aligned by
default.  Try changing some of the values in the placeholders to see how it
affects the formatting.

There are *many* more options for controlling what is included in the string
and how it is formatted.  You can see the full set of options in the `"Format
String Syntax" documentation
<https://docs.python.org/3/library/string.html#formatstrings>`_, and the
`examples <https://docs.python.org/3/library/string.html#format-examples>`_
provided can help you learn about additional features.

Using string formatting is often easier than building strings by concatenating
different pieces and provides more control than including multiple arguments in
a plain ``print()`` statement.  For example:

.. activecode:: strings23

   import math
   radius = 11
   units = "cm"
   volume = 4 / 3 * math.pi * radius**3

   # print()  (adds space before the period)
   print("The volume is", volume, "cubic", units, ".")

   # Concatenation  (complex expression, prone to errors)
   print("The volume is " + str(volume) + " cubic " + units + ".")

   # String formatting  (just right!)
   print("The volume is {:.2} cubic {}.".format(volume, units))

