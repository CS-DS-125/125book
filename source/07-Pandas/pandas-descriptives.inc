An Introduction to Working with Dataframes
==========================================

We used Pandas a bit in our work on visualizations. We are going to use
a lot more Pandas from here on out. Before we get into some of the
technical details of how Pandas works we are going to introduce you to
some methods just so you can get a sense of why Pandas is such a good
tool for working with data.

The specific dataframe methods we will use that we haven’t covered
before are:

-  ``shape``
-  ``head()``
-  ``tail()``
-  ``describe()``
-  ``transpose()``
-  ``sort_values()``
-  ``mean()``

We will also be using a few methods we have seen previously:

-  ``query()``
-  ``groupby()``

--------------

First, some imports and some code to make our charts look nicer.

.. code:: python

    import pandas as pd
    import matplotlib.pyplot as plt

.. code:: python

    # For slightly nicer charts
    %config InlineBackend.figure_formats = ['svg']
    plt.rcParams['figure.figsize'] = [10, 5]
    plt.rcParams['figure.dpi'] = 150

--------------

Now we read a CSV file of quiz grades and assign it to a variable called
``df``. This is the ‘broadway’ dataset we have been working with and it
contains a column of dates that we want pandas to treat as dates so we
are going to include an argument to treat the ‘Full’ column as a date.

.. code:: python

    df = pd.read_csv("broadway.csv", parse_dates=["Full"])

At this point all we know is that we’ve successfully read a CSV file.
Let’s find out some more about the data. First, let’s find out how much
data there is in the file.

.. code:: python

    df.shape




.. parsed-literal::

    (31296, 12)



``shape`` is a list of two numbers (technically a “tuple,” but it’s a
lot like a list) that represent the number of rows and the number of
columns in your dataframe. The broadway data set has 31,296 rows (each
representing one week of one show) and 12 columns.

It might be a good idea to get a look at our dataframe, but 31,296 rows
seems like a bit much to look at all at once. We can look at just parts
of the dataframe by using the dataframe methods ``head()`` and/or
``tail()``.

.. code:: python

    df.head()




.. raw:: html

    <div>
    <style scoped>
        .dataframe tbody tr th:only-of-type {
            vertical-align: middle;
        }
    
        .dataframe tbody tr th {
            vertical-align: top;
        }
    
        .dataframe thead th {
            text-align: right;
        }
    </style>
    <table border="1" class="dataframe">
      <thead>
        <tr style="text-align: right;">
          <th></th>
          <th>Attendance</th>
          <th>Capacity</th>
          <th>Day</th>
          <th>Full</th>
          <th>Gross</th>
          <th>Gross Potential</th>
          <th>Month</th>
          <th>Name</th>
          <th>Performances</th>
          <th>Theatre</th>
          <th>Type</th>
          <th>Year</th>
        </tr>
      </thead>
      <tbody>
        <tr>
          <th>0</th>
          <td>5500</td>
          <td>88</td>
          <td>26</td>
          <td>1990-08-26</td>
          <td>134456</td>
          <td>0</td>
          <td>8</td>
          <td>Tru</td>
          <td>8</td>
          <td>Booth</td>
          <td>Play</td>
          <td>1990</td>
        </tr>
        <tr>
          <th>1</th>
          <td>1737</td>
          <td>100</td>
          <td>24</td>
          <td>1991-03-24</td>
          <td>100647</td>
          <td>0</td>
          <td>3</td>
          <td>Miss Saigon</td>
          <td>0</td>
          <td>Broadway</td>
          <td>Musical</td>
          <td>1991</td>
        </tr>
        <tr>
          <th>2</th>
          <td>12160</td>
          <td>100</td>
          <td>31</td>
          <td>1991-03-31</td>
          <td>634424</td>
          <td>0</td>
          <td>3</td>
          <td>Miss Saigon</td>
          <td>0</td>
          <td>Broadway</td>
          <td>Musical</td>
          <td>1991</td>
        </tr>
        <tr>
          <th>3</th>
          <td>13921</td>
          <td>100</td>
          <td>7</td>
          <td>1991-04-07</td>
          <td>713353</td>
          <td>0</td>
          <td>4</td>
          <td>Miss Saigon</td>
          <td>0</td>
          <td>Broadway</td>
          <td>Musical</td>
          <td>1991</td>
        </tr>
        <tr>
          <th>4</th>
          <td>10973</td>
          <td>90</td>
          <td>14</td>
          <td>1991-04-14</td>
          <td>573981</td>
          <td>0</td>
          <td>4</td>
          <td>Miss Saigon</td>
          <td>4</td>
          <td>Broadway</td>
          <td>Musical</td>
          <td>1991</td>
        </tr>
      </tbody>
    </table>
    </div>



.. code:: python

    df.tail()




.. raw:: html

    <div>
    <style scoped>
        .dataframe tbody tr th:only-of-type {
            vertical-align: middle;
        }
    
        .dataframe tbody tr th {
            vertical-align: top;
        }
    
        .dataframe thead th {
            text-align: right;
        }
    </style>
    <table border="1" class="dataframe">
      <thead>
        <tr style="text-align: right;">
          <th></th>
          <th>Attendance</th>
          <th>Capacity</th>
          <th>Day</th>
          <th>Full</th>
          <th>Gross</th>
          <th>Gross Potential</th>
          <th>Month</th>
          <th>Name</th>
          <th>Performances</th>
          <th>Theatre</th>
          <th>Type</th>
          <th>Year</th>
        </tr>
      </thead>
      <tbody>
        <tr>
          <th>31291</th>
          <td>7234</td>
          <td>87</td>
          <td>14</td>
          <td>2016-08-14</td>
          <td>603770</td>
          <td>62</td>
          <td>8</td>
          <td>The Humans</td>
          <td>8</td>
          <td>Schoenfeld</td>
          <td>Play</td>
          <td>2016</td>
        </tr>
        <tr>
          <th>31292</th>
          <td>13485</td>
          <td>99</td>
          <td>14</td>
          <td>2016-08-14</td>
          <td>2233894</td>
          <td>97</td>
          <td>8</td>
          <td>The Lion King</td>
          <td>8</td>
          <td>Minskoff</td>
          <td>Musical</td>
          <td>2016</td>
        </tr>
        <tr>
          <th>31293</th>
          <td>10966</td>
          <td>85</td>
          <td>14</td>
          <td>2016-08-14</td>
          <td>999632</td>
          <td>66</td>
          <td>8</td>
          <td>The Phantom Of The Opera</td>
          <td>8</td>
          <td>Majestic</td>
          <td>Musical</td>
          <td>2016</td>
        </tr>
        <tr>
          <th>31294</th>
          <td>8058</td>
          <td>96</td>
          <td>14</td>
          <td>2016-08-14</td>
          <td>990128</td>
          <td>97</td>
          <td>8</td>
          <td>Waitress</td>
          <td>8</td>
          <td>Brooks Atkinson</td>
          <td>Musical</td>
          <td>2016</td>
        </tr>
        <tr>
          <th>31295</th>
          <td>13804</td>
          <td>95</td>
          <td>14</td>
          <td>2016-08-14</td>
          <td>1779664</td>
          <td>100</td>
          <td>8</td>
          <td>Wicked</td>
          <td>8</td>
          <td>Gershwin</td>
          <td>Musical</td>
          <td>2016</td>
        </tr>
      </tbody>
    </table>
    </div>



``head()`` returns first five rows by default, while ``tail()`` returns
the last five rows.

