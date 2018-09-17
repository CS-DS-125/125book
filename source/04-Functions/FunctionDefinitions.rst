.. index:: function, function definition

Function Definitions
--------------------

So far, we have only been using the functions that come with Python, but
we often need to to add new functions we write ourselves. A **function
definition** specifies the name of a new function and the sequence of
statements that execute when the function is called. Once we define a function,
we can reuse the function over and over throughout our program.  The syntax for
calling a new function we define is the same as for any other function (see the
:ref:`function call pattern <function-call-pattern>`).  

Here is an example of defining a function, followed by calling it twice:

.. activecode:: functiondef01

   def print_lyrics():
       print("I'm a lumberjack, and I'm okay.")
       print('I sleep all night and I work all day.')

   print_lyrics()
   print_lyrics()

.. index:: def keyword

``def`` is a keyword that indicates the start of a function definition.  The
name of the function here is ``print_lyrics``. The rules for function names are
the same as for variable names: letters, numbers and some punctuation marks are
legal, but the first character can’t be a number.  You can’t use a keyword as
the name of a function, and you should avoid having a variable and a function
with the same name to avoid confusion.

.. index:: argument

The empty parentheses after the name indicate that this function doesn’t
take any arguments. Later we will build functions that take arguments.

.. index:: body, indentation

.. index:: colon

The first line of the function definition has to end with a colon and the body
has to be indented. The body can contain any number of statements.  Notice that
this is the same pattern (a colon followed by an indented body) as we've seen
in for loops, while loops, and if statements.  It's consistent across the
language.

.. admonition:: Syntax Pattern

   A function definition has the form:

   ::

      def <function name>(<parameters>):
          <body>

   When Python interprets this syntax, it creates a new function with the given
   name that contains the statements (lines of code) in the body.

   Parameters are optional.  [We will fill in details about parameters farther down.]

.. admonition:: Check your understanding

   .. mchoice:: cyu_functiondef01
      :answer_a: It indicates the start of a function
      :answer_b: It executes a function
      :answer_c: It indicates that the following indented section of code is to be stored for later
      :answer_d: a and b are both true
      :answer_e: a and c are both true
      :correct: e
      :feedback_e: Correct!  "def" indicates the start of a function definition, meaning that the following indented block of code will be stored under the given name.

      What is the purpose of the "def" keyword in Python?

Defining a function creates a variable with the same name.

.. activecode:: functiondef02

   def print_lyrics():
       print("I'm a lumberjack, and I'm okay.")
       print('I sleep all night and I work all day.')

   print(print_lyrics)
   print(type(print_lyrics))

The value of ``print_lyrics`` is a *function object*, which has type
"function".

.. admonition:: Check your understanding

   .. mchoice:: cyu_functiondef02
      :answer_a: Because it is invalid syntax.
      :answer_b: Because print_lyrics() is not called.
      :answer_c: Because Python doesn't like the lyrics.
      :answer_d: Because Python got confused by seeing "print" everywhere.
      :correct: b
      :feedback_b: Correct!  When we wrote "print(print_lyrics)", that is printing out what the function is (in a sense).  We didn't write "print_lyrics()" with the parentheses that would make it a function *call* that *would* execute the function and print the lyrics.

      The program above never prints out the lyrics, "I'm a lumberjack..."  Why not?


Once you have defined a function, you can use it anywhere, even inside another
function. For example, to repeat the previous refrain, we could write a
function called ``repeat_lyrics()`` and call it:

.. activecode:: functiondef03

   def print_lyrics():
       print("I'm a lumberjack, and I'm okay.")
       print('I sleep all night and I work all day.')

   def repeat_lyrics():
       print_lyrics()
       print_lyrics()
       print_lyrics()

   repeat_lyrics()

(But that’s not really how the song goes...)

This program contains two function definitions: ``print_lyrics`` and
``repeat_lyrics``.  It's important to recognize that the function definitions
get executed just like other statements, but doing so does *not* execute the
functions.  To see this, open CodeLens for the above code, and step forward
twice.  You'll see that each time Python executes one of the ``def ...`` lines,
nothing is printed, but a new function is defined on the right.  The statements
inside the function are *stored* when the function definition is executed, and
they do not get executed until the function is *called*.

