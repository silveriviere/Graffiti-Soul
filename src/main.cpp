// Project: Graffiti Soul
// Decompiled from Jet Set Radio Future XBE

#include "types.h"
#include <cstdlib>  // For malloc

// ============================================================================
// FORWARD DECLARATIONS
// ============================================================================

// Xbox API stubs (these would normally come from Xbox SDK)
// For now, we provide empty implementations so the code links
namespace XAPILIB {
    dword _tls_index = 0;

    void XapiInitProcess() {
        // TODO: Replace with PC equivalent initialization
    }

    void _rtinit() {
        // C runtime init - handled automatically on PC
    }

    void _cinit() {
        // C++ constructor init - handled automatically on PC
    }

    dword CreateThread(pvoid lpThreadAttributes, dword dwStackSize,
                       dword lpStartAddress, pvoid lpParameter,
                       dword dwCreationFlags, pvoid lpThreadId) {
        // TODO: Replace with std::thread or platform-specific threading
        return 1; // Fake success for now
    }

    void XapiBootToDash(dword dwReason, dword dwParameter1, dword dwParameter2) {
        // Xbox-specific - boots back to dashboard
        // On PC, we just exit
    }
}

// Decompiled game functions
extern dword runtime_wrapper_thread(pvoid param);  // 0x147fb4
extern void thread_cleanup(dword threadHandle);    // 0x145585
extern dword jsrf_game_main();                     // 0x0006f9e0 - THE ACTUAL GAME!

// Global variables from XBE
dword DAT_0027dce0;  // Global at 0x0027dce0

// ============================================================================
// DECOMPILED FUNCTIONS FROM GHIDRA
// ============================================================================

// XBE Entry Point
// This is the first function that runs when the XBE loads
void entry(void) {
    ADDR(0x0); // TODO: Find actual entry address

    dword dVar1;

    DAT_0027dce0 = 0x14;
    XAPILIB::_tls_index = 0xfffffffb;
    dVar1 = XAPILIB::CreateThread(0, 0, 0x147fb4, 0, 0, 0);
    if (dVar1 == 0) {
        XAPILIB::XapiBootToDash(1, 1, 0);
    }
    thread_cleanup(dVar1);
    return;
}

// C/C++ Runtime Initialization Wrapper (0x147fb4)
// This function initializes the C runtime and calls the actual game
// Think of this as the Xbox equivalent of mainCRTStartup
dword runtime_wrapper_thread(pvoid param) {
    ADDR(0x147fb4);

    int iVar1;
    int iVar2;
    byte *puVar3;
    int unaff_FS_OFFSET;  // FS segment register offset (x86 TLS)

    // Initialize Xbox API
    XAPILIB::XapiInitProcess();

    // TLS (Thread Local Storage) setup - this is accessing thread-specific data
    iVar1 = *(int *)(*(int *)(unaff_FS_OFFSET + 0x20) + 0x250);
    if (iVar1 == 0) {
        puVar3 = (byte *)0x0;
    }
    else {
        puVar3 = *(byte **)(iVar1 + 0x24);
    }
    if (puVar3 != (byte *)0x0) {
        iVar1 = *(int *)(*(int *)(unaff_FS_OFFSET + 4) + XAPILIB::_tls_index * 4);
        iVar2 = *(int *)(*(int *)(unaff_FS_OFFSET + 0x28) + 0x28);
        *puVar3 = 1;
        *(int *)(puVar3 + 4) = (iVar1 - iVar2) + 4;
    }

    // Initialize C runtime
    XAPILIB::_rtinit();

    // Initialize C++ global constructors
    XAPILIB::_cinit();

    // *** CALL THE ACTUAL GAME! ***
    jsrf_game_main();

    // When game exits, boot back to Xbox dashboard
    XAPILIB::XapiBootToDash(1, 1, 0);
    return 0;
}

