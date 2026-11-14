/* force: {"kind": "lfr", "block": 2, "reg": 126, "hard": 4} */
/* force: {"kind": "lfr", "block": 4, "reg": 131, "hard": 4} */
/* force: {"kind": "lfr", "block": 6, "reg": 136, "hard": 4} */
/* force: {"kind": "lfr", "block": 8, "reg": 141, "hard": 4} */
/* force: {"kind": "lfr", "block": 10, "reg": 146, "hard": 4} */
/* force: {"kind": "lfr", "block": 11, "reg": 149, "hard": 4} */
extern void* D_0038EB78;
extern char D_0038F5F0[];
extern char D_003709F8[];
extern char D_00370A30[];
extern char D_00370A48[];
extern char D_00370A60[];
extern char D_00370A78[];
extern char D_00370A98[];
extern char D_00370A10[];
extern char D_00370AB0[];

extern "C" bool func_001F9EF0(void* net);
extern "C" int func_001FA660(void* net);
extern "C" unsigned int func_001F0D78(const char* name);
extern "C" const char* func_001E54B8(const char* name, int a);
extern "C" void func_001E7A30(void* s, unsigned int name, int type, const char* value);
extern "C" void func_001F0370(const char* name, void* params, int a, int b);
extern "C" bool func_001E8A50(void* params, const char* name, unsigned int* out, int required);
extern "C" void func_001F0210(unsigned int name, void* params, int a, int b, int c);

bool Cmd_00215388(void* params, void* script)
{
    void* net = D_0038EB78;
    bool ok = func_001F9EF0(net);
    if (!ok) {
        unsigned int name;
        const char* msg;
        if (func_001FA660(net) == 5) {
            name = func_001F0D78(D_0038F5F0);
            msg = D_003709F8;
        } else if (func_001FA660(net) == 4) {
            name = func_001F0D78(D_0038F5F0);
            msg = D_00370A30;
        } else if (func_001FA660(net) == 2) {
            name = func_001F0D78(D_0038F5F0);
            msg = D_00370A48;
        } else if (func_001FA660(net) == 6) {
            name = func_001F0D78(D_0038F5F0);
            msg = D_00370A60;
        } else if (func_001FA660(net) == 7) {
            name = func_001F0D78(D_0038F5F0);
            msg = D_00370A78;
        } else {
            name = func_001F0D78(D_0038F5F0);
            msg = D_00370A98;
        }
        func_001E7A30(params, name, 3, func_001E54B8(msg, 0));
        func_001F0370(D_00370A10, params, 0, 0);
    } else {
        unsigned int success;
        func_001E8A50(params, D_00370AB0, &success, 1);
        func_001F0210(success, params, 0, 0, 0);
    }
    return ok;
}
