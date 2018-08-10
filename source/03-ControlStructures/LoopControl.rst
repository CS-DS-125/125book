Loop Control Keywords
---------------------

For extra control over how a loop operates, we have the ``break`` and
``continue`` keywords.

.. index:: break keyword

Exiting a Loop with ``break``
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Sometimes you don’t know it’s time to end a loop until you get half way
through the body. In that case you can write an infinite loop on purpose
and then use the ``break`` statement to jump out of the loop.

This loop is an infinite loop because the logical expression on the ``while``
statement is simply the logical constant ``True``:

.. code:: python

   n = 10
   while True:
       print(n)
       n = n - 1
   print('Done!')

This program will run forever, or at least until your computer loses power,
because the loop's condition is always true by virtue of the fact that the
expression is the constant value ``True``.

While this is a dysfunctional infinite loop, we can still use this pattern to
build useful loops as long as we carefully add code to the body of the loop to
explicitly exit the loop using ``break`` when we have reached the exit
condition.

For example, suppose you want to take input from the user until they type
``done``. You could write:

.. activecode:: LoopControl01

   while True:
       line = input("Input (type 'done' to stop): ")
       if line == 'done':
           break
       print(line)
   print('Done!')

The loop condition is ``True``, which is always true, so the loop always
repeats when it reaches the end of its body, *but* if it hits the break
statement it leaves the loop immediately.

Each time through the loop, it prompts the user. If the user types ``done``,
then the ``break`` statement is reached, which exits the loop. Otherwise the
program echoes whatever the user types and goes back to the top of the loop.
Try it out!

This way of writing ``while`` loops is common because you can check the
condition anywhere in the loop (not just at the top) and you can express the
stop condition affirmatively ("stop when this is true") rather than negatively
("keep going until this is *not* true.").

.. index:: continue keyword

Skipping to the Next Iteration with ``continue``
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Sometimes you are in an iteration of a loop and want to finish the current
iteration and immediately jump to the next iteration. In that case you can use
the ``continue`` statement to skip to the next iteration without finishing the
body of the loop for the current iteration.

Here is an example of a loop that copies its input until the user types "done",
but treats lines that start with the hash character as lines not to be printed
(kind of like Python comments).

.. activecode:: LoopControl02

   while True:
       line = input("Input (start with '#' to skip, type 'done' to stop): ")
       if line.startswith('#'):
           continue
       if line == 'done':
           break
       print(line)
   print('Done!')

Here, all lines input by the user are printed except any that start with the
hash sign, because when the ``continue`` is executed, it ends the current
iteration and jumps back to the ``while`` statement to check the condition and
start the next iteration, thus skipping the ``print`` statement.