// Thread cleanup/wait handler (0x145585)
void thread_cleanup(dword threadHandle) {
    ADDR(0x145585);

    // TODO: Fill in decompiled code from Ghidra
    // This likely calls WaitForSingleObject or similar to wait for thread completion
}

// ============================================================================
// THE ACTUAL GAME STARTS HERE
// ============================================================================

// Forward declarations for game subsystems
struct GameState;  // 0x8840 bytes - main game state structure
extern GameState* g_GameState;  // Global at 0x0022fce0

// Game subsystem functions
extern GameState* game_state_constructor(void* this_ptr, int param2, int param3);  // 0x00012210
extern void game_state_init_subsystem(GameState* gameState);  // 0x00012c10
extern dword game_main_loop(GameState* gameState);  // 0x00013f80
extern void game_frame_update(GameState* gameState);  // 0x00013a80
extern void FUN_000123e0(uintptr_t gameState);  // 0x000123e0 - Major update function
extern void FUN_00013930(GameState* gameState);  // 0x00013930 - Major update function
extern void FUN_000659c0();  // 0x000659c0 - Unknown function
extern void FUN_00065c80();  // 0x00065c80 - Input callback
extern void sleep_milliseconds(dword ms);  // 0x00145ca6
extern void FUN_0015fa20();  // 0x0015fa20 - Initialization function
extern int FUN_0015fa10();  // 0x0015fa10 - Returns int (frame-related?)
extern void FUN_000694a0(void* device, int index);  // 0x000694a0 - Read from input device
extern ulonglong FUN_0017c3e8();  // 0x0017c3e8 - Read byte from device
extern void FUN_0003e440(void* obj, dword param);  // 0x0003e440 - Subsystem update
extern void FUN_0003e430(void* obj, dword param);  // 0x0003e430 - Subsystem update

// Global subsystem pointers (major game systems)
extern void* DAT_00251d70;  // Audio or camera system?
extern void* DAT_00251d6c;  // Major subsystem (rendering? scene?)
extern void* DAT_00251d68;  // Debug/UI text system
extern void* DAT_00251f5c;  // Input device interface

// Global state variables
extern int DAT_00251d88;   // State flag
extern int DAT_00251d44;   // State flag
extern int DAT_00251d54;   // State flag
extern int DAT_00251d58;   // State flag
extern int DAT_00251d40;   // Object counter

// Global game state pointer (at 0x0022fce0)
GameState* g_GameState = nullptr;

// Global subsystem instances
void* DAT_00251d70 = nullptr;  // Audio or camera system
void* DAT_00251d6c = nullptr;  // Major subsystem (rendering? scene?)
void* DAT_00251d68 = nullptr;  // Debug/UI text system
void* DAT_00251f5c = nullptr;  // Input device interface

// Global state variables
int DAT_00251d88 = 0;
int DAT_00251d44 = 0;
int DAT_00251d54 = 0;
int DAT_00251d58 = 0;
int DAT_00251d40 = 0;  // Object counter

// JSRF Game Main Function (0x0006f9e0)
// This is where the actual game code begins!
dword jsrf_game_main() {
    ADDR(0x0006f9e0);

    void* this_ptr;
    dword* unaff_FS_OFFSET;
    dword local_c;
    byte* puStack_8;
    dword local_4;

    // SEH (Structured Exception Handling) setup
    local_4 = 0xffffffff;
    puStack_8 = (byte*)0x0018771b;  // Exception handler address
    local_c = *unaff_FS_OFFSET;
    *unaff_FS_OFFSET = (dword)(uintptr_t)&local_c;

    // Allocate main game state (34,880 bytes)
    this_ptr = malloc(0x8840);
    local_4 = 0;

    if (this_ptr == nullptr) {
        g_GameState = nullptr;
    }
    else {
        // Construct the game state object
        g_GameState = game_state_constructor(this_ptr, 0, 0);
    }

    local_4 = 0xffffffff;

    // Initialize game subsystems
    game_state_init_subsystem(g_GameState);

    // Run main game loop (this never returns until game exits)
    game_main_loop(g_GameState);

    // Cleanup: call destructor if game state exists
    if (g_GameState != nullptr) {
        // Virtual function call - likely destructor
        // (**(code**)g_GameState)(1, this_ptr);
        // TODO: Implement proper destructor call
    }

    // Restore SEH
    *unaff_FS_OFFSET = local_c;
    return 0;
}

