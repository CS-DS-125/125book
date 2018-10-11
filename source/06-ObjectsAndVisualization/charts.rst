.. index:: charts

Charts
------

When you are dealing with a very small number of data points, its often easy to simply look and know something about what you've got. Let's say you were playing a card game and you had five cards in your hand. Without too much effort you could look at your hand and tell me the most common suit. However, the more data you have the harder it gets to just look and then draw some kind of reasonable conclusion. Let's say you could hold fifty cards in your hand. You would probably have to count them all to figure out the most common suit. Or rather than counting them, you could sort them into nice stacks and see which is the biggest. Fifty cards sorted into four nice stacks is a kind of summary of the data that may hide some of the detail, but helps you answer the question you are interested in. Good visualizations work the same way. 

Vizualizations are visual representations of data that are designed to make it easier to understand something about that data. They are a type of abstract representation and if they are done well they can be very powerful. However, it is also easy to do them poorly and to make something that is confusing or potentially misleading. Good visualizations should be clear and honest. 

There are many many different types of visuzalizations with different strengths and weakenesses. Choosing the right visualization for your question can be challenging so for now we are going to keep it simple and just talk about some key types of visualizations.  


Chart Terminology
~~~~~~~~~~~~~~~~~

A chart is a fairly common type of data visualization. Charts are often 2-dimensional figures with a horizontal x-axis and a vertical y-axis. Data is represented on these two axes using graphical elements such as lines, bars, or individual points. The x and y axes are typically labelled are marked with tic marks to help you understand what the axis is representing. 


Bar Charts
~~~~~~~~~~

Bar charts are good a representing differences between types of things. They typically plot different types of things (categories) along one axis and a numeric variables along the other. For example, a bar chart of my typical cookie consumption for the week might list types of cookies on the x-axis (categories: chocolate chip, oatmeal, sugarcookie) and then represent the number of each cookies I ate (quantitative data) as bars of different heights, with the height of the bar representing the quantitity of cookies consummed as indicated by the y-axis. Its important to realize that meanings of the bars can be very different. Those bars could represent the total number of calories in the cookies or my average mood following cookie consumption, instead of just number eaten. This is one reason that labelling your axis is important. 

Here's a more serious bar chart. Let's look at it and see what it is trying to communicate...


Line Charts
~~~~~~~~~~~

Line charts often plot something continuous (like time) on the x-axis with something quantitative on the y-axis. We could plot overall cookie consumption as a function of days of the week. The x-axis would be used to represent days sequentially. The y-axis would be used to indicate the total number of cookies eaten each day. Perhaps we'd find cookie consumption is highest on Monday and lowest on Fridays.  You should note here that you could use a bar chart for this instead, with each day being treated as its own category. That would make an okay chart, but using a line to link each day might do a better job at communicating trends over time. 

Here's a more serious line chart. Let's look at it and see what it is trying to communicate...


Scatterplots
~~~~~~~~~~~~

Scatter plots are often used to help us understand how two different things may be related. For example, let's say we were interested in if my cookie consumption was in some way related to my coffee consumption. To examine this question we might track my cookie and coffee consumption for thirty days and then make a scatterplot with number of cookies consumed represented on the x-axis and number of cups of coffee represnted on the y-axis. In this case each day would be represented as a dot somewhere on the graph. If my cookie and coffee consumption are somehow related the scatterplot might take some kind of shape, otherwise it might look fairly random and a bit like a cloud. 

Here's a more serious scatterplot. Let's look at it and see what it is trying to communicate...

Histograms
~~~~~~~~~~

Histograms look a lot like bar charts, but they are used to tell us something a bit more specific. Histograms are used to tell us the frequency at which something occurred in our data. Going back to cookies one last time, we might ask in a month of cookie eating how many days did I eat exactly five cookies? How many days did I eat zero cookies? In a histogram of cookie consumption the x-axis would represent the number of cookies consumed; the y-axis would represent the number of times that specific value occurred. I honestly don't eat all that many cookies, so in a thirty day period the most common number of cookies consummed would be zero. The next most common would probably be two, because who eats just one cookie? So if we looked at the bars in a histogram what we are seeing is the frequency (or count) of the number of times something occurs in our data.   

There is an additional complication to making histograms. When we make the graph we have to decide how many 'bins' to create along the x-axis. In the example above it might make sense to have each number represented by a single bin. This is the simplest kind of binning but its often not possible to do use the x-axis in this way. Let's say we wanted to make a histogram representing average monthly income for people from all around the world. It would not be possible to represent every value on the x-axis in a practical way - our graph would likely be  too long to be displayed. Instead we would make a decision about grouping certain ranges of incomes together. The histograms would then represent the frequency of data points that we placed into these 'bins'. How we choose to bin can have a significant impact on what the histogram looks like, and what conclusion we might come to about the data, so you will need to be careful and thoughtful about how you selected bins.   

Here's a more serious histogram. Let's look at it and see what it is trying to communicate...


