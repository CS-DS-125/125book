How to Use This Book
--------------------

As you progress through the rest of the book, don’t be afraid if the
concepts don’t seem to fit together well the first time. When you were
learning to speak, it was not a problem for your first few years that
you just made cute gurgling noises. And it was OK if it took six months
for you to move from simple vocabulary to simple sentences and took several
more years to move from sentences to paragraphs, and a few more years to be
able to write an interesting complete short story on your own.

We want you to learn Python much more rapidly, so we teach it all at the
same time over the next few chapters. But it is like learning a new
language that takes time to absorb and understand before it feels
natural. That leads to some confusion as we visit and revisit topics to
try to get you to see the big picture while we are defining the tiny
fragments that make up that big picture. While the book is written
linearly, and if you are taking a course it will progress in a linear
fashion, don’t hesitate to be very nonlinear in how you approach the
material. Look forwards and backwards and read with a light touch. By
skimming more advanced material without fully understanding the details,
you can get a better understanding of the "why?" of programming. By
reviewing previous material and even redoing earlier exercises, you will
realize that you actually learned a lot of material even if the material
you are currently staring at seems a bit impenetrable.

Usually when you are learning your first programming language, there are
a few wonderful "Ah Hah!" moments where you can look up from pounding
away at some rock with a hammer and chisel and step away and see that
you are indeed building a beautiful sculpture.

If something seems particularly hard, there is usually no value in
staying up all night and staring at it. Take a break, take a nap, have a
snack, explain what you are having a problem with to someone (or perhaps
your dog), and then come back to it with fresh eyes. I assure you that
once you learn the programming concepts in the book you will look back
and see that it was all really easy and elegant and it simply took you a
bit of time to absorb it.

Conventions Used in This Book
-----------------------------

So we are about to start diving into how to code.  But before we teach you to
code, we need to teach you how to read this book.  The first thing we need to
teach you to do is to be able to tell the difference between when we are
talking to you about regular text and when we are talking to you about code.  

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

A critical piece of learning a programming langauge is knowing its **syntax**.
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