We can pass an integer as an argument to ``head()`` or ``tail()`` to get
more rows or fewer rows.

.. code:: python

    df.head(15)




.. raw:: html

    <div>
    <style scoped>
        .dataframe tbody tr th:only-of-type {
            vertical-align: middle;
        }
    
        .dataframe tbody tr th {
            vertical-align: top;
        }
    
        .dataframe thead th {
            text-align: right;
        }
    </style>
    <table border="1" class="dataframe">
      <thead>
        <tr style="text-align: right;">
          <th></th>
          <th>Attendance</th>
          <th>Capacity</th>
          <th>Day</th>
          <th>Full</th>
          <th>Gross</th>
          <th>Gross Potential</th>
          <th>Month</th>
          <th>Name</th>
          <th>Performances</th>
          <th>Theatre</th>
          <th>Type</th>
          <th>Year</th>
        </tr>
      </thead>
      <tbody>
        <tr>
          <th>0</th>
          <td>5500</td>
          <td>88</td>
          <td>26</td>
          <td>1990-08-26</td>
          <td>134456</td>
          <td>0</td>
          <td>8</td>
          <td>Tru</td>
          <td>8</td>
          <td>Booth</td>
          <td>Play</td>
          <td>1990</td>
        </tr>
        <tr>
          <th>1</th>
          <td>1737</td>
          <td>100</td>
          <td>24</td>
          <td>1991-03-24</td>
          <td>100647</td>
          <td>0</td>
          <td>3</td>
          <td>Miss Saigon</td>
          <td>0</td>
          <td>Broadway</td>
          <td>Musical</td>
          <td>1991</td>
        </tr>
        <tr>
          <th>2</th>
          <td>12160</td>
          <td>100</td>
          <td>31</td>
          <td>1991-03-31</td>
          <td>634424</td>
          <td>0</td>
          <td>3</td>
          <td>Miss Saigon</td>
          <td>0</td>
          <td>Broadway</td>
          <td>Musical</td>
          <td>1991</td>
        </tr>
        <tr>
          <th>3</th>
          <td>13921</td>
          <td>100</td>
          <td>7</td>
          <td>1991-04-07</td>
          <td>713353</td>
          <td>0</td>
          <td>4</td>
          <td>Miss Saigon</td>
          <td>0</td>
          <td>Broadway</td>
          <td>Musical</td>
          <td>1991</td>
        </tr>
        <tr>
          <th>4</th>
          <td>10973</td>
          <td>90</td>
          <td>14</td>
          <td>1991-04-14</td>
          <td>573981</td>
          <td>0</td>
          <td>4</td>
          <td>Miss Saigon</td>
          <td>4</td>
          <td>Broadway</td>
          <td>Musical</td>
          <td>1991</td>
        </tr>
        <tr>
          <th>5</th>
          <td>14076</td>
          <td>101</td>
          <td>21</td>
          <td>1991-04-21</td>
          <td>706793</td>
          <td>0</td>
          <td>4</td>
          <td>Miss Saigon</td>
          <td>8</td>
          <td>Broadway</td>
          <td>Musical</td>
          <td>1991</td>
        </tr>
        <tr>
          <th>6</th>
          <td>14065</td>
          <td>101</td>
          <td>28</td>
          <td>1991-04-28</td>
          <td>714968</td>
          <td>0</td>
          <td>4</td>
          <td>Miss Saigon</td>
          <td>8</td>
          <td>Broadway</td>
          <td>Musical</td>
          <td>1991</td>
        </tr>
        <tr>
          <th>7</th>
          <td>14064</td>
          <td>101</td>
          <td>5</td>
          <td>1991-05-05</td>
          <td>730765</td>
          <td>0</td>
          <td>5</td>
          <td>Miss Saigon</td>
          <td>8</td>
          <td>Broadway</td>
          <td>Musical</td>
          <td>1991</td>
        </tr>
        <tr>
          <th>8</th>
          <td>13896</td>
          <td>100</td>
          <td>12</td>
          <td>1991-05-12</td>
          <td>766713</td>
          <td>0</td>
          <td>5</td>
          <td>Miss Saigon</td>
          <td>8</td>
          <td>Broadway</td>
          <td>Musical</td>
          <td>1991</td>
        </tr>
        <tr>
          <th>9</th>
          <td>13738</td>
          <td>99</td>
          <td>19</td>
          <td>1991-05-19</td>
          <td>763332</td>
          <td>0</td>
          <td>5</td>
          <td>Miss Saigon</td>
          <td>8</td>
          <td>Broadway</td>
          <td>Musical</td>
          <td>1991</td>
        </tr>
        <tr>
          <th>10</th>
          <td>13897</td>
          <td>100</td>
          <td>26</td>
          <td>1991-05-26</td>
          <td>769137</td>
          <td>0</td>
          <td>5</td>
          <td>Miss Saigon</td>
          <td>8</td>
          <td>Broadway</td>
          <td>Musical</td>
          <td>1991</td>
        </tr>
        <tr>
          <th>11</th>
          <td>14016</td>
          <td>101</td>
          <td>2</td>
          <td>1991-06-02</td>
          <td>774412</td>
          <td>0</td>
          <td>6</td>
          <td>Miss Saigon</td>
          <td>8</td>
          <td>Broadway</td>
          <td>Musical</td>
          <td>1991</td>
        </tr>
        <tr>
          <th>12</th>
          <td>14088</td>
          <td>101</td>
          <td>9</td>
          <td>1991-06-09</td>
          <td>771767</td>
          <td>0</td>
          <td>6</td>
          <td>Miss Saigon</td>
          <td>8</td>
          <td>Broadway</td>
          <td>Musical</td>
          <td>1991</td>
        </tr>
        <tr>
          <th>13</th>
          <td>14088</td>
          <td>101</td>
          <td>16</td>
          <td>1991-06-16</td>
          <td>770819</td>
          <td>0</td>
          <td>6</td>
          <td>Miss Saigon</td>
          <td>8</td>
          <td>Broadway</td>
          <td>Musical</td>
          <td>1991</td>
        </tr>
        <tr>
          <th>14</th>
          <td>14088</td>
          <td>101</td>
          <td>23</td>
          <td>1991-06-23</td>
          <td>771192</td>
          <td>0</td>
          <td>6</td>
          <td>Miss Saigon</td>
          <td>8</td>
          <td>Broadway</td>
          <td>Musical</td>
          <td>1991</td>
        </tr>
      </tbody>
    </table>
    </div>



One reason you want to look at your dataframe this way is because you
want to make sure that it was read correctly. We have been giving you
clean data that is read correctly. Real-world data will not always be
read properly, and you need to know if it wasn’t before you start
working on your data analysis. Visually inspecting your data is one way
to check to see if things are working. Another way would be to look at
some summary statistics to see if anything looks odd.

Pandas has a nice dataframe method for looking at summary statistics
called ``describe()``.

.. code:: python

    df.describe()




