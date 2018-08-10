Conventions Used in This Book
-----------------------------

Before we teach you to code, we need to teach you how to read this book.
The first thing we need to teach you to do is to be able to tell the difference
between when we are talking to you about regular text and when we are talking
to you about code.  

``code`` inline with text
^^^^^^^^^^^^^^^^^^^^^^^^^

Text formatted like this: ``variable1`` is used to indicate Python code. 
Python code is how telling the computer what to do.  In this book we will 
sometimes be mixing words meant to be read as code into regular sentences. 

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

Try it out and Active Block for yourself.  Run the block below, then change what it
prints and run it again.  Drag the slider that appears below to undo your changes.

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

In the block above the first three lines are individual lines of instructions 
that were sent to the computer. And the fourth line is the result the computer
returned. 

Why use the '>>>'? Well, one way programmers interact with computers is by 
using an intepreter, which is software that takes the programmer's code and 
converts into something the computer can understand called machine language. 
The '>>>' is a prompt commonly used in Python interpreters. It's like 
saying' enter your code here'. The last line in our block above doesn't have 
the '>>>' which indicates that this is the computer's response. We will talk 
more about all this later in the course, for now just know that '>>>' 
indicates a line of code sent to the computer.  

Syntax patterns
^^^^^^^^^^^^^^^

TODO
