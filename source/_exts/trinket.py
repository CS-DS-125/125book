from docutils import nodes
from docutils.parsers.rst import Directive
import urllib.parse


def setup(app):
    # TODO:
    #app.add_config_value(.....)

    app.add_node(trinket,
                 html=(visit_trinket_node, None),
                 # TODO: latex=(visit_trinket_node, depart_trinket_node),
                 # TODO: text=(visit_trinket_node, depart_trinket_node))
                 )

    app.add_directive('trinket', TrinketDirective)
    #app.connect('doctree-resolved', process_trinket_nodes)
    #app.connect('env-purge-doc', purge_trinkets)

    return {'version': '0.1'}   # identifies the version of our extension


class trinket(nodes.Element, nodes.General):  # nodes.literal_block):
    pass


def visit_trinket_node(self, node):
    code_param = urllib.parse.urlencode(
        { 'code': node.rawsource },
        quote_via=urllib.parse.quote  # so we get %20 for spaces, not +
    )
    url = "https://trinket.io/tools/1.0/jekyll/embed/python#{}".format(code_param)
    self.body.append(
        self.starttag(
            node,
            'iframe',
            CLASS='trinket',
            src=url,
            width='100%',
            height='300px'
        )
    )
    #self.body.append(node.rawsource)
    self.body.append('</iframe>\n')

    # Content fully processed, don't need a depart_...() call:
    raise nodes.SkipNode


class TrinketDirective(Directive):

    # this enables content in the directive
    has_content = True

    def run(self):
        node = trinket(rawsource='\n'.join(self.content))
        #node += nodes.Text("HELLO")
        return [node]