Step forward in the code one more time.  Now you'll see what happens when a
function is called.  The function call on line 10 jumps into the
``repeat_lyrics()`` function, and *then* the function is executed.

.. index:: use before def

As you might expect, you have to create a function before you can
execute it. In other words, the function definition has to be executed
before the first time the function is called.

.. admonition:: Check your understanding

   1. What do you think will happen if you move the last line of the program above (that calls ``repeat_lyrics()``) to the top of the program?
      
      Make the change, and run the program again to check.

   2. What do you think will happen if you move the definition of ``print_lyrics`` after the definition of ``repeat_lyrics``?
      
      Make the change (after undoing the change you made for (1) above), and run the program again to check.  Stepping through the code with CodeLens can help understand how it works.


.. index:: flow of execution, jump

Flow of Execution
~~~~~~~~~~~~~~~~~

In order to ensure that a function is defined before its first use, you
have to know the order in which statements are executed, which is called
the **flow of execution**.

Execution always begins at the first statement of the program.
Statements are executed one at a time, in order from top to bottom.

When a function *definition* is reached, it defines a function, storing its
statements, but remember that statements inside the function are not executed
until the function is called.

A function call is like a detour in the flow of execution. Instead of
going to the next statement, a function call does the following:

1. The flow **jumps** to the body of the function,
2. The flow proceeds through all the statements there, executing them in order,
3. When the end of the function is reached, the flow jumps back to the line
   after the original function call to pick up where it left off.

That sounds simple enough, until you remember that one function can call
another. While in the middle of one function, the program might have to
execute the statements in another function. But while executing that new
function, the program might have to execute yet another function!

Fortunately, Python is good at keeping track of where it is, so each
time a function completes, the program picks up where it left off in the
function that called it. When it gets to the end of the program, it
terminates.

What’s the moral of this story?  When you read a program, you don’t always want
to just read from top to bottom.  You need to follow the flow of execution.

CodeLens in this book and the `Python Tutor <http://pythontutor.com/>`_ website
on which it is based are both very helpful for studying the flow of execution
of programs.  You can watch where it goes, step-by-step, and both build up and
check your understanding as you watch.

.. note::

   If you are working in a Jupyter notebook environment, flow of execution also
   depends on the order in which you choose to execute cells.  When executing a
   single cell, the flow of execution works within the cell as described above,
   but you can choose to execute cells in whatever order you want.

   If you ever find yourself unsure of which code has executed when or
   otherwise confused about the state of the values and definitions of
   variables and functions, it is safest to restart the kernel and re-run the
   cells in order.  Restarting the kernel starts everything again with a "blank
   slate," in which nothing has been defined yet, and then you can make sure
   each cell executes in an order you want and can remember.

.. admonition:: Check your understanding

   .. mchoice:: cyu_functiondef03
      :answer_a: Zap ABC jane fred jane
      :answer_b: Zap ABC Zap
      :answer_c: ABC Zap jane
      :answer_d: ABC Zap ABC
      :answer_e: Zap Zap Zap
      :correct: d
      :feedback_a: Incorrect.  Make sure you're applying the rules for function definitions, function calls, and flow of execution as you think through the code.
      :feedback_b: Incorrect.  Make sure you're applying the rules for function definitions, function calls, and flow of execution as you think through the code.
      :feedback_c: Incorrect.  Make sure you're applying the rules for function definitions, function calls, and flow of execution as you think through the code.
      :feedback_d: Correct!
      :feedback_e: Incorrect.  Make sure you're applying the rules for function definitions, function calls, and flow of execution as you think through the code.

      What will the following Python program print out?

      .. code:: python

         def fred():
            print("Zap")

         def jane():
            print("ABC")

         jane()
         fred()
         jane()


.. index:: parameter, function parameter
.. index:: argument, function argument

Parameters and Arguments
~~~~~~~~~~~~~~~~~~~~~~~~

Some of the built-in functions we have been using so far require arguments. For
example, when you call ``range()``, you have to pass it a number as an
argument.  When calling ``len()``, you have to give it a string, list, or other
sequence as an argument.  Some functions take more than one argument:
``math.pow()`` in the ``math`` module takes two, the base and the exponent.

When a function is called, any arguments given in the function call are
assigned to variables in the function body called *parameters*. Here is an
example of a user-defined function that takes an argument:

.. code:: python

   def print_twice(thing):
       print(thing)
       print(thing)

