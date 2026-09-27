*This project has been created as part of the 42 curriculum by msouza-t, felforbe.*

# push_swap

## Description

The **push_swap** project is a performance-driven algorithmic challenge in the 42 curriculum. The objective of the project is to sort a stack of unique 32-bit signed integers in ascending order using a limited set of instructions and an auxiliary stack, minimizing the total number of operations performed.

The project demonstrates key software design principles including stack data structure manipulation, algorithm efficiency analysis ($O(n^2)$, $O(n\sqrt{n})$, $O(n\log n)$), adaptive routing based on initial disorder calculation, and strict input validation.

### Allowed Stack Operations
- `sa` / `sb` / `ss`: Swap the top two elements of stack A, stack B, or both.
- `pa` / `pb`: Push the top element from stack B to A, or stack A to B.
- `ra` / `rb` / `rr`: Rotate stack A, stack B, or both upward by 1 position.
- `rra` / `rrb` / `rrr`: Reverse rotate stack A, stack B, or both downward by 1 position.

---

## Instructions

### Compilation

The project uses GNU Make and `cc` with strict compilation flags (`-Wall -Wextra -Werror`).

```bash
make        # Compiles the push_swap binary
make clean  # Removes object (.o) files
make fclean # Removes object files and push_swap binary
make re     # Performs a clean re-compilation
```

### Execution

Run the binary with a sequence of integers as separate arguments or as a single string:

```bash
# Standard execution (Adaptive strategy)
./push_swap 4 2 5 1 3

# String input execution
./push_swap "4 2 5 1 3"

# Explicit algorithm flags (--simple, --medium, --complex)
./push_swap --simple 3 2 1
./push_swap --medium 40 20 50 10 30
./push_swap --complex 5 4 3 2 1

# Benchmark report flag (--bench)
./push_swap --bench --adaptive 5 4 3 2 1
```

---

## Algorithm Explanation and Justification

The project implements three core sorting algorithms and a dynamic **Adaptive Router**:

1. **Simple Algorithm ($O(n^2)$)**:
   - **Mechanism**: Small-stack sorting logic using minimal swap and rotation combinations for $N \le 5$ (such as 3-element hardcoded optimal paths and minimum element pushing for 4-5 elements).
   - **Justification**: For small inputs ($N \le 5$), high-complexity overhead algorithms like Radix Sort generate unnecessary operations. The Simple algorithm guarantees minimal operations ($\le 3$ for $N=3$, $\le 12$ for $N=5$).

2. **Medium Algorithm ($O(n\sqrt{n})$ - Chunk Sort)**:
   - **Mechanism**: The stack elements are assigned relative ranks. Elements are divided into dynamic chunks of size $k = \lfloor\sqrt{n} + 0.4\sqrt{n}\rfloor$ and pushed to stack B based on index ranges, followed by a greedy maximum-element extraction back to stack A.
   - **Justification**: For medium sizes and moderate disorder ($20\% \le \text{desordem} < 50\%$), Chunk Sort balances rotation costs and push counts efficiently, achieving significantly lower operation counts than pure quadratic sorting.

3. **Complex Algorithm ($O(n\log n)$ - Radix Sort)**:
   - **Mechanism**: Least Significant Bit (LSB) Radix Sort operating on normalized 0-indexed element ranks. Each bit level scans stack A, pushing elements with bit `0` to stack B and rotating elements with bit `1` in stack A, then pushing all elements back from B to A.
   - **Justification**: For large inputs ($N = 100$ and $N = 500$) and high disorder ($\ge 50\%$), Radix Sort achieves deterministic $O(k \cdot n)$ complexity (where $k = \lceil\log_2(n)\rceil$), sorting 100 numbers in $\approx 1080$ operations ($< 1500$) and 500 numbers in $\approx 5020$ operations ($< 5500$).

4. **Adaptive Routing**:
   - **Mechanism**: Calculates the initial disorder fraction of stack A ($\text{disorder} = \frac{\text{inversions}}{\text{total\_pairs}}$).
   - **Justification**: Automatically selects the optimal sorting strategy for any input distribution without requiring manual tuning.

---

## Resources

### References and Documentation
- **42 Project Subject**: Push_swap subject specification.
- **Radix Sort Algorithm**: Introduction to Algorithms (CLRS) - LSB Radix Sorting on integer keys.
- **Chunk Sorting Mechanics**: 42 Community guides on Push_swap chunk-based partitioning.

### Artificial Intelligence (AI) Usage Statement
AI tools (Google Antigravity / Gemini) were utilized during the development of this project strictly for the following tasks:
- **Refactoring & Code Formatting**: Verification of 42 Norminette V3 compliance (line limits, function count, variable formatting).
- **Test Generation & Scripting**: Automated test suite execution for random number distributions ($N=100$, $N=500$) and Valgrind memory leak verification.
- **Documentation & README Drafting**: Structuring and formatting the project documentation in accordance with Chapter VII requirements.
- **Parts of the Project**: No core algorithmic logic was auto-generated without manual verification; AI was used as an interactive pair-programming assistant for auditing, test verification, and documentation creation.
