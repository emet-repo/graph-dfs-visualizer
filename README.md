# Graph DFS Visualizer (BC++ / BGI Legacy Port)

This repository contains the legacy Borland C++ (BC++) MS-DOS Graph DFS visualization project from `C:\temp\Work\BC\USER\UNIVER\GRAPH`, along with a complete modern interactive Web Visualizer port.

## 🚀 Interactive Web App
Open `index.html` in any web browser to run the interactive visualizer.

### Features
- **Original .DAT File Support**: Parses all test files (`GRAPH.DAT`, `GRAPH1.DAT`, `GRAPH3.DAT`, `GRAPH5.DAT`, `GRAPH_2.DAT`).
- **Multiple Layout Modes**: Grid (original MS-DOS style), Circular, and Force-Directed.
- **Interactive Playback**: Play, Pause, Step Forward, Step Back, Reset, Speed control.
- **Step Log & Legend**: Color-coded visualization of *Unvisited*, *Active (In-Stack)*, *Finished*, and *Current* nodes, with visit order badges.
- **Node Jumping**: Click any node to jump the simulation to the exact step it was visited.

## 🐛 Bugs Fixed from Original C Implementation

1. **Inline Edge Parsing Bug (`fscanf("%c %c\n")`)**:
   - *Original*: Failed on space-separated single-line edge strings (`ag ab bc ac...`).
   - *Fix*: Tokenized pair matching supporting both single-line and multi-line `.DAT` formats.
2. **Header Edge Count Mismatch**:
   - *Original*: Mismatched `E` count headers caused premature EOF or invalid reads.
   - *Fix*: Dynamic parsing based on actual token array length.
3. **`atan` Division-by-Near-Zero Bug**:
   - *Original*: `atan((y1 - y2 + 0.01) / (x1 - x2 + 0.01))` produced arithmetic instability near vertical edges.
   - *Fix*: Replaced with `atan2(dy, dx)`.
4. **Undefined Behavior (String Literal Mutation)**:
   - *Original*: `tmp = " "; tmp[0] = ...` mutated string literal memory in C.
   - *Fix*: Pure JS string formatting.
5. **Memory Leaks (`malloc` without `free`)**:
   - *Original*: Memory allocated in loops without deallocation.
   - *Fix*: Encapsulated JS objects.
6. **Disconnected Component Skipping**:
   - *Original*: Outer loop assumed contiguous $1 \dots V$ integer indexing.
   - *Fix*: Map-based vertex tracking ensuring full coverage of disconnected components.
7. **Fixed Screen Coordinate Overflow**:
   - *Original*: Screen wrapping using `% 630` / `% 460` clipped nodes off-screen on modern display resolutions.
   - *Fix*: Relative mapping to canvas dimensions.
8. **Duplicate Global Declarations**:
   - *Original*: Shadowed global `x, y` declarations across modules.
   - *Fix*: Encapsulated scope.

## 📁 File Structure
- `index.html` — Interactive Web Visualizer
- `GRAPH.C` — Original C DFS algorithm (console)
- `GRAPH_V.C` — Original Borland BGI graph visualizer
- `GRAPH08.C` — Refactored Borland C visualizer
- `VIEW.C` / `GRAPH.H` / `GRAPH_D.H` — Rendering & data headers
- `*.DAT` — Original graph sample datasets