.. raw:: html

    <div>
    <style scoped>
        .dataframe tbody tr th:only-of-type {
            vertical-align: middle;
        }
    
        .dataframe tbody tr th {
            vertical-align: top;
        }
    
        .dataframe thead th {
            text-align: right;
        }
    </style>
    <table border="1" class="dataframe">
      <thead>
        <tr style="text-align: right;">
          <th></th>
          <th>Attendance</th>
          <th>Capacity</th>
          <th>Day</th>
          <th>Gross</th>
          <th>Gross Potential</th>
          <th>Month</th>
          <th>Performances</th>
          <th>Year</th>
        </tr>
      </thead>
      <tbody>
        <tr>
          <th>count</th>
          <td>31296.000000</td>
          <td>31296.000000</td>
          <td>31296.000000</td>
          <td>3.129600e+04</td>
          <td>31296.000000</td>
          <td>31296.000000</td>
          <td>31296.000000</td>
          <td>31296.000000</td>
        </tr>
        <tr>
          <th>mean</th>
          <td>8010.523006</td>
          <td>80.738912</td>
          <td>15.720859</td>
          <td>5.960688e+05</td>
          <td>62.404045</td>
          <td>6.509043</td>
          <td>7.224821</td>
          <td>2005.875128</td>
        </tr>
        <tr>
          <th>std</th>
          <td>3189.873933</td>
          <td>18.842815</td>
          <td>8.817000</td>
          <td>3.809796e+05</td>
          <td>28.714589</td>
          <td>3.430321</td>
          <td>2.235376</td>
          <td>6.100118</td>
        </tr>
        <tr>
          <th>min</th>
          <td>24.000000</td>
          <td>10.000000</td>
          <td>1.000000</td>
          <td>1.037000e+03</td>
          <td>0.000000</td>
          <td>1.000000</td>
          <td>0.000000</td>
          <td>1990.000000</td>
        </tr>
        <tr>
          <th>25%</th>
          <td>5508.000000</td>
          <td>70.000000</td>
          <td>8.000000</td>
          <td>3.201085e+05</td>
          <td>45.000000</td>
          <td>4.000000</td>
          <td>8.000000</td>
          <td>2001.000000</td>
        </tr>
        <tr>
          <th>50%</th>
          <td>7801.500000</td>
          <td>83.000000</td>
          <td>16.000000</td>
          <td>5.145200e+05</td>
          <td>63.000000</td>
          <td>6.000000</td>
          <td>8.000000</td>
          <td>2006.000000</td>
        </tr>
        <tr>
          <th>75%</th>
          <td>10348.000000</td>
          <td>95.000000</td>
          <td>23.000000</td>
          <td>7.852690e+05</td>
          <td>82.000000</td>
          <td>10.000000</td>
          <td>8.000000</td>
          <td>2011.000000</td>
        </tr>
        <tr>
          <th>max</th>
          <td>21631.000000</td>
          <td>892.000000</td>
          <td>31.000000</td>
          <td>3.201333e+06</td>
          <td>226.000000</td>
          <td>12.000000</td>
          <td>16.000000</td>
          <td>2016.000000</td>
        </tr>
      </tbody>
    </table>
    </div>



This is great information, but it’s a bit hard to read in this
orientation.

Dataframes have a method called ``transpose()`` that returns a new
dataframe that is a flipped copy of the original (columns become rows
and vice versa). The ``describe()`` method returns a dataframe, so we
can flip it by calling ``.transpose()`` on the result of
``.describe()``:

.. code:: python

    df.describe().transpose()




.. raw:: html

    <div>
    <style scoped>
        .dataframe tbody tr th:only-of-type {
            vertical-align: middle;
        }
    
        .dataframe tbody tr th {
            vertical-align: top;
        }
    
        .dataframe thead th {
            text-align: right;
        }
    </style>
    <table border="1" class="dataframe">
      <thead>
        <tr style="text-align: right;">
          <th></th>
          <th>count</th>
          <th>mean</th>
          <th>std</th>
          <th>min</th>
          <th>25%</th>
          <th>50%</th>
          <th>75%</th>
          <th>max</th>
        </tr>
      </thead>
      <tbody>
        <tr>
          <th>Attendance</th>
          <td>31296.0</td>
          <td>8010.523006</td>
          <td>3189.873933</td>
          <td>24.0</td>
          <td>5508.0</td>
          <td>7801.5</td>
          <td>10348.0</td>
          <td>21631.0</td>
        </tr>
        <tr>
          <th>Capacity</th>
          <td>31296.0</td>
          <td>80.738912</td>
          <td>18.842815</td>
          <td>10.0</td>
          <td>70.0</td>
          <td>83.0</td>
          <td>95.0</td>
          <td>892.0</td>
        </tr>
        <tr>
          <th>Day</th>
          <td>31296.0</td>
          <td>15.720859</td>
          <td>8.817000</td>
          <td>1.0</td>
          <td>8.0</td>
          <td>16.0</td>
          <td>23.0</td>
          <td>31.0</td>
        </tr>
        <tr>
          <th>Gross</th>
          <td>31296.0</td>
          <td>596068.813682</td>
          <td>380979.640655</td>
          <td>1037.0</td>
          <td>320108.5</td>
          <td>514520.0</td>
          <td>785269.0</td>
          <td>3201333.0</td>
        </tr>
        <tr>
          <th>Gross Potential</th>
          <td>31296.0</td>
          <td>62.404045</td>
          <td>28.714589</td>
          <td>0.0</td>
          <td>45.0</td>
          <td>63.0</td>
          <td>82.0</td>
          <td>226.0</td>
        </tr>
        <tr>
          <th>Month</th>
          <td>31296.0</td>
          <td>6.509043</td>
          <td>3.430321</td>
          <td>1.0</td>
          <td>4.0</td>
          <td>6.0</td>
          <td>10.0</td>
          <td>12.0</td>
        </tr>
        <tr>
          <th>Performances</th>
          <td>31296.0</td>
          <td>7.224821</td>
          <td>2.235376</td>
          <td>0.0</td>
          <td>8.0</td>
          <td>8.0</td>
          <td>8.0</td>
          <td>16.0</td>
        </tr>
        <tr>
          <th>Year</th>
          <td>31296.0</td>
          <td>2005.875128</td>
          <td>6.100118</td>
          <td>1990.0</td>
          <td>2001.0</td>
          <td>2006.0</td>
          <td>2011.0</td>
          <td>2016.0</td>
        </tr>
      </tbody>
    </table>
    </div>



So what is all this?

-  ‘count’ is the number of values for that variable.
-  ‘mean’ is the average.
-  ‘std’ is the standard deviation. We will talk about this later.
-  ‘min’ in the minimum value out of all of the rows.
-  ‘25%’, ‘50%’, and ‘75%’ are percentiles. We are going to skip these
   for now.
-  ‘max’ is the maximum value out of all of the rows.

In this particular dataset ‘count’ is pretty boring. The count is the
same for all of the variables and is equal to the number of rows,
because every row in the dataset has some value for every variable.
Later we will run into datasets where values are missing and the counts
may vary quite a bit from variable to variable.

If you are just getting to know your dataset, it’s worth looking at the
count, mean, min, and max to get a sense of things and to check that
they are in a reasonable range. The maximum attendance in a month in
this dataset is 21,631, that seems like a lot of people for one venue.
You might remember we noticed some potentially odd data when we were
looking at the Capacity column earlier, so it is worth looking into this
to see if this Attendance number seems reasonable. One way we can do
that is to plot a histogram of attendance.

.. code:: python

    plt.hist(x="Attendance", data=df, bins=20)
    plt.xlabel("Attendance")
    plt.ylabel("Count")
    plt.title("Histogram of Attendance Over a Month")
    plt.show()



.. image:: pandas-descriptives_files/pandas-descriptives_18_0.svg


Now we have a sense on the Attendance data as a whole, but we can’t see
much about the highest range on this histogram. Let’s use the
``query()`` method we used earlier to only look at Attendance counts
above 16000.

