/* fuzzy: 50.0 */
// Program exit (the thread's return address set up by the entry point): signals the semaphore that the
// runtime registered, if the check succeeds, then leaves through the kernel's Exit system call (0x23).
// The original is hand-written without a stack frame; this C++ does the same work with a normal frame.

extern char D_0037AF38[];
extern int* D_00354E8C[];
extern "C" int func_00346230(const char* name);
extern "C" void func_0031BCC0(int sema);

// Kernel call Exit (number 0x23 in $v1): never returns.
static inline void ExitSyscall()
{
    __asm__ __volatile__("addiu $3, $0, 0x23\n\tsyscall" : : : "$3");
}

extern "C" void func_002CE778()
{
    if (func_00346230(D_0037AF38) >= 0) {
        func_0031BCC0(*D_00354E8C[0]);
    }
    ExitSyscall();
}
