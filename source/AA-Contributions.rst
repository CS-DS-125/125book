
Contributions
=============

This book has a long, *long* list of past authors and contributors.  It has
been adapted and updated over many years and many versions.  The following
includes contributors and prefaces from previous versions from which this book
has grown.

Preface for *Python for Everybody*
----------------------------------

Remixing an Open Book
:::::::::::::::::::::

It is quite natural for academics who are continuously told to "publish
or perish" to want to always create something from scratch that is their
own fresh creation. This book is an experiment in not starting from
scratch, but instead "remixing" the book titled *Think Python: How to
Think Like a Computer Scientist* written by Allen B. Downey, Jeff
Elkner, and others.

In December of 2009, I was preparing to teach *SI502 - Networked
Programming* at the University of Michigan for the fifth semester in a
row and decided it was time to write a Python textbook that focused on
exploring data instead of understanding algorithms and abstractions. My
goal in SI502 is to teach people lifelong data handling skills using
Python. Few of my students were planning to be professional computer
programmers. Instead, they planned to be librarians, managers, lawyers,
biologists, economists, etc., who happened to want to skillfully use
technology in their chosen field.

I never seemed to find the perfect data-oriented Python book for my
course, so I set out to write just such a book. Luckily at a faculty
meeting three weeks before I was about to start my new book from scratch
over the holiday break, Dr. Atul Prakash showed me the *Think Python*
book which he had used to teach his Python course that semester. It is a
well-written Computer Science text with a focus on short, direct
explanations and ease of learning.

The overall book structure has been changed to get to doing data
analysis problems as quickly as possible and have a series of running
examples and exercises about data analysis from the very beginning.

Chapters 2–10 are similar to the *Think Python* book, but there have
been major changes. Number-oriented examples and exercises have been
replaced with data-oriented exercises. Topics are presented in the order
needed to build increasingly sophisticated data analysis solutions. Some
topics like ``try`` and ``except`` are pulled forward and presented as
part of the chapter on conditionals. Functions are given very light
treatment until they are needed to handle program complexity rather than
introduced as an early lesson in abstraction. Nearly all user-defined
functions have been removed from the example code and exercises outside
of Chapter 4. The word "recursion" [1]_ does not appear in the book at
all.

In chapters 1 and 11–16, all of the material is brand new, focusing on
real-world uses and simple examples of Python for data analysis
including regular expressions for searching and parsing, automating
tasks on your computer, retrieving data across the network, scraping web
pages for data, object-oriented programming, using web services, parsing
XML and JSON data, creating and using databases using Structured Query
Language, and visualizing data.

The ultimate goal of all of these changes is to shift from a Computer
Science to an Informatics focus and to only include topics into a first
technology class that can be useful even if one chooses not to become a
professional programmer.

Students who find this book interesting and want to further explore
should look at Allen B. Downey’s *Think Python* book. Because there is a
lot of overlap between the two books, students will quickly pick up
skills in the additional areas of technical programming and algorithmic
thinking that are covered in *Think Python*. And given that the books
have a similar writing style, they should be able to move quickly
through *Think Python* with a minimum of effort.

As the copyright holder of *Think Python*, Allen has given me permission
to change the book’s license on the material from his book that remains
in this book from the GNU Free Documentation License to the more recent
Creative Commons Attribution — Share Alike license. This follows a
general shift in open documentation licenses moving from the GFDL to the
CC-BY-SA (e.g., Wikipedia). Using the CC-BY-SA license maintains the
book’s strong copyleft tradition while making it even more
straightforward for new authors to reuse this material as they see fit.

I feel that this book serves as an example of why open materials are so
important to the future of education, and I want to thank Allen B.
Downey and Cambridge University Press for their forward-looking decision
to make the book available under an open copyright. I hope they are
pleased with the results of my efforts and I hope that you, the reader,
are pleased with *our* collective efforts.

I would like to thank Allen B. Downey and Lauren Cowles for their help,
patience, and guidance in dealing with and resolving the copyright
issues around this book.

