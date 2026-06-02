
class DiGraph:
    def __init__(self, heuristic=None):
        self.heuristic = heuristic if heuristic else lambda x: 0
        self.nodes_hx = {} #heuristic at node x
        self.edges = {} #structured as a dict = {node1: {child1: c1, child2: c2}, node2: {}}
    
    def has_edge(self, start=None, end=None):
        return start in self.edges and end in self.edges[start]


    def add_edge(self, start, end, p_cost):
        if not self.has_edge(start, end):
            if start not in self.edges:
                self.edges[start] = {}
            if end not in self.edges:
                self.edges[end] = {}
            
            self.edges[start][end] = p_cost

            if start not in self.nodes_hx:
                self.nodes_hx[start] = self.heuristic(start)
            if end not in self.nodes_hx:
                self.nodes_hx[end] = self.heuristic(end)


    def _get_eval(self, node):
        try:
            return self.nodes_hx[node]
        except KeyError:
            hx = self.heuristic(node)
            self.nodes_hx[node] = hx
            return hx 
        


