extern char D_00392868[];
extern char D_00392870[];
extern void* D_00392808;
extern "C" int func_001E84E8(void* params, char* name, unsigned int* out, int a);
extern "C" void func_002C4D98(void* m, unsigned int v);
extern "C" void func_002C5370(void* m);
extern "C" void func_002C6A40(void* m, int v);
extern "C" void func_002C4C30(void* m, int v);
extern "C" void func_002C4CB8(void* m, int a, int b, int c);

bool func_002CA8A0(void* params, void* script)
{
    unsigned int a = 0;
    void* m = D_00392808;
    func_001E84E8(params, D_00392868, &a, 0);
    unsigned int b = 0;
    func_001E84E8(params, D_00392870, &b, 0);
    if (a == 0xD443A2BC) {
        func_002C4D98(m, 0xD443A2BC);
        func_002C5370(m);
        func_002C6A40(m, 0);
    } else {
        if (b == 0x27F2117D) func_002C4C30(m, a == 0x7ECA21E5);
        else if (b == 0x1A4E0EF9) func_002C4CB8(m, 0, 1, a == 0x7ECA21E5);
        else if (b == 0x2A907CBC) func_002C4CB8(m, 0, 0, a == 0x7ECA21E5);
        else if (b == 0x01625EDA) func_002C4CB8(m, 1, 0, a == 0x7ECA21E5);
        func_002C4D98(m, a);
    }
    return true;
}
