.. index:: file

Files
=====

.. index:: persistence, secondary memory

Persistence
-----------

So far, we have learned how to write programs and communicate our intentions to
the *Central Processing Unit* using conditionals, functions, and
iterations. We have learned how to create and use data structures like lists
and strings in the *Main Memory*. The CPU and memory are where our software
works and runs. It is where all of the "thinking" happens.

But if you recall from our hardware discussions, once the power is
turned off, anything stored in either the CPU or main memory is erased. So up
until now, our programs have only produced temporary results. 

.. figure:: figs/arch.svg
   :alt: Hardware architecture, including secondary memory

   Hardware architecture, including secondary memory

In this chapter, we start to work with *Secondary Memory*, like hard drives,
where **files** are stored.  Secondary memory is not erased when the power is
turned off, and it has much more capacity than the main memory.  If we keep our
data long-term or work with large datasets we need to learn to access and store
data in files.

Example code in this section will treat the data in the box below as a file
named ``atotc_opening2.txt``.  As before, this contains opening lines from *A
Tale of Two Cities* (a few more this time).  You can edit the file below, and
its changed contents will be used in any active code blocks.

.. datafile:: atotc_opening2.txt
   :edit:

   It was the best of times,
   it was the worst of times,
   it was the age of wisdom,
   it was the age of foolishness,
   it was the epoch of belief,
   it was the epoch of incredulity,
   it was the season of Light,
   it was the season of Darkness,
   it was the spring of hope,
   it was the winter of despair,
   we had everything before us,
   we had nothing before us,
   we were all going direct to Heaven,
   we were all going direct the other way--
   in short, the period was so far like the present period, that some of
   its noisiest authorities insisted on its being received, for good or for
   evil, in the superlative degree of comparison only.

   There were a king with a large jaw and a queen with a plain face, on the
   throne of England; there were a king with a large jaw and a queen with a
   fair face, on the throne of France. In both countries it was clearer than
   crystal to the lords of the State preserves of loaves and fishes, that
   things in general were settled for ever.

   It was the year of Our Lord one thousand seven hundred and seventy-five.
   Spiritual revelations were conceded to England at that favoured period, as
   at this. Mrs. Southcott had recently attained her five-and-twentieth blessed
   birthday, of whom a prophetic private in the Life Guards had heralded the
   sublime appearance by announcing that arrangements were made for the
   swallowing up of London and Westminster. Even the Cock-lane ghost had been
   laid only a round dozen of years, after rapping out its messages, as the
   spirits of this very year last past (supernaturally deficient in
   originality) rapped out theirs. Mere messages in the earthly order of events
   had lately come to the English Crown and People, from a congress of British
   subjects in America: which, strange to relate, have proved more important to
   the human race than any communications yet received through any of the
   chickens of the Cock-lane brood. 


Text Files and Lines
--------------------

A text file can be thought of as a sequence of lines, much like a Python
string can be thought of as a sequence of characters. For example,
``atotc_opening2.txt`` above contains 37 lines.

.. index:: newline

To break the file into lines, there is a special character that
represents the "end of the line" called the **newline** character.

