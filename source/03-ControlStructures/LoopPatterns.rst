.. index:: accumulator variable

Common Loop Patterns
--------------------

We often use a ``for`` or ``while`` loop to iterate over a list of items
or the contents of a file looking to compute something from that data.
Commonly, we might want to compute a count, a sum, the largest or smallest
value, or some other result that can be found by looking at each value in the
list.

These loops are generally constructed with a few common pieces:

1. Initialize an **accumulator variable** before the loop starts that will hold
   a partial result as the loop executes and the final result when it finishes.
2. Iterate over every value using a loop.
3. In the loop body, perform some computation on each value, possibly changing
   the accumulator variable based on that computation.
4. When the loop completes, the accumulator variable holds the value you wanted
   to compute.

We will use a list of numbers to demonstrate the concepts and construction of
these loop patterns.

Counting and Summing Loops
~~~~~~~~~~~~~~~~~~~~~~~~~~

For example, to count the number of items in a list, we would write the
following ``for`` loop:

.. activecode:: looppattern01

   count = 0
   for itervar in [3, 41, 12, 9, 74, 15]:
       count = count + 1
   print('Count: ', count)

Here, the accumulator variable is ``count``.  We set ``count`` to zero before
the loop starts, and then we write a ``for`` loop to run through the list of
numbers. Our *iteration* variable is named ``itervar``, and while we do not use
``itervar`` in the loop, it does control the loop and cause the loop body to be
executed once for each of the values in the list.

In the body of the loop, we update the accumulator variable by adding 1 to the
current value of ``count`` for each of the values in the list. While the loop
is executing, the value of ``count`` is the number of values we have seen "so
far."

Once the loop completes, the value of ``count`` is the total number of
items. We constructed the loop so that we have what we want when the loop
finishes.

Another similar loop that computes the sum or total of a set of numbers is as
follows:

.. activecode:: looppattern02

   total = 0
   for itervar in [3, 41, 12, 9, 74, 15]:
       total = total + itervar
   print('Total: ', total)

In this loop we *do* use the iteration variable. Instead of simply adding one
to the ``count`` as in the previous loop, we add the actual number (3, 41, 12,
etc.) to the running total during each loop iteration. If you think about the
variable ``total``, it contains the "running total of the values so far."
Before the loop starts, ``total`` is zero because we have not yet seen any
values; during the loop ``total`` is the running total; and at the end of the
loop ``total`` is the overall total of all the values in the list.

As the loop executes, ``total`` accumulates the sum of the elements; it is the
accumulator variable in this example.

.. index:: len() function, sum() function

.. note::

   Counting items and summing values are common enough operations that Python
   has built-in functions to perform them.  We've already seen ``len()``, which
   returns the number of items in a sequence.  Computing the sum of the numbers
   in a sequence can be done with the unsurprisingly-named ``sum()`` function.
   
   Nevertheless, loop patterns like those presented above are used frequently.
   The ``len()`` and ``sum()`` functions can handle simple cases of counting or
   summing, but more complex cases, like counting or summing only certain
   values from a sequence for example, may not be achievable using the built-in
   functions.

.. index:: None special value

.. index:: special value;None

Minimum and Maximum Loops
~~~~~~~~~~~~~~~~~~~~~~~~~

Another common use of loops is to find a value in a sequence with a particular
property.  For example, we may need to find the largest or smallest number in a
sequence.

Think about how you would find the largest number in a sequence if someone were
to give you a long list of numbers one at a time.  As you went through the
numbers, you would probably keep track of the largest number you had seen so
far at any point in time.  If you ever got a larger number, you would make that
the one you were remembering.

We can follow those same basic steps in code using a variable to remember the
largest value we've seen so far, a loop to go through the sequence of numbers,
and an if statement to check whether each new number is larger than the one
we're remembering:

.. activecode:: looppattern03

   largest = None
   print('(Before)  largest =', largest)
   for itervar in [3, 41, 12, 9, 74, 15]:
       if largest is None or itervar > largest :
           largest = itervar
       print('(In loop)  itervar =', itervar, ' largest =', largest)
   print('(After)  largest =', largest)

We have added some print statements to display the state of the variables as
the program runs.  You can also explore the execution of the code with CodeLens
to see more detail.

When the program executes, the output is as follows:

::

   (Before)  largest = None
   (In loop)  itervar = 3  largest = 3
   (In loop)  itervar = 41  largest = 41
   (In loop)  itervar = 12  largest = 41
   (In loop)  itervar = 9  largest = 41
   (In loop)  itervar = 74  largest = 74
   (In loop)  itervar = 15  largest = 74
   (After)  largest = 74

The variable ``largest`` is best thought of as the "largest value we have seen
so far." Before the loop, we set ``largest`` to the constant ``None``. ``None``
is a special constant value which we can store in a variable to mark the
variable as "empty."

Before the loop starts, the largest value we have seen so far is ``None`` since
we have not yet seen any values. While the loop is executing, if ``largest`` is
``None`` then we take the first value we see as the largest so far. You can see
in the first iteration when the value of ``itervar`` is 3, since ``largest`` is
``None``, the condition of the if statement evaluates to ``True``, and we
immediately set ``largest`` to be 3.

After the first iteration, ``largest`` is no longer ``None``, so the second
part of the compound logical expression that checks ``itervar > largest``
evaluates to ``True`` only when we see a value that is larger than the "largest
so far." When we see a new "even larger" value we take that new value for
``largest``. You can see in the program output that ``largest`` progresses from
3 to 41 to 74.

At the end of the loop, we have scanned all of the values and the variable
``largest`` now does contain the largest value in the list.

.. admonition:: Check your understanding

   Modify the ActiveCode above that computes the largest value in a list to
   instead find the *smallest* value in the list.  [A solution is immediately
   below this.]

To compute the smallest number, the code is very similar with one small
change:

.. activecode:: looppattern04

   smallest = None
   print('(Before)  smallest =', smallest)
   for itervar in [3, 41, 12, 9, 74, 15]:
       if smallest is None or itervar < smallest :
           smallest = itervar
       print('(In loop)  itervar =', itervar, ' smallest =', smallest)
   print('(After)  smallest =', smallest)

Again, ``smallest`` is the "smallest value seen so far" before, during, and
after the loop executes. When the loop has completed, ``smallest`` contains the
minimum value in the list.

.. index:: min() function, max() function

.. note::

   Finding the minimum and maximum values in a sequence are also common operations,
   and again Python includes built-in functions to perform them.  The functions are
   named ``min()`` and ``max()`` respectively.

   Again, though, you will often find yourself needing to write loop patterns like
   those above instead of using ``min()`` or ``max()`` directly, because you may
   need to solve a problem that is similar but not exactly solved by them.