.. code:: python

    df_filtered_attend = df.query('Attendance > 16000')
    plt.hist(x="Attendance", data=df_filtered_attend, bins=40)
    plt.xlabel("Attendance")
    plt.ylabel("Count")
    plt.title("Histogram of Attendance Above 16000")
    plt.show()



.. image:: pandas-descriptives_files/pandas-descriptives_20_0.svg


Our histogram indicates that anything above 16000 in attendance occurs
fairly infrequently; But our 21631 max also isn’t completely isolated.
There have been other performances that get close to this number. Let’s
do some more digging. It might be interesting to know the top ten
performances in terms of attendance.

The ``sort_values()`` dataframe method will help us do this.

.. code:: python

    df.sort_values(by='Attendance', ascending=False).head(20)




.. raw:: html

    <div>
    <style scoped>
        .dataframe tbody tr th:only-of-type {
            vertical-align: middle;
        }
    
        .dataframe tbody tr th {
            vertical-align: top;
        }
    
        .dataframe thead th {
            text-align: right;
        }
    </style>
    <table border="1" class="dataframe">
      <thead>
        <tr style="text-align: right;">
          <th></th>
          <th>Attendance</th>
          <th>Capacity</th>
          <th>Day</th>
          <th>Full</th>
          <th>Gross</th>
          <th>Gross Potential</th>
          <th>Month</th>
          <th>Name</th>
          <th>Performances</th>
          <th>Theatre</th>
          <th>Type</th>
          <th>Year</th>
        </tr>
      </thead>
      <tbody>
        <tr>
          <th>1711</th>
          <td>21631</td>
          <td>100</td>
          <td>29</td>
          <td>1996-12-29</td>
          <td>1315753</td>
          <td>0</td>
          <td>12</td>
          <td>Dreams And Nightmares</td>
          <td>16</td>
          <td>Martin Beck</td>
          <td>Special</td>
          <td>1996</td>
        </tr>
        <tr>
          <th>16336</th>
          <td>21144</td>
          <td>96</td>
          <td>24</td>
          <td>2006-12-24</td>
          <td>1681661</td>
          <td>94</td>
          <td>12</td>
          <td>Dr. Seuss' How The Grinch Stole Christmas!</td>
          <td>12</td>
          <td>Hilton Theatre</td>
          <td>Musical</td>
          <td>2006</td>
        </tr>
        <tr>
          <th>16304</th>
          <td>21133</td>
          <td>96</td>
          <td>17</td>
          <td>2006-12-17</td>
          <td>1699470</td>
          <td>100</td>
          <td>12</td>
          <td>Dr. Seuss' How The Grinch Stole Christmas!</td>
          <td>12</td>
          <td>Hilton Theatre</td>
          <td>Musical</td>
          <td>2006</td>
        </tr>
        <tr>
          <th>16272</th>
          <td>20954</td>
          <td>95</td>
          <td>10</td>
          <td>2006-12-10</td>
          <td>1567295</td>
          <td>91</td>
          <td>12</td>
          <td>Dr. Seuss' How The Grinch Stole Christmas!</td>
          <td>12</td>
          <td>Hilton Theatre</td>
          <td>Musical</td>
          <td>2006</td>
        </tr>
        <tr>
          <th>17817</th>
          <td>20425</td>
          <td>80</td>
          <td>16</td>
          <td>2007-12-16</td>
          <td>1572719</td>
          <td>72</td>
          <td>12</td>
          <td>Dr. Seuss' How The Grinch Stole Christmas! 07</td>
          <td>15</td>
          <td>St. James</td>
          <td>Musical</td>
          <td>2007</td>
        </tr>
        <tr>
          <th>1601</th>
          <td>20391</td>
          <td>95</td>
          <td>1</td>
          <td>1996-12-01</td>
          <td>1250775</td>
          <td>0</td>
          <td>12</td>
          <td>Dreams And Nightmares</td>
          <td>0</td>
          <td>Martin Beck</td>
          <td>Special</td>
          <td>1996</td>
        </tr>
        <tr>
          <th>1684</th>
          <td>20177</td>
          <td>100</td>
          <td>22</td>
          <td>1996-12-22</td>
          <td>1230342</td>
          <td>0</td>
          <td>12</td>
          <td>Dreams And Nightmares</td>
          <td>15</td>
          <td>Martin Beck</td>
          <td>Special</td>
          <td>1996</td>
        </tr>
        <tr>
          <th>1657</th>
          <td>20034</td>
          <td>99</td>
          <td>15</td>
          <td>1996-12-15</td>
          <td>1213791</td>
          <td>0</td>
          <td>12</td>
          <td>Dreams And Nightmares</td>
          <td>15</td>
          <td>Martin Beck</td>
          <td>Special</td>
          <td>1996</td>
        </tr>
        <tr>
          <th>16366</th>
          <td>20019</td>
          <td>91</td>
          <td>31</td>
          <td>2006-12-31</td>
          <td>1708885</td>
          <td>90</td>
          <td>12</td>
          <td>Dr. Seuss' How The Grinch Stole Christmas!</td>
          <td>12</td>
          <td>Hilton Theatre</td>
          <td>Musical</td>
          <td>2006</td>
        </tr>
        <tr>
          <th>17851</th>
          <td>19982</td>
          <td>78</td>
          <td>23</td>
          <td>2007-12-23</td>
          <td>1645221</td>
          <td>75</td>
          <td>12</td>
          <td>Dr. Seuss' How The Grinch Stole Christmas! 07</td>
          <td>15</td>
          <td>St. James</td>
          <td>Musical</td>
          <td>2007</td>
        </tr>
        <tr>
          <th>17782</th>
          <td>19911</td>
          <td>83</td>
          <td>9</td>
          <td>2007-12-09</td>
          <td>1376658</td>
          <td>72</td>
          <td>12</td>
          <td>Dr. Seuss' How The Grinch Stole Christmas! 07</td>
          <td>14</td>
          <td>St. James</td>
          <td>Musical</td>
          <td>2007</td>
        </tr>
        <tr>
          <th>16240</th>
          <td>19430</td>
          <td>89</td>
          <td>3</td>
          <td>2006-12-03</td>
          <td>1411528</td>
          <td>81</td>
          <td>12</td>
          <td>Dr. Seuss' How The Grinch Stole Christmas!</td>
          <td>12</td>
          <td>Hilton Theatre</td>
          <td>Musical</td>
          <td>2006</td>
        </tr>
        <tr>
          <th>16207</th>
          <td>19204</td>
          <td>87</td>
          <td>26</td>
          <td>2006-11-26</td>
          <td>1578149</td>
          <td>85</td>
          <td>11</td>
          <td>Dr. Seuss' How The Grinch Stole Christmas!</td>
          <td>12</td>
          <td>Hilton Theatre</td>
          <td>Musical</td>
          <td>2006</td>
        </tr>
        <tr>
          <th>28654</th>
          <td>18683</td>
          <td>97</td>
          <td>4</td>
          <td>2015-01-04</td>
          <td>2217405</td>
          <td>91</td>
          <td>1</td>
          <td>The Illusionists - Witness The Impossible</td>
          <td>12</td>
          <td>Marquis</td>
          <td>Special</td>
          <td>2015</td>
        </tr>
        <tr>
          <th>1629</th>
          <td>17984</td>
          <td>95</td>
          <td>8</td>
          <td>1996-12-08</td>
          <td>1023030</td>
          <td>0</td>
          <td>12</td>
          <td>Dreams And Nightmares</td>
          <td>9</td>
          <td>Martin Beck</td>
          <td>Special</td>
          <td>1996</td>
        </tr>
        <tr>
          <th>17748</th>
          <td>17802</td>
          <td>80</td>
          <td>2</td>
          <td>2007-12-02</td>
          <td>1218880</td>
          <td>69</td>
          <td>12</td>
          <td>Dr. Seuss' How The Grinch Stole Christmas! 07</td>
          <td>13</td>
          <td>St. James</td>
          <td>Musical</td>
          <td>2007</td>
        </tr>
        <tr>
          <th>24057</th>
          <td>17375</td>
          <td>100</td>
          <td>1</td>
          <td>2012-01-01</td>
          <td>2941794</td>
          <td>133</td>
          <td>1</td>
          <td>Spider-Man Turn Off The Dark</td>
          <td>9</td>
          <td>Foxwoods</td>
          <td>Musical</td>
          <td>2012</td>
        </tr>
        <tr>
          <th>26997</th>
          <td>17352</td>
          <td>100</td>
          <td>29</td>
          <td>2013-12-29</td>
          <td>3201333</td>
          <td>121</td>
          <td>12</td>
          <td>Wicked</td>
          <td>9</td>
          <td>Gershwin</td>
          <td>Musical</td>
          <td>2013</td>
        </tr>
        <tr>
          <th>27473</th>
          <td>17352</td>
          <td>100</td>
          <td>20</td>
          <td>2014-04-20</td>
          <td>2769554</td>
          <td>146</td>
          <td>4</td>
          <td>Wicked</td>
          <td>9</td>
          <td>Gershwin</td>
          <td>Musical</td>
          <td>2014</td>
        </tr>
        <tr>
          <th>17885</th>
          <td>17310</td>
          <td>68</td>
          <td>30</td>
          <td>2007-12-30</td>
          <td>1465680</td>
          <td>63</td>
          <td>12</td>
          <td>Dr. Seuss' How The Grinch Stole Christmas! 07</td>
          <td>15</td>
          <td>St. James</td>
          <td>Musical</td>
          <td>2007</td>
        </tr>
      </tbody>
    </table>
    </div>



