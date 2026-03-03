<div align="center">

<img width="100%" src="https://capsule-render.vercel.app/api?type=waving&color=0:0d0d0d,40:1a0a0a,100:3d0f0f&height=230&section=header&text=dsa-master-vault&fontSize=52&fontColor=ff6b6b&fontAlignY=40&desc=Data%20Structures%20%26%20Algorithms%20%E2%80%94%20Built%20in%20C%2B%2B&descAlignY=63&descColor=ffaa80&animation=fadeIn&fontFamily=Georgia"/>

<br/>

![Language](https://img.shields.io/badge/C%2B%2B-Solutions-ff6b6b?style=for-the-badge&logo=cplusplus&logoColor=white)
![LeetCode](https://img.shields.io/badge/LeetCode-9_Solved-ffaa80?style=for-the-badge&logo=leetcode&logoColor=black)
![Perfect](https://img.shields.io/badge/100%25_Runtime-7_Problems_🥇-3d0f0f?style=for-the-badge)
![Avg](https://img.shields.io/badge/Avg_Performance-85%25+-ff6b6b?style=for-the-badge&logo=speedtest&logoColor=white)
![Semester](https://img.shields.io/badge/Semester-3_|_Ongoing-1a0a0a?style=for-the-badge)

<br/><br/>

> *"The best time to start was yesterday. The second best time is now."*

<br/>

</div>

---

## ◈ What Lives Here

This is the DSA grind — documented. Every array traversal, every linked list pointer, every algorithm that finally clicked after the third attempt. Written in **C++**, built from Week 3 of Semester 3, and still actively growing.

This vault tracks not just *what* was solved, but *how* — techniques, patterns, runtime performance, and the deliberate practice behind each solution. Seven problems hit **100% runtime**. Nine problems down. The rest of the semester ahead.

---

## ◈ Vault Structure

```
dsa-master-vault/
│
└── C++/
    ├── Algorithms/
    │   └── Math_Algorithms/
    │
    ├── Linear_DS/
    │   ├── Array/
    │   │   ├── LeetCode_Problems/
    │   │   ├── 01_viewAndInsert.cpp
    │   │   ├── 02_search.cpp
    │   │   ├── 03_delete.cpp
    │   │   └── 04_addORupdate.cpp
    │   │
    │   └── Linked_List/
    │       ├── Singly_Linked_List/
    │       │   ├── 01_insert.cpp
    │       │   └── 02_delete.cpp
    │       └── LeetCode_Problems/
    │
    └── Non_Linear_DS/
        └── [coming next...]
```

---

## ◈ Progress Scoreboard

<div align="center">

```
┌──────────────────────────────────────────────────────
│                                                      
│    Problems Solved      →   9
│    100% Runtime Hits    →   7  🥇                   
│    Average Performance  →   85%+                     
│    Active Since         →   Week 3, Semester 3       
│    Status               →   🔨 Ongoing               
│                                                      
└──────────────────────────────────────────────────────
```

</div>

---

## ◈ Problems Solved

### 📐 Arrays — 4 Problems
**Patterns practiced:** Two-pointer · Binary positioning · In-place modification

| # | Problem | Runtime | Memory | Link |
|:---:|---|:---:|:---:|:---:|
| 1 | Two Sum | 35ms (44%) | 47MB (38%) | [→ code](C++/Linear_DS/Array/LeetCode_problems/01_twoSum.cpp) |
| 26 | Remove Duplicates from Sorted Array | **0ms (100%) 🥇** | 47MB (62%) | [→ code](C++/Linear_DS/Array/LeetCode_problems/02_removeDuplicatesfromsortedArray.cpp) |
| 35 | Search Insert Position | **0ms (100%) 🥇** | 14MB (76%) | [→ code](C++/Linear_DS/Array/LeetCode_problems/03_searchInsertPosition.cpp) |
| 88 | Merge Sorted Array | **0ms (100%) 🥇** | 13MB (76%) | [→ code](C++/Linear_DS/Array/LeetCode_problems/04_mergeSortedArray.cpp) |

---

### 🔗 Linked Lists — 5 Problems
**Patterns practiced:** Fast/slow pointers · Pointer reversal · Dummy head pattern

| # | Problem | Runtime | Memory | Link |
|:---:|---|:---:|:---:|:---:|
| 21 | Merge Two Sorted Lists | **0ms (100%) 🥇** | 19MB (86%) | [→ code](C++/Linear_DS/Linked_List/LeetCode_problems/02_mergeTwoSortedLinkedList.cpp) |
| 83 | Remove Duplicates from Sorted List | **0ms (100%) 🥇** | 16MB (67%) | [→ code](C++/Linear_DS/Linked_List/LeetCode_problems/03_removeDuplicatesfromSortedLinkedList.cpp) |
| 141 | Linked List Cycle | 12ms (43%) | 12MB (81%) | [→ code](C++/Linear_DS/Linked_List/LeetCode_problems/04_linkedlistCycle.cpp) |
| 206 | Reverse Linked List | **0ms (100%) 🥇** | 13MB (42%) | [→ code](C++/Linear_DS/Linked_List/LeetCode_problems/01_reverseLinkedList.cpp) |
| 876 | Middle of the Linked List | **0ms (100%) 🥇** | 10MB (63%) | [→ code](C++/Linear_DS/Linked_List/LeetCode_problems/05_middleofLinkedList.cpp) |

---

## ◈ Custom Implementations

These aren't LeetCode solutions — they're hand-built implementations of data structure operations from scratch. The real fundamentals.

<details>
<summary><b>📐 Array Operations</b></summary>
<br/>

| File | Operation |
|---|---|
| [01_viewAndInsert.cpp](C++/Linear_DS/Array/01_viewAndinsert.cpp) | Traversal and element insertion |
| [02_search.cpp](C++/Linear_DS/Array/02_search.cpp) | Linear and positional search |
| [03_delete.cpp](C++/Linear_DS/Array/03_delete.cpp) | Element deletion with shift |
| [04_addORupdate.cpp](C++/Linear_DS/Array/04_addORupdate.cpp) | Add new or update existing element |

</details>

<details>
<summary><b>🔗 Singly Linked List Operations</b></summary>
<br/>

| File | Operation |
|---|---|
| [01_insert.cpp](C++/Linear_DS/Linked_List/Singly_Linked_List/01_insert.cpp) | Node insertion (head, tail, position) |
| [02_delete.cpp](C++/Linear_DS/Linked_List/Singly_Linked_List/02_delete.cpp) | Node deletion by value or position |

</details>

---

## ◈ Techniques in the Toolkit

```cpp
// Every pattern here has been used in a real solved problem.

// ① Two Pointer — O(n) traversal without extra space
int left = 0, right = n - 1;
while (left < right) { /* close in */ }

// ② Fast / Slow Pointer — Floyd's cycle + midpoint detection
ListNode* slow = head;
ListNode* fast = head;
while (fast && fast->next) { slow = slow->next; fast = fast->next->next; }

// ③ Dummy Head — clean edge case handling in linked lists
ListNode dummy(0);
ListNode* curr = &dummy;

// ④ In-Place Modification — O(1) space array operations
// Shift, overwrite, no auxiliary array needed.

// ⑤ Pointer Reversal — iterative list restructuring
ListNode* prev = nullptr;
while (curr) { ListNode* next = curr->next; curr->next = prev; prev = curr; curr = next; }
```

---

## ◈ Timeline

```
Week 3  ──●── Arrays from scratch. First LeetCode attempt. First 100% hit.
            │
Week 4  ────●── Linked lists. Pointer logic. 4 perfect scores in a single day.
              │
Week 5  ──────●── [ Next chapter loading... ]
```

---

## ◈ What's Coming

The vault is still being filled. On the roadmap:

- **Non-Linear DS** — Trees (Binary, BST), Graphs
- **Sorting Algorithms** — Merge sort, Quick sort, Heap sort
- **More LeetCode** — Stacks, Queues, Hash Maps
- **Algorithm Patterns** — Sliding window, BFS/DFS, Dynamic Programming foundations

---

## ◈ How to Run Any Solution

```bash
# Clone the vault
git clone https://github.com/MuhammadAhmadHamim/dsa-master-vault.git
cd dsa-master-vault

# Compile any solution
g++ -std=c++17 -O2 -o output "C++/Linear_DS/Array/LeetCode_problems/01_twoSum.cpp"

# Run
./output
```

> **Compiler:** GCC / G++ &nbsp;|&nbsp; **Standard:** C++17 &nbsp;|&nbsp; **Flag:** `-O2` for performance parity with LeetCode judge

---

## ◈ Skills Being Forged

<div align="center">

![](https://img.shields.io/badge/C%2B%2B-Pointer_Mastery-ff6b6b?style=flat-square&logo=cplusplus&logoColor=white)
![](https://img.shields.io/badge/DSA-Array_Patterns-3d0f0f?style=flat-square&logo=buffer&logoColor=white)
![](https://img.shields.io/badge/DSA-Linked_List_Design-ffaa80?style=flat-square&logo=buffer&logoColor=black)
![](https://img.shields.io/badge/Pattern-Two_Pointer-ff6b6b?style=flat-square&logo=buffer&logoColor=white)
![](https://img.shields.io/badge/Pattern-Fast_%2F_Slow_Pointer-1a0a0a?style=flat-square&logo=buffer&logoColor=ffaa80)
![](https://img.shields.io/badge/LeetCode-Active_Solver-FFA116?style=flat-square&logo=leetcode&logoColor=black)

</div>

---

## ◈ Learning Philosophy

Self-taught through deliberate practice. No shortcuts — every pattern understood before the next one is touched. Learning in public, building in private, growing every week.

The 100% runtime scores aren't luck. They're what happens when the *why* behind a solution is understood before the *how*.

---

<div align="center">

<img width="100%" src="https://capsule-render.vercel.app/api?type=waving&color=0:3d0f0f,50:1a0a0a,100:0d0d0d&height=120&section=footer&animation=fadeIn"/>

*Every solved problem is a permanent deposit. The vault only grows.*

</div>
