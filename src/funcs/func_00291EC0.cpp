/* cflags: -fopt-stack */
struct Obj_00291EC0 {
    char pad[0x3B0];
    unsigned int m3B0;
};

extern Obj_00291EC0* D_0038FC78;
extern "C" unsigned int func_00291E60(unsigned int checksum);

unsigned int func_00291EC0_get() {
    return func_00291E60(D_0038FC78->m3B0);
}
