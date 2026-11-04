extern "C" int func_00258698(int a, int b, int node);
extern "C" void* func_001E55B8(unsigned int name, int a);
extern "C" void* func_001E9378(void* arr, int i);
extern "C" bool func_001E8890(void* s, const char* name, const char** out, int required);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E7138(void* s, const char* name, const char* value);
extern "C" void func_001E73C8(void* s, const char* name, unsigned int value);
extern "C" void func_001E7268(void* s, const char* name, int value);
extern "C" void func_001E7860(void* s, const char* name, void* value);
extern "C" bool func_001E7F50(void* params, const char* name, float* out, int required);
extern "C" void func_001E7318(void* s, const char* name, float value);
extern "C" void func_001F0370(const char* name, void* params, int a, int b);
extern "C" unsigned int func_001F0D78(const char* name);
extern "C" void func_001E6AE8(void* p, int flags);

extern char D_00370CF0[];
extern char D_00370D00[];
extern char D_0038F5F0[];
extern char D_0038F428[];
extern char D_0038F678[];
extern char D_00370D10[];
extern char D_00370D20[];
extern char D_00370D38[];
extern char D_00370D58[];
extern char D_00370D68[];
extern char D_00370D80[];
extern char D_0038F408[];
extern char D_00370D90[];
extern char D_00370DA8[];

bool Cmd_002177B0(void* params, void* script)
{
    int node = -1;
    int count = 0;
    void* item;
    do {
        node = func_00258698(0, 0, node);
        if (node != -1) {
            const char* name;
            void* choose;
            if (!func_001E8890(func_001E9378(func_001E55B8(0xC472ECC5, 0), node), D_00370CF0, &name, 0)) {
                name = D_00370D00;
            }
            item = func_001E6978(func_001190D0(8));
            func_001E7138(item, D_0038F5F0, name);
            func_001E73C8(item, D_0038F428, count + 123456);
            func_001E73C8(item, D_0038F678, 0x9F67B2C8);
            func_001E73C8(item, D_00370D10, 0x2A434D05);
            func_001E73C8(item, D_00370D20, func_001F0D78(D_00370D38));
            choose = func_001E6978(func_001190D0(8));
            func_001E7268(choose, D_00370D58, node);
            func_001E7860(item, D_00370D68, choose);
            float scale;
            func_001E7F50(params, D_00370D80, &scale, 1);
            func_001E7318(item, D_0038F408, scale);
            func_001F0370(D_00370D90, item, 0, 0);
            if (item) {
                func_001E6AE8(item, 3);
            }
            if (choose) {
                func_001E6AE8(choose, 3);
            }
            count++;
        }
    } while (node != -1);
    if (count == 0) {
        item = func_001E6978(func_001190D0(8));
        func_001E7138(item, D_0038F5F0, D_00370DA8);
        func_001E73C8(item, D_0038F428, 123456);
        func_001E73C8(item, D_0038F678, 0x9F67B2C8);
        func_001E73C8(item, D_00370D10, 0x2A434D05);
        func_001E73C8(item, D_00370D20, func_001F0D78(D_00370D38));
        func_001F0370(D_00370D90, item, 0, 0);
        if (item) {
            func_001E6AE8(item, 3);
        }
    }
    return true;
}
