Conventions Used in This Book
-----------------------------

This section describes and gives examples of the conventions used for
presenting code and other specific types of information throughout the book.


``code`` inline with text
^^^^^^^^^^^^^^^^^^^^^^^^^

Text formatted ``like this`` is used to indicate a piece of Python code,
usually a literal value, a variable name, or a function name.  For example, the
following two sentences have very different meanings given their formatting:

  The program's last variable is ``unused``.

  The program's ``last`` variable is unused.

The first sentence is talking about a variable named ``unused`` that is the
final variable in the program, while the second is referring to a variable
named ``last`` that is never used in the program.


Active code
^^^^^^^^^^^

Interactive, "live" code blocks called "Active Code" are included throughout
the book.  These allow you to *run* the code presented in your browser, seeing
its output immediately next to it, and *modify* the code to try new things and
see the effects of your changes.

Each block also keeps track of changes you've made to the code, letting you
change it back to a previous version using the slider bar that appears below,
and a "download" button lets you download the code in the block to your own
computer.

Try out the following block.  Run it, then change what it prints and run it
again.  Drag the slider that appears below to revert the code to its original
version.

.. activecode:: conventions01

   print("Hello, world!")


Static code; ``>>>`` prompts
^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Some blocks of code are included in static, non-interactive blocks, like so:

.. code:: python

   word1 = "Hello"
   word2 = "world"
   print(word1, word2)

And sometimes, when we want to show the result of some code along with the code
itself, we'll use the Python interpreter's convention of including a ``>>>``
prompt before lines of code and no prompt on lines of output:

.. code:: python

   >>> word1 = "Hello"
   >>> word2 = "world"
   >>> print(word1, word2)
   Hello world
 

Syntax patterns
^^^^^^^^^^^^^^^

TODO
