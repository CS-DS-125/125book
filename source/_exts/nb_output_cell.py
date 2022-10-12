from docutils import nodes
from docutils.parsers.rst.directives.body import ParsedLiteral


def setup(app):
    app.add_directive('nboutput', NBOutputCellDirective)

    return {'version': '0.1'}   # identifies the version of our extension


class NBOutputCellDirective(ParsedLiteral):

    def run(self):
        self.options['classes'] = ["nb-output-cell"]
        label = nodes.paragraph(text="Output:", classes=["nb-output-cell-label"])
        self.add_name(label)
        return [label] + super().run()
