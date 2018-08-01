Loop Control Keywords
---------------------

.. index:: break keyword

Exiting a Loop with ``break``
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Sometimes you don’t know it’s time to end a loop until you get half way
through the body. In that case you can write an infinite loop on purpose
and then use the ``break`` statement to jump out of the loop.

This loop is obviously an *infinite loop* because the logical expression
on the ``while`` statement is simply the logical constant ``True``:

.. code:: python

   n = 10
   while True:
       print(n, end=' ')
       n = n - 1
   print('Done!')

If you make the mistake and run this code, you will learn quickly how to
stop a runaway Python process on your system or find where the power-off
button is on your computer. This program will run forever or until your
battery runs out because the logical expression at the top of the loop
is always true by virtue of the fact that the expression is the constant
value ``True``.

While this is a dysfunctional infinite loop, we can still use this
pattern to build useful loops as long as we carefully add code to the
body of the loop to explicitly exit the loop using ``break`` when we
have reached the exit condition.

For example, suppose you want to take input from the user until they
type ``done``. You could write:

.. code:: python

   while True:
       line = input('> ')
       if line == 'done':
           break
       print(line)
   print('Done!')

   # Code: http://www.py4e.com/code3/copytildone1.py

The loop condition is ``True``, which is always true, so the loop runs
repeatedly until it hits the break statement.

Each time through, it prompts the user with an angle bracket. If the
user types ``done``, the ``break`` statement exits the loop. Otherwise
the program echoes whatever the user types and goes back to the top of
the loop. Here’s a sample run:

::

   > hello there
   hello there
   > finished
   finished
   > done
   Done!

This way of writing ``while`` loops is common because you can check the
condition anywhere in the loop (not just at the top) and you can express
the stop condition affirmatively ("stop when this happens") rather than
negatively ("keep going until that happens.").

.. index:: continue keyword

Skipping to the Next Iteration with ``continue``
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Sometimes you are in an iteration of a loop and want to finish the
current iteration and immediately jump to the next iteration. In that
case you can use the ``continue`` statement to skip to the next
iteration without finishing the body of the loop for the current
iteration.

Here is an example of a loop that copies its input until the user types
"done", but treats lines that start with the hash character as lines not
to be printed (kind of like Python comments).

.. code:: python

   while True:
       line = input('> ')
       if line[0] == '#':
           continue
       if line == 'done':
           break
       print(line)
   print('Done!')

   # Code: http://www.py4e.com/code3/copytildone2.py

Here is a sample run of this new program with ``continue`` added.

::

   > hello there
   hello there
   > # don't print this
   > print this!
   print this!
   > done
   Done!

All the lines are printed except the one that starts with the hash sign
because when the ``continue`` is executed, it ends the current iteration
and jumps back to the ``while`` statement to start the next iteration,
thus skipping the ``print`` statement.
