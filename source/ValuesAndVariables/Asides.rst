Asides
------

Now is a good time to talk briefly about some good coding practices.
These are things that will help you write better code


.. index:: comments

Comments
::::::::

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


.. index:: debugging, bugs

Debugging
:::::::::

A simple fact of programming is that code almost never works the first time.
**Debugging**, the process of finding and fixing **bugs** (errors) in code, is
a critical part of the process.  In order to debug your code, you have to first
understand *what* has gone wrong, then try to figure out *why*.

.. admonition:: Three Steps for Debugging

   **Step 1:** What **should** it do?

   - Make sure you know exactly what the code *should* do.  If you don't have a
     clear idea of what program should do, it will be difficult to figure out
     how it's going wrong.

   **Step 2:** What **does** it do?

   - Run the program, and pay close attention to everything it does.  For now,
     that will mostly involve observing its output.

   **Step 3:** Where do those two **diverge**?

   - The point at which the program *starts* to do something different than
     what you expect is the point at which you can focus your debugging
     efforts.  Once you know what it should do, what it does do, and how those
     differ, you can start thinking about why that difference might occur.
     What could have caused that?  Where in the code would it happen?  Focus
     there.

There are three main types of errors you might encounter.  Understanding each
type will help you analyze and fix them when you do.


.. index:: syntax error, invalid syntax, invalid token
   single: error; syntax

Syntax Errors
^^^^^^^^^^^^^

**Syntax errors** are errors in the form of the code itself, when it doesn't
conform to the the syntax rules of the language.

For example, if you put a space in a variable name, Python thinks it is two operands
without an operator, which is invalid:

.. code:: python

   >>> bad name = 5
   SyntaxError: invalid syntax

Or code might violate rules about how numbers can be formatted:

.. code:: python

   >>> month = 09
     File "<stdin>", line 1
       month = 09
                ^
   SyntaxError: invalid token

The most common messages are ``SyntaxError: invalid syntax`` and ``SyntaxError:
invalid token``, neither of which is very informative by itself.  But these are
the most straightforward to debug.  The answer to "what should it do?" is "not
crash," and Python will tell you exactly where in the program it diverges from
that expectation (by crashing).

To debug these, look closely at where Python is saying the error occurred, and
think through all of the syntax rules you know that are relevant to that line
and its surroundings.

At this point, the syntax errors you are most likely to make are either simple
typing mistakes or using illegal variable names, like ``class`` and ``yield``,
which are keywords, or ``odd~job`` and ``US$``, which contain illegal
characters.


.. index:: runtime error, NameError
   single: error; runtime

Runtime Errors
^^^^^^^^^^^^^^

**Runtime errors** occur when something goes wrong as the program is running.
These are not caused by invalid syntax; the syntax is correct, but it tells
Python to do something that is not possible or not allowed.

The runtime error you are most likely to make is a ``NameError``, caused by
trying to use a non-existent variable in an expression.  This can happen if you
try to use a variable before you have assigned it a value or if you spell a
variable name wrong:

.. code:: python

   >>> principal = 327.68
   >>> interest = principle * rate
   NameError: name 'principle' is not defined

Also remember: variables names are case sensitive, so ``LaTeX`` is not the same
as ``latex``.

As with syntax errors, runtime errors will tell you where in the code they
occurred.  However, that line is not necessarily the location of the bug
itself.  The code might have done something wrong earlier that only resulted in
an invalid operation later on, and Python won't know that.  You may have to
spend more time comparing details of what the program *should* do and what it
*does* do to debug these.


.. index:: semantic error
   single: error: semantic

Semantic Errors
^^^^^^^^^^^^^^^

We've discussed and seen several examples already of **semantic errors**.
These occur when the program has valid syntax and runs without crashing, but it
does not do what you, the programmer, were wanting or expecting it to do.

We've seen the following semantic errors so far:

- Writing an integer with commas, like ``1,000,000``.  Python interprets that
  as a sequence of multiple values, not just one integer.
- Trying to use an invalid variable name like ``pop-tarts``.  That is valid
  Python syntax, but it is an expression subtracting the value of ``tarts``
  from the value of ``pop``.
- Using ``input()`` to ask the user to enter a number without using ``int()``
  or ``float()`` to convert it to a numeric type.  See ActiveCode
  :ref:`input02 <input02>` for an example, and :ref:`input03 <input03>` for a
  corrected version.

.. index:: order of operations

At this point, the next most likely cause of a semantic error is the order of
operations.  For example, to evaluate :math:`\frac{1}{2\pi}`, you might be
tempted to write

.. code:: python

   1.0 / 2.0 * pi

But the division happens first, so you would get :math:`\frac{\pi}{2}`, which
is not the same thing!  There is no way for Python to know what you meant to
write, so in this case you don’t get an error message; you just get the wrong
answer.

Semantic errors don't give you help in the form of a crash report pointing to a
particular line.  For these, you always have to spend time comparing what the
program *should* do to what it *does* do.  But what if the program doesn't
output much, if anything at all, on the way to doing something wrong?


.. index:: print debugging

Print Debugging
^^^^^^^^^^^^^^^

One simple tool that can help you understand more about what your code is doing
as it runs is **print debugging**.  This simply means adding print statements
to the code that will show you the values of a program's variables as it is
running.  These print statements are not needed for the final program; they're
just temporary, added for the purpose of giving you more visibility into the
program's internal state.

As an example, imagine you've seen ``for`` loops and the ``range()`` function
(as in a few earlier examples), and so you try to use them to perform a simple
calculation:

.. activecode:: print-debugging-example

   print("This program finds the product of")
   print("the integers from 1 to 6.")

   product = 1
   for i in range(1, 6):
       product = product * i

   print("The product is:", product)

The code outputs a result of 120.  But the product should be 720.  So clearly
the program isn't working as intended, but what is going wrong?  All we see is
the incorrect output.  We need to know more about what is happening before
that.

The following program has added a single print statement, printing the value of
``i`` inside the loop.  Run it and look at the output.  Can you see what is
going wrong?  You might even think of a fix, even though we haven't learned how
much of this code works yet.

.. activecode:: print-debugging-example-augmented

   print("This program finds the product of")
   print("the integers from 1 to 6.")

   product = 1
   for i in range(1, 6):
       print("The value of i is now", i)
       product = product * i

   print("The product is:", product)


