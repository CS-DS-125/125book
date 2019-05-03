

.. index:: operator, operand, expression
   pair: arithmetic; operations
   single: +; addition
   single: -; subtraction
   single: *; multiplication
   single: **; exponentiation
   single: ( ); grouping


Operators and Operands
----------------------

**Operators** are special tokens (usually symbols) that represent computations
like addition and multiplication. The values the operator is applied to are
called **operands**.  For example, in the expression ``5 + 10``, the operator is
``+``, and the values ``5`` and ``10`` are operands.

Python uses ``+`` and ``-`` and parentheses (for grouping) in the same way they
are used in arithmetic.

Multiplication, division, and exponentiation
use ``*``, ``/``, and ``**``, respectively.  So ``3 * 4`` is "three times four"
and ``3 ** 4`` is "three raised to the fourth power" or :math:`3^4`.

The following code demonstrates the use of operators.

.. activecode:: operators01

   print(2 + 3)
   print(2 - 3)
   print(2 * 3)
   print(2 / 3)
   print(2 ** 3)
   print(3 ** 2)

.. index:: order of operations

When more than one operator appears in an expression, the order of
evaluation depends on the *rules of precedence*.  For mathematical
operators, Python follows mathematical convention:

Parentheses, Exponentiation, Multiplication and Division,
Addition and Subtraction.

.. tip::

   When in doubt, always put parentheses in your expressions to make sure the
   computations are performed in the order you intend.  Even if it would work
   correctly without them, parentheses can help you and others understand
   complex expressions.


.. index:: integer division (//)
   single: /; division
   single: //; integer division

Divison
^^^^^^^

In Python 3, the division operation always evaluates to a `float`, even if the
result is a whole number.  For example:

.. activecode:: operators02

    print(4 / 2)
    print(100 / 1)
    print(type(100 / 1))

.. note::

   See how the values are printed with decimal points even though the decimal
   part is zero?  That is how Python indicates a value is a `float`.

So for example, if we wanted to convert a number of minutes, stored in a
``minutes`` variable, into hours:

.. activecode:: operators03

    minutes = 1234
    hours = minutes / 60
    print(hours)

What if we just wanted to know how many *whole* hours are in 1234 minutes?  Python provides a different division operator that can help.  **Integer division** uses the token ``//``.  It always rounds its result down to the nearest smaller integer (moving left on the number line):

.. activecode:: operators04
    :nocanvas:

    print(7 / 3)
    print(7 // 3)
    print(-7 // 3)  # ! This is *not* just the negation of the previous
    minutes = 1234
    whole_hours = minutes // 60
    print(whole_hours)


.. index:: modulus, remainder
   single: %; modulus / remainder

Modulus
^^^^^^^

The **modulus** operator works on integers and produces the **remainder** when
the first operand is divided by the second. In Python, the modulus operator is
a percent sign ``%``.

.. activecode:: operators05

   quotient = 7 // 3  # Integer division
   print(quotient)
   remainder = 7 % 3  # Modulus (remainder)
   print(remainder)

Here, 7 divided by 3 is 2 (the quotient) with 1 left over (the remainder).

.. index:: divisibility

The modulus operator turns out to be surprisingly useful. For example, you can
check whether one number is divisible by another: if ``x % y`` is zero, then
``x`` is divisible by ``y``.  The following code finds numbers divisible by 9
(it uses a ``for`` loop and other things we'll learn about later, but you can
get an idea of how it works by reading the code and changing parts to see what
happens):

.. activecode:: operators06

   for i in range(1, 100):
       if (i % 9) == 0:
           print(i, "is divisible by 9!")

You can also get the right-most digit or digits from a number using modulus.
For example,``x % 10`` give you the right-most digit of ``x`` (in base 10).
Similarly, ``x %100`` gives you the last two digits of ``x``.

.. activecode:: operators07

   for i in range(15, 25):
       last_digit = i % 10
       print("i =", i, " last digit =", last_digit)

.. index::
   pair: string; operations
   pair: string; concatenation
   pair: string; repetition

Example
^^^^^^^

Let's say we have a number of days, and we want to know how long that
is in other units of time. For example, what is 17 days in hours? 
What is 17 days in weeks?

Converting to hours can be done with multiplication. If we set
``days = 17``, and then enter the code ``hours = days * 24`` the
computer would calculate our answer. 

But what if we want something a bit more complicated, like 
converting days into weeks plus days?  For example, how could
we write a program where we enter ``days = 17`` and it then
tells us: ``2 weeks and 3 days``?

See if you can figure out how the code below uses division and
modulus to get the make this conversion.  

.. activecode:: operators_example

   days = 123
   # Convert days to hours
   hours = days * 24
   # Convert hours to minutes
   minutes = hours * 60
   # Convert days to *whole* weeks
   weeks = days // 7
   # Find the remainder as remaining days
   remaining_days = days % 7

   # Print our results
   print(days, "days is:")
   print(hours, "hours")
   print(minutes, "minutes")
   print(weeks, "weeks and", remaining_days, "days")

String Operations
^^^^^^^^^^^^^^^^^

Most of the operations that work with numbers don't make sense when applied to
strings.  For example, as we've seen, ``'Cat' / 'Dog'`` is an invalid
expression in Python.  But two of the operators above are defined for strings,
though they do not perform arithmetic when applied to strings.

The ``+`` operator works with strings, but it is not addition in the
mathematical sense. Instead it performs *concatenation*, which means joining
the strings by linking them end to end. For example:

.. activecode:: operators08

   first = 10
   second = 15
   print(first + second)

   first = '100'
   second = '150'
   print(first + second)

The ``*`` operator also works with strings if applied to a string and an
integer.  In this case, the operation is called **string repetition**.

.. activecode:: operators09

   print("Hello" * 5)

   word = 'Test'
   number = 4
   print(word * number)


Table of Operators
^^^^^^^^^^^^^^^^^^

The following table summarizes the operators discussed above.

.. table::
   :align: left

   ========== ====================== =============== 
   Operator   int, float Operation   str Operation 
   ========== ====================== =============== 
   ``+``      Addition               Concatenation 
   ``-``      Subtraction                   
   ``*``      Multiplication         Repetition    
   ``/``      Division                      
   ``//``     Integer Division               
   ``%``      Modulus
   ``**``     Exponentiation                
   ========== ====================== ===============

