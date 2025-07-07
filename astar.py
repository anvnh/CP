import heapq
import matplotlib.pyplot as plt
import networkx as nx
import matplotlib.animation as animation

class AStarTraversal:
    def __init__(self):
        self.G = nx.Graph()
        self.pos = {}
        self.fig, self.ax = plt.subplots(figsize=(8, 8))
        self.fig.suptitle('Graph Traversal Visualization: A* Algorithm', fontsize=16, fontweight='bold')
        self.colors = {
            'unvisited': '#90EE90',
            'open': '#FFD93D',
            'closed': '#4ECDC4',
            'current': '#FF1744',
            'path': '#2196F3',
            'default': '#CCCCCC'
        }
        self.edge_colors = {
            'default': '#CCCCCC',
            'path': '#2196F3'
        }

    def create_graph(self, edges):
        self.G.clear()
        for u, v, w in edges:
            self.G.add_edge(u, v, weight=w)
        self.pos = nx.spring_layout(self.G, k=5, iterations=50)

    def heuristic(self, node, goal):
        x1, y1 = self.pos[node]
        x2, y2 = self.pos[goal]
        return ((x1 - x2)**2 + (y1 - y2)**2)**0.5

    def a_star(self, start, goal):
        open_set = []
        heapq.heappush(open_set, (0, start))
        came_from = {}
        g_score = {node: float('inf') for node in self.G.nodes()}
        g_score[start] = 0
        f_score = {node: float('inf') for node in self.G.nodes()}
        f_score[start] = self.heuristic(start, goal)

        open_set_hash = {start}
        closed_set = set()

        node_colors = {node: self.colors['unvisited'] for node in self.G.nodes()}
        edge_colors = {edge: self.colors['default'] for edge in self.G.edges()}

        steps = []

        while open_set:
            current_f, current = heapq.heappop(open_set)
            open_set_hash.remove(current)

            if current == goal:
                path = []
                while current in came_from:
                    path.append(current)
                    current = came_from[current]
                path.append(start)
                path.reverse()

                for i in range(len(path) - 1):
                    edge = (min(path[i], path[i+1]), max(path[i], path[i+1]))
                    edge_colors[edge] = self.edge_colors['path']

                for node in path:
                    node_colors[node] = self.colors['path']

                steps.append((dict(node_colors), dict(edge_colors), path, 'Path found'))
                break

            closed_set.add(current)
            node_colors[current] = self.colors['closed']
            steps.append((dict(node_colors), dict(edge_colors), [], f'Closed node {current}'))

            for neighbor in self.G.neighbors(current):
                if neighbor in closed_set:
                    continue

                tentative_g_score = g_score[current] + float(self.G[current][neighbor].get('weight', 1))

                if tentative_g_score < g_score[neighbor]:
                    came_from[neighbor] = current
                    g_score[neighbor] = tentative_g_score
                    f_score[neighbor] = tentative_g_score + self.heuristic(neighbor, goal)

                    if neighbor not in open_set_hash:
                        heapq.heappush(open_set, (f_score[neighbor], neighbor))
                        open_set_hash.add(neighbor)
                        node_colors[neighbor] = self.colors['open']
                        steps.append((dict(node_colors), dict(edge_colors), [], f'Added node {neighbor} to open set'))

            node_colors[current] = self.colors['current']
            steps.append((dict(node_colors), dict(edge_colors), [], f'Processing node {current}'))

        return steps

    def draw_graph(self, node_colors, edge_colors, path=None, status=''):
        self.ax.clear()
        self.ax.set_title(f'A* Algorithm - {status}', fontsize=14, fontweight='bold', pad=20)

        nx.draw_networkx_edges(self.G, self.pos, ax=self.ax, edge_color=list(edge_colors.values()), width=2, alpha=0.8)
        nx.draw_networkx_nodes(
            self.G, self.pos, ax=self.ax,
            node_color=list(node_colors.values()),
            node_size=800, alpha=0.9,
            edgecolors='black', linewidths=2
        )
        nx.draw_networkx_labels(
            self.G, self.pos, ax=self.ax,
            font_size=12, font_weight='bold',
            font_color='white'
        )

        edge_labels = nx.get_edge_attributes(self.G, 'weight')
        nx.draw_networkx_edge_labels(self.G, self.pos, edge_labels=edge_labels, ax=self.ax, font_color='red', font_size=10)

        if path:
            path_text = f'Path: {" → ".join(map(str, path))}'
            self.ax.text(
                0.5, -0.1, path_text, transform=self.ax.transAxes,
                fontsize=14, verticalalignment='top', horizontalalignment='center',
                bbox=dict(boxstyle='round', facecolor='lightblue', alpha=0.8)
            )

        self.ax.set_aspect('equal')
        self.ax.axis('off')

    def animate(self, steps):
        def update(frame):
            node_colors, edge_colors, path, status = steps[frame]
            self.draw_graph(node_colors, edge_colors, path, status)

        anim = animation.FuncAnimation(self.fig, update, frames=len(steps), interval=1500, repeat=False, blit=False)
        return anim

    def visualize(self, edges, start, goal):
        self.create_graph(edges)
        steps = self.a_star(start, goal)
        anim = self.animate(steps)
        plt.tight_layout()
        plt.show()


if __name__ == '__main__':
    visualizer = AStarTraversal()
    n = int(input('Enter the number of nodes: '))
    m = int(input('Enter the number of edges: '))
    edges = []
    print(f'Enter {m} edges (each edge as two space-separated node names and weight):')
    for _ in range(m):
        u, v, w = input().split()
        w = float(w)  # Ép kiểu trọng số thành số thực
        edges.append((u, v, w))
    start = input('Enter the start node: ')
    goal = input('Enter the goal node: ')
    visualizer.visualize(edges, start, goal)
