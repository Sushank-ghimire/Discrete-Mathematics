# 📘 Graphs in Discrete Mathematics

A **graph** is a fundamental concept in discrete mathematics used to model pairwise relations between objects. It consists of two sets:

- A set of **vertices** (or nodes)
- A set of **edges** (that connect pairs of vertices)

---

## ✅ Definition of Graph

A **graph** is denoted by `G = (V, E)` where:

- `V` is a non-empty finite set of **vertices**
- `E` is a finite set of **edges**, where each edge is a pair of vertices.

### 🔍 Example

Let a graph be:

- `V = {a, b, c, d}`
- `E = { {a, b}, {a, c}, {b, c}, {c, d} }`

<p align="center">
  <img src="https://www.tutorialspoint.com/discrete_mathematics/images/graph.jpg" alt="Graph Example" />
</p>

---

## 🟦 Types of Graphs

### 1. Null Graph

A graph of order `n` and size `0`, i.e., no edges.

<p align="center">
  <img src="https://www.tutorialspoint.com/discrete_mathematics/images/null_graph.jpg" alt="Null Graph" />
</p>

---

### 2. Simple Graph

A graph with no loops and no more than one edge between any two different vertices.

<p align="center">
  <img src="https://www.tutorialspoint.com/discrete_mathematics/images/simple_graph.jpg" alt="Simple Graph" />
</p>

---

### 3. Directed Graph (Digraph)

A graph in which edges have directions. That is, if (u, v) is an edge, it goes from u to v.

<p align="center">
  <img src="https://www.tutorialspoint.com/discrete_mathematics/images/directed_graph.jpg" alt="Directed Graph" />
</p>

---

### 4. Multi Graph

A graph that is allowed to have multiple edges (i.e., more than one edge) between two vertices.

<p align="center">
  <img src="https://www.tutorialspoint.com/discrete_mathematics/images/multi_graph.jpg" alt="Multi Graph" />
</p>

---

### 5. Complete Graph

A graph in which every pair of distinct vertices is connected by a unique edge.

<p align="center">
  <img src="https://www.tutorialspoint.com/discrete_mathematics/images/complete_graph.jpg" alt="Complete Graph" />
</p>

---

### 6. Regular Graph

A graph where every vertex has the same degree (i.e., the same number of edges).

<p align="center">
  <img src="https://www.tutorialspoint.com/discrete_mathematics/images/regular_graph.jpg" alt="Regular Graph" />
</p>

---

### 7. Cyclic Graph

A graph that contains at least one cycle (a closed path).

<p align="center">
  <img src="https://www.tutorialspoint.com/discrete_mathematics/images/cyclic_graph.jpg" alt="Cyclic Graph" />
</p>

---

### 8. Bipartite Graph

A graph whose vertices can be divided into two disjoint sets such that every edge connects a vertex from one set to another set.

<p align="center">
  <img src="https://www.tutorialspoint.com/discrete_mathematics/images/bipartite_graph.jpg" alt="Bipartite Graph" />
</p>

---

### 9. Complete Bipartite Graph

A bipartite graph in which every vertex of one set is connected to every vertex of the other set.

<p align="center">
  <img src="https://www.tutorialspoint.com/discrete_mathematics/images/complete_bipartite.jpg" alt="Complete Bipartite Graph" />
</p>

---

### 10. Undirected Graph

A graph where edges do not have direction. The edge {u, v} is identical to {v, u}.

<p align="center">
  <img src="https://www.tutorialspoint.com/discrete_mathematics/images/undirected_graph.jpg" alt="Undirected Graph" />
</p>

---

---

### 11. Pseudograph

A **Pseudograph** is a graph that allows:

- **Multiple edges** between the same pair of vertices (like a multigraph), and
- **Loops**, i.e., edges that connect a vertex to itself.

This type of graph relaxes the restrictions of a simple graph and is commonly used in network modeling where self-loops and parallel connections are meaningful.

C. Pseudo Graph

<p align="center">
  <img src="https://www.researchgate.net/profile/Pawel-Boguslawski/publication/265219734/figure/fig4/AS:652964947562502@1532690383548/Graphs-a-simple-graph-b-multigraph-c-pseudograph-d-labelled-graph-edges-e.png" alt="Pseudograph" />
</p>

## 📚 Conclusion

Graphs are powerful tools for modeling relationships and are used in a wide array of applications including computer networks, social networks, transportation systems, and more.

> For detailed explanations, visit [TutorialsPoint Graph Theory](https://www.tutorialspoint.com/discrete_mathematics/graph_and_graph_models.htm)