We used the ``sort_values()`` method to sort our dataframe on the column
titled ‘Attendance’, and we specified that we wanted the largest values
at the top by using the ``ascending=False`` argument. Finally, we only
returned the top 20 rows of the sorted dataframe using ``head()`` with
the argument 20.

According to Wikipedia the Martin Beck Theater (renamed in 2003 as the
Al Hirschfeld Theatre) has a capacity of 1421. In December of 1996 our
data indicates that 16 performances of “Dreams and Nightmares” were
performed. 1421 \* 16 = 22,736 which is just a bit above the reported
Attendance. So all 16 showings were close to sold out. Our attendance
number is unusually large, but it is also plausible and does not appear
to be a data entry error.

It’s notable here that while ‘Dreams and Nightmares’ was the highest
attended event, it was not the highest grossing. Let’s sort the
dataframe again and see what the highest grossing events are.

.. code:: python

    df.sort_values(by='Gross', ascending=False).head(20)




.. raw:: html

    <div>
    <style scoped>
        .dataframe tbody tr th:only-of-type {
            vertical-align: middle;
        }
    
        .dataframe tbody tr th {
            vertical-align: top;
        }
    
        .dataframe thead th {
            text-align: right;
        }
    </style>
    <table border="1" class="dataframe">
      <thead>
        <tr style="text-align: right;">
          <th></th>
          <th>Attendance</th>
          <th>Capacity</th>
          <th>Day</th>
          <th>Full</th>
          <th>Gross</th>
          <th>Gross Potential</th>
          <th>Month</th>
          <th>Name</th>
          <th>Performances</th>
          <th>Theatre</th>
          <th>Type</th>
          <th>Year</th>
        </tr>
      </thead>
      <tbody>
        <tr>
          <th>26997</th>
          <td>17352</td>
          <td>100</td>
          <td>29</td>
          <td>2013-12-29</td>
          <td>3201333</td>
          <td>121</td>
          <td>12</td>
          <td>Wicked</td>
          <td>9</td>
          <td>Gershwin</td>
          <td>Musical</td>
          <td>2013</td>
        </tr>
        <tr>
          <th>25603</th>
          <td>16281</td>
          <td>100</td>
          <td>30</td>
          <td>2012-12-30</td>
          <td>2947172</td>
          <td>156</td>
          <td>12</td>
          <td>Wicked</td>
          <td>9</td>
          <td>Gershwin</td>
          <td>Musical</td>
          <td>2012</td>
        </tr>
        <tr>
          <th>24057</th>
          <td>17375</td>
          <td>100</td>
          <td>1</td>
          <td>2012-01-01</td>
          <td>2941794</td>
          <td>133</td>
          <td>1</td>
          <td>Spider-Man Turn Off The Dark</td>
          <td>9</td>
          <td>Foxwoods</td>
          <td>Musical</td>
          <td>2012</td>
        </tr>
        <tr>
          <th>30261</th>
          <td>17119</td>
          <td>99</td>
          <td>3</td>
          <td>2016-01-03</td>
          <td>2940096</td>
          <td>147</td>
          <td>1</td>
          <td>Wicked</td>
          <td>9</td>
          <td>Gershwin</td>
          <td>Musical</td>
          <td>2016</td>
        </tr>
        <tr>
          <th>28626</th>
          <td>16257</td>
          <td>100</td>
          <td>28</td>
          <td>2014-12-28</td>
          <td>2903309</td>
          <td>154</td>
          <td>12</td>
          <td>Wicked</td>
          <td>9</td>
          <td>Gershwin</td>
          <td>Musical</td>
          <td>2014</td>
        </tr>
        <tr>
          <th>28621</th>
          <td>15306</td>
          <td>100</td>
          <td>28</td>
          <td>2014-12-28</td>
          <td>2885371</td>
          <td>107</td>
          <td>12</td>
          <td>The Lion King</td>
          <td>9</td>
          <td>Minskoff</td>
          <td>Musical</td>
          <td>2014</td>
        </tr>
        <tr>
          <th>30258</th>
          <td>15198</td>
          <td>100</td>
          <td>3</td>
          <td>2016-01-03</td>
          <td>2878505</td>
          <td>106</td>
          <td>1</td>
          <td>The Lion King</td>
          <td>9</td>
          <td>Minskoff</td>
          <td>Musical</td>
          <td>2016</td>
        </tr>
        <tr>
          <th>26994</th>
          <td>15307</td>
          <td>100</td>
          <td>29</td>
          <td>2013-12-29</td>
          <td>2837158</td>
          <td>108</td>
          <td>12</td>
          <td>The Lion King</td>
          <td>9</td>
          <td>Minskoff</td>
          <td>Musical</td>
          <td>2013</td>
        </tr>
        <tr>
          <th>27473</th>
          <td>17352</td>
          <td>100</td>
          <td>20</td>
          <td>2014-04-20</td>
          <td>2769554</td>
          <td>146</td>
          <td>4</td>
          <td>Wicked</td>
          <td>9</td>
          <td>Gershwin</td>
          <td>Musical</td>
          <td>2014</td>
        </tr>
        <tr>
          <th>28662</th>
          <td>15403</td>
          <td>100</td>
          <td>4</td>
          <td>2015-01-04</td>
          <td>2740642</td>
          <td>163</td>
          <td>1</td>
          <td>Wicked</td>
          <td>8</td>
          <td>Gershwin</td>
          <td>Musical</td>
          <td>2015</td>
        </tr>
        <tr>
          <th>25594</th>
          <td>16946</td>
          <td>98</td>
          <td>30</td>
          <td>2012-12-30</td>
          <td>2716990</td>
          <td>123</td>
          <td>12</td>
          <td>Spider-Man Turn Off The Dark</td>
          <td>9</td>
          <td>Foxwoods</td>
          <td>Musical</td>
          <td>2012</td>
        </tr>
        <tr>
          <th>24066</th>
          <td>16281</td>
          <td>100</td>
          <td>1</td>
          <td>2012-01-01</td>
          <td>2712535</td>
          <td>143</td>
          <td>1</td>
          <td>Wicked</td>
          <td>9</td>
          <td>Gershwin</td>
          <td>Musical</td>
          <td>2012</td>
        </tr>
        <tr>
          <th>25597</th>
          <td>15097</td>
          <td>100</td>
          <td>30</td>
          <td>2012-12-30</td>
          <td>2666616</td>
          <td>113</td>
          <td>12</td>
          <td>The Lion King</td>
          <td>9</td>
          <td>Minskoff</td>
          <td>Musical</td>
          <td>2012</td>
        </tr>
        <tr>
          <th>25918</th>
          <td>16281</td>
          <td>100</td>
          <td>31</td>
          <td>2013-03-31</td>
          <td>2633547</td>
          <td>139</td>
          <td>3</td>
          <td>Wicked</td>
          <td>9</td>
          <td>Gershwin</td>
          <td>Musical</td>
          <td>2013</td>
        </tr>
        <tr>
          <th>29036</th>
          <td>15295</td>
          <td>100</td>
          <td>5</td>
          <td>2015-04-05</td>
          <td>2633531</td>
          <td>101</td>
          <td>4</td>
          <td>The Lion King</td>
          <td>9</td>
          <td>Minskoff</td>
          <td>Musical</td>
          <td>2015</td>
        </tr>
        <tr>
          <th>30631</th>
          <td>15236</td>
          <td>100</td>
          <td>27</td>
          <td>2016-03-27</td>
          <td>2629844</td>
          <td>99</td>
          <td>3</td>
          <td>The Lion King</td>
          <td>9</td>
          <td>Minskoff</td>
          <td>Musical</td>
          <td>2016</td>
        </tr>
        <tr>
          <th>26876</th>
          <td>16678</td>
          <td>98</td>
          <td>1</td>
          <td>2013-12-01</td>
          <td>2625327</td>
          <td>139</td>
          <td>12</td>
          <td>Wicked</td>
          <td>9</td>
          <td>Gershwin</td>
          <td>Musical</td>
          <td>2013</td>
        </tr>
        <tr>
          <th>29574</th>
          <td>15137</td>
          <td>99</td>
          <td>2</td>
          <td>2015-08-02</td>
          <td>2624288</td>
          <td>98</td>
          <td>8</td>
          <td>The Lion King</td>
          <td>9</td>
          <td>Minskoff</td>
          <td>Musical</td>
          <td>2015</td>
        </tr>
        <tr>
          <th>29518</th>
          <td>15100</td>
          <td>99</td>
          <td>19</td>
          <td>2015-07-19</td>
          <td>2620016</td>
          <td>100</td>
          <td>7</td>
          <td>The Lion King</td>
          <td>9</td>
          <td>Minskoff</td>
          <td>Musical</td>
          <td>2015</td>
        </tr>
        <tr>
          <th>30221</th>
          <td>13570</td>
          <td>100</td>
          <td>27</td>
          <td>2015-12-27</td>
          <td>2588075</td>
          <td>107</td>
          <td>12</td>
          <td>The Lion King</td>
          <td>8</td>
          <td>Minskoff</td>
          <td>Musical</td>
          <td>2015</td>
        </tr>
      </tbody>
    </table>
    </div>



