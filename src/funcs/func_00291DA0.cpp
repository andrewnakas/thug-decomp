/* cflags: -fopt-stack */
extern "C" int func_00291D70(unsigned int checksum);

struct Obj_00291DA0 {
    char pad[0x188];
    int m_values[1];
    int Get(unsigned int checksum);
};

int Obj_00291DA0::Get(unsigned int checksum) {
    int i = func_00291D70(checksum);
    if (i == -1) return 0;
    return m_values[i];
}
