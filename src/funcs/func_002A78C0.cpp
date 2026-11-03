extern "C" void* func_002A6070();
extern "C" void* func_00202EF8(void* p, unsigned int crc);
extern "C" int func_001E8A30(void* p, unsigned int key, unsigned int* out, int flag);

struct Obj_002A78C0 {
    bool IsMode();
};

bool Obj_002A78C0::IsMode() {
    unsigned int value = 0;
    func_001E8A30(func_00202EF8(func_002A6070(), 0x0F7DD263), 0x21902065, &value, 0);
    return value == 0xF81BC89B;
}
