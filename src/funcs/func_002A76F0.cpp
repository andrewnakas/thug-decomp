extern "C" void* func_002A6070();
extern "C" unsigned int func_001F0D78(void* p);
extern "C" void* func_00202EF8(void* p, unsigned int crc);
extern "C" int func_001E8A50(void* p, void* key, int* out, int flag);

extern char D_00392118[];
extern char D_00378328[];

struct Obj_002A76F0 {
    int Lookup();
};

int Obj_002A76F0::Lookup() {
    int value;
    void* p = func_002A6070();
    func_001E8A50(func_00202EF8(p, func_001F0D78(D_00392118)), D_00378328, &value, 1);
    return value;
}
