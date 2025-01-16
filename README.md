# 📅 Calendar Data Structures Implementation

## 🌟 Overview
This project implements various data structures for managing calendar objects in C++. It provides different ways to store, manipulate, and organize calendar data through multiple specialized data structures.

## 🏗️ Data Structures

### 📆 TCalendario (Calendar Class)
- Basic calendar implementation with date and message functionality
- Support for dates from year 1900 onwards
- Operators for comparison and arithmetic operations
- Memory management for message strings
- Date validation and leap year handling

### 📚 TVectorCalendario (Calendar Vector)
- Dynamic array implementation for calendar objects
- Indexing starting from 1
- Support for resizing and capacity management
- Methods for searching and displaying calendar entries

### ⛓️ TListaCalendario (Calendar Linked List)
- Linked list implementation for calendar objects
- Ordered insertion based on dates
- Position-based operations
- List manipulation methods (insert, delete, search)
- Range operations for extracting and combining sublists

### 🌳 TABBCalendario (Binary Search Tree)



Features:
- Tree traversal implementations (Inorder, Preorder, Postorder)
- Level-order traversal
- Basic tree operations (insert, delete, search)
- Tree statistics (height, node count, leaf count)

### ⚖️ TAVLCalendario (AVL Tree)



Features:
- Self-balancing AVL tree implementation
- Balance factor management
- Advanced rotation operations (LL, RR, LR, RL)
- Balanced insertion and deletion
- All standard BST operations with automatic rebalancing

## ✨ Key Features
- 🔍 Comprehensive date validation and handling
- 🛡️ Memory leak prevention through proper resource management
- 🔄 Multiple traversal options for tree structures
- 🚀 Efficient searching and sorting capabilities
- 💪 Support for various calendar operations

## 🔧 Implementation Details

### 💾 Memory Management
- Dynamic memory allocation for strings
- Proper implementation of Rule of Three
- Careful handling of null pointers
- Memory cleanup in destructors

### 📅 Date Handling
- Validation of dates (day, month, year)
- Leap year calculations
- Date comparison operations
- Date arithmetic (increment/decrement)

### ⚖️ Balancing Operations (AVL Tree)
- Balance factor tracking
- Four types of rotations:
  - ↩️ Simple left rotation (LL)
  - ↪️ Simple right rotation (RR)
  - ↪️↩️ Double left-right rotation (LR)
  - ↩️↪️ Double right-left rotation (RL)

## 💡 Usage Examples

### 📆 Basic Calendar Operations
```
// Create a calendar entry
TCalendario cal(1, 1, 2024, "New Year");

// Increment date
cal++;

// Add message
cal.ModMensaje("Updated message");
```

### 📚 Vector Operations
```
// Create a calendar vector
TVectorCalendario vec(5);

// Insert calendar entries
vec[1] = TCalendario(1, 1, 2024, "Entry 1");
vec[2] = TCalendario(2, 1, 2024, "Entry 2");
```

### 🌳 AVL Tree Operations
```
// Create an AVL tree
TAVLCalendario avl;

// Insert with automatic balancing
avl.Insertar(TCalendario(1, 1, 2024, "First Entry"));
avl.Insertar(TCalendario(2, 1, 2024, "Second Entry"));
```

## 🔧 Technical Requirements
- 💻 C++ compiler with C++11 support or higher
- 📚 Standard Template Library (STL)
- 🧠 Basic understanding of data structures and algorithms

