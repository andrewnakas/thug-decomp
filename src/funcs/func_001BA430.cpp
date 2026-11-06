extern "C" void* func_00185578(void* obj, unsigned int name);

struct Obj_001BA430 {
    char pad[0x30];
    int m30;
    char pad34[0x168 - 0x34];
    void* m168;
    void* m16C;
    void* m170;
    void Method(void* obj);
};

void Obj_001BA430::Method(void* obj)
{
    m168 = obj;
    if (!obj) {
        m16C = 0;
        m170 = 0;
    } else {
        m16C = func_00185578(obj, 0x43686585);
        m170 = func_00185578(m168, 0xD9151D4D);
        m30 = 3;
    }
}
