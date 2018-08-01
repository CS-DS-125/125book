Booleans
--------

.. index:: boolean expression

.. index:: expression!boolean

.. index:: logical operator

.. index:: operator!logical

A *boolean expression* is an expression that is either true or false.
The following examples use the operator ``==``, which compares two
operands and produces ``True`` if they are equal and ``False``
otherwise:

.. code:: python

   >>> 5 == 5
   True
   >>> 5 == 6
   False
   {}

``True`` and ``False`` are special values that belong to the class
``bool``; they are not strings:


.. index:: True special value

.. index:: False special value

.. index:: special value!True

.. index:: special value!False, bool type

.. index:: type!bool

.. code:: python

   >>> type(True)
   <class 'bool'>
   >>> type(False)
   <class 'bool'>

The ``==`` operator is one of the *comparison operators*; the others
are:

.. code:: python

   x != y               # x is not equal to y
   x > y                # x is greater than y
   x < y                # x is less than y
   x >= y               # x is greater than or equal to y
   x <= y               # x is less than or equal to y
   x is y               # x is the same as y
   x is not y           # x is not the same as y

Although these operations are probably familiar to you, the Python
symbols are different from the mathematical symbols for the same
operations. A common error is to use a single equal sign (``=``) instead
of a double equal sign (``==``). Remember that ``=`` is an assignment
operator and ``==`` is a comparison operator. There is no such thing as
``=<`` or ``=>``.


.. index:: comparison operator

.. index:: operator!comparison

Logical operators
^^^^^^^^^^^^^^^^^


.. index:: logical operator

.. index:: operator!logical

There are three *logical operators*: ``and``, ``or``, and ``not``. The
semantics (meaning) of these operators is similar to their meaning in
English. For example,

``x > 0 and x < 10``

is true only if ``x`` is greater than 0 *and* less than 10.


.. index:: and operator, or operator

.. index:: not operator, operator!and

.. index:: operator!or, operator!not

``n%2 == 0 or n%3 == 0`` is true if *either* of the conditions is true,
that is, if the number is divisible by 2 *or* 3.

Finally, the ``not`` operator negates a boolean expression, so
``not (x > y)`` is true if ``x > y`` is false; that is, if ``x`` is less
than or equal to ``y``.

Strictly speaking, the operands of the logical operators should be
boolean expressions, but Python is not very strict. Any nonzero number
is interpreted as "true."

.. code:: python

   >>> 17 and True
   True

This flexibility can be useful, but there are some subtleties to it that
might be confusing. You might want to avoid it until you are sure you
know what you are doing.





Logical operators often provide a way to simplify nested conditional
statements. For example, we can rewrite the following code using a
single conditional:

.. code:: python

   if 0 < x:
       if x < 10:
           print('x is a positive single-digit number.')

The ``print`` statement is executed only if we make it past both
conditionals, so we can get the same effect with the ``and`` operator:

.. code:: python

   if 0 < x and x < 10:
       print('x is a positive single-digit number.')



Short-circuit evaluation of logical expressions
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^


.. index:: short circuit

When Python is processing a logical expression such as
``x >= 2 and (x/y) > 2``, it evaluates the expression from left to
right. Because of the definition of ``and``, if ``x`` is less than 2,
the expression ``x >= 2`` is ``False`` and so the whole expression is
``False`` regardless of whether ``(x/y) > 2`` evaluates to ``True`` or
``False``.

When Python detects that there is nothing to be gained by evaluating the
rest of a logical expression, it stops its evaluation and does not do
the computations in the rest of the logical expression. When the
evaluation of a logical expression stops because the overall value is
already known, it is called *short-circuiting* the evaluation.


.. index:: guardian pattern

.. index:: pattern!guardian

While this may seem like a fine point, the short-circuit behavior leads
to a clever technique called the *guardian pattern*. Consider the
following code sequence in the Python interpreter:

.. code:: python

   >>> x = 6
   >>> y = 2
   >>> x >= 2 and (x/y) > 2
   True
   >>> x = 1
   >>> y = 0
   >>> x >= 2 and (x/y) > 2
   False
   >>> x = 6
   >>> y = 0
   >>> x >= 2 and (x/y) > 2
   Traceback (most recent call last):
     File "<stdin>", line 1, in <module>
   ZeroDivisionError: division by zero
   >>>

The third calculation failed because Python was evaluating ``(x/y)`` and
``y`` was zero, which causes a runtime error. But the second example did
*not* fail because the first part of the expression ``x >= 2`` evaluated
to ``False`` so the ``(x/y)`` was not ever executed due to the
*short-circuit* rule and there was no error.

We can construct the logical expression to strategically place a *guard*
evaluation just before the evaluation that might cause an error as
follows:

.. code:: python

   >>> x = 1
   >>> y = 0
   >>> x >= 2 and y != 0 and (x/y) > 2
   False
   >>> x = 6
   >>> y = 0
   >>> x >= 2 and y != 0 and (x/y) > 2
   False
   >>> x >= 2 and (x/y) > 2 and y != 0
   Traceback (most recent call last):
     File "<stdin>", line 1, in <module>
   ZeroDivisionError: division by zero
   >>>

In the first logical expression, ``x >= 2`` is ``False`` so the
evaluation stops at the ``and``. In the second logical expression,
``x >= 2`` is ``True`` but ``y != 0`` is ``False`` so we never reach
``(x/y)``.

In the third logical expression, the ``y != 0`` is *after* the ``(x/y)``
calculation so the expression fails with an error.

In the second expression, we say that ``y != 0`` acts as a *guard* to
insure that we only execute ``(x/y)`` if ``y`` is non-zero.