In Python, we represent the newline character as ``\n`` in string constants.
(That's a "backslash," because it is leaning backwards.) Even though this looks
like two characters, it is understood by Python as a single character.

If we print a string variable containing the newline character, we can see that
it prints the string on two lines, moving to the beginning of the next line when the
newline character is reached:

.. activecode:: files03

   stuff = 'Hello\nWorld!'
   print(stuff)

   stuff = 'X\nY'
   print(stuff)
   print(len(stuff))

You can also see that the length of the string ``X\nY`` is *three* characters
because the newline character is a single character.

So when we look at the lines in a file, we need to *imagine* that there is a
special invisible character called the newline at the end of each line that
marks the end of the line.


.. index:: file;open, open function
.. index:: function;open

Opening Files
-------------

When we want to read or write a file in a program, we first must **open** the
file. When you open a file, you are asking the operating system to find the
file by name, make sure the file exists, and prepare it to be read from or written to.

To open a file, we can use the ``open()`` function [[full
documentation](https://docs.python.org/3/library/functions.html#open)].  In its
simplest form, it takes one argument: a string containing the name of the file
to open.  In this example, we open the file (from above) ``atotc_opening2.txt``:

.. activecode:: files01

   file = open('atotc_opening2.txt')
   print(file)


.. index:: file object

If the call to ``open()`` is successful, it returns a **file object**. The file
object is not the actual data contained in the file, but instead it has a
"handle" that it can use to access the data.  You can use the object by calling
its *methods* via *dot notation*, just like with other objects.  You are given
a file object if the requested file exists and you have the proper permissions
to read the file.

.. figure:: figs/file_object.svg
   :alt: A file object with file handle

   A file object with file handle

If the file does not exist, ``open`` will fail with a traceback and you
will not get a file object to access the contents of the file:

.. activecode:: files02

   file = open('stuff.txt')

Later we will use ``try`` and ``except`` to deal more gracefully with
the situation where we attempt to open a file that does not exist.


.. index:: file;reading, counter

Reading Files
-------------

While the file object does not contain the data for the file, it is quite easy
to construct a ``for`` loop to read through and count each of the lines in a
file:

.. activecode:: files04

   file = open('atotc_opening2.txt')

   count = 0
   for line in file:
       count = count + 1

   print('Line Count:', count)

.. note::

   The code above reports 36 lines, despite the file having 37.  This appears
   to be a bug in the Python interpreter used to run code in the browser.  It
   skips the final line for some reason.  You can see this by adding
   ``print(line)`` inside the for loop and comparing the output to the file data
   above.
 
   The code will work correctly in any "normal" Python interpreter.

We can use the file object as the sequence in our ``for`` loop, and each
element in the sequence will be another line from the file. The ``for`` loop
above counts the number of lines in the file and prints the count. The rough
translation of the ``for`` loop into English is, "for each line in the file
represented by the file object, add one to the ``count`` variable."

When the file is read using a ``for`` loop in this manner, Python takes care of
splitting the data in the file into separate lines using the newline character.
Python reads each line through the newline and includes the newline as the last
character in the ``line`` variable for each iteration of the ``for`` loop.

Because the ``for`` loop reads the data one line at a time, it can efficiently
read and count the lines in very large files without running out of main memory
to store the data. The above program can count the lines in any size file using
very little memory since each line is read, counted, and then discarded.

If you know the file is relatively small compared to the size of your main
memory, you can read the whole file into one string using the ``read()`` method
of the file object.

.. activecode:: files05

   file = open('atotc_opening2.txt')
   inp = file.read()
   
   print(len(inp))
  
   print(inp[:20])

In this example, the entire contents (all 1,862 characters) of the file
``atotc_opening2.txt`` are read directly into the variable ``inp``. We use
string slicing to print out the first 20 characters of the string data stored
in ``inp``.

When the file is read in this manner, all the characters including all of the
lines and newline characters are one big string in the variable ``inp``. It is
a good idea to store the output of ``read`` as a variable so it is only called
once.

Remember that this form of the ``open`` function should only be used if the
file data will fit comfortably in the main memory of your computer.  If the
file is too large to fit in main memory, you should write your program to read
the file in chunks using a loop.

.. index:: close method, method;close

Closing Files
-------------

When a program is done using a file, it should **close** the file using the
`close()` method of the file object.  This will release resources in the
computer and make sure everything is cleaned up correctly.

Using a file object after it has been closed will not work:

.. activecode:: files06

   # open a file
   file = open('atotc_opening2.txt')
   inp1 = file.read()
   print(len(inp1))

   # close the file   
   file.close()

   # attempt to read from the same file object
   inp2 = file.read()
   print(len(inp2))

To make sure a file is always closed and cleaned up, it is safest to use the
`with` syntax:

.. activecode:: files07

   # open a file, and automatically close it when the with block exits
   with open('atotc_opening2.txt') as file:
      inp1 = file.read()
      print(len(inp1))

Whenever the body of the ``with`` statement (the indented lines below it) exit,
for any reason, the file object created by the ``open()`` call will automatically
be closed.

We will use the ``with`` syntax in the rest of the examples here, though manually
opening and closing a file (with ``open()`` and ``.close()``) would work as well.


.. index:: filter pattern, pattern;filter

Searching Through a File
------------------------

When you are searching through data in a file, it is a very common pattern to
read through a file, ignoring most of the lines and only processing lines which
meet a particular condition. We can combine the pattern for reading a file with
string methods to build simple search mechanisms.

For example, if we wanted to read a file and only print out lines which started
with the prefix ``'it'``, we could use the string method ``startswith()`` to select
only those lines with the desired prefix:

.. activecode:: files08

   with open('atotc_opening2.txt') as file:
       count = 0
       for line in file:
           if line.startswith('it'):
               print(line)


When this program runs, we get the following output:

::

   it was the worst of times,

   it was the age of wisdom,

   it was the age of foolishness,

   it was the epoch of belief,

   it was the epoch of incredulity,

   it was the season of Light,

   it was the season of Darkness,

   it was the spring of hope,

   it was the winter of despair,

   its noisiest authorities insisted on its being received, for good or for

The output looks correct since the only lines we are seeing are those which start
with ``'it'``, but why are we seeing the extra blank lines?  This is due to 
invisible *newline* characters. Each of the lines in the file ends with a newline, so the
``print()`` statement prints the string in the variable ``line`` which includes a
newline and then ``print()`` adds *its own* newline, resulting in the double
spacing effect we see.

We could use string slicing to print all but the last character, but a
simpler approach is to use the ``rstrip()`` method, which strips whitespace
(including newline characters) from the right side of a string:

.. activecode:: files09

   with open('atotc_opening2.txt') as file:
       count = 0
       for line in file:
           line = line.rstrip()
           if line.startswith('it'):
               print(line)

As your file processing programs get more complicated, you may want to
structure your search loops using ``continue``. The basic idea of the search
loop is that you are looking for "interesting" lines and effectively skipping
"uninteresting" lines. And then when we find an interesting line, we do
something with that line.

We can structure the loop to follow the pattern of skipping uninteresting lines
as follows:

.. activecode:: files10

   with open('atotc_opening2.txt') as file:
       count = 0
       for line in file:
           line = line.rstrip()

           # Skip 'uninteresting lines'
           if not line.startswith('it'):
               continue

           # If we get here, the line wasn't skipped,
           # so we can process our 'interesting' line:
           print(line)

The output of the program is the same. In English, the uninteresting
lines are those which do *not* start with ``'it'``, which we skip using
``continue``. For the "interesting" lines (i.e., those that start with
``'it'``) we perform the processing on those lines.

We can use the ``find()`` string method to find lines where a search string is
anywhere in the line. Since ``find()`` looks for an occurrence of a string within
another string and either returns the position of the string or -1 if the
string was not found, we can write the following loop to show lines which
contain the string ``'for'``:

.. activecode:: files11

   with open('atotc_opening2.txt') as file:
       count = 0
       for line in file:
           line = line.rstrip()

           # Skip 'uninteresting lines'
           if line.find('for') == -1:
               continue

           # If we get here, the line wasn't skipped,
           # so we can process our 'interesting' line:
           print(line)


.. index:: file;writing

Writing Files
-------------

To write data into a new file or to overwrite an old file,
we open the file with a **mode** value ``'w'`` as
the second argument to the ``open()`` function call:

.. activecode:: files12

   with open('output.txt', 'w') as file:
       print(file)

If the file doesn’t exist, a new one is created and opened. If the file
already exists, opening it in write mode **deletes** the old data
and starts fresh, so be careful! 

Once the file is opened we can use the ``write()`` method of the
file object to put data into the file. The ``write()`` methods writes
characters into the file and then returns the number of characters
written. 

There are different modes for writing characters into the file. 
The default write mode is text for writing (and reading) strings.

.. activecode:: files13

   with open('output.txt', 'w') as file:
       line1 = "This here's the wattle,\n"
       file.write(line1)

The file object keeps track of where it is, so if you call ``write()`` again,
it will add the new data to the end of the file.

We must make sure to manage the ends of lines as we write to the file by
explicitly inserting the newline character when we want to end a line.
The ``print()`` statement automatically appends a newline, but the
``write()`` method does not add the newline automatically.

.. activecode:: files14

   with open('output.txt', 'w') as file:
       line1 = "This here's the wattle,\n"
       line2 = 'the emblem of our land.\n'
       file.write(line1)
       file.write(line2)

.. note::

   Both of the above code examples write to a file.  This will show up as a
   text box labeled ``output.txt``.  The second example will write data into
   the file text box created by the first example.  Scroll up if it has gone
   off the page.

Closing files is especially important after writing data into them.
Data might not be physically written to the secondary memory until ``close()``
is called, and it remains in danger of being lost if the computer loses power.

Again, using the ``with`` syntax ensures the file is closed automatically.
Otherwise, be sure to add a call to the ``close()`` method when the program
is done writing to the file.


.. index:: debugging, whitespace
.. index:: repr function, function;repr
.. index:: string representation

Debugging
---------

When you are reading and writing files, you might run into problems with
whitespace. These errors can be hard to debug because spaces, tabs (written in
string constants as ``\t``), and newlines are normally invisible:

.. activecode:: files15

   s = '1 2\t 3\n 4'
   print(s)

The built-in function ``repr()`` can help by explicitly showing you the 'invisible'
characters in your file.  ``repr()``  takes any object as an
argument and returns a string representation of the object. If we pass in a
string,  ``repr()`` returns  that string with 'invisible' characters shown as 
backslash sequences:

.. activecode:: files18

   s = '1 2\t 3\n 4'
   print(repr(s))

This can be helpful when debugging.

.. index:: end of line character

If you are running code of different computers one problem you might run into
is that different systems use different characters to indicate the end of a line.
Some systems use a newline, represented ``\n``. Others use a return character,
represented ``\r``. Some use both. For now, you do not need to worry about this,
but it is important to keep in mind that your code may function differently 
on different operating systems or computers because of these slight variations.

For most systems, there are applications to convert files from one format to another.
You can find them (and read more about this issue that you wouldn't think
should be so complex) at `wikipedia.org/wiki/Newline
<https://wikipedia.org/wiki/Newline>`_. Or, perhaps, you might write the code
to do the conversion yourself.

