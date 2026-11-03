struct Box_002CB428 {
    unsigned char x;
    signed char y;
    unsigned char z;
    unsigned char w;
    unsigned char h;
    unsigned char d;
};

struct Park_002CB428 {
    char pad[0x352C];
    Box_002CB428 m352C;
    Box_002CB428 m3532;
};

extern char D_003928C0[];
extern char D_003928C8[];
extern "C" Park_002CB428* func_002C0368();
extern "C" int func_001E8248(void* params, int name, void** out, int a);
extern "C" int func_001E9270(void* p, int i);
extern "C" int func_001E87B8(void* params, char* name);

int func_002CB428(void* params)
{
    Box_002CB428 cur = func_002C0368()->m352C;
    Box_002CB428 max = func_002C0368()->m3532;
    void* arr = 0;
    if (func_001E8248(params, 0, &arr, 0)) {
        int w = func_001E9270(arr, 0);
        int d = func_001E9270(arr, 1);
        if (w != cur.w || d != cur.d) return 1;
    } else {
        int grow = func_001E87B8(params, D_003928C0);
        if (func_001E87B8(params, D_003928C8)) {
            if (grow) {
                if (cur.w < max.w) return 1;
            } else if (cur.w > 16) return 1;
        } else {
            if (grow) {
                if (cur.d < max.d) return 1;
            } else if (cur.d > 16) return 1;
        }
    }
    return 0;
}
