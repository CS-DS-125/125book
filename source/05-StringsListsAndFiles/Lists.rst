Lists
=====

.. index:: list, type;list

A List is a Sequence
--------------------

.. index:: list;element, list;item

Like a string, a *list* is a sequence of values. In a string, the values
are characters; in a list, they can be any type. The values in list are
called *elements* or sometimes *items*.

There are several ways to create a new list; the simplest is to enclose
the elements in square brackets ``[`` and ``]``:

.. code:: python

   [10, 20, 30, 40]
   ['crunchy frog', 'ram bladder', 'lark vomit']

The first example is a list of four integers. The second is a list of
three strings. The elements of a list don’t have to be the same type.
The following list contains a string, a float, an integer, and (lo!)
another list:

.. index:: nested list, list;nested

.. code:: python

   ['spam', 2.0, 5, [10, 20]]

A list within another list is *nested*.

.. index:: empty list, list;empty

A list that contains no elements is called an empty list; you can create
one with empty brackets, ``[]``.

As you might expect, you can assign list values to variables:

.. activecode:: lists01

   cheeses = ['Cheddar', 'Edam', 'Gouda']
   numbers = [17, 123]
   empty = []
   print(cheeses, numbers, empty)
   
.. index:: list;element
.. index:: indexing
.. index:: bracket operator
.. index:: operator;bracket
.. index:: mutability
.. index:: item assignment
.. index:: assignment;item

Lists are Mutable
-----------------

The syntax for accessing the elements of a list is the same as for
accessing the characters of a string: the bracket operator. The
expression inside the brackets specifies the index. Remember that the
indices start at 0:

.. activecode:: lists01b

   cheeses = ['Cheddar', 'Edam', 'Gouda']
   print(cheeses[0])

Unlike strings, lists *are* mutable: you can change the order of
items in a list or reassign an item in a list. When the bracket operator
appears on the left side of an assignment, it identifies the element of
the list that will be assigned.

.. activecode:: lists02

   numbers = [17, 123]
   print(numbers)
   numbers[1] = 5
   print(numbers)

The second element ``numbers`` (at index 1), which used to be 123, is changed
to 5.

You can think of a list as a relationship between indices and elements.
This relationship is called a **mapping**; each index "maps to" one of the
elements.

.. index:: exception;IndexError
.. index:: IndexError

Indexing in a list works the same way as indexing in a string:

- Indexes start from 0.
- Any integer expression can be used as an index.
- If you try to read or write an element that does not exist, you get
  an ``IndexError``.
- If an index has a negative value, it counts backward from the end of
  the list.

.. index:: list;index, list;membership
.. index:: membership;list, in operator
.. index:: operator;in

The ``in`` operator also works on lists:

.. activecode:: lists02b

   cheeses = ['Cheddar', 'Edam', 'Gouda']
   print('Edam' in cheeses)
   print('Brie' in cheeses)
   

.. index:: list;traversal, traversal;list
.. index:: for loop, loop;for
.. index:: statement;for
.. index:: looping;with indices
.. index:: index;looping with
.. index:: item update, update;item

Traversing a List
-----------------

The most common way to traverse the elements of a list is with a ``for``
loop, which we have seen previously:

.. activecode:: lists03

   cheeses = ['Cheddar', 'Edam', 'Gouda']
   for cheese in cheeses:
       print(cheese)

This works well if you only need to read the elements of the list. But if you
want to write or update the elements, you have to use indexing.  The for loop
gives you a copy of each value in the list, but it provides no way to alter
them.  A common way to do that is to combine the functions ``range`` and
``len``:

.. activecode:: lists04

   numbers = [17, 123, 42]
   print("Before:", numbers)
   
   for i in range(len(numbers)):
       numbers[i] = numbers[i] * 2
       
   print("After:", numbers)

The *sequence* in this loop is the sequence of all valid indexes into the list.  The expression ``range(len(numbers))`` gives the length of the list to ``range()``, which produces a sequence of values starting at 0 and going up to, *but not including*, the length of the list itself.  This is always going to be the valid indexes into the list!

The loop traverses the list and updates each element. Each time through the
loop, ``i`` gets the index of the next element. The assignment statement in the
body uses ``i`` to read the old value of the element and to assign the new
value.

.. index:: nested list, list;nested

Although a list can contain another list, the nested list still counts
as a single element. The length of this list is four:

.. activecode:: lists05

   nested_list = ['spam', 1, ['Brie', 'Roquefort', 'Pol le Veq'], [1, 2, 3]]
   print(len(nested_list))


.. index:: list;operation

