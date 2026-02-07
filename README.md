*This project has been created as part of the 42 curriculum by vborysov*

# PUSH_SWAP

Push_swap is a technical challenge focused on one thing: Extreme Optimization. The task is to sort a stack of integers using two stacks and a very limited set of operations.

###  Available Operations

| Instruction | Action | Description |
| :--- | :--- | :--- |
| **sa** | `swap a` | Swap the first 2 elements at the top of stack **A**. |
| **sb** | `swap b` | Swap the first 2 elements at the top of stack **B**. |
| **ss** | `swap both` | Execute `sa` and `sb` simultaneously. |
| **pa** | `push a` | Take the top element of **B** and move it to the top of **A**. |
| **pb** | `push b` | Take the top element of **A** and move it to the top of **B**. |
| **ra** | `rotate a` | Shift all elements of **A** up by 1. The first becomes the last. |
| **rb** | `rotate b` | Shift all elements of **B** up by 1. The first becomes the last. |
| **rr** | `rotate both` | Execute `ra` and `rb` simultaneously. |
| **rra** | `rev rotate a` | Shift all elements of **A** down by 1. The last becomes the first. |
| **rrb** | `rev rotate b` | Shift all elements of **B** down by 1. The last becomes the first. |
| **rrr** | `rev rotate both`| Execute `rra` and `rrb` simultaneously. |
---

## Chosen Algorithm: The Butterfly Sort

For the sorting logic, I implemented an optimized **Butterfly (Chunk-based) Algorithm**. Unlike greedy algorithms (like "The Turk") that calculate the cost of every move, the Butterfly approach focuses on efficient data distribution and pre-sorting, which consistently yields high performance with lower code complexity.

### Logical Phases:

1. **Pre-indexing (Normalization):** To make the algorithm independent of raw integer values, I first map all input numbers to their relative ranks $[0, N-1]$ using a temporary sorted array. This allows the algorithm to work with a continuous range of indices.

2. **The Butterfly Distribution (A → B):** Using a dynamic `range` ($16$ for $100$ numbers, $30$ for $500$), elements are pushed to Stack B. 
   - If the element's index is $\leq$ current counter, it is pushed and then rotated to the bottom of Stack B (`pb`, `rb`).
   - If it is within the current range, it is just pushed to the top (`pb`).
   - Otherwise, Stack A is rotated to find the next match.
   *This creates a "butterfly wing" shape in Stack B, where smaller and larger elements of the chunk are at the edges.*

3. **Optimized Collection (B → A):** Once Stack A is empty, I search for the maximum value in Stack B and push it back. Because of the previous distribution phase, the required numbers are always near the top or bottom, minimizing rotation costs.

### Performance Benchmarks:
| Stack Size | Operations Count (Avg) | Limit for 100% |
| :--- | :--- | :--- |
| **100 numbers** | **~600** | < 700 |
| **500 numbers** | **~5200** | < 5500 |

## How to run

### 1. Compilation
Build the executable using the provided Makefile:
```bash
make
```
### 2. Executing
The `push_swap` program is designed to handle input in two different formats:

#### 1) As a list of separate arguments:
```bash
./push_swap 4 5 6 1 3
```

#### 2) As a single string wrapped in quotes:
```bash
./push_swap "4 5 6 1 3"
```

## Resources

### References
* **Chunk Based Sorting Algorithm Logic:** [Chunk Algorithm](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a) — for understanding how chunk sort works
* [Push_swap Visualizer](https://github.com/o-reo/push_swap_visualizer) — for debugging

### AI Usage Disclosure

AI tools (ChatGPT / Gemini) were used as supportive development aids, similar to documentation or online references, in the following areas:

- **Algorithm discussion:** validating the general idea behind the Butterfly Sort approach and comparing it with The Turk method to better understand trade-offs.

- **Edge case review:** helping enumerate possible input scenarios (empty input, integer limits, duplicates, formatting errors) to ensure proper validation and memory safety.

- **Documentation assistance:** helping organize this README and rephrase technical explanations.

All core logic, implementation, debugging, and final decisions were performed manually.

*Note: All logic, parsing, and data structures were manually implemented to the **42 Norminette** and project requirements.*