// Game State Subsystem Initialization (0x00012c10)
void game_state_init_subsystem(GameState* gameState) {
    ADDR(0x00012c10);

    void* this_ptr;
    void* puVar1;
    dword* unaff_FS_OFFSET;
    dword local_c;
    byte* puStack_8;
    dword local_4;

    // SEH setup
    local_4 = 0xffffffff;
    puStack_8 = (byte*)0x00186c0b;
    local_c = *unaff_FS_OFFSET;
    *unaff_FS_OFFSET = (dword)(uintptr_t)&local_c;

    // Initialize subsystem pointer at offset 0x87dc
    *(void**)((byte*)gameState + 0x87dc) = nullptr;

    // Check if initialization flag at offset 0x10 is valid
    if (*(int*)((byte*)gameState + 0x10) >= 0) {
        // Allocate 0x44 bytes for a subsystem object
        this_ptr = malloc(0x44);
        local_4 = 0;

        if (this_ptr == nullptr) {
            puVar1 = nullptr;
        }
        else {
            // Initialize subsystem (constructor at 0x00012ae0)
            // puVar1 = FUN_00012ae0(this_ptr, 0, -1, 0);
            puVar1 = nullptr;  // TODO: Decompile FUN_00012ae0
        }

        // Store subsystem pointer at offset 0x87dc
        *(void**)((byte*)gameState + 0x87dc) = puVar1;
    }

    // Restore SEH
    *unaff_FS_OFFSET = local_c;
    return;
}

// Main Game Loop (0x00013f80)
// This function contains the infinite game loop
dword game_main_loop(GameState* gameState) {
    ADDR(0x00013f80);

    // Check if game state is properly initialized
    if (*(int*)((byte*)gameState + 0x10) < 0) {
        return 0xffffffff;
    }

    // INFINITE GAME LOOP
    do {
        // Inner loop: check flag at offset 0x24
        while (*(int*)((byte*)gameState + 0x24) != 0) {
            FUN_000659c0();
            sleep_milliseconds(0x10);  // Sleep 16ms (~60 FPS)
        }

        // Update game frame (render, physics, input, etc.)
        game_frame_update(gameState);

    } while (true);  // Loop forever until game exits

    // Unreachable - game loop never exits normally
    // return 0;
}

// Stub implementations for functions we haven't decompiled yet
GameState* game_state_constructor(void* this_ptr, int param2, int param3) {
    ADDR(0x00012210);
    // TODO: Decompile constructor
    return (GameState*)this_ptr;
}

