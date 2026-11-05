struct Ent_00250928 {
    char pad[0x18];
    void* m18;
};

extern void* D_00392068;
extern "C" Ent_00250928* func_002A56E0(void* p);
extern "C" void* func_00203360(void* p);
extern "C" int func_002392B8(void* p);

bool Fn_00250928()
{
    Ent_00250928* e = func_002A56E0(D_00392068);
    if (e) {
        if (e->m18) {
            if (func_002392B8(func_00203360(e->m18)) <= 0) return true;
        }
    }
    return false;
}
