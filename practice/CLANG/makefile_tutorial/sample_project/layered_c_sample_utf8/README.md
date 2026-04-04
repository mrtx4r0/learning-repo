# Layered C Sample Project

Small-but-practical sample project for experimenting with non-trivial `make` setups on Windows. The tree intentionally contains three nested directory levels under the project root so you can practice building multi-module code.

```
layered_c_sample/
├── Makefile
├── README.md
├── include/
│   └── app/
│       ├── cli/
│       │   └── cli.h
│       └── math/
│           └── operations.h
└── src/
    ├── main.c
    └── app/
        ├── cli/
        │   └── cli.c
        └── math/
            └── operations.c
```

The program reads floating-point measurements from the command line, computes min/max/average statistics, and prints a short report. The separation between `cli` and `math` namespaces illustrates how headers from deep include paths are wired up through the Makefile.

## Usage

```bash
# From the project root
make           # builds bin/layered_stats(.exe)
make run ARGS="12.4 33 8"  # runs the freshly built binary with custom values
make tree      # prints the directory structure with `tree`
make clean     # removes build/bin folders
```

Notes:

- The Makefile auto-detects Windows vs. POSIX shells to keep directory creation/removal portable.
- The default `make run` uses sample data. You can override `ARGS` to supply your own series.
- The build uses dependency files (`-MMD`) so incremental rebuilds behave like production projects.
