extern void* D_0038E8A4;
extern "C" void* func_001F2F88(void* mgr, int id);
extern "C" int func_001EDF20(void* s, int crc);
extern "C" void func_001F3108(void* mgr, int id);

bool func_001EDFB8(int id, int* list, int n)
{
    void* mgr = D_0038E8A4;
    void* s = func_001F2F88(mgr, id);
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (func_001EDF20(s, list[i])) {
            found = true;
            break;
        }
    }
    func_001F3108(mgr, id);
    return found;
}
