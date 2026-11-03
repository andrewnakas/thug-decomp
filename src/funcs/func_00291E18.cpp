/* cflags: -fopt-stack */
extern "C" int func_00291D70(unsigned int checksum);

struct Obj_00291E18 {
    char pad[0x188];
    int m_values[1];
    void Set(unsigned int checksum);
};

void Obj_00291E18::Set(unsigned int checksum) {
    int i = func_00291D70(checksum);
    if (i != -1) m_values[i] = 1;
}
