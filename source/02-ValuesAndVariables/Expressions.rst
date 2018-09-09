.. index:: expression, literal, evaluate

Expressions
-----------

**Expressions**, like we just saw in the :ref:`assignment statement syntax
pattern <assignment-statement>`, are values, variables, operators, and function
calls (which we'll learn more about in a bit) either by themselves or in
combination with one another. 

A value all by itself is considered an expression (called a **literal**), and so is a
variable, so the following are all legal expressions (assuming that the
variable ``x`` has been assigned a value):

.. code:: python

   17
   x
   x + 17
   len("Hi there!")

.. index:: len() function

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

Are you surprised it outputs *nothing*? 

You might have guessed the code would output 6, 7, and 9, because those
are the values of the expressions on each line.  But an expression by
itself doesn't output anything.  This is a common source of confusion
when you first start to code.

To see the value of an expression, we can use the ``print()`` function:

.. activecode:: expressions02

   x = 6
   print(x)
   print(x + 1)
   print(len("Hi there!"))

So expressions don't automatically create output. Then what *does* Python do
with an expression?  It **evaluates** it.

.. admonition:: Syntax Rule

   In Python, any expression, anywhere in the program, will be **evaluated** to
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

