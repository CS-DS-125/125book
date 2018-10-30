.. index:: pandas, dataframe;manipulating
.. index:: dataframe;.info(), dataframe;.cut(), dataframe;.drop(), dataframe;.copy(), dataframe;.columns, series;.tolist()

.. note::
   This is a static copy of a Jupyter notebook.  You can access a live
   version of it, allowing you to modify and execute the code, in one of two ways:
  
   - `Jhub
     <https://jhub.iwu.edu/hub/user-redirect/git-pull?repo=https%3A%2F%2Fgithub.com%2FCS-DS-125%2F125exercises-f18&branch=master&urlPath=lab/tree/125exercises-f18/ch07/pandas-manipulate.ipynb>`_
     (for students in IWU's CS/DS course)
   - `Binder
     <https://mybinder.org/v2/gh/CS-DS-125/125exercises-f18/master?filepath=ch07%2Fpandas-manipulate.ipynb>`_
     (for anyone else)

Manipulating Data and Dataframes
================================

Hopefully you have some sense of why you might want to use a dataframe
to work with your data (rather than something like a list or an array).
You could do all of the things we’ve done with lists or arrays, but if
you’re working with lots of data the dataframe object makes our work
more efficient. Now we are going to look at some really basic ways of
working with your dataframe.

The specific dataframe methods we will use that we haven’t covered
before are:

-  ``info()``
-  ``cut()``
-  ``drop()``
-  ``copy()``
-  ``columns``
-  ``tolist()``

.. code:: python3

    import pandas as pd

--------------

Getting Detailed Information about our Dataframe
------------------------------------------------

So far we have used ``head()``, ``tail()``, and ``shape()`` to get quick
information about our dataframe. There’s one more method we haven’t
covered that is useful; ``info()`` is a method that provides detailed
information about each data column and its type.

Here we read in a dataset of fictional course grades, assign it to the
variable ``df``, and then examine it with ``info()``.

.. code:: python3

    df = pd.read_csv("grades-all.csv")
    df.info()


.. parsed-literal::

    <class 'pandas.core.frame.DataFrame'>
    RangeIndex: 18 entries, 0 to 17
    Data columns (total 19 columns):
    Year          18 non-null object
    Major         18 non-null object
    Q1            18 non-null float64
    Q2            18 non-null float64
    Q3            18 non-null float64
    Q4            18 non-null float64
    Q5            18 non-null float64
    Q6            18 non-null float64
    Q7            18 non-null float64
    Q8            18 non-null float64
    Q9            18 non-null float64
    Q10           18 non-null float64
    Project1      18 non-null float64
    Project2      18 non-null float64
    Exam1         18 non-null float64
    Exam2         18 non-null float64
    Labs          18 non-null float64
    Attendance    18 non-null float64
    StudentID     18 non-null int64
    dtypes: float64(16), int64(1), object(2)
    memory usage: 2.8+ KB


What is all this telling us? First, the dataframe has 18 entries (or
rows). There are 19 columns of data, two of them are ‘object’ datatypes,
one an integer (‘int64’) and the rest are floats (‘float64’). We haven’t
paid attention to the datatypes of the columns in our datasets so far
because the data was clean. When we start working with real-world data
it will be important to check that the datatypes are what you are
expecting. For example, if a column should be a float or an integer but
its listed as an object, it’s likely that you have strings characters in
your dataset mixed in with your numerics.

--------------

Simple Indexing with Labels
---------------------------

Up to this point we have been using code that looks like this
``df['Year']`` but not thinking too much about it. We’ve described this
as reading columns of data to pass to a method but have not talked any
specifics. It’s time to dig into this a bit.

``'Year'`` in this example might be referred to as a column name or a
column label. What we’ve been doing is selecting data we want to work
with by using the label, this is known as indexing.

So let’s see what happends when we index a datframe without calling any
methods.

.. code:: python3

    df['Q1']




.. parsed-literal::

    0      9.0
    1     11.0
    2     10.0
    3      9.0
    4      9.0
    5      8.0
    6      9.0
    7      8.0
    8     10.0
    9     10.0
    10     9.0
    11    11.0
    12    12.0
    13    11.0
    14    11.0
    15     9.0
    16    10.0
    17     8.0
    Name: Q1, dtype: float64



This is something called a pandas series. The sequential numbers to the
left is the series index. The numbers to the right are the values. One
way to think of a dataframe is as a collection of series objects.
Indexing gives us access to individual series or group of series within
a dataframe.

The ususal methods can be applied to the series object.

.. code:: python3

    df['Q1'].mean()




.. parsed-literal::

    9.666666666666666



.. code:: python3

    df['Q1'].sum()




.. parsed-literal::

    174.0



We can also use variables as labels for indexing.

.. code:: python3

    quiz = 'Q1'
    df[quiz].sum()




.. parsed-literal::

    174.0



If we specify a label that doesn’t currently exist we create new columns
in our data frame.

.. code:: python3

    df['New Column!'] = 0
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
          <th>Year</th>
          <th>Major</th>
          <th>Q1</th>
          <th>Q2</th>
          <th>Q3</th>
          <th>Q4</th>
          <th>Q5</th>
          <th>Q6</th>
          <th>Q7</th>
          <th>Q8</th>
          <th>Q9</th>
          <th>Q10</th>
          <th>Project1</th>
          <th>Project2</th>
          <th>Exam1</th>
          <th>Exam2</th>
          <th>Labs</th>
          <th>Attendance</th>
          <th>StudentID</th>
          <th>New Column!</th>
        </tr>
      </thead>
      <tbody>
        <tr>
          <th>0</th>
          <td>first year</td>
          <td>English-CW</td>
          <td>9.0</td>
          <td>10.0</td>
          <td>12.0</td>
          <td>12.0</td>
          <td>10.0</td>
          <td>0.0</td>
          <td>11.0</td>
          <td>10.0</td>
          <td>11.0</td>
          <td>10.0</td>
          <td>10.85</td>
          <td>96.85</td>
          <td>93.9</td>
          <td>87.8</td>
          <td>48.0</td>
          <td>83.3</td>
          <td>1</td>
          <td>0</td>
        </tr>
        <tr>
          <th>1</th>
          <td>first year</td>
          <td>English-CW</td>
          <td>11.0</td>
          <td>12.0</td>
          <td>10.0</td>
          <td>12.0</td>
          <td>8.0</td>
          <td>11.0</td>
          <td>9.0</td>
          <td>10.5</td>
          <td>11.5</td>
          <td>10.0</td>
          <td>10.85</td>
          <td>98.85</td>
          <td>90.6</td>
          <td>86.1</td>
          <td>48.0</td>
          <td>88.9</td>
          <td>2</td>
          <td>0</td>
        </tr>
        <tr>
          <th>2</th>
          <td>second year</td>
          <td>English-CW</td>
          <td>10.0</td>
          <td>10.0</td>
          <td>11.0</td>
          <td>12.0</td>
          <td>12.0</td>
          <td>12.0</td>
          <td>11.0</td>
          <td>11.5</td>
          <td>11.0</td>
          <td>9.5</td>
          <td>11.25</td>
          <td>101.75</td>
          <td>94.4</td>
          <td>89.4</td>
          <td>48.0</td>
          <td>81.1</td>
          <td>3</td>
          <td>0</td>
        </tr>
        <tr>
          <th>3</th>
          <td>fourth year+</td>
          <td>Non-English</td>
          <td>9.0</td>
          <td>12.0</td>
          <td>12.0</td>
          <td>10.0</td>
          <td>11.0</td>
          <td>12.0</td>
          <td>11.0</td>
          <td>9.0</td>
          <td>12.0</td>
          <td>12.0</td>
          <td>11.38</td>
          <td>103.38</td>
          <td>90.0</td>
          <td>92.2</td>
          <td>48.0</td>
          <td>87.8</td>
          <td>4</td>
          <td>0</td>
        </tr>
        <tr>
          <th>4</th>
          <td>second year</td>
          <td>Non-English</td>
          <td>9.0</td>
          <td>10.0</td>
          <td>12.0</td>
          <td>11.0</td>
          <td>11.0</td>
          <td>8.0</td>
          <td>8.0</td>
          <td>8.5</td>
          <td>0.0</td>
          <td>8.0</td>
          <td>10.69</td>
          <td>88.19</td>
          <td>85.6</td>
          <td>89.4</td>
          <td>48.0</td>
          <td>83.9</td>
          <td>5</td>
          <td>0</td>
        </tr>
      </tbody>
    </table>
    </div>



We can also assign new values to existing columns using labels.

.. code:: python3

    df['New Column!'] = 'data!'
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
          <th>Year</th>
          <th>Major</th>
          <th>Q1</th>
          <th>Q2</th>
          <th>Q3</th>
          <th>Q4</th>
          <th>Q5</th>
          <th>Q6</th>
          <th>Q7</th>
          <th>Q8</th>
          <th>Q9</th>
          <th>Q10</th>
          <th>Project1</th>
          <th>Project2</th>
          <th>Exam1</th>
          <th>Exam2</th>
          <th>Labs</th>
          <th>Attendance</th>
          <th>StudentID</th>
          <th>New Column!</th>
        </tr>
      </thead>
      <tbody>
        <tr>
          <th>0</th>
          <td>first year</td>
          <td>English-CW</td>
          <td>9.0</td>
          <td>10.0</td>
          <td>12.0</td>
          <td>12.0</td>
          <td>10.0</td>
          <td>0.0</td>
          <td>11.0</td>
          <td>10.0</td>
          <td>11.0</td>
          <td>10.0</td>
          <td>10.85</td>
          <td>96.85</td>
          <td>93.9</td>
          <td>87.8</td>
          <td>48.0</td>
          <td>83.3</td>
          <td>1</td>
          <td>data!</td>
        </tr>
        <tr>
          <th>1</th>
          <td>first year</td>
          <td>English-CW</td>
          <td>11.0</td>
          <td>12.0</td>
          <td>10.0</td>
          <td>12.0</td>
          <td>8.0</td>
          <td>11.0</td>
          <td>9.0</td>
          <td>10.5</td>
          <td>11.5</td>
          <td>10.0</td>
          <td>10.85</td>
          <td>98.85</td>
          <td>90.6</td>
          <td>86.1</td>
          <td>48.0</td>
          <td>88.9</td>
          <td>2</td>
          <td>data!</td>
        </tr>
        <tr>
          <th>2</th>
          <td>second year</td>
          <td>English-CW</td>
          <td>10.0</td>
          <td>10.0</td>
          <td>11.0</td>
          <td>12.0</td>
          <td>12.0</td>
          <td>12.0</td>
          <td>11.0</td>
          <td>11.5</td>
          <td>11.0</td>
          <td>9.5</td>
          <td>11.25</td>
          <td>101.75</td>
          <td>94.4</td>
          <td>89.4</td>
          <td>48.0</td>
          <td>81.1</td>
          <td>3</td>
          <td>data!</td>
        </tr>
        <tr>
          <th>3</th>
          <td>fourth year+</td>
          <td>Non-English</td>
          <td>9.0</td>
          <td>12.0</td>
          <td>12.0</td>
          <td>10.0</td>
          <td>11.0</td>
          <td>12.0</td>
          <td>11.0</td>
          <td>9.0</td>
          <td>12.0</td>
          <td>12.0</td>
          <td>11.38</td>
          <td>103.38</td>
          <td>90.0</td>
          <td>92.2</td>
          <td>48.0</td>
          <td>87.8</td>
          <td>4</td>
          <td>data!</td>
        </tr>
        <tr>
          <th>4</th>
          <td>second year</td>
          <td>Non-English</td>
          <td>9.0</td>
          <td>10.0</td>
          <td>12.0</td>
          <td>11.0</td>
          <td>11.0</td>
          <td>8.0</td>
          <td>8.0</td>
          <td>8.5</td>
          <td>0.0</td>
          <td>8.0</td>
          <td>10.69</td>
          <td>88.19</td>
          <td>85.6</td>
          <td>89.4</td>
          <td>48.0</td>
          <td>83.9</td>
          <td>5</td>
          <td>data!</td>
        </tr>
      </tbody>
    </table>
    </div>



We can also use this type of indexing to do operations on columns.

.. code:: python3

    df['Exam_Avg'] = (df['Exam1'] + df['Exam2'])/2
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
          <th>Year</th>
          <th>Major</th>
          <th>Q1</th>
          <th>Q2</th>
          <th>Q3</th>
          <th>Q4</th>
          <th>Q5</th>
          <th>Q6</th>
          <th>Q7</th>
          <th>Q8</th>
          <th>...</th>
          <th>Q10</th>
          <th>Project1</th>
          <th>Project2</th>
          <th>Exam1</th>
          <th>Exam2</th>
          <th>Labs</th>
          <th>Attendance</th>
          <th>StudentID</th>
          <th>New Column!</th>
          <th>Exam_Avg</th>
        </tr>
      </thead>
      <tbody>
        <tr>
          <th>0</th>
          <td>first year</td>
          <td>English-CW</td>
          <td>9.0</td>
          <td>10.0</td>
          <td>12.0</td>
          <td>12.0</td>
          <td>10.0</td>
          <td>0.0</td>
          <td>11.0</td>
          <td>10.0</td>
          <td>...</td>
          <td>10.0</td>
          <td>10.85</td>
          <td>96.85</td>
          <td>93.9</td>
          <td>87.8</td>
          <td>48.0</td>
          <td>83.3</td>
          <td>1</td>
          <td>data!</td>
          <td>90.85</td>
        </tr>
        <tr>
          <th>1</th>
          <td>first year</td>
          <td>English-CW</td>
          <td>11.0</td>
          <td>12.0</td>
          <td>10.0</td>
          <td>12.0</td>
          <td>8.0</td>
          <td>11.0</td>
          <td>9.0</td>
          <td>10.5</td>
          <td>...</td>
          <td>10.0</td>
          <td>10.85</td>
          <td>98.85</td>
          <td>90.6</td>
          <td>86.1</td>
          <td>48.0</td>
          <td>88.9</td>
          <td>2</td>
          <td>data!</td>
          <td>88.35</td>
        </tr>
        <tr>
          <th>2</th>
          <td>second year</td>
          <td>English-CW</td>
          <td>10.0</td>
          <td>10.0</td>
          <td>11.0</td>
          <td>12.0</td>
          <td>12.0</td>
          <td>12.0</td>
          <td>11.0</td>
          <td>11.5</td>
          <td>...</td>
          <td>9.5</td>
          <td>11.25</td>
          <td>101.75</td>
          <td>94.4</td>
          <td>89.4</td>
          <td>48.0</td>
          <td>81.1</td>
          <td>3</td>
          <td>data!</td>
          <td>91.90</td>
        </tr>
        <tr>
          <th>3</th>
          <td>fourth year+</td>
          <td>Non-English</td>
          <td>9.0</td>
          <td>12.0</td>
          <td>12.0</td>
          <td>10.0</td>
          <td>11.0</td>
          <td>12.0</td>
          <td>11.0</td>
          <td>9.0</td>
          <td>...</td>
          <td>12.0</td>
          <td>11.38</td>
          <td>103.38</td>
          <td>90.0</td>
          <td>92.2</td>
          <td>48.0</td>
          <td>87.8</td>
          <td>4</td>
          <td>data!</td>
          <td>91.10</td>
        </tr>
        <tr>
          <th>4</th>
          <td>second year</td>
          <td>Non-English</td>
          <td>9.0</td>
          <td>10.0</td>
          <td>12.0</td>
          <td>11.0</td>
          <td>11.0</td>
          <td>8.0</td>
          <td>8.0</td>
          <td>8.5</td>
          <td>...</td>
          <td>8.0</td>
          <td>10.69</td>
          <td>88.19</td>
          <td>85.6</td>
          <td>89.4</td>
          <td>48.0</td>
          <td>83.9</td>
          <td>5</td>
          <td>data!</td>
          <td>87.50</td>
        </tr>
      </tbody>
    </table>
    <p>5 rows × 21 columns</p>
    </div>



Here’s where things get more interesting. We can pass lists of labels to
index multiple columns.

.. code:: python3

    exam_list = ['Exam1', 'Exam2']
    df[exam_list].mean()




.. parsed-literal::

    Exam1    89.627778
    Exam2    89.344444
    dtype: float64



We can also pass the list directly.

.. code:: python3

    df[['Project1', 'Project2']].mean()




.. parsed-literal::

    Project1    10.873889
    Project2    99.290556
    dtype: float64



It looks like ``'Project 1'`` was entered as raw points out of 12; while
``'Project 2'`` was entered as percentages. We can fix that with some
simple operations.

.. code:: python3

    df['Project1'] = (df['Project1']/12)*100
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
          <th>Year</th>
          <th>Major</th>
          <th>Q1</th>
          <th>Q2</th>
          <th>Q3</th>
          <th>Q4</th>
          <th>Q5</th>
          <th>Q6</th>
          <th>Q7</th>
          <th>Q8</th>
          <th>...</th>
          <th>Q10</th>
          <th>Project1</th>
          <th>Project2</th>
          <th>Exam1</th>
          <th>Exam2</th>
          <th>Labs</th>
          <th>Attendance</th>
          <th>StudentID</th>
          <th>New Column!</th>
          <th>Exam_Avg</th>
        </tr>
      </thead>
      <tbody>
        <tr>
          <th>0</th>
          <td>first year</td>
          <td>English-CW</td>
          <td>9.0</td>
          <td>10.0</td>
          <td>12.0</td>
          <td>12.0</td>
          <td>10.0</td>
          <td>0.0</td>
          <td>11.0</td>
          <td>10.0</td>
          <td>...</td>
          <td>10.0</td>
          <td>90.416667</td>
          <td>96.85</td>
          <td>93.9</td>
          <td>87.8</td>
          <td>48.0</td>
          <td>83.3</td>
          <td>1</td>
          <td>data!</td>
          <td>90.85</td>
        </tr>
        <tr>
          <th>1</th>
          <td>first year</td>
          <td>English-CW</td>
          <td>11.0</td>
          <td>12.0</td>
          <td>10.0</td>
          <td>12.0</td>
          <td>8.0</td>
          <td>11.0</td>
          <td>9.0</td>
          <td>10.5</td>
          <td>...</td>
          <td>10.0</td>
          <td>90.416667</td>
          <td>98.85</td>
          <td>90.6</td>
          <td>86.1</td>
          <td>48.0</td>
          <td>88.9</td>
          <td>2</td>
          <td>data!</td>
          <td>88.35</td>
        </tr>
        <tr>
          <th>2</th>
          <td>second year</td>
          <td>English-CW</td>
          <td>10.0</td>
          <td>10.0</td>
          <td>11.0</td>
          <td>12.0</td>
          <td>12.0</td>
          <td>12.0</td>
          <td>11.0</td>
          <td>11.5</td>
          <td>...</td>
          <td>9.5</td>
          <td>93.750000</td>
          <td>101.75</td>
          <td>94.4</td>
          <td>89.4</td>
          <td>48.0</td>
          <td>81.1</td>
          <td>3</td>
          <td>data!</td>
          <td>91.90</td>
        </tr>
        <tr>
          <th>3</th>
          <td>fourth year+</td>
          <td>Non-English</td>
          <td>9.0</td>
          <td>12.0</td>
          <td>12.0</td>
          <td>10.0</td>
          <td>11.0</td>
          <td>12.0</td>
          <td>11.0</td>
          <td>9.0</td>
          <td>...</td>
          <td>12.0</td>
          <td>94.833333</td>
          <td>103.38</td>
          <td>90.0</td>
          <td>92.2</td>
          <td>48.0</td>
          <td>87.8</td>
          <td>4</td>
          <td>data!</td>
          <td>91.10</td>
        </tr>
        <tr>
          <th>4</th>
          <td>second year</td>
          <td>Non-English</td>
          <td>9.0</td>
          <td>10.0</td>
          <td>12.0</td>
          <td>11.0</td>
          <td>11.0</td>
          <td>8.0</td>
          <td>8.0</td>
          <td>8.5</td>
          <td>...</td>
          <td>8.0</td>
          <td>89.083333</td>
          <td>88.19</td>
          <td>85.6</td>
          <td>89.4</td>
          <td>48.0</td>
          <td>83.9</td>
          <td>5</td>
          <td>data!</td>
          <td>87.50</td>
        </tr>
      </tbody>
    </table>
    <p>5 rows × 21 columns</p>
    </div>



And while we are at it, let’s convert the quiz grades to percentages as
well. It looks like they were also out of 12 points.

.. code:: python3

    quiz_list = ['Q1', 'Q2', 'Q3', 'Q4', 'Q5', 'Q6', 'Q7', 'Q8', 'Q9','Q10']
    df[quiz_list] = (df[quiz_list]/12) * 100
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
          <th>Year</th>
          <th>Major</th>
          <th>Q1</th>
          <th>Q2</th>
          <th>Q3</th>
          <th>Q4</th>
          <th>Q5</th>
          <th>Q6</th>
          <th>Q7</th>
          <th>Q8</th>
          <th>...</th>
          <th>Q10</th>
          <th>Project1</th>
          <th>Project2</th>
          <th>Exam1</th>
          <th>Exam2</th>
          <th>Labs</th>
          <th>Attendance</th>
          <th>StudentID</th>
          <th>New Column!</th>
          <th>Exam_Avg</th>
        </tr>
      </thead>
      <tbody>
        <tr>
          <th>0</th>
          <td>first year</td>
          <td>English-CW</td>
          <td>75.000000</td>
          <td>83.333333</td>
          <td>100.000000</td>
          <td>100.000000</td>
          <td>83.333333</td>
          <td>0.000000</td>
          <td>91.666667</td>
          <td>83.333333</td>
          <td>...</td>
          <td>83.333333</td>
          <td>90.416667</td>
          <td>96.85</td>
          <td>93.9</td>
          <td>87.8</td>
          <td>48.0</td>
          <td>83.3</td>
          <td>1</td>
          <td>data!</td>
          <td>90.85</td>
        </tr>
        <tr>
          <th>1</th>
          <td>first year</td>
          <td>English-CW</td>
          <td>91.666667</td>
          <td>100.000000</td>
          <td>83.333333</td>
          <td>100.000000</td>
          <td>66.666667</td>
          <td>91.666667</td>
          <td>75.000000</td>
          <td>87.500000</td>
          <td>...</td>
          <td>83.333333</td>
          <td>90.416667</td>
          <td>98.85</td>
          <td>90.6</td>
          <td>86.1</td>
          <td>48.0</td>
          <td>88.9</td>
          <td>2</td>
          <td>data!</td>
          <td>88.35</td>
        </tr>
        <tr>
          <th>2</th>
          <td>second year</td>
          <td>English-CW</td>
          <td>83.333333</td>
          <td>83.333333</td>
          <td>91.666667</td>
          <td>100.000000</td>
          <td>100.000000</td>
          <td>100.000000</td>
          <td>91.666667</td>
          <td>95.833333</td>
          <td>...</td>
          <td>79.166667</td>
          <td>93.750000</td>
          <td>101.75</td>
          <td>94.4</td>
          <td>89.4</td>
          <td>48.0</td>
          <td>81.1</td>
          <td>3</td>
          <td>data!</td>
          <td>91.90</td>
        </tr>
        <tr>
          <th>3</th>
          <td>fourth year+</td>
          <td>Non-English</td>
          <td>75.000000</td>
          <td>100.000000</td>
          <td>100.000000</td>
          <td>83.333333</td>
          <td>91.666667</td>
          <td>100.000000</td>
          <td>91.666667</td>
          <td>75.000000</td>
          <td>...</td>
          <td>100.000000</td>
          <td>94.833333</td>
          <td>103.38</td>
          <td>90.0</td>
          <td>92.2</td>
          <td>48.0</td>
          <td>87.8</td>
          <td>4</td>
          <td>data!</td>
          <td>91.10</td>
        </tr>
        <tr>
          <th>4</th>
          <td>second year</td>
          <td>Non-English</td>
          <td>75.000000</td>
          <td>83.333333</td>
          <td>100.000000</td>
          <td>91.666667</td>
          <td>91.666667</td>
          <td>66.666667</td>
          <td>66.666667</td>
          <td>70.833333</td>
          <td>...</td>
          <td>66.666667</td>
          <td>89.083333</td>
          <td>88.19</td>
          <td>85.6</td>
          <td>89.4</td>
          <td>48.0</td>
          <td>83.9</td>
          <td>5</td>
          <td>data!</td>
          <td>87.50</td>
        </tr>
      </tbody>
    </table>
    <p>5 rows × 21 columns</p>
    </div>



Notice how we used the list above to apply the same operation to all of
the data columns in the list. That is a short bit of code that is doing
quite a bit.

Creating New Dataframes with Indexing
-------------------------------------

We can use indexing to create new dataframes. You might notice the
``copy()`` method used below. It is making a new copy of the dataframe,
instead of just showing us part of the existing dataframe (called a
view). We will discuss why you would want to do this in more detail
later.

.. code:: python3

    copy_list = ['StudentID', 'Q1', 'Q2', 'Q3', 'Q4', 'Q5', 'Q6', 'Q7', 'Q8', 'Q9','Q10']
    dfquiz = df[copy_list].copy()
    dfquiz.head()




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
          <th>StudentID</th>
          <th>Q1</th>
          <th>Q2</th>
          <th>Q3</th>
          <th>Q4</th>
          <th>Q5</th>
          <th>Q6</th>
          <th>Q7</th>
          <th>Q8</th>
          <th>Q9</th>
          <th>Q10</th>
        </tr>
      </thead>
      <tbody>
        <tr>
          <th>0</th>
          <td>1</td>
          <td>75.000000</td>
          <td>83.333333</td>
          <td>100.000000</td>
          <td>100.000000</td>
          <td>83.333333</td>
          <td>0.000000</td>
          <td>91.666667</td>
          <td>83.333333</td>
          <td>91.666667</td>
          <td>83.333333</td>
        </tr>
        <tr>
          <th>1</th>
          <td>2</td>
          <td>91.666667</td>
          <td>100.000000</td>
          <td>83.333333</td>
          <td>100.000000</td>
          <td>66.666667</td>
          <td>91.666667</td>
          <td>75.000000</td>
          <td>87.500000</td>
          <td>95.833333</td>
          <td>83.333333</td>
        </tr>
        <tr>
          <th>2</th>
          <td>3</td>
          <td>83.333333</td>
          <td>83.333333</td>
          <td>91.666667</td>
          <td>100.000000</td>
          <td>100.000000</td>
          <td>100.000000</td>
          <td>91.666667</td>
          <td>95.833333</td>
          <td>91.666667</td>
          <td>79.166667</td>
        </tr>
        <tr>
          <th>3</th>
          <td>4</td>
          <td>75.000000</td>
          <td>100.000000</td>
          <td>100.000000</td>
          <td>83.333333</td>
          <td>91.666667</td>
          <td>100.000000</td>
          <td>91.666667</td>
          <td>75.000000</td>
          <td>100.000000</td>
          <td>100.000000</td>
        </tr>
        <tr>
          <th>4</th>
          <td>5</td>
          <td>75.000000</td>
          <td>83.333333</td>
          <td>100.000000</td>
          <td>91.666667</td>
          <td>91.666667</td>
          <td>66.666667</td>
          <td>66.666667</td>
          <td>70.833333</td>
          <td>0.000000</td>
          <td>66.666667</td>
        </tr>
      </tbody>
    </table>
    </div>



We can index using the same list of quizzes, calculate an overall mean
(across the columns using axis=1), and assign that to a new series we
create called ``'Quiz Avg'``.

.. code:: python3

    quiz_list = copy_list[1:]
    dfquiz['Quiz Avg'] = dfquiz[quiz_list].mean(axis=1)
    dfquiz.head()




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
          <th>StudentID</th>
          <th>Q1</th>
          <th>Q2</th>
          <th>Q3</th>
          <th>Q4</th>
          <th>Q5</th>
          <th>Q6</th>
          <th>Q7</th>
          <th>Q8</th>
          <th>Q9</th>
          <th>Q10</th>
          <th>Quiz Avg</th>
        </tr>
      </thead>
      <tbody>
        <tr>
          <th>0</th>
          <td>1</td>
          <td>75.000000</td>
          <td>83.333333</td>
          <td>100.000000</td>
          <td>100.000000</td>
          <td>83.333333</td>
          <td>0.000000</td>
          <td>91.666667</td>
          <td>83.333333</td>
          <td>91.666667</td>
          <td>83.333333</td>
          <td>79.166667</td>
        </tr>
        <tr>
          <th>1</th>
          <td>2</td>
          <td>91.666667</td>
          <td>100.000000</td>
          <td>83.333333</td>
          <td>100.000000</td>
          <td>66.666667</td>
          <td>91.666667</td>
          <td>75.000000</td>
          <td>87.500000</td>
          <td>95.833333</td>
          <td>83.333333</td>
          <td>87.500000</td>
        </tr>
        <tr>
          <th>2</th>
          <td>3</td>
          <td>83.333333</td>
          <td>83.333333</td>
          <td>91.666667</td>
          <td>100.000000</td>
          <td>100.000000</td>
          <td>100.000000</td>
          <td>91.666667</td>
          <td>95.833333</td>
          <td>91.666667</td>
          <td>79.166667</td>
          <td>91.666667</td>
        </tr>
        <tr>
          <th>3</th>
          <td>4</td>
          <td>75.000000</td>
          <td>100.000000</td>
          <td>100.000000</td>
          <td>83.333333</td>
          <td>91.666667</td>
          <td>100.000000</td>
          <td>91.666667</td>
          <td>75.000000</td>
          <td>100.000000</td>
          <td>100.000000</td>
          <td>91.666667</td>
        </tr>
        <tr>
          <th>4</th>
          <td>5</td>
          <td>75.000000</td>
          <td>83.333333</td>
          <td>100.000000</td>
          <td>91.666667</td>
          <td>91.666667</td>
          <td>66.666667</td>
          <td>66.666667</td>
          <td>70.833333</td>
          <td>0.000000</td>
          <td>66.666667</td>
          <td>71.250000</td>
        </tr>
      </tbody>
    </table>
    </div>



Now, just for fun, let’s say we want to assign letter grades based on
the average. There’s a method called ``cut()`` that allows us to specify
the bins we would like (ranges) and then supply labels for those bins.
In this case the labels are letter grades.

.. code:: python3

    dfquiz['Quiz_Avg_Letter'] = pd.cut(dfquiz['Quiz Avg'], bins=[0, 60, 70, 80, 90, 100], labels= ['F', 'D', 'C', 'B', 'A'])
    dfquiz.head()




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
          <th>StudentID</th>
          <th>Q1</th>
          <th>Q2</th>
          <th>Q3</th>
          <th>Q4</th>
          <th>Q5</th>
          <th>Q6</th>
          <th>Q7</th>
          <th>Q8</th>
          <th>Q9</th>
          <th>Q10</th>
          <th>Quiz Avg</th>
          <th>Quiz_Avg_Letter</th>
        </tr>
      </thead>
      <tbody>
        <tr>
          <th>0</th>
          <td>1</td>
          <td>75.000000</td>
          <td>83.333333</td>
          <td>100.000000</td>
          <td>100.000000</td>
          <td>83.333333</td>
          <td>0.000000</td>
          <td>91.666667</td>
          <td>83.333333</td>
          <td>91.666667</td>
          <td>83.333333</td>
          <td>79.166667</td>
          <td>C</td>
        </tr>
        <tr>
          <th>1</th>
          <td>2</td>
          <td>91.666667</td>
          <td>100.000000</td>
          <td>83.333333</td>
          <td>100.000000</td>
          <td>66.666667</td>
          <td>91.666667</td>
          <td>75.000000</td>
          <td>87.500000</td>
          <td>95.833333</td>
          <td>83.333333</td>
          <td>87.500000</td>
          <td>B</td>
        </tr>
        <tr>
          <th>2</th>
          <td>3</td>
          <td>83.333333</td>
          <td>83.333333</td>
          <td>91.666667</td>
          <td>100.000000</td>
          <td>100.000000</td>
          <td>100.000000</td>
          <td>91.666667</td>
          <td>95.833333</td>
          <td>91.666667</td>
          <td>79.166667</td>
          <td>91.666667</td>
          <td>A</td>
        </tr>
        <tr>
          <th>3</th>
          <td>4</td>
          <td>75.000000</td>
          <td>100.000000</td>
          <td>100.000000</td>
          <td>83.333333</td>
          <td>91.666667</td>
          <td>100.000000</td>
          <td>91.666667</td>
          <td>75.000000</td>
          <td>100.000000</td>
          <td>100.000000</td>
          <td>91.666667</td>
          <td>A</td>
        </tr>
        <tr>
          <th>4</th>
          <td>5</td>
          <td>75.000000</td>
          <td>83.333333</td>
          <td>100.000000</td>
          <td>91.666667</td>
          <td>91.666667</td>
          <td>66.666667</td>
          <td>66.666667</td>
          <td>70.833333</td>
          <td>0.000000</td>
          <td>66.666667</td>
          <td>71.250000</td>
          <td>C</td>
        </tr>
      </tbody>
    </table>
    </div>



Reordering Columns
------------------

We can also use labels to reorder columns. Let’s say we weant to move
``'Quiz Avg'`` to the front (left-most) of the dataframe. To accomplish
this we will first use the ``columns`` property, which is an object
containing all of the column labels.

.. code:: python3

    dfquiz.columns




.. parsed-literal::

    Index(['StudentID', 'Q1', 'Q2', 'Q3', 'Q4', 'Q5', 'Q6', 'Q7', 'Q8', 'Q9',
           'Q10', 'Quiz Avg', 'Quiz_Avg_Letter'],
          dtype='object')



Second, we can then apply the ``tolist()`` method to convert the object
returned by columns in to a list. We then assign that list to the
variable ``'column_labels'``.

.. code:: python3

    column_order = dfquiz.columns.tolist()
    column_order




.. parsed-literal::

    ['StudentID',
     'Q1',
     'Q2',
     'Q3',
     'Q4',
     'Q5',
     'Q6',
     'Q7',
     'Q8',
     'Q9',
     'Q10',
     'Quiz Avg',
     'Quiz_Avg_Letter']



We can reorder the items in the list and then use that list to reorder
the dataframe itself. We can reorder the list by changing the list
ourselves. We then use the reordered lists to reorder our dataframe.

.. code:: python3

    column_order1 = ['Quiz Avg', 'Quiz_Avg_Letter','StudentID', 'Q1', 'Q2', 'Q3', 'Q4', 'Q5', 'Q6', 'Q7', 'Q8', 'Q9', 'Q10']
    dfquiz_reordered1 = dfquiz[column_order1].copy()
    dfquiz_reordered1.head()




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
          <th>Quiz Avg</th>
          <th>Quiz_Avg_Letter</th>
          <th>StudentID</th>
          <th>Q1</th>
          <th>Q2</th>
          <th>Q3</th>
          <th>Q4</th>
          <th>Q5</th>
          <th>Q6</th>
          <th>Q7</th>
          <th>Q8</th>
          <th>Q9</th>
          <th>Q10</th>
        </tr>
      </thead>
      <tbody>
        <tr>
          <th>0</th>
          <td>79.166667</td>
          <td>C</td>
          <td>1</td>
          <td>75.000000</td>
          <td>83.333333</td>
          <td>100.000000</td>
          <td>100.000000</td>
          <td>83.333333</td>
          <td>0.000000</td>
          <td>91.666667</td>
          <td>83.333333</td>
          <td>91.666667</td>
          <td>83.333333</td>
        </tr>
        <tr>
          <th>1</th>
          <td>87.500000</td>
          <td>B</td>
          <td>2</td>
          <td>91.666667</td>
          <td>100.000000</td>
          <td>83.333333</td>
          <td>100.000000</td>
          <td>66.666667</td>
          <td>91.666667</td>
          <td>75.000000</td>
          <td>87.500000</td>
          <td>95.833333</td>
          <td>83.333333</td>
        </tr>
        <tr>
          <th>2</th>
          <td>91.666667</td>
          <td>A</td>
          <td>3</td>
          <td>83.333333</td>
          <td>83.333333</td>
          <td>91.666667</td>
          <td>100.000000</td>
          <td>100.000000</td>
          <td>100.000000</td>
          <td>91.666667</td>
          <td>95.833333</td>
          <td>91.666667</td>
          <td>79.166667</td>
        </tr>
        <tr>
          <th>3</th>
          <td>91.666667</td>
          <td>A</td>
          <td>4</td>
          <td>75.000000</td>
          <td>100.000000</td>
          <td>100.000000</td>
          <td>83.333333</td>
          <td>91.666667</td>
          <td>100.000000</td>
          <td>91.666667</td>
          <td>75.000000</td>
          <td>100.000000</td>
          <td>100.000000</td>
        </tr>
        <tr>
          <th>4</th>
          <td>71.250000</td>
          <td>C</td>
          <td>5</td>
          <td>75.000000</td>
          <td>83.333333</td>
          <td>100.000000</td>
          <td>91.666667</td>
          <td>91.666667</td>
          <td>66.666667</td>
          <td>66.666667</td>
          <td>70.833333</td>
          <td>0.000000</td>
          <td>66.666667</td>
        </tr>
      </tbody>
    </table>
    </div>



Or we can use list methods to slice and recombine the column list to
accomplish the same thing.

.. code:: python3

    column_order2 = column_order[-2:] + column_order[:-2]
    column_order2




.. parsed-literal::

    ['Quiz Avg',
     'Quiz_Avg_Letter',
     'StudentID',
     'Q1',
     'Q2',
     'Q3',
     'Q4',
     'Q5',
     'Q6',
     'Q7',
     'Q8',
     'Q9',
     'Q10']



We then use the reordered list to reorder our dataframe.

.. code:: python3

    dfquiz_reordered2 = dfquiz[column_order2].copy()
    dfquiz_reordered2.head()




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
          <th>Quiz Avg</th>
          <th>Quiz_Avg_Letter</th>
          <th>StudentID</th>
          <th>Q1</th>
          <th>Q2</th>
          <th>Q3</th>
          <th>Q4</th>
          <th>Q5</th>
          <th>Q6</th>
          <th>Q7</th>
          <th>Q8</th>
          <th>Q9</th>
          <th>Q10</th>
        </tr>
      </thead>
      <tbody>
        <tr>
          <th>0</th>
          <td>79.166667</td>
          <td>C</td>
          <td>1</td>
          <td>75.000000</td>
          <td>83.333333</td>
          <td>100.000000</td>
          <td>100.000000</td>
          <td>83.333333</td>
          <td>0.000000</td>
          <td>91.666667</td>
          <td>83.333333</td>
          <td>91.666667</td>
          <td>83.333333</td>
        </tr>
        <tr>
          <th>1</th>
          <td>87.500000</td>
          <td>B</td>
          <td>2</td>
          <td>91.666667</td>
          <td>100.000000</td>
          <td>83.333333</td>
          <td>100.000000</td>
          <td>66.666667</td>
          <td>91.666667</td>
          <td>75.000000</td>
          <td>87.500000</td>
          <td>95.833333</td>
          <td>83.333333</td>
        </tr>
        <tr>
          <th>2</th>
          <td>91.666667</td>
          <td>A</td>
          <td>3</td>
          <td>83.333333</td>
          <td>83.333333</td>
          <td>91.666667</td>
          <td>100.000000</td>
          <td>100.000000</td>
          <td>100.000000</td>
          <td>91.666667</td>
          <td>95.833333</td>
          <td>91.666667</td>
          <td>79.166667</td>
        </tr>
        <tr>
          <th>3</th>
          <td>91.666667</td>
          <td>A</td>
          <td>4</td>
          <td>75.000000</td>
          <td>100.000000</td>
          <td>100.000000</td>
          <td>83.333333</td>
          <td>91.666667</td>
          <td>100.000000</td>
          <td>91.666667</td>
          <td>75.000000</td>
          <td>100.000000</td>
          <td>100.000000</td>
        </tr>
        <tr>
          <th>4</th>
          <td>71.250000</td>
          <td>C</td>
          <td>5</td>
          <td>75.000000</td>
          <td>83.333333</td>
          <td>100.000000</td>
          <td>91.666667</td>
          <td>91.666667</td>
          <td>66.666667</td>
          <td>66.666667</td>
          <td>70.833333</td>
          <td>0.000000</td>
          <td>66.666667</td>
        </tr>
      </tbody>
    </table>
    </div>



Removing Columns
----------------

We can also use labels to remove columns. The ``drop()`` method will
take a label, or list of labels, and drop them from the dataframe.
``drop()`` can be used to remove rows as well so we have to tell is to
specifically look for a column with the label we specified. We tell it
to look for column by specifying ``axis=1`` (we would use ``axis=0`` if
we wanted to drop rows). The ``inplace=True`` argument is something we
will discuss later.

.. code:: python3

    df.drop('New Column!', axis=1, inplace=True)
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
          <th>Year</th>
          <th>Major</th>
          <th>Q1</th>
          <th>Q2</th>
          <th>Q3</th>
          <th>Q4</th>
          <th>Q5</th>
          <th>Q6</th>
          <th>Q7</th>
          <th>Q8</th>
          <th>Q9</th>
          <th>Q10</th>
          <th>Project1</th>
          <th>Project2</th>
          <th>Exam1</th>
          <th>Exam2</th>
          <th>Labs</th>
          <th>Attendance</th>
          <th>StudentID</th>
          <th>Exam_Avg</th>
        </tr>
      </thead>
      <tbody>
        <tr>
          <th>0</th>
          <td>first year</td>
          <td>English-CW</td>
          <td>75.000000</td>
          <td>83.333333</td>
          <td>100.000000</td>
          <td>100.000000</td>
          <td>83.333333</td>
          <td>0.000000</td>
          <td>91.666667</td>
          <td>83.333333</td>
          <td>91.666667</td>
          <td>83.333333</td>
          <td>90.416667</td>
          <td>96.85</td>
          <td>93.9</td>
          <td>87.8</td>
          <td>48.0</td>
          <td>83.3</td>
          <td>1</td>
          <td>90.85</td>
        </tr>
        <tr>
          <th>1</th>
          <td>first year</td>
          <td>English-CW</td>
          <td>91.666667</td>
          <td>100.000000</td>
          <td>83.333333</td>
          <td>100.000000</td>
          <td>66.666667</td>
          <td>91.666667</td>
          <td>75.000000</td>
          <td>87.500000</td>
          <td>95.833333</td>
          <td>83.333333</td>
          <td>90.416667</td>
          <td>98.85</td>
          <td>90.6</td>
          <td>86.1</td>
          <td>48.0</td>
          <td>88.9</td>
          <td>2</td>
          <td>88.35</td>
        </tr>
        <tr>
          <th>2</th>
          <td>second year</td>
          <td>English-CW</td>
          <td>83.333333</td>
          <td>83.333333</td>
          <td>91.666667</td>
          <td>100.000000</td>
          <td>100.000000</td>
          <td>100.000000</td>
          <td>91.666667</td>
          <td>95.833333</td>
          <td>91.666667</td>
          <td>79.166667</td>
          <td>93.750000</td>
          <td>101.75</td>
          <td>94.4</td>
          <td>89.4</td>
          <td>48.0</td>
          <td>81.1</td>
          <td>3</td>
          <td>91.90</td>
        </tr>
        <tr>
          <th>3</th>
          <td>fourth year+</td>
          <td>Non-English</td>
          <td>75.000000</td>
          <td>100.000000</td>
          <td>100.000000</td>
          <td>83.333333</td>
          <td>91.666667</td>
          <td>100.000000</td>
          <td>91.666667</td>
          <td>75.000000</td>
          <td>100.000000</td>
          <td>100.000000</td>
          <td>94.833333</td>
          <td>103.38</td>
          <td>90.0</td>
          <td>92.2</td>
          <td>48.0</td>
          <td>87.8</td>
          <td>4</td>
          <td>91.10</td>
        </tr>
        <tr>
          <th>4</th>
          <td>second year</td>
          <td>Non-English</td>
          <td>75.000000</td>
          <td>83.333333</td>
          <td>100.000000</td>
          <td>91.666667</td>
          <td>91.666667</td>
          <td>66.666667</td>
          <td>66.666667</td>
          <td>70.833333</td>
          <td>0.000000</td>
          <td>66.666667</td>
          <td>89.083333</td>
          <td>88.19</td>
          <td>85.6</td>
          <td>89.4</td>
          <td>48.0</td>
          <td>83.9</td>
          <td>5</td>
          <td>87.50</td>
        </tr>
      </tbody>
    </table>
    </div>


