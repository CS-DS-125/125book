An Example Program: Word Count
------------------------------

Text is a really interesting type of data. Computers can't read and understand text the way humans do but they can process text as a special type of data (strings) and tell us interesting things about the text. 

For example, companies will have data scientists write programs that analyze the texts in Tweets to attempt to find out how much people like their product. (This type of analysis is called 'sentiment' analysis.)

Sentiment analysis might involve counting how often some words (like 'Great!') co-occur with a product name and tracking how often these co-occurences happen over time. 

We are going to look at a really basic program that is designed to analyze text and tell us something about it. 

The file below contains the opening lines of :title:`A Tale of Two Cities` by Charles Dickens.  

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

Let's say we were interested in finding out if Dickens preferred words that started with a particular letter. 
A very short program could find an answer to the question very quickly.

Keep in mind that while we are using just a short piece of A Tale of Two Cities as an example, our program would be just as happy to analyze the entire book, and would do it in a few seconds at most. Computers are particularly good at solving problems that involve doing the same thing over and over again (like looking for a letter) very quickly. 

Here's a short Python program for counting words that start with 'W'.  Try
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

Unless you've had some programming before, this code probably looks like nonsense to you. By the time you're done with the class you'll be able to read this code and write similar programs for yourself. 

Let's take a look at the code and start to get a rough sense of how programs work.
The first line of code is used to tell the computer which character to look for in the text. Change the letter and re-run the code to see what kind of answer you get. (If you want to tinker a bit, try to see if uppercase and lowercase versions of the same letter give you the same result. Try replacing one letter with two, like "th" and see if it works.)

The second line of code tells the computer where to find the data and opens up the data to be analyzed.

The rest of the program goes through every word in the text file and counts each word that starts with the letter we specified. The final line prints a statement with the result.

You can tinker with the different lines to make the program do other things. You could make it say something else by replacing 'words start with' in the last line. When the computer doesn't understand what you are asking it to do it will report an error. Don't worry if you're tinkering and the code stops working. Tinkering is the best way to learn how things work.  

The data can be edited, too!  Add or remove some words in the data file up above, and then check to make sure the program counts them correctly when you re-run it.

.. tip::

   **Try things and see what happens.**

   This interactive, iterative process is a great way to learn some aspects of
   programming.  Take some code, change it, run it, see what the result is, and
   repeat.  Try things [by changing the code] and see what happens [when you
   run the changed code].

And just for fun, here is another program that does the exact same thing as the one above, but uses many fewer lines of code. 

.. activecode:: wordcount_example_succint

   countchar = 'w'

   with open("atotc_opening.txt") as f:
       count = sum(word.startswith(countchar) for word in f.read().split())

   print("{} words start with '{}'.".format(count, countchar))

This version probably makes even less sense, and that's okay. It's important to understand that the same task can be solved many different ways in programming. And since there isn't just one solution for any probloem, we will need to also learn about writing programs that other people can read and evaluate. 

Good code not only solves the problem, it is also clear and straight-forward (we will use the term well-structured). By the end of this course we also hope you will understand how to write clear, straight-forward code that other humans can also understand. 
