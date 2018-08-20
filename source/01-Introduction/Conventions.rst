Conventions Used in This Book
-----------------------------

Before we teach you to code, we need to teach you how to read this book.
The first thing we need to teach you to do is to be able to tell the difference
between when we are talking to you about regular text and when we are talking
to you about code.  

``code`` inline with text
^^^^^^^^^^^^^^^^^^^^^^^^^

Text formatted like this: ``variable1`` is used to indicate Python code. 
Python code is how we will be telling the computer what to do.  In this book we
will sometimes be mixing words meant to be read as code into regular sentences.

For example: 

  The program's last variable is ``unused``.

  The program's ``last`` variable is unused.

These sentences have very different meanings. The first sentence is talking
about a variable named ``unused`` that is the final variable in the program. 
The second sentence is referring to a variable named ``last`` that is never
used in the program.


Active code
^^^^^^^^^^^

Interactive, "live" code blocks called "Active Code" are included throughout
the book.  These allow you to *run* the code and see the programs output 
immediately next to the block. You can also *modify* the code to try new 
things and see what happens. The "Active Code" is a great way for you to 
check your understanding of the material. 

We encourage you to look at the code in each block before you run it and try
to make a prediction about what will happen when you do. If it doesn't do quite
what you thought, it's worth figuring out why and paying attention to all of the
bits of the code. In programming, the details really matter. The Active Code blocks
are there to help you figure out the details.

Don't be hesitant to mess around and change the Code Blocks. Each block keeps track
of changes you've made and lets you change it back to a previous version using a
slider bar under the block. 

If you want to keep your code, you can also click the "download" button in the block. 

Try out an Active Code Block for yourself.  Run the code below, then change
what it prints and run it again.  Drag the slider that appears below to undo
your changes.

.. activecode:: conventions01

   print("Hello, world!")

The "Show CodeLens" will bring up the block's code in an interactive tool
called `Online Python Tutor <http://pythontutor.com/>`_ that allows you to
**visualize** what the code is doing, step-by-step and line-by-line.  For the
above program, this isn't very interesting, because it is a single, simple
line.  For any later code that is not immediately obvious, though, using this
"CodeLens" can help you gain a *much* better understanding of how the code
works.

Static code; ``>>>`` prompts
^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Some blocks of code are included in non-interactive blocks that you can't
change. Non-interactive blocks look like this:

.. code:: python

   word1 = "Hello"
   word2 = "world"
   print(word1, word2)

And sometimes, when we want to show the result of some code along with the code
itself, we'll use this: ``>>>``

.. code:: python

   >>> word1 = "Hello"
   >>> word2 = "world"
   >>> print(word1, word2)
   Hello world

In the block above the first three lines are individual lines of instructions 
that were sent to the computer. And the fourth line is the result the computer
returned. 

.. index:: REPL, read-evaluate-print loop

Why use the ``>>>``? Well, one way programmers interact with computers is by
using a **read-evaluate-print loop (REPL)**.  A REPL is software that *reads* a
line of code typed in by a user, *evaluates* it to determine its value, and
*prints* that value back to the user.  The ``>>>`` is a prompt commonly used in
Python REPLs. It's like saying 'Enter your code here.'

So the example above includes three lines entered by the user (the first three
with the ``>>>`` prompts).  The first two lines did not print anything, because
(as we'll see soon), they are assignments that don't output or produce any
value themselves.  The last line entered by the user, ``print(word1, word2)``
does have an output below it, which is the result of evaluating that line.

If you want to try out a Python REPL yourself, you can access one online at
`https://www.python.org/shell/ <https://www.python.org/shell/>`_.  Or, if you
have Python installed on your own computer, you may be able to access its REPL
by running the ``python3`` command in a Terminal or Command Prompt (details
depend on your operating system).

.. index:: syntax
.. _syntax-definition:

Syntax patterns
^^^^^^^^^^^^^^^

A critical pieces of learning a programming langauge is knowing its **syntax**.
The syntax of a language is the set of rules that specify what is a *valid*
program and what is not.  Any program that does not follow all of the syntax rules
of its language cannot be run.

Throughout this book, we will present syntax *patterns* each time we present a new
piece of Python's syntax.  They will look like this:

.. admonition:: Syntax Pattern

   Details of the pattern will go here.

These are *formal*, *precise* rules about how Python must be written.  It's
worth memorizing their details (there aren't many, to be honest) and keeping
them in mind whenever you are writing your own code or reading someone else's.
