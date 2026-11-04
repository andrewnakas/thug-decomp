/* cflags: -fopt-stack */
extern "C" int func_001E8398(void* params, unsigned int name, unsigned int* out, int flags);
extern "C" unsigned int func_00291E60(unsigned int checksum);

unsigned int func_00291E80_get(void* params) {
    unsigned int value = 0;
    func_001E8398(params, 0x651533EC, &value, 0);
    value = func_00291E60(value);
    return value;
}