Now that’s a much different list.

So let’s do a bit more investigating to compare the highest grossing and
the highest attendance performance in our dataset. Let’s take a quick
look at both using some of the new methods we’ve been working with.

.. code:: python

    df.sort_values(by='Attendance', ascending=False).head(20).describe().transpose()




.. raw:: html

    <div>
    <style scoped>
        .dataframe tbody tr th:only-of-type {
            vertical-align: middle;
        }
    
        .dataframe tbody tr th {
            vertical-align: top;
        }
    
        .dataframe thead th {
            text-align: right;
        }
    </style>
    <table border="1" class="dataframe">
      <thead>
        <tr style="text-align: right;">
          <th></th>
          <th>count</th>
          <th>mean</th>
          <th>std</th>
          <th>min</th>
          <th>25%</th>
          <th>50%</th>
          <th>75%</th>
          <th>max</th>
        </tr>
      </thead>
      <tbody>
        <tr>
          <th>Attendance</th>
          <td>20.0</td>
          <td>19414.65</td>
          <td>1440.460536</td>
          <td>17310.0</td>
          <td>17938.50</td>
          <td>19946.5</td>
          <td>20399.50</td>
          <td>21631.0</td>
        </tr>
        <tr>
          <th>Capacity</th>
          <td>20.0</td>
          <td>91.45</td>
          <td>9.242209</td>
          <td>68.0</td>
          <td>86.00</td>
          <td>95.0</td>
          <td>99.25</td>
          <td>100.0</td>
        </tr>
        <tr>
          <th>Day</th>
          <td>20.0</td>
          <td>16.00</td>
          <td>10.597914</td>
          <td>1.0</td>
          <td>7.00</td>
          <td>16.5</td>
          <td>24.50</td>
          <td>31.0</td>
        </tr>
        <tr>
          <th>Gross</th>
          <td>20.0</td>
          <td>1704496.15</td>
          <td>606900.713582</td>
          <td>1023030.0</td>
          <td>1299508.50</td>
          <td>1570007.0</td>
          <td>1701823.75</td>
          <td>3201333.0</td>
        </tr>
        <tr>
          <th>Gross Potential</th>
          <td>20.0</td>
          <td>69.15</td>
          <td>45.893785</td>
          <td>0.0</td>
          <td>47.25</td>
          <td>78.0</td>
          <td>91.75</td>
          <td>146.0</td>
        </tr>
        <tr>
          <th>Month</th>
          <td>20.0</td>
          <td>10.45</td>
          <td>3.691740</td>
          <td>1.0</td>
          <td>12.00</td>
          <td>12.0</td>
          <td>12.00</td>
          <td>12.0</td>
        </tr>
        <tr>
          <th>Performances</th>
          <td>20.0</td>
          <td>11.90</td>
          <td>3.596782</td>
          <td>0.0</td>
          <td>11.25</td>
          <td>12.0</td>
          <td>15.00</td>
          <td>16.0</td>
        </tr>
        <tr>
          <th>Year</th>
          <td>20.0</td>
          <td>2005.25</td>
          <td>6.171880</td>
          <td>1996.0</td>
          <td>2003.50</td>
          <td>2006.0</td>
          <td>2007.00</td>
          <td>2015.0</td>
        </tr>
      </tbody>
    </table>
    </div>



.. code:: python

    df.sort_values(by='Gross', ascending=False).head(20).describe().transpose()




