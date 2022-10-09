An Example Program: Word Count
------------------------------

Text is a really interesting type of data. Computers can't read and understand text
the way humans do but they can process text as a special type of data (strings) and
tell us interesting things about the text. 

For example, companies will have data scientists write programs that analyze the
texts in Tweets to attempt to find out how much people like their product.
(This type of analysis is called 'sentiment' analysis.)

Sentiment analysis might involve counting how often some words (like 'Great!')
co-occur with a product name and tracking how often these co-occurences happen over time. 

We are going to look at a really basic program that is designed to analyze text
and tell us something about it. 

The file below contains the opening lines of :title:`A Tale of Two Cities` by
Charles Dickens (`source <https://www.gutenberg.org/ebooks/98>`_).

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

Let's say we were interested in finding out if Dickens preferred words that started
with a particular letter. A very short program could find an answer to the question
very quickly.

Keep in mind that while we are using just a short piece of A Tale of Two Cities as
an example, our program would be just as happy to analyze the entire book, and would
do it in a few seconds at most. Computers are particularly good at solving problems
that involve doing the same thing over and over again (like looking for a letter)
very quickly. 

Here's a short Python program for counting words that start with 'W'.  Try
running it!

.. activecode:: wordcount_example

   # Count words in a file starting with a given letter.

   countchar = 'w'

   file = open("atotc_opening.txt")

   text = file.read()

   words = text.split()

   count = 0
   for word in words:
       if word.startswith(countchar):
           count = count + 1

   file.close()

   print(f"{count} words start with '{countchar}'.")

Unless you've learned some programming before, this code probably looks like
nonsense to you. By the time you're done with the class you'll be able to read
this code and write similar programs for yourself. 

Let's take a look at the code and start to get a rough sense of how programs
work.  We'll point out and name some of the basic parts of Python programs
here, and most of them will be discussed in depth in the next few chapters.

.. index:: comment

The very first line is a **comment**:

.. code:: python

   # Count words in a file starting with a given letter.

Programs are instructions for the computer to follow, but this isn't an
instruction at all!  Comments are *ignored* by the computer when it executes
the program, and we write them for *ourselves*.  They let us include extra
information about the program that can help us or others reading our code
understand what it is doing or why we have written the code that way.

So how does the computer know that this is just a comment and not an
instruction?  The ``#`` character ("hash mark," "pound sign," "octothorpe"...
call it what you like) is the key.  The :ref:`syntax <syntax-definition>` of
the Python language includes a rule that states that anything following a ``#``
character is a comment.  So we have our first syntax pattern:

.. admonition:: Syntax Pattern

   **Comments** in Python start with a ``#`` character.

   Comments (anything following the ``#`` character on a line) will be ignored
   by Python when executing the program.

The next line of the program ``countchar = 'w'`` is an example of *assigning a
value to a variable*, also known as an *assignment*.  Here, it is telling the
computer which character to look for in the text.  Change the letter and re-run
the code to see what kind of answer you get. (If you want to tinker a bit, see
if uppercase and lowercase versions of the same letter give you the same
result. Try replacing one letter with two, like ``'th'`` and see if it works.)

The following line of code ``file = open("atotc_opening.txt")`` tells the
computer where to find the data and opens up the data to be analyzed.  It is
another example of assigning a value to a variable (you can see that it shares
the ``=`` symbol with the previous line), and it has a *function call*, where
the name ``open`` is followed by parentheses ``(`` ``)``.

The rest of the program involves more assignments and function calls (see if
you can see where those patterns are repeated), a *for loop* (that executes a
set of instructions repeatedly), and a *conditional* (starting with ``if``).
With these, the program goes through every word in the text file and counts
each word that starts with the letter we specified. The final line prints a
statement with the result.

You can tinker with the different lines to make the program do other things. You
could make it say something else by replacing 'words start with' in the last line.
When the computer doesn't understand what you are asking it to do it will report
an error. Don't worry if you're tinkering and the code stops working. Tinkering
is the best way to learn how things work.  

The data can be edited, too!  Add or remove some words in the data file up above,
and then check to make sure the program counts them correctly when you re-run it.

.. tip::

   **Try things and see what happens.**

   This interactive, iterative process is a great way to learn some aspects of
   programming.  Take some code, change it, run it, see what the result is, and
   repeat.  Try things [by changing the code] and see what happens [when you
   run the changed code].

And just as an example, here is another program that does the exact same thing
as the one above, but uses many fewer lines of code. 

.. activecode:: wordcount_example_succint

   # Count words in a file starting with a given letter.

   countchar = 'w'

   with open("atotc_opening.txt") as f:
       count = sum(word.startswith(countchar) for word in f.read().split())

   print(f"{count} words start with '{countchar}'.")

This version probably makes even less sense, and that's okay. It's important to
understand that the same task can be solved many different ways in programming. And 
since there isn't just one solution for any problem, we will need to also learn
about writing programs that other people can read and understand. 

Good code not only solves the problem, it is also clear and well-organized
(we will use the term well-structured inthe course). Bad code either doesn't do the
job correctly or is so convuoluted that other people can't understand it. When bad
code breaks it may be easier to simply re-write everything from scratch rather than
trying to decipher the code. By the end of this course you will understand 
how to write clear, straight-forward code that both instructs the computer to how to
correctly accomplish the task and that the other humans can also understand. 
