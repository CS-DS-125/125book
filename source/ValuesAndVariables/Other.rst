
Comments
--------


.. index:: comment

As programs get bigger and more complicated, they get more difficult to
read. Formal languages are dense, and it is often difficult to look at a
piece of code and figure out what it is doing, or why.

For this reason, it is a good idea to add notes to your programs to
explain in natural language what the program is doing. These notes are
called *comments*, and in Python they start with the ``#`` symbol:

.. code:: python

   # compute the percentage of the hour that has elapsed
   percentage = (minute * 100) / 60

In this case, the comment appears on a line by itself. You can also put
comments at the end of a line:

.. code:: python

   percentage = (minute * 100) / 60     # percentage of an hour

Everything from the ``#`` to the end of the line is ignored; it has no
effect on the program.

Comments are most useful when they document non-obvious features of the
code. It is reasonable to assume that the reader can figure out *what*
the code does; it is much more useful to explain *why*.

This comment is redundant with the code and useless:

.. code:: python

   v = 5     # assign 5 to v

This comment contains useful information that is not in the code:

.. code:: python

   v = 5     # velocity in meters/second.

Good variable names can reduce the need for comments, but long names can
make complex expressions hard to read, so there is a trade-off.

Debugging
---------


.. index:: debugging

At this point, the syntax error you are most likely to make is an
illegal variable name, like ``class`` and ``yield``, which are keywords,
or ``odd~job`` and ``US$``, which contain illegal characters.


.. index:: syntax error, error!syntax

If you put a space in a variable name, Python thinks it is two operands
without an operator:

.. code:: python

   >>> bad name = 5
   SyntaxError: invalid syntax

.. code:: python

   >>> month = 09
     File "<stdin>", line 1
       month = 09
                ^
   SyntaxError: invalid token

For syntax errors, the error messages don’t help much. The most common
messages are ``SyntaxError: invalid syntax`` and
``SyntaxError: invalid token``, neither of which is very informative.


.. index:: error message, use before def

.. index:: exception, runtime error

.. index:: error!runtime

The runtime error you are most likely to make is a "use before def;"
that is, trying to use a variable before you have assigned a value. This
can happen if you spell a variable name wrong:

.. code:: python

   >>> principal = 327.68
   >>> interest = principle * rate
   NameError: name 'principle' is not defined

Variables names are case sensitive, so ``LaTeX`` is not the same as
``latex``.


.. index:: case-sensitivity, variable names

.. index:: semantic error, error!semantic

At this point, the most likely cause of a semantic error is the order of
operations. For example, to evaluate :math:`1/2\pi`, you might be
tempted to write

.. code:: python

   >>> 1.0 / 2.0 * pi

But the division happens first, so you would get :math:`\pi / 2`, which
is not the same thing! There is no way for Python to know what you meant
to write, so in this case you don’t get an error message; you just get
the wrong answer.


.. index:: order of operations
