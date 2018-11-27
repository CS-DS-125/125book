Objects (Refresher)
===================

Before we talk about classes, it's worth summarizing and refreshing everything
we know about objects so far.

String Objects
--------------

We first introduced the term "object" and the concept when discussing Strings,
and :ref:`String objects <string-objects>` were the first kind of object we
discussed.  A few key points repeated from that chapter:

.. admonition:: Definition

   An **object** contains both data and **methods**, which are functions that
   are built into the object and can modify or perform operations on it.

   As another way of putting it, objects "know things" and "can do things":

   * Objects "know things": an object holds *data*.
   * Objects "can do things": an object contains *code* (the methods).

In the case of a string object, the object's data is the characters of the
string itself.  And there are a few ways to learn about what methods (code) it
contains.

Methods, like any other function, can be called to execute them.  Calling a
method is similar to calling a function (it takes arguments and returns a
value) but to access a method within an object, we use :ref:`dot notation
<dot-notation>` just like when accessing functions within modules.

For example, the method ``upper()`` takes a string and returns a new string
with all uppercase letters:

.. activecode:: objects_refresher01

   word = 'banana'
   print(word)
   new_word = word.upper()
   print(new_word)

This form of dot notation specifies the name of the method, ``upper()``, and the
name of the string to apply the method to, ``word``. The empty parentheses
indicate that this method takes no argument.

.. index:: attribute, object;attribute

Objects in Pandas
-----------------

In Pandas, the most important type of object we have seen and used is the
DataFrame.  DataFrames contain a wide range of methods, and we have explored
some of those in the earlier chapter.  DataFrames also introduce one new aspect
of objects that we glossed over before: **attributes**.

Above, we said that objects "know things" and "can do things."  Methods are what
an object can "do," and attributes are what an object "knows."  In other words,
an attribute is data stored inside an object and given a name, just like a method
is code stored inside an object and given a name.  And just as methods can be
accessed via dot notation, so too can attributes.

One example we've seen is ``df.shape``.  The ``.shape`` attribute of a
DataFrame contains the row and column counts for that DataFrame.  Notice that
we access it via dot notation (naming the attribute ``shape`` we want to access
inside the object ``df``) but that the name is *not* followed by parentheses.
This is what differentiates an attribute from a method.

