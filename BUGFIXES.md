# Graph DFS Visualizer bug fixes

This document records the issues that were corrected while porting the original C/BGI DFS implementation into a browser-based visualizer.

## Fixed issues

- Edge count header mismatch — actual token count used
- `fscanf("%c %c\n")` broke on inline edges — tokenized correctly
- `atan(dy/(dx+0.01))` near-vertical divide — replaced with `atan2`
- `malloc` without `free` memory leaks — JS GC
- Writing to a string literal (UB): `tmp=" "; tmp[0]=…`
- Global `x,y` declared twice — all state in objects
- Disconnected components skipped — outer loop handles all
- Node coords `%630/%460` clipped off-screen — mapped to canvas

## Notes

These fixes were part of the porting process and are preserved here separately from the product UI so the visualizer reads as a learning tool rather than a bug report.