.. raw:: html

    <div>
    <style scoped>
        .dataframe tbody tr th:only-of-type {
            vertical-align: middle;
        }
    
        .dataframe tbody tr th {
            vertical-align: top;
        }
    
        .dataframe thead th {
            text-align: right;
        }
    </style>
    <table border="1" class="dataframe">
      <thead>
        <tr style="text-align: right;">
          <th></th>
          <th>count</th>
          <th>mean</th>
          <th>std</th>
          <th>min</th>
          <th>25%</th>
          <th>50%</th>
          <th>75%</th>
          <th>max</th>
        </tr>
      </thead>
      <tbody>
        <tr>
          <th>Attendance</th>
          <td>20.0</td>
          <td>15928.55</td>
          <td>1017.512988</td>
          <td>13570.0</td>
          <td>15226.50</td>
          <td>15830.0</td>
          <td>16745.00</td>
          <td>17375.0</td>
        </tr>
        <tr>
          <th>Capacity</th>
          <td>20.0</td>
          <td>99.65</td>
          <td>0.670820</td>
          <td>98.0</td>
          <td>99.75</td>
          <td>100.0</td>
          <td>100.00</td>
          <td>100.0</td>
        </tr>
        <tr>
          <th>Day</th>
          <td>20.0</td>
          <td>17.40</td>
          <td>12.857109</td>
          <td>1.0</td>
          <td>3.00</td>
          <td>23.5</td>
          <td>29.00</td>
          <td>31.0</td>
        </tr>
        <tr>
          <th>Gross</th>
          <td>20.0</td>
          <td>2774785.15</td>
          <td>161423.755857</td>
          <td>2588075.0</td>
          <td>2632609.25</td>
          <td>2728816.0</td>
          <td>2889855.50</td>
          <td>3201333.0</td>
        </tr>
        <tr>
          <th>Gross Potential</th>
          <td>20.0</td>
          <td>125.15</td>
          <td>21.786705</td>
          <td>98.0</td>
          <td>106.75</td>
          <td>122.0</td>
          <td>143.75</td>
          <td>163.0</td>
        </tr>
        <tr>
          <th>Month</th>
          <td>20.0</td>
          <td>7.10</td>
          <td>4.897905</td>
          <td>1.0</td>
          <td>2.50</td>
          <td>7.5</td>
          <td>12.00</td>
          <td>12.0</td>
        </tr>
        <tr>
          <th>Performances</th>
          <td>20.0</td>
          <td>8.90</td>
          <td>0.307794</td>
          <td>8.0</td>
          <td>9.00</td>
          <td>9.0</td>
          <td>9.00</td>
          <td>9.0</td>
        </tr>
        <tr>
          <th>Year</th>
          <td>20.0</td>
          <td>2013.85</td>
          <td>1.460894</td>
          <td>2012.0</td>
          <td>2012.75</td>
          <td>2014.0</td>
          <td>2015.00</td>
          <td>2016.0</td>
        </tr>
      </tbody>
    </table>
    </div>



What we have done above is the following: \* sort the dataframe by our
variable of interest (Attendance or Gross) using ``sort_values()`` \*
return the first 20 entries of that sorted dataframe using ``head()`` \*
return summary statistics on just those first 20 entries using
``describe()`` \* flip the final dataframe so its a bit more reader
friendly using ``transpose()``

There is a million dollar difference in the average weekly gross between
the highest grossing and the highest attendance performances! Another
interesting bit of information is the average year. The average year for
the highest attendance was 2005.25 while the average year for the
highest grossing was 2013.85

Let’s take a closer look at trends in the mean by year for Gross and
Attendance. We can do this by using the ``groupby()`` method and the
``mean()`` method.

.. code:: python

    df.groupby(by='Year').mean()




