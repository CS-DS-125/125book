.. index:: pandas, categorical data
.. index:: dataframe;.replace(), dataframe;.value_counts(), dataframe;.crosstab()

.. note::
   This is a static copy of a Jupyter notebook.  You can access a live
   version of it, allowing you to modify and execute the code, in one of two ways:
  
   - `Jhub
     <https://jhub.iwu.edu/hub/user-redirect/git-pull?repo=https%3A%2F%2Fgithub.com%2FCS-DS-125%2F125exercises-f18&branch=master&urlPath=lab/tree/125exercises-f18/ch07/pandas-categorical.ipynb>`_
     (for students in IWU's CS/DS course)
   - `Binder
     <https://mybinder.org/v2/gh/CS-DS-125/125exercises-f18/master?filepath=ch07%2Fpandas-categorical.ipynb>`_
     (for anyone else)

Working with Categorical Data
=============================

In our work on vsiualizazations up to this point we have often been
looking at continuous variables (data that takes on a range of values;
for example, gross revenue), and sometimes we have been looking at
continuous variables as they related to some categorical variable (for
example, gross revenue by performance type).

In this section we are going to look at some methods that will help you
examine your data with a particular eye toward tools that help you
examine categorical variables.

The specific dataframe methods we will use that we haven’t covered
before are:

-  ``replace()``
-  ``value_counts()``
-  ``crosstab()``

.. code:: python3

    import pandas as pd
    import matplotlib.pyplot as plt

.. code:: python3

    # For slightly nicer charts
    plt.rcParams['figure.figsize'] = [10, 6]
    plt.rcParams['figure.dpi'] = 150

--------------

For this section we will use a dataset ``titanic.csv``
(`source <http://web.stanford.edu/class/archive/cs/cs109/cs109.1166/problem12.html>`__),
containing data about the passengers on the `RMS
Titanic <https://en.wikipedia.org/wiki/RMS_Titanic>`__.

First, we read a CSV file of passengers on the Titanic and assign it to
a variable called ``df``. Each row in the dataset represents one
passenger on the titanic. Each row contains information about the
passenger and whether they survived. The columns are labelled as
follows: \* ‘Survived’ \* ‘Pclass’ \* ‘Name’ \* ‘Sex’ \* ‘Age’ \*
‘Siblings/Spouses Aboard’ \* ‘Parents/Children Aboard’ \* ‘Fare’

.. code:: python3

    df = pd.read_csv("titanic.csv")
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
          <th>Survived</th>
          <th>Pclass</th>
          <th>Name</th>
          <th>Sex</th>
          <th>Age</th>
          <th>Siblings/Spouses Aboard</th>
          <th>Parents/Children Aboard</th>
          <th>Fare</th>
        </tr>
      </thead>
      <tbody>
        <tr>
          <th>0</th>
          <td>0</td>
          <td>3</td>
          <td>Mr. Owen Harris Braund</td>
          <td>male</td>
          <td>22.0</td>
          <td>1</td>
          <td>0</td>
          <td>7.2500</td>
        </tr>
        <tr>
          <th>1</th>
          <td>1</td>
          <td>1</td>
          <td>Mrs. John Bradley (Florence Briggs Thayer) Cum...</td>
          <td>female</td>
          <td>38.0</td>
          <td>1</td>
          <td>0</td>
          <td>71.2833</td>
        </tr>
        <tr>
          <th>2</th>
          <td>1</td>
          <td>3</td>
          <td>Miss. Laina Heikkinen</td>
          <td>female</td>
          <td>26.0</td>
          <td>0</td>
          <td>0</td>
          <td>7.9250</td>
        </tr>
        <tr>
          <th>3</th>
          <td>1</td>
          <td>1</td>
          <td>Mrs. Jacques Heath (Lily May Peel) Futrelle</td>
          <td>female</td>
          <td>35.0</td>
          <td>1</td>
          <td>0</td>
          <td>53.1000</td>
        </tr>
        <tr>
          <th>4</th>
          <td>0</td>
          <td>3</td>
          <td>Mr. William Henry Allen</td>
          <td>male</td>
          <td>35.0</td>
          <td>0</td>
          <td>0</td>
          <td>8.0500</td>
        </tr>
      </tbody>
    </table>
    </div>



--------------

Replacing Values
----------------

The 0 and 1 values used to the code the ‘Survived’ column is not easy to
read or understand. The 1, 2, 3 values used to code Passenger Class are
a little better but could also be improved with more descriptive values.
To recode values in a column we can use the ``replace()`` method on a
column.

.. code:: python3

    df['Survived'] = df['Survived'].replace(0, 'Perished')

In the first line of code above we have applied the ``replace()`` method
to the ‘Survived’ column of the dataframe. Specifically,
``df['Survived']`` is accessing the ‘Survived’ column of the dataframe,
and ``.replace()`` is calling a method on that column that takes any
instance of the first argument we supply, in this case ``0``, and
replaces it with the second value, ``'Perished'``.

We can do this again to replace ``1`` with ``'Survived'``.

.. code:: python3

    df['Survived'] = df['Survived'].replace(1, 'Lived')
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
          <th>Survived</th>
          <th>Pclass</th>
          <th>Name</th>
          <th>Sex</th>
          <th>Age</th>
          <th>Siblings/Spouses Aboard</th>
          <th>Parents/Children Aboard</th>
          <th>Fare</th>
        </tr>
      </thead>
      <tbody>
        <tr>
          <th>0</th>
          <td>Perished</td>
          <td>3</td>
          <td>Mr. Owen Harris Braund</td>
          <td>male</td>
          <td>22.0</td>
          <td>1</td>
          <td>0</td>
          <td>7.2500</td>
        </tr>
        <tr>
          <th>1</th>
          <td>Lived</td>
          <td>1</td>
          <td>Mrs. John Bradley (Florence Briggs Thayer) Cum...</td>
          <td>female</td>
          <td>38.0</td>
          <td>1</td>
          <td>0</td>
          <td>71.2833</td>
        </tr>
        <tr>
          <th>2</th>
          <td>Lived</td>
          <td>3</td>
          <td>Miss. Laina Heikkinen</td>
          <td>female</td>
          <td>26.0</td>
          <td>0</td>
          <td>0</td>
          <td>7.9250</td>
        </tr>
        <tr>
          <th>3</th>
          <td>Lived</td>
          <td>1</td>
          <td>Mrs. Jacques Heath (Lily May Peel) Futrelle</td>
          <td>female</td>
          <td>35.0</td>
          <td>1</td>
          <td>0</td>
          <td>53.1000</td>
        </tr>
        <tr>
          <th>4</th>
          <td>Perished</td>
          <td>3</td>
          <td>Mr. William Henry Allen</td>
          <td>male</td>
          <td>35.0</td>
          <td>0</td>
          <td>0</td>
          <td>8.0500</td>
        </tr>
      </tbody>
    </table>
    </div>



We can use the same method to replace the ``1``, ``2``, ``3`` values in
‘Pclass’ with ``'First Class'``, ``'Second Class'``, and
``'Third Class'``.

.. code:: python3

    df['Pclass'] = df['Pclass'].replace([1,2,3], ['First Class', 'Second Class', 'Third Class'])
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
          <th>Survived</th>
          <th>Pclass</th>
          <th>Name</th>
          <th>Sex</th>
          <th>Age</th>
          <th>Siblings/Spouses Aboard</th>
          <th>Parents/Children Aboard</th>
          <th>Fare</th>
        </tr>
      </thead>
      <tbody>
        <tr>
          <th>0</th>
          <td>Perished</td>
          <td>Third Class</td>
          <td>Mr. Owen Harris Braund</td>
          <td>male</td>
          <td>22.0</td>
          <td>1</td>
          <td>0</td>
          <td>7.2500</td>
        </tr>
        <tr>
          <th>1</th>
          <td>Lived</td>
          <td>First Class</td>
          <td>Mrs. John Bradley (Florence Briggs Thayer) Cum...</td>
          <td>female</td>
          <td>38.0</td>
          <td>1</td>
          <td>0</td>
          <td>71.2833</td>
        </tr>
        <tr>
          <th>2</th>
          <td>Lived</td>
          <td>Third Class</td>
          <td>Miss. Laina Heikkinen</td>
          <td>female</td>
          <td>26.0</td>
          <td>0</td>
          <td>0</td>
          <td>7.9250</td>
        </tr>
        <tr>
          <th>3</th>
          <td>Lived</td>
          <td>First Class</td>
          <td>Mrs. Jacques Heath (Lily May Peel) Futrelle</td>
          <td>female</td>
          <td>35.0</td>
          <td>1</td>
          <td>0</td>
          <td>53.1000</td>
        </tr>
        <tr>
          <th>4</th>
          <td>Perished</td>
          <td>Third Class</td>
          <td>Mr. William Henry Allen</td>
          <td>male</td>
          <td>35.0</td>
          <td>0</td>
          <td>0</td>
          <td>8.0500</td>
        </tr>
      </tbody>
    </table>
    </div>



--------------

Value Counts
------------

That looks pretty good. Now the big question: What can this data tell us
about who was likely to survive the titanic? First, let’s find out how
many people lived.

.. code:: python3

    df['Survived'].value_counts()




.. parsed-literal::

    Perished    545
    Lived       342
    Name: Survived, dtype: int64



What we’ve done here is apply the ``value_counts()`` method to the
‘Survived’ column of the dataframe. Specifically, ``df['Survived']`` is
accessing the ‘Survived’ column of the dataframe, and
``.value_counts()`` is calling a method on that column that counts the
number of times each unique value appears in the column.

If we group dataframe rows using ``.groupby()``, then
``.value_counts()`` will apply within each group. For example, here we
group the data by the Passenger Class (‘Pclass’) values, then use
``.value_counts()`` again on the ‘Survived’ column of the grouped data:

.. code:: python3

    df_byPclass = df.groupby(by='Pclass')
    df_byPclass['Survived'].value_counts()




.. parsed-literal::

    Pclass        Survived
    First Class   Lived       136
                  Perished     80
    Second Class  Perished     97
                  Lived        87
    Third Class   Perished    368
                  Lived       119
    Name: Survived, dtype: int64



Notice, however, that by default ``value_counts()`` is sorting the
results by the most frequent outcome. This makes the result above a bit
hard to read since the first class passengers are sorted differently
than the rest (since more survived than perished). We can pass an
argument to ``value_counts()`` to stop it from sorting this way.

.. code:: python3

    df_byPclass['Survived'].value_counts(sort=False)




.. parsed-literal::

    Pclass        Survived
    First Class   Lived       136
                  Perished     80
    Second Class  Lived        87
                  Perished     97
    Third Class   Lived       119
                  Perished    368
    Name: Survived, dtype: int64



We can also use the ``.groupby()`` method to group on multiple columns
by passing it a list of column names.

.. code:: python3

    df_byClassSex = df.groupby(by=['Pclass', 'Sex'])
    df_byClassSex['Survived'].value_counts(sort=False)




.. parsed-literal::

    Pclass        Sex     Survived
    First Class   female  Lived        91
                          Perished      3
                  male    Lived        45
                          Perished     77
    Second Class  female  Lived        70
                          Perished      6
                  male    Lived        17
                          Perished     91
    Third Class   female  Lived        72
                          Perished     72
                  male    Lived        47
                          Perished    296
    Name: Survived, dtype: int64



We can also reverse the order of our grouping to get a slightly
different output.

.. code:: python3

    df_bySexClass = df.groupby(by=['Sex','Pclass'])
    df_bySexClass['Survived'].value_counts(sort=False)




.. parsed-literal::

    Sex     Pclass        Survived
    female  First Class   Lived        91
                          Perished      3
            Second Class  Lived        70
                          Perished      6
            Third Class   Lived        72
                          Perished     72
    male    First Class   Lived        45
                          Perished     77
            Second Class  Lived        17
                          Perished     91
            Third Class   Lived        47
                          Perished    296
    Name: Survived, dtype: int64



--------------

Cross Tabulation
----------------

Up to this point we have used ``value_counts()`` to and ``groupby()`` to
produce basic counts in a table-like format. When we compare survival
for different groups, we are taking one kind of categorical data
(Survived, Perished) and seeing how it relates to another kind of
categorical data (First Class, Second Class, Third Class). This type of
analysis is really common in all kinds of applications. A more formal
tool for looking at data this way is a `‘Contingency Table’ or ‘Cross
Tabulation’. <https://en.wikipedia.org/wiki/Contingency_table>`__

.. code:: python3

    pd.crosstab(df['Pclass'], df['Survived'])




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
          <th>Survived</th>
          <th>Lived</th>
          <th>Perished</th>
        </tr>
        <tr>
          <th>Pclass</th>
          <th></th>
          <th></th>
        </tr>
      </thead>
      <tbody>
        <tr>
          <th>First Class</th>
          <td>136</td>
          <td>80</td>
        </tr>
        <tr>
          <th>Second Class</th>
          <td>87</td>
          <td>97</td>
        </tr>
        <tr>
          <th>Third Class</th>
          <td>119</td>
          <td>368</td>
        </tr>
      </tbody>
    </table>
    </div>



In the code above we have passed two columns from our dataframe into the
Pandas ``crosstab()`` method. **Note** that this is a function in Pandas
itself, not in a particular dataframe, so we are specifying ``pd`` (the
Pandas module we imported above) on the left side of the dot notation,
and we are passing dataframe columns into it as arguments.

The ``crosstab()`` method has some additional features that make it very
useful.

First, we can add the argument ``margins`` that produces row or column
subtotals (margins):

.. code:: python3

    pd.crosstab(df['Pclass'], df['Survived'], margins=True)




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
          <th>Survived</th>
          <th>Lived</th>
          <th>Perished</th>
          <th>All</th>
        </tr>
        <tr>
          <th>Pclass</th>
          <th></th>
          <th></th>
          <th></th>
        </tr>
      </thead>
      <tbody>
        <tr>
          <th>First Class</th>
          <td>136</td>
          <td>80</td>
          <td>216</td>
        </tr>
        <tr>
          <th>Second Class</th>
          <td>87</td>
          <td>97</td>
          <td>184</td>
        </tr>
        <tr>
          <th>Third Class</th>
          <td>119</td>
          <td>368</td>
          <td>487</td>
        </tr>
        <tr>
          <th>All</th>
          <td>342</td>
          <td>545</td>
          <td>887</td>
        </tr>
      </tbody>
    </table>
    </div>



Second, we can add an argument ``normalize`` that coverts frequency
counts to percentages. By setting the ``normalize`` argument to the
string ``'index'``, we specify that we want values in each row converted
to percentages of that row’s total. For example, the value in the
resulting table for Pclass=1 and Survived=‘Perished’ will indicate what
percentage *of first class passengers* perished:

.. code:: python3

    pd.crosstab(df['Pclass'], df['Survived'], margins=True, normalize='index')




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
          <th>Survived</th>
          <th>Lived</th>
          <th>Perished</th>
        </tr>
        <tr>
          <th>Pclass</th>
          <th></th>
          <th></th>
        </tr>
      </thead>
      <tbody>
        <tr>
          <th>First Class</th>
          <td>0.629630</td>
          <td>0.370370</td>
        </tr>
        <tr>
          <th>Second Class</th>
          <td>0.472826</td>
          <td>0.527174</td>
        </tr>
        <tr>
          <th>Third Class</th>
          <td>0.244353</td>
          <td>0.755647</td>
        </tr>
        <tr>
          <th>All</th>
          <td>0.385569</td>
          <td>0.614431</td>
        </tr>
      </tbody>
    </table>
    </div>



Here’s a similar crosstabs examining the survival of passengers with
sibling or spouses aboard the ship:

.. code:: python3

    pd.crosstab(df['Siblings/Spouses Aboard'], df['Survived'], margins=True, normalize='index')




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
          <th>Survived</th>
          <th>Lived</th>
          <th>Perished</th>
        </tr>
        <tr>
          <th>Siblings/Spouses Aboard</th>
          <th></th>
          <th></th>
        </tr>
      </thead>
      <tbody>
        <tr>
          <th>0</th>
          <td>0.347682</td>
          <td>0.652318</td>
        </tr>
        <tr>
          <th>1</th>
          <td>0.535885</td>
          <td>0.464115</td>
        </tr>
        <tr>
          <th>2</th>
          <td>0.464286</td>
          <td>0.535714</td>
        </tr>
        <tr>
          <th>3</th>
          <td>0.250000</td>
          <td>0.750000</td>
        </tr>
        <tr>
          <th>4</th>
          <td>0.166667</td>
          <td>0.833333</td>
        </tr>
        <tr>
          <th>5</th>
          <td>0.000000</td>
          <td>1.000000</td>
        </tr>
        <tr>
          <th>8</th>
          <td>0.000000</td>
          <td>1.000000</td>
        </tr>
        <tr>
          <th>All</th>
          <td>0.385569</td>
          <td>0.614431</td>
        </tr>
      </tbody>
    </table>
    </div>



We can extend the cross tabs by passing a list of columns. Here we’ve
passed in two dataframe columns for the crosstab rows and a single
column for the crosstab columns.

.. code:: python3

    pd.crosstab([df['Pclass'], df['Sex']], df['Survived'], normalize='index')




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
          <th>Survived</th>
          <th>Lived</th>
          <th>Perished</th>
        </tr>
        <tr>
          <th>Pclass</th>
          <th>Sex</th>
          <th></th>
          <th></th>
        </tr>
      </thead>
      <tbody>
        <tr>
          <th rowspan="2" valign="top">First Class</th>
          <th>female</th>
          <td>0.968085</td>
          <td>0.031915</td>
        </tr>
        <tr>
          <th>male</th>
          <td>0.368852</td>
          <td>0.631148</td>
        </tr>
        <tr>
          <th rowspan="2" valign="top">Second Class</th>
          <th>female</th>
          <td>0.921053</td>
          <td>0.078947</td>
        </tr>
        <tr>
          <th>male</th>
          <td>0.157407</td>
          <td>0.842593</td>
        </tr>
        <tr>
          <th rowspan="2" valign="top">Third Class</th>
          <th>female</th>
          <td>0.500000</td>
          <td>0.500000</td>
        </tr>
        <tr>
          <th>male</th>
          <td>0.137026</td>
          <td>0.862974</td>
        </tr>
      </tbody>
    </table>
    </div>


