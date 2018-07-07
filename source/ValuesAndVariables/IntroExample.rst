Word Count Example Program (Again)
----------------------------------

We can use much of what we've covered in this chapter to help make some sense
of the :ref:`word count example program <wordcount_example>` from the
introduction.  Here it is again:

.. code:: python

   countchar = 'w'

   file = open("atotc_opening.txt")

   text = file.read()

   words = text.split()

   count = 0
   for word in words:
       if word.startswith(countchar):
           count = count + 1

   file.close()

   print("{} words start with '{}'.".format(count, countchar))

Here is what we can understand so far, just based on the contents of this
chapter:

.. code:: python

   countchar = 'w'

Right away, we can see that this line is an example of the :ref:`assignment
statement syntax pattern <assignment-statement>`.  We can interpret this as
"The ``countchar`` variable gets the value ``'w'``," and we know that ``'w'``
is a *string* value.

.. code:: python

   file = open("atotc_opening.txt")

Again, we have an assignment statement.  It's creating a variable called
``file`` and assigning it...  What?  Well, we don't know exactly what that does
yet, but from the context we can guess that it has something to do with the
file named ``atotc_opening.txt``.  We'll cover the ``open()`` function later.

.. code:: python

   text = file.read()
   words = text.split()

More assignment statements, this time creating a ``text`` variable and a
``words`` variable.  The ``file`` variable from the line above is used here,
but again, the details of what, precisely, these lines do will come later in
the book.  The variable names help us understand the code, though, because they
were :ref:`chosen well <variable-naming>`.  It's possible to guess that this
will "read" the file that was "opened" earlier, that the ``text`` variable will
contain the text of that file, and that ``words`` will contain words from that
text.

.. code:: python

   count = 0

Another simple assignment statement.  Here, ``count`` gets the value ``0``.
Many programs start with a series of variable assignments like these, creating
variables and giving them initial values for the rest of the program to use.

.. code:: python

   for word in words:
       if word.startswith(countchar):

The ``for`` and ``if`` keywords used in these lines will be covered in the very
next chapter.  For now, form a guess about what they mean based on what you
know of the variables involved, the common English meaning of the words used,
and what you can see the program output.  You can compare your guess to the
formal definitions when you reach them in a few sections.

.. code:: python

   count = count + 1

Here we have an assignment statement with an expression on the right hand side.
This is an example of a variable update, and specifically it is an
**increment**.  This line sets the ``count`` variable to get its current value
plus one.

.. code:: python

   file.close()

   print("{} words start with '{}'.".format(count, countchar))

In these remaining lines, we see a print statement, but with an oddly-formed
string, and something to do with the ``file`` variable above, whose meaning can be guessed from the names used and the context, but for which we have no precise interpretation yet.

