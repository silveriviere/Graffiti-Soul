# Graffiti Soul

A decompilation project for **Jet Set Radio Future** (JSRF) for the original Xbox.

## Important Legal Notice

### ⚠️ Game Preservation and Educational Use Only

This project exists solely for **game preservation, research, and educational purposes**. This repository does NOT contain and will NEVER distribute:

- Game ROMs, ISOs, or executables
- Original game assets (textures, models, sounds, music, etc.)
- Copyrighted game data of any kind
- Any material that would allow you to play the game without owning it

### 🎮 You MUST Own a Legal Copy of the Game

**THIS PROJECT REQUIRES YOU TO OWN A LEGITIMATE COPY OF JET SET RADIO FUTURE.**

To use this project, you must:
1. **Purchase** or own an original physical copy of Jet Set Radio Future for Xbox
2. Legally extract the executable from your own game disc
3. Use your own legally obtained game assets

**We do not condone, support, or facilitate piracy in any form.**

### Copyright and Trademark Notice

Jet Set Radio Future, all related characters, logos, and intellectual property are © SEGA Corporation. This project is not affiliated with, endorsed by, or connected to SEGA in any way. All trademarks and copyrights belong to their respective owners.

This is a fan-made preservation project created to:
- Document the technical implementation of a historic game
- Preserve gaming history for future generations
- Enable the game to run on modern hardware for those who legally own it
- Provide educational insights into Xbox game development

---

## About This Project

Graffiti Soul is a reverse engineering and decompilation effort aimed at understanding and preserving the technical implementation of Jet Set Radio Future, one of the Xbox's most beloved titles. The goal is to create a matching decompilation that can be compiled back into functionally equivalent code.

### Why Decompile?

- **Preservation**: As original Xbox hardware ages and fails, preserving games becomes critical
- **Education**: Understanding how commercial games were developed provides valuable learning opportunities
- **Modding**: Enabling the community to fix bugs and create mods (with legal game copies)
- **Portability**: Potentially enabling the game to run on modern systems (for legal owners)

### Project Status

🚧 **Early Development** - This project is in its initial stages.

Currently implemented:
- Basic XBE entry point structure
- Thread initialization framework
- Game state initialization stubs
- Main game loop skeleton

Much work remains to fully decompile all game systems.

## Building

### Prerequisites

- CMake 3.15 or higher
- C++17 compatible compiler (GCC, Clang, or MSVC)
- Git

### Build Instructions

```bash
# Clone the repository
git clone https://github.com/yourusername/graffiti-soul.git
cd graffiti-soul

# Create build directory
mkdir build && cd build

# Configure and build
cmake ..
cmake --build .

# The executable will be in build/bin/graffiti-soul
```

Or use the build script:

```bash
./build.sh
```

## Project Structure

```
graffiti-soul/
├── src/
│   └── main.cpp           # Entry point and main game loop
├── include/
│   └── types.h            # Type definitions matching Xbox SDK
├── docs/
│   └── function_template.cpp  # Template for decompiled functions
├── CMakeLists.txt         # Build configuration
└── README.md              # This file
```

## Contributing

Contributions are welcome! If you're interested in helping preserve this game:

1. You **must** own a legitimate copy of JSRF
2. Use tools like Ghidra or IDA Pro to analyze your legally obtained executable
3. Document your findings and create matching C++ implementations
4. Submit pull requests with clear documentation

### Decompilation Guidelines

- All function addresses should be documented using the `ADDR()` macro
- Match the original assembly as closely as possible
- Use descriptive names when the original symbols are unknown
- Document any assumptions or uncertainties
- Do not include any copyrighted assets or data

## Legal FAQ

**Q: Is this legal?**
A: Reverse engineering for interoperability, preservation, and educational purposes is generally protected under fair use doctrine in many jurisdictions. However, you must own a legal copy of the game.

**Q: Can I play the game with this?**
A: This decompilation alone will not let you play the game. You need the original game assets, which you must obtain legally from your own copy.

**Q: Will this repository provide game files?**
A: **NO.** We will never distribute any copyrighted game files, assets, or executable code from the original game.

**Q: Can I use this for emulation?**
A: This is not an emulator. This is a native reimplementation that requires you to have legal access to the game's assets.

## Disclaimer

This software is provided "as is" without warranty of any kind. The developers and contributors assume no liability for any misuse of this code. This project is for educational and preservation purposes only.

**Support the original creators: If you enjoy Jet Set Radio Future, please purchase legitimate SEGA products to support the company that created this masterpiece.**

## Resources

- [Jet Set Radio Future on Wikipedia](https://en.wikipedia.org/wiki/Jet_Set_Radio_Future)
- [Original Xbox Technical Documentation](https://xboxdevwiki.net/)

## License

This decompilation project is released for educational and preservation purposes. The original game code and assets remain the property of SEGA Corporation. See LICENSE for details on the decompilation code itself.

---

**Remember: This project is only legal and ethical if you own a legitimate copy of the game. Please support game preservation by purchasing games legally.**
