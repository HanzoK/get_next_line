# get_next_line

## Project Overview
`get_next_line` reads a file descriptor **line by line**, returning one line per call.

It must handle arbitrary buffer sizes and memory cleanup correctly.

## Concepts Covered
- Static variables
- File descriptors
- Buffer accumulation
- EOF & error handling

## Build
```
cc get_next_line.c get_next_line_utils.c
```

## Usage

```
char *line;

while ((line = get_next_line(fd)))
{
    printf("%s", line);
    free(line);
}
```

## Edge case handling

- End of file without newline
- Invalid file descriptors
- Allocation failures