List Operations
---------------

Most of the operators that we have seen work with strings will work with lists just the same.  You can expand your understanding of them as "list operators" to be "sequence operators," working on sequences of values whether they be strings or lists.

.. index:: concatenation;list
.. index:: list;concatenation

The ``+`` operator concatenates lists:

.. activecode:: lists06

   a = [1, 2, 3]
   b = [4, 5, 6]
   c = a + b
   print(c)

.. index:: repetition;list
.. index:: list;repetition

And the ``*`` operator repeats a list a given number of times:

.. activecode:: lists06b

   print([0] * 4)
   print([1, 2, 3] * 3)

.. index:: slice operator, operator;slice
.. index:: index;slice, list;slice
.. index:: slice;list

The slice operator also works on lists:

.. activecode:: lists06c

   t = ['a', 'b', 'c', 'd', 'e', 'f']
   print(t[1:3])
   print(t[:4])
   print(t[3:])

.. index:: list;copy, slice;copy
.. index:: copy;slice

As with strings, if you omit the first index, the slice starts at the
beginning. If you omit the second, the slice goes to the end. So if you omit
both, the slice is a copy of the whole list.  This seems pointless, but it is
often useful when applied to lists!

.. activecode:: lists06d

   t = ['a', 'b', 'c', 'd', 'e', 'f']
   print(t[:])

.. index:: mutability

Since lists are mutable, it is often useful to make a copy before performing
operations that modify lists.  We'll see an example below.

.. index:: list;method, method;list
.. index:: append method, method;append
.. index:: extend method, method;extend
.. index:: sort method, method;sort

List Methods
------------

Like strings, lists are objects as well.  And like with strings, this means
that lists contain useful built-in **methods** that we can call using dot
notation.  

For example, the list method ``append()`` adds a new element to the end of a
list:

.. activecode:: lists08

   t = ['a', 'b', 'c']
   print("Before:", t)
   t.append('d')
   print("After:", t)

The ``extend()`` list method takes a list as an argument and appends all of the
elements (note that ``t2`` is unmodified):

.. activecode:: lists09

   t1 = ['a', 'b', 'c']
   t2 = ['d', 'e']
   print("t1 Before:", t1)
   print("t2 Before:", t2)
   t1.extend(t2)
   print("t1 After:", t1)
   print("t2 After:", t2)

The ``sort()`` method rearranges the elements of the list from low to high:

.. activecode:: lists10a

   t = ['d', 'c', 'e', 'b', 'a']
   print("Before:", t)
   t.sort()
   print("After:", t)

Most list methods are void methods; they modify the list and return ``None``.
If you accidentally write ``t = t.sort()``, you will be disappointed with the
result:

.. activecode:: lists10b

   t = ['d', 'c', 'e', 'b', 'a']
   print("Before:", t)
   t = t.sort()
   print("After:", t)


.. index:: element deletion
.. index:: deletion;element of list
.. index:: pop method, method;pop
.. index:: del operator, operator;del
.. index:: remove method, method;remove

Deleting elements
-----------------

There are several ways to delete elements from a list. If you know the
index of the element you want, you can use the list method ``pop()``:

.. activecode:: lists11

   t = ['a', 'b', 'c']
   print("Before:", t)
   x = t.pop(1)
   print("After:", t)
   print("x:", x)

``pop()`` modifies the list and returns the element that was removed. If you
don’t provide an index, it deletes and returns the *last* element.

If you don’t need the removed value, you can use the ``del`` operator:

.. activecode:: lists12

   t = ['a', 'b', 'c']
   print("Before:", t)
   del t[1]
   print("After:", t)

If you know the value of the element you want to remove (but not its index),
you can use ``remove()``:

.. activecode:: lists13a

   t = ['a', 'b', 'c']
   print("Before:", t)
   t.remove('b')
   print("After:", t)

The return value of ``remove()`` is ``None``; it is a void function.  So again,
don't try to write something like ``t = t.remove('b')``:

.. activecode:: lists13b

   t = ['a', 'b', 'c']
   print("Before:", t)
   t = t.remove('b')
   print("After:", t)


Lists and Functions
-------------------

We've seen a number of built-in functions that can be applied to lists that
allow you to quickly compute something from a list without writing your own
loops:

.. activecode:: lists14a

   nums = [3, 41, 12, 9, 74, 15]
   print(len(nums))
   print(max(nums))
   print(min(nums))
   print(sum(nums))
   print(sum(nums)/len(nums))

Note that none of these functions are *methods*; we do *not* call them with dot
notation.  Instead, these are functions that accept a list as an *argument*.