.. raw:: html

    <div>
    <style scoped>
        .dataframe tbody tr th:only-of-type {
            vertical-align: middle;
        }
    
        .dataframe tbody tr th {
            vertical-align: top;
        }
    
        .dataframe thead th {
            text-align: right;
        }
    </style>
    <table border="1" class="dataframe">
      <thead>
        <tr style="text-align: right;">
          <th></th>
          <th>Attendance</th>
          <th>Capacity</th>
          <th>Day</th>
          <th>Gross</th>
          <th>Gross Potential</th>
          <th>Month</th>
          <th>Performances</th>
        </tr>
        <tr>
          <th>Year</th>
          <th></th>
          <th></th>
          <th></th>
          <th></th>
          <th></th>
          <th></th>
          <th></th>
        </tr>
      </thead>
      <tbody>
        <tr>
          <th>1990</th>
          <td>5500.000000</td>
          <td>88.000000</td>
          <td>26.000000</td>
          <td>134456.000000</td>
          <td>0.000000</td>
          <td>8.000000</td>
          <td>8.000000</td>
        </tr>
        <tr>
          <th>1991</th>
          <td>13638.512195</td>
          <td>100.560976</td>
          <td>16.219512</td>
          <td>747943.243902</td>
          <td>0.000000</td>
          <td>7.829268</td>
          <td>7.317073</td>
        </tr>
        <tr>
          <th>1992</th>
          <td>11737.109589</td>
          <td>92.698630</td>
          <td>15.780822</td>
          <td>578939.479452</td>
          <td>21.219178</td>
          <td>6.219178</td>
          <td>7.575342</td>
        </tr>
        <tr>
          <th>1993</th>
          <td>10934.178947</td>
          <td>94.326316</td>
          <td>16.073684</td>
          <td>486015.726316</td>
          <td>39.168421</td>
          <td>6.936842</td>
          <td>7.789474</td>
        </tr>
        <tr>
          <th>1994</th>
          <td>10625.095808</td>
          <td>84.502994</td>
          <td>15.724551</td>
          <td>500111.742515</td>
          <td>12.700599</td>
          <td>6.988024</td>
          <td>7.251497</td>
        </tr>
        <tr>
          <th>1995</th>
          <td>9689.257908</td>
          <td>85.489051</td>
          <td>15.479319</td>
          <td>481401.532847</td>
          <td>19.257908</td>
          <td>7.058394</td>
          <td>7.194647</td>
        </tr>
        <tr>
          <th>1996</th>
          <td>7898.931071</td>
          <td>81.667020</td>
          <td>15.674443</td>
          <td>373025.033934</td>
          <td>2.153765</td>
          <td>8.036055</td>
          <td>7.152704</td>
        </tr>
        <tr>
          <th>1997</th>
          <td>7878.449254</td>
          <td>80.773881</td>
          <td>16.003731</td>
          <td>377683.038806</td>
          <td>40.375373</td>
          <td>6.666418</td>
          <td>7.237313</td>
        </tr>
        <tr>
          <th>1998</th>
          <td>8062.668286</td>
          <td>79.968078</td>
          <td>15.499653</td>
          <td>399857.448994</td>
          <td>71.199861</td>
          <td>6.308119</td>
          <td>7.353227</td>
        </tr>
        <tr>
          <th>1999</th>
          <td>7848.025921</td>
          <td>78.348568</td>
          <td>16.197135</td>
          <td>401229.260573</td>
          <td>66.657572</td>
          <td>6.362210</td>
          <td>7.315143</td>
        </tr>
        <tr>
          <th>2000</th>
          <td>8039.936352</td>
          <td>79.394357</td>
          <td>15.778871</td>
          <td>445101.553806</td>
          <td>70.209974</td>
          <td>6.459974</td>
          <td>7.356299</td>
        </tr>
        <tr>
          <th>2001</th>
          <td>7785.526676</td>
          <td>78.816689</td>
          <td>15.493160</td>
          <td>440357.337209</td>
          <td>66.723666</td>
          <td>6.502736</td>
          <td>7.338577</td>
        </tr>
        <tr>
          <th>2002</th>
          <td>7566.053785</td>
          <td>77.878486</td>
          <td>15.783533</td>
          <td>468953.177955</td>
          <td>66.929615</td>
          <td>6.717795</td>
          <td>7.124834</td>
        </tr>
        <tr>
          <th>2003</th>
          <td>7610.702610</td>
          <td>77.754808</td>
          <td>15.765110</td>
          <td>497708.013049</td>
          <td>64.740385</td>
          <td>6.494505</td>
          <td>7.156593</td>
        </tr>
        <tr>
          <th>2004</th>
          <td>7792.246217</td>
          <td>78.453232</td>
          <td>15.757221</td>
          <td>515031.667813</td>
          <td>63.968363</td>
          <td>6.482806</td>
          <td>7.175378</td>
        </tr>
        <tr>
          <th>2005</th>
          <td>7899.488786</td>
          <td>78.866755</td>
          <td>15.742084</td>
          <td>544320.408971</td>
          <td>67.978892</td>
          <td>6.412269</td>
          <td>7.140501</td>
        </tr>
        <tr>
          <th>2006</th>
          <td>8216.067604</td>
          <td>82.418340</td>
          <td>15.780455</td>
          <td>625497.648594</td>
          <td>74.082999</td>
          <td>6.554217</td>
          <td>7.271754</td>
        </tr>
        <tr>
          <th>2007</th>
          <td>7972.854043</td>
          <td>80.308350</td>
          <td>15.284681</td>
          <td>609686.721893</td>
          <td>67.101249</td>
          <td>6.462196</td>
          <td>7.237344</td>
        </tr>
        <tr>
          <th>2008</th>
          <td>7778.590194</td>
          <td>77.859564</td>
          <td>15.898305</td>
          <td>596516.990315</td>
          <td>61.905569</td>
          <td>6.427966</td>
          <td>7.368039</td>
        </tr>
        <tr>
          <th>2009</th>
          <td>8117.278666</td>
          <td>81.403753</td>
          <td>15.528839</td>
          <td>673773.197359</td>
          <td>63.909659</td>
          <td>6.617790</td>
          <td>7.211258</td>
        </tr>
        <tr>
          <th>2010</th>
          <td>7810.693996</td>
          <td>78.596514</td>
          <td>16.240155</td>
          <td>668991.883796</td>
          <td>59.315042</td>
          <td>6.675920</td>
          <td>7.258877</td>
        </tr>
        <tr>
          <th>2011</th>
          <td>8182.976383</td>
          <td>81.940621</td>
          <td>15.601215</td>
          <td>729188.823212</td>
          <td>62.152497</td>
          <td>6.491903</td>
          <td>6.966937</td>
        </tr>
        <tr>
          <th>2012</th>
          <td>7940.106302</td>
          <td>80.493953</td>
          <td>15.320815</td>
          <td>760916.858689</td>
          <td>62.989179</td>
          <td>6.401655</td>
          <td>7.210694</td>
        </tr>
        <tr>
          <th>2013</th>
          <td>8304.118364</td>
          <td>85.492109</td>
          <td>15.705165</td>
          <td>855121.362267</td>
          <td>70.538020</td>
          <td>6.760402</td>
          <td>7.058106</td>
        </tr>
        <tr>
          <th>2014</th>
          <td>8052.334969</td>
          <td>85.303681</td>
          <td>15.919018</td>
          <td>834669.209202</td>
          <td>71.236196</td>
          <td>6.671166</td>
          <td>7.205521</td>
        </tr>
        <tr>
          <th>2015</th>
          <td>8125.784596</td>
          <td>84.215404</td>
          <td>15.564809</td>
          <td>847303.490294</td>
          <td>69.589856</td>
          <td>6.633062</td>
          <td>7.167188</td>
        </tr>
        <tr>
          <th>2016</th>
          <td>8052.380019</td>
          <td>82.654528</td>
          <td>15.555556</td>
          <td>812104.390289</td>
          <td>65.419234</td>
          <td>4.224090</td>
          <td>7.357610</td>
        </tr>
      </tbody>
    </table>
    </div>



Looking though the means, we find the average weekly Attendance appears
to have peaked in 1991, while the Gross peaked in 2013.

We can use some line charts to confirm this. To do so we are going to
assign the dataframe we just made to a new variable called ``df_means``
and then use that data for our plots. We are also going to use
``reset_index()`` to make it easier to access the ‘Year’ column (don’t
worry about this for now).

.. code:: python

    df_means = df.groupby(by='Year').mean().reset_index()

.. code:: python

    plt.plot('Year', 'Attendance', data=df_means)
    plt.xlabel('Year')
    plt.ylabel('Average Attendance')
    plt.title('Average Attendance Over Time')
    plt.show()



.. image:: pandas-descriptives_files/pandas-descriptives_32_0.svg


.. code:: python

    plt.plot('Year', 'Gross', data=df_means)
    plt.xlabel('Year')
    plt.ylabel('Average Gross')
    plt.title('Average Gross Over Time')
    plt.show()



.. image:: pandas-descriptives_files/pandas-descriptives_33_0.svg


So what do we make of all of this? Attendance appears to have peaked in
the early 90’s, declined rapidly thereafter, and then remained more or
less remained steady ever since. Average gross revenue on the other hand
peaked in the early 90’s, declined thereafter, and has been steadily
rising until 2013 when it started to plateau.

Let’s consider one more question. Does this pattern we’ve observed hold
for both Musicals and Plays?

.. code:: python

    df_musicals = df.query('Type == "Musical"')
    df_musicals_means = df_musicals.groupby(by='Year').mean().reset_index()
    
    df_plays = df.query('Type == "Play"')  
    df_plays_means = df_plays.groupby(by='Year').mean().reset_index()

What does the above code do? Following a pattern we have used previously
we:

-  created two separate dataframes, one for play and one for musicals,
   by applying the ``query()`` method
-  grouped the data by year by applying the ``groupby()`` method
-  calculated means by applying the ``mean()`` method
-  applied ``reset_index()`` to make the ‘Year’ column easier to work
   with

.. code:: python

    df_musicals = df.query('Type == "Musical"')
    df_musicals_means = df_musicals.groupby(by='Year').mean().reset_index()
    
    df_plays = df.query('Type == "Play"')  
    df_plays_means = df_plays.groupby(by='Year').mean().reset_index()
    
    plt.plot('Year', 'Attendance', data=df_musicals_means)
    plt.plot('Year', 'Attendance', data=df_plays_means)
    plt.xlabel('Year')
    plt.ylabel('Average Attendance')
    plt.title('Musicals and Plays: Average Attendance Over Time')
    plt.legend(["Musicals", "Plays"])
    plt.show()



.. image:: pandas-descriptives_files/pandas-descriptives_37_0.svg


.. code:: python

    plt.plot('Year', 'Gross', data=df_musicals_means)
    plt.plot('Year', 'Gross', data=df_plays_means)
    plt.xlabel('Year')
    plt.ylabel('Average Gross')
    plt.title('Musicals and Plays: Average Gross Over Time')
    plt.legend(["Musicals", "Plays"])
    plt.show()  



.. image:: pandas-descriptives_files/pandas-descriptives_38_0.svg


It appears that while plays have lower attendance and gross revenue than
musicals they have generally followed the same long-term trends. Both
have shown typically shown stable attendance and increasing gross
revenue since the year 2000.
