import matplotlib.pyplot as plt
import networkx as nx
import matplotlib.animation as animation
from collections import deque
import time

class GraphTraversal:
    def __init__(self):
        self.G = nx.Graph()
        self.pos = {}
        self.fig, (self.ax1, self.ax2) = plt.subplots(1, 2, figsize=(16, 8))
        self.fig.suptitle('Graph Traversal Visualization: DFS vs BFS', fontsize=16, fontweight='bold')
        plt.subplots_adjust(top=0.85)
        # Colors for different states
        self.colors = {
            'unvisited': '#90EE90',     # Light green
            'visiting': '#FF6B6B',      # Red
            'queued': '#FFD93D',        # Yellow
            'visited': '#4ECDC4',       # Teal
            'current': '#FF1744',       # Bright red
            'default': '#CCCCCC'        # Default edge color
        }

        self.edge_colors = {
            'default': '#CCCCCC',      # Light gray
            'traversal': '#2196F3'     # Blue
        }

    def create_graph(self, edges):
        """Create graph from edge list"""
        self.G.clear()
        for u, v in edges:
            self.G.add_edge(u, v)

        # Create circular layout for better visualization
        self.pos = nx.spring_layout(self.G, k=3, iterations=50)

    def draw_graph(self, ax, title, node_colors, edge_colors, visited_order=None):
        """Draw the graph with specified colors"""
        ax.clear()
        ax.set_title(title, fontsize=14, fontweight='bold', pad=20)

        # Draw edges
        nx.draw_networkx_edges(self.G, self.pos, ax=ax, edge_color=list(edge_colors.values()), width=2, alpha=0.8)

        # Draw nodes
        nx.draw_networkx_nodes(
            self.G, self.pos, ax=ax,
            node_color=list(node_colors.values()),
            node_size=800, alpha=0.9,
            edgecolors='black', linewidths=2
        )

        # Draw labels
        nx.draw_networkx_labels(
            self.G, self.pos, ax=ax,
            font_size=12, font_weight='bold',
            font_color='white'
        )

        # Show visited order
        if visited_order:
            order_text = f"Visited Order: {' → '.join(map(str, visited_order))}"
            # Place the text below the graph with a larger font size and background
            ax.text(
                0.5, -0.1, order_text, transform=ax.transAxes,
                fontsize=14, verticalalignment='top', horizontalalignment='center',
                bbox=dict(boxstyle='round', facecolor='lightblue', alpha=0.8)
            )

        ax.set_aspect('equal')
        ax.axis('off')

    def dfs_visualization(self, start_node=1):
        """Visualize DFS algorithm"""
        visited = set()
        stack = [start_node]
        visited_order = []
        traversal_edges = set()

        # Initialize colors
        node_colors = {node: self.colors['unvisited'] for node in self.G.nodes()}
        edge_colors = {edge: self.colors['default'] for edge in self.G.edges()}

        steps = []

        def dfs_recursive(node, parent=None):
            if node in visited:
                return

            visited.add(node)
            visited_order.append(node)

            # Add edge to traversal tree
            if parent is not None:
                edge = (min(parent, node), max(parent, node))
                traversal_edges.add(edge)
                edge_colors[edge] = self.edge_colors['traversal']

            # Current node being visited
            node_colors[node] = self.colors['visiting']
            steps.append((dict(node_colors), dict(edge_colors), list(visited_order), f"Visiting node {node}"))

            # Visit neighbors
            for neighbor in sorted(self.G.neighbors(node)):
                if neighbor not in visited:
                    dfs_recursive(neighbor, node)

            # Mark as completely visited
            node_colors[node] = self.colors['visited']
            steps.append((dict(node_colors), dict(edge_colors), list(visited_order), f"Completed node {node}"))

        dfs_recursive(start_node)
        return steps

    def bfs_visualization(self, start_node=1):
        """Visualize BFS algorithm"""
        visited = set()
        queue = deque([start_node])
        visited.add(start_node)
        visited_order = []
        traversal_edges = set()

        # Initialize colors
        node_colors = {node: self.colors['unvisited'] for node in self.G.nodes()}
        edge_colors = {edge: self.colors['default'] for edge in self.G.edges()}

        steps = []
        node_colors[start_node] = self.colors['queued']
        steps.append((dict(node_colors), dict(edge_colors), list(visited_order), f"Added node {start_node} to queue"))

        while queue:
            current = queue.popleft()
            visited_order.append(current)

            # Current node being processed
            node_colors[current] = self.colors['visiting']
            steps.append((dict(node_colors), dict(edge_colors), list(visited_order), f"Processing node {current}"))

            # Add neighbors to queue
            for neighbor in sorted(self.G.neighbors(current)):
                if neighbor not in visited:
                    visited.add(neighbor)
                    queue.append(neighbor)
                    node_colors[neighbor] = self.colors['queued']
                    # Add edge to traversal tree
                    edge = (min(current, neighbor), max(current, neighbor))
                    traversal_edges.add(edge)
                    edge_colors[edge] = self.edge_colors['traversal']

                    steps.append((dict(node_colors), dict(edge_colors), list(visited_order), 
                                f"Added node {neighbor} to queue from {current}"))
            # Mark current as visited
            node_colors[current] = self.colors['visited']
            steps.append((dict(node_colors), dict(edge_colors), list(visited_order), f"Completed node {current}"))
        return steps

    def animate_traversal(self, dfs_steps, bfs_steps):
        """Create animated visualization"""
        max_steps = max(len(dfs_steps), len(bfs_steps))

        def animate(frame):
            # DFS animation
            if frame < len(dfs_steps):
                node_colors, edge_colors, visited_order, status = dfs_steps[frame]
                self.draw_graph(self.ax1, f"DFS - {status}", node_colors, edge_colors, visited_order)

            # BFS animation
            if frame < len(bfs_steps):
                node_colors, edge_colors, visited_order, status = bfs_steps[frame]
                self.draw_graph(self.ax2, f"BFS - {status}", node_colors, edge_colors, visited_order)

            # Add legend
            legend_elements = [
                plt.Line2D([0], [0], marker='o', color='w', markerfacecolor=self.colors['unvisited'], 
                          markersize=10, label='Unvisited'),
                plt.Line2D([0], [0], marker='o', color='w', markerfacecolor=self.colors['queued'], 
                          markersize=10, label='In Queue (BFS)'),
                plt.Line2D([0], [0], marker='o', color='w', markerfacecolor=self.colors['visiting'], 
                          markersize=10, label='Currently Visiting'),
                plt.Line2D([0], [0], marker='o', color='w', markerfacecolor=self.colors['visited'], 
                          markersize=10, label='Visited'),
                plt.Line2D([0], [0], color=self.edge_colors['traversal'], linewidth=3, label='Traversal Tree')
            ]

            # Move legend further down and away from the visited order text
            self.fig.legend(handles=legend_elements, loc='lower center', ncol=5, 
                           bbox_to_anchor=(0.5, 0.05))  # Adjust position here

        anim = animation.FuncAnimation(self.fig, animate, frames=max_steps, interval=1500, repeat=False, blit=False)
        return anim

    def visualize(self, edges, start_node=1):
        """Main visualization function"""
        self.create_graph(edges)

        print("Generating DFS steps...")
        dfs_steps = self.dfs_visualization(start_node)

        print("Generating BFS steps...")
        bfs_steps = self.bfs_visualization(start_node)
        print("Creating animation...")

        anim = self.animate_traversal(dfs_steps, bfs_steps)

        plt.tight_layout()
        plt.subplots_adjust(bottom=0.15)
        plt.show()


if __name__ == "__main__":
    # Create visualizer
    visualizer = GraphTraversal()

    # Ask the user for the number of nodes and edges
    n = int(input("Enter the number of nodes: "))
    m = int(input("Enter the number of edges: "))

    # Collect edges from user input
    edges = []
    print(f"Enter {m} edges (each edge as two space-separated node numbers):")
    for _ in range(m):
        # u, v = map(int, input().split())
        u, v = input().split()
        edges.append((u, v))

    print("Graph Traversal Visualization")
    print("=" * 40)
    print("Edges:", edges)
    print("Starting visualization...")

    # start_node = int(input("Enter the start node (choose a number from the graph nodes): "))
    start_node = (input("Enter the start node (choose a number from the graph nodes): "))

    # Start visualization
    anim = visualizer.visualize(edges, start_node=start_node)
