.. index::
   single: variable; updating

Updating Variables
------------------

A common pattern in assignment statements is an assignment statement that
updates a variable, where the new value of the variable depends on the old
value of the variable.

.. code:: python

   x = x + 1

As a math equation this doesn't make a lot of sense (unless x is
:math:`\infty`), but this works in programming beause :ref:`assignment is not
equality <assignment-is-not-equality>`.  According to the :ref:`assignment
statement syntax pattern <assignment-statement>`, the computer will *first*
evaluate the expression on the right, ``x + 1``, and *then* assign that value
to ``x``.  So the statement means "get the current value of ``x``, add 1 to it,
and then update ``x`` with the new value."

If x doesn't exist yet and has no value this staement will give you an error.
Python will evaluate the right side and be unable to proceed.  Try this:

.. activecode:: updatingvars01

   x = x + 1

What's missing?
Before you can update a variable, you have to *initialize* it, usually
with a simple assignment:

.. activecode:: updatingvars02

   # initialize x
   x = 0

   # update x
   x = x + 1


.. index:: increment, decrement

Updating a variable by adding or subtracting 1 is very common in programming, and so those updates have special names:

.. admonition:: Definition

   Updating a variable by adding 1 is called an **increment**, and subtracting 1
   is called a **decrement**.

.. admonition:: Check your understanding

   .. fillintheblank:: cyi_updatingvars01

      If each of the following lines of code are run one after the other, what
      will the value of ``x`` be after each line?  Write the value ``x`` holds
      after each line executes in the blank to the right of the line.

      ``x = 12`` |blank|

      ``y = 34`` |blank|

      ``z = 56`` |blank|

      ``x = x + y`` |blank|

      ``z = x`` |blank|

      ``x = y`` |blank|

      -   :12: Correct.  The assignment statement gives ``x`` a value.
          :x: Incorrect.  The assignment statement gives ``x`` a value.
      -   :12: Correct.  Assigning a value to ``y`` doesn't change ``x``.
          :x: Incorrect.  Assigning a value to ``y`` doesn't change ``x``.
      -   :12: Correct.  Assigning a value to ``z`` doesn't change ``x``.
          :x: Incorrect.  Assigning a value to ``z`` doesn't change ``x``.
      -   :46: Correct.  ``x`` gets the sum of ``x`` (before the update) and ``y``.
          :x: Incorrect.  ``x`` gets the sum of ``x`` (before the update) and ``y``.
      -   :46: Correct.  Assigning ``z`` doesn't change ``x``.
          :x: Incorrect.  Assigning ``z`` doesn't change ``x``.
      -   :34: Correct.  ``x`` gets the value of ``y``, which hasn't changed since it was initialized.
          :x: Incorrect.  ``x`` gets the value of ``y``, which hasn't changed since it was initialized.