// Per-Frame Game Update (0x00013a80)
// This is called 60 times per second and runs ALL game logic
void game_frame_update(GameState* gameState) {
    ADDR(0x00013a80);

    void* this_ptr;
    int iVar1;
    // float10 fVar2;  // x87 FPU register
    ulonglong uVar3, uVar4, uVar5, uVar6;
    float fVar7;
    dword uVar8;

    // ========================================================================
    // INPUT PROCESSING - Map button presses to game actions
    // ========================================================================
    // This section checks input flags and calls FUN_00065c80() when buttons pressed
    // Offsets 0x50-0x6c appear to be "button pressed this frame" flags
    // Offsets 0x40-0x4c appear to be "button state" flags

    if (*(int*)((byte*)gameState + 0x50) != 0) {
        FUN_00065c80();  // Input callback
        *(dword*)((byte*)gameState + 0x40) = 1;
    }
    if (*(int*)((byte*)gameState + 0x54) != 0) {
        FUN_00065c80();
        *(dword*)((byte*)gameState + 0x40) = 0;
    }
    if (*(int*)((byte*)gameState + 0x58) != 0) {
        FUN_00065c80();
        *(dword*)((byte*)gameState + 0x44) = 1;
    }
    if (*(int*)((byte*)gameState + 0x5c) != 0) {
        FUN_00065c80();
        *(dword*)((byte*)gameState + 0x44) = 0;
    }
    if (*(int*)((byte*)gameState + 0x60) != 0) {
        FUN_00065c80();
        *(dword*)((byte*)gameState + 0x48) = 1;
    }
    if (*(int*)((byte*)gameState + 100) != 0) {  // 0x64
        FUN_00065c80();
        *(dword*)((byte*)gameState + 0x48) = 0;
    }
    if (*(int*)((byte*)gameState + 0x68) != 0) {
        FUN_00065c80();
        *(dword*)((byte*)gameState + 0x4c) = 1;
    }
    if (*(int*)((byte*)gameState + 0x6c) != 0) {
        FUN_00065c80();
        *(dword*)((byte*)gameState + 0x4c) = 0;
    }

    // Clear input flags for next frame
    *(dword*)((byte*)gameState + 0x50) = 0;
    *(dword*)((byte*)gameState + 0x54) = 0;
    *(dword*)((byte*)gameState + 0x58) = 0;
    *(dword*)((byte*)gameState + 0x5c) = 0;
    *(dword*)((byte*)gameState + 0x60) = 0;
    *(dword*)((byte*)gameState + 100) = 0;  // 0x64
    *(dword*)((byte*)gameState + 0x68) = 0;
    *(dword*)((byte*)gameState + 0x6c) = 0;

    FUN_000659c0();  // Unknown function - maybe input poll?
    *(dword*)((byte*)gameState + 0x74) = 0;

    FUN_000123e0((uintptr_t)gameState);  // Major update function

    // ========================================================================
    // MAIN GAME UPDATE BRANCH
    // ========================================================================
    if (*(int*)((byte*)gameState + 0x94) == 0) {
        // Normal game update path

        FUN_0015fa20();  // Some initialization function

        // Read input device data (likely controller)
        // Pattern: Read bytes and combine into RGB color? Or 3D vector?
        FUN_000694a0(&DAT_00251f5c, 8);
        uVar3 = FUN_0017c3e8();
        FUN_000694a0(&DAT_00251f5c, 9);
        uVar4 = FUN_0017c3e8();
        FUN_000694a0(&DAT_00251f5c, 10);
        uVar5 = FUN_0017c3e8();
        *(dword*)((byte*)gameState + 0x28) = ((int)uVar3 << 8 | (uint)uVar4) << 8 | (uint)uVar5;

        // Read another set of 3 bytes
        FUN_000694a0(&DAT_00251f5c, 0xc);
        uVar3 = FUN_0017c3e8();
        FUN_000694a0(&DAT_00251f5c, 0xd);
        uVar4 = FUN_0017c3e8();
        FUN_000694a0(&DAT_00251f5c, 0xe);
        uVar5 = FUN_0017c3e8();
        *(dword*)((byte*)gameState + 0x2c) = ((int)uVar3 << 8 | (uint)uVar4) << 8 | (uint)uVar5;

        // Read 4 bytes
        FUN_000694a0(&DAT_00251f5c, 0x10);
        uVar3 = FUN_0017c3e8();
        FUN_000694a0(&DAT_00251f5c, 0x11);
        uVar4 = FUN_0017c3e8();
        FUN_000694a0(&DAT_00251f5c, 0x12);
        uVar5 = FUN_0017c3e8();
        FUN_000694a0(&DAT_00251f5c, 0x13);
        uVar6 = FUN_0017c3e8();
        *(dword*)((byte*)gameState + 0x30) =
            (((int)uVar3 << 8 | (uint)uVar4) << 8 | (uint)uVar5) << 8 | (uint)uVar6;

        // Conditional read based on flag at 0x3c
        if (*(int*)((byte*)gameState + 0x3c) == 0) {
            FUN_000694a0(&DAT_00251f5c, 0x15);
            uVar3 = FUN_0017c3e8();
            FUN_000694a0(&DAT_00251f5c, 0x16);
            uVar4 = FUN_0017c3e8();
            FUN_000694a0(&DAT_00251f5c, 0x17);
            uVar5 = FUN_0017c3e8();
            *(dword*)((byte*)gameState + 0x34) = ((int)uVar3 << 8 | (uint)uVar4) << 8 | (uint)uVar5;
        }
        else {
            *(dword*)((byte*)gameState + 0x34) = *(dword*)((byte*)gameState + 0x38);
        }

        // Update subsystem at offset 0x434 (virtual function calls)
        this_ptr = *(void**)((byte*)gameState + 0x434);
        if (this_ptr != nullptr) {
            FUN_0003e440(this_ptr, *(dword*)((byte*)gameState + 0x2c));
            FUN_0003e430(this_ptr, *(dword*)((byte*)gameState + 0x28));
        }

        // Call virtual functions on global subsystem (DAT_00251d70)
        // These appear to be setting parameters (floats) - possibly audio/camera?
        iVar1 = *(int*)DAT_00251d70;
        uVar8 = 1;
        // fVar2 = FUN_000694a0(&DAT_00251f5c, 0x1f);
        // fVar7 = (float)fVar2;
        // fVar2 = FUN_000694a0(&DAT_00251f5c, 0x1b);
        // (**(code**)(iVar1 + 0x14))(DAT_00251d70, (float)fVar2, fVar7, uVar8);
        // TODO: Implement float reading

        // Similar calls for channels 2 and 3
        // ... (omitted for brevity)

        // Call virtual function at offset 0xc
        // (**(code**)(*DAT_00251d70 + 0xc))(DAT_00251d70);

        FUN_00013930(gameState);  // Major update function

        // ====================================================================
        // DEBUG OVERLAY RENDERING
        // ====================================================================
        if (*(int*)((byte*)gameState + 0x18) != 0) {
            // Debug mode is enabled

            if (DAT_00251d88 != -1) {
                DAT_00251d88 = -1;
                // (**(code**)(*DAT_00251d6c + 0xa8))(DAT_00251d6c, 0xffffffff);
            }

            iVar1 = 0; // (**(code**)(*DAT_00251d6c + 0xb0))(DAT_00251d6c);
            if (iVar1 >= 0) {
                // Debug overlay active

                if (DAT_00251d44 != 1) {
                    DAT_00251d44 = 1;
                    // (**(code**)(*DAT_00251d6c + 0x148))(DAT_00251d6c, 0, 1);
                }

                if (DAT_00251d54 != -1) {
                    DAT_00251d54 = -1;
                    // (**(code**)(*DAT_00251d6c + 0x144))(DAT_00251d6c, 0, 0xffffffff);
                }

                if (DAT_00251d58 != -1) {
                    DAT_00251d58 = -1;
                    // (**(code**)(*DAT_00251d6c + 0x144))(DAT_00251d6c, 1, 0xffffffff);
                }

                // Print debug stats - FPS, object count, etc.
                // (**(code**)(*DAT_00251d68 + 0x20))(DAT_00251d68, 0x32, 300, "Object=%d", DAT_00251d40);
                DAT_00251d40 = 0;

                // Print FPS counter
                // (**(code**)(*DAT_00251d68 + 0x20))(DAT_00251d68, 0x32, 0x140, "Fps=%d",
                //     *(dword*)((byte*)gameState + 0x7c));

                // Print TPS (Ticks Per Second?)
                // (**(code**)(*DAT_00251d68 + 0x20))(DAT_00251d68, 0x32, 0x154, "Tps=%d",
                //     *(dword*)((byte*)gameState + 0x80));

                // Print TPF (Ticks Per Frame?)
                // (**(code**)(*DAT_00251d68 + 0x20))(DAT_00251d68, 0x32, 0x168, "Tpf=%d",
                //     *(dword*)((byte*)gameState + 0x84));

                // Print execution time in microseconds
                // (**(code**)(*DAT_00251d68 + 0x20))(DAT_00251d68, 0x32, 0x17c, "Exec =%dus",
                //     *(dword*)((byte*)gameState + 0x87b8), *(dword*)((byte*)gameState + 0x87bc));

                // Print draw time in microseconds
                // (**(code**)(*DAT_00251d68 + 0x20))(DAT_00251d68, 0x32, 400, "Draw =%dus",
                //     *(dword*)((byte*)gameState + 0x87c0), *(dword*)((byte*)gameState + 0x87c4));

                if (DAT_00251d44 != 2) {
                    DAT_00251d44 = 2;
                    // (**(code**)(*DAT_00251d6c + 0x148))(DAT_00251d6c, 0, 2);
                }

                // switchD_00052088::caseD_2();  // Unknown switch case
                // (**(code**)(*DAT_00251d6c + 0xb4))(DAT_00251d6c);
            }
        }

        // Rendering call?
        if (*(int*)((byte*)gameState + 0x74) == 0) {
            // (**(code**)(*DAT_00251d6c + 0xb8))(DAT_00251d6c);
        }
    }
    else if (*(int*)((byte*)gameState + 0x94) == 1) {
        // Alternative update path (paused? loading?)
        do {
            iVar1 = FUN_0015fa10();
        } while (iVar1 == *(int*)((byte*)gameState + 0x87d0));

        *(dword*)((byte*)gameState + 0x94) = 0;

        if (*(int*)((byte*)gameState + 0x74) == 0) {
            // (**(code**)(*DAT_00251d6c + 0xb8))(DAT_00251d6c);
        }
    }

    // Increment frame counters
    *(int*)((byte*)gameState + 0x87e0) = *(int*)((byte*)gameState + 0x87e0) + 1;
    *(int*)((byte*)gameState + 0x87e4) = *(int*)((byte*)gameState + 0x87e4) + 1;

    return;
}

