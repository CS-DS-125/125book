Conventions Used in This Book
-----------------------------

Before we teach you to code, we need to teach you how to read this book.
The first thing we need to teach you to do is to be able to tell the difference
between when we are talking to you about regular text and when we are talking
to you about code.  

``code`` inline with text
^^^^^^^^^^^^^^^^^^^^^^^^^

Text formatted like this: ``variable1`` is used to indicate Python code. 
Python code is how we will be talking to the computer and telling it what
to do. In this book we will sometimes be mixing words meant to be code into
non-code sentences. 
For example: 

  The program's last variable is ``unused``.

  The program's ``last`` variable is unused.

These entences have very different meanings given their formatting.
The first sentence is talking about a variable named ``unused`` that is the
final variable in the program, while the second is referring to a variable
named ``last`` that is never used in the program.


Active code
^^^^^^^^^^^

Interactive, "live" code blocks called "Active Code" are included throughout
the book.  These allow you to *run* the code and see the programs output 
immediately next to the block. You can also *modify* the code to try new 
things and see what happens.

Its easy to think you've got a clear understanding, when maybe you actually
don't. The "Active Code" is a way for you to find out if you've got a good
handle on the material. Each block keeps track of changes you've made to
the code, letting you change it back to a previous version using a slider 
bar under the block. 

If you want you can also click the "download" button lets you download the
code in the block to your own computer.

Try it out for yourself.  Run the block below, then change what it prints and run it
again.  Drag the slider that appears below to undo your changes.

.. activecode:: conventions01

   print("Hello, world!")


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

In the block above the first three lines are individual lines that were sent to
the computer. And the fourth line is the result the computer returned. Why use
the '>>>'? Well, one common way programmers interact with the computer is by 
using an intepreter, which is software that takes the programmer's code and 
converts into something the computer can understand called machine language. 
The '>>>' is a prompt commonly used in Python interpreters. It's sort of like 
saying' enter your code here'. The last line in our block above doesn't have 
the '>>>' which indicates that the is the computer's response. We will talk 
more about all this later in the course, for now just know that '>>>' 
indicates a line of code.  

Syntax patterns
^^^^^^^^^^^^^^^

TODO
