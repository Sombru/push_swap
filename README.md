*This project has been created as part of the 42 curriculum by pkostura.*

# push_swap

## Description

`push_swap` is a 42 cursus algorithm project. The goal is to sort a stack of
integers using only a limited set of stack operations and to output the shortest
or near-shortest possible sequence of operations.

The program receives integers as command-line arguments, validates the input,
creates stack `a`, and prints the operations needed to sort it in ascending
order. A second stack, `b`, is used as temporary storage during sorting.

Allowed operations:

- `sa`, `sb`, `ss`: swap the top two elements.
- `pa`, `pb`: push the top element from one stack to the other.
- `ra`, `rb`, `rr`: rotate a stack upward.
- `rra`, `rrb`, `rrr`: reverse rotate a stack downward.

## Instructions

### Compilation

Build the mandatory program:

```sh
make
```

Build the bonus checker, if available:

```sh
make bonus
```

Remove object files:

```sh
make clean
```

Remove object files and binaries:

```sh
make fclean
```

Rebuild from scratch:

```sh
make re
```

### Execution

Run `push_swap` with integers as separate arguments:

```sh
./push_swap 3 2 1
```

Or as one quoted argument:

```sh
./push_swap "3 2 1"
```

The program prints one operation per line:

```text
sa
rra
```

Invalid input, duplicated numbers, or allocation/parsing errors print:

```text
Error
```

### Checking The Result

With the official Linux checker:

```sh
ARG="3 2 1"; ./push_swap $ARG | ./checker_linux $ARG
```

Expected output:

```text
OK
```

To count operations:

```sh
ARG="3 2 1"; ./push_swap $ARG | wc -l
```

## Technical Choices

### Stack Representation

Stacks are represented with integer arrays. The top of each stack is stored at
index `0`, so operations like `pa`, `pb`, `ra`, and `rra` directly match the
project subject wording.

### Input Parsing

The parser supports both required input styles:

```sh
./push_swap 1 2 3
./push_swap "1 2 3"
```

The program rejects invalid tokens and duplicated values.

### Sorting Strategy

The implementation uses different strategies depending on input size:

- For very small inputs, it uses dedicated small-sort logic.
- For larger inputs, it uses rank compression and a chunk/window-based strategy.

Rank compression replaces each integer with its position in sorted order:

```text
40 10 30 60 20 50
```

becomes:

```text
3 0 2 5 1 4
```

After compression, the sorter pushes values from stack `a` to stack `b` using a
dynamic rank window. Then it repeatedly brings the largest value in `b` to the
top and pushes it back to `a`. Since `pa` inserts at the top of `a`, pushing
values back from largest to smallest rebuilds stack `a` in ascending order.

## Project Structure

- `main.c`: program entry point.
- `parse_args.c`: input parsing.
- `stack.c`: stack allocation and basic stack helpers.
- `operations.c`: implementation of the required push_swap operations.
- `sort.c`: sorting algorithm.
- `debug.c`: debugging helpers.
- `checker_bonus.c`: bonus checker entry point.
- `libft/`: custom 42 library dependency.

## Resources

Classic and project-related references:

- 42 push_swap subject: official project requirements and operation rules.
- Radix sort: https://en.wikipedia.org/wiki/Radix_sort
- Longest increasing subsequence: https://en.wikipedia.org/wiki/Longest_increasing_subsequence
- Push_swap radix tutorial by Leo Fu: https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e
- Push_swap algorithm notes by VBrazhnik: https://github.com/VBrazhnik/Push_swap/wiki/Algorithm
- K-sort / decision median guide: https://guides.reimann.ee/docs/push_swap/

### AI Usage

AI assistance was used as a development aid for this project. It helped with:

- Explaining possible sorting strategies for `push_swap`.
- Comparing radix sort, LIS-based sorting, and chunk/window-based sorting.
- Drafting and reviewing parsing logic.
- Generating small local test scripts to verify sortedness and operation counts.
- Drafting this README.