void sleep_milliseconds(dword ms) {
    ADDR(0x00145ca6);
    // TODO: Implement sleep function
    // Original likely calls Sleep() or similar
}

// Game update functions (stubs)
void FUN_000123e0(uintptr_t gameState) {
    ADDR(0x000123e0);
    // TODO: Decompile - major update function
    (void)gameState;
}

void FUN_000659c0() {
    ADDR(0x000659c0);
    // TODO: Decompile - unknown function (called in main loop)
}

void FUN_00013930(GameState* gameState) {
    ADDR(0x00013930);
    // TODO: Decompile - major update function
    (void)gameState;
}

void FUN_00065c80() {
    ADDR(0x00065c80);
    // TODO: Decompile - input callback
}

void FUN_0015fa20() {
    ADDR(0x0015fa20);
    // TODO: Decompile - initialization function
}

int FUN_0015fa10() {
    ADDR(0x0015fa10);
    // TODO: Decompile - returns frame/time value?
    return 0;
}

void FUN_000694a0(void* device, int index) {
    ADDR(0x000694a0);
    // TODO: Decompile - read from input device
    (void)device;
    (void)index;
}

ulonglong FUN_0017c3e8() {
    ADDR(0x0017c3e8);
    // TODO: Decompile - read byte from device
    return 0;
}

void FUN_0003e440(void* obj, dword param) {
    ADDR(0x0003e440);
    // TODO: Decompile - subsystem update
    (void)obj;
    (void)param;
}

void FUN_0003e430(void* obj, dword param) {
    ADDR(0x0003e430);
    // TODO: Decompile - subsystem update
    (void)obj;
    (void)param;
}

// ============================================================================
// PC PORT ENTRY POINT
// ============================================================================

int main(int argc, char* argv[]) {
    // For the PC port, we skip the Xbox-specific threading
    // and call the game directly after minimal initialization

    // TODO: Replace Xbox API calls with PC equivalents
    // For now, just call the game main
    return jsrf_game_main();
}