| Charles Severance
| www.dr-chuck.com
| Ann Arbor, MI, USA
| September 9, 2013

Charles Severance is a Clinical Associate Professor at the University of
Michigan School of Information.

.. [1]
   Except, of course, for this line.


Contributor List for *Python for Everybody*
-------------------------------------------

Elliott Hauser, Stephen Catto, Sue Blumenberg, Tamara Brunnock, Mihaela
Mack, Chris Kolosiwsky, Dustin Farley, Jens Leerssen, Naveen KT, Mirza
Ibrahimovic, Naveen (@togarnk), Zhou Fangyi, Alistair Walsh, Erica
Brody, Jih-Sheng Huang, Louis Luangkesorn, and Michael Fudge

You can see contribution details at:

https://github.com/csev/py4e/graphs/contributors

Contributor List for *Python for Informatics*
---------------------------------------------

Bruce Shields for copy editing early drafts, Sarah Hegge, Steven Cherry,
Sarah Kathleen Barbarow, Andrea Parker, Radaphat Chongthammakun, Megan
Hixon, Kirby Urner, Sarah Kathleen Barbrow, Katie Kujala, Noah Botimer,
Emily Alinder, Mark Thompson-Kular, James Perry, Eric Hofer, Eytan Adar,
Peter Robinson, Deborah J. Nelson, Jonathan C. Anthony, Eden Rassette,
Jeannette Schroeder, Justin Feezell, Chuanqi Li, Gerald Gordinier, Gavin
Thomas Strassel, Ryan Clement, Alissa Talley, Caitlin Holman, Yong-Mi
Kim, Karen Stover, Cherie Edmonds, Maria Seiferle, Romer Kristi D.
Aranas (RK), Grant Boyer, Hedemarrie Dussan,

Preface for "Think Python"
--------------------------

The strange history of "Think Python"
:::::::::::::::::::::::::::::::::::::

(Allen B. Downey)

In January 1999 I was preparing to teach an introductory programming
class in Java. I had taught it three times and I was getting frustrated.
The failure rate in the class was too high and, even for students who
succeeded, the overall level of achievement was too low.

One of the problems I saw was the books. They were too big, with too
much unnecessary detail about Java, and not enough high-level guidance
about how to program. And they all suffered from the trap door effect:
they would start out easy, proceed gradually, and then somewhere around
Chapter 5 the bottom would fall out. The students would get too much new
material, too fast, and I would spend the rest of the semester picking
up the pieces.

Two weeks before the first day of classes, I decided to write my own
book. My goals were:

-  Keep it short. It is better for students to read 10 pages than not
   read 50 pages.

-  Be careful with vocabulary. I tried to minimize the jargon and define
   each term at first use.

-  Build gradually. To avoid trap doors, I took the most difficult
   topics and split them into a series of small steps.

-  Focus on programming, not the programming language. I included the
   minimum useful subset of Java and left out the rest.

I needed a title, so on a whim I chose *How to Think Like a Computer
Scientist*.

My first version was rough, but it worked. Students did the reading, and
they understood enough that I could spend class time on the hard topics,
the interesting topics and (most important) letting the students
practice.

I released the book under the GNU Free Documentation License, which
allows users to copy, modify, and distribute the book.

What happened next is the cool part. Jeff Elkner, a high school teacher
in Virginia, adopted my book and translated it into Python. He sent me a
copy of his translation, and I had the unusual experience of learning
Python by reading my own book.

Jeff and I revised the book, incorporated a case study by Chris Meyers,
and in 2001 we released *How to Think Like a Computer Scientist:
Learning with Python*, also under the GNU Free Documentation License. As
Green Tea Press, I published the book and started selling hard copies
through Amazon.com and college book stores. Other books from Green Tea
Press are available at `greenteapress.com <http://greenteapress.com>`__.

In 2003 I started teaching at Olin College and I got to teach Python for
the first time. The contrast with Java was striking. Students struggled
less, learned more, worked on more interesting projects, and generally
had a lot more fun.

