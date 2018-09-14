
Built-In Functions
------------------

Python provides a number of important built-in functions that we can use
without needing to provide the function definition. The creators of
Python wrote a set of functions to solve common problems and included
them in Python for us to use.  We've seen and used several already:

::

   print()
   len()
   input()
   int()
   float()
   str()
   range()
   min()
   max()
   sum()

You already have a good idea of what these do, but now we can describe them
more precisely.  For example: "The ``print()`` function prints its arguments on
the screen, separating them with spaces if there are multiple arguments."  We
now have the word *arguments* to describe the values we've been passing into
the ``print()`` function.

Or for another example: "The ``len()`` function returns the number of items in
its argument."  We can describe the function in terms of its *return value*
and *argument*.

.. note::

   You should treat the names of built-in functions as reserved words
   (i.e., avoid using "max" as a variable name).

   Technically, Python will allow you to "override" their built-in definitions,
   but it is likely to lead to confusion.

.. index:: math module, math library
.. index:: module, module object

Math Functions
~~~~~~~~~~~~~~

Python has a ``math`` **module** (sometimes called a **library**) that provides
most of the familiar mathematical functions. Before we can use the module, we
have to import it with an **import statement**:

.. code:: python

   import math

.. note::

   Import statements are almost always written at the top of our program,
   above any other code.  This gives us one quick place to look to see what
   modules the code is using, instead of having to look for import statments
   throughout the whole program.

.. index:: dot notation

This statement creates a **module object** named ``math``.  that contains a
large set of built-in mathematical functions (and some variables).  To access
one of the functions, you have to specify the name of the module and the name
of the function, separated by a dot (also known as a period). This format is
called **dot notation**.

.. admonition:: syntax pattern

   Dot notation is used to access a function inside a module object:

   ::

      <module name>.<function name>(<arguments>)

   This can be read as "access <function name> *inside* <module name>, and call
   it with <arguments>."

   To access a variable within a module:

   ::

      <module name>.<variable name>

   In general, if we write ``A.B`` for any ``A`` and ``B``, it means "the thing named ``B`` inside the module named ``A``."

   Make sure you get the direction right!  It is always accessing the name on the **right** in the module on the **left**.

.. index:: log function
.. index:: sine function
.. index:: trigonometric function

.. activecode:: builtins01

   import math

   signal_power = 120
   noise_power = 30
   ratio = signal_power / noise_power
   decibels = 10 * math.log10(ratio)
   print("Signal:", signal_power, " Noise:", noise_power)
   print("Decibels:", decibels)

This example uses a function named ``log10()`` inside the ``math`` module to
compute the logarithm base 10 of a signal-to-noise ratio.  The math module also
provides a function called ``log()`` that computes logarithms base :math:`e`.
(If none of that is familiar to you, don't worry!  It's just an example of some
mathematical functions that are commonly used in certain types of
calculations.)

.. activecode:: builtins02

   import math

   radians = 0.7
   height = math.sin(radians)
   print(height)

.. index:: pi

This second example finds the sine of ``radians``. The name of the
variable is a hint that ``sin()`` and the other trigonometric functions
(``cos()``, ``tan()``, etc.) take arguments in radians. To convert from
degrees to radians, divide by 360 and multiply by :math:`2 \pi`.  The constant :math:`\pi` is an important, commonly used value, and so it is provided in the ``math`` module as well:

.. activecode::  builtins03

   import math

   degrees = 45
   radians = degrees / 360.0 * 2 * math.pi
   print(math.sin(radians))

The expression ``math.pi`` gets the variable ``pi`` from the math
module. The value of this variable is an approximation of :math:`\pi`,
accurate to about 15 digits.

.. index:: sqrt() function, square root

Rules of trigonometry can show that we can check the previous result by
comparing it to the square root of two divided by two.  The square root
function is another common function provided by the ``math`` module:

.. activecode::  builtins04

   import math

   print(math.sqrt(2) / 2.0)


The full list of functions and values defined in the ``math`` module is available in the official documentation for Python: `Documentation for the math module <https://docs.python.org/3/library/math.html>`_


.. index:: random number
.. index:: deterministic, pseudorandom

Random Numbers
~~~~~~~~~~~~~~

Given the same inputs, most computer programs generate the same outputs every
time, so they are said to be **deterministic**. Determinism is usually a good
thing, since we expect the same calculation to yield the same result. For some
applications, though, we want the computer to be unpredictable. Games are an
obvious example, but there are more.

Making a program truly nondeterministic turns out to be not so easy, but there
are ways to make it at least seem nondeterministic. One of them is to use
**algorithms** that generate **pseudorandom** numbers. Pseudorandom numbers are
not truly random because they are generated by a deterministic computation, but
just by looking at the numbers it is all but impossible to distinguish them
from random.

.. index:: random module

The ``random`` module provides functions that generate pseudorandom numbers
(which we will simply call "random" from here on).  Again, to use it, we just have to write ``import random`` at the top of our code.

The function ``random()`` returns a random float between 0.0 and 1.0
(including 0.0 but not 1.0). Each time you call ``random()``, you get the
next number in a long series. To see a sample, run this loop:

.. activecode:: random01

   import random

   for i in range(10):
       x = random.random()
       print(x)

This program produces the following list of 10 random numbers between 0.0 and
up to but not including 1.0.  Every time you run it, it produces a different
set of numbers.

The ``random()`` function is only one of many functions in the ``random``
module. The function ``randint()`` takes two arguments, a low value and a high
value (in that order), and it returns an integer from the range between the two
values (including both).

.. activecode:: random02

   import random

   for i in range(10):
       x = random.randint(10, 20)
       print(x)

To choose an element from a sequence at random, you can use ``choice()``:

.. activecode:: random03

   import random

   options = ['dog', 'cat', 'emu', 'llama', 'guppy']
   for i in range(10):
       animal = random.choice(options)
       print(animal)


The ``random`` module also provides functions to generate random values
from continuous distributions including Gaussian, exponential, gamma,
and a few more.  As with the ``math`` module, the ``random`` module is fully documented in Python's official documentation: `Documentation for the random module <https://docs.python.org/3/library/random.html>`_

Other Modules
~~~~~~~~~~~~~

The ``math`` and ``random`` modules are commonly used, especially when dealing
with data.  Many others are provided as part of what is called Python's
"Standard Library."  The full list is in Python's documentation: `The Python
Standard Library <https://docs.python.org/3/library/>`_.  Scroll through that page to get a sense of what sorts of modules are available.  You'll see modules related to strings, files, numbers, dates, and much more.

Many common calculations and tools have been written and provided in modules.
It is commonly said in programming: "Don't reinvent the wheel."  Common, basic
problems have been solved for you already and functions provided for them.  If
you use those functions, you can focus your time and energy on the more
interesting problems that are more specific to your work.

.. admonition:: Remember

   To use any function provided by a module in Python's standard library:

   1. Write an *import statement* at the top of your program: ``import modulename``
   2. Use *dot-notation* to access a function within the module: ``modulename.functionname()``