The ``sum()`` function only works when the list elements are numbers.
The other functions (``max()``, ``len()``, etc.) work with lists of
strings and other types as well.

To show how these can be used, we can rewrite a program that computes the
average of a list of numbers entered by the user using a list.

First, the program to compute an average without a list:

.. activecode:: lists15

   total = 0
   count = 0
   while (True):
       inp = input('Enter a number ("done" to stop): ')
       if inp == 'done':
           break
       value = float(inp)
       total = total + value
       count = count + 1

   average = total / count
   print('Average:', average)

In this program, we have ``count`` and ``total`` variables to keep the
number and running total of the user’s numbers as we repeatedly prompt
the user for a number.

We could simply remember each number as the user entered it and use
built-in functions to compute the sum and count at the end.

.. activecode:: lists16

   numlist = list()
   while (True):
       inp = input('Enter a number ("done" to stop): ')
       if inp == 'done':
           break
       value = float(inp)
       numlist.append(value)

   average = sum(numlist) / len(numlist)
   print('Average:', average)

We make an empty list before the loop starts, and then each time we have
a number, we append it to the list. At the end of the program, we simply
compute the sum of the numbers in the list and divide it by the count of
the numbers in the list to come up with the average.


.. index:: list;function, function;list
.. index:: split method, method;split
.. index:: join method, method;join

Lists and Strings
-----------------

A string is a sequence of characters and a list is a sequence of values,
but a list of characters is *not* the same as a string. To convert from a
string to a list of characters, you can use ``list()``:

.. activecode:: lists17

   s = 'spam'
   t = list(s)
   print(s)
   print(t)

Because ``list()`` is the name of a built-in function, you should avoid using
it as a variable name.  It is also good to avoid the letter ``l``, because it
looks too much like the number ``1``. So that’s why the code in this section
uses ``t``.

The ``list()`` function breaks a string into individual letters. If you
want to break a string into words, you can use the ``split()`` string method:

.. activecode:: lists18

   s = 'pining for the fjords'
   t = s.split()
   print(s)
   print(t)

Once you have used ``split()`` to break the string into a list of words, you can
use the index operator ``[]`` to get a particular word in the list.

You can call ``split()`` with an optional argument called a **delimiter**
that specifies which characters to use as word boundaries. The following
example uses a hyphen as a delimiter:

.. activecode:: lists19

   s = 'duck-duck-duck-duck-goose!'
   delimiter = '-'
   t = s.split(delimiter)
   print(s)
   print(t)

The string method ``join()`` is the inverse of ``split()``. It takes a list of
strings and concatenates the elements.  It isn't called how you might expect it
to be, though.  ``join()`` is a string method, so you have to call it from the
delimiter string (that is, put the delimiter string on the left side of the dot
notation) and pass the list as an argument:

.. activecode:: lists20a

   t = ['pining', 'for', 'the', 'fjords']
   delimiter = '_-_'
   s = delimiter.join(t)
   print(t)
   print(s)


In this case the delimiter is the string ``'_-_'``, so ``join()`` puts a copy
of that between each word.  To join strings with spaces, use ``' '`` as the
delimiter.  To concatenate strings (join them with nothing in between), you can
use the empty string, ``''``, as a delimiter.

.. activecode:: lists20b

   t = ['pining', 'for', 'the', 'fjords']

   # Join with spaces
   delimiter1 = ' '
   s1 = delimiter1.join(t)
   print(t)
   print(s1)

   # Concatenate (join with nothing between the strings)
   delimiter2 = ''
   s2 = delimiter2.join(t)
   print(t)
   print(s2)

.. index:: object, value
.. index:: is operator, operator;is
.. index:: equivalence, identity

Objects and Values
------------------

If we execute these assignment statements:

.. code:: python

   a = 'banana'
   b = 'banana'

we know that ``a`` and ``b`` both refer to a string, but it might not be clear
whether they refer to the *same* string. There are two possible states:

.. figure:: figs/list1.svg
   :alt: Variables and Objects

   Variables and Objects

In one case, ``a`` and ``b`` refer to two different objects that have
the same value.  In the second case, they refer to the same object.

To check whether two variables refer to the same object, you can use the ``is``
operator.  The expression ``A is B`` will evaluate to ``True`` if ``A`` and
``B`` are the same object and ``False`` if they are not.  So to check the
situation of our ``'banana'`` strings:

.. activecode:: lists22

   a = 'banana'
   b = 'banana'
   print(a is b)   

In this example, Python only created one string object, and both ``a`` and
``b`` refer to it.

