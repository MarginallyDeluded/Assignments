import heapq
from di_graph import DiGraph

class UninformedSearch:
    def __init__(self, graph=DiGraph(), start_node=None, goal_node=None):
        self.graph = graph
        self.start = start_node
        self.goal = goal_node
        
    def _goal_test(self, current):
        return current == self.goal 

    def limiting_depth(self, depth_limit=0, current=None): #depth limit = height of graph
        #check if current node is goal
        if self._goal_test(current):
            return "SUCCESS", [current]
        
            #cutoff reached, so backtrack
        if depth_limit == 0:
            cutoff = True
            return "CUTOFF", []
        
        cutoff = False
        neighbours = self.graph.edges.get(current, {}) #expand current and get its neighbours

        for neighbour in neighbours:
            #obtain status = SUCCESS, CUTOFF or FAILURE and path to goal 
            status, path = self.limiting_depth(depth_limit - 1, neighbour)
            
            #if goal reached, append current node to path, return path 
            if status == "SUCCESS":
                path = [current] + path
                return "SUCCESS", path
            #else backtrack 
            if status == "CUTOFF":
                cutoff = True 

        if cutoff:
            return "CUTOFF", []
        else:
            return "FAILURE", []

    
    def iterative_limit(self, current=None):
        curr_limit = 1 #initialise from a depth > 0
        status, path = self.limiting_depth(curr_limit, current)
        if current is None:
            current = self.start

        while True:
            if status == "SUCCESS":
                return status, path
            if status == "FAILURE":
                #terminate 
                return status, []

            curr_limit += 1
            status, path = self.limiting_depth(curr_limit, current)
        
    def uniform_cost(self, current=None):
        if current is None:
            current = self.start
        
        frontier = [] #min heap/priority queue
        heapq.heapify(frontier)
        explored = {current: 0} #{node: cumulative path cost from start node}
        heapq.heappush(frontier, (0, current, [current])) #stored as (cumulative cost, current_node, path)
        path = []
        
        while len(frontier) != 0:

            node_cost, node, path = heapq.heappop(frontier)

            if self._goal_test(node):
                return "SUCCESS", path 

            if node_cost > explored.get(node):
                continue 

            for neighbour, edge_cost in self.graph.edges.get(node, {}).items():
                new_cost = node_cost + edge_cost 

                if neighbour not in explored or new_cost < explored.get(neighbour):
                    explored.update({neighbour: new_cost})
                    new_path = path + [neighbour]
                    heapq.heappush(frontier, (new_cost, neighbour, new_path))

        return "FAILURE", []




