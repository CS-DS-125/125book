An Example Program: Word Count
------------------------------

One branch of data science involves text analysis; let's look at a little
example of that type of analysis.  The file below contains the opening lines of
:title:`A Tale of Two Cities` by Charles Dickens.  This is a relatively short
piece of text to be using a program to analyze, but keep in mind that any
program that can analyze this text can analyze something hundreds or thousands
of times longer just as well.

.. datafile:: atotc_opening.txt
   :edit:

   It was the best of times,
   it was the worst of times,
   it was the age of wisdom,
   it was the age of foolishness,
   it was the epoch of belief,
   it was the epoch of incredulity,
   it was the season of Light,
   it was the season of Darkness,
   it was the spring of hope,
   it was the winter of despair,
   we had everything before us,
   we had nothing before us,
   we were all going direct to Heaven,
   we were all going direct the other way--
   in short, the period was so far like the present period, that some of
   its noisiest authorities insisted on its being received, for good or for
   evil, in the superlative degree of comparison only.


So that is our data, the input to our program.  Let's say we want to count the
number of words in the text that start with a particular letter.  (Like I said,
this is a "little" example; most real text analysis problems are rather more
complex.  But this still encompasses some of the basic steps most text analysis
will follow.)  The following is a Python program for solving that problem.  Try
running it!

.. activecode:: wordcount_example

   countchar = 'w'

   file = open("atotc_opening.txt")

   text = file.read()

   words = text.split()

   count = 0
   for word in words:
       if word.startswith(countchar):
           count = count + 1

   file.close()

   print("{} words start with '{}'.".format(count, countchar))

Now, this code probably makes very little sense to anyone who hasn't learned
much Python yet, but it still serves to show you some correct, well-structured
code for solving a problem; you can at least start to get a rough sense of how
Python works here.  And everything in there is something we will cover in this
book.  So this program can be aspirational for you, if you want; by working
through this book, you'll learn to write programs like that (and more!).

The above code can be edited and re-run.  Try changing the character that is
used to identify words to count, in the first line, and re-run the program.
The data can be edited, too!  Add or remove some words to the data file
included earlier, and check to make sure the program counts them correctly when
you re-run it.

.. tip::

   **Try things and see what happens.**

   This interactive, iterative process is a great way to learn some aspects of
   programming.  Take some code, change it, run it, see what the result is, and
   repeat.  Try things [by changing the code] and see what happens [when you
   run the changed code].

And just for fun, here is another program that does the exact same thing as the
one above, but more succinctly.

.. activecode:: wordcount_example_succint

   countchar = 'w'

   with open("atotc_opening.txt") as f:
       count = sum(word.startswith(countchar) for word in f.read().split())

   print("{} words start with '{}'.".format(count, countchar))

This version probably makes even less sense, and that's okay.  Some of the
tools used in this version are beyond what this book will ever cover.  But it
is a good example of how programming almost *never* has a single correct
solution.  There are incredibly many ways to write a program to solve even a
simple problem.
