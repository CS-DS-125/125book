.. index::
   single: variable; updating

Updating Variables
------------------

A common pattern in assignment statements is an assignment statement
that updates a variable, where the new value of the variable depends on
the old.

.. code:: python

   x = x + 1

This is the type of statement that makes little sense in mathematics (unless x
is :math:`\infty` perhaps), but remember: :ref:`assignment is not equality
<assignment-is-not-equality>`.  According to the :ref:`assignment statement
syntax pattern <assignment-statement>`, this is interepreted by *first* evaluating the expression on the right, ``x + 1``, and *then* assigning that value to ``x``.  So the statement means "get the current value of
``x``, add 1 to it, and then update ``x`` with the new value."

If you try to update a variable that doesn’t exist, you get an error,
because Python evaluates the right side before it assigns a value to
``x``:

.. activecode:: updatingvars01

   x = x + 1

Before you can update a variable, you have to *initialize* it, usually
with a simple assignment:

.. code:: python

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
      -   :36: Correct.  ``x`` gets the sum of ``x`` (before the update) and ``y``.
          :x: Incorrect.  ``x`` gets the sum of ``x`` (before the update) and ``y``.
      -   :36: Correct.  Assigning ``z`` doesn't change ``x``.
          :x: Incorrect.  Assigning ``z`` doesn't change ``x``.
      -   :34: Correct.  ``x`` gets the value of ``y``, which hasn't changed since it was initialized.
          :x: Incorrect.  ``x`` gets the value of ``y``, which hasn't changed since it was initialized.
