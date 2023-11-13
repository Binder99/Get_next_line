# get_next_line - Line Reading Function

## Description

The `get_next_line` function is designed to read lines from a file descriptor (`fd`). Repeated calls to this function, such as within a loop, allow reading a text file one line at a time. The function returns the line that was read, including the terminating `\n` character, except when the end of the file is reached and the line does not end with `\n`. If there is nothing else to read or an error occurs, it returns `NULL`.

## Files

Turn in the following files:

- `get_next_line.c`
- `get_next_line_utils.c`
- `get_next_line.h`

## Parameters

- `fd`: The file descriptor to read from.

## Return Value

- Read line: correct behavior
- `NULL`: Nothing else to read or an error occurred.

## External Functions

- `read`
- `malloc`
- `free`

## Usage

1. Repeated calls to `get_next_line` allow reading a file one line at a time.
2. Returns the line read or `NULL` if there's nothing else to read or an error occurs.
3. Ensure the function works correctly when reading from a file or standard input.

## Header File

Your `get_next_line.h` must contain at least the prototype of the `get_next_line` function.

## Additional Notes

- The returned line should include the terminating `\n` character, except when the end of the file is reached and the line does not end with `\n`.
- Use the option `-D BUFFER_SIZE=n` in your compiler call to define the buffer size for `read()`.
- The buffer size can be modified by peer-evaluators and the Moulinette for testing.
- Consider the potential undefined behavior if the file changes between calls without reaching the end or when reading a binary file.
- Avoid using global variables and `lseek()`.
- The use of `libft` in this project is forbidden.

## Compilation Example

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c
```

## Important Note

Test your function with different `BUFFER_SIZE` values (e.g., 9999, 1, 10000000) to ensure its robustness. Minimize reading at each `get_next_line` call and return the current line when encountering a new line. Do not read the entire file at once and then process each line.
