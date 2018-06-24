.. index:: expression, literal, evaluate

Expressions
-----------

An **expression**, like we just saw in the :ref:`assignment statement syntax
pattern <assignment-statement>`, is a combination of values, variables,
operators, and function calls (which we'll learn more about in a bit). A value
all by itself is considered an expression (called a **literal**), and so is a
variable, so the following are all legal expressions (assuming that the
variable ``x`` has been assigned a value):

.. code:: python

   17
   x
   x + 17
   len("Hi there!")

.. note::

   ``len()`` is a built-in Python function that returns the length of a string
   (the number of characters in it).  This is the third built-in function we've
   seen so far, including ``print()`` and ``type()``.

Expressions seem so simple that beginning programmers often make incorrect
assumptions about them and misunderstand how they work.  What do you think the
following code outputs?

.. activecode:: expressions01

   x = 6
   x
   x + 1
   len("Hi there!")

If you guessed *nothing*, you were right!  Or you might have guessed the code
would output 6, 7, and 9, because those are the values of the expressions on
each line.  But an expression by itself doesn't output anything.  This is a
common source of confusion for beginners.

To see the value of an expression, we can use the ``print()`` function:

.. activecode:: expressions02

   x = 6
   print(x)
   print(x + 1)
   print(len("Hi there!"))

Then what *does* an expression do?  We have to understand Python's syntax rule
for expressions.

.. admonition:: Syntax Rule

   In Python, any expression, anywhere in the program, is **evaluated** to
   produce a value.  That value is then used *in place of* the expression as
   the statement it is in executes.

   **Evaluation Rules:**

   - A *variable* in an expression is replaced with the value that it refers to.
   - *Operations* (like ``1 + 1`` and ``x * 5``) are replaced with the result of
     the operation.
   - *Function calls* (like ``len("Hi there!")``) are replaced with the return
     value of the function (which we'll learn more about later).

Examples:

- An expression *on a line by itself* is evaluated, but then the result is
  discarded.

  .. code:: python
    
     5
     x + 1

  In both of those statements, the expression is evaluated and a value is
  obtained (5 and whatever x+1 equals, respectively), but it isn't used or
  saved anywere.

- An expression *on the right hand side of an assignment statement* is
  evaluated, and then the resulting value is saved in the variable on the left
  hand side.

  .. code:: python

     x = 5 + 10
     years = 12
     days = years * 365

  In each of these statements, first the expression on the right hand side
  is evaluated, then that value is saved in the variable on the left.

- An expression *inside the parentheses of a function call* is evaluated, and
  then the resulting value is given to the function to use.

  .. code:: python
    
     print(5 + 10)
     print(years)

  Here, the ``print()`` function is given the *values* ``15`` and ``12``
  (assuming ``years`` was assigned ``12`` as above), so that is what it prints.
  Note that it does *not* print the string ``"years"``.

