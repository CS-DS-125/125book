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
contains.  For any object, the built-in Python function ``dir()`` will list the
methods available in an object.

.. code:: python

   >>> mystring = 'Hello world'
   >>> dir(mystring)
   ['capitalize', 'casefold', 'center', 'count', 'encode',
   'endswith', 'expandtabs', 'find', 'format', 'format_map',
   'index', 'isalnum', 'isalpha', 'isdecimal', 'isdigit',
   'isidentifier', 'islower', 'isnumeric', 'isprintable',
   'isspace', 'istitle', 'isupper', 'join', 'ljust', 'lower',
   'lstrip', 'maketrans', 'partition', 'replace', 'rfind',
   'rindex', 'rjust', 'rpartition', 'rsplit', 'rstrip',
   'split', 'splitlines', 'startswith', 'strip', 'swapcase',
   'title', 'translate', 'upper', 'zfill']

Methods, like any other function, can be called to execute them.  Calling a
method is similar to calling a function (it takes arguments and can return a
value), but to access a method within an object, we use :ref:`dot notation
<dot-notation>` just like when accessing functions within modules.

For example, the method ``upper()`` takes a string and returns a new string
with all uppercase letters:

.. activecode:: objects_refresher01

   word = 'banana'
   print(word)
   new_word = word.upper()
   print(new_word)

This form of dot notation specifies the name of the method, ``upper()``, and the
name of the object to apply the method to, ``word``. The parentheses are empty
because this method takes no arguments.

See the rest of the section on :ref:`String objects <string-objects>` for more
examples.


.. index:: attribute, object;attribute

Objects in Pandas
-----------------

In Pandas, the most important type of object we have seen and used is the
DataFrame.  DataFrames contain a wide range of methods, and we have explored
some of those in the earlier chapter.  If we use the ``dir()`` method to
list *all* of a DataFrame's methods, we find a *long* list:

.. code:: python

   >>> dir(df)
   ['T', 'abs', 'add', 'add_prefix', 'add_suffix', 'agg', 'aggregate', 'align',
   'all', 'any', 'append', 'apply', 'applymap', 'as_matrix', 'asfreq', 'asof',
   'assign', 'astype', 'at', 'at_time', 'axes', 'between_time', 'bfill',
   'bool', 'boxplot', 'clip', 'clip_lower', 'clip_upper', 'columns', 'combine',
   'combine_first', 'compound', 'copy', 'corr', 'corrwith', 'count', 'cov',
   'cummax', 'cummin', 'cumprod', 'cumsum', 'describe', 'diff', 'div',
   'divide', 'dot', 'drop', 'drop_duplicates', 'dropna', 'dtypes',
   'duplicated', 'empty', 'eq', 'equals', 'eval', 'ewm', 'expanding', 'ffill',
   'fillna', 'filter', 'first', 'first_valid_index', 'floordiv', 'from_dict',
   'from_records', 'ftypes', 'ge', 'get', 'get_dtype_counts',
   'get_ftype_counts', 'get_values', 'groupby', 'gt', 'head', 'hist', 'iat',
   'idxmax', 'idxmin', 'iloc', 'index', 'infer_objects', 'info', 'insert',
   'interpolate', 'isin', 'isna', 'isnull', 'items', 'iteritems', 'iterrows',
   'itertuples', 'ix', 'join', 'keys', 'kurt', 'kurtosis', 'last',
   'last_valid_index', 'le', 'loc', 'lookup', 'lt', 'mad', 'mask', 'max',
   'mean', 'median', 'melt', 'memory_usage', 'merge', 'min', 'mod', 'mode',
   'mul', 'multiply', 'ndim', 'ne', 'nlargest', 'notna', 'notnull',
   'nsmallest', 'nunique', 'pct_change', 'pipe', 'pivot', 'pivot_table',
   'plot', 'pop', 'pow', 'prod', 'product', 'quantile', 'query', 'radd',
   'rank', 'rdiv', 'reindex', 'reindex_axis', 'reindex_like', 'rename',
   'rename_axis', 'reorder_levels', 'replace', 'resample', 'reset_index',
   'rfloordiv', 'rmod', 'rmul', 'rolling', 'round', 'rpow', 'rsub', 'rtruediv',
   'sample', 'select', 'select_dtypes', 'sem', 'set_axis', 'set_index',
   'shape', 'shift', 'size', 'skew', 'slice_shift', 'sort_index',
   'sort_values', 'squeeze', 'stack', 'std', 'style', 'sub', 'subtract', 'sum',
   'swapaxes', 'swaplevel', 'tail', 'take', 'to_clipboard', 'to_csv',
   'to_dense', 'to_dict', 'to_excel', 'to_feather', 'to_gbq', 'to_hdf',
   'to_html', 'to_json', 'to_latex', 'to_msgpack', 'to_panel', 'to_parquet',
   'to_period', 'to_pickle', 'to_records', 'to_sparse', 'to_sql', 'to_stata',
   'to_string', 'to_timestamp', 'to_xarray', 'transform', 'transpose',
   'truediv', 'truncate', 'tshift', 'tz_convert', 'tz_localize', 'unstack',
   'update', 'values', 'var', 'where', 'xs']

We have only explored a few of these.  Clearly there is a great deal more
functionality inside a DataFrame than we have covered so far.

DataFrames also introduce one new aspect of objects that we glossed over
before: **attributes**.  

Above, we said that objects "know things" and "can do things."  Methods are what
an object can "do," and attributes are what an object "knows."  In other words,
an attribute is data stored inside an object and given a name, just like a method
is code stored inside an object and given a name.  And just as methods can be
accessed via dot notation, so too can attributes.

One example we've seen is ``df.shape``.  The ``.shape`` attribute of a
DataFrame contains the row and column counts for that DataFrame.  Notice that
we access it via dot notation (naming the attribute ``shape`` we want to access
inside the object ``df``) but that the name is *not* followed by parentheses.
This is what differentiates an attribute from a method, and ``.shape`` is not a
method.


.. index:: TypeError, exception;TypeError

.. admonition:: Common Error

   If you attempt to *call* an attribute, by putting parentheses after the name,
   you will encounter a ``TypeError`` exception.  It will tell you that the
   attribute, whatever type it is, is not "callable."  Methods and functions
   can be called and thus are "callable."  If you see this error message, it
   should indicate to you that the name you are accessing is not a method but
   rather is an attribute that can be accessed without the parentheses.

   For example, if `df` is an empty DataFrame (with 0 rows and 0 columns),
   attempting to call `df.shape()` results in an error:

   .. code:: python

      >>> df.shape()
      Traceback (most recent call last):
        File "<stdin>", line 1, in <module>
      TypeError: 'tuple' object is not callable

   While accessing it as an attribute succeeds:

   .. code:: python

      >>> df.shape
      (0, 0)