This function assigns the argument to a parameter named ``thing``. When
the function is called, it prints the value of the parameter (whatever
it is) twice.

.. activecode:: functiondef04

   def print_twice(thing):
       print(thing)
       print(thing)

   print_twice("Hi there!")

   print_twice(1234)

   sentence = "This is a sentence."
   print_twice(sentence)

   import math
   print_twice(math.pi)

Run the above code in CodeLens.  Watch what happens when you call the
``print_twice()`` function with an argument.  Each time, the value of the
argument is copied into the ``thing`` parameter (a variable) inside the
``print_twice()`` function.  After a call to the function ends, that variable
no longer exists.  We can fill in some details about parameters in the function
definition syntax pattern now:

.. admonition:: Syntax Pattern

   A function definition has the form:

   ::

      def <function name>(<parameters>):
          <body>

   When Python interprets this syntax, it creates a new function with the given
   name that contains the statements (lines of code) in the body.

   Parameters are optional.  If one or more parameters are specified, as variable
   names separated by commas, then they behave as follows:

   1. Each time the function is called, it must be called with one argument for
      each of the parameters in the function definition.
   2. Each parameter is a variable that exists only inside the function body.
   3. The *value* of each argument will be assigned to a parameter, matching
      each argument to a parameter by the order in which they are written.
   4. When the function ends, the parameter variables are deleted.  (They no
      longer exist and cannot be used outside of the function.)

The same rules of composition that apply to built-in functions also
apply to user-defined functions, so we can use any kind of expression as
an argument for ``print_twice``.  Again, for the code below, use CodeLens to
watch what happens each time the function is called and what value is assigned
to its parameter:

.. activecode:: functiondef05

   def print_twice(thing):
       print(thing)
       print(thing)

   print_twice('Spam ' * 4)

   sentence = "This is a sentence."
   print_twice(len(sentence))

   import math
   print_twice(math.cos(math.pi))

Every function argument is *evaluated* before the function is called, and its
*value* is passed in to be assigned to the parameter.

A common source of confusion for beginner programmers is the use of variables as function arguments.  The line above that calls ``print_twice(sentence)`` is an example of this.  You *might* think that this will just make the ``sentence`` variable available inside the function, so you could use it like this:

.. activecode:: functiondef06

   def print_twice(thing):
       print(sentence)
       print(sentence)

   sentence = "This is a sentence."
   print_twice(sentence)

The error this code produces shows that the ``sentence`` variable does not
exist within the function, even if we use that variable as an argument when
calling the function.  The key detail of function definitions that explains
this is the rule that says "The *value* of each argument will be assigned to a
parameter..."

In other words, the name of the variable we pass as an argument (``sentence``)
has nothing to do with the name of the parameter (``thing``). It doesn’t matter
what the value was called back home (in the caller); here in ``print_twice``,
we call it ``thing``.


.. index:: fruitful function
.. index:: void function
.. index:: function; fruitful
.. index:: function; void

Fruitful Functions and Void Functions
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Some of the functions we are using, such as ``len()`` or ``int()``, yield
results; for lack of a better name, they are sometimes called **fruitful
functions**.  Other functions, like ``print_twice()``, perform an action but
*don’t* return a value.  They are called **void functions**.

.. index:: return

To return a result from a function, making it a fruitful function, we use the
``return`` statement in our function. For example, we could make a very simple
function called ``add_two()`` that adds two numbers together and returns a result.

.. activecode:: functiondef08

   def add_two(a, b):
       added = a + b
       return added

   x = add_two(3, 5)
   print(x)

When this script executes, the ``print()`` statement will print out ``8``
because the ``add_two()`` function was called with 3 and 5 as arguments.
Within the function, the parameters ``a`` and ``b`` were 3 and 5 respectively.
The function computed the sum of the two numbers and placed it in the local
function variable named ``added``. Then it used the ``return`` statement to
send the computed value back to the calling code as the function result, which
was assigned to the variable ``x`` and printed out.

It is worth using CodeLens again to watch that happen and see how each line works.

When you call a fruitful function, you almost always want to do something with
the result it produces; for example, you might assign the result to a variable
as in the example above or use it as part of an expression:

.. code:: python

   golden = (math.sqrt(5) + 1) / 2

If you call a fruitful function and do *not* store the result of the function
in a variable, the return value vanishes!

