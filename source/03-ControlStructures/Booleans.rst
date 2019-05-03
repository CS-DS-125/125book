.. index:: Boolean

Booleans
--------

We've seen ``<condition>`` in two patterns so far: the conditional (``if``
statements) and the while loop.  Until now, we've just said that it should be
an expression that evaluates to ``True`` or ``False`` without going into much
detail.  It turns out that there is a specific *data type* that is used for
these values (``True`` and ``False``) and for the expressions used in conditions:
the **Boolean** data type.

.. activecode:: boolean01

   print(type(True))
   print(type(False))

.. index:: True, False, bool type, type;bool

``True`` and ``False`` are the only two values that this ``bool`` data type can have.
Note that they are *not* strings; they aren't written in quotation marks.

.. index:: Boolean expression, comparison operator, operator;comparison

Comparison Operators
^^^^^^^^^^^^^^^^^^^^

So if every condition for an ``if`` or ``while`` statement needs to evaluate to a
Boolean value, how do we write expressions that produce the correct type?
We've already seen some examples:

.. code:: python

   x < y
   n > 0
   choice == 'a'

These are **Boolean expressions**, meaning they each evaluate to a Boolean
value.  Each of those expressions is an *operator* with two *operands*.  The
``==`` operator compares two operands and produces ``True`` if their values are
equal and ``False`` otherwise:

.. code:: python

   >>> 5 == 5
   True
   >>> 5 == 6
   False
   >>> x = 'hello'
   >>> y = 'hello'
   >>> x == y
   True

The complete list of comparison operators:

.. table::
   :align: left

   ================ ===============================
   Operator         Interpretation
   ================ ===============================
   ``x == y``       x is equal to y
   ``x != y``       x is not equal to y
   ``x > y``        x is greater than y
   ``x < y``        x is less than y
   ``x >= y``       x is greater than or equal to y
   ``x <= y``       x is less than or equal to y
   ================ ===============================

.. caution::

   Although these operations are probably familiar to you, the Python symbols are
   different from the mathematical symbols for the same operations. A common error
   is to use a single equal sign (``=``) instead of a double equal sign (``==``).
   But ``=`` is an assignment operator and ``==`` is a comparison operator.

   **Remember:** ``=`` is *setting* something equal to a value, while ``==`` is
   *asking a question* about whether two things *are* equal.

   Also, there is no such thing in Python as ``=<`` or ``=>``.  They're always
   written like they're most commonly said aloud: e.g., ``<=`` is "less than or
   equal to."


.. index:: logical operator, operator;logical
.. index:: and operator, or operator, not operator

Logical Operators
^^^^^^^^^^^^^^^^^

Sometimes we need a condition to depend on more than one comparion.  For
example, what if we wanted a while loop to continue as long as one variable was
greater than 5 and another was less than 5?  In Python, we can *often* (though
certainly not always!) write a condition just as we would say it in English:

.. activecode:: boolean02

   x = 8
   y = 3
   while x > 5 and y < 5:
      print("Still going!  x is", x, "and y is", y)
      x = x - 1
      y = y + 1
   print("Done.  x is", x, "and y is", y)

There are three **logical operators**: ``and``, ``or``, and ``not``. The
semantics (meaning) of these operators is similar to their meaning in English.
For example,

``x > 0 and x < 10``

is true only if ``x`` is greater than 0 *and* less than 10.

``n%2 == 0 or n%3 == 0`` is true if *either* of the conditions is true, that
is, if the number is divisible by 2 *or* 3.

Finally, the ``not`` operator negates a boolean expression, so ``not (x > y)``
is true if ``x > y`` is false; that is, if ``x`` is less than or equal to
``y``.

.. caution::

   One common mistake for beginning programmers is to write conditions like this:

   .. code:: python
   
      x > 0 and < 10

   or like this:

   .. code:: python

      age == 18 or 19 or 20

   You might want to read the first example as "x is greater than 0 and less
   than 10," and the second *looks* like "age is 18, 19, or 20."  But in
   Python, these are both *invalid syntax*!  Remember that ``and`` and ``or``
   are operators that take two *independent* Boolean operands, one on each
   side.  That is, each side of an ``and`` or an ``or`` must be something that
   evaluates to ``True`` or ``False`` by itself.
 
   On the left side of the ``and``, ``x > 0`` is a valid Boolean expression
   that will evaluate to ``True`` or ``False``, but on the right side, ``< 10``
   is not a valid expression!

.. admonition:: Check your understanding

   .. mchoice:: cyu_bool01
      :answer_a: year > 1900 < 2000
      :answer_b: year > 1900 and < 2000
      :answer_c: year > 1900 or < 2000
      :answer_d: year > 1900 and year < 2000
      :answer_e: year > 1900 or year < 2000
      :correct: d
      :feedback_a: This is invalid syntax.  The '<' operator has to be given two numbers, but its left hand side in this case is a Boolean value.
      :feedback_b: This is invalid syntax.  The 'and' operator has to be given two Boolean values, but its right hand side in this case is an invalid expression, because the '<' needs a number on its left hand side.
      :feedback_c: This is invalid syntax.  The 'or' operator has to be given two Boolean values, but its right hand side in this case is an invalid expression, because the '<' needs a number on its left hand side.
      :feedback_d: Correct!
      :feedback_e: This expression will evaluate to 'True' if 'year' is holding any number at all.  The 'or' evaluates to 'True' if either side is 'True', and in thise case, at least one of the two sides will always be 'True'.

      Which of the following expressions is a correct, valid Python expression
      for checking whether the ``year`` variable's value is between 1900 and
      2000?
   

Logical operators often provide a way to simplify nested conditional
statements. For example, we can rewrite the following code using a single
conditional:

.. activecode:: boolean03

   x = int(input("Please enter an integer: "))
   if 0 < x:
       if x < 10:
           print("x is a positive single-digit number.")

The ``print`` statement is executed only if we make it past both conditionals,
so we can get the same effect with the ``and`` operator:

.. activecode:: boolean04

   x = int(input("Please enter an integer: "))
   if 0 < x and x < 10:
       print("x is a positive single-digit number.")

.. admonition:: Check your understanding

   .. code:: python

      if year == 1969:
          if month == 'July':
              if day == 20:
                  print("Moon landing!")

   In the ActiveCode below, rewrite the above conditional using a single if
   statement with one conditional expression that is equivalent.

   .. activecode:: cyubool02

      # Your code here.

   You can test your code and practice writing ``input()`` statements by adding
   code that asks you to input a year, month, and day before the if statement.
