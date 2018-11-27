.. index:: class, instance

Classes
=======

The objects we've seen and used thus far have all had specific *types*, and
each type is consistent between objects of that type.  Every DataFrame contains
the same set of methods and attributes, every String object works the same way,
and every File object can be used just like any other.  The consistent set of
functionality within an object of a given type must be defined somewhere.
That's where classes come in.

A **class** defines a type of object.  It specifies what attributes any object
of that type will have and what methods it will have.  A common analogy is to
think of classes like cookie cutters and objects like cookies made from them.
Each cookie cutter defines the shape of a particular kind of cookie, and it can
be used to make one cookie or many cookies with that shape.

.. figure:: figs/cookie_cutter.jpg
   :alt: Cookie cutter and cookies
   :width: 400px

   Cookie cutter and cookies

We often call each object created from a given class an **instance** of that
class, sometimes referring to the variables that hold those objects "instance
variables."

Defining a Class
----------------

As with everything else in Python, the definition of a class must follow a
particular syntax:

.. admonition:: Syntax Pattern

   A class definition has the form:

   ::

      class <class name>:
          <body>

   Furthermore, the ``<body>`` can contain one or more **method definitions**:

   ::
  
      def <method name>(self, <optionally more parameters>):
          <body> 

   Each method definition is like any other function definition, but each
   method must have at least one parameter, and that first parameter is
   conventionally named ``self``.  [This isn't an absolute rule, but it will
   always be followed as far as we are concerned in this book.]

*[in progress]*