.. activecode:: functiondef09

   def add_two(a, b):
       added = a + b
       return added

   add_two(3, 5)

The function call does compute the sum of 3 and 5, but since it doesn’t store
the result in a variable or do anything else, it is not very useful.  (We saw
another example of code executing but not accomplishing anything -- because its
result wasn't saved or used anywhere -- in :ref:`code back in Chapter 2
<expressions01>`.)

.. caution::

   A *very* common mistake beginner programmers make is to assume that a return
   statement with a variable makes that variable exist outside of the function.
   They often write code like this:

   .. activecode:: functiondef10

      def add_two(a, b):
         added = a + b
         return added

      add_two(3, 5)
      print(added)

   Refer back to the :ref:`function call pattern <function-call-pattern>` for
   the exact details of what happens when a function is called.  The function
   call itself is *evaluated* to become the returned *value* -- and remember
   that a *value* is not the same thing as a *variable*.
 
   In the return statement, the *value* of the ``added`` variable is returned,
   not the variable itself.  So the function call here becomes the value ``8``,
   as if we had just written ``8`` on that line by itself.

   This reinforces what we said above: when you call a fruitful function, you
   almost always want to assign its return value to a variable or otherwise use
   the function call in an expression.  Calling a fruitful function on a line
   by itself effectively throws away its return value.


.. index:: function, reasons for

Why Define Functions?
~~~~~~~~~~~~~~~~~~~~~

It may not be clear why it is worth the trouble to divide a program into
functions. There are several reasons:

- **Testing and Debugging:** Dividing a long program into functions can help
  you to test and debug the parts individually, one at a time and then assemble
  them into a working whole.

- **Code Reuse (within a program):** Functions can make a program smaller by
  eliminating repetitive code.  (A common refrain in programming is "DRY: Don't Repeat Yourself.")

- **Code Maintenance:** If you have to update, fix, or change code that is
  defined in a function, you only have to make changes in one place, and those
  changes will take effect everywhere the function is called.

- **Code Reuse (across programs):**  Well-designed functions are often useful
  for many programs.  Once you write and debug a function, you can reuse it in
  other programs.

- **Overall:** Creating a new function gives you an opportunity to name a
  potentially very complex group of statements and then refer to them by that
  simple name anywhere they need to be used.  This makes your program easier to
  read, understand, and debug.

.. index:: abstraction

The final point embodies a critical concept in programming and computer science
called **abstraction**.  Abstraction, in this context, is the practice of
hiding or ignoring details in order to manage complexity.

For an example outside of computer science, consider cars.  Cars are complex
machines, with an incredible number of interacting parts and systems involved
in their operation.  Even a trained automotive engineer can't consider *all* of
those pieces and their interactions simultaneously, and most of us have very
little of the knowledge we'd need to even try.

And yet we *use* a car, driving it successfully from place to place without
knowing or understanding any of that detail.  We have a simplified "interface" to control the car: a steering wheel, a gear shift, and some pedals.  All we need to understand is how those parts direct the functioning of the car at a high level.  That interface is an *abstraction* of the total complexity of the car and its functioning, and all of that complexity has been hidden behind the abstraction.  The abstraction allows us to ignore the complexity while still using it successfully.

Programs can be incredibly complex as well, containing far more detail than we
can hope to capture in our heads at once.  Even the steps required to
successfully print a simple greeting like ``"Hello, World!"`` on the screen are
more than we'd want to deal with.  And so the ``print()`` function exists as an
*abstraction* of that complexity.  The complexity is hidden, we can ignore it,
and we are able to easily use it via the simple "interface" of the ``print()``
function call.

So in general, you can create function definitions to accomplish the same
thing.  You can take some code you have written, put it in a function, and
later just refer to that function by its name without worrying about exactly
how it works internally.  This basic idea brings us all of the benefits listed
above: clearer organization, easy code reuse, improved testing and debugging,
and simpler maintenance.

.. Throughout the rest of the book, often we will use a function definition
.. to explain a concept. Part of the skill of creating and using functions
.. is to have a function properly capture an idea such as "find the
.. smallest value in a list of values." Later we will show you code that
.. finds the smallest in a list of values and we will present it to you as
.. a function named ``min`` which takes a list of values as its argument
.. and returns the smallest value in the list.


