.. index:: function call

Function Calls
--------------

In the context of programming, a **function** is a named sequence of
statements that performs a computation. When you define a function, you
specify the name and the sequence of statements. Later, you can "call"
the function by name. We have already seen many examples of **function
calls**.  Consider this one, for example:

.. code:: python

   >>> type(32)
   <class 'int'>

.. index:: argument, function argument

The name of the function is ``type``. The expression in parentheses is
called the **argument** of the function. The argument is a value or
variable that we are passing into the function for it to use in some way.
The result, for the ``type`` function, is the type of the argument.

.. index:: return value

It is common to say that a function "takes" an argument and "returns" a
result. The result is called the **return value**.

Using Return Values
~~~~~~~~~~~~~~~~~~~

When a function has a return value, we have a few common ways of using it.
First, we can store the return value in a variable so we can use it somewhere
else:

.. code:: python

   name = input("Please enter your name: ")

   total = sum(values)

   count = len(values)

   wholenum = int(floatval)

Each of those is an example of *calling a function* and *storing its return value* in a variable.  Let's look at the first one in more detail:

.. code:: python

   name = input("Please enter your name: ")

If we break this down, we see that it is an example of a :ref:`variable
assignment <assignment-statement>`.  The rule for assignments says that
variable on the left, ``name``, is assigned the value of the expression on the
right.  On the right, we see ``input("Please enter your name: ")``.  Like we
explained above, this is a *function call*, and ``"Please enter your name: "``
is its *argument*.  That means that we are passing the prompt string into the
function to be used by it.  And then we know that the ``input()`` function
produces a string containing whatever the user types in.  That string is its
*return value*.  It is that return value that is actually assigned to the variable on the left.

It's important to understand exactly how a function call is interpreted:

.. _function-call-pattern:

.. admonition:: Syntax Pattern

   Function calls have the form:

   ::
   
      <function name>(<argument1>, <argument2>, ...)

   There may be zero arguments (nothing written between the parentheses), one
   argument, or multiple arguments separated by commas.  Each argument is a
   value or some other expression that evaluates to some value.  The values of
   the arguments are passed into the function for it to use.

   When the function finishes execution, the function call *returns*.  If it
   has a return value (some do, some don't), then the entire function call
   *evaluates to* that return value.

Applying that rule to the above example, the call to ``input(...)`` *evaluates
to* the string containing whatever the user types in.  Or in the case of
``total = sum(values)``, the call to ``sum(values)`` *evaluates to* the
numerical summation of the numbers in ``values``, and that result is then what
is stored in the variable ``total``, following the rule of the variable
assignment statement.  You have already seen and probably written a lot of code
that uses return values like this (storing them in variables); now you can
understand in some more detail exactly what is happening when you do.

We can also unpack a common pattern we've been using for a while in order to understand it more fully:

.. code:: python

   age = int(input("Please enter your age: "))

Here, there are *two* function calls.  It is calling the ``int()`` function and
the ``input()`` function.  We can see that the argument to ``input()`` is
``"Please enter your age: "``.  But what is the argument to ``int()``, exactly?

The argument to ``int()`` is the *return value of* ``input()``.  The call to
``input()`` *evaluates to* whatever the user types in, and that string is then
passed into ``int()`` as its argument.  Function calls that return values can
be used anywhere any other expression or value can be written.

.. admonition:: Check your understanding

   .. fillintheblank:: cyu_functioncalls01

      .. code:: python

         values = [1.1, 2.3, 5.8, 13.21]
         total = sum(values)
         count = len(values)
         whole_total = int(sum(values))

      How many function calls are in the above code?  |blank|
      
      How many function calls have ``values`` as an argument?  |blank|
      
      How many function calls have a single The code above has a single number as its argument?  |blank|

      -  :4: Correct.  ``sum()`` is called twice, ``len()`` once, and ``int()`` once.
         :x: Incorrect.  Think about how many times the function call syntax pattern appears.
      -  :3: Correct.  ``values`` is an argument to ``sum()`` (twice) and ``len()``.
         :4: Incorrect.  ``values`` is not directly passed as an argument to all of the function calls.
         :x: Incorrect.  An argument is a variable or expression written in the parentheses of a function call.
      -  :1: Correct.  The return value of ``sum()`` in the last line is a single number, and that is passed to ``int()`` as an argument.
         :x: Incorrect.  Think carefully about what the argument to every one of the function calls is.

   .. fillintheblank:: cyu_functioncalls02

      .. code:: python

         name = 'ABCDEFGH'
         something = last(firsthalf(name))
         print(something)

      If the ``last()`` function returns the last letter in its argument, and the ``firsthalf()`` function returns the first half of its argument (e.g., the first 4 characters if its argument is an 8 character string):
      
      What does the above code print?  |blank|

      -  :'D': Correct.  ``firsthalf()`` returns ``'ABCD'``, and then ``last()`` returns ``'D'``.
         :"D": Correct.  ``firsthalf()`` returns ``'ABCD'``, and then ``last()`` returns ``'D'``.
         :D: Correct.  ``firsthalf()`` returns ``'ABCD'``, and then ``last()`` returns ``'D'``.
         :'d': Close!  But case (upper- or lowercase) matters in strings.
         :"d": Close!  But case (upper- or lowercase) matters in strings.
         :d: Close!  But case (upper- or lowercase) matters in strings.
         :x: Incorrect.  Carefully think it through, step-by-step, treating each function call separately.

