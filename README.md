# Project: Graffiti Soul

Native PC port of Jet Set Radio Future through reverse engineering and decompilation.

## Project Structure

```
graffiti-soul/
├── CMakeLists.txt          # Main build configuration
├── src/
│   ├── main.cpp            # Entry point (originally 0x147fb4)
│   ├── engine/             # Core engine systems (TODO)
│   ├── graphics/           # D3D rendering code (TODO)
│   ├── physics/            # Physics and movement (TODO)
│   ├── game/               # Game logic (TODO)
│   └── audio/              # Sound system (TODO)
├── include/
│   ├── types.h             # Common type definitions
│   └── ...                 # Headers for each subsystem
└── docs/
    └── memory_map.md       # XBE address mapping (TODO)
```

## Building

```bash
mkdir build && cd build
cmake ..
make
```

## Decompilation Workflow

1. **Identify function in Ghidra** at original XBE address
2. **Create stub** in appropriate source file with ADDR() macro
3. **Copy decompiled code** from Ghidra
4. **Clean up types** - replace Ghidra generic types with proper ones
5. **Identify dependencies** - what other functions does it call?
6. **Test compilation** - does it build?
7. **Document** - add comments explaining what you learned

## Key Addresses (XBE)

- `0x147fb4` - Main game initialization thread
- `0x145585` - Thread cleanup handler
- (Add more as you discover them)

