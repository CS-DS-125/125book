from docutils import nodes
from docutils.parsers.rst.directives.admonitions import Note
from docutils.statemachine import ViewList
import urllib.parse

_TEMPLATE = '''
This is a static copy of a Jupyter notebook.  You can access a live
version of it, allowing you to modify and execute the code, in one of two ways:

- `Jhub
  <https://jhub.iwu.edu/hub/user-redirect/git-pull?repo=https%3A%2F%2Fgithub.com%2FCS-DS-125%2F125book&branch=master&urlPath=lab/tree/125book/{{NOTEBOOK_PATH}}>`_
  (for students in IWU's CS/DS course)
- `Binder
  <https://mybinder.org/v2/gh/CS-DS-125/125book/master?urlpath=/lab/tree/{{NOTEBOOK_PATH}}>`_
  (for anyone else)
'''

def setup(app):
    app.add_directive('live_notebook', LiveNotebookDirective)

    return {'version': '0.1'}   # identifies the version of our extension


class LiveNotebookDirective(Note):

    def run(self):
        notebook_path = self.content[0]
        new_content = _TEMPLATE.replace("{{NOTEBOOK_PATH}}", notebook_path).split('\n')
        self.content = ViewList(new_content)
        return super().run()