Over the last five years I have continued to develop the book,
correcting errors, improving some of the examples and adding material,
especially exercises. In 2008 I started work on a major revision—at the
same time, I was contacted by an editor at Cambridge University Press
who was interested in publishing the next edition. Good timing!

I hope you enjoy working with this book, and that it helps you learn to
program and think, at least a little bit, like a computer scientist.

Acknowledgements for "Think Python"
:::::::::::::::::::::::::::::::::::

(Allen B. Downey)

First and most importantly, I thank Jeff Elkner, who translated my Java
book into Python, which got this project started and introduced me to
what has turned out to be my favorite language.

I also thank Chris Meyers, who contributed several sections to *How to
Think Like a Computer Scientist*.

And I thank the Free Software Foundation for developing the GNU Free
Documentation License, which helped make my collaboration with Jeff and
Chris possible.

I also thank the editors at Lulu who worked on *How to Think Like a
Computer Scientist*.

I thank all the students who worked with earlier versions of this book
and all the contributors (listed in an Appendix) who sent in corrections
and suggestions.

And I thank my wife, Lisa, for her work on this book, and Green Tea
Press, and everything else, too.

| Allen B. Downey
| Needham MA

Allen Downey is an Associate Professor of Computer Science at the
Franklin W. Olin College of Engineering.

Contributor List for "Think Python"
-----------------------------------

(Allen B. Downey)

More than 100 sharp-eyed and thoughtful readers have sent in suggestions
and corrections over the past few years. Their contributions, and
enthusiasm for this project, have been a huge help.

For the detail on the nature of each of the contributions from these
individuals, see the "Think Python" text.

Lloyd Hugh Allen, Yvon Boulianne, Fred Bremmer, Jonah Cohen, Michael
Conlon, Benoit Girard, Courtney Gleason and Katherine Smith, Lee Harr,
James Kaylin, David Kershaw, Eddie Lam, Man-Yong Lee, David Mayo, Chris
McAloon, Matthew J. Moelter, Simon Dicon Montford, John Ouzts, Kevin
Parks, David Pool, Michael Schmitt, Robin Shaw, Paul Sleigh, Craig T.
Snydal, Ian Thomas, Keith Verheyden, Peter Winstanley, Chris Wrobel,
Moshe Zadka, Christoph Zwerschke, James Mayer, Hayden McAfee, Angel
Arnal, Tauhidul Hoque and Lex Berezhny, Dr. Michele Alzetta, Andy
Mitchell, Kalin Harvey, Christopher P. Smith, David Hutchins, Gregor
Lingl, Julie Peters, Florin Oprina, D. J. Webre, Ken, Ivo Wever, Curtis
Yanko, Ben Logan, Jason Armstrong, Louis Cordier, Brian Cain, Rob Black,
Jean-Philippe Rey at Ecole Centrale Paris, Jason Mader at George
Washington University made a number Jan Gundtofte-Bruun, Abel David and
Alexis Dinno, Charles Thayer, Roger Sperberg, Sam Bull, Andrew Cheung,
C. Corey Capel, Alessandra, Wim Champagne, Douglas Wright, Jared
Spindor, Lin Peiheng, Ray Hagtvedt, Torsten Hübsch, Inga Petuhhov, Arne
Babenhauserheide, Mark E. Casida, Scott Tyler, Gordon Shephard, Andrew
Turner, Adam Hobart, Daryl Hammond and Sarah Zimmerman, George Sass,
Brian Bingham, Leah Engelbert-Fenton, Joe Funke, Chao-chao Chen, Jeff
Paine, Lubos Pintes, Gregg Lind and Abigail Heithoff, Max Hailperin,
Chotipat Pornavalai, Stanislaw Antol, Eric Pashman, Miguel Azevedo,
Jianhua Liu, Nick King, Martin Zuther, Adam Zimmerman, Ratnakar Tiwari,
Anurag Goel, Kelli Kratzer, Mark Griffiths, Roydan Ongie, Patryk
Wolowiec, Mark Chonofsky, Russell Coleman, Wei Huang, Karen Barber, Nam
Nguyen, Stéphane Morin, Fernando Tardio, and Paul Stoop.