But when you create two lists, even with the same elements in each, you get two
objects:

.. activecode:: lists23

   a = [1, 2, 3]
   b = [1, 2, 3]
   print(a is b)
   
In this case we would say that the two lists are **equivalent**, because they
have the same elements, but not **identical**, because they are not the same
object. If two objects are identical, they are also equivalent, but if they are
equivalent, they are not necessarily identical.

Until now, we have been using "object" and "value" interchangeably, but it is
more precise to say that an object has a value. If you execute ``a = [1,2,3]``,
``a`` refers to a list object whose value is a particular sequence of elements.
If another list has the same elements, we would say it has the same value.

.. index:: reference
.. index:: aliasing, reference;aliasing

References and Aliasing
-----------------------

If ``a`` refers to an object and you assign ``b = a``, then both variables will
refer to the same object:

.. activecode:: lists24

   a = [1, 2, 3]
   b = a
   print(b is a)

The association of a variable with an object is called a **reference**. In this
example, there are two references to the same object.

An object with more than one reference has more than one name, so we say that
the object is **aliased**.

If the aliased object is mutable, changes made with one alias affect the
other:

.. activecode:: lists25a

   a = [1, 2, 3]
   b = a
   print("a before:", a)
   print("b before:", b)

   b[0] = 17
   print("a after:", a)
   print("b after:", b)


Although this behavior can be useful, it is error-prone. In general, it
is safer to avoid aliasing when you are working with mutable objects.  This is
a case where making a *copy* of a list using slicing can be helpful!  For
example, the following is just a slight modification of the above example, but
now altering ``b`` doesn't affect ``a``:

.. activecode:: lists25b

   a = [1, 2, 3]
   b = a[:]
   print("a before:", a)
   print("b before:", b)

   b[0] = 17
   print("a after:", a)
   print("b after:", b)


.. index:: debugging

Debugging
---------

Careless use of lists (and other mutable objects) can lead to long hours
of debugging. Here are some common pitfalls and ways to avoid them:


.. index:: sort method, method;sort

1. Don’t forget that most list methods modify the argument and return
   ``None``. This is the opposite of the string methods, which return a
   new string and leave the original alone.

   If you are used to writing string code like this:

   .. code:: python

      word = word.strip()

   It is tempting to write list code like this:

   .. code:: python

      t = t.sort()           # WRONG!

   Because ``sort()`` returns ``None``, the next operation you perform
   with ``t`` is likely to fail.

   Before using list methods and operators, you should read the documentation
   carefully and try them out a few times. The methods and operators that lists
   share with other sequences (like strings) are documented at
   `https://docs.python.org/3/library/stdtypes.html#common-sequence-operations
   <https://docs.python.org/3/library/stdtypes.html#common-sequence-operations>`_.
   The methods and operators that only apply to mutable sequences are
   documented at
   `https://docs.python.org/3/library/stdtypes.html#mutable-sequence-types
   <https://docs.python.org/3/library/stdtypes.html#mutable-sequence-types>`_.

.. index:: idiom

2. Pick an idiom and stick with it.

   An "idiom" in programming is a particular style or way of accomplishing
   something.  Part of the problem with lists is that there are too many ways
   to do things.  Of the many options, make sure you consistently use just one
   throughout a program.

   For example, to remove an element from a list, you can use ``pop()``,
   ``remove()``, or ``del``.

   To add an element, you can either use the ``append()`` method or the ``+``
   operator.  Be careful, though.  Don’t forget that these are right:

   .. code:: python

      t.append(x)
      t = t + [x]

   And these are wrong:

   .. code:: python

      t.append([x])          # WRONG!
      t = t.append(x)        # WRONG!
      t + [x]                # WRONG!
      t = t + x              # WRONG!

   Try out each of these examples in the active code block below to make sure
   you understand what they do. Notice that only the last one causes a runtime
   error; the other three are legal, but they do the wrong thing.

   .. activecode:: list_testing01

      t = ['a', 'bee', 'sea', 'D']
      x = 'eeeee'

      # Try out the above examples here:


.. index:: aliasing;copying to avoid
.. index:: copy;to avoid aliasing

3. Make copies to avoid aliasing.

   If you want to use a method like ``sort()`` that modifies the argument,
   but you need to keep the original list as well, you can make a copy first.

   .. code:: python

      orig = t[:]  # orig is a copy of t now
      t.sort()     # t is now sorted, but orig is unmodified

   In this example you could also use the built-in function ``sorted()``,
   which returns a new, sorted list and leaves the original alone. But
   in that case you should avoid using ``sorted`` as a variable name!
