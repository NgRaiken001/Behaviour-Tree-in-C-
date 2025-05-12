# 🌲 Custom Behavior Tree in C++

A lightweight, modular **Behavior Tree** system implemented in **pure C++**, designed for simulating complex AI decision-making. The architecture supports reusable nodes, hierarchical control flow, and extensibility—ideal for game AI systems.

---

## 🧠 What is a Behavior Tree?

A **Behavior Tree (BT)** is a model used in game development and robotics for decision-making AI. It structures behaviors as a tree of tasks that control logic based on conditions and actions. It's more scalable and readable than traditional finite state machines for complex AI.

---

## ⚙️ Features

- ✅ **Node Types**: Supports **Selector**, **Sequence**, **Leaf (Action)**, and **Condition** nodes.
- 🔁 **Tick-Based Evaluation**: Every node runs on a recursive tick function to evaluate tree state.
- 🧩 **Modular Design**: Easy to plug in new actions and composite logic.
- 🔄 **Return States**: `Success`, `Failure`, and `Running` are returned per node, following BT conventions.
- 👀 Clean OOP structure using inheritance and interfaces.

---

## 🛠️ Tech Stack

- **C++ (Standard Library Only)**
- Object-Oriented Design
- Design Patterns: **Composite**, **Strategy**, **Template Method**

---

## 📁 Project Structure

```plaintext
/BehaviorTree/
│
├── Node.hpp            # Base class for all nodes
├── Selector.hpp        # Selector node: runs children until one succeeds
├── Sequence.hpp        # Sequence node: runs children until one fails
├── ConditionNode.hpp   # Checks a condition, returns true/false
├── ActionNode.hpp      # Performs an action (e.g., attack, move, idle)
├── BehaviorTree.cpp    # Sets up and ticks the tree
